
# Sorting Algorithms 

**Sorting Algorithms**, is a collection of efficient and commonly used sorting algorithms implemented in the C programming language. This project is perfect for those studying algorithms or data structures.

## 👾 Features

- **Comprehensive Algorithm Support**: Implementations include classic sorting techniques such as Bubble Sort, Quick Sort, Merge Sort, and more.
- **Performance Analysis**: Each algorithm includes its time complexity (Big-O notation) for better understanding and comparison.
- **Educational Value**: Ideal for learning how different sorting algorithms work and their use cases.

## 🚀 Getting Started

Follow these steps to explore and execute the sorting algorithms.

### 1. Prerequisites

- A Linux-based operating system (tested on Linux Min).
- GCC (GNU Compiler Collection) installed on your system.

### 2. Compiling the Code

Use the following command to compile a specific sorting algorithm:

```bash
gcc bubble.c -o bubble
```

Replace `bubble.c` with the desired file name (e.g., `quickSort.c`).

### 3. Running the Program

Run the compiled program to see the sorting in action:

```bash
./bubble
```

## 🔍 Algorithms Included

Below is a list of sorting algorithms, with brief descriptions and their time complexities:

### 1. Bubble Sort (`bubble.c`)
- **Description**: Compares adjacent elements and swaps them if they are in the wrong order. Repeats this process until the array is sorted.
- **Complexity**: 
  - Best: O(n)
  - Average: O(n²)
  - Worst: O(n²)

### 2. Counting Sort (`couting.c`)
- **Description**: Sorts integers by counting the occurrences of each value and calculating their positions.
- **Complexity**: 
  - Best, Average, Worst: O(n + k) (where `k` is the range of input values)

### 3. Insertion Sort (`insertion.c`)
- **Description**: Builds the sorted array one element at a time by inserting each element into its correct position.
- **Complexity**: 
  - Best: O(n)
  - Average: O(n²)
  - Worst: O(n²)

### 4. Quick Sort (`quickSort.c`)
- **Description**: Divides the array into two smaller sub-arrays around a pivot and recursively sorts them.
- **Complexity**: 
  - Best: O(n log n)
  - Average: O(n log n)
  - Worst: O(n²)

### 5. Selection Sort (`selection.c`)
- **Description**: Repeatedly selects the smallest (or largest) element and swaps it with the first unsorted element.
- **Complexity**: 
  - Best, Average, Worst: O(n²)

### 6. Bucket Sort (`bucket.c`)
- **Description**: Divides the array into buckets and sorts each bucket individually.
- **Complexity**: 
  - Best: O(n + k)
  - Average: O(n + k)
  - Worst: O(n²)

### 7. Heap Sort (`heap.c`)
- **Description**: Uses a binary heap data structure to repeatedly extract the maximum (or minimum) element.
- **Complexity**: 
  - Best, Average, Worst: O(n log n)

### 8. Merge Sort (`mergesort.c`)
- **Description**: Divides the array into halves, sorts each half recursively, and merges them back together.
- **Complexity**: 
  - Best, Average, Worst: O(n log n)

### 9. Radix Sort (`radix.c`)
- **Description**: Sorts numbers by processing individual digits from least to most significant.
- **Complexity**: 
  - Best, Average, Worst: O(nk) (where `k` is the number of digits)

### 10. Shell Sort (`shell.c`)
- **Description**: An optimized version of insertion sort that uses a gap sequence to reduce comparisons.
- **Complexity**: 
  - Best: O(n log n)
  - Average: Depends on gap sequence
  - Worst: O(n²)

## 🛠️ How It Works

Each algorithm is implemented in its respective `.c` file. The programs take an unsorted array as input, apply the sorting technique, and display the sorted array.
