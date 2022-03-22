#include "Personnage.h"



class Bourrin : public Personnage
{
private:
	int forceur;


public:
	Bourrin();
	Bourrin(string n, int h, int f, int e, bool k, int fo);

	int getForceur() const;
	void setForceur(int fo);

	friend ostream& operator<<(ostream& os, Bourrin const& p);

};

