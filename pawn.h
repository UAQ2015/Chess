#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
/**
* Base class for pawn
*/

class Pawn:public Piece
{
public:
    Pawn(int, int, int);
    ~Pawn();
    virtual void Draw();
/**
* Virtual function to draw a pawn
*/

};

#endif

