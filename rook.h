#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
/**
* Base class for rook
*/

class Rook:public Piece
{
	public:
		Rook(int, int, int);
		~Rook();
		void Draw();
};

#endif
