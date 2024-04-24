#include <iostream>
#include "cv_10.hpp"

int main()
{
    cout<< "Permutation: " << endl;
    generate_permutations(3);

    int x = 500;
    vector<int> sorted_array = {10, 50, 100, 200, 256, 500, 750, 1000};
    cout << "---------------------------" << endl;
    cout << "Binary search:" << endl;
    int ind = binary_search(x, sorted_array);
    cout << "Array: ";
    for (int num : sorted_array) {
        cout << num << " ";
    }
    cout << endl;

    if (ind == -1) {
        cout << "Number " << x << " is not in the array." << endl;
    } else {
        cout << "Number " << x << " is at index " << ind << endl;
    }

    return 0;
}