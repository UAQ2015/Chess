#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include <string>
/**
* Base class for rook
*/

using namespace std;

class Rook:public Piece
{
	public:
		Rook(int, int, int);
		~Rook();
		void Draw();
		bool Validate(string);
};

#endif
