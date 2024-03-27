#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void bubble_sort(int *array, int size){
    for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
    }
}

void selection_sort(int *array, int size){
    for(int i = 0; i < size - 1; i++){
        int min_index = i;

        for(int j = i + 1; j < size; j++){
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }
        
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}



int main(){
    int array[1000];
    int size = 0;

    
    ifstream inputFile("unsorted_array.txt");

    
    if (inputFile.is_open()) {
        
        while (inputFile >> array[size]) {
            size++;
        }
        
        
        inputFile.close();
    } else {
        cout << "Failed to open the file." << endl;
        return 1; 
    }
    
    
    bubble_sort(array, size);

    
    //selection_sort(array, size);

    
    for (int i = 0; i < size; i++) {
        cout << array[i] << " " << "\n";
    }
    cout << endl;

    return 0;
}