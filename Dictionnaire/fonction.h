//Made by MBIADA BAYON IDRIS DONALD 21Q2915
#ifndef FONCTION_H
#define FONCTION_H

#include "table_hachage.h"

void load();
void save();
void search_word();//first int for the language, seconf for the requested action(traduction or explication) and the char for the word itself
void add();
void add_load(element);
void del_word();


void lect(char*);
int ranger(char*);
int comp(char*, char*);
element classer(int, char*);

//Made by MBIADA BAYON IDRIS DONALD 21Q2915

#endif

