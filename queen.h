#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

/**
* Base class for queen
*/

class Queen : public Piece {
public:
    Queen(int player, int row, int col, PiecesArray &board);

    Queen(int player, string position, PiecesArray &board);

    ~Queen();

    void Draw();
    bool Validate(string);
};

#endif

