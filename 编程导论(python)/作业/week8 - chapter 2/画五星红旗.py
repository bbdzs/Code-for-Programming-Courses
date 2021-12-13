import turtle

""" turtle.speed(0)
turtle.delay(0) """

#无痕调整画笔坐标
def Go(x,y) : 
    turtle.penup()
    turtle.goto(x,y)
    turtle.pendown()

#传入朝向画小五角星
def DrawSmallStar(degree):
    turtle.seth(degree)
    turtle.fillcolor("yellow")
    turtle.pencolor("yellow")

    turtle.begin_fill()
    for x in range(5):
        turtle.forward(38.0417418)
        turtle.right(144)
    turtle.end_fill()


#国旗大小600*400
turtle.pencolor("red")
turtle.fillcolor("red")
turtle.begin_fill()
Go(-300,200)
turtle.goto(300,200)
turtle.goto(300,-200)
turtle.goto(-300,-200)
turtle.goto(-300,200)
turtle.end_fill()

#绘制大五角星
Go(-200,160)
turtle.pencolor("yellow")
turtle.fillcolor("yellow")
turtle.begin_fill()

turtle.setheading(288)
for i in range(5):
    turtle.forward(120)
    turtle.right(144)
turtle.end_fill()

#第一个小五角星
Go(-100 - 17.3145, 160 - 6.174)
DrawSmallStar(48.96347)

#第二个小五角星
Go(-60 - 19.7948663580, 120 - 2.857143)
DrawSmallStar(36.213211)

#第三个小五角星
Go(-60 - 19.5, 60 + 5.714285848)
DrawSmallStar(5)

#第四个小五角星
Go(-100 - 17.2, 20 + 15.99999)
DrawSmallStar(-35.1301)

turtle.hideturtle()
turtle.done()