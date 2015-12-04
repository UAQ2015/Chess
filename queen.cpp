#include "queen.h"
#include <iostream>

Queen::Queen(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
//    std::cout << "Creating a Queen\n";
}

Queen::~Queen() {
//    std::cout << "Killing a Queen :s\n";
}

void Queen::Draw() {
if(player == 1)
        cout <<BOLDGREEN;
   else
        cout <<BOLDRED;
        std::cout << "Q";
        cout <<BLACK;
}


Queen::Queen(int _player, string _position, PiecesArray &_board) : Piece(_player, _position, _board) {

}

bool Queen::Validate(string dest)
{

  bool V= false;
        int cd = (int) (dest[0] - 'a'); // letters are the columns
        int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
        int i=1, flag=0;
		//Rook part
		if (c == cd) {
	        	int direction = rd - r > 0 ? 1 : -1;
        		for ( i = r + direction; i < rd; i++) {
            			// cout << "Getting piece " << i << " " << c << endl;
            			Piece *p = board[i][c];

            			if (p != NULL) {
                			cout << "There is a piece in the path\n";
                			p->Draw();
                			cout << endl;
                			return false;
            			}
        		}
        		if (board[rd][cd] == NULL || board[rd][cd]->player != player)
            			return true;
        		// the destination is a piece from the same player
        		return false;
    		} 
		
		if (r == rd) {
        			int direction = rd - c > 0 ? 1 : -1;
        			for ( i = c + direction; i < cd; i++) {
           				 // cout << "Getting piece " << i << " " << c << endl;
            				Piece *p = board[r][i];
	
        				if (p != NULL) {
                				cout << "There is a piece in the path\n";
                				p->Draw();
                				cout << endl;
                				return false;
            				}
        			}				
        		if (board[rd][cd] == NULL || board[rd][cd]->player != player)
            			return true;
        		// the destination is a piece from the same player
        		return false;
    			}

			//bishop part
			if (cd==c)
                        return false;
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
                	if((rd-r)/(cd-c) == 1)
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
                        	if(V==true && (board[rd][cd]==NULL || board[rd][cd]->player==2))
                                        return true;
                	if(player==2)
                        	if(V==true && (board[rd][cd]==NULL || board[rd][cd]->player==1))
                                        return true;

	return false;
}
