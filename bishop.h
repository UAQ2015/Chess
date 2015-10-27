#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
/**
* Base class for bishop
*/
class Bishop:public Piece
{
        public:
                Bishop(int, int, int);
                ~Bishop();
                void Draw();
};

#endif

