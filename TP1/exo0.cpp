#include <iostream>


int power(int value, int n) {
    if (n == 0) {
        return 1;
    } else {
        return value * power(value, n - 1);
    }
}

int main() {
    int value = 3;
    int n = 4;
    std::cout << value << " à la puissance " << n << " est égale à : " << power(value, n) << std::endl;
    return 0;
}