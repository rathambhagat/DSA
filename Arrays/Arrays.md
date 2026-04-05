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
## MultiDimensinal Array
Arrays In multiple dimensional: 1D, 2D, 3D
## Overview
---Adding at the end---
# Problems
## Problem 1 - LeetCode1(available in C also)
1. Two Sum - Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
### Detail Documentation 
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


🏃‍♂️ Step-by-Step Logic Flow
```
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

## Problem 2 - LeetCode217(available in C also)

### Detail Documentation

📖 The Analogy: The Phone Book vs. The VIP List
* **Hash Map (Python Dictionary):** Think of this like a **Phone Book**. It stores a *Key* (a person's name) and a *Value* (their phone number). If you just want to know if "Alice" exists, a phone book works, but it forces you to also write down a phone number for her, wasting ink and space.
* **Hash Set (Python Set):** Think of this like a **Bouncer's VIP Guest List**. There are no phone numbers, no extra details. It’s just a list of names. The bouncer only asks one question: *"Is your name on this list?"* (Yes or No).
Because the "Contains Duplicate" problem only asks *if* a number exists (not *where* it is), the VIP Guest List (Hash Set) is the absolute perfect tool. It saves memory because we don't have to store dummy values.

📝 Algorithm Documentation: Contains Duplicate (Hash Set Solution)

📌 Problem Statement
Given an integer array `nums`, return `True` if any value appears at least twice in the array, and return `False` if every element is distinct.

💻 The Code
```python
class Solution(object):
    def containsDuplicate(self, nums):
        seen = set()                  # Initialize an empty Hash Set (The VIP List)
        for num in nums:              # Grab each number one by one
            if num in seen:           # Is this number already on the VIP list?
                return True           # 🚨 Emergency Exit! We found a duplicate!
            seen.add(num)             # If not, add them to the VIP list
            
        return False                  # Safety net: We checked everyone, no duplicates
```

🧠 Core Logic & Strategy
Instead of comparing every number to every other number (which would be a slow $O(n^2)$ time), we use a **Hash Set** to keep track of the numbers we have already seen. 

As we loop through the array, we ask our `seen` set: *"Have we seen this number before?"*
1. If the answer is **Yes**, it means we just found a duplicate. We immediately `return True` and stop the function.
2. If the answer is **No**, we add the current number to the `seen` set and move on to the next number.
3. If the loop finishes completely without ever finding a duplicate, we `return False`.

⏱️ Complexity Analysis
* **Time Complexity: $O(n)$**
  We traverse the list of $n$ elements exactly once. Checking if an item exists in a Python set (`if num in seen`) is incredibly fast—it takes $O(1)$ time on average. Therefore, the total time is linear.
* **Space Complexity: $O(n)$**
  In the worst-case scenario (every single number in the array is unique), our `seen` set will have to store every single element from the array, taking up $O(n)$ extra space in memory.

🏃‍♂️ Step-by-Step Logic Flow

```
**Example Input:** `nums = [1, 2, 3, 1]`

1. **Initialization:** We create an empty set `seen = set()`.
2. **Loop 1 (`num = 1`):**
   * Is `1` in `seen`? No.
   * Add to set: `seen.add(1)`.
   * *State of set:* `{1}`
3. **Loop 2 (`num = 2`):**
   * Is `2` in `seen`? No.
   * Add to set: `seen.add(2)`.
   * *State of set:* `{1, 2}`
4. **Loop 3 (`num = 3`):**
   * Is `3` in `seen`? No.
   * Add to set: `seen.add(3)`.
   * *State of set:* `{1, 2, 3}`
5. **Loop 4 (`num = 1`):**
   * Is `1` in `seen`? **Yes!**
   * Emergency exit activated: `return True`.
```

🤔 Common Pitfalls & Python Quirks
*These are specific details to remember when writing this in Python.*

1. `set()` vs `{}`
In Python, if you type `seen = {}`, Python creates an empty **Dictionary** (Hash Map). If you want an empty **Set**, you *must* type `seen = set()`. (Confusingly, once a set has items inside it, Python prints it with curly braces like `{1, 2, 3}`, but you cannot initialize an empty one that way!)
2. `.add()` vs `[]`
Because a Set doesn't have "keys and values" like a Dictionary, you cannot use square brackets to put things inside it. 
* **Dictionary:** `seen[num] = True`
* **Set:** `seen.add(num)`

3. Iterating over the array
When you write `for i in nums:`, Python gives you the *actual value* inside the array, not the index (0, 1, 2). It is highly recommended to name the variable `num` instead of `i` (`for num in nums:`) so you don't accidentally treat it like an index position.

## Problem 
## Notes
--- Adding later ---