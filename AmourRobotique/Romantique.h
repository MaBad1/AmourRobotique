#include "Personnage.h"
#include "Enemy.h"


class Romantique : public Personnage
{
private:
	int sensibilite;

public:
	//constructeurs
	Romantique();
	Romantique(string n, int h, int f, int e, bool k,int x, int s);

	//getters/setters.
	int getSensibilite() const;
	void setSensibilite(int s);

	void disquetteRomantiqueL(Enemy& enemy);
	void disquetteRomantiqueM(Enemy& enemy);
	void disquetteRomantiqueXL(Enemy& enemy);

	//méthode pour utiliser les objets dont l'utilisation dépend de cette classe.
	void use(Objet o);

	friend ostream& operator<<(ostream& os, Romantique const& p);

};


