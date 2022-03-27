#include "Bourrin.h"

Bourrin::Bourrin()
{
	setForceur(50);
}

Bourrin::Bourrin(string n, int h, int f, int e, bool k,int x, int fo)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
	setInv(x);
	setForceur(fo);
}

int Bourrin::getForceur() const
{
	return forceur;
}

void Bourrin::setForceur(int fo)
{
	if (fo < 0 || fo > 50)
	{
		forceur = 0;
		cout << "Unacceptable Forcing !" << endl;
	}
	else {
		forceur = fo;
	}
}

void Bourrin::disquetteBourrinL(Enemy& enemy)
{
	if (getForceur() >= 100) {
		cout << "Frappe moi !" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setForceur(getForceur() + 8);

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

void Bourrin::disquetteBourrinM(Enemy& enemy)
{
	if (getForceur() >= 100) {
		cout << "Frappe moi !" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setForceur(getForceur() + 15);

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

void Bourrin::disquetteBourrinXL(Enemy& enemy)
{
	if (getForceur() >= 100) {
		cout << "Frappe moi !" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setForceur(getForceur() + 20);

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

void Bourrin::use(Objet o)
{
	for (int i = 0; i < inventaire.size(); i++) {
		for (int j = 0; j < inventaire[i].size(); j++) {
			if (inventaire[i][j] == o.getValeur()) {
				if (inventaire[i][j] == 5) {
					setEgo(getEgo() + o.getBonus());
					setForceur(getForceur() + o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " sort un fouet !" << endl;
					break;
				}
				else if (inventaire[i][j] == 6) {
					setFlirt(getFlirt() + o.getBonus());
					setForceur(getForceur() + o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " montre des menottes !" << endl;
					break;
				}
				else {
					cout << getName() << "ne peut pas utiliser cet objet" << endl;
					break;
				}
			}
		}
	}
}

ostream& operator<<(ostream& os, Bourrin const& p)
{
	os << "--- " << p.getName() << " ---" << endl;
	os << "Vie : " << p.getHealth() << endl;
	os << "Flirt : " << p.getFlirt() << endl;
	os << "Ego : " << p.getEgo() << endl;
	os << "Ko : " << (p.getKo() ? "Ko" : "Toujours debout") << endl;
	os << "Forceur : " << p.getForceur() << endl << endl;
	return os;
}
