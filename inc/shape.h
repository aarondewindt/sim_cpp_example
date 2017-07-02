//
// Created by elviento on 7/2/17.
//

#ifndef SIM_CPP_EXAMPLE_SHAPE_H
#define SIM_CPP_EXAMPLE_SHAPE_H

/** Project wide namespace
 *
 * All code belonging to the project shall be places inside the same project wide
 * namespace. Namespaces may still be nested inside the project wide namespace.
 *
 */
namespace sim_cpp_example {
    /** Interface class for a shape types.
     *
     * This is an abstract class used as a generic interface to interact with
     * different types of shapes.
     *
     * An interface is a type of abstract class that does not implement any
     * of its members. Its purpose is to force child classes to an implement
     * that's required somewhere else. So it's a purely abstract class.
     *
     */
    class ShapeInterface {

        /** Returns the area of the shape.
         *
         * @return The area of the shape.
         */
        virtual double get_area() = 0;
    };
}



#endif //SIM_CPP_EXAMPLE_SHAPE_H
