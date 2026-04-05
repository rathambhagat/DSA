/*
1. Two Sum LeetCode Problem 1
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

#include <stdlib.h>


// 1. Define what our "dictionary" looks like
struct hashTable {
    int key;           // The number itself (what we are looking for)
    int value;         // The index of the number
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

*/