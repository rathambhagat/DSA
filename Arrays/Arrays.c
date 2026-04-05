/*
1. Two Sum LeetCode Problem 1
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

#include <stdlib.h>
#include "uthash.h" // Need to Download this library to make the code working 

// 1. Define what our "dictionary" looks like
struct hashTable {
    int key;           // The number itself (what we are looking for)
    int value;         // The index of the number
    UT_hash_handle hh; // The magical uthash tool that makes this work
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Initialize our empty "seen" dictionary
    struct hashTable *seen = NULL; 
    struct hashTable *entry;       // A temporary variable to hold what we find
    
    // Allocate memory for our answer array (which will hold 2 numbers)
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2; // Tell LeetCode our returning array has exactly 2 items

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // 2. CHECK THE DICTIONARY: "if complement in seen:"
        HASH_FIND_INT(seen, &complement, entry);
        
        if (entry != NULL) {
            // WE FOUND IT!
            result[0] = entry->value; // seen[complement]
            result[1] = i;            // current index
            
            // Note: In a real-world C program, we would free the memory of our 
            // hash map here to prevent memory leaks, but LeetCode accepts it like this.
            return result;
        }
        
        // 3. NOT FOUND, ADD TO DICTIONARY: "seen[num] = i"
        entry = (struct hashTable*)malloc(sizeof(struct hashTable));
        entry->key = nums[i];
        entry->value = i;
        HASH_ADD_INT(seen, key, entry);
    }
    
    // 4. SAFETY NET: "return []"
    *returnSize = 0;
    free(result);
    return NULL;
}

/*
217. Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <stdbool.h> // C needs this to understand 'true' and 'false'
#include <stdlib.h>
#include "uthash.h"  // Don't forget your local file!

// 1. Define our "VIP List" Set
struct hashSet {
    int key;              // The number itself
    UT_hash_handle hh;    // 🚨 MANDATORY: The magic handle you fixed earlier!
    // Notice: NO 'value' integer here! We don't need it.
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashSet *seen = NULL; // Initialize empty VIP list
    struct hashSet *entry;       // Temporary variable
    
    for (int i = 0; i < numsSize; i++) {
        // 2. CHECK THE VIP LIST: "if num in seen:"
        HASH_FIND_INT(seen, &nums[i], entry);
        
        if (entry != NULL) {
            // WE FOUND A DUPLICATE! EMERGENCY EXIT!
            
            // Note: To be a good C citizen, we should write a loop to free() 
            // all the memory in 'seen' before returning, but LeetCode 
            // will accept this exact code for speed.
            return true; 
        }
        
        // 3. NOT FOUND, ADD TO VIP LIST: "seen.add(num)"
        entry = (struct hashSet*)malloc(sizeof(struct hashSet));
        entry->key = nums[i];
        HASH_ADD_INT(seen, key, entry);
    }
    
    // 4. SAFETY NET: Checked everything, no duplicates
    return false;
}