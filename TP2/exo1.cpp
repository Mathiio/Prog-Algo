#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
	int n = toSort.size();
    int i, j, min_idx;

    // parcourt du tableau
    for (i = 0; i < n-1; i++) {
        // élément minimum dans le tableau pas trié
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (toSort[j] < toSort[min_idx])
                min_idx = j;

        // Échange élément minimum trouvé avec premier élément du tableau pas trié
        int temp = toSort[min_idx];
        toSort[min_idx] = toSort[i];
        toSort[i] = temp;
    }
}



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}
