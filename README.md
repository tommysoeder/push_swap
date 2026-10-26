# push_swap

`push_swap` is a 42 project written in C. Its goal is to sort a sequence of unique integers using two stacks and a restricted instruction set, while printing the operations needed to reach ascending order.

The final program is located in **[`Push_swap/Proyecto/`](Push_swap/Proyecto/)**. The other files under `Push_swap/` are course material, study notes, standalone exercises, and previously compiled learning binaries; they are not part of the final executable.

## The problem

The program starts with:

- stack **A**, containing the input integers in the order provided;
- stack **B**, initially empty.

It must leave stack A sorted from smallest at the top to largest at the bottom, with stack B empty. Instead of printing the sorted values, the program writes one valid stack operation per line.

For example:

```bash
./push_swap 3 2 1
```

produces:

```text
sa
rra
```

## Final implementation

The executable is built exclusively from the sources listed in `Push_swap/Proyecto/Makefile`.

```text
Push_swap/Proyecto/
├── Makefile
├── include/push_swap.h
├── src/                  # Final parser, stacks, operations, and sorting code
├── checker_linux         # Precompiled external testing utility
├── checker_Mac           # Precompiled external testing utility
├── count_moves.sh        # Prints an operation count and sequence
├── test_one.sh           # Checks one supplied input
├── test_random.sh        # Runs randomized correctness checks
└── stress_random.sh      # Checks randomized inputs and tracks the largest count
```

At the wider repository level:

```text
Push_swap/
├── Proyecto/             # Final push_swap program
├── *.pdf                 # Subject and personal study notes
├── ejercicios*.c        # Learning exercises
├── pruebas*.c            # Standalone experiments
├── a.out                 # Auxiliary compiled file
└── listas.out            # Auxiliary compiled file
```

The PDFs, exercises, experiments, and auxiliary executables are not linked into `push_swap`.

## Data structures

Each stack is implemented as a doubly linked list:

- `t_node` stores an integer plus `next` and `prev` links.
- `t_stack` stores pointers to the top and bottom nodes and tracks its size.

This design supports removing or inserting nodes at either end without reallocating their values. The shared internal primitives implement swap, push, rotate, and reverse rotate by relinking existing nodes.

## Available operations

| Operation | Effect |
| --- | --- |
| `sa` | Swap the first two elements of stack A. |
| `sb` | Swap the first two elements of stack B. |
| `ss` | Perform `sa` and `sb` together. |
| `pa` | Move the top element of B to the top of A. |
| `pb` | Move the top element of A to the top of B. |
| `ra` | Move the top element of A to its bottom. |
| `rb` | Move the top element of B to its bottom. |
| `rr` | Perform `ra` and `rb` together. |
| `rra` | Move the bottom element of A to its top. |
| `rrb` | Move the bottom element of B to its top. |
| `rrr` | Perform `rra` and `rrb` together. |

All eleven operations are implemented, although the current sorting paths use only the subset needed by each strategy.

## Sorting strategy

The program first checks whether stack A is already sorted. If it is, it exits without printing operations.

### Small inputs

- **Two values:** swaps them when necessary.
- **Three values:** selects a fixed combination of swap, rotate, and reverse rotate for each ordering.
- **Four values:** moves the minimum to B, sorts the remaining three, and pushes the minimum back to A.
- **Five values:** moves the two smallest values to B, sorts the remaining three, arranges B when needed, and restores both values to A.

When moving a minimum to the top, the implementation chooses forward rotation or reverse rotation according to its position in the stack.

### Larger inputs

Inputs with more than five values use binary least-significant-digit radix sorting:

1. Copy the stack values into an array.
2. Sort that array with selection sort.
3. Replace every stack value with its zero-based rank in the sorted array. This index compression converts negative and widely spaced integers into the range `0..n-1`.
4. Process the compressed values one bit at a time, from least significant to most significant.
5. For each bit, push zero-bit values to B with `pb` and rotate one-bit values in A with `ra`.
6. Restore every value from B to A with `pa` before processing the next bit.

The radix phase generates `O(n log n)` stack operations for `n` values. The current rank-building stage uses selection sort and a linear rank lookup, so its in-memory preprocessing time is `O(n²)`.

## Input validation

Arguments may be supplied separately or as whitespace-separated strings:

```bash
./push_swap 4 2 1 3
./push_swap "4 2 1 3"
./push_swap "4 2" "1 3"
```

The parser:

- accepts optional leading `+` or `-` signs;
- requires every remaining character to be a decimal digit;
- rejects empty or whitespace-only arguments;
- rejects values outside the signed 32-bit `int` range;
- rejects duplicate values across all arguments.

Invalid input writes `Error` to standard error and exits with status 1. Running the program without values exits normally without output.

## Build

Requirements:

- a C compiler available as `cc`;
- GNU Make;
- a Unix-like environment for the bundled test scripts.

Clone the repository, enter the final project directory, and compile:

```bash
git clone https://github.com/tommysoeder/push_swap.git
cd push_swap/Push_swap/Proyecto
make
```

The Makefile builds with `-Wall -Wextra -Werror` and creates `./push_swap`.

Available targets:

```bash
make          # Build push_swap
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Rebuild from scratch
```

## Usage

Run the program with a list of unique integers:

```bash
./push_swap 8 -3 5 1 0
```

Count the generated operations:

```bash
./push_swap 8 -3 5 1 0 | wc -l
```

Check the result with the included Linux checker:

```bash
./push_swap 8 -3 5 1 0 | ./checker_linux 8 -3 5 1 0
```

A correct sequence produces:

```text
OK
```

The helper scripts must also be run from `Push_swap/Proyecto/` because they use relative paths to `push_swap` and the checker.

```bash
sh test_one.sh 3 2 1
sh test_random.sh 100 10
sh stress_random.sh 100 10
sh count_moves.sh 5 4 3 2 1
```

The randomized scripts additionally require common Unix tools such as `seq`, `shuf`, `wc`, and `tee`.

## Concepts practised

- Linked data structures and pointer manipulation.
- Stack invariants and constant-time endpoint operations.
- Strict parsing and integer-bound validation.
- Duplicate detection and error paths.
- Specialized sorting for small inputs.
- Coordinate compression and bitwise radix sorting.
- Algorithmic complexity and operation-count tradeoffs.
- Memory allocation, ownership, and cleanup.
- Makefiles, compiler warnings, shell pipelines, and test helpers.

## Current limitations

- There is no bonus checker implementation or checker build target. `checker_linux` and `checker_Mac` are precompiled testing utilities; their source is not present in this repository.
- The final algorithm uses binary radix sorting for every input larger than five. It does not implement chunk-based, longest-increasing-subsequence, or cost-based optimizations.
- Index compression and duplicate detection use quadratic-time passes, which are adequate for the project-sized inputs but are not designed for very large datasets.
- The repository has no automated Makefile test target; validation is provided through shell scripts and the precompiled checker binaries.
- `src/run_sort.c` contains an alternative dispatcher but is not listed in the Makefile. The compiled program uses the private dispatcher defined in `src/main.c`.

## Author

Created by [tommysoeder](https://github.com/tommysoeder) as part of the 42 curriculum.

AI tools were used to review the repository and improve this documentation. The implementation details described here were verified against the source code and build configuration; this statement does not attribute AI use to code where the repository provides no such record.
