# 歌词接龙
# 生成歌词list
Lyric = ("Creeper?",\
"Awww man",\
"So we back in the mine, got our pick axe swinging from side to side",\
"Side, side to side",\
"This task a grueling one",\
"Hope to find some diamonds tonight, night, night",\
"Diamonds tonight",\
"Heads up, you hear a sound",\
"Turn around and look up, total shock fills your body",\
"Oh no it's you again",\
"I could never forget those eyes, eyes, eyes",\
"Eyes, eyes, eyes",\
"'Cause baby tonight",\
"The creeper's trying to steal all our stuff again",\
"'Cause baby tonight, you grab your pick, shovel and bolt again", \
"And run, run until it's done, done",\
"Until the sun comes up in the morn'",\
"'Cause baby tonight, the creeper's trying to steal all our stuff again",\
"Just when you think you're safe",\
"Overhear some hissing from right behind",\
"Right, right behind",\
"That's a nice life you have",\
"Shame it's gotta end at this time, time, time",\
"Time, time, time, time",\
"Blows up, then your health bar drops",\
"You could use a 1-up, get inside don't be tardy",\
"So now you're stuck in there",\
"Half a heart is left but don't die, die, die",\
"Die, die, die, die",\
"'Cause baby tonight",\
"The creeper's trying to steal all your stuff again",\
"'Cause baby tonight, you grab your pick, shovel and bolt again",\
"And run, run until it's done, done",\
"Until the sun comes up in the morn'",\
"'Cause baby tonight",\
"The creeper's trying to steal all your stuff again",\
"Creepers, you're mine",\
"Dig up diamonds, and craft those diamonds and make some armor",\
"Get it baby, go and forge that like you so, MLG pro",\
"The sword's made of diamonds, so come at me bro",\
"Training in your room under the torch light",\
"Hone that form to get you ready for the big fight",\
"Every single day and the whole night",\
"Creeper's out prowlin'",\
"alright",\
"Look at me, look at you",\
"Take my revenge that's what I'm gonna do",\
"I'm a warrior baby, what else is new",\
"And my blade's gonna tear through you",\
"Bring it",\
"'Cause baby tonight",\
"The creeper's trying to steal all our stuff again",\
"Yeah baby tonight, grab your sword, armor and gold, take your revenge",\
"So fight, fight like it's the last",\
"Last night of your life, life, show them your bite",\
"'Cause baby tonight",\
"The creeper's trying to steal all our stuff again",\
"'Cause baby tonight, you grab your pick, shovel and bolt again",\
"And run, run until it's done, done",\
"Until the sun comes up in the morn'",\
"'Cause baby tonight, the creepers tried to steal all our stuff again")
couplet = ('对穿肠：一乡二里，共三夫子不识四书五经六义，竟敢教七八九子，十分大胆。',
'十室九贫，凑得八两七钱六分五毫四厘，尚且又三心二意，一等下流。',
'对穿肠：图画里，龙不吟，虎不啸，小小书童可笑可笑。',
'棋盘上，车无轮，马无缰，叫声将军提防提防。',
'对穿肠：莺莺燕燕翠翠红红处处融融洽洽。',
'雨雨风风花花叶叶年年暮暮朝朝。',
'对穿肠：十口心思，思君思国思社稷。',
'八目尚赏，赏花赏月赏秋香。',
'对穿肠：我上等威风，显现一身虎胆。',
'你下流贱格，露出半个龟头。',
'对穿肠：你家坟头来种树。',
'汝家澡盆杂配鱼。',
'对穿肠：鱼肥果熟入我肚。',
'你老娘来亲下厨。',
'对穿肠：……'
)

def main1():
    Ly_Num = 0
    while Ly_Num < len(Lyric):
        print(Lyric[Ly_Num])
        Ly_Num += 1
        if Ly_Num == len(Lyric):
            print('well done')
            break
        Answer = input()
        if Answer == Lyric[Ly_Num]:
            Ly_Num += 1
        elif Answer in ['quit']:
            break
        else:
            print("oops!you are wrong,don't give up and let's restart")
            Ly_Num =0
def main2():
    coup_Num = 0
    while coup_Num < len(couplet):
        print(couplet[coup_Num])
        coup_Num += 1
        if coup_Num == len(couplet):
            print('噗（口吐鲜血倒地）')
            break
        Answer = input()
        if Answer == couplet[coup_Num]:
            coup_Num += 1
        elif Answer in ['quit']:
            break
        else:
            print("错啦，重来！")
            coup_Num =0

a = int(input('你想选择哪一个进行接龙呢？（输入quit以随时退出）\n1.creeper\t2.对王之王\n'))
if a == 1:
    main1()
elif a == 2:
    main2()

