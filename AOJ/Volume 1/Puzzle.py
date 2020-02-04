n=int(input())
st=True
for _ in range(n):
    if st==False:
        print()

    puzzle=[]
    for i in range(9):
        row=[int(j) for j in input().split(" ")]
        puzzle.append(row)

    dup=[[False for i in range(9)] for j in range(9)]
    for i in range(9):
        for j in range(9):
            for k in range(9):
                if i!=k and puzzle[i][j]==puzzle[k][j]:
                    dup[i][j]=True
                if j!=k and puzzle[i][j]==puzzle[i][k]:
                    dup[i][j]=True

            for p in range(3):
                for q in range(3):
                    x=(i//3)*3+p
                    y=(j//3)*3+q
                    if (x==i and y==j):
                        continue

                    if puzzle[x][y]==puzzle[i][j]:
                        dup[i][j]=True

    for i in range(9):
        for j in range(9):
            if dup[i][j]:
                print("*", end="")
            else:
                print(" ", end="")
            print(puzzle[i][j], end="")
        print()
    st=False
