#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;


// Recherche binaire sur tableau pour trouver l'indice de l'élément toSearch
int binarySearch(Array& array, int toSearch){
  // Initialise start et end -> intervalle de recherche
  // Initialise mid -> milieu intervalle 
  // Initialise Index à -1 -> signifie élément toSearch pas trouvé dans array.
  int start = 0;
  int end = array.size();
  int mid, Index = -1;

  // Fait recherche tant que intervalle recherche n'est pas vide
  while (start < end) {
    // Calcule indice élément du milieu intervalle.
    mid = (start + end) / 2;
    // Si valeur toSearch est supérieur à valeur élément du milieu intervalle. 
    if (toSearch > array[mid]) {
      // Met à jour indice start pour exclure moitié gauche intervalle
      start = mid + 1;
      // Si valeur toSearch est inférieure à valeur nv milieu intervalle
    } else if (toSearch < array[mid]) {
      // Met à jour indice end pour exclure moitié droite intervalle
      end = mid;
      // Si valeur toSearch égal à valeur milieu intervalle 
    } else {
      // Assigne à Index valeur milieu intervalle et sort de boucle.
      Index = mid;
      break;
    }
  }

  return Index;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchWindow(binarySearch);
	w->show();

	return a.exec();
}
