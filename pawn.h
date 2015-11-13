#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

/**
* Base class for pawn
*/

class Pawn : public Piece {
public:
    Pawn(int player, int row, int col, PiecesArray &board);

    Pawn(int player, string position, PiecesArray &board);

    ~Pawn();

    virtual void Draw();
/**
* Virtual function to draw a pawn
*/

    bool Validate(string);


};


#endif

