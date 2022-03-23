#include "Beauf.h"

Beauf::Beauf()
{
	setLourdeur(50);
}

Beauf::Beauf(string n, int h, int f, int e, bool k, int l)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
	setLourdeur(l);

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
	if (getLourdeur() == 100) {
		cout << "C'est l'histoire du mec qui bouffe le cul d'une pute !" << endl;	
	}
	else {
		setFlirt(getFlirt() - 50);
		int bonus = getLourdeur() + 5;
	}
}

void Beauf::disquetteBeaufM(Enemy& enemy)
{
	if (getLourdeur() == 100) {
		cout << "C'est l'histoire du mec qui bouffe le cul d'une pute !" << endl;
	}
	else {
		setLourdeur(getLourdeur() - 50);
		int bonus = getFlirt() + 25;
	}
}

void Beauf::disquetteBeaufXL(Enemy& enemy)
{
	if (getLourdeur() == 100) {
		cout << "C'est l'histoire du mec qui bouffe le cul d'une pute !" << endl;
	}
	else {
		setLourdeur(getLourdeur() - 50);
		int bonus = getFlirt() + 25;
	}
}

ostream& operator<<(ostream& os, Beauf const& p)
{
	os << "--- " << p.getName() << " ---" << endl;
	os << "Vie : " << p.getHealth() << endl;
	os << "Flirt : " << p.getFlirt() << endl;
	os << "Ego : " << p.getEgo() << endl;
	os << "Ko : " << (p.getKo() ? "Ko" : "Toujours debout") << endl;
	os << "Lourdeur : " << p.getLourdeur() << endl << endl;
	return os;

}

