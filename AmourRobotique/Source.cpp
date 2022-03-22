#include "Beauf.h"
#include "Romantique.h"
#include "Bourrin.h"
#include<time.h>

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
	Personnage p2("Mathieu", 200, 200, 100, false,5);
	Personnage p3("Giovan", 200, 200, 100, false,5);

	Personnage p4("Valentine", 200, 200, 100, false,5);
	Personnage p5("Helene", 200, 200, 100, false,5);
	Personnage p6("Manon", 200, 200, 100, false,5);


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




	int choixP = 0;

	int choixEnemie = 0;
	cout << p1;

	while (p1.getHealth() + p2.getHealth() + p3.getHealth() > 0 && p1.getHealth() > 0) {

		if (p1.getKo() == false) {
			cout << endl << "---" << p1.getName() << "---" << endl;


			cout << "1.Faible 2.Moyen 3. Forte" << endl << "Selectionner le sort" << endl;
			cin >> choixP;
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

		if (p2.getKo() == false) {
			cout << endl << "---" << p2.getName() << "---" << endl;
			cout << "1.Faible 2.Moyen 3. Forte" << endl << "Selectionner le sort" << endl;
			cin >> choixP;

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

		if (p3.getKo() == false) {
			cout << endl << "---" << p3.getName() << "---" << endl;
			cout << "1.Faible 2.Moyen 3. Forte" << endl << "Selectionner l'atatck" << endl;
			cin >> choixP;


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


		cout << "FIN DE TOUR JOUEUR" << endl;


		srand(time(NULL));
		choixEnemie = 1 + rand() % 3;
		cout << endl << "---" << p4.getName() << "---" << endl << "elle/il prepare son attaque" << endl;
		if (p4.getKo() == false) {
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
		choixEnemie = 1 + rand() % 3;
		cout << endl << "---" << p5.getName() << "---" << endl << "elle/il prepare son attaque" << endl;
		if (p5.getKo() == false) {
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
		choixEnemie = 1 + rand() % 3;
		cout << endl << "---" << p6.getName() << "---" << endl << "elle/il prepare son attaque" << endl;
		if (p6.getKo() == false) {
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
		cout << "FIN DE TOUR ENEMIE" << endl;


	}

}