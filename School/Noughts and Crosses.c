// Libraries
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

// Prototypes
void instructions(char board[3][3]);
void displayBoard(char board[3][3]);
int move(char board[3][3], char player);
bool checkWin(char board[3][3], char player);

int main() 
{
    char board[3][3] = {
        {'1','2','3'} ,
        {'4','5','6'} ,
        {'7','8','9'}
    };

    instructions(board);

    int roundNum = 0;
    for (int i = 0 ; i < 9 ; i++) {
        if (roundNum % 2 == 0) { 
            move(board, 'X');
        } else {
            move(board, '0');
        }
        if (checkWin(board, 'X') == true || checkWin(board, '0') == true) {
            break;
        }
        roundNum++;
    }

    displayBoard(board);
    if (checkWin(board, 'X') == true) {
        printf("X is the Winner!\n");
    } else if (checkWin(board, '0') == true) {
        printf("0 is the Winner!\n");
    } else {
        printf("Draw!");
    }

    return 0;
}

void instructions(char board[3][3])
{
    printf("Welcome to Noughts and Crosses\n\n");
    printf("------------------------------\n\n");
    printf("Instructions:\n\n");
    printf("This is a 2 player game\n");
    printf("The first player will be crosses (X)\n");
    printf("The second player will be noughts (0)\n");
    printf("The game is presented in a grid:\n\n");
    displayBoard(board);
    printf("To choose a position for your piece, enter the location number.\n\n");
}

void displayBoard(char board[3][3])
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("───┼───┼───\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("───┼───┼───\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

int move(char board[3][3], char player)
{
    displayBoard(board);

    // Get players position and check if within range
    char c = '0';
    int position = -10;
    printf("%c's turn. Where would you like to place your piece? ", player);
    do {
        if (scanf("%d", &position) == 0) {
            printf("%c's turn. Where would you like to place your piece? ", player);
            do {
                c = getchar();
            }
            while (!isdigit(c));
            ungetc(c, stdin);
        } else if (position < 1 || position > 9) {
            printf("Position out of range\n");
            printf("%c's turn. Where would you like to place your piece? ", player);
        }
    } while (position < 1 || position > 9);

    // Calculate row and column from position
    int row = (position - 1) / 3;
    int column = (position + 2) % 3; 

    
    // Check if position is taken
    if ((position + 48) != board[row][column]) {
        printf("Position taken\n");
        move(board, player);
    } else {
        board[row][column] = player;
    }
}

bool checkWin(char board[3][3], char player)
{
    // Checks Vertical
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
        return true;
    } else if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
        return true;
    } else if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
        return true;  
    }

    // Checks Horizontal
    else if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
        return true;
    } else if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
        return true;
    } else if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
        return true;
    }

    // Checks Diagonal
    else if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    // Return false if no win conditions
    else {
        return false;
    }
}