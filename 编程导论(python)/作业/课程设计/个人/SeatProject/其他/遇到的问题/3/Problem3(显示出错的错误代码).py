import tkinter as tk

import DrawSeat  # 自己写的另一文件
from PIL import Image, ImageTk  # 用于调整图像尺寸 显示图片

# ------------------首页----------------- 

""" 显示图片 """    
img_mv = []
def Show_Image():

    img_mv.append(0) #使下面的图像与下标对应
    for i in range(1,9):
        image1 = Image.open("./img/mv"+str(i)+".png")
        image1 = image1.resize((180,240), Image.ANTIALIAS)
        img_mv.append(ImageTk.PhotoImage(image1)) 

    for i in range(1,5):
        l = tk.Label(frm_Up, image=img_mv[i])
        l.grid(row=0, column=i-1) #图片list下标从1开始，grid列从0开始，差一个

    for i in range(5,9):
        l = tk.Label(frm_Down, image=img_mv[i])
        l.grid(row=0, column=i-5)
