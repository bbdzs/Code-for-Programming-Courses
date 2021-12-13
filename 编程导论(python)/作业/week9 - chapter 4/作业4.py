""" 
提取所有元音字母转为小写加到一个字符串中
把所有不重复的元音字母加到一个字符串中
收集到所有元音字母的次数 
"""

#判断是否为元音字母
def isVowel(s):
    if(s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u') :
        return 1
    return 0

#判断元音字母是否重复
def check_duplicate(s):
    check = 1
    for i in range(len(vowel)) :
        if(s == vowel[i]):
            check = 0
    if(check):
        return 1
    return 0


text = input("请输入一段英文")
temporary = "" #存元音字母的临时字符串
vowel = "" #出现过的元音字母
cnt = 0 #记录出现5个元音字母的次数

for i in range(len(text)) :
    if(isVowel(text[i])) :  #是元音字母
        temporary += text[i].lower()
        if(check_duplicate(text[i])) : #没重复
            vowel += text[i]
            if(len(vowel) == 5): #已经收集到5个元音字母，清空 重新开始计数
                cnt += 1
                vowel = ""

print("所有出现过的元音字母{}".format(temporary))
print("5个元音字母全出现的次数为{}".format(cnt))