#include "Enemy.h"
#include "Personnage.h"

class Beauf : public Personnage
{
private:
	int lourdeur;

public:
	Beauf();
	Beauf(string n, int h, int f, int e, bool k, int l);

	int getLourdeur() const;
	void setLourdeur(int l);

	void disquetteBeaufL(Enemy& enemy);
	void disquetteBeaufM(Enemy& enemy);
	void disquetteBeaufXL(Enemy& enemy);

	friend ostream& operator<<(ostream& os, Beauf const& p);

};
