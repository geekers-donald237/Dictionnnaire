//Made by MBIADA BAYON IDRIS DONALD 21Q2915
#include "fonction.h"
#include "table_hachage.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void load()
{
    char a;
    char chaine[161], *c;
    element e = NULL;
    FILE* dictio = NULL;

    dictio = fopen("dico.data", "r");
    if(dictio == NULL){
        printf("Le chargement du fichier dictionnaire a échoué ou alors il n'existe pas,\nle programme sera chargé mais ne contiendra aucun mot.\n");
        dictio = fopen("dico.data", "w+");
        fclose(dictio);
        a = getchar();
    }
    else
    {
        rewind(dictio);//ramene au debut du fichiers
        while(fgets(chaine, 160, dictio) != NULL)
        {
            e = newE();
            strcpy(e->value.m, strtok(chaine, "|"));
            strcpy(e->value.fr, strtok(NULL, "|"));
            strcpy(e->value.mean, strtok(NULL, "\n"));
            add_load(e);
        }
        fclose(dictio);
    }
}

void save()
{
    char a;
    FILE* dictio = NULL;
    dictio = fopen("dico.data", "w+");
    if(dictio == NULL){
        printf("L'enregistrement du fichier dictionnaire a échoué.\n");
        a = getchar();
    }
    else
    {
        for(int i = 0; i < 26; ++i)
        {
            for(element actual = dico->valeurs[i]; actual != NULL; actual = actual->next)
            {
                fprintf(dictio, "%s|%s|%s\n", actual->value.m, actual->value.fr, actual->value.mean);
            }
        }
    	fclose(dictio);
    }

}

void search_word()
{
    int rang;
	char *mot;
	element word;
	mot = malloc(30 * sizeof(char));
	system("clear");
	printf("\nEntrer le mot (en peuhl) : ");
	lect(mot);

    	rang = ranger(mot);
	word = search(rang, mot);
	if(word == NULL)
		printf("\nMot non trouvé !");
	else
		printf("\n\nMot : %s\n\nTraduction française : %s\n\nExplication : %s\n", word->value.m, word->value.fr, word->value.mean);

	printf("\nAppuyez pour continuer...");
}
void add()
{
	int rang;
	element prev, word;
	word = newE();

	system("clear");
    	printf("\n\t\t!!!VOUS POUVEZ AJOUTER UNE EXPLICATION AUX MOTS EXISTANTS!!!\n\n");
	printf("\nVous voulez ajouter un nouveau mot.\nEntrer le mot (en peuhl) : ");
	lect(word->value.m);
	printf("\nEntrer le mot en français : ");
	lect(word->value.fr);
	printf("\nEntrer l'explication du mot (en peuhl) : ");
	lect(word->value.mean);

	rang = ranger(word->value.m);
	prev = classer(rang, word->value.m);
	insert(rang, prev, word);

    printf("\nLe mot a bien été ajouté au dictionnaire !\n");
	printf("\nAppuyez pour continuer...");
}


void add_load(element e)
{
    int rang;
    element prev;
    rang = ranger(e->value.m);
    prev = classer(rang, e->value.m);
    insert(rang, prev, e);
}

void del_word()
{
	int rang;
	char* mot;
	mot = malloc(30 * sizeof(char));
	system("clear");
	printf("\nEntrer le mot (en peuhl) à supprimer : ");
	lect(mot);
    rang = ranger(mot);
	del(rang,mot);

	printf("\nAppuyez pour continuer...");
}



void lect(char* m)
{
    for (int i = 0; i < strlen(m); ++i)
        m[i] = 0;
    char a = getchar();
    while(a == '\n')
        a = getchar();
    int i;
    for (i = 0; a != '\n'; ++i)
    {
        m[i] = tolower(a);
        a = getchar();
    }
    m[i] = '\0';
}


int ranger(char* mot)
{   
    switch(mot[0])
    {
        case 'a': return 0; break;
        case 'b': return 1; break;
        case 'c': return 2; break;
        case 'd': return 3; break;
        case 'e': return 4; break;
        case 'f': return 5; break;
        case 'g': return 6; break;
        case 'h': return 7; break;
        case 'i': return 8; break;
        case 'j': return 9; break;
        case 'k': return 10; break;
        case 'l': return 11; break;
        case 'm': return 12; break;
        case 'n': return 13; break;
        case 'o': return 14; break;
        case 'p': return 15; break;
        case 'q': return 16; break;
        case 'r': return 17; break;
        case 's': return 18; break;
        case 't': return 19; break;
        case 'u': return 20; break;
        case 'v': return 21; break;
        case 'w': return 22; break;
        case 'x': return 23; break;
        case 'y': return 24; break;
        case 'z': return 25; break;
    }
}


int comp(char* m, char* n)
{
    int i = 0, M = strlen(m), N = strlen(n);

    while(i < M && i < N)
    {
    	if(m[i] < n[i])
    		return 0;//m vient avant n
    	if(m[i] > n[i])
    		return 1;//m vient apres n
    	if(m[i] == n[i])
    		i++;
    }
    if(i < M)
    	return 1;
    if(i < N)
    	return 0;
    if(i == M && M == N)
    	return 2;//les mots sont identiques
}



element classer(int r, char* mot)
{
	element actual;
	actual = dico->valeurs[r];
    if(actual == NULL)
        return NULL;
	while(comp(mot, actual->value.m) == 1 && actual->next != NULL)
		actual = actual->next;
	if(actual->next == NULL)
		return actual;
    if(comp(mot, actual->value.m) == 0)
        return actual->prev;
    if(comp(mot, actual->value.m) == 2){
        del(ranger(mot), mot);
        return actual->prev;
    }
}

//Made by MBIADA BAYON IDRIS DONALD 21Q2915

