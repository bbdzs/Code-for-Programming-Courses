import random

word = input("请输入一个单词")

length = len(word)
s = word[0] #取出单词首字母
e = word[length-1] #取出单词尾字母
scramble = list(word[1:length-1])#取出需要打乱的部分

random.shuffle(scramble) #打乱顺序

print(s+"".join(scramble)+e) #将list转为string 拼接后输出 