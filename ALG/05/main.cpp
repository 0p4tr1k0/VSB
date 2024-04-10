#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

void sequential_search(int *array, int size, int to_search){
    int found_index = -1;

    for (int i = 0; i < size; i++) {
        if (array[i] == to_search) {
            found_index = i;
            cout << "Hledana hodnota " << to_search << " byla nalezena na indexu: " << found_index << endl;
            return;
        }
    }
        cout << "Hledana hodnota " << to_search << " nebyla nalezena v poli." << endl;
    
    
}

void substring_pattern_search(const string& text, const string& pattern){
    int text_length = text.length();
    int pattern_length = pattern.length();

    for (int i = 0; i <= text_length - pattern_length; ++i) {
        int j;
        for (j = 0; j < pattern_length; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == pattern_length) {
            std::cout << "Pattern '"<<pattern<<"' found at index " << i << std::endl;
        }
    }
}



void closest_pair(const std::string& text, const std::string& pattern) {
    int text_length = text.length();
    int pattern_length = pattern.length();

    for (int i = 0; i <= text_length - pattern_length; ++i) {
        int j;
        for (j = 0; j < pattern_length; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == pattern_length) {
            std::cout << "Pattern found at index " << i << std::endl;
        }
    }
}


int main(){
    int array[1000];
    int size;
    string text;
    string pattern = "sit";
    
    ifstream inputFile("unsorted_array.txt");

    if (inputFile.is_open()) {
        
        int i =0;
        while (inputFile >> size)
        {
            array[i++]=size;
        }
        
    }
    inputFile.close();

    ifstream inputFile2("text.txt");

    if (inputFile2.is_open()) {
        
        inputFile2 >> text;
        
    }
    inputFile2.close();


    ifstream my_file;
	
    


    sequential_search(array, 1000, 287);
    substring_pattern_search(text, pattern);
    

    return 0;

}