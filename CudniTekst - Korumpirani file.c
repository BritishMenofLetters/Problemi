#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int FileToBuffer(const char*, char**);

int main() {
    const char* file = "Test.txt";  // npr. 1 2 3 4
    char* buffer = NULL;

    FileToBuffer(file, &buffer);

    return 0;
}

int FileToBuffer(const char* file, char** buff) {
    int numBytes;
    /*
    char tekst[] = "1 2 3 4 5 6";

    FILE* fp = fopen(file, "w");      //Ukoliko se u datoteku upisuje preko fwrite
    fwrite(tekst, 1, sizeof(tekst), fp); //Upis stringa u datoteku
    fclose(fp);

    fp = fopen(file, "r");
    */

    //Zakomentirati sljedecu naredbu ukoliko se koristi prethodni komentirani kod
    FILE* fp = fopen(file, "r");	//Otvaranje datoteke za citanje

//  fp = fopen(file, "r");	        //Otvaranje datoteke za citanje kod koristenja fwrite (potrebno odkomentirati)

    if (fp == NULL) {
        puts("Greska pri otvaranju datoteke");
        return -1;	//Ukoliko je nemoguce doci do datoteke
    }

    fseek(fp, 0L, SEEK_END);	    //Postavaljanje pokazivaca na kraj datoteke
    numBytes = ftell(fp);		    //Ocitavanje velicine datoteke za buffer


    *buff = (char*)malloc(numBytes);	//Stvaranje buffera
    if (*buff == NULL) {
        puts("Greska pri stvaranje buffera");
        return -1;
    }

    fseek(fp, 0L, SEEK_SET);                     //Postavljanje pokazivaca na pocetak datoteke za buffer
    fread(*buff, sizeof(char), numBytes, fp);   //Upisivanje datoteke u buffer

    fclose(fp); //Zatvaranje datoteke

    return 0;
}