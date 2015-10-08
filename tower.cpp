#include "tower.h"
#include <iostream>

Tower::Tower(int _player, int _x, int _y)
	:Piece(_player, _x, _y)
{	
	std::cout<<"Building a tower\n";
}

Tower::~Tower()
{
	std::cout<<"Destroying a tower *BOOM*\n";
}

void Tower::Draw()
{
	std::cout<<"Tower\n";
}
