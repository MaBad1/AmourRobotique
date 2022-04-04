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
	Rateau = { {"J'ai le sida",
		"C'est pour compenser ta petite bite ?",
		"Je suis en r�alit� un homme"},
		{"Tu as l'air super sympa. Je suis s�re que mon copain t'adorerait. Viens je vais te le pr�senter !",
		"t'es comme un fr�re pour moi",
		"C'est la premi�re fois que je parle d'aussi pr�s avec quelqu'un depuis que j'ai eu mon herp�s"},
		{"Ca te d�range si on baise avec mon fr�re ?",
		"Ta bite m�rite pas mon cul",
		"Ouvre la fen�tre j'viens de l�cher une caisse"} };
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
	if (s < 0 || s > 150)
	{
		seduction = 0;
		cout << "Acceptable seduction !" << endl;
	}
	if (s == 0 || s < 0)
	{
		setKo(true);
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

string Enemy::getRandomRateau(int power)
{
	return Rateau[power][rand() % 3];
}

void Enemy::rateauL(Personnage& enemy)
{
	cout << getRandomRateau(0) << endl << endl;
	
	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		//Le random pour creer "un poucentage" de chacal
		int SortAttaque;
		SortAttaque = (rand() % 100) + 1;

		if (SortAttaque < 90) {
			enemy.setEgo(enemy.getEgo() - (getRateau() / 4));
			cout << "R�ussis  ";
		}
		else {
			cout << "Loup�  ";
		}
	}
}

void Enemy::rateauM(Personnage& enemy)
{
	cout << getRandomRateau(1) << endl << endl;

	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		//Le random pour creer "un poucentage" de chacal
		int SortAttaque;
		SortAttaque = (rand() % 100) + 1;

		if (SortAttaque < 80) {
			enemy.setEgo(enemy.getEgo() - (getRateau() / 3));
			cout << "R�ussis  ";
		}
		else {
			cout << "Loup�  ";
		}
	}
}

void Enemy::rateauXL(Personnage& enemy)
{
	cout << getRandomRateau(2) << endl << endl;

	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		//Le random pour creer "un poucentage" de chacal
		int SortAttaque;
		SortAttaque = (rand() % 100) + 1;

		if (SortAttaque < 45) {
			enemy.setEgo(enemy.getEgo() - (getRateau() / 2));
			cout << "R�ussis  ";
		}
		else {
			cout << "Loup�  ";
		}
	}
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
