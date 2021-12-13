txt1=input("请输入要交换的文件1的文件名:")
txt2=input("请输入要交换的文件2的文件名:")

f1=open(txt1, "r+")
f2=open(txt2, "r+")

l1=f1.read()
l2=f2.read()

#两文件光标调到开头并删掉后面所有内容
f1.seek(0) 
f1.truncate()
f2.seek(0)
f2.truncate()

f1.write(l2)
f2.write(l1)

f1.close()
f2.close()
