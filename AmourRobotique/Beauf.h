#include "Enemy.h"
#include "Personnage.h"

class Beauf : public Personnage
{
private:
	int lourdeur;

public:
	//constructeurs
	Beauf();
	Beauf(string n, int h, int f, int e, bool k, int x, int l);

	//Getter/setter
	int getLourdeur() const;
	void setLourdeur(int l);

	void disquetteBeaufL(Enemy& enemy);
	void disquetteBeaufM(Enemy& enemy);
	void disquetteBeaufXL(Enemy& enemy);

	//méthode pour utiliser les objets dont l'utilisation dépend de cette classe.
	void use(Objet o);


	friend ostream& operator<<(ostream& os, Beauf const& p);

};
