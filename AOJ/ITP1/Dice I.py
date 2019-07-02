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


dice=Dice(*[int(i) for i in input().split(" ")])
for s in input():
    if s=="S":
        dice.S()
    if s=="E":
        dice.E()
    if s=="N":
        dice.N()
    if s=="W":
        dice.W()
print(dice.top)
