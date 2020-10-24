#nullable enable
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;
using Mirai_CSharp;
using Mirai_CSharp.Models;

namespace CreeperBot.src.CreeperUtility
{
    class Lyric
    {
        public string[] Content { get; set; }
        public static bool IsMulti(Lyric lyric) => lyric.Content.Length > 1;
        public VoiceMessage? Voice { get; set; }

        public Lyric(MiraiHttpSession session, string content, string? voicePath)
        {
            Content = new string[] { content };
            if (voicePath != null)
                Voice = session.UploadVoiceAsync(UploadTarget.Group, voicePath).GetAwaiter().GetResult();
        }

        public Lyric(MiraiHttpSession session, string[] content, string? voicePath)
        {
            Content = content;
            if (voicePath != null)
                Voice = session.UploadVoiceAsync(UploadTarget.Group, voicePath).GetAwaiter().GetResult();
        }

        public Lyric(Lyric voiceTarget, string content)
        {
            Content = new string[] { content };
            Voice = voiceTarget.Voice;
        }

        public Lyric(Lyric voiceTarget, string[] content)
        {
            Content = content;
            Voice = voiceTarget.Voice;
        }
    }
}
