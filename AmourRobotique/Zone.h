#pragma once
#include <iostream>

using namespace std;

class Zone
{
private:
	string name;
	int zoneid;
	int niveau;
	int chemins;
	bool linked;


public:

	/*Constructeurs*/

	Zone();
	Zone(string n, int z, int niv, int c, bool l);

	/*Getters / setters */
	string getName() const;
	void setName(string n);

	int getZoneid() const;
	void setZoneid(int z);

	int getNiveau() const;
	void setNiveau(int niv);

	int getChemins() const;
	void setChemins(int c);

	bool getLinked() const;
	void setLinked(bool l);

	friend ostream& operator<<(ostream& os, Zone const& zo);

};

