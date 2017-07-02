//
// Created by elviento on 7/2/17.
//

#ifndef SIM_CPP_EXAMPLE_RECTANGLE_H
#define SIM_CPP_EXAMPLE_RECTANGLE_H

#include "shape.h"


/** sim_cpp_example - Project wide namespace
 *
 * All code belonging to the project shall be places inside the same project wide
 * namespace. Namespaces may still be nested inside the project wide namespace.
 *
 */
namespace sim_cpp_example {

    /** Rectangle - Class used to represent rectangles.
     *
     * This class is used to represent rectangles, it inherits from ShapeInterface
     *
     */
    class Rectangle : public ShapeInterface{
    public:
        /** Constructor based on length and width.
         *
         * @param length Length of the rectangle.
         * @param width Width of the rectangle.
         *
         */
        Rectangle(double length, double width);

        /** Returns the area of the rectangle.
         *
         * @return the area of the rectangle.
         */
        double get_area();
    private:

        // Data members are named as normal variables, but with a trailing underscore.
        double length_; /**< Length of the rectangle. */
        double width_;  /**< Width of the rectangle. */

    };
}

#endif //SIM_CPP_EXAMPLE_RECTANGLE_H
