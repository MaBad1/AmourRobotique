#include "Romantique.h"

Romantique::Romantique()
{
	setSensibilite(50);
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
	
}

int Romantique::getSensibilite() const
{
	return sensibilite;
}

void Romantique::setSensibilite(int s)
{
	if (s < 0 || s > 50)
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
