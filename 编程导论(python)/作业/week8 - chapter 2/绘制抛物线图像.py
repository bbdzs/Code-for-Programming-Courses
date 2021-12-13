#绘制抛物线图像

import turtle

#调试加速绘图用
turtle.speed(0)
turtle.delay(0)

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
turtle.forward(350)
turtle.write("y",font=("",15,"normal"))
DrawArrow()
turtle.setheading(90)
turtle.backward(350*2)
turtle.forward(350)

#绘制函数图像
Go(-15,225)
for i in range(-15,16) :
    turtle.goto(i,i*i)
turtle.write("y=x^2")

turtle.done()
