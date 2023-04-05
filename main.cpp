#include <iostream>
using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(char board[][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game has been won
bool checkWin(char board[][3], char player)
{
    // Check rows for win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player) && (board[i][1] == player) && (board[i][2] == player)) {
            return true;
        }
    }

    // Check columns for win
    for (int i = 0; i < 3; i++) {
        if ((board[0][i] == player) && (board[1][i] == player) && (board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals for win
    if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) {
        return true;
    }
    if ((board[0][2] == player) && (board[1][1] == player) && (board[2][0] == player)) {
        return true;
    }

    // If no win, return false
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[][3])
{
    // Check if all the spaces are filled
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }

    // If all spaces are filled and no win, return true for draw
    return true;
}

// Function to get the player's move
void getPlayerMove(char board[][3], char player)
{
    int row, col;

    cout << "Enter row and column for player " << player << " (example: 1 2): ";
    cin >> row >> col;

    // Check if space is already taken
    while (board[row-1][col-1] != '-') {
        cout << "The space is already taken. Please try again." << endl;
        cout << "Enter row and column for player " << player << " (example: 1 2): ";
        cin >> row >> col;
    }

    // Place player's move on the board
    board[row-1][col-1] = player;
}

int main()
{
    char board[3][3] = {{'-', '-', '-'},
                        {'-', '-', '-'},
                        {'-', '-', '-'}};

    char player = 'X';
    bool win = false;
    bool draw = false;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;

    while (!win && !draw) {
        displayBoard(board);
        getPlayerMove(board, player);
        win = checkWin(board, player);
        draw = checkDraw(board);
        if (!win && !draw) {
            if (player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }
        }
    }

    displayBoard(board);

    if (win) {
        cout << "Congratulations! Player " << player << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}