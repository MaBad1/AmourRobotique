#include "Objet.h"

Objet::~Objet()
{
	cout << getName() << "utilisé !" << endl;
}

Objet::Objet()
{
	setName("Default");
	setBonus(5);
	setMalus(5);
	setDesc("Random item");
	setValeur(1);
}

Objet::Objet(string n, int b, int m, string d, int v)
{
	setName(n);
	setBonus(b);
	setMalus(m);
	setDesc(d);
	setValeur(v);
}

string Objet::getName() const
{
	return name;
}

void Objet::setName(string n)
{
	if (n.size() <= 0 || n.size() >= 20) {
		name = "Mauvaise taille";
	}
	else {
		name = n;
	}
}

int Objet::getBonus() const
{
	return bonus;
}

void Objet::setBonus(int b)
{
	if (b < 0 || b > 30)
	{
		bonus = 0;
		cout << "Bonus invalide !" << endl;
	}
	else {
		bonus = b;
	}
}

int Objet::getMalus() const
{
	return malus;
}

void Objet::setMalus(int m)
{
	if (m < 0 || m > 30)
	{
		malus = 0;
		cout << "Malus invalide !" << endl;
	}
	else {
		malus = m;
	}
}

string Objet::getDesc() const
{
	return description;
}

void Objet::setDesc(string d)
{
	if (d.size() <= 0 || d.size() >= 140) {
		description = "Mauvaise taille";
	}
	else {
		description = d;
	}
}

int Objet::getValeur() const
{
	return valeur;
}

void Objet::setValeur(int v)
{
	if (v < 1 || v > 6)
	{
		valeur = 1;
		cout << "Valeur incompatible !" << endl;
	}
	else {
		valeur = v;
	}
}
