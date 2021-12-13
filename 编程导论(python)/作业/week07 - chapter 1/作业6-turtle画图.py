import turtle

#显示文字
turtle.penup()
turtle.goto(-100,300)
turtle.pendown()
turtle.write("Hello Everyone!",font=("宋体",20,"normal"))

turtle.penup()
turtle.goto(-110,270)
turtle.pendown()
turtle.write("Created by Cai Qianzhe",font=("宋体",15,"normal"))
##############################################

#太阳花图案

turtle.speed(0)

#初始化坐标、颜色
turtle.penup()
turtle.goto(50,0)
turtle.pendown()
turtle.color("red", "yellow")

#开始绘画
turtle.begin_fill()

for _ in range(36):
    turtle.forward(300)
    turtle.left(170)

turtle.end_fill()
###############################################

#图案3-8

#初始化坐标、颜色
turtle.penup()
turtle.goto(-200,0)
turtle.pendown()

turtle.color("deepskyblue")
turtle.speed(0)

#开始绘画
deg = -90
turtle.setheading(deg)

while deg <= 90:
    turtle.circle(100)
    deg += 5
    turtle.setheading(deg)
#####################################33

#回滚上面两个图案

#调整笔刷速度，否则太慢
turtle.speed(10)
turtle.delay(0)

#开始回滚155次
for _ in range(155):
    turtle.undo()

###########################################
#图案3-7升级版

#正方形画圆
turtle.speed(10)
turtle.delay(1)
turtle.color("cyan")

turtle.penup()
turtle.goto(0,0)
turtle.pendown()

for _ in range(74):
    for _ in range(4):
        turtle.forward(100)
        turtle.right(90)
    turtle.right(5)


#螺旋线
turtle.penup()
turtle.goto(0,0)
turtle.pendown()
turtle.color("coral")

turtle.speed(5)
for i in range(100):
    turtle.forward(i+5)
    turtle.left(92)
turtle.speed(10)
for i in range(100,200):
    turtle.forward(i+5)
    turtle.left(92)
turtle.speed(0)
for i in range(200,350):
    turtle.color("gold")
    turtle.forward(i+5)
    turtle.left(92)
for i in range(350,500):
    turtle.color("yellow")
    turtle.forward(i+5)
    turtle.left(92)

turtle.exitonclick()
