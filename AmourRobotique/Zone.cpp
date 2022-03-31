#include "Zone.h"

Zone::Zone()
{
	setName("Artemisia");
	setZoneid(0);
	setNiveau(0);
	setChemins(3);
	setLinked(false);
}

Zone::Zone(string n, int z, int niv, int c, bool l)
{
	setName(n);
	setZoneid(z);
	setNiveau(niv);
	setChemins(c);
	setLinked(l);
}

string Zone::getName() const
{
	return name;
}

void Zone::setName(string n)
{
	if (n.size() <= 0 || n.size() >= 100) {
		name = "BadSize";
	}
	else {
		name = n;
	}
}

int Zone::getZoneid() const
{
	return zoneid;
}

void Zone::setZoneid(int z)
{
	zoneid = z;
}

int Zone::getChemins() const
{
	return chemins;
}

void Zone::setChemins(int c)
{
	chemins = c;
}

int Zone::getNiveau() const
{
	return niveau;
}

void Zone::setNiveau(int niv)
{
	niveau = niv;
}

bool Zone::getLinked() const
{
	return linked;
	
}

void Zone::setLinked(bool l)
{
	linked = l;
}



ostream& operator<<(ostream& os, Zone const& zo)
{
	os << "--- " << zo.getName() << " ---" << endl;
	os << "identifiant de la zone : " << zo.getZoneid() << endl;
	os << "niveau de zone actuel : " << zo.getNiveau() << endl;
	os << "nombre de chemins suivants  : " << zo.getChemins() << endl;
	os << "La zone est elle liee a votre zone actuelle ?  " << zo.getLinked() << endl;


	return os;

}
