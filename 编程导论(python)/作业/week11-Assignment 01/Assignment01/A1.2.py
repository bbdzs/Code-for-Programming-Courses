def main():
    while 1:
        CalculSum = []
        #读入两个数，num1是A，num2是B
        print("请输入一个数")
        num1 = int(input())
        print("请再输入一个数")
        num2 = int(input()) #向下取整，不要小数
        while num2>=2 :
            if num2 % 2 == 1 :
                CalculSum.append(num1) #B是奇数，把A加入求和序列
            num1 *= 2
            num2 = int(num2/2)
        CalculSum.append(num1) #最后一次结果加入求和序列

        #求和输出
        ans = 0
        for i in range(len(CalculSum)) :
            ans += CalculSum[i]
        print("这两个数相乘结果是："+str(ans))

        #询问是否重复运行程序
        repeat = input("\n是否计算其他数(Yes/No)?\n")
        repeat.lower() #输入大小写都行
        if repeat == "no" :
            print("程序退出")
            break

main()
