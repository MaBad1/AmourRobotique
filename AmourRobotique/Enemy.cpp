#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(string n, int r, int s, bool k)
{
	setName(n);
	setRateau(r);
	setSeduction(s);
	setKo(k);
}


string Enemy::getName() const
{
	return name;
}
//Si le nom de mon Enemy est inf�rieur/�gale a 0 ou sup�rieur/�gale a 20
//La console nous affiche Mauvaise Taille
//Si il est entre 1 et 19 �crit le nom donn�
void Enemy::setName(string n)
{
	if (n.size() <= 0 || n.size() >= 20) {
		name = "Mauvaise taille";
	}
	else {
		name = n;
	}
}


int Enemy::getRateau() const
{
	return rateau;
}

//On r�cup�re l'attaque de notre Enemy
//Si celle-ci n'est pas comprise entre 0 et 30, elle est affich� !
void Enemy::setRateau(int r)
{
	if (r < 0 || r > 30)
	{
		rateau = 10;
		cout << "Unacceptable ego !" << endl;
	}
	else {
		rateau = r;
	}
}



int Enemy::getSeduction() const
{
	return seduction;
}
//On r�cup�re la vie de notre Enemy
//Si celle-ci n'est pas comprise entre 0 et 150, elle est affich� !
void Enemy::setSeduction(int s)
{
	if (s < 0 || s > 150)
	{
		seduction = 80;
		cout << "Unacceptable seduction !" << endl;
	}
	else {
		seduction = s;
	}
}

bool Enemy::getKo() const
{
	return ko;
}

void Enemy::setKo(bool k)
{
	ko = k;
}

bool Enemy::operator>(Enemy& target)
{
	return false;
}

bool Enemy::operator<(Enemy& target)
{
	return false;
}

ostream& operator<<(ostream& os, Enemy const& p)
{
	os << "--- " << p.getName() << " ---" << endl;
	os << "S�duction(vie) : " << p.getSeduction() << endl;
	os << "Rateau(Atk) : " << p.getRateau() << endl;

	return os;
}
