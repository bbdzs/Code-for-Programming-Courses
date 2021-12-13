""" 求总成绩和平均成绩后写入文件 """

import csv

""" 读入并储存文件到list """
scoreFile = open("score.csv","r",encoding='utf-8-sig')
line = csv.reader(scoreFile,delimiter=',')
perRow=[]
for row in line:
    perRow.append(row)
scoreFile.close()

""" 求每个人的总成绩和平均 """
for i in range(1,4) :
    sum = 0
    for j in range(1,4):
        sum += int(perRow[i][j])
    perRow[i][4] = str(sum) #第i个人的总成绩
    perRow[i][5] = str(sum/3) #第i个人的平均成绩

""" 求成绩的平均 """
sum = [0.0]*6 #用于记录每一列的和
for i in range(1,4) :
    for j in range(1,6):
        sum[j] += float(perRow[i][j])
for i in range(1,6):
    perRow[4][i] = str(sum[i]/3)

print(perRow)

""" 将结果写入文件 """
scoreFile = open("score.csv","w",encoding="utf-8-sig",newline="")
for i in range(5):
    csv.writer(scoreFile).writerow(perRow[i])

scoreFile.close()
