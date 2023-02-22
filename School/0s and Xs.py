def instructions(board):
    print("Welcome to noughts and crosses\n")
    print("------------------------------\n")
    print("Instructions:\n")
    print("This is a 2 player game")
    print("The first player will be crosses (X)")
    print("The second player will be noughts (0)")
    print("The game is presented in a grid:")
    displayBoard(board)
    print("\nTo choose a position for your piece, enter the location number.\n")
    
def displayBoard(board):
    print(f"\n  {board[0][0]} │ {board[0][1]} │ {board[0][2]}")
    print(" ───┼───┼───")
    print(f"  {board[1][0]} │ {board[1][1]} │ {board[1][2]}")
    print(" ───┼───┼───")
    print(f"  {board[2][0]} │ {board[2][1]} │ {board[2][2]}")
    
def move(board, player):
    position = -1

    while position == -1:
        position = getMove(board, player)

    # Calculate array index values    
    row = (position - 1) // 3
    column = (position + 2) % 3    
    
    board[row][column] = player
    return board

def getMove(board, player):
    try:
        position = int(input(f"\n{player}: Please select your move "))
    except ValueError:
        print("Not a valid position")
        return -1
    
    if position < 1 or position > 9:
        print("Position out of range.")
        return -1

    # Calculate array index values    
    row = (position - 1) // 3
    column = (position + 2) % 3    

    if board[row][column] != position:
        print("Position taken")
        return -1

    return position

def check_win(board, player):
    # Check for vertical wins
    if board[0][0] == player and board[1][0] == player and board[2][0] == player:
        return True
    if board[0][1] == player and board[1][1] == player and board[2][1] == player:
        return True
    if board[0][2] == player and board[1][2] == player and board[2][2] == player:
        return True

    # Check for horizontal wins
    if board[0][0] == player and board[0][1] == player and board[0][2] == player:
        return True
    if board[1][0] == player and board[1][1] == player and board[1][2] == player:
        return True
    if board[2][0] == player and board[2][1] == player and board[2][2] == player:
        return True
    
    # Check for diagonal wins 
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True

    else:
        return False

def main():
    board = [[1,2,3],[4,5,6],[7,8,9]]
    instructions(board)
    roundNum = 0
    for i in range(9):
        displayBoard(board)
        if roundNum % 2 == 0:
            player = "X"
        else:
            player = "0"
        move(board, player)
        if check_win(board, "X") == True or check_win(board, "0") == True:
            break
        roundNum += 1

    displayBoard(board)
    if check_win(board, "X") == True:
        print("X is the Winner!")
    elif check_win(board, "0") == True:
        print("0 is the Winner!")
    else:
        print("Draw!")
    
if __name__ == "__main__":
    main()
    
