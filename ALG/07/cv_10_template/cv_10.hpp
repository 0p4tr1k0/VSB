#pragma once
#include <iostream>
#include <vector>

using namespace std;


void swap(vector<int>& array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void print_permutation(const vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void generate_permutations_helper(vector<int>& array, int start, int n) {
    if (start == n - 1) {
        print_permutation(array);
        return;
    }

    for (int i = start; i < n; i++) {
        swap(array, start, i);

        generate_permutations_helper(array, start + 1, n);

        swap(array, start, i);
    }
}


void generate_permutations(int n) {

    vector<int> array;
    for (int i = 1; i <= n; i++) {
        array.push_back(i);
    }


    generate_permutations_helper(array, 0, n);
}


int binary_search(int target, const vector<int> &sorted_array) {
    int left = 0;
    int right = sorted_array.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted_array[mid] == target) {
            return mid; 
        }
        if (sorted_array[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }
    return -1;
}