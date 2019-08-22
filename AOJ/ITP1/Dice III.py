import copy


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

    def spin(self):
        self.left, self.behind, self.right, self.front = self.front, self.left, self.behind, self.right

    def __eq__(self, _dice2):
        dice2 = copy.deepcopy(_dice2)
        for i in range(4):
            if self._eqaul(dice2):
                return True
            dice2.spin()
        dice2 = copy.deepcopy(_dice2)
        dice2.N()
        dice2.N()
        for i in range(4):
            if self._eqaul(dice2):
                return True
            dice2.spin()
        dice2 = copy.deepcopy(_dice2)
        dice2.N()
        for i in range(4):
            if self._eqaul(dice2):
                return True
            dice2.spin()
        dice2 = copy.deepcopy(_dice2)
        dice2.E()
        for i in range(4):
            if self._eqaul(dice2):
                return True
            dice2.spin()
        dice2 = copy.deepcopy(_dice2)
        dice2.W()
        for i in range(4):
            if self._eqaul(dice2):
                return True
            dice2.spin()
        dice2 = copy.deepcopy(_dice2)
        dice2.S()
        for i in range(4):
            if self._eqaul(dice2):
                return True
            dice2.spin()
        return False

    def _eqaul(self, dice2):
        return self.front == dice2.front and self.behind == dice2.behind and self.left == dice2.left and self.right == dice2.right and self.top == dice2.top and self.bottom == dice2.bottom

    def __repr__(self):
        return ",".join([str(object=i) for i in (self.top, self.front, self.right, self.left, self.behind, self.bottom)])


dice1 = Dice(*[int(i) for i in input().split(" ")])
dice2 = Dice(*[int(i) for i in input().split(" ")])

if(dice1 == dice2):
    print("Yes")
else:
    print("No")
