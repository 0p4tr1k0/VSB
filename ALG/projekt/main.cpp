/**
 * @file main.cpp
 * @brief Program pro rekonstrukci a vizualizaci binárního stromu.
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Definice binárního stromu
struct TreeNode {
    int data; /**< Data uzlu */
    TreeNode* left; /**< Ukazatel na levý podstrom */
    TreeNode* right; /**< Ukazatel na pravý podstrom */

    /**
     * Konstruktor pro vytvoření nového uzlu.
     * @param val Hodnota, která bude uložena v uzlu.
     */
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

/**
 * Funkce pro rekonstrukci binárního stromu ze zadaného řetězce.
 * @param input Vstupní řetězec, který reprezentuje binární strom.
 * @param index Index vstupního řetězce, od kterého začne rekonstrukce.
 * @return Ukazatel na kořen rekonstruovaného binárního stromu.
 */
TreeNode* reconstructTree(const string& input, int& index) {
    if (input.empty() || index >= input.size()) return nullptr;

    // Načtení aktuálního čísla
    int val = 0;
    while (index < input.size() && isdigit(input[index])) {
        val = val * 10 + (input[index] - '0');
        index++;
    }

    TreeNode* root = new TreeNode(val);

    // Rekurzivně rekonstruuje levý podstrom
    if (index < input.size() && input[index] == '(') {
        index++;
        root->left = reconstructTree(input, index);
        index++; // Přeskočení závorky ')'
    }

    // Rekurzivně rekonstruuje pravý podstrom
    if (index < input.size() && input[index] == '(') {
        index++;
        root->right = reconstructTree(input, index);
        index++; // Přeskočení závorky ')'
    }

    return root;
}

/**
 * Funkce pro vytvoření řetězce z binárního stromu.
 * @param root Kořen binárního stromu.
 * @return Řetězec reprezentující binární strom.
 */
string treeToString(TreeNode* root) {
    if (!root) return "";

    string result = to_string(root->data);

    if (root->left || root->right) {
        result += "(";
        result += treeToString(root->left);
        result += ")";
        if (root->right) {
            result += "(";
            result += treeToString(root->right);
            result += ")";
        }
    }

    return result;
}

/**
 * Funkce pro vytvoření horizontálního řetězce z binárního stromu.
 * @param root Kořen binárního stromu.
 * @return Horizontální řetězec reprezentující binární strom.
 */
string treeToHorizontalString(TreeNode* root) {
    if (!root) return "";

    string result = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result += to_string(node->data) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "- ";
            }
        }
        result += "\n";
    }

    return result;
}

/**
 * Funkce pro vytvoření vertikálního řetězce z binárního stromu.
 * @param root Kořen binárního stromu.
 * @param output Výstupní řetězec pro vertikální reprezentaci stromu.
 * @param depth Hloubka uzlu ve stromu.
 */
void treeToVerticalString(TreeNode* root, string& output, int depth = 0) {
    if (!root) return;

    // Rekurzivní výpis pravého podstromu
    treeToVerticalString(root->right, output, depth + 1);

    // Vytvoření oddělovače pro lepší vizualizaci stromu
    string separator = "";
    for (int i = 0; i < depth; ++i)
        separator += "   ";

    // Výpis uzlu
    output += separator + to_string(root->data) + "\n";

    // Rekurzivní výpis levého podstromu
    treeToVerticalString(root->left, output, depth + 1);
}

int main() {
    // Testovací řetězec pro rekonstrukci stromu
    string input = "4(2(3)(1))(6(5))";
    //string input = "10(9(8)(7(6(5))))";
    //string input = "9(8(7(6)(5(4))3))";

    // Index pro rekonstrukci stromu
    int index = 0;

    // Rekonstrukce stromu
    TreeNode* root = reconstructTree(input, index);

    // Výpis stromu ve formě řetězce
    string output = treeToString(root);
    cout << "Reconstructed string from tree: " << output << endl;

    // Výpis stromu
    cout << "\nHorizontal tree:\n";
    cout << treeToHorizontalString(root);

    cout << "\nVertical tree:\n";
    string verticalOutput;
    treeToVerticalString(root, verticalOutput);
    cout << verticalOutput;

    return 0;
}