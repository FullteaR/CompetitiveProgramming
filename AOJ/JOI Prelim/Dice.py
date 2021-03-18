class Dice:
    def __init__(self, a, b, c, d, e, f):
        self.top = a
        self.front = b
        self.right = c
        self.left = d
        self.behind = e
        self.bottom = f

    def S(self):
        self.top, self.front, self.behind, self.bottom = self.behind, self.top, self.bottom, self.front

    def N(self):
        self.behind, self.top, self.bottom, self.front = self.top, self.front, self.behind, self.bottom

    def E(self):
        self.top, self.bottom, self.left, self.right = self.left, self.right, self.bottom, self.top

    def W(self):
        self.left, self.right, self.bottom, self.top = self.top, self.bottom, self.left, self.right

    def R(self):
        self.front, self.behind, self.right, self.left = self.right, self.left, self.behind, self.front

    def L(self):
        self.front, self.behind, self.right, self.left = self.left, self.right, self.front, self.behind


while True:
    n = int(input())
    if n==0:
        break
    dice = Dice(1,2,3,4,5,6)
    retval = 1
    for i in range(n):
        ope = input().strip()
        if ope=="North":
            dice.N()
        elif ope=="East":
            dice.E()
        elif ope=="West":
            dice.W()
        elif ope=="South":
            dice.S()
        elif ope=="Left":
            dice.L()
        else:
            assert ope=="Right"
            dice.R()
        retval += dice.top
    print(retval)
