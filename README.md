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

The C++ code must be cross-platform and able to run on at least Linux
and Windows (and optionally macOS). So the code should use the C++
standard libraries as much possible. This includes C++11 and C++14.
Whenever it's not possible try using cross-platform libraries such as
boos, eigen, gnuplot-iostream, etc.


FS: Folder structure
--------------------

The project is split in these folders. This structure is largely based
on http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure.
Aside from the directories shown below, cmake and doxygen will generate
their directories when executing.

### Directories
 - **bin:**   Contains the project binaries.
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
Core Guidelines* while keeping them similar to *PEP-8* (which is already
 being used for python by the team) whenever possible.


* [NL.1: Don't say in comments what can be clearly stated in code](#Rl-comments)
* [NL.2: State intent in comments](#Rl-comments-intent)
* [NL.3: Keep comments crisp](#Rl-comments-crisp)
* [NL.4: Maintain a consistent indentation style](#Rl-indent)
* [NL.5: Don't encode type information in names](#Rl-name-type)
* [NL.7: Make the length of a name roughly proportional to the length of its scope](#Rl-name-length)
* [NL.8: Use a consistent naming style](#Rl-name)
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

```c++
auto x = m * v1 + vv;   // multiply m with v1 and add the result to vv
```


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

Always indenting the statement after `if (...)`, `for (...)`, and
`while (...)` is usually a good idea:

```c++
if (i < 0) error("negative argument");

if (i < 0)
    error("negative argument");
```

##### Note

Always indent code inside a namespace, class, struct, function, etc,
with the exception of the visibility keywords (public, protected,
private) in classes and structures.

```c++
namespace sim_cpp_example {
    class Rectangle : public ShapeInterface {
    public:
        Rectangle(double length, double width);

        double get_area();
    private:

        double length_;
        double width_;

    };
}
```


### <a name="Rl-name-type"></a>NL.5: Don't encode type information in names

##### Rationale

If names reflect types rather than functionality, it becomes hard to
change the types used to provide that functionality. Also, if the type
of a variable is changed, code using it will have to be modified.
Minimize unintentional conversions.

##### Example, bad

```c++
void print_int(int i);
void print_string(const char*);

print_int(1);   // OK
print_int(x);   // conversion to int if x is a double
```

##### Note

Names with types encoded are either verbose or cryptic.

```c++
printS  // print a std::string
prints  // print a C-style string
printi  // print an int
```

PS. Hungarian notation is evil (at least in a strongly statically-typed
language).


### <a name="Rl-name-length"></a>NL.7: Make the length of a name roughly proportional to the length of its scope

**Rationale**: The larger the scope the greater the chance of confusion
and of an unintended name clash.

##### Example

```c++
double sqrt(double x);   // return the square root of x; x must be non-negative

int length(const char* p);  // return the number of characters in a zero-terminated C-style string

int length_of_string(const char zero_terminated_array_of_char[])    // bad: verbose

int g;      // bad: global variable with a cryptic name

int open;   // bad: global variable with a short, popular name

The use of `p` for pointer and `x` for a floating-point variable is conventional and non-confusing in a restricted scope.
```


### <a name="Rl-name"></a>NL.8: Use a consistent naming style

**Rationale**: Consistence in naming and naming style increases
readability.

##### Types

Type declarations such as classes, structures, typedefs, etc, should
use `CamelCase`.

```c++
typename<typename T>
class HashTbl {   // maps string to T
    // ...
};
```

##### non_types

Non-types such as variables, functions, enumerator members, namespaces
etc, should be `lower_case_with_underscore`.

##### MARCOS

Use `ALL_CAPS` for macros and **only** macros. This is
to avoid confusing macros with names that obey scope and type rules.

###### Example

```c++
void f()
{
    const int SIZE{1000};  // Bad, use 'size' instead
    int v[SIZE];
}
```

###### Note
This rule applies to non-macro symbolic constants:

```c++
enum bad { BAD, WORSE, HORRIBLE }; // BAD
```


### <a name="Rl-space"></a>NL.15: Use spaces sparingly

##### Reason

Too much space makes the text larger and distracts.

##### Example, bad

```c++
#include < map >

int main(int argc, char * argv [ ])
{
    // ...
}
```

##### Example

```c++
#include <map>

int main(int argc, char* argv[])
{
    // ...
}
```


### <a name="Rl-literals"></a>NL.11: Make literals readable

##### Reason

Readability.

##### Example

Use digit separators to avoid long strings of digits

```c++
auto c = 299'792'458; // m/s2
auto q2 = 0b0000'1111'0000'0000;
auto ss_number = 123'456'7890;
```

##### Example

Use literal suffixes where clarification is needed

```c++
auto hello = "Hello!"s; // a std::string
auto world = "world";   // a C-style string
auto interval = 100ms;  // using <chrono>
```

##### Note

Literals should not be sprinkled all over the code as ["magic constants"](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-magic),
but it is still a good idea to make them readable where they are defined.
It is easy to make a typo in a long string of integers.


### <a name="Rl-order"></a>NL.16: Use a conventional class member declaration order

##### Reason

A conventional order of members improves readability.

When declaring a class use the following order

* types: classes, enums, and aliases (`using`)
* constructors, assignments, destructor
* functions
* data

Use the `public` before `protected` before `private` order.

Private types and functions can be placed with private data.

Avoid multiple blocks of declarations of one access (e.g., `public`) dispersed among blocks of declarations with different access (e.g. `private`).

##### Example
```c++
class X {
public:
    // interface
protected:
    // unchecked function for use by derived class implementations
private:
    // implementation details
};
```

##### Note

The use of macros to declare groups of members often violates any ordering rules.
However, macros obscures what is being expressed anyway.


### <a name="Rl-knr"></a>NL.17: Use K&R-derived layout

##### Reason

This is the original C and C++ layout. It preserves vertical space well. It distinguishes different language constructs (such as functions and classes) well.

##### Note

In the context of C++, this style is often called "Stroustrup".

##### Example

```c++
struct Cable {
    int x;
    // ...
};

double foo(int x)
{
    if (0 < x) {
        // ...
    }

    switch (x) {
        case 0:
            // ...
            break;
        case amazing:
            // ...
            break;
        default:
            // ...
            break;
    }

    if (0 < x)
        ++x;

    if (x < 0)
        something();
    else
        something_else();

    return some_value;
}
```

Note the space between `if` and `(`

##### Note

Use separate lines for each statement, the branches of an `if`, and the body of a `for`.

##### Note

The `{` for a `class` and a `struct` is *not* on a separate line, but the `{` for a function is.

##### Note

Capitalize the names of your user-defined types to distinguish them from standards-library types.

##### Note

Do not capitalize function names.


### <a name="Rl-ptr"></a>NL.18: Use C++-style declarator layout

##### Reason

The C-style layout emphasizes use in expressions and grammar, whereas the C++-style emphasizes types.
The use in expressions argument doesn't hold for references.

##### Example

```c++
T& operator[](size_t);   // OK
T &operator[](size_t);   // just strange
T & operator[](size_t);   // undecided
```

### <a name="Rl-misread"></a>NL.19: Avoid names that are easily misread

##### Reason

Readability.
Not everyone has screens and printers that make it easy to distinguish all characters.
We easily confuse similarly spelled and slightly misspelled words.

##### Example

```c++
int oO01lL = 6; // bad

int splunk = 7;
int splonk = 8; // bad: splunk and splonk are easily confused
```

### <a name="Rl-stmt"></a>NL.20: Don't place two statements on the same line

##### Reason

Readability.
It is really easy to overlook a statement when there is more on a line.

##### Example

```c++
int x = 7; char* p = 29;    // don't
int x = 7; f(x);  ++x;      // don't
```


### <a name="Rl-dcl"></a>NL.21: Declare one name (only) per declaration

##### Reason

Readability.
Minimizing confusion with the declarator syntax.


### <a name="Rl-void"></a>NL.25: Don't use `void` as an argument type

##### Reason

It's verbose and only needed where C compatibility matters.

##### Example

```c++
void f(void);   // bad

void g();       // better
```

##### Note

Even Dennis Ritchie deemed `void f(void)` an abomination.
You can make an argument for that abomination in C when function prototypes were rare so that banning:

```c++
int f();
f(1, 2, "weird but valid C89");   // hope that f() is defined int f(a, b, c) char* c; { /* ... */ }
```

would have caused major problems, but not in the 21st century and in C++.


### <a name="Rl-const"></a>NL.26: Use conventional `const` notation

##### Reason

Conventional notation is more familiar to more programmers.
Consistency in large code bases.

##### Example

```c++
const int x = 7;    // OK
int const y = 9;    // bad

const int *const p = nullptr;   // OK, constant pointer to constant int
int const *const p = nullptr;   // bad, constant pointer to constant int
```

##### Note

We are well aware that you could claim the "bad" examples more logical than the ones marked "OK",
but they also confuse more people, especially novices relying on teaching material using the far more common, conventional OK style.

As ever, remember that the aim of these naming and layout rules is consistency and that aesthetics vary immensely.


