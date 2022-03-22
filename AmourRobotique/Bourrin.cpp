#include "Bourrin.h"

Bourrin::Bourrin()
{
	setForceur(50);
}

Bourrin::Bourrin(string n, int h, int f, int e, bool k, int fo)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
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
