using System;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;

internal class TcpHandler
{

    public static uint timeoutCounter;
    public static Queue<Tuple<string, dynamic>> PackageQueues = new();

    public static void Handle(TcpClient client, NetworkStream stream, ref List<byte> buffer)
    {
        string message = Encoding.UTF8.GetString(buffer.ToArray());

        switch(message)
        {
            case "GET":

                if(timeoutCounter < 3)
                timeoutCounter++;

                if (PackageQueues.Count > 0)
                {
                    Tuple<string, dynamic> pair;
                    PackageQueues.TryDequeue(out pair);

                    string crazy = JsonSerializer.Serialize(pair.Item2);
                    crazy.Replace("_params", "params"); // coz of the keyword you know

                    stream.Write(Encoding.UTF8.GetBytes("[\"" + pair.Item1 + "\"," + crazy + "]\0"));
                }
                else
                {
                    stream.Write(new byte[1] { 0 });
                }

                break;

            case "EXIT":
                // either im too dumb or c# tcp lib is being super gay to linux socket to disconnect the the socket if i call close from the menu.
                client.Close();
                Console.WriteLine("Client disconnected.");
                break;

            default:
                Console.WriteLine(message);
                break;
        }
    }
}

