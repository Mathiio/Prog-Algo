#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


int Heap::leftChild(int nodeIndex) {
	// Retourne l'indice de l'enfant gauche du noeud d'indice nodeIndex.
    return 2 * nodeIndex + 1;
}

int Heap::rightChild(int nodeIndex) {
	// Retourne l'indice de l'enfant droit du noeud d'indice nodeIndex.
    return 2 * nodeIndex + 2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// Initialiser i avec la taille du tas pour savoir ou insérer nvl valeur
	int i = heapSize;
	// On insère la nvl valeur à l'index i dans le tas
	this->get(i)=value;
	// Réorganise le tas en partant de i(taille du tas) jusqu'à la racine(indice 0) 
	// Effectue la boucle tant que la valeur de i est supérieure à celle de son parent
	while(i>0 && this->get(i)>this->get((i-1)/2)){
		// A chaque passage, la valeur de i est échangé avec celle de son parent
		swap(i,(i-1)/2);
		// Indice i mis à jour pour pointer vers le parent du nouvel indice i
		i=(i-1)/2;
	}
	// Boucle s'arrête quand chaque valeur d'un parent est supérieure ou égal à ses enfants.
}





void Heap::heapify(int heapSize, int nodeIndex)
{
	// Initialise i_max à nodeIndex, l'indice du nœud avec la valeur maximale
	int i_max = nodeIndex;
	// Calcule indices des enfants gauche et droit du nœud donné avec leftChild et rightChild.
	int leftChildIndex = leftChild(nodeIndex);
	int rightChildIndex = rightChild(nodeIndex);

	// Vérifie si indice enfant gauche est inférieur à la taille du tas
	// Vérifie si valeur enfant gauche est supérieure à valeur du nœud valeur maximale. 
	// Si c'est le cas, on met à jour i_max pour pointer sur l'enfant gauche.
	if (leftChildIndex < heapSize && this->get(leftChildIndex) > this->get(i_max)) {
		i_max = leftChildIndex;
	}

	// Vérifie si indice enfant droit est inférieur à la taille du tas
	// Vérifie si valeur enfant droit est supérieure à valeur du nœud valeur maximale. 
	// Si c'est le cas, on met à jour i_max pour pointer sur l'enfant droit.
	if (rightChildIndex < heapSize && this->get(rightChildIndex) > this->get(i_max)) {
		i_max = rightChildIndex;
	}

	// Si i_max différent de nodeIndex
	// Si un enfant a une valeur plus grande que noeud actuel
	if (i_max != nodeIndex) {
		// Echange des valeurs des nœuds correspondants
		swap(nodeIndex, i_max);
		// Appel fonction heapify récursivement sur indice i_max pour vérifier propriété de tas bien maintenue.
		heapify(heapSize, i_max);
	}
}

void Heap::buildHeap(Array& numbers)
{
    int n = numbers.size();

    // Insère chaque élément de la liste des nombres dans le tas
    for (int i = 0; i < n; i++) {
        insertHeapNode(i, numbers[i]);
    }

    // Réorganise les nœuds pour maintenir la propriété de tas
    // Part de indice n/2-1 (dernier nœud qui a enfants) puis remonte à racine.
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(n, i);
    }
}

void Heap::heapSort()
{
    int n = size();

    // Construit tas binaire avec objet Heap courant
    buildHeap(*this);

    // Trie éléments tas en échangeant racine avec dernier élément non trié, 
    // Appel heapify pour trier chaque éléments -> réorganise tas et maintient propriété tas. 
    for (int i = n - 1; i >= 0; i--) {
        swap(0, i);
        heapify(i, 0);
    }
}





int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
