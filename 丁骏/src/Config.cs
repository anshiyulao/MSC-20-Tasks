using System;
using System.Collections.Generic;
using System.Text;

namespace CreeperBot.src
{
    static class Config
    {
        public static readonly string Host = "127.0.0.1";
        public static readonly    int Port = 8080;
        public static readonly string Key  = "1c783ceb3f5344d097781ab771021efc";

        public static string HelperPath = @"..\..\..\dependence\Helper.txt";
        public static string SplitedLyricsPath = @"..\..\..\dependence\SplitedLyrics.txt";
        public static string VoiceFolder = @"..\..\..\dependence\creeper\";

        //[Obsolete("please provide a qq num")]
        public static readonly long QQNum = 2235282107;

        public static readonly string[] CommandStart = new string[] { "CreeperBot", "Creeper", "Creeperbot", "creeperbot" };
    }
}
