/*
169. Majority Element
Easy

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

// Fancy Shmacy Solution. "Boyer–Moore majority vote algorithm" This is pretty neat. You take a value as the majority
// and increment if it comes up again, and decrement if it isn't. Once you hit 0, you use that element as the next
// majority object. it works because if there are more than n/2 of the majority number, then it will always have more
// elements that bring it back to being the main one.
class Solution {
public:
    int majorityElement(vector<int>& nums){
        // Use the Boyer-Moore majority vote algorithm
        int majority_item = 0;
        int majority_count = 0;
        for (auto num : nums){
            if (majority_count == 0){
                majority_item = num;
            }

            if (num == majority_item){
                majority_count++;
            }
            else{
                majority_count--;
            }

        }

        return majority_item;
    }
};



// This one uses Hashmaps. Better than our first attempt since we go from O(n^2) to O(n) (linear time), but we are O(n)
//space complexity. Going to use unordered_maps here, since it uses a hashmap (vs. a map which uses a red/black tree). 
// This is much more familiar to me in Python since I use dictionaries a ton)
class Solution2 {
public:
    int majorityElement(vector<int>& nums){
        std::unordered_map<int, int> elements;

        // if a key/value pair doesn't exist, it'll create it for me. This is really
        // nice. Python doesn't do this (you have to use get(), setdefault(), or defaultdict)
        for (auto num : nums){
            elements[num]++;
        }

        int maxKey = 0;
        int maxValue = 0;
        for(const auto& pair : elements){
            if (pair.second > maxValue){
                maxValue = pair.second;
                maxKey = pair.first;
            }
        }

        return maxKey;
    }
};


// This is a naive approach. O(n^2) time complexity, so pretty bad!
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element = 0;
        int majority_count = 0;
        int nums_size = nums.size();

        for (int i = 0; i < nums_size; ++i){
            int curr_element = nums[i];
            int curr_count = GetCount(curr_element, nums);

            if (curr_count > majority_count){
                majority_element = curr_element;
                majority_count = curr_count;
            }
        }

        return majority_element;
    }

    int GetCount(int element, const vector<int>& nums){
        int nums_size = nums.size();
        int count = 0;
        for (int i = 0; i < nums_size; ++i){      
            if (nums[i] == element){
                ++count;
            }
        }

        return count;
    }
};