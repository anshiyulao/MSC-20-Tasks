using System;
using System.Collections.Generic;
using System.Text;
using Mirai_CSharp;
using Mirai_CSharp.Models;

namespace CreeperBot.src
{
    [Obsolete("警告：将会进行单元测试")]
    static class UnitTest
    {
        public static void Run(MiraiHttpSession session, long target)
        {
            //session.SendGroupMessageAsync(target, session.UploadVoiceAsync(UploadTarget.Group, @"..\..\..\dependence\creeper\1.mp3").GetAwaiter().GetResult());
            /*
            foreach (var voices in CreeperUtility.Creeper.Lyrics)
            {
                session.SendGroupMessageAsync(target, voices.Voice);
            }
            */
        }
    }
}
