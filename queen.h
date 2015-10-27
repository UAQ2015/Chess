#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
/**
* Base class for queen
*/

class Queen:public Piece
{
        public:
                Queen(int, int, int);
                ~Queen();
                void Draw();
};

#endif

