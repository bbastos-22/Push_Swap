*This project has been created as part of the 42 curriculum by bbastos-.*

## Description

Push Swap is a 42 School project that challenges the implementation of a sorting algorithm under operational constraints. The objective is to sort a list of random integers using two stacks (A and B) and a limited set of operations, while minimizing the total number of instructions emitted.

### Goal
- Sort any sequence of integers in ascending order on stack A
- Use only allowed stack operations (swap, push, rotate, reverse rotate)
- Minimize the number of operations for efficiency
- Handle edge cases and validate input strictly

### Overview
The solution implements a hybrid sorting strategy:
- **Small inputs (≤5)**: Dedicated low-cost sorting routines
- **Large inputs (>5)**: Chunk-based algorithm that partitions elements by rank and transfers them between stacks, then reinserts them in optimal order

The project covers essential topics in computer science: algorithm design, data structures (linked lists), performance optimization, and handling strict style constraints (Norminette compliance).

## Instructions

### Compilation

```bash
make           # Compile the project
make re        # Recompile from scratch
make clean     # Remove object files
make fclean    # Remove all generated files
```

### Execution

```bash
./push_swap <number1> <number2> <number3> ...
```

**Example:**
```bash
./push_swap 3 2 1 0 4
./push_swap 5 3 1 2 4 6
```

The program outputs a sequence of operations that sort the input. Pipe the output to `checker_linux` to validate:

```bash
./push_swap 3 2 1 0 4 | ./checker_linux 3 2 1 0 4
```

Expected output: `OK` (if sorted correctly)

### Input Requirements
- Integer values between INT_MIN (-2147483648) and INT_MAX (2147483647)
- No duplicate values allowed
- Valid number format (optional +/- sign followed by digits)
- Minimum 1 argument required

### Input Validation
The program explicitly rejects:
- Non-integer arguments
- Values outside the int32 range
- Duplicate values
- Empty argument lists

Error output: `Error\n` (written to standard error)

### Allowed Operations

| Operation | Notation | Effect |
|-----------|----------|--------|
| Swap A    | `sa`     | Swap first two elements of stack A |
| Swap B    | `sb`     | Swap first two elements of stack B |
| Swap both | `ss`     | Perform `sa` and `sb` simultaneously |
| Push A    | `pa`     | Move top of B to top of A |
| Push B    | `pb`     | Move top of A to top of B |
| Rotate A  | `ra`     | Top of A goes to bottom of A |
| Rotate B  | `rb`     | Top of B goes to bottom of B |
| Rotate both | `rr`   | Perform `ra` and `rb` simultaneously |
| Rev Rot A | `rra`    | Bottom of A goes to top of A |
| Rev Rot B | `rrb`    | Bottom of B goes to top of B |
| Rev Rot both | `rrr` | Perform `rra` and `rrb` simultaneously |

### Project Structure

```
.
├── Makefile                 # Build configuration
├── includes/
│   └── push_swap.h         # Main header with prototypes
├── libs/
│   ├── Libft/              # Custom C library
│   └── Printf/             # Custom printf clone
├── srcs/
│   └── main.c              # Entry point, parsing, cleanup
├── ops/                    # Stack operations
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   └── reverse_rotate.c
├── algorithm/              # Sorting strategies
│   ├── sort.c              # Dispatcher and small sorts
│   ├── sort_helpers.c      # Helpers for 3 and 5 element sorts
│   └── sort_large_helpers.c # Chunk-based large sort
├── utils/                  # Utilities
│   ├── parse.c             # Input validation
│   ├── stack_utils.c       # Stack initialization and checks
│   ├── stack_helpers.c     # Rank and position utilities
│   └── free.c              # Memory deallocation
└── README.md               # This file
```

## Resources

### Sorting Algorithms
- [Sorting Algorithm Visualization](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html) - Interactive tool to understand algorithm behavior
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) - Time and space complexity reference

### Data Structures
- [Linked Lists in C](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm) - Comprehensive guide to linked list implementation
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) - Stack operations and use cases

### Push Swap Specific
- [42 Intra Push Swap](https://intra.42.fr/projects/push_swap) - Official project description
- [Push Swap Visualizer](https://push-swap-visualizer.herokuapp.com/) - Debug tool to visualize operations (or local version)

### Algorithm Optimization
- [Chunk-Based Sorting](https://en.wikipedia.org/wiki/Bucket_sort) - Related concept to partitioning strategy
- [Greedy Algorithms](https://www.geeksforgeeks.org/greedy-algorithms/) - Foundation for cost-based decision making

---

## AI Usage

**GitHub Copilot** was used throughout this project for:

### Testing & Validation
- **Test Case Generation**: Running automated 300+ iterations with random inputs to isolate edge cases
- **Benchmark Setup**: Building batch test loops to measure performance across different input sizes
- **Error Diagnosis**: Comparing tester output with checker results to distinguish algorithm correctness from visualization issues

### Documentation
- **README & Reports**: Generating comprehensive project documentation including algorithm overview, usage examples, and technical architecture

---

## Performance Metrics

Typical operation counts (measured on random inputs):
- **100 elements**: ~900-1000 operations (target: ≤1500, bonus: ≤800)
- **500 elements**: ~6000-6500 operations (target: ≤7000, bonus: ≤5500)

Performance depends on:
- Input permutation
- Chunk size tuning
- Rotation direction selection during chunk transfer phase

---

## Testing

Run tests with the provided checker:

```bash
# Single test
./push_swap 2 1 0 | ./checker_linux 2 1 0

# Batch test with 100 random numbers
ARGS="$(shuf -i 0-99 -n 100 | tr '\n' ' ')" && ./push_swap $ARGS | ./checker_linux $ARGS

# Batch test with 500 random numbers
ARGS="$(shuf -i 0-499 -n 500 | tr '\n' ' ')" && ./push_swap $ARGS | ./checker_linux $ARGS
```

---

## Author
- **bbastos-** - 42 School student

---

## License
This project is part of the 42 School curriculum. All rights reserved.
