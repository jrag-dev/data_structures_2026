#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> library = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {9, 11, 13, 15}
    };

    // Starting from the bottom right corner of the bookshelf
    int row = library.size() - 1;
    int col = library[0].size() - 1;
    bool goingUp = true;

    while (col >= 0) {
        std::cout << library[row][col] << " ";
        if (goingUp) {
            if (row == 0) {
                goingUp = false;
                col -= 1;
            } else {
                row -= 1;
            }
        } else {
            if (row == static_cast<int>(library.size() - 1)) {
                goingUp = true;
                col -= 1;
            } else {
                row += 1;
            }
        }
    }

    return 0;
}