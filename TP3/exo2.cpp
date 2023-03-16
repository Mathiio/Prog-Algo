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
    int low = 0;
    int high = array.size() - 1;
    int mid = (low + high) / 2;
    int found = 0;

    // Binary search for min index
    while (low <= high) {
        if (array[mid] < toSearch) {
            low = mid + 1;
        } else if (array[mid] == toSearch) {
            indexMin = mid;
            high = mid - 1;
            found = 1;
        } else {
            high = mid - 1;
        }

        mid = (low + high) / 2;
    }

    // If find no result
    if (!found) {
        indexMin = indexMax = -1;
        return;
    }

    // Binary search for max index
    low = indexMin;
    high = array.size() - 1;
    mid = (low + high) / 2;

    while (low <= high) {
        if (array[mid] > toSearch) {
            high = mid - 1;
        } else if (array[mid] == toSearch) {
            indexMax = mid;
            low = mid + 1;
        } else {
            low = mid + 1;
        }

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