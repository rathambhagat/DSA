# Arrays
 A fixed-size, contiguous collection of elements of the same type, accessed by index.
## Time Complexicity
Accessing: O(1)
Insert: O(1)/O(N)
Delete: O(N)/O(1)
Traverse: O(N)
Search: a) Linear: O(N)
        b) Binary: O(logN)
Update: O(1)
## Benefits 
1) Random Access O(1)
2) Cache Friendly
3) ease of sorting
4) Implement other Data Structure
## Limitations 
1) Fixed Size
2) O(N) - Insert/ Delete Ineffiecient for Frequent modifications
## When to USE
1) Implement Other Data Structure
2) Caching
3) Tree visite nodes
4) Mathematical
5) Coding Patterns
# MultiDimensinal Array
Arrays In multiple dimensional: 1D, 2D, 3D
## Overview

## Problems
### Problem 1 - LeetCode1
1. Two Sum - Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
#### Detail Documentation 
📝 Algorithm Documentation: Two Sum (Hash Map Solution)

📌 Problem Statement
Given an array of integers `nums` and an integer `target`, return the **indices** of the two numbers that add up to the `target`. 

You may assume that each input would have exactly one solution, and you may not use the same element twice.

💻 The Code
```python
class Solution(object):
    def twoSum(self, nums, target):
        seen = {}                     
        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
        return []
```

🧠 Core Logic & Strategy
The brute-force way to solve this is to use two nested loops to check every number against every other number. However, that is slow. 
This optimized solution uses a **Hash Map** (a Python Dictionary) to act as a "history book." As we iterate through the list, we calculate the `complement` (the number we *need* to reach the target). We then check our history book:
1. If the complement is already in our history book, we found our pair!
2. If it is not, we write the current number and its index into the history book and move to the next number.

⏱️ Complexity Analysis
* **Time Complexity: $O(n)$**
  We traverse the list containing $n$ elements exactly once. Inside the loop, calculating the complement and checking if it exists in the dictionary (`if complement in seen:`) takes $O(1)$ time on average. Therefore, the overall time complexity is linear.
* **Space Complexity: $O(n)$**
  The extra space required depends on the number of items stored in the hash table, which stores at most $n$ elements in the worst-case scenario (e.g., if the matching pair is at the very end of the list).

```
🏃‍♂️ Step-by-Step Logic Flow
**Example Input:** `nums = [2, 7, 11, 15]`, `target = 9`

1. **Initialization:** We create an empty dictionary `seen = {}`.
2. **Loop 1 (`i = 0`, `num = 2`):**
   * Calculate complement: `9 - 2 = 7`.
   * Is `7` in `seen`? No.
   * Add to dictionary: `seen[2] = 0`.
   * *State of dictionary:* `{2: 0}`
3. **Loop 2 (`i = 1`, `num = 7`):**
   * Calculate complement: `9 - 7 = 2`.
   * Is `2` in `seen`? **Yes!**
   * Emergency exit activated: `return [seen[2], i]`.
   * **Result:** `[0, 1]`
```

🤔 Common Pitfalls & Doubts Clarified
*These are specific conceptual hurdles I overcame while learning this algorithm.*
1. How can we check for a complement if the dictionary starts empty?
The dictionary is empty *only* at the very first step. The core mechanic is that we build the dictionary as we go. We check the dictionary first, and if the complement isn't there, we store the current number in the dictionary *after*. By the time we find the second number of our pair, the first number has already been saved into the dictionary.

2. Does `enumerate()` store things in a dictionary?
No. `enumerate()` is simply a built-in Python function that loops over an iterable (like a list) and hands you two variables at the exact same time: the **index counter** (`i`) and the **value** (`num`). It does no storing itself. We are manually doing the storing on the line `seen[num] = i`.

3. How does the code get `nums` and `target` if there is no `input()` function?
When solving this on platforms like LeetCode, or in object-oriented programming, the inputs are passed directly to the class method. Behind the scenes, the system creates an instance of the class and feeds the arguments directly into the function, like this:
```python
solver = Solution()
answer = solver.twoSum([2, 7, 11, 15], 9)
```

4. Once the `if` statement passes and returns the answer, does it still execute `seen[num] = i`?
**Absolutely not.** The `return` keyword acts as an emergency exit for a function. The moment Python hits `return [seen[complement], i]`, it instantly stops the function, hands the data back, and completely shuts down. The line below it (`seen[num] = i`) never runs for that final number. In the `[2, 7, 11, 15]` example, the number `7` is never actually added to the dictionary.

5. Why is there a `return []` at the very end of the function?
This is a safety net. While most algorithms guarantee a valid answer, if the function is handed a trick question (e.g., `nums = [1, 2, 3]`, `target = 100`), the `for` loop will finish without ever hitting the `return` statement inside the loop. The `return []` ensures the code handles this gracefully by stating, "I checked everything, and no pair exists."

## Notes
