#include "Personnage.h"

Personnage::Personnage()
{
	setName("Bouffon");
	setHealth(50);
	setFlirt(20);
	setInv(5);

}

Personnage::Personnage(string n, int h, int f, int e, bool k, int x)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
	setInv(x);

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
	if (e < 0 || e > 100)
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


void Personnage::setInv(int x)
{
	for (int i = 0; i < x; i++) {
		inventaire.push_back(vector<int>(x));
		for (int j = 0; j < x; j++) {
			inventaire[i][j] = 0;
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
	os << "Health : " << p.getHealth() << endl;
	os << "Flirt : " << p.getFlirt() << endl;
	os << "Ego : " << p.getEgo() << endl;

	return os;

}
