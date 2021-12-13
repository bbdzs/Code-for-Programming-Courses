# countries and capitals

capital_dict = {}

country,capital = input("Enter a country and a capital comma separated (Q,Q to quit): ").split(',')

while (country,capital) != ('Q','Q'):
    capital_dict[country]=capital
    country,capital = input("Enter a country and a capital comma separated (Q,Q to quit): ").split(',')

#print(sorted(capital for capital in list(capital_dict.values())))
""" 以列表输出字典第二维 for接收字典转的列表(元组构成)需要两个变量，只要第二个变量"""
#print([capital for country,capital in list(capital_dict.items())]) 
""" 以列表输出字典第二维 for接收字典转的列表(元组构成)需要两个变量，只要第二个变量"""
#print(sorted(capital for country,capital in list(capital_dict.items())))
""" 排序时转不转列表 [] 均可 """
#print(sorted([capital for country,capital in list(capital_dict.items()])))
