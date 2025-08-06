
# 🔄 Push_swap - My First Sorting Algorithm Project

![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-100%2F100-success?style=flat-square)

## 📖 About The Project

Push_swap the first major algorithm project at 42 School! 🎉 The goal is to sort a stack of integers using the smallest number of operations possible, with only two stacks and a limited set of operations.

This project taught me so much about:
- **Algorithm optimization** 🧠
- **Data structures** (stacks)
- **Memory management** in C

## 🎯 The Challenge

Given a stack A with random integers and an empty stack B, sort stack A in ascending order using these operations:

### Stack Operations
- `sa` - swap first 2 elements of stack A  
- `sb` - swap first 2 elements of stack B  
- `ss` - sa and sb at the same time  
- `pa` - push first element of B to A  
- `pb` - push first element of A to B  
- `ra` - rotate stack A (first element becomes last)  
- `rb` - rotate stack B  
- `rr` - ra and rb at the same time  
- `rra` - reverse rotate A (last element becomes first)  
- `rrb` - reverse rotate B  
- `rrr` - rra and rrb at the same time  

## 🛠️ Installation & Setup

### Clone the repository
```bash
git clone https://github.com/alakhida/push_swap.git
cd push_swap
```

### Compilation
```bash
make
```

### Running the program
```bash
# Basic usage
./push_swap 4 67 3 87 23

# With negative numbers
./push_swap -1 2 -3 4 5

# Check if it's sorted correctly
./push_swap 4 67 3 87 23
```

### Testing
```bash
# Test with random numbers
ARG=$(seq 100 1 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test 100 numbers (should be under 700 operations)
./push_swap $(seq 1 100 | shuf | tr '\n' ' ') | wc -l

# Test 500 numbers (should be under 5500 operations)
./push_swap $(seq 1 500 | shuf | tr '\n' ' ') | wc -l
```

## 🧮 My Algorithm Strategy

After lots of research and testing, I implemented different strategies based on stack size:

### Small Stacks (2-3 elements)
- 2 elements: Simple swap if needed  
- 3 elements: Hardcoded optimal moves (max 2 operations)

### Medium Stacks (4-5 elements)
- Push smallest elements to stack B  
- Sort remaining 3 in stack A  
- Push back from B to A

### Large Stacks (100+ elements)
- Radix Sort approach for 100 elements  
- Chunk-based sorting for 500+ elements  
- Divide numbers into chunks and sort systematically  

## 🔧 Key Functions

### Input Validation
- `is_valid_inputs()` - Main validation function  
- `check_double()` - Checks for duplicate numbers  
- `check_int_range()` - Validates integer overflow  
- `check_char()` - Validates character input  

### Sorting Logic
- `sort()` - Main sorting dispatcher  
- `decide_case()` - Chooses algorithm based on stack size  
- `sort_three_numbers()` - Optimized 3-element sort  
- `four_fifth_case()` - Handles 4-5 elements  

### Stack Operations
- `push_stack()` - Push operation  
- `rotate()` - Rotate operation  
- `reverse_rotate()` - Reverse rotate operation  
- `swap()` - Swap operation  

## 📊 Performance Results

| Elements       | Moves Used     | Requirement        | ✅ |
|----------------|----------------|--------------------|----|
| 3 elements     | 2 moves        | ≤ 3 moves          | ✅ |
| 5 elements     | 8 moves        | ≤ 12 moves         | ✅ |
| 100 elements   | ~650 moves     | < 700 moves        | ✅ |
| 500 elements   | ~4800 moves    | < 5500 moves       | ✅ |

### Algorithm Optimization 🎯
- First attempt was too slow for large numbers  
- Had to research and implement better sorting strategies  
- Spent countless hours optimizing move counts  

### Edge Cases 🔍
- Empty input, single numbers, already sorted arrays  
- Negative numbers and integer overflow  
- Duplicate numbers validation  

### Code Organization 📚
- Started with everything in one file (bad idea!)  
- Learned to split into logical modules  
- Memory leaks were everywhere at first!

## 🎓 What I've Learned
- Algorithms aren't just theory – they solve real problems!  
- Memory management is crucial in C (and painful when you mess it up)  
- Code organization makes debugging so much easier  

---

**"The best way to learn programming is to program... and debug... and debug some more."**  

**Final Grade: 100/100 ⭐**

