import copy

def OutPut():
    print("x: ",x)
    print("y_light: ",y_light)
    print("y_oneChange: ",y_oneChange)
    print("y_deep: ",y_deep)
    print()


print("原始值复制：")
x = [1,2,3]
y_light = x #x y同时改变
y_oneChange = x.copy() # y除第一层外全改变 
y_deep = copy.deepcopy(x) #互不影响
OutPut()

print("第一层加变量：")
x.append(4)
OutPut()

print("第一层加list: ")
x.append([1,2])
OutPut()

y_oneChange = x.copy() #将第一层有list的x复制下来
print("第二层改变前的y_oneChange:",y_oneChange)

print("第二层加list:")
x[4].append([3,4])
OutPut()
