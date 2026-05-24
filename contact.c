//
// Created by Yassir on 24-5-2026.
//

#include <stdio.h>
#include "contact.h"

void contactToevoegen(Contact contacten[], int *aantalContacten) {
    int loop = 1;
    Contact nieuwContact;
    while (loop) {
        printf("Naam: ");
        scanf("%s", nieuwContact.naam);
        getchar();
        printf("Email: ");
        scanf("%s", nieuwContact.email);
        getchar();
        printf("Telefoonnummer: ");
        scanf("%s", nieuwContact.telefoonNummer);
        getchar();
        loop = 0;
    }


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
    contactenTonen(contacten, aantalContacten);
    printf("Selecteer een contact: [nummer]\n");
    int keuze;
    scanf("%d", &keuze);
    getchar();

    if (keuze > aantalContacten) {
        printf("Keuze bestaat niet");
    } else {
        Contact teUpdatenContact = contacten[keuze - 1];
        printf("Huidige naam: \"%s\"\nVoer een nieuwe naam in:\n", teUpdatenContact.naam);
        scanf("%s", teUpdatenContact.naam);
        getchar();
        printf("Huidige email: \"%s\"\nVoer een nieuwe email in:\n", teUpdatenContact.email);
        scanf("%s", teUpdatenContact.email);
        getchar();
        printf("Huidige telefoonnummer: \"%s\"\nVoer een nieuwe telefoonnummer in:\n", teUpdatenContact.naam);
        scanf("%s", teUpdatenContact.telefoonNummer);
        getchar();
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