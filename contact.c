//
// Created by Yassir on 24-5-2026.
//

#include <stdio.h>
#include "contact.h"

#include <string.h>



int contact_toevoegen(Contact contacten[], int *aantalContacten, Contact contact) {
    if (*aantalContacten >= MAX_CONTACTS) {
        return 0;
    }

    snprintf(contacten[*aantalContacten].naam, sizeof(contacten[*aantalContacten].naam), "%s", contact.naam);
    snprintf(contacten[*aantalContacten].email, sizeof(contacten[*aantalContacten].email), "%s", contact.email);
    snprintf(contacten[*aantalContacten].telefoonNummer, sizeof(contacten[*aantalContacten].telefoonNummer), "%s", contact.telefoonNummer);
    (*aantalContacten)++;
    return 1;

}

void contactenTonen(Contact contacten[], int aantalContacten) {
    if (aantalContacten <= 0) {
        printf("Het telefoonboek is nog leeg.\n");
        return;
    }
    for (int i = 0; i < aantalContacten; i++) {
        printf("\nContact %d:\n", i+1);
        printf("Naam: %s\n", contacten[i].naam);
        printf("Email: %s\n", contacten[i].email);
        printf("Telefoonnummer: %s\n", contacten[i].telefoonNummer);
    }
}


int contact_updaten(Contact contacten[], int contactIndex, Contact contact) {
    snprintf(contacten[contactIndex].naam, sizeof(contacten[contactIndex].naam), "%s", contact.naam);
    snprintf(contacten[contactIndex].email, sizeof(contacten[contactIndex].email), "%s", contact.email);
    snprintf(contacten[contactIndex].telefoonNummer, sizeof(contacten[contactIndex].telefoonNummer), "%s", contact.telefoonNummer);

    return 1;
}

int contact_verwijderen(Contact contacten[], int *aantalContacten, int contactIndex) {
    if (*aantalContacten == 0) {
        // printf("Er zijn geen contacten om te verwijderen\n");
        return 0;
    }
    if (contactIndex < 0|| contactIndex > *aantalContacten-1) {
        // printf("Keuze bestaat niet\n");
        return -1;
    }

    for (int i = contactIndex; i < *aantalContacten-1; ++i) {
        contacten[i] = contacten[i+1];
    }

    (*aantalContacten)--;
    // printf("Contact Verwijderd!\n");
    return 1;
}