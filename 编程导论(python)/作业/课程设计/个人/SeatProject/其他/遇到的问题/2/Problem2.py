""" 随机生成空座 """
seatSold = [] #记录座位是否已售出 0未售 1已售
def Make_seats():
    seatSold.clear()
    file_seat = open("Seats.csv","w",encoding="utf-8-sig",newline="")
    num = 0 #已售座位数 即1的个数
    row = [] #记录每一排座位情况的临时list
    
    #生成已售和未售座位表
    for i in range(10): 
        row.clear()
        for j in range(10):
                f = random.randint(0,1)
                row.append(f) 
                if f == 1:
                    num += 1
        seatSold.append(row) #当前排生成完毕，加入list
        csv.writer(file_seat).writerow(seatSold[i])
        csv.writer(file_seat).writerow(["第一排：",seatSold[0]])
    
    csv.writer(file_seat).writerow(["第1/3/10排："])
    csv.writer(file_seat).writerow(seatSold[0])
    csv.writer(file_seat).writerow(seatSold[2])
    csv.writer(file_seat).writerow(seatSold[9])
    #写入csv文件
    csv.writer(file_seat).writerow(["共100个座位，已售："+str(num)+" 未售："+str(100-num)])
    for i in range(10):
        csv.writer(file_seat).writerow(seatSold[i])
    file_seat.close()
