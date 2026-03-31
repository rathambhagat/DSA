# Algorithms -
Algorithm in computer science is a precise, step-by-step set of instructions or rules followed to solve a specific problem or perform a task.

**Key Characteristics of an Algorithm:**
*Clear Instructions:* Each step must be unambiguous.
*Input & Output:* It takes defined inputs and produces a specific output.
*Finite:* It must eventually end after a limited number of steps.
*Effective:* The steps must be feasible. 

## Time Complexicity
Time complexity is a measure of the amount of computational time an algorithm takes to run as a function of the length of its input.

**Key Concepts**
*Focus on Growth Rate:* Time complexity does not measure the actual execution time in seconds (which can vary based on hardware, programming language, and operating system), but rather the rate at which the number of operations grows as the input size() increases. This provides a universal metric for comparing different algorithms objectively.
*Big O Notation:* This is the standard mathematical notation used to express the upper bound or worst-case scenario of an algorithm's running time. It simplifies the analysis by focusing only on the most significant term (the one that grows fastest) and ignoring constant factors and lower-order terms.
*Scalability:* Understanding time complexity helps developers determine how an algorithm will perform with large datasets (scalability), allowing them to choose the most efficient approach for a given problem.

**Common Types of Time Complexity**
Here are some of the most frequent types of time complexities, ordered from most efficient to least efficient: 
*Constant Time (O(1)):* The execution time is constant and does not depend on the input size at all. An example is accessing the first element of an array.
*Logarithmic Time (O(log n)):* The execution time grows logarithmically with the input size. This often occurs in "divide and conquer" algorithms where the problem size is halved at each step, such as in a binary search.
*Linear Time (O(n)):* The execution time increases linearly and proportionally with the input size. An example is iterating through a list to find a specific item (linear search).
*Linearithmic Time (O(n log n)):* The execution time grows proportionally to the input size multiplied by the logarithm of the input size. Efficient sorting algorithms like Merge Sort and Heap Sort fall into this category.
*Quadratic Time (O(n²)):* The execution time grows with the square of the input size. This is typical for algorithms with nested loops, such as Bubble Sort or Selection Sort.
*Exponential Time (O(2ⁿ)):* The execution time doubles with each addition to the input data set. This is often seen in brute-force solutions for complex problems like the Traveling Salesman Problem or naive recursive calculations of the Fibonacci sequence. 

## Space Complexicity
Space complexity is a measure of the total amount of memory an algorithm requires to run to completion, as a function of the size of its input. It quantifies the growth rate of memory consumption as the input size increases and is typically expressed using Big O notation.

**Components of Space Complexity**
Total space complexity is composed of two main parts: 
• *Fixed Part:* The memory required for elements that do not change with the input size, such as constants, simple variables, and the algorithm's code itself. This part is constant for a given program. 
• *Variable Part (Auxiliary Space):* The extra or temporary memory required during execution that does depend on the input size. This includes dynamic memory allocation, the space used by the recursion call stack, and temporary data structures. [4, 5, 6, 7, 8]  
In algorithm analysis, the focus is often on the auxiliary space because the input size is a given parameter, and we are interested in the extra memory the algorithm needs to do its work.

**Common Space Complexities (Big O Notation)**
Space complexity helps in comparing different algorithms, especially in memory-constrained environments like mobile devices or embedded systems.

> | O(1) | Constant Space | The memory usage is fixed and does not change with the input size. Examples include swapping two variables or iterative factorial calculation.  |
> | O(log n) | Logarithmic Space | The memory usage grows logarithmically with the input size. This is common in some recursive algorithms like binary search, due to the call stack depth.  |
> | O(n) | Linear Space | The memory usage grows linearly with the input size. Examples include storing elements in a standard array or linked list, or the recursion depth in a simple recursive function.  |
> | O(n²) | Quadratic Space | The memory usage grows proportionally to the square of the input size, such as with an adjacency matrix representation of a graph or a two-dimensional array.  |

**Time-Space Trade-off** 
Often, there is a trade-off between time complexity (how fast an algorithm runs) and space complexity. An algorithm might use more memory (higher space complexity) to run faster (lower time complexity), or vice versa. 

• Example: Merge Sort has a time complexity of O(n log n) but requires O(n) auxiliary space for temporary arrays. In contrast,  Insertion Sort operates in-place with O(1) auxiliary space, but has a worst-case time complexity of O(n²). 

## What is Big O
Big O notation is a mathematical tool used in computer science to analyze the efficiency of an algorithm, describing how its runtime or space requirements grow as the input size (
) increases.
