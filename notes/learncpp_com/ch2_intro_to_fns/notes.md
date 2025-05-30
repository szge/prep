- **function**: a (reusable) sequence of statements designed to do a particular job, executed sequentially
- **function call**: an expression telling the CPU to interrupt the current fn, execute another, and return
- nested functions are not supported in C++
- when the program starts, the OS makes a call to `main()`; it's required to return an `int`, and explicit fn calls to `main` aren't allowed.
- global vars are initialized prior to executing `main()`. if one of their initializers calls a fn, then it will execute before main.
- C++ defines 3 status codes: 0/`EXIT_SUCCESS`, and `EXIT_FAILURE`. they are preprocessor macros defined in `cstdlib`.
- a value-returning fn that doesn't return a value will produce undefined behaviour.
  - the only exception is main, which returns 0 if no return value is specified.
- fns can only return one value
- best practice: don't repeat yourself. use variables to store calculations, functions, and loops
- void functions will cause a compiler error:
  - if used in an expression that requires a value (e.g. `cout << hi()`)
  - if it tries to return a value
- **fn parameter**: variables used in the header of a fn. they are initialized by values provided by the caller.
  - _pass by value_: the value of each argument is copied into the matching parameter (copy initialization)
- the number of arguments provided in the caller must generally match, or there will be a compiler error
- **unreferenced parameters**: parameters that aren't used in the fn body. will generate compiler warning
  - used to differentiate whether a `++` or `--` overload is a prefix (`c++`) or postfix (`++c`) case
- **unnamed parameters**: `void doSomething(int) {}`; could be used in refactoring a fn with many uses
- local variables (defined in fn bodies) are destroyed in the opposite order of creation, at the end of the curly braces it was defined in
  - lifetime is the time between variable creation and destruction. it's runtime property
  - when an object is destroyed, in most cases nothing happens, it just becomes invalid; for class type objects, the destructor is invoked.
  - using an object after destruction is undefined behavior. eventually the memory used by the object will be deallocated
- identifier scope is a compile-time property; using an out-of-scope identifier will cause a compiler error
- names used for parameters or body variables are only visible in that function. this keeps functions independent
- best practice: define local variables as close to their first use as reasonable.
- **temporary object**: an unnamed object used to hold a value needed for a short time
  - e.g. generated by compiler for storing fn return values, after the original has gone out of scope
  - have no scope (they don't have an identifier)
  - destroyed at the end of the full expression where they're created
  - modern C++ (>17) will try to avoid generating temporaries; e.g., it will just initialize a variable directly with a return value
- effectively use functions: group repeated statements, well-defined input&output, one task
- **forward declaration**: a statement telling the compiler that an identifier exists before definition
  - using a forward-declared fn will result in a linker error
  - most often used with fns, but can be used with other identifiers
- **one-definition rule**
  1. within each file, a fn, variable, type, or template in a scope (e.g., fn, namespace) can only have one defn.
     1. violation causes a compiler error
  2. within a program, a fn or variable in a given scope can only have one defn. 
     1. violation causes a linker error
  3. types, templates, inline fn, and inline variables can have duplicate defns in different files, as long as they are identical
     1. violation causes undefined behavior
- **naming collision**: an identifier introduced in a way that the compiler or linker can't tell them apart
  - if same file, compiler error. if separate files, linker error.
- **scope region**: an area of source code where declared identifiers are considered distinct from other scopes.
  - e.g. function body, namespace
- any name outside a class, fn, namespace is considered part of the global namespace/scope
- **using directive**: allows access to names in a namespace without a prefix, e.g. `using namespace std;`
  - best practice: avoid these! they can introduce conflicts.
- **preprocessor**: a program that manipulates source code before compilation; strips out comments, ends each file in a newline, processes `#include` directives
  - the preprocessor recursively replaces `#include <file>` with the contents of that file.
  - **macro**: a rule defining how input text is converted into replacement output text. there exist object and fn-like macros.
    - best practice: macro names should have uppercase with underscores; generally avoid substitution usage, and definitely avoid fn macros.
  - generally, only use object-like macros without substitution text. e.g. `#ifdef PRINT_JOE ... #endif` to have conditional compilation of code
  - `#if 0 ... #endif`, `#ifdef ... #endif`, `ifndef ... #endif`
- **header files**: conventionally used to propagate related forward declarations into a file, e.g. `#include <iostream>`
  - don't add this to the compile command, since they are included by the `#include` statements.
  - for now, avoid adding definitions in header files, since they will violate the one-definition rule.
    - some definitions can be safely defined in header files due to ODR exemptions, like inline fns and vars, types, templates.
  - best practice: code files should `#include` their paired header, allowing errors at compile time rather than link time.
  - best practice: avoid `#include`ing .cpp files. if the project doesn't compile, then you need to add them to your project
  - angled brackets (e.g. iostream) points the preprocessor to search the "include directories", configured in your compiler settings.
  - rule: use double quotes for header files you write, angled brackets for compiler or 3rd party libs
  - `<iostream.h>` defines in the global namespace (bad), and `<iostream>` defines in the std namespace (good)
  - avoid using relative paths in `#include`, since the directory structure might change. tell your compiler to look for header files somewhere else
  - headers can include other headers
  - best practice: `#include` all header files needed to compile. don't rely on headers included transitively from other headers.
  - best practice: to flag missing includes, order them as follows: (1) paired (2) project (3) third-party (4) standard lib
  - best practice: document what something does or how to use it in the header. document how something works in the source files
- **header guards**: conditional directives to avoid violating the ODR, e.g., due to headers including headers
  - header guards don't prevent inclusion in different files. therefore, avoid putting definitions in header files, and put the definition in only one source file.
  - modern compilers support `#pragma once`, which replaces user-defined header guards.
- **how to design your first programs**
  1. define your goal in 1-2 sentences; maybe as a user-facing outcome
  2. define requirements/constraints (budget, timeline, space, etc.); focus on "what", not "how"
  3. define tools, targets (OS), (code) backup plan (GitHub)
  4. break hard problems into easy ones (start from top down)
  5. figure out the sequence of events (bedroom -> bathroom -> breakfast)
- **optimize for maintainability, not performance**