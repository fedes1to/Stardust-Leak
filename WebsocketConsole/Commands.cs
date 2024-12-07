using System.Text;

public class Commands
{
    static string version = "23.8.0";
    public static Commands instance = new();

    Tuple<string, dynamic> reload(List<string> args)
    {
        var json = new { };
        return new("update_progress", json);
    }

    Tuple<string, object> ban(List<string> args)
    {
        var json = new
        {
            reason = args[0]
        };
        return new("ban", json);
    }

    // patched
    Tuple<string, dynamic> evaluate_lobby(List<string> args)
    {
        var json = new
        {
            like = Convert.ToInt32(args[0]),
            player_id = args[1]
        };

        return new("evaluate_lobby", json);
    }

    Tuple<string, dynamic> new_skin(List<string> args)
    {
        var json = JsonTemplate.UpdateProgress(new
        {
            i = RandHex(),
            n = args[0],
            c = args[1],
            h = new List<string>()
            {
                RandHex(20),
                RandHex(20)
            }
        });

        return new("update_progress", json);
    }

    Tuple<string, dynamic> add_currency(List<string> args)
    {
        var json = JsonTemplate.UpdateProgress(new
        {
            c = new List<dynamic>
                {
                    new
                    {
                        id = cmdID.AddCurrency,
                        ci = RandHex(),
                        p = new
                        {
                            c = args[0],
                            v = Convert.ToInt32(args[1]),
                            ca = 1,
                            sc = 1
                        },
                        h = new {},
                        v = version,
                        u = new List<int>() {278}
                    },
                    new
                    {
                        id = cmdID.AnalyticsProgress,
                        ci = RandHex(),
                        p = new
                        {
                            eid = 1012,
                            _params = new
                            {
                               ip1 = Convert.ToInt32(args[1]),
                               sp1 = args[0],
                               sp2 = "OfferWall",
                               ip2 = 0
                            }
                        },
                        h = new {},
                        v = version,
                        u = new List<int>() {278}
                    }
                }
        });

        return new("update_progress", json);
    }

    public static string RandHex(int length = 4)
    {
        Random random = new Random();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++)
        {
            int randomValue = random.Next(256);
            sb.Append(randomValue.ToString("X2"));
        }
        return sb.ToString().ToLower();
    }
}