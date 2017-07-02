//
// Created by elviento on 7/2/17.
//

#include "rectangle.h"

/** sim_cpp_example - Project wide namespace
 *
 * All code belonging to the project shall be places inside the same project wide
 * namespace. Namespaces may still be nested inside the project wide namespace.
 *
 */
namespace sim_cpp_example {

    Rectangle::Rectangle(double length, double width) :
        length_(length),
        width_(width)
    {}

    double Rectangle::get_area() {
        return length_ * width_;
    }
}

