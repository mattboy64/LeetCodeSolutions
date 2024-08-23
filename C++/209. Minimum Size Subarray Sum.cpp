/*
209. Minimum Size Subarray Sum
Medium

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/


/*
Tried a greedy algorithm first. It's O(n^2), and interestingly enough, they have
a test case that fails. Real answer is an adjustable sliding window. It's a method
that's good for subarrays or substring type problems, executes in O(n) and O(1) SC.
This version is an adjustable size one, but a fixed size one that slides along is
just as easy. You can also use a binary search.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int nums_size = nums.size();
        int best_length = INT_MAX;

        int curr_length = 0;
        int curr_total = 0;

        int left_index = 0;
        int right_index = 0;

        // Sliding window
        while (right_index < nums_size){
            curr_total += nums[right_index];

            while (curr_total >= target){
                curr_length = right_index - left_index + 1;

                if (curr_length < best_length){
                    best_length = curr_length;
                }

                curr_total -= nums[left_index];
                ++left_index;
            }

            ++right_index;
        }

        return best_length == INT_MAX ? 0 : best_length;
    }
};