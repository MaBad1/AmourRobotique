#include "Beauf.h"
#include "Romantique.h"
#include "Bourrin.h"


//Fonction pour ouvrir l'inventaire.
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

//loot des objets dans l'inventaire d'un personnage.
void loot(Personnage& p, Objet o) //On utilise une copie des objets pour garder les presets intacts.
{
	for (int i = 0; i < p.inventaire.size(); i++) {
		for (int j = 0; j < p.inventaire[i].size(); j++) {
			if (p.inventaire[i][j] > 0) {
				cout << "next case";
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

	//Création des 6 objets du jeu.
	Objet Fleur("Fleur", 10, 5, "+10 Flirt, -5 Ego", 1);
	Objet Bague("Bague", 5, 10, "+5 sensibilite, -10 Ego", 2);
	Objet Capote("Capote", 10, 15, "+10 Ego, +15 Lourdeur", 3);
	Objet Video("Video de Bigard", 5, 10, "+5 Flirt, +10 Lourdeur", 4);
	Objet Fouet("Fouet", 10, 15, "+10 Ego, +15 Forceur", 5);
	Objet Menottes("Menottes", 5, 10, "+5 Flirt, +10 Forceur", 6);
	
	


}