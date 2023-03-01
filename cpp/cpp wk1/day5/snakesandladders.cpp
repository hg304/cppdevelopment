#include <iostream>
#include <cstdlib>

using namespace std;

int playgame(char p[100], int pos, string player) {
	string ok;
	cout << player << ",  press enter to throw dice";
	cin >> ok;
	cout << "\n";
	
	int dice = rand() % 6 + 1;

	cout << "Your roll was " << dice << "\n";
	
	p[pos] = '0';
	for (int i = 0; i < dice; i++) {
		pos += 1;
		if (i == (dice - 1)) {
			p[pos] = 'x';
		}
	}
	
	if (pos > 99) {
		return 99;
	}
	
	return pos;
	
}

int snakeladdercheck(char board[100], int pos) {
	if (board[pos] == '1') {
		cout << "You are on a ladder! Going up 40 places...\n";
		pos += 40;
	} else if (board[pos] == '2') {
		cout << "You are on a ladder! Going up 24 places...\n";
		pos += 24;
	} else if (board[pos] == '3') {
		cout << "You are on a ladder! Going up 19 places...\n";
		pos += 19;
	} else if (board[pos] == '4') {
		cout << "You are on a ladder! Going up 23 places...\n";
		pos += 23;
	} else if (board[pos] == 'a') {
		cout << "You are on a snake! Going down 38 places...\n";
		pos -= 38;		
	} else if (board[pos] == 'b') {
		cout << "You are on a snake! Going down 22 places...\n";
		pos -= 22;
	} else if (board[pos] == 'c') {
		cout << "You are on a snake! Going down 21 places...\n";
		pos -= 21;
	} else {
		cout << "You have not landed on a snake or ladder.\n";
	}
	
	return pos;
}

int main() {
	char board[100];
	char p1[100], p2[100];
	string player1, player2;
	int flag = 0;
	
	for (int i = 0; i < 100; i++) {
		p1[i] = '0';
		p2[i] = '0'; 
	}
	
	p1[0] = 'x';
	p2[0] = 'x';
	
	int p1pos = 0, p2pos = 0;
	
	board[5] = '1'; board[18] = '2'; board[51] = '3'; board[56] = '4'; board[46] = 'a'; board[61] = 'b'; board[95] = 'c';
	
	cout << "Enter player 1's name: ";
	cin >> player1;
	cout << "\n";
	
	cout << "Enter player 2's name: ";
	cin >> player2;
	cout << "\n";
	
	do {
		if (p1pos == p2pos) {
			for (int i = 0; i < 100; i++) {
				if (i == p1pos) {
					cout << "x ";
				} else {
					if (board[i] == '1' || board[i] == '2' || board[i] == '3' || board[i] == '4') {
						cout << i+1 << "L ";
					} else if (board[i] == 'a' || board[i] == 'b' || board[i] == 'c') {
						cout << i+1 << "S ";
					} else {
						cout << i+1 << " ";
					}
				}
			}
		} else {
			for (int i = 0; i < 100; i++) {
				if (i == p1pos || i == p2pos) {
					cout << "x ";
				} else {
					if (board[i] == '1' || board[i] == '2' || board[i] == '3' || board[i] == '4') {
						cout << i+1 << "L ";
					} else if (board[i] == 'a' || board[i] == 'b' || board[i] == 'c') {
						cout << i+1 << "S ";
					} else {
						cout << i+1 << " ";
					}
				}
			}
		}
		cout << "\n\n";
		cout << "Player 1's position: " << p1pos+1 << "\n";
		cout << "Player 2's position: " << p2pos+1 << "\n";
		
		if (flag == 0) {
			p1pos = playgame(p1, p1pos, player1);
			p1pos = snakeladdercheck(board, p1pos);
			cout << "New position: " << p1pos+1 << "\n";
			flag = 1;
		} else {
			p2pos = playgame(p2, p2pos, player2);
			p2pos = snakeladdercheck(board, p2pos);
			cout << "New position: " << p2pos+1 << "\n";
			flag = 0;
		}
	} while (p1pos != 99 && p2pos != 99);
	
	if (p1[99] == 'x') {
		cout << player1 << " is the winner\n";
	} else {
		cout << player2 << " is the winner\n";
	}
	
}
