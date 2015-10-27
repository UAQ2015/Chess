#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
/**
* Base class for knight
*/

class Knight:public Piece
{
        public:
                Knight(int, int, int);
                ~Knight();
                void Draw();
};

#endif


