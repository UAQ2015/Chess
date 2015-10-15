#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn:public Piece
{
        public:
                Pawn(int, int, int);
                ~Pawn();
                void Draw();
};

#endif

