#include <iostream>
#include <string>
#include "chessboard.h"

using namespace std;

int main()
{
    ChessBoard cb;

//	cb.TestRook();
	//cb.TestPawn();
	//cb.TestBishop();
	//cb.TestKnight();
	//cb.TestQueen();
//	cb.TestKing();
	string move="";
	Piece *p=NULL;
	bool v;

	while(cb.winner==0){
		do{
			if (cb.turn==1)
				cout<<"Player UP, is your turn.\n";
			else
				cout<<"Player DOWN, is your turn.\n";
			cb.Draw();
			cout<<"Move piece from :\n";
			cin>>move;
			p= cb.GetPiece(move);
			cout<<"Move piece to:\n";
			cin>>move;
			v= cb.Validate(p, move);

			if(v==true){
				cb.Move(p, move);
			}else{
				cout<<"Error invalid movement\n";
			}

		}while(v==false);

		cb.ChangeTurn();
	}


	cout<<"Done.\n";
    return 0;	
}

