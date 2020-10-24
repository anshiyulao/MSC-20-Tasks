using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Mirai_CSharp;
using Mirai_CSharp.Models;
using Mirai_CSharp.Plugin;

namespace CreeperBot.src.plugins
{
    static class Helper
    {
        public static readonly string[] helperCommand = new string[] { "helper", "help", "帮助", "-h", "--help" };
        public static async Task<bool> CommandProcessor(MiraiHttpSession session, IGroupMessageEventArgs e)
        {
            var (hasCommandStart, commandArgs) = Utility.CommandGroupMessageArgs(e);
            if (!hasCommandStart)
                return false;

            var args = commandArgs.Split(' ', StringSplitOptions.RemoveEmptyEntries);

            if (!helperCommand.Contains(args[0].ToLower()))
                return false;

            var helperArgs = args.Skip(1);

            using var file = new StreamReader(Config.HelperPath);
            var str = await file.ReadToEndAsync();

            if (!helperArgs.Any())
            {
                await session.SendGroupMessageAsync(e.Sender.Group.Id, new AtMessage(e.Sender.Id), new PlainMessage("\r\n" + str));
                return false;
            }
            else
            {
                var instructions = str.Split("-----", StringSplitOptions.RemoveEmptyEntries).Where(s => !Regex.IsMatch(s, @"^\W+$"));
                bool matched = false;

                foreach (var ins in instructions)
                {
                    var trimedStr = ins.TrimStart();

                    // 判断是否属于该命令的帮助
                    if (trimedStr.Substring(0, trimedStr.IndexOf('\n')).Trim() == helperArgs.Aggregate((x, y) => x+y))
                    {
                        matched = true;
                        await session.SendGroupMessageAsync(e.Sender.Group.Id,
                                                            new AtMessage(e.Sender.Id),
                                                            new PlainMessage("\r\n" + trimedStr));
                        break;
                    }
                }
                if (!matched)
                    await session.SendGroupMessageAsync(e.Sender.Group.Id,
                                                        new IMessageBase[] { new PlainMessage("抱歉，没有对应命令的帮助") },
                                                        ((SourceMessage)e.Chain[0]).Id);
            }
            return false;
        }
    }
}
