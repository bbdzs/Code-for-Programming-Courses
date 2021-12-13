oil_sc = 19477 #原油生产量
oil_xh = 64965 #原油消费量
oil_cb = 3773 #原油储备

oil_impt = oil_xh - oil_sc #原油进口量

oil_daysc = oil_sc / 365 #每天原油生产量
oil_dayxh = oil_xh / 365 #每天原油消耗量

oil_day = oil_cb / (oil_dayxh - oil_daysc) #由 （原油储备 + n*原油生产 = n*原油消耗）可推得天数n

print("以2020年为参照，中国每年消耗原油{0:d}万吨，生产原油{1:d}万吨，原油储备{2:d}万吨，需要进口原油{3:d}万吨。".format(oil_xh,oil_sc,oil_cb,oil_impt))
print("若战争爆发，中国的原油储备和自产原油可以维持{0:.1f}天。".format(oil_day))
