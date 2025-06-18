---
# Push Swap
A C implementation of the sorting algorithm that sorts integers using two stacks and a limited set of operations.

## Description

 * This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you'll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimize data sorting. This sorting algorithm project where you must sort a stack of integers using a minimal set of operations. You write two programs:


1. **push_swap** – calculates and prints the list of operations to sort the given numbers.
2. **checker** – reads a list of operations and verifies whether they sort the stack correctly.



## Table of Contents
- [Description](#description)
- [Algorithm Overview](#algorithm-overview)
- [Available Operations](#available-operations)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Implementation Details](#implementation-details)
- [Performance](#performance)

## Description

Push Swap is a sorting algorithm project that takes a list of integers and sorts them using two stacks (stack A and stack B) with a restricted set of operations. The goal is to sort the numbers in ascending order in stack A using the minimum number of operations possible.

This implementation uses different sorting strategies based on the input size:
- **2-3 elements**: Hardcoded optimal solutions
- **4-5 elements**: Optimized algorithms using both stacks
- **Larger sets**: Radix sort with chunk-based optimization

## Algorithm Overview

The program employs a hybrid approach:

1. **Small Arrays (2-5 elements)**: Uses predefined optimal sorting sequences
2. **Large Arrays (6+ elements)**: Uses a modified radix sort algorithm with chunking
3. **Index Assignment**: Elements are assigned indices based on their relative values
4. **Chunk Processing**: Elements are divided into chunks for efficient processing

## Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element at the top of B to A |
| `pb` | Push the first element at the top of A to B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## Installation

```bash
# Clone the repository
git clone <repository-url>
cd push_swap

# Compile the project
make

# Or compile manually
gcc -Wall -Wextra -Werror *.c libft/*.c -o push_swap
```

## Usage

```bash
./push_swap [numbers...]
```

### Input Methods

1. **Multiple arguments**: `./push_swap 3 2 1 4 5` 
ARG="3 2 1 4 5"
./push_swap $ARG
2. **Single quoted string**: `./push_swap "3 2 1 4"`
3. **Mixed format**: `./push_swap 3 "2 1" 4`

### Input Validation

The program validates input and exits with "Error\n" if:
- Arguments contain non-numeric characters
- Numbers are outside the range of 32-bit integers (INT_MIN to INT_MAX)
- Duplicate numbers are provided
- Invalid format (empty arguments, only signs, etc.)

## Examples

```bash
# Sort 3 numbers
./push_swap 2 1 3
# Output: sa

# Sort 5 numbers
./push_swap 5 4 3 2 1
# Output: pb pb ra pb ra sa pa pa ra pa ra

# Already sorted (no output)
./push_swap 1 2 3 4 5

# With negative numbers
./push_swap -01 000 0001
# Output: (appropriate operations)

# Using quoted strings
./push_swap "42 -17 0 3"
```

## Project Structure

```
push_swap/
├── main.c                  # Main program entry point
├── pushswap.h             # Header file with all declarations
├── validation.c           # Input validation functions
├── init_stack.c          # Stack initialization
├── utils.c               # Utility functions (memory management, etc.)
├── set_index.c           # Index assignment and atoi validation
├── sort_stack.c          # Main sorting algorithm (radix sort)
├── sort_little_stack.c   # Optimized sorting for small arrays
├── sort_utils.c          # Sorting utility functions
├── swap_operations.c     # Swap operations (sa, sb, ss)
├── push_operations.c     # Push operations (pa, pb)
├── rotate_operations.c   # Rotate operations (ra, rb, rr)
├── rr_operations.c       # Reverse rotate operations (rra, rrb, rrr)
└── libft/                # Custom C library
    ├── libft.h
    ├── ft_atoi.c
    └── [other libft functions]
```

## Implementation Details

### Data Structures

```c
typedef struct s_node {
    int             val;     // Original value
    int             index;   // Relative position in sorted order
    struct s_node   *next;   // Next node in stack
} t_node;

typedef struct s_stack {
    t_node  *a;  // Stack A
    t_node  *b;  // Stack B
} t_stack;
```

### Sorting Strategies

1. **Size 2**: Simple comparison and swap if needed
2. **Size 3**: All 6 possible combinations handled explicitly
3. **Size 4-5**: Move smallest elements to stack B, sort remaining, push back
4. **Size 6+**: Radix sort with chunk optimization

### Index Assignment

Before sorting, each element is assigned an index representing its position in the final sorted array. This allows the algorithm to work with relative positions rather than absolute values.

### Chunk-Based Radix Sort

For larger arrays, the algorithm:
1. Calculates optimal chunk size based on array length
2. Moves elements to stack B in chunks based on their indices
3. Sorts stack B in descending order
4. Pushes elements back to stack A

## Performance

The algorithm aims to minimize the number of operations:

- **Size 3**: At most 2 operations
- **Size 5**: At most 12 operations  
- **Size 100**: Typically under 700 operations
- **Size 500**: Typically under 5500 operations

## Error Handling

The program handles various error conditions:
- Invalid numeric input
- Integer overflow/underflow
- Duplicate values
- Empty or malformed arguments

All errors result in "Error\n" being printed to stderr and program termination.

## Memory Management

The program properly manages memory allocation and deallocation:
- All dynamically allocated structures are freed
- No memory leaks in normal operation
- Proper cleanup on error conditions
