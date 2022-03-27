#include "Romantique.h"

Romantique::Romantique()
{
	setSensibilite(100);
}

Romantique::Romantique(string n, int h, int f, int e, bool k, int x, int s)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
	setInv(x);
	setSensibilite(s);
	
	Disquette = { {"On devrait t'arrêter pour excès de beauté.",
		"Salu.j'ai pas mis le \"t\" parceque je veux le prendre avec toi.",
		"Depuis le 14 mars on peut sortir sans pass, mais moi je peux pas sortir sans toi."},
		{"Je viens de voir qu'on envoyait des avions de chasse en Ukraine, mais moi je veux pas que tu partes",
		"Ton nom c'est Google ? Parce que tu es tout ce que je recherche",
		"En vrai je te met un 9/10 car je suis le +1 qu'il te manque"},
		{"Excuse moi t'aurais pas l'heure ? Parce que depuis que je t'ai vu j'ai perdu la notion du temps.",
		"Il y a tellement de soleil dans tes yeux que je bronze quand tu me regardes",
		"J'ai besoin d'un bouche à bouche car je viens de me noyer dans ton regard."} };
}

int Romantique::getSensibilite() const
{
	return sensibilite;
}

void Romantique::setSensibilite(int s)
{
	if (s < 0 || s > 100)
	{
		sensibilite = 0;
		cout << "Unacceptable Sensibilite !" << endl;
	}
	else {
		sensibilite = s;
	}
}

void Romantique::disquetteRomantiqueL(Enemy& enemy)
{
	if (getSensibilite() <= 0) {
		cout << "La politesse, ras le cul, on baise ?" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setSensibilite(getSensibilite() - 8);

		srand(time(NULL));
		for (int i = 0; i < 3; i++) {
			//Le random pour creer "un poucentage" de chacal
			int SortAttaque;
			SortAttaque = (rand() % 100) + 1;

			if (SortAttaque < 90) {
				enemy.setSeduction(enemy.getSeduction() - (getFlirt() / 4));
				cout << "Réussis  ";
			}
			else {
				cout << "Loupé  ";
			}
		}
	}
}

void Romantique::disquetteRomantiqueM(Enemy& enemy)
{
	if (getSensibilite() <= 0) {
		cout << "La politesse, ras le cul, on baise ?" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setSensibilite(getSensibilite() - 15);

		srand(time(NULL));
		for (int i = 0; i < 3; i++) {
			//Le random pour creer "un poucentage" de chacal
			int SortAttaque;
			SortAttaque = (rand() % 100) + 1;

			if (SortAttaque < 80) {
				enemy.setSeduction(enemy.getSeduction() - (getFlirt() / 3));
				cout << "Réussis  ";
			}
			else {
				cout << "Loupé  ";
			}
		}
	}
}

void Romantique::disquetteRomantiqueXL(Enemy& enemy)
{
	if (getSensibilite() <= 0) {
		cout << "La politesse, ras le cul, on baise ?" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setSensibilite(getSensibilite() - 20);

		srand(time(NULL));
		for (int i = 0; i < 3; i++) {
			//Le random pour creer "un poucentage" de chacal
			int SortAttaque;
			SortAttaque = (rand() % 100) + 1;

			if (SortAttaque < 45) {
				enemy.setSeduction(enemy.getSeduction() - (getFlirt() / 2));
				cout << "Réussis  ";
			}
			else {
				cout << "Loupé  ";
			}
		}
	}
}

//Méthode pour utiliser les objets.
void Romantique::use(Objet o)
{
	//Navigation dans l'inventaire.
	for (int i = 0; i < inventaire.size(); i++) {
		for (int j = 0; j < inventaire[i].size(); j++) {
			//Si l'objet est trouvé on l'utilise.
			if (inventaire[i][j] == o.getValeur()) {
				//Si l'objet 1 est choisit par l'utilisateur on utilise celui ci.
				if (inventaire[i][j] == 1) {
					setFlirt(getFlirt() + o.getBonus());
					setEgo(getEgo() - o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " offre des fleurs !" << endl;
					break;
				}
				//Pareil pour l'objet 2.
				else if (inventaire[i][j] == 2) {
					setSensibilite(getSensibilite() + o.getBonus());
					setEgo(getEgo() - o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " offre une bague !" << endl;
					break;
				}
				//Si l'utilisateur choisit un autre objet cela ne fonctionne pas en raison des limitations de classe.
				else {
					cout << getName() << " ne peut pas utiliser cet objet" << endl;
					break;
				}			
			}
		}
	}
}


ostream& operator<<(ostream& os, Romantique const& p)
{
	//A modifier ??
	os << "--- " << p.getName() << " ---" << endl;
	os << "Vie : " << p.getHealth() << endl;
	os << "Flirt : " << p.getFlirt() << endl;
	os << "Ego : " << p.getEgo() << endl;
	os << "Ko : " << (p.getKo() ? "Ko" : "Toujours debout") << endl;
	os << "Sensibilite : " << p.getSensibilite() << endl << endl;

	return os;
}
