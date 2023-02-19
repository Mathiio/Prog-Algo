#include <iostream>



void allEvens(int *evens, int *array, int *evenSize, int *arraySize) {
    if (array[*arraySize-1] % 2 == 0) {
        evens[(*evenSize)] = array[*arraySize-1];
        (*evenSize)++;
    }

    if (*arraySize > 0) {
        (*arraySize)--;
        allEvens(evens, array, evenSize, arraySize);
    }
}


int main() {
    int *evens = new int[100];
    int array[] = {9, 2, 5, 228, 24, 33, 121, 1017, 402, 68, 79};  
    int evenSize = 0;  
    int arraySize = 11;  


    std::cout << "Les nombres du tableau initial sont :";
    for (int j = 0; j < arraySize; j++) {
        std::cout << array[j] << ", ";
    }
    std::cout << std::endl;

    allEvens(evens, array, &evenSize, &arraySize);

    std::cout << "Les nombres du tableau de nombres pairs sont : ";
    for (int i = 0; i < evenSize; i++) {
        std::cout << evens[i] << " ";
    }
    std::cout << std::endl;
}