#include <iostream> 
using namespace std;
 
bool sign = false;
int num[9][9];

void Input() {
    char temp[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> temp[i][j];
            num[i][j] = temp[i][j] - '0';
        }
    }
}

void Output() {
    cout << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << num[i][j] << " ";
            if (j % 3 == 2)
                cout << "   ";
        }
        cout << endl;
        if (i % 3 == 2)
            cout << endl;
    }
}

bool Check(int n, int key) {
    for (int i = 0; i < 9; i++) {
        int j = n / 9;
        if (num[j][i] == key) return false;
    }
    for (int i = 0; i < 9; i++) {
        int j = n % 9;
        if (num[i][j] == key) return false;
    }
    int x = n / 9 / 3 * 3, y = n % 9 / 3 * 3;
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            if (num[i][j] == key) return false;
    return true;
}
 
int DFS(int n) {
    if (n > 80) {
        sign = true;
        return 0;
    } if (num[n / 9][n % 9] != 0) DFS(n + 1);
    else {
        for (int i = 1; i <= 9; i++) {
            if (Check(n, i)) {
                num[n / 9][n % 9] = i;
                DFS(n + 1);
                if (sign) return 0;
                num[n / 9][n % 9] = 0;
            }
        }
    }
}

int main() {
	cout << "Welcome to use C++to solve Sudoku puzzles. When you can't do Sudoku puzzles, you can use this." << endl;
    cout << "Please enter a 9 × Sudoku matrix of 9, the vacancy is represented by 0:" << endl;
    Input();
    DFS(0);
    Output();
    return 0;
}