/*
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

/*
First one is O(n^2) time complexity. Naive approach
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element = 0;
        int majority_count = 0;
        int nums_size = nums.size();

        for (int i = 0; i < nums_size; ++i)
        {
            int curr_element = nums[i];
            int curr_count = GetCount(curr_element, nums);

            if (curr_count > majority_count)
            {
                majority_element = curr_element;
                majority_count = curr_count;
            }
        }

        return majority_element;
    }

    int GetCount(int element, const vector<int>& nums)
    {
        int nums_size = nums.size();
        int count = 0;
        for (int i = 0; i < nums_size; ++i)
        {      
            if (nums[i] == element)
            {
                ++count;
            }
        }

        return count;
    }
};