#include "raylib.h"
#include <iostream>

using namespace std;

const int SIZE = 9;
const int CELL_SIZE = 60;
const int OFFSET_X = 50;
const int OFFSET_Y = 50;

// Sudoku Board
int board[SIZE][SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

// Selected Cell
int selectedRow = -1;
int selectedCol = -1;

// SUDOKU FUNCTIONS

// Check row
bool isRowSafe(int board[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (board[row][col] == num)
            return false;
    }
    return true;
}

// Check column
bool isColSafe(int board[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (board[row][col] == num)
            return false;
    }
    return true;
}

// Check 3x3 box
bool isBoxSafe(int board[SIZE][SIZE], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row + startRow][col + startCol] == num)
                return false;
        }
    }
    return true;
}

// Check safe position
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {

    return isRowSafe(board, row, num) &&
           isColSafe(board, col, num) &&
           isBoxSafe(board, row - row % 3, col - col % 3, num);
}

// Backtracking Algorithm
bool solveSudoku(int board[SIZE][SIZE]) {

    int row, col;
    bool emptyFound = false;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {

            if (board[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }

        if (emptyFound)
            break;
    }

    if (!emptyFound)
        return true;

    for (int num = 1; num <= 9; num++) {

        if (isSafe(board, row, col, num)) {

            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

// MAIN FUNCTION

int main() {

    InitWindow(800, 650, "Sudoku Solver - raylib");

    SetTargetFPS(60);

    // Buttons
    Rectangle solveButton = {620, 150, 130, 50};
    Rectangle clearButton = {620, 230, 130, 50};

    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();

        // Mouse Click
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            // Select Cell
            if (mouse.x >= OFFSET_X &&
                mouse.x <= OFFSET_X + CELL_SIZE * 9 &&
                mouse.y >= OFFSET_Y &&
                mouse.y <= OFFSET_Y + CELL_SIZE * 9) {

                selectedCol = (mouse.x - OFFSET_X) / CELL_SIZE;
                selectedRow = (mouse.y - OFFSET_Y) / CELL_SIZE;
            }

            // Solve Button
            if (CheckCollisionPointRec(mouse, solveButton)) {
                solveSudoku(board);
            }

            // Clear Button
            if (CheckCollisionPointRec(mouse, clearButton)) {

                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        board[i][j] = 0;
                    }
                }
            }
        }

        // Keyboard Input
        int key = GetKeyPressed();

        if (selectedRow != -1 && selectedCol != -1) {

            if (key >= KEY_ONE && key <= KEY_NINE) {

                board[selectedRow][selectedCol] =
                    key - KEY_ZERO;
            }

            // Delete Number
            if (key == KEY_BACKSPACE || key == KEY_DELETE) {
                board[selectedRow][selectedCol] = 0;
            }
        }

        // DRAWING

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Sudoku Solver", 280, 10, 35, DARKBLUE);

        // Highlight Selected Cell
        if (selectedRow != -1 && selectedCol != -1) {

            DrawRectangle(
                OFFSET_X + selectedCol * CELL_SIZE,
                OFFSET_Y + selectedRow * CELL_SIZE,
                CELL_SIZE,
                CELL_SIZE,
                LIGHTGRAY
            );
        }

        // Draw Grid
        for (int row = 0; row < SIZE; row++) {

            for (int col = 0; col < SIZE; col++) {

                int x = OFFSET_X + col * CELL_SIZE;
                int y = OFFSET_Y + row * CELL_SIZE;

                DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, BLACK);

                // Draw Numbers
                if (board[row][col] != 0) {

                    DrawText(
                        TextFormat("%d", board[row][col]),
                        x + 20,
                        y + 15,
                        30,
                        DARKBLUE
                    );
                }
            }
        }

        // Thick Lines
        for (int i = 0; i <= 9; i++) {

            int thickness = (i % 3 == 0) ? 4 : 1;

            // Horizontal
            DrawLineEx(
                {(float)OFFSET_X, (float)(OFFSET_Y + i * CELL_SIZE)},
                {(float)(OFFSET_X + 9 * CELL_SIZE), (float)(OFFSET_Y + i * CELL_SIZE)},
                thickness,
                BLACK
            );

            // Vertical
            DrawLineEx(
                {(float)(OFFSET_X + i * CELL_SIZE), (float)OFFSET_Y},
                {(float)(OFFSET_X + i * CELL_SIZE), (float)(OFFSET_Y + 9 * CELL_SIZE)},
                thickness,
                BLACK
            );
        }

        // Solve Button
        DrawRectangleRec(solveButton, DARKGREEN);
        DrawText("SOLVE", 650, 165, 25, WHITE);

        // Clear Button
        DrawRectangleRec(clearButton, MAROON);
        DrawText("CLEAR", 650, 245, 25, WHITE);

        // Instructions
        DrawText("Instructions:", 600, 330, 22, BLACK);
        DrawText("1. Click a cell", 600, 370, 18, DARKGRAY);
        DrawText("2. Press 1-9", 600, 400, 18, DARKGRAY);
        DrawText("3. Click Solve", 600, 430, 18, DARKGRAY);
        DrawText("4. Backspace to erase", 600, 460, 18, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}