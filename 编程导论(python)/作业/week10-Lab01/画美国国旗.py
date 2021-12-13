import turtle


def drawSquar():  # 画国旗的红条纹
    turtle.goto(300,175)
    turtle.setheading(180)
    turtle.color('#B22234')
    turtle.begin_fill()
    for i in range(7):
        turtle.forward(600)
        turtle.left(90)
        turtle.forward(350 / 13)
        turtle.left(90)
        turtle.forward(600)
        turtle.right(90)
        turtle.forward(350 / 13)
        turtle.right(90)
    turtle.end_fill()


def drawSmallsqure():  # 画国旗左上角的蓝色矩形
    turtle.color('#3C3B6E') 
    turtle.begin_fill()  # 开始填充
    turtle.left(90)
    turtle.forward(350 / 2)
    turtle.left(90)
    turtle.forward(300)
    turtle.left(90)
    turtle.forward(350 * 7 / 13)
    turtle.left(90)
    turtle.forward(300)
    turtle.end_fill()  # 填充结束

def drawStarsInLine(x,y,num) : # 画每行的小星星
    for i in range(num):    # 每行画num个星星
            turtle.goto(x, y)  
            turtle.color('white')
            turtle.begin_fill()
            turtle.setheading(108)
            for j in range(5):  # 画每一个星星
                turtle.left(144)
                turtle.forward(20)
            x -= 50
            turtle.end_fill()


def drawStars():  # 画左上角的小星星，七行，四行六个，三行五个
    x = -25
    y = 10
    for i in range(4):  # 画四行 每行六个星星
        
        drawStarsInLine(x,y,6)
        y += 350 / 13 * 2
    
    x = -50
    y = 350 / 13 +10    
    for i in range(3):  # 画三行 每行五个
        drawStarsInLine(x,y,5)
        y += 350 / 13 * 2


def main() :
    turtle.setup(1000.0, 600.0) 
    turtle.speed(0)
    turtle.penup()  # 隐藏画笔画出的线 只要填充的色块即可

    drawSquar()  # 画国旗的条纹

    turtle.home()

    drawSmallsqure()  # 画国旗左上角的小矩形

    turtle.home()

    drawStars()  # 画左上角的小星星

    turtle.hideturtle()
    turtle.done()

main()
