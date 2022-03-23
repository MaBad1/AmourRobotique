#include "Personnage.h"

class Beauf : public Personnage
{
private:
	int lourdeur;

public:
	//constructeurs
	Beauf();
	Beauf(string n, int h, int f, int e, bool k,int x, int l);

	//Getter/setter
	int getLourdeur() const;
	void setLourdeur(int l);

	//m�thode pour utiliser les objets dont l'utilisation d�pend de cette classe.
	void use(Objet o);

	void disquetteBeauf();

	friend ostream& operator<<(ostream& os, Beauf const& p);

};
