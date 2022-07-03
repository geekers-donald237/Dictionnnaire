//Made by MBIADA BAYON IDRIS DONALD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_hachage.h"


#include "fonction.h"

element newE()
{
    element a;

    a = (element)malloc(sizeof(Element));
    a->next = NULL;
    a->prev = NULL;
    a->value.m = (char*)malloc(30 * sizeof(char));
    a->value.fr = (char*)malloc(30 * sizeof(char));
    a->value.mean = (char*)malloc(100 * sizeof(char)); 

    return a;
}

void initialize()
{
    dico = (hachtab*)malloc(sizeof(hachtab));
    dico->valeurs = (element*)malloc(26* sizeof(element));
    for (int i = 0; i < 26; ++i)
        dico->valeurs[i] = NULL;
}


void insert(int r, element prev, element mot)
{
    if(prev == NULL)
    {
        mot->next = NULL;
        mot->prev = NULL;
        dico->valeurs[r] = mot;
    }
    else
    {
        mot->next = prev->next;
        mot->prev = prev;
        if(prev->next != NULL)
            prev->next->prev = mot;
        prev->next = mot;
    }

}


element search(int r, char* mot)
{
    element actual;
    actual = dico->valeurs[r];

    if(actual == NULL)
        return NULL;
    while(strcmp(mot, actual->value.m) != 0 && actual->next != NULL)
        actual = actual->next;
    if(strcmp(mot, actual->value.m) != 0 && actual->next == NULL)
        return NULL;
    else
        return actual;
}


//Function for deleting an element in the hach table
void del(int r, char* mot)
{
    if(dico->valeurs[r] == NULL)
        printf("\nLe mot est introuvable !\n");
    else
    {
        element word;
        word = search(r, mot);
        if(word == NULL)
            printf("\nLe mot est introuvable !\n");
        else{
            if(word->prev != NULL)
                word->prev->next = word->next;
            else{
                dico->valeurs[r] = word->next;
                if(word->next != NULL)
                    word->next->prev = NULL;
            }
            
            if(word->next != NULL)
                word->next->prev = word->prev;
            else{
                if(word->prev != NULL)
                    word->prev->next = NULL;
            }
            printf("\nLe mot a bien été supprimé du dictionnaire !\n");
        }
    }
}


 