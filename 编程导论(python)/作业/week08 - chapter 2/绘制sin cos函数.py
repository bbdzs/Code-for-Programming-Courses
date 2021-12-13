#绘制sin cos函数图像

import math
import turtle

""" #调试加速绘图用
turtle.speed(0)
turtle.delay(0) """

#无痕调整画笔坐标
def Go(x,y) : 
    turtle.penup()
    turtle.goto(x,y)
    turtle.pendown()

#画坐标轴箭头
def DrawArrow() :
    turtle.fillcolor("black")
    turtle.begin_fill()
    turtle.left(150)
    turtle.forward(10)
    turtle.left(120)
    turtle.forward(10)
    turtle.left(120)
    turtle.forward(10)
    turtle.end_fill()


#绘制坐标轴
#绘制x轴
turtle.write("0",font=("",15,"normal"))
turtle.forward(350)
turtle.write("x",font=("",15,"normal"))
DrawArrow()
turtle.setheading(0)
turtle.backward(350*2)
turtle.forward(350)

#绘制y轴
turtle.left(90)
turtle.forward(250)
turtle.write("y",font=("",15,"normal"))
DrawArrow()
turtle.setheading(90)
turtle.backward(250*2)
turtle.forward(250)

#绘制sin函数
Go(-300,0)
turtle.pencolor("Blue")

for i in range(-300,301) :
    x = i*(2*math.pi/100) #turtle画布中每100个单位为三角函数的一个周期
    y = math.sin(x)*100    
    turtle.goto(i,y)

#标出经过x轴时的坐标及函数名
    if(i == -275) :
        turtle.write("y=sinx")
    if(i%50 == 0 and i != 0) :
        turtle.write(str(int(i/50))+"\u03c0",font=(9))


#绘制cos函数
turtle.pencolor("red")

Go(-340,-15)
turtle.write("y=cosx")

Go(-325,0)
for i in range(-325,276) :
    x = i*(2*math.pi/100)
    y = math.cos(x)*100    
    turtle.goto(i,y)

turtle.done()
