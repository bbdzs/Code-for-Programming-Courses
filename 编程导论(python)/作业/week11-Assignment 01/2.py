fileName = input("请输入文件名:")
f = open(fileName,"r")
f.readline() #跳过第一行

lineNum = 2 #行号
line = f.readline()
while line :

    if line[0].isalpha : #开头是否是一个单词
        num=1
    else :
        num=0 
        
    for i in range(len(line)-1) : #统计单词数
        if line[i] == " " and line[i+1].isalpha() :
            num += 1
            
    print("第{}行: ".format(lineNum),line,"共{}个单词".format(num))
    lineNum+=1
    line = f.readline()

