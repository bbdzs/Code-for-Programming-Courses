import turtle
import random

def drawArrow() :
    turtle.left(150)
    turtle.forward(15)
    turtle.backward(15)
    turtle.left(60)
    turtle.forward(15)
    turtle.backward(15)

cnt = int(input("请输入画线次数"))
turtle.backward(300)
turtle.forward(600) #x轴
turtle.write("x")
drawArrow()
turtle.home()

turtle.left(90) #y轴
turtle.backward(300)
turtle.forward(600)
turtle.write("y")
drawArrow()
turtle.home()

for i in range(cnt) :
    length = random.randint(50,400) 
    direction = random.randint(0,360)
    turtle.setheading(direction)
    turtle.forward(length)
    drawArrow()
    turtle.home()

turtle.done()
