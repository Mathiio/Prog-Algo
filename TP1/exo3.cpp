#include <iostream>

int search(int value, int array[], int size) {
    if (size == 0) {
        return -1; 
    } else if (array[size - 1] == value) {
        return size - 1;
    } else {
        return search(value, array, size - 1);
    }
}

int main() {
    int array[] = {2, 28, 41, 4, 12, 21, 5, 207};
    int value = 21;
    int size = sizeof(array) / sizeof(array[0]);
    int index = search(value, array, size);
    if (index == -1) {
        std::cout << "L'index de la valeur " << value << " n'a pas été trouvé..." << std::endl;
    } else {
        std::cout << "L'index de la valeur " << value << " est : " << index << std::endl;
    }
    return 0;
}