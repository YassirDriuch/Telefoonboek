#include <stdio.h>

#define MAX_CONTACTS 100

typedef struct {
    char naam[50];
    char email[80];
    char telefoonNummer[50];
}Contact;

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

void menu() {
    Contact contacten[MAX_CONTACTS];
    int aantalContacten = 0;
    int loop = 1;
    while (loop) {
        int keuze;

        printf("1. Contact Toevoegen\n2. Contacten Tonen\n9. Exit\nMaak je keuze: \n");

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
    printf("Hello, World!\n");
    menu();
    return 0;
}
