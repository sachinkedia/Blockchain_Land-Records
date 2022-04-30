
#include<iostream>
#include<vector>
#include<time.h>
#include<iomanip>
#include<windows.h>
#include "board.cpp"
#include "movegen.cpp"
#include "makemove.cpp"
#include "alphabeta.cpp"

string DefaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
using namespace std;
int main(){

    time_t start, end;
    double time_taken;
    alphabeta ab;            // Object of class Alpha beta
    ab.ParseFEN(DefaultFen); //set default position (i.e. starting of the game)
    ab.PrintBoard();
    int n=0,q;
    while(n!=4){                    //n=4 when user select exit option
        if(ab.Check_FM()){
            cout<<"\nGame Drawn";       //check for fifty moves
            break;
        }
        if(ab.IsCheckMate()){
            cout<<"\nGame Over";        //check for checkmate
            break;
        }
        string fen;
        string mov;
        cout<<"\n1. fen\n2. move\n3. CPU move\n4. exit\nEnter choice:";
        cin>>n;
        switch(n){
            case 1: cout<<"Enter FEN: ";
                    getchar();                  
                    getline(cin, fen,'\n');
                    ab.ParseFEN(fen);
                    ab.PrintBoard();
                    break;
            case 2: cout<<"Enter move: ";
                    cin>>mov;
                    ab.validMove(mov);break;
            case 3: cout<<"\nEnter Depth:";
                    cin>>q;
                    time(&start);
                    ab.execmove(ab.bestmove(q));
                    time(&end);
                    time_taken = double(end - start);
                    ab.PrintBoard();
                    cout<<"\nExecution Time: "<<fixed<< time_taken << setprecision(5)<<"sec\n";
                    break;
            case 4: break;
            default: cout<<"Invalid choice";
        }      
    }
}