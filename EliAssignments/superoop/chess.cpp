#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> location;
typedef vector<int> Array;
typedef vector<location> Locations; 

class ChessMarble {
private:
    location pos;
public:
    ChessMarble(int row, int col) : pos({row, col}) {};
    int getRow() { return pos.first; }
    int getCol() { return pos.second; }
    void setRow(int row) { pos.first = row; }
    void setCol(int col) { pos.second = col; }
    bool valid(int index) {
        return index >= 0 && index < 8;
    }
    bool valid(int row, int col) {
        return valid(row) && valid(col);
    }
    virtual Locations possibleMoves() = 0;
    virtual void move(int row, int col) = 0;
};

class Knight : public ChessMarble {
public:
    Knight(int row, int col) : ChessMarble(row, col) {};
    Locations possibleMoves();
    void move(int row, int col);
};

Locations Knight::possibleMoves() {
    Locations moves;
    for(int i = +1; i >= -1; i -= 2) {
        for(int j = +1; j >= -1; j -= 2) {
            int row1 = getRow() + i * 2;
            int col1 = getRow() + j * 1;
            if (valid(row1, col1)) {
                moves.emplace_back(row1, col1);
            }
            int row2 = getRow() + i * 1;
            int col2 = getRow() + j * 2;
            if (valid(row2, col2)) {
                moves.emplace_back(row2, col2);
                }
        }
    }
}

void Knight::move(int row, int col) {
    setRow(row);
    setCol(col);
}