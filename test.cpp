#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> my2DVector = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Remove the inner vector at index 1 (the second inner vector)
    my2DVector.erase(my2DVector.begin() + 1);

    // Print the updated 2D vector
    for (const std::vector<int>& innerVector : my2DVector) {
        for (int num : innerVector) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
