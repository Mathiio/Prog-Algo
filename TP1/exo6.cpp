#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    int* donnees;
    int capacite;
    int count;
};


void initialise(Liste* liste)
{
    liste->premier=nullptr;
}


bool est_vide(const Liste* liste)
{
   return liste == NULL;
}


void ajoute(Liste* liste, int valeur)
{
    Noeud *newliste = new Noeud();
    newliste->donnee = valeur;
    newliste->suivant = nullptr;

    Noeud *current = liste->premier;

    if(current == nullptr){
        liste->premier = newliste;
    }
    else{
        while(current->suivant != nullptr){ 
            current = current->suivant;
        }
        current->suivant = newliste;
    }
}


void affiche(const Liste* liste)
{
    Noeud *current = liste->premier;
    while (current != nullptr){
        cout << current->donnee << endl;
        current = current->suivant;
    }
}


int recupere(const Liste* liste, int n)
{
    Noeud *current = liste->premier;
    int i=0;
    if(est_vide(liste)){
        cout << "La liste est vide !" << endl;
    }
    while(i<n){
        i++;
        current=current->suivant;
    }
    return current->donnee;
}


int cherche(const Liste* liste, int valeur)
{
    Noeud *current = liste->premier;
    int pos=1;
    if(est_vide(liste)){
        cout << "La liste est vide !" << endl;
    }
    while(!(valeur==current->donnee)){
        current=current->suivant;
        pos++;
    }
    return pos;
}


void stocke(Liste* liste, int n, int valeur)
{
    Noeud *current = liste->premier;
    int i=1;
    if(est_vide(liste)){
        cout << "La liste est vide !" << endl;
    }
    while(i<n){
        i++;
        current=current->suivant;
    }
    current->donnee= valeur;
}


void ajoute(DynaTableau* tableau, int valeur)
{
    // Si le tableau est vide, allouez de la mémoire pour un élément.
    if (tableau->donnees == NULL) {
        tableau->donnees = (int*) malloc(sizeof(int));
        tableau->capacite = 1;
    }
    // Si le tableau est plein, allouez de la mémoire pour deux fois la capacité actuelle.
    else if (tableau->count == tableau->capacite) {
        tableau->capacite *= 2;
        tableau->donnees = (int*) realloc(tableau->donnees, tableau->capacite * sizeof(int));
    }
    // Ajoutez la nouvelle valeur à la fin du tableau.
    tableau->donnees[tableau->count] = valeur;
    tableau->count++;
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->capacite = capacite;
    tableau->donnees = (int*) malloc(capacite*sizeof(int));
    tableau->count = 0;
}


bool est_vide(const DynaTableau* liste)
{
    if (liste->donnees == NULL) {
        return 1; 
    } else {
        return 0; 
    }
}


void affiche(DynaTableau* tableau)
{
    if (est_vide(tableau)) {
        cout << "Le tableau est vide !" << endl;
    }
    int counter =0;
    for (int i = 0; i < tableau->capacite; i++) {
         cout <<tableau->donnees[i] << endl;
         counter++;
    }
    tableau->count = counter;
}


int recupere(const DynaTableau* tableau, int n)
{
    int i=0;
    if(est_vide(tableau)){
        cout << "Le tableau est vide !" << endl;
    }
    while(i<n){
        i++;
    }
    return tableau->donnees[i];
}


int cherche(const DynaTableau* tableau, int valeur)
{
    int pos=0;
    if(est_vide(tableau)){
        cout << "Le tableau est vide !" << endl;
    }
    while(!(valeur==tableau->donnees[pos])){
        pos++;
    }
    pos++;
    return pos;
}


void stocke(DynaTableau* tableau, int n, int valeur)
{
    int i=0;
    if(est_vide(tableau)){
        cout << "Le tableau est vide !" << endl;
    }
    while(i<(n-1)){
        i++;
    }
    tableau->donnees[i]=valeur;
}


//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    // Noeud *current = liste->premier;
    // if(est_vide(liste)){
    //     cout << "La liste est vide !" << endl;
    // }
    // liste->premier = liste->premier->suivant;
    // free(current);
    return 0;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{

}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    return 0;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans le tableau à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}


