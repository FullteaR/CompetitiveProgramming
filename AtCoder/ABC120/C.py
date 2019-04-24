S=input()
red=S.count("0")
blue=S.count("1")

if red==0 or blue==0:
    print(0)
else:
    print(min(red,blue)*2)
