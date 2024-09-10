#ifndef ANIME_H
#define ANIME_H

typedef struct Entry
{
    int id;
    char name[200];
    char source[25];
    char rating[25];
    double score;
    int scored_by;
    char premiered[25] ;
    char studio[50];

} Entry;

typedef struct Database
{
    Entry* entriesPointer;
    int size;
} Database;

//create a new database struct. The database should store a pointer to entriesPointer in memory. Use malloc to create space for entriesPointer.
//open the provided database csv file and create an entry in the database for each row, not including the header
Database* CreateDatabase();

//check through the database, print all entriesPointer with a name that contains substring. Use strstr for this, look it up yourself!
void SearchDatabase(Database* database, char* substring);

//Should print all info about entry
void PrintEntry(Entry* entryPtr);

//this should free the database entriesPointer, then free the database pointer itself
void FreeDatabase(Database* database);

#endif