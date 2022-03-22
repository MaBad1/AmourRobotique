#pragma once
#include <iostream>
#include <vector>
#include "Objet.h"

using namespace std;

class Personnage
{
private:

	string name;
	int health;
	int flirt;
	int ego;
	bool ko;


public:

	vector<vector<int>> inventaire;

	Personnage();

	Personnage(string n, int h, int f, int e, bool k, int x);

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

	void setInv(int x);

	bool operator>(Personnage& target);

	bool operator<(Personnage& target);

	friend ostream& operator<<(ostream& os, Personnage const& p);

};

