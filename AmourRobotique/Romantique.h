#include "Personnage.h"


class Romantique : public Personnage
{
private:
	int sensibilite;

public:
	Romantique();
	Romantique(string n, int h, int f, int e, bool k, int s);

	int getSensibilite() const;
	void setSensibilite(int s);

	friend ostream& operator<<(ostream os, Romantique const& p);

};


