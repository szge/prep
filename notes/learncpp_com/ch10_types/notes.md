- conversions don't change the data being converted; it just produces the result (temporary object) from the data
- implicit type conversion: when a data type is required, but another one is supplied
  - happens when: initializing, fn return value, binary ops, fn call with differing types, or non-Boolean value in if-statement
  - C++ defines **standard conversions** that specify how various types convert to others within the same "group".
    - numeric promotions: small integrals -> `int`, `unsigned int`; `float` -> `double`
    - numeric conversions: other integral and floating pt conversions that aren't promotions
    - qualification conversions: add or remove `const` or `volatile`
    - value transformations: change the value category of an expression
    - ptr conversions: `std::nullptr` -> ptr types, or ptr types to other ptr types
  - if no valid conversion can be found, then compilation will fail with an error
  - narrowing conversions are disallowed when using brace-initialization
- numeric promotion: the type conversion of certain narrower numeric types (e.g. `char`) to certain wider numeric types (`int`, `double`)
  - all are **value-preserving** (safe): every possible source value can be converted to an equal value of the destination type; the compiler will freely use these
  - reduces redundancy: you can write a fn with `int` or `double` types and call them with types that can be numerically promoted to match
  - floating-pt promotion: `float` -> `double`
  - integral promotions
    - `signed char`, `signed short` -> `int`
    - `unsigned char`, `char8_t`, `unsigned short` -> `int` if it can hold the entire range, otherwise `unsigned int`
    - `char` follows the conversion rules above depending on if it's signed or unsigned
    - `bool` -> `int`
    - value-preserving, but doesn't necessarily preserve signedness
- numeric conversions: remaining numeric type conversions that aren't covered by "numeric promotion"
  1. integral type to any other integral type (excluding promotions)
  2. floating pt to any other floating pt, e.g. `double` -> `float`, `double` -> `long double` (excluding promotions)
  3. floating pt to any integral, e.g. `double` -> `int`
  4. integral to any floating pt, e.g. `int` -> `double`
  5. integral or floating pt to bool
  - can be value-preserving (safe), reinterpretive (unsafe, but no data lost; e.g. signedness conversions), or lossy (unsafe)
  - general rules:
    - converting a value into a type whose range doesn't support that value will lead to unexpected results
    - overflow is well-defined for unsigned values and undefined behaviour for signed values
    - converting from a larger type to a smaller type from the same family will generally work if the value fits in the smaller type range
- narrowing conversions: potentially unsafe conversion where the destination type might not hold all values of the source type
  - floating pt -> integral, floating pt -> narrower floating pt, integral -> floating pt, integral -> another integral type that can't represent all values
    - unless the value converted is constexpr and can be stored exactly in the destination type
  - avoid when possible; if you need one, use `static_cast` for explicit conversion
  - initializing a narrower floating pt type with a constexpr value is allowed as long as the value is in its range, even if it can't store it exactly
- arithmetic conversions: default (non-overloaded) operators require operands to be of the same type
  1. if one operand is an integral type and another is a floating pt, the integral is converted to floating pt; otherwise, integrals are numerically promoted
  2. if one operand is signed and the other unsigned, special rules apply; otherwise, the operator with lower rank is converted into the higher rank
     1. (highest rank) long double, ..., long long, ..., int (lowest)
     2. special rules: see learncpp 10.5
  - `signed` - `unsigned` converts the `signed` to `unsigned` resulting in an unexpected result; so in general, avoid unsigned integers
  - you can use `std::common_type_t<int, double>` to find common types
- explicit type conversion (casting) and static_cast
  - `static_cast` (compile-time btw related types); preferred, e.g. `static_cast<int>(x)` or `int { x }` (temp object)
    - returns temporary object direct-initialized with converted value
    - prefer `static_cast` over initializing a temp object like `int { x }`
  - `dynamic_cast` (runtime conversions on ptrs or refs in an inheritance hierarchy)
  - `const_cast` (adds or removes const)
  - `reinterpret_cast` (reinterprets the bit-level representation as another type)
  - C-style casts (performs some combo of static, const, or reinterpret cast), e.g. `(int) x` or `int(x)`
    - generally avoided, since it can actually perform multiple conversions without clarity
    - allows converting a derived object to an inaccessible (e.g. privately inherited) base class
- typedefs and type aliases
  - `using` is the keyword for creating an alias to an existing data type, e.g. `using Distance = double`
    - use anywhere a type is needed
    - conventionally, start name with capital letter and no suffix
    - not type safe since it doesn't prevent semantic errors
    - the scope of a type alias follows the same rules as variable identifiers; either global and usable for the file, or just block-scoped
      - for use across multiple files, define in a header file
    - `using FcnType = int(*)(double, char);`
  - `typedef` is the older way of creating a type alias; prefer type aliases
    - `typedef long Miles;`
  - when to use type aliases
    - use in combination with preprocessor directives to define aliases that include the type's size in bits (since the C++ standard doesn't specify a size for types)
      - `std::int8_t` is typically a typedef for `signed char`, so printing it to console usually prints as a character
    - to make complex types easier to read, e.g. `using VectPairSI = std::vector<std::pair<std::string, int>>;`
    - document the meaning of a value, e.g. `using TestScore = int; TestScore gradeTest();`
    - easier code maintenance (can update types just by changing the alias)
  - introduce complexity; use type aliases when they provide a clear benefit to readability or maintenance
- type deductions with `auto`: allows the compiler to deduce an object type from its initializer
  - can use with `const`, `constexpr`, and other qualifiers
  - the initializer must not be blank or reduce to an incomplete type like `void`
  - more complex rules for ptrs and refs
  - usually drops `const` from the deduced type, so add `const` yourself if desired
  - `constexpr` is implicitly const, so re-add if desired
  - use when the type of the object doesn't matter, favour explicit types when it differs from the initializer
- type deduction for fns (with `auto`, from C++14)
  - all return statements must return values of the same type
    - prevents mismatched return types that could result in unexpected conversions
  - fns with `auto` return type must be fully defined before usage, not just forward declared; normally only callable from the same file
  - prefer explicit return types
  - trailing return type syntax: e.g. `auto compare(int, double) -> std::common_type<int, double>;`
    - helpful for readability and aligning consecutive fn declarations, and for return types deduced based on the type of fn params
  - type deduction can't be used for fn param types; in C++20, using `auto` for params actually uses function templates, a different feature