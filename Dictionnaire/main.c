//Made by MBIADA BAYON IDRIS DONALD 21Q2915
#include "fonction.h"
#include "table_hachage.h"
#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>


int main()
{
	int c, quit = 0;
    char mot[30];

    hachtab* dico;
    initialize(dico);

    load();


    while(!quit)
    {
    	system("clear");
	    printf("---------->DICTIONNAIRE PEUHL -- FRANÇAIS<------------\n\nCeci est un dictionnaire qui donne la signification d'un mot peuhl\nainsi qu'une traduction approchée en française.");
	    printf("\n\n_________OPTIONS_________\n1.\tExplication/traduction\n2.\tAjout de mot  (Veuillez d'abord à supprimer les informations d'un mot existant avant de les changer.)\n3.\tSuppression de mot\n0.\tQuitter\n\nVotre choix...");
	    scanf("%d", &c);
		FILE*f = fopen("dico.data","rt");
		char e;
		while((c = fgetc(f)) != EOF){
			printf("%c",e);
		}
		fclose(f);
	    switch(c){
	    	case 1 : search_word();
	    	break;
	    	case 2 : add();
	    	break;
	    	case 3 : del_word();
	    	break;
	    	case 0 : quit = 1;
	    	break;
	    	default : printf("\nEntrer une option valide...\n");
	    	c = getchar();
	    	c = getchar();
	    	break;
	    }
	    c = getchar();

	}
	system("clear");
	save();

    return 0;
}


//Made by MBIADA BAYON IDRIS DONALD 21Q2915
