line = int(input("请输入图案行数"))

i = 1
while(i < line+1) : 
    j = 0
    while(j < line-i) :
        print("  ", end="")
        j += 1
    j = 0
    while(j < 2*i-1) :
        print("* ", end="")
        j += 1
    i += 1
    print("")
    