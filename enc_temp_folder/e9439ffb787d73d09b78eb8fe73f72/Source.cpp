#include "Beauf.h"
#include "Romantique.h"
#include "Bourrin.h"
#include "Enemy.h"
#include<time.h>
#include "Zone.h"
#include <list>
#include <Windows.h>

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
	int Lecture = 0;
	cout << "Choisissez le numéro d'un objet dont lire la description (ou 0 pour skip) : " << endl;
	cin >> Lecture;

	switch (Lecture) {
	case 0:
		cout << " "<< endl;
		break;
	case 1:
		cout << "Fleur, +10 Flirt, -5 Ego." << endl;
		break;
	case 2:
		cout << "Bague, +5 sensibilite, -10 Ego." << endl;
		break;
	case 3:
		cout << "Capote, +10 Ego, +15 Lourdeur." << endl;
		break;
	case 4:
		cout << "Video de Bigard, +5 Flirt, +10 Lourdeur." << endl;
		break;
	case 5:
		cout << "Fouet, +10 Ego, +15 Forceur." << endl;
		break;
	case 6:
		cout << "Menottes, +5 Flirt, +10 Forceur." << endl;
		break;
	default:
		break;
	}
}

// Création des 6 objets du jeu.
Objet Fleur("Fleur", 10, 5, "+10 Flirt, -5 Ego", 1);
Objet Bague("Bague", 5, 10, "+5 sensibilite, -10 Ego", 2);
Objet Capote("Capote", 10, 15, "+10 Ego, +15 Lourdeur", 3);
Objet Video("Video de Bigard", 5, 10, "+5 Flirt, +10 Lourdeur", 4);
Objet Fouet("Fouet", 10, 15, "+10 Ego, +15 Forceur", 5);
Objet Menottes("Menottes", 5, 10, "+5 Flirt, +10 Forceur", 6);

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


//attack joueur
void attackBourrin(Bourrin& p, Enemy& e1, Enemy& e2, Enemy& e3)
{
	int cible = 0;

	if (p.getKo() == false) 
	{
		int choixObjet = 0;
		cout << p << endl;
		cout << "1.Objet   2.Disquettes" << endl;
		cin >> choixObjet;
		if (choixObjet ==1) 
		{
			int choixItem;
			cout << "Choisisez un objet à utiliser :" << endl;
			cout << "1:Fleur   2:Bague   3:Capote" << endl << "4:Video de Bigard   5:Fouet   6:Menottes" << endl;
			cin >> choixItem;
			switch (choixItem) {
			case 1:
				p.use(Fleur);
				break;
			case 2:
				p.use(Bague);
				break;
			case 3:
				p.use(Capote);
				break;
			case 4:
				p.use(Video);
				break;
			case 5:
				p.use(Fouet);
				break;
			case 6:
				p.use(Menottes);
				break;
			}
			cout << p << endl;
		}

		if (choixObjet == 2)
		{
			cout << "Choix d'une cible :" << endl << "1." << e1.getName() << "  2." << e2.getName() << "  3." << e3.getName() << endl;
			cin >> cible; //ciblage de l'énemi
			if (cible == 1)
			{
				int choixP = 0;//initialisation du choix
				if (p.getKo() == false) {
					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteBourrinM(e1);
						cout << endl << e1 << endl;
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBourrinL(e1);
						cout << endl << e1 << endl;
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBourrinXL(e1);
						cout << endl << e1 << endl;
					}
				}

			}
			if (cible == 2)
			{
				int choixP = 0;//initialisation du choix

				if (p.getKo() == false) {
					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteBourrinM(e2);
						cout << endl << e2 << endl;
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBourrinL(e2);
						cout << endl << e2 << endl;

					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBourrinXL(e2);
						cout << endl << e2 << endl;


					}
				}

			}
			if (cible == 3)
			{
				int choixP = 0;//initialisation du choix

				if (p.getKo() == false) {


					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteBourrinM(e3);
						cout << endl << e3 << endl;

					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBourrinL(e3);
						cout << endl << e3 << endl;

					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBourrinXL(e3);
						cout << endl << e3 << endl;
					}
				}

			}

		}
	}
	else {
	cout << p.getName() << " n'est plus dans cette discution." << endl;
	}
}
void attackRomantique(Romantique& p, Enemy& e1, Enemy& e2, Enemy& e3)
{
	int cible = 0;

	if (p.getKo() == false) 
	{
		int choixObjet = 0;
		cout << p << endl;
		cout << "1.Objet   2.Disquettes" << endl;
		cin >> choixObjet;
		if (choixObjet ==1) 
		{
			int choixItem;
			cout << "Choisisez un objet à utiliser :" << endl;
			cout << "1:Fleur   2:Bague   3:Capote "<< endl <<"4:Video de Bigard   5:Fouet   6:Menottes" << endl;
			cin >> choixItem;
			switch (choixItem) {
			case 1:
				p.use(Fleur);
				break;
			case 2:
				p.use(Bague);
				break;
			case 3:
				p.use(Capote);
				break;
			case 4:
				p.use(Video);
				break;
			case 5:
				p.use(Fouet);
				break;
			case 6:
				p.use(Menottes);
				break;
			}
			cout << p << endl;
		}

		if (choixObjet == 2)
		{
			cout << "Choix d'une cible :" << endl << "1." << e1.getName() << "   2." << e2.getName() << "   3." << e3.getName() << endl;
			cin >> cible; //ciblage de l'énemi
			if (cible == 1)
			{
				int choixP = 0;//initialisation du choix
				if (p.getKo() == false) {
					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteRomantiqueM(e1);
						cout << endl << e1 << endl;
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteRomantiqueL(e1);
						cout << endl << e1 << endl;
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteRomantiqueXL(e1);
						cout << endl << e1 << endl;
					}
				}

			}
			if (cible == 2)
			{
				int choixP = 0;//initialisation du choix

				if (p.getKo() == false) {
					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteRomantiqueM(e2);
						cout<< endl << e2 << endl;

					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteRomantiqueL(e2);
						cout << endl << e2 << endl;
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteRomantiqueXL(e2);
						cout << endl << e2 << endl;
					}
				}

			}
			if (cible == 3)
			{
				int choixP = 0;//initialisation du choix

				if (p.getKo() == false) {


					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteRomantiqueM(e3);
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteRomantiqueL(e3);

					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteRomantiqueXL(e3);

					}
				}

			}

		}
	}
	else {
	cout << p.getName() << " n'est plus dans cette discution." << endl;
	}

}
void attackBeauf(Beauf& p, Enemy& e1, Enemy& e2, Enemy& e3)
{
	int cible = 0;

	if (p.getKo() == false) 
	{
		int choixObjet = 0;
		cout << p << endl;
		cout << "1.Objet    2.Disquettes" << endl;
		cin >> choixObjet;
		if (choixObjet ==1) 
		{
			int choixItem;
			cout << "Choisisez un objet à utiliser :" << endl;
			cout << "1: Fleur   2:Bague   3:Capote" << endl << "4:Video de Bigard   5:Fouet   6:Menottes" << endl;
			cin >> choixItem;
			switch (choixItem) {
			case 1:
				p.use(Fleur);
				break;
			case 2:
				p.use(Bague);
				break;
			case 3:
				p.use(Capote);
				break;
			case 4:
				p.use(Video);
				break;
			case 5:
				p.use(Fouet);
				break;
			case 6:
				p.use(Menottes);
				break;
			}
			cout << p << endl;
		}

		if (choixObjet == 2)
		{
			cout << "Choix d'une cible :" << endl << "1." << e1.getName() << " 2." << e2.getName() << " 3." << e3.getName() << endl;
			cin >> cible; //ciblage de l'énemi
			if (cible == 1)
			{
				int choixP = 0;//initialisation du choix
				if (p.getKo() == false) {
					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteBeaufM(e1);
						cout << endl << e1 << endl;

					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBeaufL(e1);
						cout << endl << e1 << endl;

					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBeaufXL(e1);
						cout << endl << e1 << endl;

					}
				}

			}
			if (cible == 2)
			{
				int choixP = 0;//initialisation du choix

				if (p.getKo() == false) {
					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteBeaufM(e2);
						cout << endl << e2 << endl;

					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBeaufL(e2);
						cout << endl << e2 << endl;

					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBeaufXL(e2);
						cout << endl << e2 << endl;

					}
				}

			}
			if (cible == 3)
			{
				int choixP = 0;//initialisation du choix

				if (p.getKo() == false) {


					cout << "1.Faible   2.Moyen   3.Forte" << endl << "Selectionner la puissance de la disquette" << endl;
					cin >> choixP;
					//Choix de l'attack
					if (choixP == 1) {
//						cout << "ATTACK Faible" << endl;
						p.disquetteBeaufM(e3);
						cout << endl << e3 << endl;

					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBeaufL(e3);
						cout << endl << e3 << endl;

					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBeaufXL(e3);
						cout << endl << e3 << endl;
					}
				}

			}

		}
	}
	else {
	cout << p.getName() << " n'est plus dans cette discution." << endl;
	}
}
void checkhealth(Personnage& p) {
	if (p.getEgo() == 0) {
		p.setEgo(100);
		p.setHealth(p.getHealth() - 1);
	}
	if (p.getHealth() == 0)
	{
		p.setKo(true);
	}
}

//attack enemy
void attackenemy(Personnage& p1, Personnage& p2, Personnage& p3, Enemy& e)
{
	srand(time(NULL));
	cout << e << endl;
	int cible = 1+ rand()%3;
	if (e.getKo() == false) 
	{
		if (cible == 1) 
		{

			cout << endl << "---" << e.getName() << "---" << endl << "elle prepare sa riposte" << endl;
			int choixEnemie = 1 + rand() % 3;//random
			cout << "La cible choisie est " << p1.getName() << endl;
			//Choix de l'attack
			if (e.getKo() == false) {

				if (choixEnemie == 1) {
					cout << "ATTACK Faible" << endl;
					e.rateauM(p1);
					checkhealth(p1);
					cout << endl << p1<< endl;

				}
				if (choixEnemie == 2) {
					cout << "ATTACK Moyenne" << endl;
					e.rateauL(p1);
					checkhealth(p1);
					cout << endl << p1 << endl;

				}
				if (choixEnemie == 3) {

					cout << "ATTACK Forte" << endl;

					e.rateauXL(p1);
					checkhealth(p1);
					cout << endl << p1 << endl;


				}
			}
			
		}
		if (cible == 2) 
		{
			cout << endl << "---" << e.getName() << "---" << endl << "elle prepare sa riposte" << endl;
			int choixEnemie = 1 + rand() % 3;//random
			cout << "La cible choisie " << p2.getName() << endl;
			//Choix de l'attack
			if (e.getKo() == false) {

				if (choixEnemie == 1) {
					cout << "ATTACK Faible" << endl;
					e.rateauM(p2);
					checkhealth(p2);
					cout << endl << p2 << endl;

				}
				if (choixEnemie == 2) {
					cout << "ATTACK Moyenne" << endl;
					e.rateauL(p2);
					checkhealth(p2);
					cout << endl << p2 << endl;

				}
				if (choixEnemie == 3) {
					cout << "ATTACK Forte" << endl;
					e.rateauXL(p2);
					checkhealth(p2);
					cout << endl << p2 << endl;

				}
			}
		}
		if (cible == 3) 
		{
			cout << endl << "---" << e.getName() << "---" << endl << "elle prepare sa riposte" << endl;
			cout << "La cible choisie " << p3.getName() << endl;
			int choixEnemie = 1 + rand() % 3;//random
			//Choix de l'attack
			if (e.getKo() == false) {
				if (choixEnemie == 1) {
//					cout << "ATTACK Faible" << endl;
					e.rateauM(p3);
					checkhealth(p3);

					cout << endl << p3 << endl;


				}
				if (choixEnemie == 2) {
// 					cout << "ATTACK Moyenne" << endl;
					e.rateauL(p3);
					checkhealth(p3);

					cout << endl << p3 << endl;


				}
				if (choixEnemie == 3) {
//					cout << "ATTACK Forte" << endl;
					e.rateauXL(p3);
					checkhealth(p3);

					cout << endl << p3 << endl;


				}
			}
		}
	}
	else {
	cout << e.getName() << " n'est plus dans cette discution." << endl;
	}
}


void Choix(Personnage& personnage, vector<Zone> zones, vector<Zone> zonesPossibles, int chosen_way)
{

	if (personnage.getPlace() == 0) {//si la position du joueur 1 est de 0 (c'est à dire le spawn)

		int choixZ = 0; // création/réinitialisation à 0 de la variable de choix de zone
		int FinChoixZ = 0;// création/réinitialisation à 0 de la variable de fin de choix de zone pour sortir du while plus bas


		cout << "le joueur :  " << personnage.getName() << " se trouve au départ" << endl << endl;

		for (int i = 0; i < zones.size(); i++) {//recherche parmis chaque zone, qu'elle zone est accessible pour le joueur
			if (zones[i].getNiveau() == 1) {//ici, on cherche chaque zone dont le niveau est 1 (si le joueur est dans une zone de niveau1, il faudra chercher les zones de niveau 2)
				cout << zones[i].getName() << " est possible " << endl << endl;//toutes les zones de niveau 1
				zones[i].setLinked(true);//sont accessibles
				zonesPossibles.push_back(zones[i]);//ajout de la zone dans une nouvelle liste qui ne contient que les zones possibles
			}
		}

		//cout << " taille de la liste : " << zonesPossibles.size() << endl;

		if (zonesPossibles.size() == 3) {//si il y a 3 zones différentes on vient ici

			while (FinChoixZ == 0) {

				cout << "Choisissez une des zones disponibles en écrivant un chiffre entre 1 et 3" << endl;
				cin >> choixZ;

				system("cls"); //Clean

				if (choixZ == 1) {//le joueur choisit la zone n°1
					cout << "Vous entrez dans : " << zonesPossibles[0].getName() << endl << endl;//on affiche le nom de la zone n°1 (!)attention(!) le premier élément d'une liste est toujours 0, le deuxième 1 etc...
					zonesPossibles[1].setLinked(false);//on délink les autres zones car elles ne seront plus accessibles (pas besoin de comprendre ça je l'utilise pas pour l'instant)
					zonesPossibles[2].setLinked(false);
					chosen_way = 1;//le choix choisis est le numéro un , permet d'initialiser les boucles de jeu plus bas
					FinChoixZ = 1;//on sort de la boucle
				}
				else if (choixZ == 2) {
					cout << "vous entrez dans : " << zonesPossibles[1].getName() << endl;
					zonesPossibles[0].setLinked(false);
					zonesPossibles[2].setLinked(false);
					chosen_way = 2;
					FinChoixZ = 1;
				}
				else if (choixZ == 3) {
					cout << "vous entrez dans : " << zonesPossibles[2].getName() << endl;
					zonesPossibles[0].setLinked(false);
					zonesPossibles[1].setLinked(false);
					chosen_way = 3;
					FinChoixZ = 1;
				}
				else {
					cout << "erreur d'entree, veuillez entrer un chiffre entre 1 et 3" << endl;
				}
			}
		}

		if (zonesPossibles.size() == 2) {//si il y a 2 zones différentes on vient ici

			while (FinChoixZ == 0) {

				cout << "Choisissez une des zones disponibles en écrivant un chiffre entre 1 et 2" << endl;
				cin >> choixZ;

				if (choixZ == 1) {//le joueur choisit la zone n°1
					cout << "Vous entrez dans : " << zonesPossibles[0].getName() << endl;//on affiche le nom de la zone n°1 (!)attention(!) le premier élément d'une liste est toujours 0, le deuxième 1 etc...
					zonesPossibles[1].setLinked(false);//on délink les autres zones car elles ne seront plus accessibles (pas besoin de comprendre ça je l'utilise pas pour l'instant)
					chosen_way = 1;//le choix choisis est le numéro un , permet d'initialiser les boucles de jeu plus bas
					FinChoixZ = 1;//on sort de la boucle
				}
				else if (choixZ == 2) {
					cout << "vous entrez dans : " << zonesPossibles[1].getName() << endl;
					zonesPossibles[0].setLinked(false);
					chosen_way = 2;
					FinChoixZ = 1;
				}
				else {
					cout << "erreur d'entree, veuillez entrer un chiffre entre 1 et 2" << endl;
				}
			}
		}
	}
}


int main() {
	SetConsoleOutputCP(1252);

	Personnage p1("Anto", 200, 200, 100, false, 5, 0);

	Bourrin b1("Anto", 3, 20, 100, false, 5, 0);
	Romantique r1("Mathieu", 3, 15, 150, false, 5, 100);
	Beauf bof1("Giovan", 3, 20, 100, false, 5, 0);

	Enemy e1("Stefanie", 12, 110, false);
	Enemy e2("Gwendoline", 20, 80, false);
	Enemy e3("Patricia", 16, 100, false);


	system("cls"); //Clean

	//système de zone
	int choixZ = 0; // création de la variable de choix de zone
	int FinChoixZ = 0; // création de la variable de fin de boucle de choix de zone
	int chosen_way = 0;//creation de la variable de choix de zone pour initialiser la boucle de gameplay selon le choix

	Zone z1("Tord boyaux", 1, 1, 2, false);//creation d'une zone ("nom", id, Niveau, nombre de chemins suivants, lié au joueur ?)
	Zone z2("chupitos", 2, 1, 3, false);
	Zone z3("victoria", 3, 1, 1, false);
	Zone z4("Alhambra", 4, 2, 2, false);//cette zone est donc une zone dédiée à une potentielle suite du premier niveau car l'attribut niveau est à 2
	Zone z5("bockale", 5, 2, 1, false);

	//cout << z1 << endl;//affichage des infos de z1

	vector<Zone> zones;//creation d'un tableau avec des zones
	zones.push_back(z1);//ajout de la première zone dans le tableau
	zones.push_back(z2);
	zones.push_back(z3);
	zones.push_back(z4);


	vector<Zone> zonesPossibles;//creation de la liste qui n'aura que les zones accessibles

	Choix(p1, zones, zonesPossibles, chosen_way);//

	//BOUCLES DE JEU ---------------------------------------------------

	cout << "Vous rencontrez trois jolies humaines" << endl << endl;
	//Boucle de Combat
	srand(time(NULL));
	while (b1.getHealth() + r1.getHealth() + bof1.getHealth() > 0 && e1.getSeduction() + e2.getSeduction() + e3.getSeduction() > 0) {

		attackBourrin(b1, e1, e2, e3);

		attackRomantique(r1, e1, e2, e3);

		attackBeauf(bof1, e1, e2, e3);

		cout << "FIN DE TOUR JOUEUR" << endl << endl;

		attackenemy(b1, r1, bof1, e1);
		attackenemy(b1, r1, bof1, e2);
		attackenemy(b1, r1, bof1, e3);

		cout << endl << "FIN DE TOUR ENEMIE" << endl << endl;

	}

	if (b1.getHealth() + r1.getHealth() + bof1.getHealth() == 0)
	{
		cout << "Le groupe de fille que vous avez rencontrer, vous à laisser sur le carreaux! Vos egos viennent de prendre un coup." << endl;
	}

	if (e1.getSeduction() + e2.getSeduction() + e3.getSeduction() == 0)
	{
		cout << "Vous avez remporter votre première conquête." << endl;
	}

	cout << "depart du combat" << endl << endl;
}
