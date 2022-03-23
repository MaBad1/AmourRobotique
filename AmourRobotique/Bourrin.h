#include "Personnage.h"



class Bourrin : public Personnage
{
private:
	int forceur;


public:
	//constructeurs
	Bourrin();
	Bourrin(string n, int h, int f, int e, bool k, int x, int fo);

	//getter/setter
	int getForceur() const;
	void setForceur(int fo);

	//m�thode pour utiliser les objets dont l'utilisation d�pend de cette classe.
	void use(Objet o);

	friend ostream& operator<<(ostream& os, Bourrin const& p);

};

