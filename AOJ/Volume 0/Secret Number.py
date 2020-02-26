import re


password=0
while True:
    try:
        str=input()

        str=re.sub("[^\d]"," ",str)
        str=re.sub("\s+"," ",str)
        for i in str.split(" "):
            try:
                password+=int(i)
            except ValueError:
                pass


    except EOFError:
        break

print(password)
