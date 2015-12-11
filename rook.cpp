#include "rook.h"
#include <iostream>

Rook::Rook(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}


Rook::Rook(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
//	std::cout<<"Building a rook\n";
}

Rook::~Rook() {
//	std::cout<<"Destroying a rook *BOOM*\n";
}

void Rook::Draw() {
   if(player == 1)
        cout <<BOLDGREEN;
   else
        cout <<BOLDRED;
        std::cout << "R";
        cout <<BLACK;
}

bool Rook::Validate(string dest) {
    bool v = false;
    int cd = (int) (dest[0] - 'a'); // letters are the columns
    int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
	
	
	if(c>7||cd>7||r>7||rd>7||c<0||cd<0||r<0||rd<0)
	{
		cout << "not valid position\n";
		return false;
	}
    if (c == cd) {
        if(rd>r)
		{
        	for (int i = r+1; i < rd; i++) {
            	// cout << "Getting piece " << i << " " << c << endl;
					if(board[i][c]!=NULL){
        	        cout << "There is a piece in the path\n";
                	cout << endl;
                	return false;
   			   	}
        	}
		}
        if(rd<r)
		{
        	for (int i = rd+1; i < r; i++) {
            	// cout << "Getting piece " << i << " " << c << endl;
					if(board[i][c]!=NULL){
        	        cout << "There is a piece in the path\n";
                	cout << endl;
                	return false;
   			   		}
        	}
		}

        if (board[rd][cd] == NULL || board[rd][cd]->player != player)
            return true;
        // the destination is a piece from the same player
        return false;
    } 
	    if (r == rd) {
        if(cd>c)
		{
        	for (int i = c+1; i < cd; i++) {
            	// cout << "Getting piece " << i << " " << c << endl;
					if(board[r][i]!=NULL){
        	        cout << "There is a piece in the path\n";
                	cout << endl;
                	return false;
   			   	}
        	}
		}
        if(cd<c)
		{
        	for (int i = cd+1; i < c; i++) {
            	// cout << "Getting piece " << i << " " << c << endl;
					if(board[r][i]!=NULL){
        	        cout << "There is a piece in the path\n";
                	cout << endl;
                	return false;
   			   		}
        	}
		}

        if (board[rd][cd] == NULL || board[rd][cd]->player != player)
            return true;
        // the destination is a piece from the same player
        return false;

		}
}

