#include "matrix.h"
#include <cstdlib>
#include <time.h>
#include <cmath>

void sudoku::matrix::init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (this->obj[i][j])
                this->ne[i][j] = 1;
            else this->ne[i][j] = 0;
        }
    }
}

sudoku::matrix::matrix() {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            this->obj[i][j] = 0;
        }
    }
}

sudoku::matrix::matrix(const matrix &M) {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            obj[i][j] = M.obj[i][j];
            ne[i][j] = M.ne[i][j];
        }
    }
}

bool FindUnassignedLocation(int grid[N][N],
                            int &row, int &col);

// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(int grid[N][N], int row,
            int col, int num);


bool SolveSudoku(int grid[N][N]) {
    int row, col;
    // If there is no unassigned location,
    // we are done
    if (!FindUnassignedLocation(grid, row, col))
        // success!
        return true;

    // Consider digits 1 to N
    for (int num = 1; num <= N; num++) {
        // Check if looks promising
        if (isSafe(grid, row, col, num)) {

            // Make tentative assignment
            grid[row][col] = num;

            // Return, if success
            if (SolveSudoku(grid))
                return true;
            // Failure, unmake & try again
            grid[row][col] = 0;
        }
    }

    // This triggers backtracking
    return false;
}


bool UsedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool UsedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num) {
    for (int row = 0; row < N1; row++)
        for (int col = 0; col < N1; col++)
            if (grid[row + boxStartRow]
                [col + boxStartCol] ==
                num)
                return true;
    return false;
}


bool isSafe(int grid[N][N], int row,
            int col, int num) {

    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % N1,
                         col - col % N1, num)
           && grid[row][col] == 0;
}


bool FindUnassignedLocation(int grid[N][N],
                            int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}


void sudoku::matrix::solvebacktracking() {
    init();
    SolveSudoku(this->obj);
}


void sudoku::matrix::write(int i, int j, int val) {
    if (ne[i][j])
        return;
    this->obj[i][j] = val;
}

int sudoku::matrix::read(int i, int j) {
    return this->obj[i][j];
}

void sudoku::matrix::empty() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            this->obj[i][j] = 0;
        }
    }
}

bool sudoku::matrix::you_win() {

    matrix m(*this);
    m.reset();
    m.solvebacktracking();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m.obj[i][j] != obj[i][j])
                return false;
        }
    }
    return true;
}

void sudoku::matrix::new_puzzle() {
    empty();
    solvebacktracking();
    srand(time(NULL));
    int rdbox = rand() % 10 + 40;
    for (int k = 0; k < rdbox; ++k) {
        int i = rand() % N;
        int j = rand() % N;
        while (!obj[i][j]) {
            i = rand() % N;
            j = rand() % N;
        }
        obj[i][j] = 0;
    }
    init();
}

void sudoku::matrix::reset() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!ne[i][j])
                obj[i][j] = 0;
        }
    }
}
