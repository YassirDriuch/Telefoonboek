//
// Created by Yassir on 24-5-2026.
//

#include <stdio.h>
#include "contact.h"

void menu() {
    Contact contacten[MAX_CONTACTS];
    int aantalContacten = 0;
    int loop = 1;
    while (loop) {
        int keuze;

        printf("\n===== HOOFDMENU =====\n1. Contact Toevoegen\n2. Contacten Tonen\n3. Contact Aanpassen\n4. Contact Verwijderen\n9. Exit\nMaak je keuze: \n");

        scanf("%d", &keuze);
        getchar();

        switch (keuze) {
            case 1:
                contactToevoegen(contacten, &aantalContacten);
                break;
            case 2:
                contactenTonen(contacten, aantalContacten);
                break;
            case 3:
                contactUpdaten(contacten, aantalContacten);
                break;
            case 4:
                contactVerwijderen(contacten, &aantalContacten);
                break;
            case 9:
                printf("exit");
                loop = 0;
                break;
            default:
                printf("Ongeldige keuze\n");
        }
    }
}


int main(void) {
    printf("Telefoonboek by Yassir Driuch\nGeschreven als persoonlijke leeropdracht in C\n");
    menu();
    return 0;
}
