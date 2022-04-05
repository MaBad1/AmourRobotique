#include "Beauf.h"
#include "Romantique.h"
#include "Bourrin.h"
#include "Enemy.h"
#include<time.h>
#include "Zone.h"
#include <list>
#include <Windows.h>


//Fonction pour faire des jolies cleans monsieur
void Cleans()
{
	int h;
	
	cout << "Pour skip appuie sur 1" << endl;
	cin >> h;
	if (h == 1) 
	{
		system("cls"); //Clean
	}
}


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
		cout << "1.Objet   2.Disquettes" << endl ;
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
			Cleans();
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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBourrinL(e1);
						cout << endl << e1 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBourrinXL(e1);
						cout << endl << e1 << endl;
						Cleans();
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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBourrinL(e2);
						cout << endl << e2 << endl;
						Cleans();

					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBourrinXL(e2);
						cout << endl << e2 << endl;
						Cleans();

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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBourrinL(e3);
						cout << endl << e3 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBourrinXL(e3);
						cout << endl << e3 << endl;
						Cleans();
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
			Cleans();
		}

		if (choixObjet == 2)
		{
			cout << "Choix d'une cible :" << endl << "1." << e1.getName() << "   2." << e2.getName() << "   3." << e3.getName() << endl;
			cin >> cible; //ciblage de l'énemi
			if (cible == 1 && e1.getKo() == false)
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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteRomantiqueL(e1);
						cout << endl << e1 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteRomantiqueXL(e1);
						cout << endl << e1 << endl;
						Cleans();
					}
				}
			}
			else if(cible == 1 && e1.getKo() == true)
			{
				system("cls"); //Clean
				cout << "Choix d'une cible :" << endl << "   2." << e2.getName() << "   3." << e3.getName() << endl;
				cin >> cible; //ciblage de l'énemi
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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteRomantiqueL(e2);
						cout << endl << e2 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteRomantiqueXL(e2);
						cout << endl << e2 << endl;
						Cleans();
					}
				}

			}
			else if (cible == 2 && e2.getKo() == true)
			{
				system("cls"); //Clean
				cout << "Choix d'une cible :" << endl << "1." << e1.getName() << "   3." << e3.getName() << endl;
				cin >> cible; //ciblage de l'énemi
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
						cout << endl << e3 << endl;
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteRomantiqueL(e3);
						cout << endl << e3 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteRomantiqueXL(e3);
						cout << endl << e3 << endl;
						Cleans();
					}
				}

			}
			else if (cible == 3 && e3.getKo() == true)
			{
				system("cls"); //Clean
				cout << "Choix d'une cible :" << endl << "1." << e1.getName() << "   2." << e2.getName() << endl;
				cin >> cible; //ciblage de l'énemi
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
			Cleans();
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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBeaufL(e1);
						cout << endl << e1 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBeaufXL(e1);
						cout << endl << e1 << endl;
						Cleans();
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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBeaufL(e2);
						cout << endl << e2 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBeaufXL(e2);
						cout << endl << e2 << endl;
						Cleans();
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
						Cleans();
					}
					if (choixP == 2) {
//						cout << "ATTACK Moyenne" << endl;
						p.disquetteBeaufL(e3);
						cout << endl << e3 << endl;
						Cleans();
					}
					if (choixP == 3) {
//						cout << "ATTACK Forte" << endl;
						p.disquetteBeaufXL(e3);
						cout << endl << e3 << endl;
						Cleans();
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
					Cleans();

				}
				if (choixEnemie == 2) {
					cout << "ATTACK Moyenne" << endl;
					e.rateauL(p1);
					checkhealth(p1);
					cout << endl << p1 << endl;
					Cleans();
				}
				if (choixEnemie == 3) {

					cout << "ATTACK Forte" << endl;

					e.rateauXL(p1);
					checkhealth(p1);
					cout << endl << p1 << endl;
					Cleans();

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
					Cleans();
				}
				if (choixEnemie == 2) {
					cout << "ATTACK Moyenne" << endl;
					e.rateauL(p2);
					checkhealth(p2);
					cout << endl << p2 << endl;
					Cleans();
				}
				if (choixEnemie == 3) {
					cout << "ATTACK Forte" << endl;
					e.rateauXL(p2);
					checkhealth(p2);
					cout << endl << p2 << endl;
					Cleans();
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
					Cleans();

				}
				if (choixEnemie == 2) {
// 					cout << "ATTACK Moyenne" << endl;
					e.rateauL(p3);
					checkhealth(p3);

					cout << endl << p3 << endl;
					Cleans();

				}
				if (choixEnemie == 3) {
//					cout << "ATTACK Forte" << endl;
					e.rateauXL(p3);
					checkhealth(p3);

					cout << endl << p3 << endl;
					Cleans();

				}
			}
		}
	}
	else {
	cout << e.getName() << " n'est plus dans cette discution." << endl;
	}
}


void Choix(Personnage& personnage, vector<Zone> zones, vector<Zone> zonesPossibles, int& chosen_way, vector<Zone>&zoneOccupee){
	if (personnage.getPlace() == 0 ){//si la position du joueur 1 est de 0 (c'est à dire le spawn)

		int choixZ = 0; // création/réinitialisation à 0 de la variable de choix de zone
		int FinChoixZ = 0;// création/réinitialisation à 0 de la variable de fin de choix de zone pour sortir du while plus bas


		cout << "L'équipe :  " << personnage.getName() << " se trouve au départ" << endl << endl;

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
					chosen_way = 1;//le choix choisis est le numéro un , permet d'initialiser les boucles de jeu plus bas
					zoneOccupee.push_back(zonesPossibles[0]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(1);
					FinChoixZ = 1;//on sort de la boucle
				}
				else if (choixZ == 2) {
					cout << "vous entrez dans : " << zonesPossibles[1].getName() << endl;
					chosen_way = 2;
					zoneOccupee.push_back(zonesPossibles[1]);
					personnage.setPlace(1);
					FinChoixZ = 1;
				}
				else if (choixZ == 3) {
					cout << "vous entrez dans : " << zonesPossibles[2].getName() << endl;
					chosen_way = 3;
					zoneOccupee.push_back(zonesPossibles[2]);
					personnage.setPlace(1);
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
					chosen_way = 1;//le choix choisis est le numéro un , permet d'initialiser les boucles de jeu plus bas
					zoneOccupee.push_back(zonesPossibles[0]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(1);
					FinChoixZ = 1;//on sort de la boucle
				}
				else if (choixZ == 2) {
					cout << "vous entrez dans : " << zonesPossibles[1].getName() << endl;
					chosen_way = 2;
					zoneOccupee.push_back(zonesPossibles[1]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(1);
					FinChoixZ = 1;
				}
				else {
					cout << "erreur d'entree, veuillez entrer un chiffre entre 1 et 2" << endl;
				}
			}
		}
	}
}

void Choix2(Personnage& personnage, vector<Zone> zones, vector<Zone> zonesPossibles, int& chosen_way, vector<Zone>&zoneOccupee) {
	if (personnage.getPlace() == 1) {//si la position du joueur 1 est de 1 (c'est à dire la fin du niveau 1)

		int choixZ = 0; // création/réinitialisation à 0 de la variable de choix de zone
		int FinChoixZ = 0;// création/réinitialisation à 0 de la variable de fin de choix de zone pour sortir du while plus bas
		zonesPossibles.clear();




		cout << "L'équipe :  " << personnage.getName() << " se trouve au départ" << endl << endl;

		

		for (int i = 0; i < zones.size(); i++) {//recherche parmis chaque zone, qu'elle zone est accessible pour le joueur

			if (zoneOccupee[0].getZoneid() == 1) {
				if (zones[i].getNiveau() == 2 && zones[i].getZoneid() > 10 && zones[i].getZoneid() < 20) {//ici, on cherche chaque zone dont le niveau est 2 
					cout << zones[i].getName() << " est possible " << endl << endl;
					zones[i].setLinked(true);//sont accessibles
					zonesPossibles.push_back(zones[i]);//ajout de la zone dans une nouvelle liste qui ne contient que les zones possibles
				}
			}

			else if (zoneOccupee[0].getZoneid() == 2) {
				if (zones[i].getNiveau() == 2 && zones[i].getZoneid() > 20 && zones[i].getZoneid() < 30) {//ici, on cherche chaque zone dont le niveau est 2, et l'id correspondant à la zone précédente 
					cout << zones[i].getName() << " est possible " << endl << endl;//toutes les zones de niveau 1
					zones[i].setLinked(true);//sont accessibles
					zonesPossibles.push_back(zones[i]);//ajout de la zone dans une nouvelle liste qui ne contient que les zones possibles
				}
			}

		}
		zoneOccupee.clear();//on clear le tableau qui contien la zone occupée car on change de zone

		//cout << " taille de la liste : " << zonesPossibles.size() << endl;

		if (zonesPossibles.size() == 3) {//si il y a 3 zones différentes on vient ici

			while (FinChoixZ == 0) {

				cout << "Choisissez une des zones disponibles en écrivant un chiffre entre 1 et 3" << endl;
				cin >> choixZ;

				system("cls"); //Clean

				if (choixZ == 1) {//le joueur choisit la zone n°1
					cout << "Vous entrez dans : " << zonesPossibles[0].getName() << endl << endl;//on affiche le nom de la zone n°1 (!)attention(!) le premier élément d'une liste est toujours 0, le deuxième 1 etc...
					chosen_way = 1;//le choix choisis est le numéro un , permet d'initialiser les boucles de jeu plus bas
					zoneOccupee.push_back(zonesPossibles[0]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(2);
					FinChoixZ = 1;//on sort de la boucle
				}
				else if (choixZ == 2) {
					cout << "vous entrez dans : " << zonesPossibles[1].getName() << endl;
					chosen_way = 2;
					zoneOccupee.push_back(zonesPossibles[1]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(2);
					FinChoixZ = 1;
				}
				else if (choixZ == 3) {
					cout << "vous entrez dans : " << zonesPossibles[2].getName() << endl;
					chosen_way = 3;
					zoneOccupee.push_back(zonesPossibles[2]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(2);
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
					chosen_way = 1;//le choix choisis est le numéro un , permet d'initialiser les boucles de jeu plus bas
					zoneOccupee.push_back(zonesPossibles[0]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(2);
					FinChoixZ = 1;//on sort de la boucle
				}
				else if (choixZ == 2) {
					cout << "vous entrez dans : " << zonesPossibles[1].getName() << endl;
					chosen_way = 2;
					zoneOccupee.push_back(zonesPossibles[1]);//on met dans un tableau la zone où le joueur veut entrer.
					personnage.setPlace(2);
					FinChoixZ = 1;
				}
				else {
					cout << "erreur d'entree, veuillez entrer un chiffre entre 1 et 2" << endl;
				}
			}
		}
	}
}

void Choix3(Personnage& personnage, vector<Zone> zones, vector<Zone> zonesPossibles, int& chosen_way, vector<Zone>&zoneOccupee) {
	if (personnage.getPlace() == 2) {//si la position du joueur 1 est de 1 (c'est à dire la fin du niveau 1)

		int choixZ = 0; // création/réinitialisation à 0 de la variable de choix de zone
		int FinChoixZ = 0;// création/réinitialisation à 0 de la variable de fin de choix de zone pour sortir du while plus bas
		zonesPossibles.clear();




		cout << "L'équipe :  " << personnage.getName() << " se trouve au départ" << endl << endl;

		for (int j = 0; j < zones.size(); j++) {
			zones[j].setLinked(false);
		}

		for (int i = 0; i < zones.size(); i++) {//recherche parmis chaque zone, qu'elle zone est accessible pour le joueur
			if (zoneOccupee[0].getZoneid() == 1) {
				if (zones[i].getNiveau() == 2 || zones[i].getZoneid() > 10 || zones[i].getZoneid() < 20) {//ici, on cherche chaque zone dont le niveau est 2 
					cout << zones[i].getName() << " est possible " << endl << endl;//toutes les zones de niveau 1
					zones[i].setLinked(true);//sont accessibles
					zonesPossibles.push_back(zones[i]);//ajout de la zone dans une nouvelle liste qui ne contient que les zones possibles
				}
			}
			else if (zoneOccupee[0].getZoneid() == 2) {
				if (zones[i].getNiveau() == 2 || zones[i].getZoneid() > 20 || zones[i].getZoneid() < 30) {//ici, on cherche chaque zone dont le niveau est 2, et l'id correspondant à la zone précédente 
					cout << zones[i].getName() << " est possible " << endl << endl;//toutes les zones de niveau 1
					zones[i].setLinked(true);//sont accessibles
					zonesPossibles.push_back(zones[i]);//ajout de la zone dans une nouvelle liste qui ne contient que les zones possibles
				}
			}

		}
		zoneOccupee.clear();//on clear le tableau qui contien la zone occupée car on change de zone

		//cout << " taille de la liste : " << zonesPossibles.size() << endl;

		if (zonesPossibles.size() == 2) {//si il y a 2 zones différentes on vient ici

			while (FinChoixZ == 0) {

				cout << "Choisissez une des zones disponibles en écrivant un chiffre entre 1 et 2" << endl;
				cin >> choixZ;

				if (choixZ == 1) {//le joueur choisit la zone n°1
					cout << "Vous entrez dans : " << zonesPossibles[0].getName() << endl;//on affiche le nom de la zone n°1 (!)attention(!) le premier élément d'une liste est toujours 0, le deuxième 1 etc...
					zonesPossibles[1].setLinked(false);//on délink les autres zones car elles ne seront plus accessibles (pas besoin de comprendre ça je l'utilise pas pour l'instant)
					chosen_way = 1;//le choix choisis est le numéro un , permet d'initialiser les boucles de jeu plus bas
					zoneOccupee.push_back(zonesPossibles[0]);
					personnage.setPlace(3);
					FinChoixZ = 1;//on sort de la boucle
				}
				else if (choixZ == 2) {
					cout << "vous entrez dans : " << zonesPossibles[1].getName() << endl;
					zonesPossibles[0].setLinked(false);
					chosen_way = 2;
					zoneOccupee.push_back(zonesPossibles[1]);
					personnage.setPlace(3);
					FinChoixZ = 1;
				}
				else {
					cout << "erreur d'entree, veuillez entrer un chiffre entre 1 et 2" << endl;
				}
			}
		}
		else {
			cout << "Vous entrez dans : " << zonesPossibles[0].getName() << endl;
			chosen_way = 1;
			personnage.setPlace(3);
			FinChoixZ = 1;//on sort de la boucle
		}
	}
}

void choix4(Personnage& personnage, vector<Zone> zones, vector<Zone> zonesPossibles, int& chosen_way, vector<Zone>&zoneOccupee) {
	if (personnage.getPlace() == 3) {
		int choixZ = 0; // création/réinitialisation à 0 de la variable de choix de zone
		int FinChoixZ = 0;// création/réinitialisation à 0 de la variable de fin de choix de zone pour sortir du while plus bas
		zonesPossibles.clear();

		cout << "Appuyez sur 1 pour entrer dans la meilleur boite de nuit" << endl;

		while (choixZ != 1) {
			cin >> choixZ;
		}
		if (choixZ == 1) {
			cout << "vous entrez dans la meilleure boite de nuit, partez à la chasse" << endl;
			chosen_way = 1;
			personnage.setPlace(4);
		}

	}
}


void Boucle1(int chosen_way, Bourrin& b1, Beauf& bof1, Romantique& r1, Enemy& e1, Enemy& e2, Enemy& e3) {
	if (chosen_way == 1) { // si le joueur choisit la première zone 
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
	if (chosen_way == 2) { // si le joueur choisit la deuxième zone 
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
	else { // si le joueur choisit la troisième zone 
		cout << "Vous rencontrez trois jolies humaines" << endl << endl;
		
		cout << chosen_way << endl;
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

}


int main() {

	SetConsoleOutputCP(1252);

	Enemy e1("Stefanie", 12, 20, false);//valeur initiale des hp : 110
	Enemy e2("Gwendoline", 20, 20, false);//valeur initiale des hp : 80
	Enemy e3("Patricia", 16, 20, false);//valeur initiale des hp : 100
	Enemy e4("Stefanie", 12, 20, false);
	Enemy e5("Gwendoline", 20, 20, false);
	Enemy e6("Patricia", 16, 20, false);
	Enemy e7("Gwendoline", 20, 20, false);
	Enemy e8("Patricia", 16, 20, false);
	Enemy e9("Stefanie", 12, 20, false);
	Enemy e10("Gwendoline", 20, 20, false);
	Enemy e11("Patricia", 16, 20, false);
	Enemy e12("Stefanie", 12, 20, false);
	Enemy e13("Gwendoline", 20, 20, false);
	Enemy e14("Patricia", 16, 20, false);

	Personnage p1("Les bras Cassé", 200, 200, 100, false, 5, 0);

	Bourrin b1("Anto", 3, 20, 100, false, 5, 0);
	Romantique r1("Mathieu", 3, 15, 150, false, 5, 100);
	Beauf bof1("Giovan", 3, 20, 100, false, 5, 0);


	system("cls"); //Clean

	cout << "Jean-Kévin, toujours vierge, avait envie de tourner une page de sa vie ce soir. Benoît et moi allons tout faire pour l’aider à tremper le biscuit avant la levée du soleil…" << endl << endl;
	Cleans();

	cout << " Nous avions rendez vous devant le O’Tacos de notre ville afin de se remplir la panse mais également, faire le point sur le but de la soirée et la manière dont Benoît et moi allons tout faire pour mettre en avant notre cher Jean Kévin devant les demoiselles qu’on va aborder sous peu. " << endl << endl;
	Cleans();

	cout << "A moi de faire de mon mieux pour que ce puceau de Kev devienne un vrai mâle." << endl << endl;
	cout << "Allez, en avant, premier bar !" << endl << endl << endl;
	

	//système de zone
	int choixZ = 0; // création de la variable de choix de zone
	int FinChoixZ = 0; // création de la variable de fin de boucle de choix de zone
	int chosen_way = 0;//creation de la variable de choix de zone pour initialiser la boucle de gameplay selon le choix

	Zone z1("Tord boyaux", 1, 1, 2, false);//creation d'une zone ("nom", id, Niveau, nombre de chemins suivants, lié au joueur ?)
	Zone z2("chupitos", 2, 1, 3, false);
	Zone z3("victoria", 3, 1, 1, false);

	Zone z4("Antirouille", 11, 2, 2, false);//zone de niveau 2 liée au tord boyau car son id commence par un 1
	Zone z5("bockale", 12, 2, 1, false);//zone de niveau 2 liée au tord boyau car son id commence par un 1

	Zone z6("Temple Bar", 21, 2, 1, false);//zone de niveau 2 liée au chupitos car son id commence par un 2
	Zone z7("PMU", 22, 2, 1, false);//zone de niveau 2 liée au chupitos car son id commence par un 2

	Zone z8("Les 3 singes", 31, 2, 1, false);//zone de niveau 2 liée au victoria car son id commence par un 3
	Zone z9("Café Z", 32, 2, 1, false);//zone de niveau 2 liée au victoria car son id commence par un 3

	Zone z10("Le Panama", 111, 3, 1, false);//zone de niveau 3 liée a l'antirouille  car son id commence par un 11
	Zone z11("la taverne", 121, 3, 1, false);//zone de niveau 3 liée au bockale car son id commence par un 12

	Zone z12("Le Cargo", 200, 3, 1, false);//zone de niveau 3 liée au temple bar et au pmu car son id commence par un 2

	Zone z13("Le Rockstore", 300, 3, 1, false);//zone de niveau 3 liée aux 3 singes et au café z car son id commence par un 3

	Zone z14("Jungle night club", 4, 4, 1, false);//zone de niveau 4 liée à chaque zone de niveau 3 car zone finale 


	//cout << z1 << endl;//affichage des infos de z1

	vector<Zone> zones;//creation d'un tableau avec des zones
	zones.push_back(z1);//ajout de la première zone dans le tableau
	zones.push_back(z2);
	zones.push_back(z3);
	zones.push_back(z4);
	zones.push_back(z5);
	zones.push_back(z6);
	zones.push_back(z7);
	zones.push_back(z8);
	zones.push_back(z9);
	zones.push_back(z10);
	zones.push_back(z11);
	zones.push_back(z12);
	zones.push_back(z13);
	zones.push_back(z14);


	vector<Zone> zonesPossibles;//creation de la liste qui n'aura que les zones accessibles
	vector<Zone> zoneOccupee;

	Choix(p1, zones, zonesPossibles, chosen_way, zoneOccupee);//
	cout << p1.getPlace() << endl;
	cout << "test" << zoneOccupee[0].getZoneid() << endl;
	//BOUCLES DE JEU ---------------------------------------------------

	Boucle1(chosen_way, b1, bof1, r1, e1, e2, e3);

	Choix2(p1, zones, zonesPossibles, chosen_way, zoneOccupee);

}
