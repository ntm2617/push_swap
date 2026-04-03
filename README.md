This project has been created as part of the 42 curriculum by nkarnpan

**Description**:
Goal -> The primary objective of the push_swap project is to sort data on a stack, with a strictly limited set of operations, using the absolute lowest possible number of actions. It serves as an intensive exercise in algorithmic logic, optimization, and data structure management within the 42 curriculum.

Overview -> The program takes a random list of unsorted integers and places them into "Stack A," while "Stack B" begins empty. To sort the numbers in ascending order within Stack A, you must calculate and execute a highly optimized sequence of specific commands. The allowed moves are limited to:
	Swap: Exchange the top two elements of a stack.
	Push: Move the top element from one stack to the other.
	Rotate: Shift all elements in a stack up or down by one position.
**Allowed Moves:** sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

-------------------------------------------
**Instructions**:
### Compilation
This project includes a standard `Makefile`. To compile the program, open terminal in the root directory of the repository and run: make
Additional Makefile rules:
- make clean: Removes all object (.o) files.
- make fclean: Removes object files and the push_swap executable.
- make re: Fully recompiles the project from scratch.

### Execution
Example 1: Separate arguments 
	./push_swap 4 67 3 87 23
Example 2: Single string argument
	./push_swap "4 67 3 87 23"
**The program will output a list of instructions (e.g., pb, ra, sa, rr) line by line. If the input is invalid (contains duplicates, non-integer characters, or numbers larger than an integer), the program will print Error to the standard error output

### Testing with the Checker
	Verifying the accuracy of your sorting algorithm by piping the output of push_swap into the provided OS checker program (checker_linux).
- Ensure the checker has execution permissions: chmod +x checker_linux
- Run the programs together using a variable: ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

-------------------------------------------
**Resources**:
### references
- [The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Push Swap in less than 4200 operations](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0)
- [Visualizer](https://github.com/o-reo/push_swap_visualizer)

### AI Usage
During the development of this project, an AI assistant (Google Gemini) was used as an interactive tutor and debugging partner. The AI was explicitly used for the following tasks:
- Algorithm Micro-Optimizations: Brainstorming logic to shave off final moves to beat the 5500 limit. This included implementing "True Cost" pathfinding, finding the optimal chunk size (65), and developing the `sb` and `sa` "rescue tricks" to save Phase 2 rotations.
- Debugging Memory Errors: Identifying and resolving specific C segmentation faults, such as uninitialized struct pointers and `NULL` pointer dereferencing when evaluating empty stacks (`b->top != NULL`).
- Norminette Refactoring: Restructuring functions to adhere strictly to the 42 Norminette. The AI helped conceptualize how to use `t_chunk` struct pointers and helper functions to bypass the 4-parameter and 25-line limits without breaking the core logic.
- Documentation: Assisting in structuring and formatting this `README.md` file.