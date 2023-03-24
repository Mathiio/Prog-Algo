#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


int Heap::leftChild(int nodeIndex) {
    return 2 * nodeIndex + 1;
}

int Heap::rightChild(int nodeIndex) {
    return 2 * nodeIndex + 2;
}


void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
	this->get(i)=value;
	while(i>0 && this->get(i)>this->get((i-1)/2)){
		swap(i,(i-1)/2);
		i=(i-1)/2;
	}
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i_max = nodeIndex;
	int leftChildIndex = leftChild(nodeIndex);
	int rightChildIndex = rightChild(nodeIndex);

	if (leftChildIndex < heapSize && this->get(leftChildIndex) > this->get(i_max)) {
		i_max = leftChildIndex;
	}

	if (rightChildIndex < heapSize && this->get(rightChildIndex) > this->get(i_max)) {
		i_max = rightChildIndex;
	}

	if (i_max != nodeIndex) {
		swap(nodeIndex, i_max);
		heapify(heapSize, i_max);
	}
}

void Heap::buildHeap(Array& numbers)
{
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        insertHeapNode(i, numbers[i]);
    }

    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(n, i);
    }
}

void Heap::heapSort()
{
    int n = size();

    buildHeap(*this);

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
