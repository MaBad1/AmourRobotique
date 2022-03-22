#include "Romantique.h"

Romantique::Romantique()
{
	setSensibilite(50);
}

Romantique::Romantique(string n, int h, int f, int e, bool k, int s)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
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

ostream& operator<<(ostream os, Romantique const& p)
{
	os << "--- " << p.getName() << " ---" << endl;
	os << "Vie : " << p.getHealth() << endl;
	os << "Flirt : " << p.getFlirt() << endl;
	os << "Ego : " << p.getEgo() << endl;
	os << "Ko : " << (p.getKo() ? "Ko" : "Toujours debout") << endl;
	os << "Sensibilite : " << p.getSensibilite() << endl << endl;
	return os;
}
