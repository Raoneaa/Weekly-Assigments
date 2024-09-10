#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anime.h"

#define LENGTH 12000 // a little bigger than the number of rows in the csv file

Database* CreateDatabase(){
    // opening the file and if its not able to open throw and error message
    FILE *file = fopen("anime.csv", "r");
    if(file == NULL){
        printf("Error loading file\n");
        return NULL;
    }

    // creating array for database struct
    Database* database = malloc(sizeof(Database));
    if (database == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // creating array for entries pointer using the database
    database->entriesPointer = malloc(LENGTH * sizeof(Entry));
    if (database->entriesPointer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        free(database);
        return NULL;
    }



    char buffer[LENGTH];
    fgets(buffer, LENGTH, file);



// fix to read each struct type and not leave the last couple blank
    int entryNum = 0; // entry counter as well as telling it where to allocate in the array
    while (fgets(buffer, LENGTH, file) != NULL ) {
        sscanf(buffer, "%d,%[^,],%[^,],%[^,],%lf,%d,%[^,],%[^,]", // scanning into the data then moving to next row
               &database->entriesPointer[entryNum].id,
               database->entriesPointer[entryNum].name,
               database->entriesPointer[entryNum].source,
               database->entriesPointer[entryNum].rating,
               &database->entriesPointer[entryNum].score, // i have a feeling this might be causing it but have yet to figure it out

               // these are being left black
               &database->entriesPointer[entryNum].scored_by,
               database->entriesPointer[entryNum].premiered,
               database->entriesPointer[entryNum].studio);

        ++entryNum; // adding to entry counter
    }


    printf("Database loaded\n");

    database->size = entryNum; // assigming the size struct to the number of entries

    fclose(file); // close file
    return database; // return the pointer
}


void SearchDatabase(Database* database, char* substring){
    int found = 0; // makes found false and if found then makes it true
    for(int i = 0; i < database->size;++i){
        char* search = strstr(database->entriesPointer[i].name, substring); // checks pointer to name struct and substring
        if(search){
            PrintEntry(database->entriesPointer+ i); // sends the pointer for the string that matches
            found = 1; // makes found true
        }
    }

    if(!found){ // if there are no matches are found it gives message
        printf("No matches found\n");
    }
}

void PrintEntry(Entry* entryPtr){
    printf("Entry %d\n", entryPtr->id);
    printf("Title: %s\n", entryPtr->name);
    printf("Source: %s\n", entryPtr->source);
    printf("Rating: %s\n", entryPtr->rating);
    printf("Score: %.2lf\n", entryPtr->score);
    printf("Scored By: %d\n", entryPtr->scored_by);
    printf("Premiered: %s\n", entryPtr->premiered);
    printf("Studio: %s\n", entryPtr->studio);
    printf("\n");
}

void FreeDatabase(Database* database){
    if (database != NULL) { // freeing the database array and entry array
        free(database->entriesPointer);
        free(database);
    }
}


