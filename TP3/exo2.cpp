#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */

void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
    // Initialise indice bas pour recherche binaire
    int low = 0;
    // Initialise indice haut pour recherche binaire
    int high = array.size() - 1;
    // Initialise indice milieu pour recherche binaire
    int mid = (low + high) / 2;
    // Initialise booléen -> true si élément recherché trouvé
    int found = 0;


    // Tant que low inférieur à taille totale tableau
    while (low <= high) {
        // Si élément au milieu est inférieur à l'élément recherché
        if (array[mid] < toSearch) {
            // Déplace indice bas pour ignorer moitié gauche
            low = mid + 1;
            // Si élément milieu égal à élément cherché
        } else if (array[mid] == toSearch) {
            // Définit indice min sur indice milieu actuel
            indexMin = mid;
            // Déplace indice haut pour ignorer moitié droite
            high = mid - 1;
            // Passe found à true car élément recherché trouvé
            found = 1;
            // Si élément milieu est supérieur à élément recherché
        } else {
            // Déplace indice haut pour ignorer moitié droite
            high = mid - 1;
        }
        // Réinitialise indice milieu
        mid = (low + high) / 2;
    }

    // Si pas résultat pour find
    if (!found) {
        // Passe indexMin et indexMax à -1
        indexMin = indexMax = -1;
        return;
    }

    // Recherche binaire pour indice max
    // Réinitialise tous les indices
    low = indexMin;
    high = array.size() - 1;
    mid = (low + high) / 2;

    // Tant que low inférieur à taille totale tableau
    while (low <= high) {
        // Si élément milieu est supérieur élément recherché
        if (array[mid] > toSearch) {
            // Déplace indice haut pour ignorer moitié droite
            high = mid - 1;
            // Si élément milieu est égal à élément recherché
        } else if (array[mid] == toSearch) {
            // Définit indice max sur indice milieu actuel
            indexMax = mid;
            // Déplace indice bas pour ignorer moitié gauche
            low = mid + 1;
            // Si élément milieu est supérieur à élément recherché
        } else {
            // Déplace indice bas pour ignorer moitié gauche
            low = mid + 1;
        }
        // Réinitialise indice milieu
        mid = (low + high) / 2;
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}