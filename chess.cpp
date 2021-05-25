#include <iostream>
 
using namespace std;

int chessField[8][8];
int results = 0;
 
void showChessField() {
    for(int rows = 0; rows < 8; ++rows) {
        for(int cols = 0; cols < 8; ++cols) {
            cout << ((chessField[rows][cols]) ? "1 " : "0 ");
        }
        cout << endl;
    }
}

bool tryPosition(int rows, int cols) {
    for(int i = 0; i < rows; ++i) {
        if(chessField[i][cols]) {
            return false;
        }
    }
    for(int i = 1; i <= rows && cols - i >= 0; ++i) {
        if(chessField[rows - i][cols - i]) {
            return false;
        }
    }
    for(int i = 1; i <= rows && cols + i < 8; i++) {
        if(chessField[rows - i][cols + i]) {
            return false;
        }
    }
    return true;
}

void setPosition(int row) {
    if(row == 8) {
        showChessField();
        cout << "Result: " << ++results << "\n\n";
        return;
    }
    for(int i = 0; i < 8; ++i) {
        if(tryPosition(row, i)) {
            chessField[row][i] = 1;
            setPosition(row + 1);
            chessField[row][i] = 0;
        }
    }
    return;
}

int main() {
    setPosition(0);
    getchar();
    return 0;
}