#include <iostream>
#include <fstream>
#include <string.h>
#include "header.h"

using namespace std;

void parsen(ifstream &datei){
    int zaehler;
    enum zustand zustand;
    char zeichen;
    char puffer[100];
    char root[20];
    char child[20];


    for (zaehler=0;;) {
        datei.get(zeichen);
        if (datei.eof()) break;

        switch(zeichen) {
        case '<':
            zustand = isNothing;
            break;

        case '>':
            puffer[zaehler]='\0';
            strcpy(child,puffer);
            cout << child << endl;
            break;

        case ' ':
            if(zustand == isRoot){
                zustand = isChild;
                puffer[zaehler]='\0';
                strcpy(root,puffer);
                cout << root << " enthaelt die Tags: ";
            }
            else if(zustand == isChild){
                puffer[zaehler]='\0';
                strcpy(child,puffer);
                cout << child << ", ";
            }
            zaehler=0;
            break;

        case '!':

            for (int i = 0;i < 8;i++){
                datei.get(zeichen);
            }
            zustand = isRoot;
            break;

        case '\n':
            break;

        default:
            puffer[zaehler]=zeichen;
            zaehler++;
            break;
        }
    }
}
