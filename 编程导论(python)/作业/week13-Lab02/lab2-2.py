""" 查询学生成绩 """

import csv

""" 读入文件到list """
scoreFile = open("score.csv","r",encoding="utf-8-sig")
line = csv.reader(scoreFile,delimiter=',')
perRow = []
for row in line:
    perRow.append(row)
scoreFile.close()

print(perRow)


""" 查找学生 """
name = input("请输入你想查询的学生姓名：")

f = 1
for i in range(1,4) :
    if name==perRow[i][0] :
        print("作业1 "+perRow[i][1]+"  作业2 "+perRow[i][2]+"  期末考试 "+perRow[i][3]+"  总成绩 "+perRow[i][4])
        f = 0
if f :
    print("此人不存在!")
