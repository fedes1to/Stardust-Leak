using System.Net;
using System.Net.Sockets;
using System.Reflection;
using System.Text;
using System.Text.Json;
using static System.Runtime.InteropServices.JavaScript.JSType;

class Program
{
    static string LocalIPAddress = GetLocalIPAddress();
    static TcpListener server = new(IPAddress.Parse(LocalIPAddress), 8080);

    static void Main(string[] args)
    {
        server.Start();
        Console.WriteLine($"Server has been started on {LocalIPAddress}. Put this IP in the menu to connect the console.");

        Task.Run(() =>
        {
            while (true)
            {
                string[] args = Console.ReadLine().Split(" ");
                MethodInfo method = typeof(Commands).GetMethod(args[0], BindingFlags.NonPublic | BindingFlags.Instance);
                try
                {
                    if (method != null)
                    {
                        var crazy = args.ToList();
                        crazy.RemoveAt(0);

                        var result = (Tuple<string, dynamic>)method.Invoke(Commands.instance, new object[1] { crazy });
                        Console.WriteLine(result.Item1 + " (queue): " + JsonSerializer.Serialize(result.Item2));
                        TcpHandler.PackageQueues.Enqueue(result);
                    }
                    else
                    {
                        Console.WriteLine($"Can't find command method named \"{args[0]}\"");
                    }
                }
                catch (Exception err)
                {
                    Console.WriteLine(err);
                }

            }
        });

        TcpClient client = null;

        Task.Run(() =>
        {
            while(true)
            {
                if(client != null && client.Connected)
                {
                    Thread.Sleep(1000);

                    if (TcpHandler.timeoutCounter > 0)
                    {
                        TcpHandler.timeoutCounter--;
                    }
                    else if (TcpHandler.timeoutCounter == 0)
                    {
                        client.Close();
                        Console.WriteLine("Client disconnected.");
                    }
                }
            }
        });

        while (true)
        {
            client = server.AcceptTcpClient();
            NetworkStream clientStream = client.GetStream();

            while (client.Connected)
            {
                List<byte> buffer = new();

                while (client.Available > 0)
                {
                    var currByte = new Byte[1];
                    int i = clientStream.Read(currByte, 0, 1);

                    if (i >= 1)
                    {
                        if (currByte[0] == 0) { 
                            break;
                        };
                        buffer.Add(currByte[0]);
                    }
                };

                if (buffer.Count > 0)
                    TcpHandler.Handle(client, clientStream, ref buffer);
            }
        }
    }

    public static string GetLocalIPAddress()
    {

        var host = Dns.GetHostEntry(Dns.GetHostName());
        foreach (var ip in host.AddressList)
        {
            if (ip.AddressFamily == AddressFamily.InterNetwork)
            {
                return ip.ToString();
            }
        }
        throw new Exception("No network adapters with an IPv4 address in the system!");
    }
}