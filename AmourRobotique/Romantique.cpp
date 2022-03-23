#include "Romantique.h"

Romantique::Romantique()
{
	setSensibilite(50);
}

Romantique::Romantique(string n, int h, int f, int e, bool k, int x, int s)
{
	setName(n);
	setHealth(h);
	setFlirt(f);
	setEgo(e);
	setKo(k);
	setInv(x);
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

//Méthode pour utiliser les objets.
void Romantique::use(Objet o)
{
	//Navigation dans l'inventaire.
	for (int i = 0; i < inventaire.size(); i++) {
		for (int j = 0; j < inventaire[i].size(); j++) {
			//Si l'objet est trouvé on l'utilise.
			if (inventaire[i][j] == o.getValeur()) {
				//Si l'objet 1 est choisit par l'utilisateur on utilise celui ci.
				if (inventaire[i][j] == 1) {
					setFlirt(getFlirt() + o.getBonus());
					setEgo(getEgo() - o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " offre des fleurs !" << endl;
					break;
				}
				//Pareil pour l'objet 2.
				else if (inventaire[i][j] == 2) {
					setSensibilite(getSensibilite() + o.getBonus());
					setEgo(getEgo() - o.getMalus());
					inventaire[i][j] = 0;
					cout << getName() << " offre une bague !" << endl;
					break;
				}
				//Si l'utilisateur choisit un autre objet cela ne fonctionne pas en raison des limitations de classe.
				else {
					cout << getName() << " ne peut pas utiliser cet objet" << endl;
					break;
				}			
			}
		}
	}
}


ostream& operator<<(ostream& os, Romantique const& p)
{
	os << "--- " << p.getName() << " ---" << endl;
	os << "Vie : " << p.getHealth() << endl;
	os << "Flirt : " << p.getFlirt() << endl;
	os << "Ego : " << p.getEgo() << endl;
	os << "Ko : " << (p.getKo() ? "Ko" : "Toujours debout") << endl;
	os << "Sensibilite : " << p.getSensibilite() << endl << endl;

	return os;
}
