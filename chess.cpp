#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int rows = 8;
const int cols = 8;

bool isValid(int r, int c) {
    return (r >= 0 && r < rows && c >= 0 && c < cols);
}

int convertToVertex(int row, int col) {
    return row * cols + col + 1;
}

void generateGraphMatrix(vector<vector<int>>& graphMatrix) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int currentVertex = convertToVertex(r, c);

            int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
            int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

            for (int i = 0; i < 8; ++i) {
                int newRow = r + dr[i];
                int newCol = c + dc[i];

                if (isValid(newRow, newCol)) {
                    int neighborVertex = convertToVertex(newRow, newCol);
                    graphMatrix[currentVertex].push_back(neighborVertex);
                }
            }
        }
    }
}

int main() {
    ofstream myfile("king.txt");

    vector<vector<int>> graphMatrix(rows * cols + 1);

    generateGraphMatrix(graphMatrix);

    for(int i = 1; i <= rows * cols; ++i) {
        myfile << i << " ";
        for(int neighbor : graphMatrix[i]) {
            myfile << neighbor << " ";
        }
        myfile << "\n";
    }

    myfile.close();

    return 0;
}
