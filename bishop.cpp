#include "bishop.h"
#include <iostream>

Bishop::Bishop(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board)
{
//        std::cout<<"Creating a Bishop\n";
}

Bishop::~Bishop()
{
//        std::cout<<"Killing a Bishop\n";
}

void Bishop::Draw()
{
        std::cout<<"B";
}

Bishop::Bishop(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}


bool Bishop::Validate(string dest)
{
        bool V= false;
        int cd = (int) (dest[0] - 'a'); // letters are the columns
        int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
  	int i=1, flag=0;
                if ((rd-r)/(cd-c) == -1)
                {
			if(cd-c<0)
			{
					for(i=1;i<c-cd;i++)
						if(board[r+i][c-i]!=NULL)
							flag=1;
               				if(flag==0)
						 V=true;
			}
			else
       			{
                                        for(i=1;i<cd-c;i++)
                                                if(board[r-i][c+i]!=NULL)
                                                        flag=1;
                                        if(flag==0)
                                                V=true;
                        }
 
                }
		if((d-c)/(rd-r) == 1)
		{
			if(cd-c<0)
                        {
                                        for(i=1;i<c-cd;i++)
                                                if(board[r-i][c-i]!=NULL)
                                                        flag=1;
                                        if(flag==0)
                                                V=true;
                        }
                        else
                        {
                                        for(i=1;i<cd-c;i++)
                                                if(board[r+i][c+i]!=NULL)
                                                        flag=1;
                                        if(flag==0)
                                                V=true;
                        }

		}
		if(player==1)
i			if(V==true && board[rd][cd]==NULL)
			{
				if(board[rd][cd]->player==2)
					return V;
				else
					return V;
			}	
		else
			if(V==true && board[rd][cd]==NULL)
                        {
                                if(board[rd][cd]->player==1)
                                        return V;
                                else
                                        return V;
                        }
			
}
