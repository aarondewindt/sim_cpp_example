//
// Created by elviento on 7/2/17.
//

#ifndef SIM_CPP_EXAMPLE_TRIANGLE_H
#define SIM_CPP_EXAMPLE_TRIANGLE_H

#include "shape.h"

/** Project wide namespace
 *
 * All code belonging to the project shall be places inside the same project wide
 * namespace. Namespaces may still be nested inside the project wide namespace.
 *
 */
namespace sim_cpp_example {

    class Triangle : public ShapeInterface {
    public:
        /** Constructor based on width and height.
         *
         * @param height The height of the triangle.
         * @param width The width of the triangle.
         *
         */
        Triangle(double height, double width);

        /** Constructor based on side length.
         *
         * @param length_1 Length of the first side.
         * @param length_2 Length of the second side.
         * @param length_3 Length of the third side.
         *
         */
        Triangle(double length_1, double length_2, double length_3);


        /** Returns the area of the triangle.
         *
         * @return The area of the triangle
         */
        double get_area();

    private:

        // Data members are named as normal variables, but with a trailing underscore.
        double height_; /**< Length of the triangle. */
        double width_;  /**< Width of the triangle. */
    };
}

#endif //SIM_CPP_EXAMPLE_TRIANGLE_H
