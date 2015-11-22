#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

/**
* Base class for knight
*/

class Knight : public Piece {
public:
    Knight(int player, int row, int col, PiecesArray &board);
    Knight(int player, string position, PiecesArray &board);

    ~Knight();

    void Draw();
    bool Validate(string);
};

#endif


