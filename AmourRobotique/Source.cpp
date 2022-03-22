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
	}
}

int main() {


	Personnage p1("Anto", 200, 200, 100, false, 5);

	cout << p1;
	openInv(p1.inventaire);


}