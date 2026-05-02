#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class piece;
class PieceManager;
class Board;


class Piece {

public:
    char *name;
    char team;
    operator char*() const {return name;}
    Piece(char *_name, char _team) : name(_name), team(_team) {};

};

class PieceManager {
public:
    PieceManager(Board *_board) : board(_board) {}

    void AddPiece(Piece p) {
        pieces.push_back(p);
    }

private:
    Board *board;
    std::vector<Piece> pieces;

};

class Board {

public:
    Board(int x = 12, int y = 12) {
        board[x*y];
        width = x;
        height = y;
    }

    void PlacePiece(int x, int y, Piece *piece) {
        board[x + y*width] = piece;
    }

    Piece* AT(int x, int y) {
        return board[x + width * y];
    }

    void Print() {
        for (int i = 0; i < width; i++) {
            for (int k = 0; k < height; k++) {
                printf("+---");
            }
            printf("+\n");
            for (int k = 0; k < height; k++) {
                printf("|   ");
            }
            printf("|\n");
        }
        
        
        
        for (int k = 0; k < height; k++) {
            printf("+---");
        }
        printf("+\n");
    }

private:
    int width;
    int height;
    Piece *board[];
};

int main() {
    Board board;

    board.Print();

    return 0;
}
