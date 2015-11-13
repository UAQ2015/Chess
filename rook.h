#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <string>
/**
* Base class for rook
*/

using namespace std;

class Rook : public Piece {
public:
    Rook(int player, int row, int col, PiecesArray &board);

    Rook(int i, string basic_string, PiecesArray &board);

    ~Rook();

    void Draw();

    bool Validate(string);
};

#endif
