//
// Created by Yassir on 26-5-2026.
//

#include <stdio.h>
#include <string.h>

#include "contact.h"
#include "gui.h"
void lees_regel(char buffer[], int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
};

void cli_contact_toevoegen(Contact contacten[], int aantalContacten) {
    Contact contact;

    printf("Naam: ");
    lees_regel(contact.naam, sizeof(contact.naam));

    printf("Email: ");
    lees_regel(contact.email, sizeof(contact.email));

    printf("Telefoonnummer: ");
    lees_regel(contact.telefoonNummer, sizeof(contact.telefoonNummer));

    int result = contact_toevoegen(contacten, &aantalContacten, contact);
    if (result == 0) {
        printf("\nTelefoonboek is vol!\n");
    } else {
        printf("Contact %s is succesvol opgeslagen op locatie %d", contacten[aantalContacten].naam, result);
    }
}

// void cli_contacten_tonen() {
//     contactenTonen();
// }

void cli_contact_updaten(Contact contacten[], int aantalContacten) {
    int keuze;

    contactenTonen(contacten, aantalContacten);
    printf("Selecteer een contact: [nummer]\n");
    scanf("%d", &keuze);
    getchar();

    if (keuze <= 0 || keuze > aantalContacten) {
        printf("Keuze bestaat niet");
    } else {
        Contact teUpdatenContact = contacten[keuze-1];

        printf("Huidige naam: \"%s\"\nVoer een nieuwe naam in:\n", teUpdatenContact.naam);
        lees_regel(teUpdatenContact.naam, sizeof(teUpdatenContact.naam));

        printf("Huidige email: \"%s\"\nVoer een nieuwe email in:\n", teUpdatenContact.email);
        lees_regel(teUpdatenContact.email, sizeof(teUpdatenContact.email));

        printf("Huidige telefoonnummer: \"%s\"\nVoer een nieuwe telefoonnummer in:\n", teUpdatenContact.telefoonNummer);
        lees_regel(teUpdatenContact.telefoonNummer, sizeof(teUpdatenContact.telefoonNummer));

        contact_updaten(contacten, keuze-1, teUpdatenContact);
        printf("Contact %s is opgeslagen.\n%d/100 Contacten\n", contacten[keuze-1].naam, aantalContacten);
    }
}

void cli_contact_verwijderen(Contact contacten[], int aantalContacten) {
    int keuze;

    contactenTonen(contacten, aantalContacten);
    printf("Selecteer een contact: [nummer]\n");
    scanf("%d", &keuze);
    getchar();

    int result = contact_verwijderen(contacten, &aantalContacten, keuze-1);

    if (result == 0) {
        printf("Er zijn geen contacten om te verwijderen!\n");
        return;
    }
    if (result == -1) {
        printf("Keuze bestaat niet.");
    }

    printf("Contact succesvol verwijderd");
}

void cli_menu() {
    Contact contacten[MAX_CONTACTS];
    int aantalContacten = 0;
    int loop = 1;
    while (loop) {
        int keuze;

        printf("\n===== HOOFDMENU =====\n1. Contact Toevoegen\n2. Contacten Tonen\n3. Contact Aanpassen\n4. Contact Verwijderen\n9. Terug\nMaak je keuze: \n");

        scanf("%d", &keuze);
        getchar();

        switch (keuze) {
            case 1:
                cli_contact_toevoegen(contacten, aantalContacten);
                break;
            case 2:
                contactenTonen(contacten, aantalContacten);
                break;
            case 3:
                cli_contact_updaten(contacten, aantalContacten);
                break;
            case 4:
                cli_contact_verwijderen(contacten, aantalContacten);
                break;
            case 9:
                loop = 0;
                break;
            default:
                printf("Ongeldige keuze\n");
        }
    }
}

void main_menu() {
    int loop = 1;
    while (loop) {
        int keuze;
        printf("\nHoe wil je gebruik maken van deze applicatie?\n1. GUI\n2. CLI\n\n0. Applicatie sluiten\n");
        scanf("%d", &keuze);
        getchar();

        switch (keuze) {
            case 1:
                gui_menu();
                break;
            case 2:
                cli_menu();
                break;
            case 9:
                loop = 0;
                break;
        }
    }
}