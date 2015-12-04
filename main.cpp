#include <iostream>
#include <string>
#include "chessboard.h"

using namespace std;

int main()
{
    ChessBoard cb;

//	cb.TestRook();
//	cb.TestPawn();
	//cb.TestBishop();
	//cb.TestKnight();
	//cb.TestQueen();
//	cb.TestKing();
	string move="";
	Piece *p=NULL;
	bool v;
	cout << BLACK;
	while(cb.winner==0){
		do{
			if (cb.turn==1)
			{
				cout <<BOLDGREEN;
				cout<<"Player GREEN, is your turn.\n";
				cout <<BLACK;
			}
			else
			{
				cout <<BOLDRED;
				cout<<"Player RED, is your turn.\n";
				cout <<BLACK;
			}
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

	if (cb.turn == 1)
	cout<<"Player GREEN is the WINNER!!!!!!!!\n";
	else
	cout << "Player RED is the WINNER!!!!!!!!!\n";
    return 0;	
}

