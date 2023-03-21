#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <conio.h>

#define up 72
#define down 80
#define left 75
#define right 77

using namespace std;

class Character {
	public:
		int health, x, y;
		
		int getHealth() {
			return health;
		}
		
		void loseHealth() {

		}
		
		int getX() {
			return x;
		}
		
		int getY() {
			return y;
		}
		
};

class Player: public Character {
	public:
		string name;
		Player() {
			health = 100;
			x = 0, y = 0;
			name = "Player";
		}
		
		Player(string n) {
			health = 100;
			x = 0, y = 0;
			name = n;
		}
		
		void move(int key) {
			if (key == up) {
				y--;
			} else if (key == down) {
				y++;
			} else if (key == right) {
				x++;
			} else if (key == left) {
				x--;
			}
		}
		
		void increaseHealth(int amount) {
			health += amount;
		}
		
		void loseHealthNoFight() {
			health -= 45;
		}
		
		void loseHealth() {
			health -= rand() % 25 + 1;
		}
};

class Enemy: public Character {
	public:
		Enemy(int posx, int posy) {
			health = 100;
			x = posx, y = posy;
		}
		
		void loseHealth() {
			health -= rand() % 35 + 1;
		}
	
};

class Food {
	public:
		int amount, x, y;
		
		Food(int xx, int yy, int ch) {
			x = xx;
			y = yy;
			switch(ch) {
				case 1:
					amount = 20;
					break;
				case 2:
					amount = 35;
					break;
				case 3:
					amount = 50;
					break;
			}
		}
		
		void interactPlayer(Player* p) {
			p->increaseHealth(this->amount);
		}
		
		int getX() {
			return x;
		}
		
		int getY() {
			return y;
		}
};


class Map {

	public:
		int m[6][6];
		int row, col;
		
		Map() {
			row = sizeof(m)/sizeof(m[0]);
			col = sizeof(m[0])/sizeof(m[0][0]);
		}
		
		bool checkIfExit(Player* p, int killcount) {
			if ((p->getX() == 5 && p->getY() == 2) && killcount >= 2) {
				return true;
			} else if (p->getX() == 5 && p->getY() == 2 && killcount < 2) {
				cout << "You have not killed enough enemies to unlock the exit\n";
				return false;
			} else {
				return false;
			}
		}
		
		string checkMultiple(Player* p, vector<Enemy*> e, vector<Food*> f, int x, int y) {
			bool food = false;
			bool enemy = false;
			for (int i = 0; i < e.size(); i++) {
				if (e[i]->getX() == x && e[i]->getY() == y) {
					enemy = true;
				}
			}
			for (int i = 0; i < f.size(); i++) {
				if (f[i]->getX() == x && f[i]->getY() == y) {
					food = true;
				}
			}
			
			if (p->getX() == x && p->getY() == y) {
				if (enemy == true && food == true) {
					return "P,E,F";
				} else if (enemy == true && food == false) {
					return "P,E";
				} else if (food == true && enemy == false) {
					return "P,F";
				}
			} else {
				if (enemy == true && food == true) {
					return "E,F";
				}
			}
			
			return "";
		}
		
		bool checkForEnemy(vector<Enemy*> e, int x, int y) {
			for (int i = 0; i < e.size(); i++) {
				if (e[i]->getX() == x && e[i]->getY() == y) {
					return true;
				}
			}
			return false;
		}
		
		bool checkForFood(vector<Food*> f, int x, int y) {
			for (int i = 0; i < f.size(); i++) {
				if (f[i]->getX() == x && f[i]->getY() == y) {
					return true;
				}
			}
			return false;
		}
		
		void checkBoundary(Player* p) {
				if (p->y < 0) {
					cout << "Out of boundaries\n";
					p->y++;
				} else if (p->y > col-1) {
					cout << "Out of boundaries\n";
					p->y--;
				} else if (p->x > row-1) {
					cout << "Out of boundaries\n";
					p->x--;
				} else if (p->x < 0) {
					cout << "Out of boundaries\n";
					p->x++;
				}
			}
			
			Enemy* getEnemy(vector<Enemy*> e, int x, int y) {
			for (int i = 0; i < e.size(); i++) {
				if (e[i]->getX() == x && e[i]->getY() == y) {
					return e[i];
				}
			}
		}
			
			Food* getFood(vector<Food*> f, int x, int y) {
			for (int i = 0; i < f.size(); i++) {
				if (f[i]->getX() == x && f[i]->getY() == y) {
					return f[i];
				}
			}
		}
		
		void display(Player* p, vector<Enemy*> e, vector<Food*> f) {
			for (int i = 0; i < row; i++) {
				cout << "| ";
				for (int j = 0; j < col; j++) {
					string mult = checkMultiple(p, e, f, j, i);
					bool enemy = false, food = false;
					if (mult != "") {
						cout << mult << "|   ";
					} else {
						bool enemy = checkForEnemy(e, j, i);
						bool food = checkForFood(f, j, i);
						if (p->getX() == j && p->getY() == i) {
							cout << "P  |   ";
						} else if (enemy == true) {
							cout << "E  |   ";
						} else if (food == true) {
							cout << "F  |   ";
						} else if (i == 2 && j == 5) {
							cout << "-> |";
						} else {
							cout << "   |   ";
						}
					}
				}
				cout << endl;
			}
		}
};

void removeFood(vector<Food*> &f, int x, int y) {
	for (int i = 0; i < f.size(); i++) {
		if (f[i]->getX() == x && f[i]->getY() == y) {
			f.erase(f.begin() + i);
			break;
		}
	}
	return;
}

void removeEnemy(vector<Enemy*> &e, int x, int y) {
	for (int i = 0; i < e.size(); i++) {
		if (e[i]->getX() == x && e[i]->getY() == y) {
			e.erase(e.begin() + i);
			break;
		}
	}
	return;
}

void consumeFood(Player* p, vector<Food*> &f, Map* m) {
	Food* ff = m->getFood(f, p->getX(), p->getY());
	ff->interactPlayer(p);
	removeFood(f, p->getX(), p->getY());
	return;
}

void fight(Player* p, vector<Enemy*> &e, Map* m) {
	Enemy* ee = m->getEnemy(e, p->getX(), p->getY());
	while (p->getHealth() > 0 && ee->getHealth() > 0) {
		ee->loseHealth();
		p->loseHealth();
	}
	if (ee->getHealth() <= 0) {
		cout << "The enemy has been defeated\nYour remaining health is " << p->getHealth() << endl;
		removeEnemy(e, p->getX(), p->getY());
	} else if (p->getHealth() <= 0){
		cout << "You died!\n";
	}
	return;
}


int main() {
	vector<Enemy*> enemies;
	vector<Food*> foods;
	for (int i = 0; i < 3; i++) {
		int posx = rand() % 5 + 1;
		int posy = rand() % 5 + 1;
		Enemy* e = new Enemy(posx, posy);
		enemies.push_back(e);
	}
	
	for (int i = 0; i < 3; i++) {
		int posx = rand() % 5;
		int posy = rand() % 5;
		int num = rand() % 3 + 1;
		Food* f = new Food(posx, posy, num);
		foods.push_back(f);
	}
	
	string name, code;
	int movement, ch, killcount = 0;
	
	Map* m = new Map();
	
	cout << "Welcome to the game\nPlease enter your player's name: ";
	cin >> name;
	Player* p;
	if (name == "") {
		p = new Player();	
	} else {
		p = new Player(name);
	}
	while (m->checkIfExit(p, killcount) == false) {
		int amount = 2-killcount;
		m->display(p, enemies, foods);
		cout << "Enemies killed: " << killcount << "\nNumber of enemies left to unlock exit: " << amount << endl;
		cout << "Your current position is: " << p->getX() << " " << p->getY() << "\nPress a key to move...\n";
		movement = getch();
		p->move(movement);
		m->checkBoundary(p);
		if (m->checkForFood(foods, p->getX(), p->getY()) && m->checkForEnemy(enemies, p->getX(), p->getY())) {
			cout << "You have an enemy and food in this room\n";
			cout << "Food found and has been consumed\n";
			consumeFood(p, foods, m);
			fight(p, enemies, m);
			killcount++;
		} else if (m->checkForFood(foods, p->getX(), p->getY()) && !m->checkForEnemy(enemies, p->getX(), p->getY())) {
			cout << "Food found and has been consumed\n";
			consumeFood(p, foods, m);
		} else if (!m->checkForFood(foods, p->getX(), p->getY()) && m->checkForEnemy(enemies, p->getX(), p->getY())) {
			fight(p, enemies, m);
			killcount++;
		} else {
			cout << "Nothing is in this room.\n";
		}
		
		if (p->getHealth() <= 0) {
			break;
		}
	}
	
	if (p->getHealth() <= 0) {
		cout << endl;
	} else {
		cout << "Congrats! You made it past the exit!\n";
	}
	
	return 0;
		
}
