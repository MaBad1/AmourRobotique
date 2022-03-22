#include "Beauf.h"
#include "Romantique.h"
#include "Bourrin.h"


void openInv(vector<vector<int>> inventaire)
{
	for (int i = 0; i < inventaire.size(); i++) {
		for (int j = 0; j < inventaire[i].size(); j++) {
			switch (inventaire[i][j]) {
			case 0:
				cout << "[ ]";
				break;
			case 1:
				cout << "[1]";
				break;
			case 2:
				cout << "[2]";
				break;
			case 3:
				cout << "[3]";
				break;
			case 4:
				cout << "[4]";
				break;
			case 5:
				cout << "[5]";
				break;
			case 6:
				cout << "[6]";
				break;
			default:
				break;
			}
		}
		cout << endl;
		cout << endl;
	}
}

void loot(Personnage& p, Objet o) {
	for (int i = 0; i < p.inventaire.size(); i++) {
		for (int j = 0; j < p.inventaire[i].size(); j++) {
			if (p.inventaire[i][j] > 0) {
				cout << "+1";
			}
			else{
				p.inventaire[i][j]= o.getValeur();
				break;
			}
		}
		break;
	}
}

int main() {


	Personnage p1("Anto", 200, 200, 100, false, 5);
	Objet o1("Fleur", 10, 5, "+10 Flirt, -5 Ego", 1);
	Objet o2("Bague", 5, 10, "+5 sensibilite, -10 Ego", 2);
	Objet o3("Capote", 10, 15, "+10 Ego, +15 Lourdeur", 3);
	Objet o4("Video de Bigard", 5, 10, "+5 Flirt, +10 Lourdeur", 4);
	Objet o5("Fouet", 10, 15, "+10 Ego, +15 Forceur", 5);
	Objet o6("Menottes", 5, 10, "+5 Flirt, +10 Forceur", 6);

	cout << p1;
	openInv(p1.inventaire);

	loot(p1, o1);
	loot(p1, o3);
	loot(p1, o6);
	loot(p1, o2);
	loot(p1, o5);
	loot(p1, o4);

	openInv(p1.inventaire);


}