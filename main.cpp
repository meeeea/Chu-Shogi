#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

class piece;
class PieceManager;
class Board;


class Piece {

public:
    const char *name;
    char team;
    operator const char*() const {
        std::string _name;
        _name = " ";
        _name += name;
        _name.push_back(team);
        _name.push_back(' ');
        return _name.c_str();
    }
    Piece(const char *_name, char _team) : name(_name), team(_team) {};

};

class PieceManager {
public:
    PieceManager() {}

    void AddPiece(const char *_name,char _team) {
        Piece p(_name, _team);
        pieces.push_back(p);
    }
    Piece* Back() {
        return &pieces.back();
    }
private:
    std::vector<Piece> pieces;
};

class Board {

public:
    Board(int x = 12, int y = 12, int _pieceNameLen = 3) {
        board.resize(x * y);
        width = x;
        height = y;
        pieceNameLen = _pieceNameLen;
    }

    Board(char * filePath) {
        std::ifstream reader(filePath);
        string initializer[3];
        getline(reader, initializer[0]);
        getline(reader, initializer[0]);
        getline(reader, initializer[1]);
        getline(reader, initializer[2]);

        width = std::stoi(initializer[0]);
        height = std::stoi(initializer[1]);
        pieceNameLen = std::stoi(initializer[2]);
        board.resize(width * height);

        string piecesetter;
        while (getline(reader, piecesetter)) {
            vector<string> instance = split(piecesetter, '|', 4);
            int x = std::stoi(instance.at(0));
            int y = std::stoi(instance.at(1));
            const char * name = instance.at(2).c_str();
            char team = instance.at(3).at(0);
            PlacePiece(x, y, name, team);
        }
    }

    void PlacePiece(int x, int y, const char *_name, char _team) {
        pieces.AddPiece(_name, _team);
        board.at(x + y*width) = pieces.Back();
    }

    Piece* AT(int x, int y) {
        return board.at(x + y*width);
    }

    void Print() {
        std::string empty = " ";
        for (int i = 0; i < pieceNameLen + 1; i++) {
            empty.push_back(' ');
        }

        for (int i = 0; i < width; i++) {
            for (int k = 0; k < height; k++) {
                printf("+");
                for (int i = 0; i < pieceNameLen + 2; i++) {
                    printf("-");
                }
            }
            printf("+\n");
            for (int k = 0; k < height; k++) {
                printf("|%s", board.at(i + k * width) ? (const char*) *board.at(i + k * width) : empty.c_str());
            }
            printf("|\n");
        }
        
        for (int k = 0; k < height; k++) {
            printf("+");
            for (int i = 0; i < pieceNameLen + 2; i++) {
                printf("-");
            }
        }
        printf("+\n");
    }

private:
    int width;
    int height;
    int pieceNameLen;
    PieceManager pieces;
    vector<Piece*> board;

    vector<string> split(string str, char splitter, int size) {
        vector<string> output(size);
        int selector = -1;
        int count = 0;
        while ((selector = str.find(splitter)) != string::npos) {
            output.at(count) = str.substr(0, selector);
            
            str = str.substr(selector + 1);
            count++;
            if (count == size) {
                break;
            }
        }
        output.back() = str;
        return output;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        return 1;
    }

    Board board( argv[1] );


    board.Print();
    
    return 0;
}