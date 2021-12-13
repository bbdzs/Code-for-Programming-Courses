#标记判断相应类别是否存在
check_num = 0 
check_lowercase = 0
check_uppercase = 0
check_len = 0
check_valid = 0

Password = input("请输入密码")

if(6 <= len(Password) <= 20) :
    check_len = 1
for i in range(len(Password)) :
    if(Password[i].islower()):
        check_lowercase = 1
    if(Password[i].isupper()) :
        check_uppercase = 1
    if('0' <= Password[i] <= '9') :
        check_num = 1

if(check_num and check_lowercase and check_uppercase and check_len) :
    check_valid = 1

if(check_valid) :
    print("Passward is valid.")
else:
    print("Passward is not valid.")




