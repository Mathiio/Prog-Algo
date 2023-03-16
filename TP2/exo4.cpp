#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	if (size < 2) {
        return;
    }

	// split
	int pivot = toSort[size-1];
	
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

    for (int i = 0; i < size-1; i++) {
        if (toSort[i] <= pivot) {
            lowerArray[lowerSize++] = toSort[i];
        } else {
            greaterArray[greaterSize++] = toSort[i];
        }
    }
	
	// recursiv sort of lowerArray and greaterArray
    recursivQuickSort(lowerArray, lowerSize);
    recursivQuickSort(greaterArray, greaterSize);
    
	// merge
	int i = 0;
    for (int j = 0; j < lowerSize; j++) {
        toSort[i++] = lowerArray[j];
    }
    toSort[i++] = pivot;
    for (int j = 0; j < greaterSize; j++) {
        toSort[i++] = greaterArray[j];
    }
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
