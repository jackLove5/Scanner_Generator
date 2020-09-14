# Scanner Generator

This program generates code for a lexical analyzer (similar to lex/flex).
The user provides a list of regex/syntactic category pairs, and the program outpts code for a C++ class that implements the specified lexer.

Specifically, the program outputs a direct coded, maximal-munch lexer.

This project was inspired by chapters 2 and 3 of "Engineering a Compiler" (Cooper, Torczon). These chapters present common algorithms/techniques used in front end compiler applications.

This project is in an unfinished but usable state. I plan to spend the next semester or so working on improving the application's usability.

Many of the challenges I ran into were related to design. Some refactoring may be appropriate. All FSM classes are concrete implementations and depend on certain behaviors, so we could probably extract some sort of interface or create an inheritance relationship.

Fortunately the project can be divided into several distinct pieces which made debugging easy. Also, the textbook provided psuedocode for most of the important algorithms which left little room for logic errors.

Much of the program's runtime is spent minimizing the DFA which, in hindsight, is a bit silly because minimizing the DFA does not result in a more efficient scanner. It only minimzes the number of states in the DFA and thus the amount of code that gets generated.

All in all, I've really enjoyed the time I've spent on this project. This is by far the most technical project I've worked on, but the subject interested me, so I never got bored. I think compilers are a super interesting field of study because they combine a lot of different areas of Computer Science that I think are cool. In the future, I would definitely like to continue making small compiler projects in my free time.
