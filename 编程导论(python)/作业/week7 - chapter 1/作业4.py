num_car = 575e4
pf_car = 0.15 #一辆车一千米排放量 kg
length = 15000 #每辆车行驶距离 km

pf_tot = num_car * pf_car * length
print("北京2015年全年机动车排放废气{0:.2f}吨".format(pf_tot))

peo_tot = 2114e4
peo = pf_tot / peo_tot
print("平均每人吸入{0:.2f}吨废气".format(peo))
