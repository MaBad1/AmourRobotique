#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Enemy
{
private:

	string name;
	int rateau;//L'attaque des adversaires
	int seduction; //Barre de vie
	bool ko;//En Vie ou mort

public:

	vector<vector<int>> inventaire;

	Enemy();

	Enemy(string n, int r, int s, bool k);

	string getName() const;
	void setName(string n);

	int getRateau() const;
	void setRateau(int r);

	int getSeduction() const;
	void setSeduction(int s);

	bool getKo() const;
	void setKo(bool k);

	bool operator>(Enemy& target);

	bool operator<(Enemy& target);

	friend ostream& operator<<(ostream& os, Enemy const& p);




};

