//
// Created by Yassir on 24-5-2026.
//

#ifndef TELEFOONBOEK_CONTACT_H
#define TELEFOONBOEK_CONTACT_H
#define MAX_CONTACTS 100

typedef struct {
    char naam[50];
    char email[80];
    char telefoonNummer[50];
}Contact;

int contact_toevoegen(Contact contacten[], int *aantalContacten, Contact contact);
void contactenTonen(Contact contacten[], int aantalContacten);
int contact_updaten(Contact contacten[], int contactIndex, Contact contact);
int contact_verwijderen(Contact contacten[], int *aantalContacten, int contactIndex);

#endif //TELEFOONBOEK_CONTACT_H
