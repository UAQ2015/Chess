#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

/**
* Base class for bishop
*/
class Bishop : public Piece {
public:
    Bishop(int player, int row, int col, PiecesArray &board);
    Bishop(int player, string position, PiecesArray &board);

    ~Bishop();

/**
* Virtual function to draw a pawn
*/
    virtual void Draw();


};

#endif

