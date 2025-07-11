- **constant**: a value that can't be changed during execution
  - **named** constants have an identifier
    - constant variables, macros with substitution text, enumerated constants
  - **literal** constants don't have an identifier
- the object's type includes const, e.g. `const double`
- const variables must be initialized on definition (assignment results in compiler error)
  - can be initialized from other variables, including non-const ones
- you can use `const` for function value params, but it's not necessary since it's a copy that will be destroyed
- you can make a function return value const (e.g. `const int getValue()`) but this can result in worse performance.
- best practice: don't use `const` for function parameters or return values.
- best practice: if a variable can be made `const`, do it to reduce complexity and bugs
- best practice: prefer constant variables to macros.
- **literals** are values inserted directly into the code.
- for historical reasons, strings are not a fundamental data type in C++.
- best practice: avoid "magic numbers" (unclear meaning), use constexpr variables instead.
- **optimization**
  - **optimizing compilers** (most modern compilers) automatically optimize as part of compilation.
  - the debug build usually disables optimization, and release usually enables.
  - "as-if" rule: a compiler can modify a program however, as long as they don't affect "observable behavior".
    - exception: unnecessary calls to a copy or move constructor
  - **compile-time evaluation**: when the compiler evaluates an expression at compile-time
    - **constant folding**: when the compiler replaces expressions with their result; e.g. 3 + 4 gets replaced with 7
    - **dead-code elimination**
    - const variables are easier to optimize for the compiler
  - optimization rearranges things, making things harder to debug.
- **constexpr**: constant expressions
  - the "as-if" rule is implemented by the compiler, so we can't reliably know if code will execute at compile time or not.
  - C++ provides language features for compile-time programming (code executed at compile time), helping with performance and quality
  - **constant expression**: an expression that must be evaluatable at compile-time, meaning each part (literal, variable, operator, fn call) must be evaluatable at compile-time:
    - literals, most operators with constant expression operands (`2 * sizeof(int)`), const integral vars (`const int x{5};`), constexpr vars, constexpr fn calls with constexpr args
    - non-type template params, enumerators, type traits, constexpr lambda expressions
  - the following can't be used in a constant expression:
    - non-const vars, const non-integral vars, return values of non-constexpr fns, fn params, operators `new`, `delete`, `throw`, `typeid`, `,` (comma) operator
  - in contexts that require a constant expression (`const int x {3+4};`), the compiler is required to evaluate constant expressions.
    - otherwise (`int x {3+4};`), the compiler may choose to evaluate it at compile-time or runtime.
- **constexpr variables**: use the `constexpr` keyword instead of `const` in a variable's declaration.
  - this allows the compiler to assist in ensuring the variable is a valid constexpr.
  - `const`: the value can't be changed after initialization, and the value of the initializer may be known at compile-time or runtime
  - `constexpr`: the object can be used in a constant expression; the value must be known at compile-time
  - `constexpr` variables are implicitly `const`
  - best practice: use `constexpr` if the initializer is a constant expression, `const` if not, or if it's a type that requires dynamic memory allocation like vector.
- `std::string`
  - C-style string variables are hard to use; prefer `std::string` and `std::string_view`.
  - `std::string` requires dynamic memory allocation since its size can change at runtime
  - use `std::ws` input manipulator to get `std::cin` to ignore leading whitespace before extraction, so the previous newline doesn't get put into the string
    - `std::ws` isn't preserved across calls, so you need `std::cin >> std::ws` for every `getline()` call
  - initializing a `std::string` is expensive; try to minimize copies
  - don't pass `std::string` by value - this results in an expensive copy. in most cases, use a `std::string_view` param instead
  - you _can_ return a `std::string` since it supports "move semantics"
    - as long as the return statement expression resolves to
      - (1) a local var of type `std::string`
      - (2) `std::string` returned by value from another fn call or operator
      - (3) `std::string` temporary that is created as part of the return statement
    - instead of returning a C-style string literal, use a `std::string_view` return type instead
  - `constexpr std::string` has limited support in C++20. if you need this, use `std::string_view` instead
- `std::string_view`
  - e.g. `std::string s {"hi"};` copies the C-style string literal into memory allocated for `s`. this is slow (unlike fundamental types like `int`)
  - if we just need to get read-only access to an existing string (C-style, `std::string`, or `std::string_view`), we can use a `string_view`, especially for fn params
  - `std::string_view` will not implicitly convert to `std::string`, to prevent expensive copies.
    - if you want to do this, you can (1) create a `std::string` with a `std::string_view` initializer, or (2) use `static_cast`
  - assignment changes what `std::string_view` is viewing. e.g., if `std::string_view sv {name};`, assigning to `sv` will change `sv` but not `name`
  - unlike `std::string`, `std::string_view` has full support for `constexpr`.
  - initialize with `std::string_view` or C-style literal, but NOT `std::string` literal (`s` suffix) (dangling)
  - returning a `std::string_view` can be dangerous if viewing a local variable.
    - you can return a C-style string literal as a `std::string_view` since they exist for the entire program.
  - view modification fns (doesn't modify underlying): `remove_prefix()`, `remove_suffix()`; the only way to reset it is through re-assigning the source.
    - this means you can view a substring without making a copy.
    - however, this means `std::string_view` isn't necessarily null-terminated. (C-style and `std::string` are always null-terminated). this is mostly fine since it keeps track of length.
      - however, you should avoid writing code that assumes it's null-terminated. if you need null termination, convert it to a string.
- `view`ing is inexpensive. you have no responsibility for objects viewed, but you also have no control over those objects.
  - `std::string` does a copy so it can fully own a value.
  - if the string being viewed by `std::string_view` is modified or destroyed, using the view will result in undefined behavior.
  - `std::string_view` is best used as a read-only fn param.
  - prefer `std::string_view` to `const std::string&`.
  - when a `std::string` is modified, any views are likely to be invalidated.
- General guide
  - variables
    - use `std::string` when you need to modify a string, store user-inputted text, or store the `std::string` return value of a fn
    - use `std::string_view` when you only need read-only access of an existing string, a symbolic constant for a C-style string, or you need a fn return value that is a C-style string or a non-dangling `std::string_view`.
  - fn params
    - use `std::string` when the fn needs to modify the arg string without affecting the caller (rare)
    - use `std::string_view` for other stuff
  - return types
    - use `std::string` when the return value is a `std::string` local var or fn param, or a fn call that returns a `std::string` by value
    - use `std::string_view` when the fn returns a C-style string literal or local `std::string_view` initialized with a C-style string literal, or it returns a `std::string_view` param.



**Insights**

Things to remember about `std::string`:

- Initializing and copying std::string is expensive, so avoid this as much as possible.
- Avoid passing std::string by value, as this makes a copy.
- If possible, avoid creating short-lived std::string objects.
- Modifying a std::string will invalidate any views to that string.
- It is okay to return a local std::string by value.
- 
Things to remember about `std::string_view`:
- std::string_view is typically used for passing string function parameters and returning string literals.
- Because C-style string literals exist for the entire program, it is always okay to set a std::string_view to a C-style string literal.
- When a string is destroyed, all views to that string are invalidated.
- Using an invalidated view (other than using assignment to revalidate the view) will cause undefined behavior.
- A std::string_view may or may not be null-terminated.