//
// Created by Yassir on 24-5-2026.
//

#include <stdio.h>
#include "contact.h"

#include <string.h>

void leesRegel(char buffer[], int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
};

void contactToevoegen(Contact contacten[], int *aantalContacten) {
    if (*aantalContacten >= MAX_CONTACTS) {
        printf("Telefoonboek is vol!");
        return;
    }
    Contact nieuwContact;

    printf("Naam: ");
    leesRegel(nieuwContact.naam, sizeof(nieuwContact.naam));

    printf("Email: ");
    leesRegel(nieuwContact.email, sizeof(nieuwContact.email));

    printf("Telefoonnummer: ");
    leesRegel(nieuwContact.telefoonNummer, sizeof(nieuwContact.telefoonNummer));


    contacten[*aantalContacten] = nieuwContact;
    (*aantalContacten)++;

    printf("Contact %s is opgeslagen.\n%d/100 Contacten\n", nieuwContact.naam, *aantalContacten);
};

void contactenTonen(Contact contacten[], int aantalContacten) {
    for (int i = 0; i < aantalContacten; i++) {
        printf("\nContact %d:\n", i+1);
        printf("Naam: %s\n", contacten[i].naam);
        printf("Email: %s\n", contacten[i].email);
        printf("Telefoonnummer: %s\n", contacten[i].telefoonNummer);
    }
}


void contactUpdaten(Contact contacten[], int aantalContacten) {
    int keuze;

    if (aantalContacten <= 0) {
        printf("Het telefoonboek is nog leeg.\nVoeg eerst een contact toe!");
        return;
    }
    contactenTonen(contacten, aantalContacten);
    printf("Selecteer een contact: [nummer]\n");
    scanf("%d", &keuze);
    getchar();

    if (keuze <= 0 || keuze > aantalContacten) {
        printf("Keuze bestaat niet");
    } else {
        Contact teUpdatenContact = contacten[keuze - 1];

        printf("Huidige naam: \"%s\"\nVoer een nieuwe naam in:\n", teUpdatenContact.naam);
        leesRegel(teUpdatenContact.naam, sizeof(teUpdatenContact.naam));

        printf("Huidige email: \"%s\"\nVoer een nieuwe email in:\n", teUpdatenContact.email);
        leesRegel(teUpdatenContact.email, sizeof(teUpdatenContact.email));

        printf("Huidige telefoonnummer: \"%s\"\nVoer een nieuwe telefoonnummer in:\n", teUpdatenContact.telefoonNummer);
        leesRegel(teUpdatenContact.telefoonNummer, sizeof(teUpdatenContact.telefoonNummer));

        contacten[keuze - 1] = teUpdatenContact;
        printf("Contact %s is opgeslagen.\n%d/100 Contacten\n", contacten[keuze-1].naam, aantalContacten);
    }
};

void contactVerwijderen(Contact contacten[], int *aantalContacten) {
    if (*aantalContacten == 0) {
        printf("Er zijn geen contacten om te verwijderen\n");
        return;
    }
    contactenTonen(contacten, *aantalContacten);

    int keuze;
    scanf("%d", &keuze);
    getchar();

    if (keuze < 1|| keuze > *aantalContacten) {
        printf("Keuze bestaat niet\n");
        return;
    }

    for (int i = keuze-1; i < *aantalContacten-1; ++i) {
        contacten[i] = contacten[i+1];
    }

    (*aantalContacten)--;
    printf("Contact Verwijderd!\n");
};