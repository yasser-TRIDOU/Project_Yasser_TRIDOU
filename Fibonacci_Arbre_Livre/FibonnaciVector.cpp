#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Function to multiply two matrices
vector<vector<long int>> multiplyMatrix(const vector<vector<long int>> &matrix1, const vector<vector<long int>> &matrix2) {
    long int rows1 = matrix1.size();
    long int cols1 = matrix1[0].size();
    long int cols2 = matrix2[0].size();

    vector<vector<long int>> result(rows1, vector<long int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to raise a matrix to the power n
vector<vector<long int>> powerMatrix(const vector<vector<long int>> &matrix, long int n) {
    long int size = matrix.size();

    // Base case: return the matrix itself if n is 1
    if (n == 1) {
        return matrix;
    }

    // Recursive case: divide and conquer
    if (n % 2 == 0) {
        vector<vector<long int>> halfPower = powerMatrix(matrix, n / 2);
        return multiplyMatrix(halfPower, halfPower);
    } else {
        vector<vector<long int>> halfPower = powerMatrix(matrix, (n - 1) / 2);
        return multiplyMatrix(multiplyMatrix(halfPower, halfPower), matrix);
    }
}

// Function to calculate the nth Fibonacci number using matrix exponentiation
long int fibonacci(long int n) {
    if (n == 0) {
        return 0;
    }

    // Fibonacci matrix: {{1, 1}, {1, 0}}
    vector<vector<long int>> fibMatrix = {{1, 1},
                                     {1, 0}};

    // Raise the Fibonacci matrix to the power (n - 1)
    vector<vector<long int>> resultMatrix = powerMatrix(fibMatrix, n - 1);

    // The result is the top-left element of the resulting matrix
    return resultMatrix[0][0];
}

int main() {
    long int n;
    cout << "Enter the value of n for Fibonacci number: ";
    cin >> n;
    auto start_time = std::chrono::high_resolution_clock::now();
    long int data=fibonacci(n);

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Temps d'execution : " << duration.count() << " microseconds." << std::endl;

    cout << "Fibonacci number at position " << n << ": " << data << endl;

    return 0;
}