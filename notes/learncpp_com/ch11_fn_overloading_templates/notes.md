- fn overloading: creating multiple fns with the same name but different param types. use for program simplicity
  1. the compiler needs to be able to differentiate between the fns
     - based number (including ellipsis) or type of params (excludes type aliases, const). NOT return type.
     - however, for member fns, `const`, `volatile`, and ref-qualifiers are used for overloading
  2. overload resolution: the compiler needs to be able to match fn calls to the appropriate overload
  - needs to satisfy both these conditions; otherwise, compiler error
  - **type signature**: parts of the fn header used for differentiation, including name, num params, param type, an fn-level qualifiers. excludes return type
- overload resolution
  - compiler goes through a sequence of rules to determine the best match.
    - at each step, the compiler applies type conversions to the args in the fn call. for each conversion, it checks if there are any matches.
      1. no matching fns found. compiler goes to next step in sequence
      2. a single matching fn found. matching considered complete
      3. more than one matching fn found. compiler issues an ambiguous match compile error.
        - e.g., `5L` could be numerically converted to `int` or `double`
    - if the compiler reaches the end of the sequence without finding a match, it will issue a compile error
  1. tries to find an exact match; two phases:
     1. check for an exact parameter type match
     2. check with trivial conversions, including lvalue to rvalue, qualification (non-const to const), non-reference to reference
  2. tries to find a match by applying numeric promotion
  3. tries to find a match by applying numeric conversions
  4. tries to find a match through user-defined conversions
     - a class constructor also acts as a user-defined conversion
  5. tries to find a matching fn with ellipsis
  - resolving ambiguous matches: (1) define a new overloaded fn with exact types (2) explicitly cast the args (3) literal suffixes
  - for fns with multiple args, the compiler applies matching rules to each arg in turn.
- deleting fns: sometimes you want to disable calling your fn with values of certain types.
  - e.g. `void printInt(char) = delete;`
  - deleted fns are still considered candidates in fn overload resolution, so they can still cause ambiguous match compilation errors
  - if a deleted fn is selected during fn overload resolution, it will cause an error
- default args: using an equals sign to specify a default argument, e.g. `void foo(int x = 5);`
  - default args are inserted by the compiler at the site of the fn call, to match the fn signature.
  - can be used to add new params to an existing fn without breaking existing calls
  - C++ doesn't provide syntax to support fn calls with values for right params but default values for left params (e.g. `print(,,3)`)
    - any explicitly provided args must be the leftmost args
    - in a fn signature, all default parameters must be on the right side.
    - default args should be written in the order of likelihood of setting
  - default args can't be redeclared (e.g. only one of forward declaration or definition), and must be declared before use.
    - best practice: declared default args in the forward declaration so they're more likely to be included before use
  - default values aren't part of a fn signature
  - default values can lead to ambiguous matches; fns called thru fn ptrs aren't considered, so you can use them to make fns non-ambiguous
- template system: simplifies creating fns/classes that work with different data types
  - **primary template**: initial fn template; **instantiated fns**: fns generated from primary template
  - template params: (1) type template params, (2) non-type template params representing constexpr values, (3) template template params
  - use a single capital letter `T`, `U`, ... to name type template params that are used in trivial or obvious ways; a longer name otherwise
- fn template instantiation
  - fn templates aren't actually fns (compiled, executed directly); instead, they generate fns
  - to instantiate a fn, the compiler basically clones the primary template and replaces the template type with the specified type
  - template argument deduction: the compiler can deduce the actual type that should be used from the fn call, e.g. `max(3, 5);`
  - in most cases, prefer normal fn syntax (no angle brackets), for specificity, unless you need the fn template version to be preferred
  - fn templates with non-template params: allowed (e.g. `int someFn(T, double);`)
  - instantiated fns may not always compile, e.g. if the ops in the fn aren't compatible with the type
  - instantiated fns may not make sense semantically
    - you can tell the compiler that some types should be disallowed
  - beware fn templates with _modifiable_ static local vars: each fn instantiated from the template will have its own version of the static local var
- fn templates with multiple template types
  - prefer using `auto` for each fn param when you want them to be independent (different) types, in C++20
  - fn templates may be overloaded; the rules for selection are called "partial ordering of fn templates"
    - whichever fn template is more restrictive/specialized will be preferred
- non-type template params: a template param with a fixed type that is a placeholder for a constexpr value
  - allowed types: integral, enumeration, `std::nullptr_t`, floating pt, obj/fn/member-fn ptr or ref, literal class
  - e.g. `std::bitset<8> bits { 0b0000'0101 };` tells bitset how many bitsets we want it to store
  - primarily used to pass in constexpr values to fns or classes so they can be used in contexts needing constexpr
    - (regular fn params can't be constexpr)
  - certain types of arguments can be implicitly converted to match a non-type template param of a different type. (refer to ch11)
- using fn templates in multiple files
  - the compiler error if you use a fn template before defining it. conventionally, put it in a header file.
    - fn templates are implicitly inline so they don't violate the ODR
  - 