#整存整取1年期
money = 90000.0
num = 5

while num > 0 :
    money += 90000*0.02
    num = num-1

print ("整存整取1年期，5年后总额是", round(money,2))


#整存整取5年期
money = 90000.0
num = 5

while num > 0 :
    money += money*0.0305
    num = num-1

print ("整存整取5年期，5年后总额是", round(money,2))
print ("整存整取5年期，收入", round(money-90000,2))

