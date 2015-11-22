#include "pawn.h"
#include <iostream>


Pawn::Pawn(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
//        std::cout<<"Creating a pawn :p\n";
}

Pawn::~Pawn() {
    //       std::cout<<"Killing a pawn Meh!\n";
}

void Pawn::Draw() {
    std::cout << "p";
}

Pawn::Pawn(int _player, string _position, PiecesArray &_board) : Piece(_player, _position, _board) {

}

bool Pawn::Validate(string dest)
{
	bool V= false;
	int cd = (int) (dest[0] - 'a'); // letters are the columns
   	int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
	  if (player==1)
        {
                if (c == cd) 
                {
			if((r==1&&rd==3)||(rd==r+1))	
			{
				if(board[rd][cd]==NULL && board[r+1][cd+1]==NULL)
						return V=true;
			}
		}
		if((c ==cd+1)||(c==cd-1))
			if(r==rd+1 && board[rd][cd]->player==2)
				return V=true;
		
	}	
	
	 if (player==2)
        {
                if (c == cd)        
                {
                        if((r==1 && rd==3)||(rd==r+1))
                        {            
				if(board[rd][cd]==NULL && board[r-1][cd-1]==NULL)
						return V=true;
                        }
                }
                if((c ==cd+1)||(c==cd-1))
			if(r==rd-1 && board[rd][cd]->player==1)
                                return V=true;

        }

}
