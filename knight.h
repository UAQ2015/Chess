#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class KNIGHT:public Piece
{
        public:
                Knight(int, int, int);
                ~Knight();
                void Draw();
};

#endif


