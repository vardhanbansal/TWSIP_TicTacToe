#include<iostream>
using namespace std;
#include <conio.h>

void PrintNumberBoard();
void PrintTable();
int addMark();
int check();
					
char Table[3][3] = {' ',' ',' ',
					' ',' ',' ',
					' ',' ',' '	};

int turn =1;
char mark = 'O';
int input;


int main(){
	int won=0;
	int validInput=0;

	for(int i=0;i<9;i++){
		system("cls");
		PrintTable();

		if(turn) cout<<"Player 1 (Symbol : O)"<<endl;
		else cout<<"Player 2 (Symbol : X)"<<endl;

		PrintNumberBoard();
		cout<<"Enter Input form Table"<<endl;
		cin>>input;

		while(input<0 || input>9){
			cout<<"Input is Invalid! , Please Re-Enter the Input : ";
			cin>>input;
		}
		if(turn) mark = 'O';
		else mark = 'X';

		validInput = addMark();
		if(!validInput){
			i--;
			continue;
		}
		won=check();
		if(won){
			system("cls");
			PrintTable();
			if(turn) cout<<endl<<"Player 1 You Won!!";
			else cout<<endl<<"Player 2 You Won!!";
			getch();
			break;
		}
		if(i==8){
			system("cls");
			PrintTable();
			 cout<<endl<<"Match Drawn!!";
		}

		turn = !turn;

	}
	return 0;
}

void PrintNumberBoard(){
	cout<<endl<<endl<<"Table Formation"<<endl;
	cout<<" 1 | 2 | 3 "<<endl;
	cout<<"---------- "<<endl;
	cout<<" 4 | 5 | 6 "<<endl;
	cout<<"---------- "<<endl;
	cout<<" 7 | 8 | 9 "<<endl;
}

void PrintTable(){
	cout<<" "<<Table[0][0]<<" | "<<Table[0][1]<<" | "<<Table[0][2]<<" "<<endl;
	cout<<"---------- "<<endl;
	cout<<" "<<Table[1][0]<<" | "<<Table[1][1]<<" | "<<Table[1][2]<<" "<<endl;
	cout<<"---------- "<<endl;
	cout<<" "<<Table[2][0]<<" | "<<Table[2][1]<<" | "<<Table[2][2]<<" "<<endl;
}


int addMark(){
	for(int i=0,k=1;i<3;i++){
		for(int j=0;j<3;j++,k++){
			if(k==input) {
				if(Table[i][j] == ' '){
					Table[i][j] = mark;
					return 1;
				}
				else{
					cout<<"Invalid Input";
					getch();
					return 0;
				}
			}
		}
	}
}

int check(){

	//checking of rows
	if(Table[0][0]==mark && Table[0][1]==mark && Table[0][2]==mark)
		return 1;
	if(Table[1][0]==mark && Table[1][1]==mark && Table[1][2]==mark)
		return 1;
	if(Table[2][0]==mark && Table[2][1]==mark && Table[2][2]==mark)
		return 1;

	//checking of cloumns
	if(Table[0][0]==mark && Table[1][0]==mark && Table[2][0]==mark)
		return 1;
	if(Table[0][1]==mark && Table[1][1]==mark && Table[2][1]==mark)
		return 1;
	if(Table[0][2]==mark && Table[1][2]==mark && Table[2][2]==mark)
		return 1;

	//checking of diagonals
	if(Table[0][0]==mark && Table[1][1]==mark && Table[2][2]==mark)
		return 1;
	if(Table[0][2]==mark && Table[1][1]==mark && Table[2][0]==mark)
		return 1;

	return 0;
}
