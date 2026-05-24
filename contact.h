//
// Created by Yassir on 24-5-2026.
//

#ifndef TELEFOONBOEK_CONTACT_H
#define TELEFOONBOEK_CONTACT_H

typedef struct {
    char naam[50];
    char email[80];
    char telefoonNummer[50];
}Contact;

void contactToevoegen(Contact contacten[], int *aantalContacten);
void contactenTonen(Contact contacten[], int aantalContacten);
void contactUpdaten(Contact contacten[], int aantalContacten);
void contactVerwijderen(Contact contacten[], int *aantalContacten);

#endif //TELEFOONBOEK_CONTACT_H
