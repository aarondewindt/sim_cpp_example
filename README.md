DARE Simulations C++ Example Project
====================================

This project serves as an example C++ project showing the folder
structure, basic code style, documentation and unit testing. Existing
and freely available standards are used. Support for python code will be
added in the future.

 - Code style: Google C++ Style Guide (https://google.github.io/styleguide/cppguide.html)
 - Documentation: Doxygen (http://www.stack.nl/~dimitri/doxygen/index.html)
 - Unit testing: Google test (https://github.com/google/googletest)


Folder structure
----------------

The project is split in these folders. This structure is largely based
on http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure.

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
