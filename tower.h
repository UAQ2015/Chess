#ifndef TOWER_H
#define TOWER_H
#include "piece.h"

class Tower:public Piece
{
	public:
		Tower(int, int, int);
		~Tower();
		void Draw();
};

#endif
