#include <iostream>

#include "rectangle.h"
#include "triangle.h"

// Do not so this. Never use 'using namespace'. Always use the fully
// qualified name.
using namespace sim_cpp_example;


int main() {
    Rectangle rectangle = Rectangle(1, 2);
    Triangle triangle = Triangle(3, 4, 5);

    std::cout << "Rectangle area: " << rectangle.get_area() << std::endl;
    std::cout << "Triangle area: " << triangle.get_area() << std::endl;
    return 0;
}
