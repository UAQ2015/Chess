#include <iostream>
#include "piece.h"
#include "tower.h"

int main()
{
	Piece p(1, 1, 0);
	Piece p2(2, 6, 0);
	p.Draw();
	Tower t(1, 0, 0), t2(2, 7, 0);
	t.Draw();
	return 0;	
}
