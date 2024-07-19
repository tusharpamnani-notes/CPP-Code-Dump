/*
 The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.
 Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.
 Two queens on the same chessboard can attack each other if any of the below condition satisfies: 
   1. They share a row. 
   2. They share a column. 
   3. They share a diagonal. 
*/

#include <vector>

void addSol(vector<vector<int>> &result, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    result.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    // same row
    while (y >= 0) {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    // upper diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // lower diagonal
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    return true;
}

void sol(int col, vector<vector<int>> &result, vector<vector<int>> &board, int n) {
    // base condition
    if (col == n) {
        addSol(result, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            sol(col + 1, result, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> result;

    sol(0, result, board, n);

    return result;
}
