DARE Simulations C++ Example Project
====================================

This project serves as an example C++ project showing the folder
structure, basic code style, documentation and unit testing. Existing
and freely available standards are used. Support for python code will be
added in the future.

 - Build tool: CMake (https://cmake.org)
 - Code style: C++ Core Guidelines (https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)
 - Documentation: Doxygen (http://www.stack.nl/~dimitri/doxygen/index.html)
 - Unit testing: Google test (https://github.com/google/googletest)


FS: Folder structure
--------------------

The project is split in these folders. This structure is largely based
on http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure.
Aside from the directories shown below, cmake and doxygen will generate
their directories when executing.

### Directories
 - **doc:**   Contains the project documentation.
 - **inc:**   All project header files and all third party header files
              that do not exist under `/usr/local/include` are also placed
              here.
 - **lib:**   Any libraries that get compiled by the project and third
              party libraries distributed with the code.
 - **spike:** Smaller classes or code files used to test technologies
              or ideas. These can then be kept around for future
              reference without cluttering the project's code.
 - **src:**   The application and only the applications source files.
 - **test:**  All test code files.


### Files
 - **.gitignore:** The repository's gitignore file. It should include
                   ignores for tools and IDE's commonly used by us
                   (Clion, eclipse, python, matlab, etc).
 - **CMakeLists.txt:** Cmake project definition file.
 - **doxyfile:** Doxygen's configuration file.
 - **LICENCE:** Licence file if applicable.
 - **README.md:** This readme file.


NL: Naming and layout
---------------------

As most C++ style guides, the *C++ Core Guidelines* doesn't define
naming and layout conventions. Instead it gives recommendations and
leaves the final decision to the developers. The main recommendation is
to keep the naming conventions consistent throughout the entire project.
This sections describes the naming conventions used by our projects.
These conventions are based on the recommendation given by the *C++
Core Guidelines* with some modifications to keep them similar to
*PEP-008* which is already being used by the team.


* [NL.1: Don't say in comments what can be clearly stated in code](#Rl-comments)
* [NL.2: State intent in comments](#Rl-comments-intent)
* [NL.3: Keep comments crisp](#Rl-comments-crisp)
* [NL.4: Maintain a consistent indentation style](#Rl-indent)
* [NL.5: Don't encode type information in names](#Rl-name-type)
* [NL.7: Make the length of a name roughly proportional to the length of its scope](#Rl-name-length)
* [NL.8: Use a consistent naming style](#Rl-name)
* [NL.9: Use `ALL_CAPS` for macro names only](#Rl-all-caps)
* [NL.10: Avoid CamelCase](#Rl-camel)
* [NL.11: Make literals readable](#Rl-literals)
* [NL.15: Use spaces sparingly](#Rl-space)
* [NL.16: Use a conventional class member declaration order](#Rl-order)
* [NL.17: Use K&R-derived layout](#Rl-knr)
* [NL.18: Use C++-style declarator layout](#Rl-ptr)
* [NL.19: Avoid names that are easily misread](#Rl-misread)
* [NL.20: Don't place two statements on the same line](#Rl-stmt)
* [NL.21: Declare one name (only) per declaration](#Rl-dcl)
* [NL.25: Don't use `void` as an argument type](#Rl-void)
* [NL.26: Use conventional `const` notation](#Rl-const)

### <a name="Rl-comments"></a>NL.1: Don't say in comments what can be clearly stated in code

##### Reason

Compilers do not read comments.
Comments are less precise than code.
Comments are not updated as consistently as code.

##### Example, bad

    auto x = m * v1 + vv;   // multiply m with v1 and add the result to vv



### <a name="Rl-comments-intent"></a>NL.2: State intent in comments

##### Reason

Code says what is done, not what is supposed to be done. Often intent can be stated more clearly and concisely than the implementation.

##### Example

```c++
void stable_sort(Sortable& c)
    // sort c in the order determined by <, keep equal elements (as defined by ==) in
    // their original relative order
{
    // ... quite a few lines of non-trivial code ...
}
```

##### Note

If the comment and the code disagrees, both are likely to be wrong.



### <a name="Rl-comments-crisp"></a>NL.3: Keep comments crisp

##### Reason

Verbosity slows down understanding and makes the code harder to read by spreading it around in the source file.

##### Note

Use intelligible English.
I may be fluent in Papiamentu, but most programmers are not; the maintainers of my code may not be.
Avoid SMS lingo and watch your grammar, punctuation, and capitalization.
Aim for professionalism, not "cool."


### <a name="Rl-indent"></a>NL.4: Maintain a consistent indentation style

##### Reason

Readability. Avoidance of "silly mistakes."

##### Example, bad
```c++
int i;
for (i = 0; i < max; ++i); // bug waiting to happen
if (i == j)
    return i;
```

##### Note

Always indenting the statement after `if (...)`, `for (...)`, and `while (...)` is usually a good idea:

if (i < 0) error("negative argument");

if (i < 0)
    error("negative argument");

##### Note

Always indent code inside a namespace, class, struct, etc.
```c++
namespace sim_cpp_example {
    class Rectangle : public ShapeInterface{
    public:
        Rectangle(double length, double width);

        double get_area();
    private:

        double length_;
        double width_;

    };
}
```