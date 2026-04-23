/*
 * Here's the task: you've been given a 2D matrix consisting of individual cells, each holding 
 * a unique integer value. Your goal is to create a function that will traverse this matrix, 
 * starting at the bottom-right cell. From there, you'll travel up to the top of the same column, 
 * then move left to the next column, and then continue downward from the top of this new column. 
 * After reaching the bottom of the column, you again move left and start moving upward. This 
 * unique traverse pattern will be performed until all the cells have been visited.
 *
 * Consider this small 3×43×4 matrix as an example:
 * 
 * {
     {1, 2, 3, 4},
     {5, 6, 7, 8},
     {9, 10, 11, 12}
  * }

  * With the described traversal pattern, your function should 
  * return this list: [12, 8, 4, 3, 7, 11, 10, 6, 2, 1, 5, 9]
*/

#include <iostream>
#include <vector>


void traversal_pattern(const std::vector<std::vector<int>> &array) {
    if (array.empty() || array[0].empty()) return;

    int rows = array.size();
    int cols = array[0].size();

    for (int j = cols - 1; j >= 0; j--) {
        if ((cols -1 -j) % 2 == 0) {
            for (int i = rows -1; i >= 0; i--) {
                std::cout << array[i][j] << " ";
            }
        }  else {
            for (int i = 0; i < rows; i++) {
                std::cout << array[i][j] << " ";
            }
        }
    }

    std::cout << std::endl;
}

std::vector<int> column_traverse(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::string direction = "up";
    int row = rows - 1;
    int col = cols - 1;
    std::vector<int> output;

    while (output.size() < rows * cols) {
        output.push_back(matrix[row][col]);

        if (direction == "up") {
            if (row - 1 < 0) {
                direction = "down";
                col -= 1;
            } else {
                row -= 1;
            }
        } else {
            if (row + 1 == rows) {
                direction = "up";
                col -= 1;
            } else {
                row += 1;
            }
        }
    }
    return output;
}

std::vector<int> reverse_traverse(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<int> output;

    for (int row = rows - 1; row >= 0; --row) {
        for (int col = cols - 1; col >= 0; --col) {
            output.push_back(matrix[row][col]);
        }
    }

    return output;
}


int main() {
    std::vector<std::vector<int>> array = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::cout << "rows: " << array.size() << std::endl;
    std::cout << "columns: " << array[0].size() << std::endl;

    std::vector<int> result = column_traverse(array);
    for (const auto& row : array) {
        for (const auto& col : row) {
            std::cout << col << " ";
        }
    }

    std::cout << std::endl;

    traversal_pattern(array);
}