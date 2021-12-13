fo = open("test.txt","r")
fn = open("testNEW.txt","w")

strold = fo.read()

#先将读入的字符串转为list
stro = []
for i in range(len(strold)) :
    stro.append(strold[i])

#在列表中查找空格，每五个一组为一行，加入换行符
num = 0
for i in range(len(stro)) :
    if stro[i] == " ":
        num += 1
        if num>0 and num%5 == 0 :
            stro[i] = "\n"

#list转为字符串存入新文件
stro = "".join(stro)
fn.write(stro)

fo.close()
fn.close()
