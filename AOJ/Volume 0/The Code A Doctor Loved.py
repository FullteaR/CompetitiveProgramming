_encode={
    " ":"101",
    "'":"000000",
    ",":"000011",
    "-":"10010001",
    ".":"010001",
    "?":"000001",
    "A":"100101",
    "B":"10011010",
    "C":"0101",
    "D":"0001",
    "E":"110",
    "F":"01001",
    "G":"10011011",
    "H":"010000",
    "I":"0111",
    "J":"10011000",
    "K":"0110",
    "L":"00100",
    "M":"10011001",
    "N":"10011110",
    "O":"00101",
    "P":"111",
    "Q":"10011111",
    "R":"1000",
    "S":"00110",
    "T":"00111",
    "U":"10011100",
    "V":"10011101",
    "W":"000010",
    "X":"10010010",
    "Y":"10010011",
    "Z":"10010000"
}

def encode(c):
    return _encode[c]

def decode(s):
    num=0
    for i,c in enumerate(s):
        if c=="1":
            num+=2**(4-i)
    if num<26:
        return chr(ord('A')+num)
    elif num==26:
        return " "
    elif num==27:
        return "."
    elif num==28:
        return ","
    elif num==29:
        return "-"
    elif num==30:
        return "'"
    else:
        return "?"


while True:
    try:
        s=input()
        encoded=""
        for c in s:
            encoded+=encode(c)
        while(len(encoded)%5!=0):
            encoded+="0"
        decoded=""
        for i in range(len(encoded)//5):
            decoded+=decode(encoded[5*i:5*i+5])
        print(decoded)
    except EOFError:
        break
