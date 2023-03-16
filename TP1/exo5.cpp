#include <iostream>
#include <math.h>
struct Point {
  double x;
  double y;
};


int isMandelbrot(Point z, Point point, int n){
    if (n == 0) {
        return true;
    }

    double x = z.x * z.x - z.y * z.y + point.x;
    double y = 2 * z.x * z.y + point.y;
    Point z_next = {x, y};

    double abs_z_next = sqrt(x * x + y * y);
    if (abs_z_next > 2) {
        return false;
    }

    return isMandelbrot(z_next, point, n-1);
    return 0;
}



int main() {
  Point z = {0, 0};
  Point point = {-0.5, 0.0};
  int n = 100;

  if (isMandelbrot(z, point, n)) {
    std::cout << "Le point donné appartient à l'ensemble de Mandelbrot." << std::endl;
  } else {
    std::cout << "Le point donné n'appartient pas à l'ensemble de Mandelbrot." << std::endl;
  }
}