import turtle

num = int(input("输入一个整数"))
x = -950 #横坐标
cnt = 0

turtle.setup(width=1000,height=800) #画布大小和初始位置
turtle.penup()
turtle.goto(-950,800)
turtle.pendown()

while num != 1 :
    if num % 2 :  #这个数是奇数
        num = num*3 + 1
        turtle.goto(x,num/10-450)
        turtle.write(num)
        x += 15
        cnt += 1
    else :
        num /= 2
        turtle.goto(x,num/10-450)
        turtle.write(num)
        x += 15
        cnt += 1
print("共执行{:}次".format(cnt))

turtle.done()


