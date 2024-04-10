#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

void knapsack() {
    ifstream file("batoh.txt");
    
    if (!file) {
        cout << "Soubor se nepodařilo otevřít." << endl;
        return;
    }
    
    int knapsackCapacity;
    file >> knapsackCapacity;
    
    vector<Item> items;
    Item item;
    
    while (file >> item.weight >> item.value) {
        items.push_back(item);
    }
    
    file.close();
    
    vector<int> dp(knapsackCapacity + 1, 0);
    
    for (const auto& item : items) {
        for (int w = knapsackCapacity; w >= item.weight; w--) {
            dp[w] = max(dp[w], dp[w - item.weight] + item.value);
        }
    }
    
    cout << "Maximální hodnota, kterou lze z batohu získat: " << dp[knapsackCapacity] << endl;
}

void distance_matrix(){}

int main() {
    knapsack();
    
    return 0;
}
