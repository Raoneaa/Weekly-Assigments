#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anime.h"

/*
 * fix not adding everything properly from initalizing the database
 * add priting if there is a match
 * finish the search database feature
 */


int main(int argc,char* argv[]) {
     // initialize the database, if error print out message, if not print out message
    Database* database = CreateDatabase();
    char array[100];

    printf("Enter search string: ");
    char searchString[100];
    fgets(searchString,100,stdin);
    int length = strlen(searchString);
    searchString[length] = '\0';

    printf("%s",searchString);
    printf("\n");
    SearchDatabase(database,searchString);
    FreeDatabase(database);
    return 0;
}
