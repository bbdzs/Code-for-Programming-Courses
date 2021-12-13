peotot = 1411778724 #总人口共1411778724人
birth_rate = 0.00852   #出生率
die_rate = 0.00707 #死亡率
sec = 60*60*24*365  #全年总秒数

birth_tot = peotot * birth_rate
birth = birth_tot / sec

die_tot = peotot * die_rate
die = die_tot / sec

print("2021年每秒出生", round(birth,3), "人，死亡", round(die,3), "人")
