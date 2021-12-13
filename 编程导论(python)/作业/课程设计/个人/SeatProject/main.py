import csv
import random
import tkinter as tk
import tkinter.messagebox
import turtle

import qrcode

# ---------------------选座页面--------------------------

class Seats_Related():
    #  初始化类
    def __init__(self, master, mv_num):
        if mv_num == 1:
            self.mv_Name = "扬名立万"
        elif mv_num == 2:
            self.mv_Name = "古董局中局"
        elif mv_num == 3:
            self.mv_Name = "长津湖"
        elif mv_num == 4:
            self.mv_Name = "门锁"
        elif mv_num == 5:
            self.mv_Name = "你的世界如果没有我"
        elif mv_num == 6:
            self.mv_Name = "只要你过的比我好"
        elif mv_num == 7:
            self.mv_Name = "梅艳芳"
        elif mv_num == 8:
            self.mv_Name = "笨鸟大冒险"
        self.seatSold = []  # 记录座位是否已售出 0未售 1已售
        self.select={}  # 存储用户选择座位的字典
        self.num = 0  # 已售座位数 即1的个数
        # 创建选座窗口
        self.seatScreen = tk.Toplevel(master=master) 
        self.seatScreen.title("电影《"+self.mv_Name+"》 请选择座位")
        x, y = self.Cal_center(800, 800)
        self.seatScreen.geometry("%dx%d+%d+%d" %(800,800,x,y))
        self.seatScreen.resizable(width=False, height=False) #禁止拉伸

    def Cal_center(self,w, h):
        # 屏幕宽高
        scnWidth = root.winfo_screenwidth()
        scnHeight = root.winfo_screenheight()
        # 窗口宽高
        wdWidth = w
        wdHeight = h
        x = (scnWidth-wdWidth) / 2
        y = (scnHeight-wdHeight) / 2
        return x, y

        

    def Seatmain(self):
        self.canvas = tk.Canvas(master=self.seatScreen, width=800, height=800)
        
        self.canvas.pack()
        self.turtle_screen = turtle.TurtleScreen(self.canvas)
        self.canvas_Seat = turtle.RawTurtle(self.turtle_screen)
        
        self.Make_seats()
        self.Draw_seats()
        
        # 当点击窗口x退出时执行
        self.seatScreen.protocol("WM_DELETE_WINDOW", on_closing) # 检测窗口关闭 捕获命令WM_DELETE_WINDOW    
        self.seatScreen.mainloop() 

    # ================功能与计算判断====================
    """ 随机生成销售情况 空座 """
    def Make_seats(self):
        self.seatSold.clear()  # 可能会多次调用该函数，先清除此前记录
        file_seat = open("Seats.csv","w",encoding="utf-8-sig",newline="")
        csv.writer(file_seat).writerow(["电影《"+self.mv_Name+"》"])
        self.num = 0  # 已售座位数 即1的个数
        row = []  # 记录每一排座位情况的临时list
        # 生成已售和未售座位表
        for i in range(10): 
            row.clear()
            for j in range(10):
                    f = random.choice([0]*4+[1]*2)  # 以未售约是已售概率的两倍随机生成
                    row.append(f) 
                    if f == 1:
                        self.num += 1
            self.seatSold.append(row.copy())  # 当前排生成完毕，加入list

        # 写入csv文件
        csv.writer(file_seat).writerow(["共100个座位，已售："+str(self.num)+" 未售："+str(100-self.num)])
        for i in range(10):
            csv.writer(file_seat).writerow(self.seatSold[i])
        file_seat.close()

    """ 画辅助网格 """
    def AuxiliaryLine(self):
        # 划横线
        y=160
        for i in range(11):
            self.Goto(-200,y)
            self.canvas_Seat.write(str(y))
            self.canvas_Seat.forward(400)
            y -= 40
        
        # 画竖线
        self.canvas_Seat.right(90)
        x = -200
        for i in range(11):
            self.Goto(x,160)
            self.canvas_Seat.write(x)
            self.canvas_Seat.forward(400)
            x += 40

# ============================== 点击功能 =============================
    """ 根据坐标计算座位号 """
    def Cal_seatNumber(self,x,y):
        zuo = 0
        if abs(x) < 40 :
            tmp = 1
        else:
            tmp = int(abs(x)/40)+1
        if(x >= 0):
            zuo = 5+tmp
        else:
            zuo = 6-tmp

        pai = 0
        tmp = int(abs(y)/40)
        if y > 0:
            if y <= 40:
                pai = 4
            else:
                pai = 4-tmp
        else:
            if y >= -40:
                pai = 5
            else:
                pai = 5+tmp
            
        return pai, zuo

    """ 判断是否可以选中 """
    def Check_ClickIcon(self,pai, zuo, x, y): 
        if zuo != 1:
            x -= (zuo-1)*40
        if pai != 1:
            y += (pai-1)*40

        if -195<=x<=-165 and 125<=y<=155:
            if self.seatSold[pai-1][zuo-1] == 1:  # 此前已被售出，不可选
                return 0
            if (pai,zuo) not in self.select:  # 可以选择
                self.select[(pai,zuo)] = 1
                return 1 
            if self.select[(pai,zuo)] == 1:  # 已被选，点击应取消选择
                del self.select[(pai,zuo)]
                return 2

    """ 计算x排x座对应的画笔坐标，用于选择座位时替换原图标    """     
    def Cal_pos(self,pai,zuo):
        x = -180+40*(zuo-1)
        y = 140-40*(pai-1)
        return x,y

    """ 点击确定按钮 """
    def Button_Yes(self): 

        if not self.select:  # 用户没选择座位
            if tkinter.messagebox.showwarning(title="提示", message="您还没有选择座位，请选择合适的座位进行购票。"):
                pass
            else:
                file_seat = open("Seats.csv", "a+", newline='', encoding="utf-8-sig")  # 写入用户购买信息
                csv.writer(file_seat).writerow(["用户未买票"])
                file_seat.close()
                root.destroy()
        else:  # 用户已选座位
            # 用户购买信息已确定，更新列表并新建字符串便于输出
            str_selectSeats = ""  # 把用户选择的座位转成字符串，便与输出
            for pai,zuo in self.select.keys():
                str_selectSeats += (str(pai)+"排"+str(zuo)+"座 ")

            if tkinter.messagebox.askyesno(title="提示", message="电影《"+self.mv_Name+"》\n您选择的座位是："+str_selectSeats+".\n是否需要重选？", default="no"):
                pass
            else:
                for pai,zuo in self.select.keys():
                    self.seatSold[pai-1][zuo-1] = 1  # 更新列表 用户新选的座位变为已售
                self.num += len(self.select)
                file_seat = open("Seats.csv", "w", newline='', encoding="utf-8-sig")  # 需要重新覆盖写入，更新用户购买信息
                csv.writer(file_seat).writerow(["电影《"+self.mv_Name+"》"])
                csv.writer(file_seat).writerow(["共100个座位，已售："+str(self.num)+" 未售："+str(100-self.num)])
                for i in range(10):
                    csv.writer(file_seat).writerow(self.seatSold[i])
                csv.writer(file_seat).writerow(["用户购买了"+str_selectSeats])
                file_seat.close()
                self.seatScreen.destroy()

                # ==================== 二维码功能==================
                # 创建窗口
                self.QRscreen = tk.Toplevel(master=root)
                self.QRscreen.title("购票成功")
                # 生成二维码
                qr = qrcode.QRCode()
                qr.add_data("您购买的电影为《"+self.mv_Name+"》\n座位："+str_selectSeats)
                img_QR = qr.make_image(fill_color='black', back_color='white')  # 生成二维码
                img_QR.save("Ticket.png")  # 保存到硬盘上
                # 窗口显示
                lwords = tk.Label(self.QRscreen,text="请保留好观影二维码(已自动保存至程序文件夹)，欢迎再次光临！")
                lwords.pack()
                img_QR = tk.PhotoImage(master=self.QRscreen, file="./Ticket.png")
                tk.Label(self.QRscreen,image=img_QR).pack()
                tk.Button(self.QRscreen,width=20,height=2,text="确定", command=root.destroy).pack()
                #取得并计算窗口大小参数 自动居中窗口
                self.QRscreen.update()  # 更新窗口数据 否则获取的窗口宽高永远为1
                wdWidth = self.QRscreen.winfo_width()
                wdHeight = self.QRscreen.winfo_height()
                x, y = self.Cal_center(wdWidth, wdHeight)  # 设置宽高 窗口自动居中
                self.QRscreen.geometry("%dx%d+%d+%d" %(wdWidth,wdHeight,x,y))

                # 当点击窗口右上x退出
                self.QRscreen.protocol("WM_DELETE_WINDOW", root.destroy)  # 检测窗口关闭 捕获命令WM_DELETE_WINDOW      
                
                self.QRscreen.mainloop()


    """ 点击按钮区域+选座功能 """
    def Click_deal(self, x, y):
        # 处理点击确定按钮
        if -40<=x<=40 and -330<=y<=-290:  # 点击了确定按钮
            self.Button_Yes() 
            
        # 处理点击座位
        pai, zuo = self.Cal_seatNumber(x,y)  # 计算座位号
        
        if 1<=pai<=10 and 1<=zuo<=10:  # 该座位号存在
            f = self.Check_ClickIcon(pai, zuo, x, y)  # 检查是否可以选中 0不可选 1变绿 2变灰
            if f == 1:  # 选中变绿
                self.canvas_Seat.goto(self.Cal_pos(pai,zuo)) 
                self.canvas_Seat.clearstamp(self.idSeat[pai-1][zuo-1])
                self.canvas_Seat.shape(shapeGreen)
                self.idSeat[pai-1][zuo-1] = self.canvas_Seat.stamp()
            elif f == 2:  # 取消选择 变灰
                self.canvas_Seat.goto(self.Cal_pos(pai,zuo)) 
                self.canvas_Seat.clearstamp(self.idSeat[pai-1][zuo-1])
                self.canvas_Seat.shape(shapePray)
                self.idSeat[pai-1][zuo-1] = self.canvas_Seat.stamp()

    # ================绘图-===================

    """ 无痕移动到某一坐标 用于画辅助元素 """
    def Goto(self, x, y):
        self.canvas_Seat.penup()
        self.canvas_Seat.goto(x,y)
        self.canvas_Seat.pendown()

    """ 画矩形 """
    def Draw_rectangle(self, length, width):
        self.canvas_Seat.forward(length)
        self.canvas_Seat.right(90)
        self.canvas_Seat.forward(width)
        self.canvas_Seat.right(90)
        self.canvas_Seat.forward(length)
        self.canvas_Seat.right(90)
        self.canvas_Seat.forward(width)

    idSeat = []  # 二维数组 记录每个座位的stamp_id，便于点击时清除
    def Draw_seats(self):
        self.canvas_Seat.speed(0)
        self.turtle_screen.delay(0)
        self.turtle_screen.bgcolor("lightyellow")

        self.turtle_screen.addshape(shapePray)
        self.turtle_screen.addshape(shapeGreen)
        self.turtle_screen.addshape(shapeRed)
    #    AuxiliaryLine() #画辅助网格

    # ===========================根据销售情况生成最初座位==========================
        self.canvas_Seat.penup()
        self.canvas_Seat.setheading(0)
        x = -180
        y = 140

        row = []  # 记录每一排stamp_id的临时数组
        for i in range(10):  # 画行
            row.clear()
            for j in range(10):  # 画列
                self.canvas_Seat.goto(x,y)
                if self.seatSold[i][j] == 1:  # 根据Make_seat函数生成的座位来决定放置座位颜色
                    self.canvas_Seat.shape(shapeRed)
                else:
                    self.canvas_Seat.shape(shapePray)
                row.append(self.canvas_Seat.stamp())  #放置座位并记录id
                x += 40
            self.idSeat.append(row.copy())
            x = -180
            y -= 40

        # ===================画辅助元素=================
        # 排号旁的竖线
        self.canvas_Seat.color("pink") #sandybrown
        self.canvas_Seat.pensize(1)
        self.Goto(-210,170)
        self.canvas_Seat.setheading(270)
        self.canvas_Seat.forward(420)
        self.canvas_Seat.penup()
        
        # 排号文字
        self.canvas_Seat.color("black")
        y = 130
        for i in range(1,10):
            self.Goto(-230,y)
            self.canvas_Seat.write(str(i),move = False, font=("黑体", 18, "normal"))
            y -= 40
        self.Goto(-237,y)
        self.canvas_Seat.write("10", move = False, font=("黑体", 18, "normal"))

        # 屏幕中央线+长方形
        self.canvas_Seat.color("lightgreen")
        self.Goto(0,200)
        self.canvas_Seat.pensize(2)
        self.canvas_Seat.setheading(270)
        self.canvas_Seat.forward(450)  # 屏幕中央线
        self.Goto(-55,205)
        self.canvas_Seat.color("lightgreen")
        self.canvas_Seat.pensize(10)
        self.canvas_Seat.setheading(0)
        self.canvas_Seat.begin_fill()
        self.Draw_rectangle(110,35)  # 矩形
        self.canvas_Seat.end_fill()
        self.Goto(-48,175)
        self.canvas_Seat.color("white")
        self.canvas_Seat.write("银幕中央", move = False, font=("楷体", 18, "bold"))

        # 最上方三个座位图标说明
        self.Goto(-1200,365) # 画底色
        self.canvas_Seat.color("linen")
        self.canvas_Seat.pensize(50)
        self.canvas_Seat.setheading(0)
        self.canvas_Seat.forward(2400)
        self.canvas_Seat.penup()
        self.Goto(-180,365) # 说明图标
        self.canvas_Seat.shape(shapePray)
        self.canvas_Seat.stamp()
        self.canvas_Seat.forward(150)
        self.canvas_Seat.shape(shapeGreen)
        self.canvas_Seat.stamp()
        self.canvas_Seat.forward(150)
        self.canvas_Seat.shape(shapeRed)
        self.canvas_Seat.stamp()
        self.Goto(-155,353) # 说明文字
        self.canvas_Seat.penup()
        self.canvas_Seat.color("black")
        self.canvas_Seat.write("可选", move = False, font=("黑体", 19, "normal"))
        self.canvas_Seat.forward(150)
        self.canvas_Seat.write("已选", move = False, font=("黑体", 19, "normal"))
        self.canvas_Seat.forward(150)
        self.canvas_Seat.write("已售", move = False, font=("黑体", 19, "normal"))

        # 画银幕梯形
        self.Goto(-200,340)
        self.canvas_Seat.setheading(320)
        self.canvas_Seat.pendown()
        self.canvas_Seat.pensize(3)
        self.canvas_Seat.pencolor("lightcyan")
        self.canvas_Seat.fillcolor("lightcyan")
        self.canvas_Seat.begin_fill()
        self.canvas_Seat.forward(60)
        self.canvas_Seat.left(40)
        self.canvas_Seat.forward(300)
        self.canvas_Seat.left(40)
        self.canvas_Seat.forward(60)
        self.canvas_Seat.end_fill()

        # 银幕文字
        self.Goto(-95,300)
        self.canvas_Seat.color("cornflowerblue")
        self.canvas_Seat.write("影 厅 银 幕", move = False, font=("黑体", 25, "bold"))

        # 确定按钮
        self.Goto(-40,-290)
        self.canvas_Seat.color("palegreen")
        self.canvas_Seat.setheading(0)
        self.canvas_Seat.begin_fill()
        self.Draw_rectangle(80,40)
        self.canvas_Seat.end_fill()
        self.Goto(-26,-325)
        self.canvas_Seat.color("black")
        self.canvas_Seat.write("确定", move = False, font=("宋体",20,"normal"))

        self.canvas_Seat.penup()
        self.canvas_Seat.hideturtle()
        self.turtle_screen.onscreenclick(self.Click_deal)
# ====================选座页面主程序=============================
""" 选座程序 """
def Seats(mv_num):
    root.withdraw()
    s = Seats_Related(root, mv_num)
    s.Seatmain()
# --------------------------end------------------------


# ------------------首页----------------- 
""" 注册并添加图标 全局变量 其它函数可用  """
shapePray = "./img/pray.gif"
shapeRed = "./img/red.gif"
shapeGreen = "./img/green.gif"

""" 显示图片 """    
def Show_Image():
    for i in range(1,5):
        l = tk.Label(frm_Up, image=img_mv[i])
        l.grid(row=0, column=i-1)  # 图片list下标从1开始，grid列从0开始，差一个

    for i in range(5,9):
        l = tk.Label(frm_Down, image=img_mv[i])
        l.grid(row=0, column=i-5) 

""" 设置按钮 """
def Show_Buttom():
    # 点击按钮传入电影编号便与输出 启动选座界面
    tk.Button(frm_Up, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(1)).grid(row=1, column=0)
    tk.Button(frm_Up, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(2)).grid(row=1, column=1)
    tk.Button(frm_Up, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(3)).grid(row=1, column=2)
    tk.Button(frm_Up, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(4)).grid(row=1, column=3)
    tk.Button(frm_Down, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(5)).grid(row=1, column=0)
    tk.Button(frm_Down, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(6)).grid(row=1, column=1)
    tk.Button(frm_Down, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(7)).grid(row=1, column=2)
    tk.Button(frm_Down, text="点击购票", activebackground="white", cursor="hand2", command=lambda: Seats(8)).grid(row=1, column=3)
    

""" 首页显示 """
def Show_main():
    label_title = tk.Label(root, width=20, height=2, text="正在热映(8部)", fg="red",font=("黑体",20))
    label_title.pack()

    Show_Image()
    Show_Buttom()

    frm_Up.pack()
    frm_Down.pack()
# -------------------end----------------------- 

""" 获得屏幕分辨率，计算窗口参数 用于自动居中窗口 """

def Cal_center():
    # 屏幕宽高
    scnWidth = root.winfo_screenwidth()
    scnHeight = root.winfo_screenheight()
    # 窗口宽高
    wdWidth = 1000
    wdHeight = 650
    x = (scnWidth-wdWidth) / 2
    y = (scnHeight-wdHeight) / 2
    root.geometry("%dx%d+%d+%d" %(wdWidth,wdHeight,x,y))

# ------------------主程序---------------- 

root = tk.Tk()
Cal_center()  # 设置窗口宽高并居中
root.title("电影购票系统")
root.resizable(width=False, height=False)  # 禁止拉伸

# 首页的两个框架 上下显示
frm_Up = tk.Frame(root)
frm_Down = tk.Frame(root)

# 导入图片 全局变量
img_mv = []
img_mv.append(0)  # 使下面的图像与下标对应
for i in range(1,9):
    img_mv.append( tk.PhotoImage(master=root, file="./img/mv"+str(i)+".png"))

Show_main()

# 当点击窗口右上x退出时执行
def on_closing():
    if tkinter.messagebox.askokcancel("询问", "是否退出购票", default="cancel"):
        root.destroy()
root.protocol("WM_DELETE_WINDOW", on_closing)  # 检测窗口关闭 捕获命令WM_DELETE_WINDOW

root.mainloop()

