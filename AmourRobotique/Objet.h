#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Objet
{
private :

	string name;
	int bonus;
	int malus;
	string description;
	int valeur; //La valeur corrspond ? l'ID de l'objet qui servira ? le stocker et l'utiliser dans l'inventaire.

public :

	~Objet(); //Destructeur

	Objet();

	Objet(string n, int b, int m, string d, int v);

	string getName() const;
	void setName(string n);

	int getBonus() const;
	void setBonus(int b);

	int getMalus() const;
	void setMalus(int m);

	string getDesc() const;
	void setDesc(string d);

	int getValeur() const;
	void setValeur(int v);
};

