
## 🔄 Push_Swap

A optimized sorting algorithm project for the **42 Curriculum**


## 📌 Overview

**Push_swap** is an algorithmic project where the goal is simple yet challenging: sort a random set of integers using **two stacks (`A` and `B`)** and a **strictly limited set of operations**, minimizing the total number of moves.

- **Stack A**: Starts with a list of unsorted numbers and must end up sorted in ascending order.
- **Stack B**: Starts completely empty and is used as an auxiliary workspace.

---

## 🕹️ Allowed Operations

| Move | Description |
| :--- | :--- |
| **`sa`** / **`sb`** / **`ss`** | **Swap**: Swap the first 2 elements at the top of stack A, B, or both. |
| **`pa`** / **`pb`** | **Push**: Take the top element of one stack and push it onto the top of the other. |
| **`ra`** / **`rb`** / **`rr`** | **Rotate**: Shift all elements up by 1 position (first becomes last). |
| **`rra`** / **`rrb`** / **`rrr`** | **Reverse Rotate**: Shift all elements down by 1 position (last becomes first). |

---

## 🧠 Algorithm & Technical Choices

### 1. Data Structure: Doubly Linked List 🔗
- Each node stores its raw `value`, its normalized `index`, and pointers to `next` and `prev`.
- A dedicated stack structure tracks `top`, `bottom`, and total `size`, allowing fast $O(1)$ stack operations from both ends.

### 2. Pre-processing: Index Normalization 🔢
- Before sorting, all numbers are mapped to clean indices `0` through `N - 1`.
- This removes the complexity of working with negative values or extreme integer boundaries during calculations.

### 3. Small Sorts ($\le 5$ numbers) 🎯
- **2 & 3 elements**: Hardcoded decision tree solving permutations in $\le 3$ moves.
- **4 & 5 elements**: Identifies and pushes the smallest values to Stack B, sorts the remaining 3 in Stack A, and pushes them back.

### 4. Big Sort: Optimized Chunking Strategy (100 & 500 numbers) 🚀

The large sorting algorithm is divided into two distinct, highly optimized phases:

#### 🔹 Phase 1: Push to Stack B (Chunk Sorting)
- Elements are transferred in dynamic **chunks** (e.g., chunk size of **65** for 500 numbers).
- **Smart Rotation (`rb`) Optimization**: When an element is pushed to B, if its index is in the lower half of the chunk, Stack B is immediately rotated (`rb`). This splits each chunk into two separate tiers inside Stack B, halving search costs later on.
- **Greedy Direction Cost**: Evaluates whether rotating from the top (`ra`) or reverse-rotating from the bottom (`rra`) requires fewer moves, pairing rotation commands (`rr`) where possible.

#### 🔹 Phase 2: Push Back to Stack A (Cost Calculation)
- Locates the largest remaining elements in Stack B.
- Evaluates the shortest rotational path to bring them to the top (using `rb` vs `rrb`).
- Utilizes smart lookahead (`sort_hun_helper`): if the next target element is just underneath the top, an immediate `sb` or swap-and-push is performed to eliminate unnecessary full stack rotations.

---

## 🛠️ Features

- ⚡ **High Efficiency**: Consistently scores 100/100 (100 numbers in $< 700$ moves, 500 numbers in $< 5,500$ moves).
- 🛡️ **Robust Parsing**: Accepts both separated arguments (`./push_swap 3 2 1`) and formatted strings (`./push_swap "3 2 1"`).
- 🚨 **Strict Error Handling**: Validates duplicate numbers, non-numeric characters, and values outside 32-bit `[INT_MIN, INT_MAX]`. Prints `Error\n` to `stderr` and exits gracefully.
- 🧹 **Zero Memory Leaks**: Cleanly frees all allocations (stacks, nodes, and split strings) on both successful exit and error paths.
- 📏 **Norminette Compliant**: Meets all 42 Norm standards.

---

## 💻 Compilation & Usage

### Compilation
The project includes a standard `Makefile`:

```bash
make        # Compiles the push_swap executable
make clean  # Removes object files (.o)
make fclean # Removes object files and push_swap binary
make re     # Cleans and recompiles everything
```

### Execution

```bash
# Example 1: Multiple arguments
./push_swap 4 67 3 87 23

# Example 2: String argument
./push_swap "4 67 3 87 23"
```

---

## 🧪 Testing with Checker

Verify sorting correctness by piping `push_swap` into the 42 checker:

```bash
# Give execution permissions to the checker
chmod +x checker_linux

# Test random numbers and check output
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

To count operations:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

---

## 🤖 AI Usage Disclosure

In compliance with 42 guidelines, an AI assistant was utilized as a pair-programming partner for:
- **Algorithmic Fine-Tuning**: Brainstorming micro-optimizations (chunk threshold tuning and paired rotation logic) to stay comfortably under the 5,500 move threshold.
- **Norminette Refactoring**: Designing helper structs (`t_chunk`) and modular helpers to cleanly satisfy the 4-parameter and 25-line limits.
- **Documentation**: Structuring and styling this `README.md`.

---

## 📚 References & Resources

- [The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — Jamie Dawson
- [Push Swap in less than 4200 operations](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0) — Ulysse GKS
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) — Interactive visual debugging tool
```
