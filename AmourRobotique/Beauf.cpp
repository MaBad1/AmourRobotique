#include "Beauf.h"

Beauf::Beauf()
{
	setLourdeur(100);
}

Beauf::Beauf(string n, int h, int f, int e, bool k,int x, int l)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
	setInv(x);
	setLourdeur(l);

	Disquette = {{"Contrairement à ma bagnole, toi t'as pas besoin de phare pour briller",
		"Ton cul est tellement beau que c’est une honte que tu doives t’assoir dessus.",
		"Je suis pas basketeur pourtant je pourrais bien mettre la main au panier"},
		{"Ton père est un voleur, il a volé toutes les autoroutes de France pour les mettre dans ta chatte.",
		"Si ta jambe droite c'est Noël et ta jambe gauche le 31 décembre j'me taperais bien une bouffe entre les fêtes",
		"C'est pas parce qu'il y a un gardien qu'on ne peut pas marquer de but."},
		{"Tes yeux sont si profond que je peux voir l'intérieur de ta chatte",
		"Elles sont jolies tes dents elle ferait un beau collier au tour de ma bite",
		"Les mauvaises langues parlent, les bonnes donnent des orgames."} };
}

int Beauf::getLourdeur() const
{
	return lourdeur;
}

void Beauf::setLourdeur(int l)
{
	if (l < 0 || l > 100)
	{
		lourdeur = 0;
		cout << "Unacceptable Lourding !" << endl;
	}
	else {
		lourdeur = l;
	}
}

void Beauf::disquetteBeaufL(Enemy& enemy)
{
	if (getLourdeur() >= 100) {
		cout << "Je t'aime.. Oops" << endl;	
	}
	else {
		//Incrémentation de la lourdeur
		setLourdeur(getLourdeur() + 8);

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

void Beauf::disquetteBeaufM(Enemy& enemy)
{
	if (getLourdeur() >= 100) {
		cout << "Je t'aime.. Oops" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setLourdeur(getLourdeur() + 15);

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

void Beauf::disquetteBeaufXL(Enemy& enemy)
{
	if (getLourdeur() >= 100) {
		cout << "Je t'aime.. Oops" << endl;
	}
	else {
		//Incrémentation de la lourdeur
		setLourdeur(getLourdeur() + 20);

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

void Beauf::use(Objet o)
{
	for (int i = 0; i < inventaire.size(); i++) {
		for (int j = 0; j < inventaire[i].size(); j++) {
			if (inventaire[i][j] == o.getValeur()) {
				if (inventaire[i][j] == 3) {
					setEgo(getEgo() + o.getBonus());
					setLourdeur(getLourdeur() + o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " montre une capote !" << endl;
					break;
				}
				else if (inventaire[i][j] == 4) {
					setFlirt(getFlirt() + o.getBonus());
					setLourdeur(getLourdeur() + o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " montre une video de Bigard !" << endl;
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

ostream& operator<<(ostream& os, Beauf const& p)
{
	//A modifier ??
	os << "--- " << p.getName() << " ---" << endl;
	os << "Vie : " << p.getHealth() << endl;
	os << "Flirt : " << p.getFlirt() << endl;
	os << "Ego : " << p.getEgo() << endl;
	os << "Ko : " << (p.getKo() ? "Ko" : "Toujours debout") << endl;
	os << "Lourdeur : " << p.getLourdeur() << endl << endl;
	return os;

}

