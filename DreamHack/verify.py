
def asdf(): 
    str = "DH{cbababab-ababababab-ababababab-abababab}"

    print(len(str))

    if(len(str) != 43) :
        print("length error")
        return

    if (str[0] != "D"):
        print("str[0]")
        return
    if (str[1] != "H"):
        print("str[1]")
        return
    if (str[2] != "{"):
        print("str[2]")
        return
        

    if ( str[11] != chr(45) ):
        print("str[11]")
        return
    if ( str[22] != chr(45) ):
        print("str[22]")
        return
    if ( str[33] != chr(45) ):
        print("str[33]")
        return
    if ( str[42] != chr(125) ):
        print("str[42]")
        return
    
    
    for i in range (3, 10):
        if ( str[i] <= chr(47) ):
            print(i , "1")
            return
        if ( str[i] <= chr(70) or str[i] > chr(90) ):
            if(str[i] > chr(102)):
                print(i, "2")
                return
        print(i, "3")
        return 
    
    for i in range (12, 21):
        if ( str[i] <= chr(47) ):
            print(i)
            return
        if ( str[i] <= chr(70) or str[i] > chr(90) ):
            if(str[i] > chr(102)):
                print(i)
                return
        print(i)
        return 
    
    for i in range (23, 32):
        if ( str[i] <= chr(47) ):
            print(i)
            return
        if ( str[i] <= chr(70) or str[i] > chr(90) ):
            if(str[i] > chr(102)):
                print(i)
                return
        print(i)
        return 
    
    for i in range (34, len(str)-1):
        if ( str[i] <= chr(47) ):
            print(str[i])
            return
        if ( str[i] <= chr(70) or str[i] > chr(90) ):
            if(str[i] > chr(102)):
                print(i)
                return
        print(str[i])
        return 
    


    
    print("good!")

def testa():
    for i in range (33, 127):
        if ( chr(i) > chr(47) ):
            if ( chr(i) <= chr(70) or chr(i) > chr(90) ):
                if(chr(i) <= chr(102)):
                    print(i)
            continue    


testa()
asdf()