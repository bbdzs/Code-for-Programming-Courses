time = int(input("输入当前秒数"))

print(time, end="")

hour = time // (60*60)
time -= (hour*60*60)
mint = time // 60
time -= (mint*60)
sec = time 

print("秒为", hour, "小时", mint, "分钟和", sec, "秒")
