**The debugging process**
1. find the root cause
2. understand why the issue is occurring
3. determine a fix
4. repair the issue
5. retest to ensure the problem is fixed and there are no new problems

**finding where the error is**
- strategy: code inspection 
- strategy: run the program 
- reproduce the problem, and write down the steps
- print debugging
  - comment out code
  - validate code flow by printing function calls (use `std:cerr`, which is unbuffered)
  - print values
  - can enable/disable debugging with preprocessor directives (`#ifdef ENABLE_DEBUG`)
  - can send debugging info to a logger (plog, spdlog, etc.)
- integrated debugger
  - CLI (gdb), GUI (turbo), integrated (IDE)
  - debug config, add breakpoint, add debugger
  - "step into": move to the current function call if it exists, otherwise go to the next line
  - "step over": move to the next line without entering any function calls on the current line
  - "step out": continue execution until exiting the current function (useful for skipping library calls)
  - `std::cout` is buffered, so it may not print immediately.
    - `std::cout << std::unitbuf;` to enable auto flushing for debugging, remove after debugging
  - run to cursor, continue, start, breakpoints, set next
  - watching variables
  - **call stack**: the list of all active functions called to get to the current point of execution

**finding issues before they become problems**
- follow best practices
- don't code when tired or frustrated
- understand common language pitfalls
- prefer using the standard lib to writing your own code
- don't let fns get too long (<= 10 lines, <5 if possible)
- comment liberally
- start with simple solutions, then add complexity incrementally
- avoid clever/non-obvious solutions
- optimize for maintainability, not performance


- **defensive programming**: attempting to anticipate all the ways the software can be misused (input validation)
- test after coding a bit
- unit testing
- constraints with `assert` and `static_assert`
- static analysis tools (linters) (clang-tidy, cpplint, etc.)