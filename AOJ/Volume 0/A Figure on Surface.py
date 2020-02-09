while True:
    try:
        board=[[0 for i in range(14)],[0 for i in range(14)],[0 for i in range(14)]]
        for i in range(8):
            row=[0,0,0]+[int(j) for j in input()]+[0,0,0]
            board.append(row)
        board.append([0 for i in range(14)])
        board.append([0 for i in range(14)])
        board.append([0 for i in range(14)])

        for i in range(3,11):
            for j in range(3,11):
                if board[i][j]==0:
                    continue

                if board[i][j]==1 and board[i+1][j]==1 and board[i][j+1]==1 and board[i+1][j+1]==1:
                    block="A"
                elif board[i][j]==1 and board[i+1][j]==1 and board[i+2][j]==1 and board[i+3][j]==1:
                    block="B"
                elif board[i][j]==1 and board[i][j+1]==1 and board[i][j+2]==1 and board[i][j+3]==1:
                    block="C"
                elif board[i][j]==1 and board[i+1][j]==1 and board[i+1][j-1]==1 and board[i+2][j-1]==1:
                    block="D"
                elif board[i][j]==1 and board[i][j+1]==1 and board[i+1][j+1]==1 and board[i+1][j+2]==1:
                    block="E"
                elif board[i][j]==1 and board[i+1][j]==1 and board[i+1][j+1]==1 and board[i+2][j+1]==1:
                    block="F"
                elif board[i][j]==1 and board[i][j+1]==1 and board[i+1][j-1]==1 and board[i+1][j]==1:
                    block="G"
        print(block)
        input()


    except EOFError:
        break
