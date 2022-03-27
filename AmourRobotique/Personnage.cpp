#include "Personnage.h"

Personnage::Personnage()
{
	setName("Bouffon");
	setHealth(50);
	setFlirt(20);
	setInv(5);
	setPlace(0);

}

Personnage::Personnage(string n, int h, int f, int e, bool k, int x, int p)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
	setInv(x);
	setPlace(p);

}

string Personnage::getName() const
{
	return name;
}

void Personnage::setName(string n)
{
	if (n.size() <= 0 || n.size() >= 20) {
		name = "Mauvaise taille";
	}
	else {
		name = n;
	}

}

int Personnage::getHealth() const
{
	return health;

}

void Personnage::setHealth(int h)
{
	if (h < 0 || h > 200)
	{
		health = 0;
		cout << "Unacceptable health !" << endl;
	}
	else {
		health = h;
	}
}

int Personnage::getFlirt() const
{
	return flirt;
}

void Personnage::setFlirt(int f)
{
	if (f < 0 || f > 200)
	{
		flirt = 0;
		cout << "Unacceptable flirt !" << endl;
	}
	else {
		flirt = f;
	}
}

int Personnage::getEgo() const
{
	return ego;
}

void Personnage::setEgo(int e)
{
	if (e < 0 || e > 200)
	{
		ego = 0;
		cout << "Unacceptable ego !" << endl;
	}
	else {
		ego = e;
	}
}

bool Personnage::getKo() const
{
	return ko;
}

void Personnage::setKo(bool k)
{
	ko = k;
}

int Personnage::getPlace() const
{
	return place;
}

void Personnage::setPlace(int p)
{
	place = p;
}

string Personnage::getRandomDisquette(int power)
{
	return Disquette[power][rand() % 3];
	
}


void Personnage::setInv(int x)
{
	for (int i = 0; i < x; i++) {
		inventaire.push_back(vector<int>(x));
		for (int j = 0; j < x; j++) {
			inventaire[i][j] = 0;
		}
	}
}

void Personnage::use(Objet o)
{
	for (int i = 0; i < inventaire.size(); i++) {
		for (int j = 0; j < inventaire[i].size(); j++) {
			//Si l'objet est trouvé on l'utilise.
			if (inventaire[i][j] == o.getValeur()) {
				cout << getName() << " ne peut pas utiliser cet objet" << endl;
				break;
			}
		}
	}
}


bool Personnage::operator>(Personnage& target)
{
	return getName().size() > target.getName().size();
}

bool Personnage::operator<(Personnage& target)
{
	return !(getName().size() > target.getName().size());

}

ostream& operator<<(ostream& os, Personnage const& p)
{
	os << "--- " << p.getName() << " ---" << endl;
	os << "Nombre de vie : " << p.getHealth() << endl;
	os << "Ego(Vie) : " << p.getEgo() << endl;
	os << "Flirt(Atk) : " << p.getFlirt() << endl;
	

	return os;

}
