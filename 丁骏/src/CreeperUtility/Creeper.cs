#nullable enable
using Mirai_CSharp;
using Mirai_CSharp.Models;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CreeperBot.src.CreeperUtility
{
    static class Creeper
    {
        public static List<Lyric> Lyrics = new List<Lyric>();
        public static void Init(MiraiHttpSession session)
        {
            using var reader = new StreamReader(Config.SplitedLyricsPath);
            string? lyricLine;
            var re = new Regex(@"^-(?<commandName>\w+)(\=(?<param>(\S)+))?");
            int lineNum = 1;
            while ((lyricLine = reader.ReadLine()) != null)
            {
                var result = re.Match(lyricLine);
                if (!result.Success)
                {
                    if (lyricLine == "*rap*")
                        Lyrics.Add(new Lyric(session, lyricLine, Config.VoiceFolder + "rap.mp3"));
                    else if (lyricLine == "*end*")
                        Lyrics.Add(new Lyric(session, lyricLine, Config.VoiceFolder + "end.mp3"));
                    else
                        Lyrics.Add(new Lyric(session, lyricLine, Config.VoiceFolder + lineNum++ + ".mp3"));
                }
                else
                {
                    if (result.Groups["commandName"].Value == "j")
                        Lyrics.Add(
                                      new Lyric(Lyrics[int.Parse(result.Groups["param"].Value)], 
                                                lyricLine)
                                  );
                    else if (result.Groups["commandName"].Value == "m")
                    {
                        lyricLine = lyricLine.Substring(lyricLine.IndexOf(' '));
                        var contents = lyricLine.Split("|", StringSplitOptions.RemoveEmptyEntries).Select(s => s.Trim()).ToArray();
                        Lyrics.Add(new Lyric(session, contents, Config.VoiceFolder + lineNum++ + ".mp3"));
                    }
                }
            }
        }
    }
}
