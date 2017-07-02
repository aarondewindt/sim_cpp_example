//
// Created by elviento on 7/2/17.
//

// The first header to be included should be the header associated with the source file.
#include "triangle.h"

// Then headers from the standard library.
#include <math.h>

// Followed by headers from third party libraries.

// And finally headers from the project.


namespace sim_cpp_example {

    Triangle::Triangle(double height, double width) :
        height_(height),
        width_(width)
    {}

    Triangle::Triangle(double length_1, double length_2, double length_3) {
        // Initialize the height_ and width_ class members by using the first
        // length as the width and calculating the height using Heron's
        // formula in combination with the triangle area formula.

        width_ = length_1;

        double s = (length_1 + length_2 + length_3);
        height_ = 2 / width_* sqrt(s * (s - length_1) * (s - length_2) * (s - length_3));
    }

    double Triangle::get_area() {
        return 0.5 * height_ * width_;
    }
}
