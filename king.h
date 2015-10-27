#ifndef KING_H
#define KING_H
#include "piece.h"
/**
* Base class for king
*/
class King:public Piece
{
        public:
                King(int, int, int);
                ~King();
                void Draw();
};

#endif


