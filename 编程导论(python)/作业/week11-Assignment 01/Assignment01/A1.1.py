integ = [0,1,2,3,4,5,6,7,8,9] #用于暴力枚举的数字
vis = [1,1,1,1,1,1,1,1,1,1] #记录当前枚举的数字是否可用
alaph = "aSENDMORY"
num = [0,0,0,0,0,0,0,0,0] #储存字母对应的替换数字

def check():
#      send + more = money 
#下标：1234 + 5672 = 56328

    #当前枚举情况下的三个数
    send = num[1]*1000 + num[2]*100 + num[3]*10 + num[4]
    more = num[5]*1000 + num[6]*100 + num[7]*10 + num[2]
    money = num[5]*10000 + num[6]*1000 + num[3]*100 + num[2]*10 + num[8]

    #判断等式成立就输出
    if send+more == money :
        for i in range(1,9) :
            print(alaph[i],"is",num[i])
        print()
    return

def SetNumber(now):
    if now>8: #边界
        return
    
    for i in range(len(integ)) : #按顺序给每个字母填所有数字
        if i == 0 and now == 5 : #m不能代表0
            continue

        t = integ[i] 
        if vis[t] == 1: 
            num[now] = t #数字还没用过可以用于替换
        
            vis[t] = 0

            if now == 8: #填充完成，检查是否合法
                check()
            
            SetNumber(now+1) #继续填下一个字母
            vis[t] = 1 #回溯，取不到当前数字，标记可用
    return

def main():
    SetNumber(1) #递归给每个字母赋值替换，按"sendmory"顺序用整数代替字母传参

main()
