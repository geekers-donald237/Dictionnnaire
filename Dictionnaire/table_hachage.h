//Made by MBIADA BAYON IDRIS DONALD 21Q2915
#ifndef TABLE_HACHAGE_H
#define TABLE_HACHAGE_H


/*definnition d'un mot*/
typedef struct mot{
	char 	*m;
	char 	*fr;
	char	*mean;
}mot;


typedef struct Element Element;
typedef Element* element;
struct Element
{
    mot 	value;
    element next;
    element prev;
};


//La table de hachage
typedef struct hachtab
{
	element *valeurs;
}hachtab;


hachtab* dico;

//Prototypes de fonctions de gestion de la table de hachage
element	newE();

void 	initialize();
void 	insert(int, element, element);
void 	del(int, char*);
element search(int, char*);


#endif
