using CreeperBot.src;
using CreeperBot.src.CreeperUtility;
using CreeperBot.src.plugins;
using Mirai_CSharp;
using Mirai_CSharp.Models;
using System;
using System.Linq;
using System.Threading.Tasks;

namespace CreeperBot.src
{
    class Program
    {
        static void CommandParser(string[] args)
        {
            if(!args.Any()) return;

            if (args[0] == "config")
            {
                if (args.Length < 2) return;

                if (args[1] == "path")
                {
                    if (args.Length < 4) return;

                    if (args[2] == "helper")
                        Config.HelperPath = args[3];
                    if (args[3] == "lyrics")
                        Config.SplitedLyricsPath = args[3];
                    if (args[3] == "voicefolder")
                        Config.VoiceFolder = args[3] + "\\";
                }
            }    
        }
        static async Task Main(string[] args)
        {
            var options = new MiraiHttpSessionOptions(Config.Host, Config.Port, Config.Key);
            await using var session = new MiraiHttpSession();

            session.GroupMessageEvt += Helper.CommandProcessor;
            session.GroupMessageEvt += CreeperSolitaire.Register;

            await session.ConnectAsync(options, Config.QQNum);

            Creeper.Init(session);

            UnitTest.Run(session, 1139534508);

            while (true)
            {
                var command = await Console.In.ReadLineAsync();
                if (command == "exit")
                    Environment.Exit(0);
                
                var commandArgs = command.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                CommandParser(commandArgs);
            }
        }
    }
}
