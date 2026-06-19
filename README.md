# push_swap

> Sort a stack of integers using two stacks and a limited set of operations — with the fewest moves possible.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![School](https://img.shields.io/badge/school-42%20Heilbronn-black.svg)
![Norm](https://img.shields.io/badge/norminette-passing-brightgreen.svg)

---

## About

**push_swap** is a sorting algorithm project. Given a stack of integers (stack **A**), the program outputs the minimal sequence of operations needed to sort it in ascending order using only a second auxiliary stack (stack **B**) and a restricted instruction set.

---

## Operations

| Instruction | Description |
|---|---|
| `sa` | Swap the top two elements of stack A |
| `sb` | Swap the top two elements of stack B |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A upward (top becomes bottom) |
| `rb` | Rotate stack B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (bottom becomes top) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Usage

### Build

```bash
make
```

### Run

```bash
./push_swap 3 1 4 1 5 9 2 6
```

Output (example):
```
pb
pb
sa
pa
pa
...
```

Both argument styles are supported:
```bash
./push_swap 3 2 1
./push_swap "3 2 1"
```

### Validate with a checker

```bash
ARG="3 1 4 1 5 9 2 6"
./push_swap $ARG | ./checker $ARG
```

Expected output: `OK`

### Error handling

The program writes `Error` to stderr and exits on:
- Non-integer arguments
- Integers outside the `INT` range
- Duplicate values
- Empty input

---

## Algorithm

The sorting uses a **three-pass chunking strategy** based on value range pivots.

**Step 1 — Compute pivots**

From the min and max values in stack A, three pivot points are derived:
```
mid     = (max + min) / 2
premid  = (mid + min) / 2
postmid = (mid + max) / 2
```

**Step 2 — Three passes from A to B**

Elements are pushed from A to B in three successive passes, each using a different upper-bound threshold:

1. Push elements below `mid` (using `premid` as the B-ordering check)
2. Push elements below `postmid` (keeping B roughly ordered)
3. Push remaining elements until only 3 remain in A

In each pass, `first_pour` decides the cheapest move: push directly, rotate A, rotate both, or reverse rotate A — depending on where the smallest eligible element currently sits (top, second, or bottom of A).

**Step 3 — Sort the 3 remaining elements in A**

`sort_stack_a` handles the base case of 3 elements with at most 2 operations by moving the largest to the bottom.

**Step 4 — Pour B back into A**

`pour_back_from_stack_b` inserts each element from B back into its correct position in A, rotating A forward or backward to find the right slot. `arange_stack_b` pre-sorts the top of B before each insertion to minimise rotations.

**Step 5 — Final alignment**

A tail `rra` loop corrects the rotation offset if the sorted sequence isn't yet at the top.

---

## Structure

```
push_swap/
├── push_swap.h     # Structs, prototypes, includes
├── push_swap.c     # Entry point, argument parsing, ft_atoi, free_n_exit
├── sort_stack.c    # Main sort logic: pivots, passes, sort_stack_a, if_sorted
├── first_pour.c    # Per-element decision logic for A→B and B→A transfers
├── operations.c    # All stack operations: swap, push, rotate, reverse_rotate
├── lists.c         # Linked list utilities: lstnew, lstadd_back, lstsize, etc.
├── ft_split.c      # Parses single-string input into a stack
├── ft_printf.c     # Minimal printf for operation output
└── free_split.c    # Frees the split result after parsing
```

---

## Makefile Targets

| Target | Description |
|---|---|
| `make` / `make all` | Build `push_swap` binary |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and binary |
| `make re` | `fclean` + `all` |

---

## Notes

- The stack is implemented as a **singly linked list** (`t_list`).
- Integer overflow is caught by parsing with `long int` and comparing against `INT_MAX` / `INT_MIN`.
- The program outputs nothing if the input is already sorted.
- Written in compliance with the **42 Norm**.

---

*42 Heilbronn — Core Curriculum*
