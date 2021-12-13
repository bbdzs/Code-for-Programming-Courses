def main():
    print("请输入第1个数",end=" ")
    num1 = input()
    print("请输入第2个数",end=" ")
    num2 = input()
    print("请输入第3个数",end=" ")
    num3 = input()

    #判断输入是否全为数字,是数字继续执行.否则数值错误,退出
    if str.isdigit(num1) and str.isdigit(num2) and str.isdigit(num3) : 
        #全部转成数字便于计算
        num1 = int(num1)
        num2 = int(num2)
        num3 = int(num3)
        
        if num2 == 0 : #除数是0
           print("ZeroDivisionError")
        elif (num2 > num1) : #除数大于被除数 数值错误
            print("ValueError")
        else :
            print(int(num1/num2)+num3) #没问题就输出值
    else :
        print("ValueError")

main()
