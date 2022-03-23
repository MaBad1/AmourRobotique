#pragma once
#include <iostream>
#include <vector>
#include "Objet.h"

using namespace std;

class Personnage
{
private:

	string name;
	int health;//Nombre de revive
	int flirt;//L'attaque des adversaires
	int ego;//Barre de vie
	bool ko;//En Vie ou mort


public:
	//déclaration de l'inventaire en public pour pouvoir le modifier sans passer par getters/setters.
	vector<vector<int>> inventaire;

	//constructeurs.
	Personnage();

	Personnage(string n, int h, int f, int e, bool k, int x);

	//getters setters des attributs en privé.
	string getName() const;
	void setName(string n);

	int getHealth() const;
	void setHealth(int h);

	int getFlirt() const;
	void setFlirt(int f);

	int getEgo() const;
	void setEgo(int e);

	bool getKo() const;
	void setKo(bool k);

	//Setter de l'inventaire pour le créer aux dimenstions voulues.
	void setInv(int x);

	bool operator>(Personnage& target);

	bool operator<(Personnage& target);

	friend ostream& operator<<(ostream& os, Personnage const& p);

};

