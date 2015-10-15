#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop:public Piece
{
        public:
                Bishop(int, int, int);
                ~Bishop();
                void Draw();
};

#endif

