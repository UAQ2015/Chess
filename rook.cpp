#include "rook.h"
#include <iostream>

Rook::Rook(int _player, int _x, int _y)
	:Piece(_player, _x, _y)
{	
//	std::cout<<"Building a rook\n";
}

Rook::~Rook()
{
//	std::cout<<"Destroying a rook *BOOM*\n";
}

void Rook::Draw()
{
	std::cout<<"R";
}

bool Rook::Validate(string dest)
{
	bool v=false;
	int cd= (int) (dest[0]-'a'); // letters are the columns
	int rd= (int) 8- (dest[1]-'0'); // numbers are rows

	if(c==cd){
		cout<<"r "<<r<<"rd "<<rd<<endl;
		for(int i=r;i<rd;i++){
			cout<<endl<<i<<endl;
			if (board[i][c]!=NULL)
				return false;
		}
		if (board[rd][cd]==NULL|| board[rd][cd]->player != player)
			return true;
		// the destination is a piece from the same player
		return false;
	}else if(r==rd){
	}
	else{
		cout << "invalid movement\n";
		return false;
	}

	return v;
}

