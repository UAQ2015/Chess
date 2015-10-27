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
//                void Draw();
		virtual void Draw();
/**
* Virtual function to draw a pawn
*/


};

#endif

