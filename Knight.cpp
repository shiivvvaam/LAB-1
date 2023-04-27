#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

bool isValid(int x, int y, vector<vector<int>>& board) {
    // Check if the cell is within the board
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }

    // Check if the cell has already been visited
    if (board[x][y] != -1) {
        return false;
    }

    // It's a valid cell to visit
    return true;
}

bool solveKnightTour(vector<vector<int>>& board, int x, int y, int moveNumber) {
    // Base case: All cells have been visited
    if (moveNumber == N * N) {
        return true;
    }

    // Possible moves for the knight
    int rowMoves[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int colMoves[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    // Try each possible move
    for (int i = 0; i < N; i++) {
        int nextX = x + rowMoves[i];
        int nextY = y + colMoves[i];

        if (isValid(nextX, nextY, board)) {
            // Mark the cell as visited
            board[nextX][nextY] = moveNumber;

            // Recursively visit the rest of the cells
            if (solveKnightTour(board, nextX, nextY, moveNumber + 1)) {
                return true;
            }

            // Backtrack: Unmark the cell and try the next move
            board[nextX][nextY] = -1;
        }
    }

    // All moves have been tried and nothing worked
    return false;
}

int main() {
    // Initialize the board with -1 (unvisited)
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Start the tour from (0, 0)
    board[0][0] = 0;

    if (solveKnightTour(board, 0, 0, 1)) {
        // Print the solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found" << endl;
    }

    return 0;
}
