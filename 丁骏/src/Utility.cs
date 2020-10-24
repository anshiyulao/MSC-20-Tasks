using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using Mirai_CSharp.Models;
using System.Reflection.Metadata.Ecma335;

namespace CreeperBot.src
{
    static class Utility
    {
        public static bool CommandStartChecker(string str) 
            => Config.CommandStart.Contains(str.Split(' ', StringSplitOptions.RemoveEmptyEntries).First());

        public static (bool, string) CommandStringProcess(string command)
        {
            if (CommandStartChecker(command))
                return (true, command.Substring(command.IndexOf(' ') + 1));
            else
                return (false, null);
        }

        public static (bool, string) CommandGroupMessageArgs(IGroupMessageEventArgs args)
        {
            if (args.Chain.Length != 2 || !(args.Chain[1] is PlainMessage))
                return (false, null);
            else
            {
                return CommandStringProcess(((PlainMessage)args.Chain[1]).Message);
            }
        }
    }
}
