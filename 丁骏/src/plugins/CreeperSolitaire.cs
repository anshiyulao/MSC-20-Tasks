using CreeperBot.src.CreeperUtility;
using Mirai_CSharp;
using Mirai_CSharp.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CreeperBot.src.plugins
{
    class CreeperSolitaire
    {
        public readonly long GroupNum;
        protected int currentLine = 0;
        public CreeperSolitaire(long groupNum)
        {
            GroupNum = groupNum;
        }
        
        public async Task<bool> CommandProcessor(MiraiHttpSession session, IGroupMessageEventArgs e)
        {
            using StreamReader reader = new StreamReader(Config.SplitedLyricsPath);
            var command = ((PlainMessage)e.Chain[1]).Message;
            bool correct = false;
            var words = Regex.Split(command, @"\W").Where(s => s != "" && s != " ").ToArray();
            currentLine++;
            int j = 0;
            int i = 0;
            for (i = 0; ; i++, j++)
            {
                if (j == words.Length)
                {
                    correct = true;
                    break;
                }

                // 目前等价内容还不能使用
                if (i == Creeper.Lyrics[currentLine].Content[0].Split().Length)
                {
                    currentLine++;
                    i = 0;
                }

                if (Creeper.Lyrics[currentLine].Content[0].Split()[i] != words[j])
                {
                    correct = false;
                    break;
                }
            }

            if (correct && i == Creeper.Lyrics[currentLine].Content[0].Split().Length)
            {
                await session.SendGroupMessageAsync(e.Sender.Group.Id, Creeper.Lyrics[++currentLine].Voice);
            }
            else if (correct)
            {
                await session.SendGroupMessageAsync(e.Sender.Group.Id, new PlainMessage(Creeper.Lyrics[currentLine]
                                                                                               .Content[0]
                                                                                               .Split()
                                                                                               .Skip(i)
                                                                                               .Aggregate((x, y) => x+" "+y)));
            }
            else
            {
                await session.SendGroupMessageAsync(e.Sender.Group.Id, new AtMessage(e.Sender.Id), new PlainMessage("\r\n你错啦，哈哈，再来一次吧"));
                session.GroupMessageEvt -= this.CommandProcessor;
            }
            return false;
        }

        public static async Task<bool> Register(MiraiHttpSession session, IGroupMessageEventArgs e)
        {
            var (ok, command) = Utility.CommandGroupMessageArgs(e);
            if (!ok) return false;
            if (command.ToLower() != "creeper?") return false;

            await session.SendGroupMessageAsync(e.Sender.Group.Id, Creeper.Lyrics[0].Voice);

            session.GroupMessageEvt += (new CreeperSolitaire(e.Sender.Group.Id)).CommandProcessor;

            return false;
        }
    }
}
