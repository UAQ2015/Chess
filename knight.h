#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight:public Piece
{
        public:
                Knight(int, int, int);
                ~Knight();
                void Draw();
};

#endif


