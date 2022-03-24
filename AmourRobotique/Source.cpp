#include "Beauf.h"
#include "Romantique.h"
#include "Bourrin.h"
#include "Enemy.h"
#include<time.h>

//Fonction pour ouvrir l'inventaire.
void openInv(vector<vector<int>>& inventaire)
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
//Loot des items/déposé dans l'inventaire
void loot(Personnage& p, Objet o) // On utilise une copie des objets pour garder les presets intacts.
{
	for (int i = 0; i < p.inventaire.size(); i++) {
		for (int j = 0; j < p.inventaire[i].size(); j++) {
			if (p.inventaire[i][j] > 0) {
				cout << "next case";
			}
			else {
				p.inventaire[i][j] = o.getValeur();
				break;
			}
		}
		break;
	}
}



void tourjoueur(Personnage& p)
{
	int choixP = 0;//initialisation du choix

	if (p.getKo() == false) {


		cout << endl << "---" << p.getName() << "---" << endl;

		cout << "1.Faible 2.Moyen 3. Forte" << endl << "Selectionner le sort" << endl;
		cin >> choixP;
		//Choix de l'attack
		if (choixP == 1) {
			cout << "ATTACK Faible" << endl;
		}
		if (choixP == 2) {
			cout << "ATTACK Moyenne" << endl;
		}
		if (choixP == 3) {
			cout << "ATTACK Forte" << endl;
		}
	}



}


void tourenemy(Enemy& e) {


	int choixEnemie = 1 + rand() % 3;//random

	//Choix de l'attack
	if (e.getKo() == false) {
		cout << endl << "---" << e.getName() << "---" << endl << "elle/il prepare son attaque" << endl;

		if (choixEnemie == 1) {
			cout << "ATTACK Faible" << endl;
		}
		if (choixEnemie == 2) {
			cout << "ATTACK Moyenne" << endl;
		}
		if (choixEnemie == 3) {

			cout << "ATTACK Forte" << endl;
		}
	}
}


int main() {

	Personnage p1("Anto", 200, 200, 100, false, 5);
	Personnage p2("Mathieu", 200, 200, 100, false, 5);
	Personnage p3("Giovan", 200, 200, 100, false, 5);

	Enemy e1("Stefanie", 10, 100, false);
	Enemy e2("Gwendoline", 10, 100, false);
	Enemy e3("Patricia", 10, 100, false);

	// Création des 6 objets du jeu.
	Objet Fleur("Fleur", 10, 5, "+10 Flirt, -5 Ego", 1);
	Objet Bague("Bague", 5, 10, "+5 sensibilite, -10 Ego", 2);
	Objet Capote("Capote", 10, 15, "+10 Ego, +15 Lourdeur", 3);
	Objet Video("Video de Bigard", 5, 10, "+5 Flirt, +10 Lourdeur", 4);
	Objet Fouet("Fouet", 10, 15, "+10 Ego, +15 Forceur", 5);
	Objet Menottes("Menottes", 5, 10, "+5 Flirt, +10 Forceur", 6);

	cout << p1;
	openInv(p1.inventaire);

	//Boucle de Combat
	while (p1.getHealth() + p2.getHealth() + p3.getHealth() > 0) {

		tourjoueur(p1);
		tourjoueur(p2);
		tourjoueur(p3);

		cout << "FIN DE TOUR JOUEUR" << endl;

		tourenemy(e1);
		tourenemy(e2);
		tourenemy(e3);

		cout << endl << "FIN DE TOUR ENEMIE" << endl;


	}

}
