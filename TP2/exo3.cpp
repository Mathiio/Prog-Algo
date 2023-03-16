#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	int n = toSort.size();

    // Parcourt le tableau
    for (int i = 0; i < n - 1; i++) {

        // Parcourir le tableau de 0 à n-i-1
        // La plus grande valeur se retrouvera à la fin
        for (int j = 0; j < n - i - 1; j++) {
            if (toSort[j] > toSort[j + 1]) {
                // Echanger toSort[j] et toSort[j+1]
                int temp = toSort[j];
                toSort[j] = toSort[j + 1];
                toSort[j + 1] = temp;
            }
        }
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
