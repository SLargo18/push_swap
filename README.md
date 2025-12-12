# ♻️ push_swap

## 📌 Description

`push_swap` is an algorithmic project that sorts a stack of integers using a limited set of operations on two stacks. The goal is to sort the data with the smallest possible number of instructions.

This project challenges your skills in algorithm design, data structure manipulation, and optimization under strict constraints, using only the C programming language.

---

## 🛠️ Skills Developed

- Custom sorting algorithms
- Linked list and stack implementation
- Input parsing and validation
- Optimization of operations
- Memory management in C
- Complexity analysis and performance tuning

---

## 🧠 Allowed Operations

- `sa`, `sb`, `ss` – swap top elements
- `pa`, `pb` – push from one stack to another
- `ra`, `rb`, `rr` – rotate
- `rra`, `rrb`, `rrr` – reverse rotate

---

## ⚙️ Compilation

```bash
make


*This project has been created as part of the 42 curriculum by salargo-.*

# push_swap

## Description
`push_swap` is an algorithmic project whose goal is to sort a stack of integers using a limited set of operations applied on two stacks (A and B). The challenge is to output a sequence of instructions that sorts the numbers using the fewest possible moves, following strict operational constraints, and implementing all logic in C. This project evaluates algorithmic thinking, data structure manipulation, memory management, and performance optimization.

## Instructions

### Compilation
This project provides a Makefile with the following commands:

- `make` — compiles the program and generates the `push_swap` executable
- `make clean` — removes all object files
- `make fclean` — removes object files and the executable
- `make re` — performs a full rebuild
- `make debug` — compiles with debug flags (`-g3 -fsanitize=address`)
- `make test` — runs basic tests
- `make test-performance` — performance test with 100 random numbers
- `make test-500` — performance test with 500 random numbers
- `make help` — shows all available Makefile commands

Compilation settings:  
- Compiler: `cc`
- Flags: `-Wall -Wextra -Werror`
- Includes: `-I./include`

### Execution
Run the program by passing a list of integers as arguments:  
`./push_swap <list_of_numbers>`

Example:  
`./push_swap 3 2 1`

The program will output the sequence of allowed operations needed to sort the input numbers.

## Resources
Classic references used for this project include:
- System documentation: `man malloc`, `man free`, `man write`, `man exit`
- Algorithm references: radix sort, quicksort principles, k_sort method
- Documentation on stacks, linked lists, and data structures
- The official push_swap subject PDF from the 42 curriculum
 

## AI Usage
AI was used only to clarify algorithmic concepts, understand complexity behavior, and improve the clarity and structure of this README. All implementation, debugging, and logic were written manually by the author. No AI-generated code was used.

