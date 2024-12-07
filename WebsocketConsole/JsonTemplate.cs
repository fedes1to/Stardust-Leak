

public class JsonTemplate
{
    public static dynamic UpdateProgress(dynamic obj)
    {
        return new
        {
            id = cmdID.Snapshot,
            i = Commands.RandHex(),
            p = obj
        };
    }
}

