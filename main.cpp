#include <iostream>
#include <stdio.h>

using namespace std;



class Board {

public:
    Board(int x = 12, int y = 12) {
        board[x*y];
        width = x;
        height = y;

        for (int i = 0; i < x; i++) {
            for (int k = 0; k < y; k++) {
                board[i + k * x] = i*k;
            }
        }
    }

    int AT(int x, int y) {
        return board[x + width * y];
    }

private:
    int width;
    int height;
    int board[];
};



int main() {
    Board board;

    printf("%i", board.AT(5,2));

    return 0;
}
