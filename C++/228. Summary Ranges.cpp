/*
228. Summary Ranges
Easy

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b


Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"


Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
*/


// Really simple solution. I like this one. Store the first element and then
// inside the loop increment until we get to the last item in the range. Much
// cleaner than my first attempt.
class Solution {
public:
	vector<string> summaryRanges( vector<int>& nums ) {
		vector<string> output_ranges;
		int num_size = nums.size();

		for (int i = 0; i < num_size; ++i) {
			int first = nums[i];

			while (i + 1 < num_size && nums[i + 1] == nums[i] + 1) {
				++i;
			}

			if (nums[i] == first) {
				output_ranges.push_back( format( "{}", first ) );
			}
			else {
				output_ranges.push_back( format( "{}->{}", first, nums[i] ) );
			}
		}

		return output_ranges;
	}
};

// First attempt. The above example simplifies things a bunch so I'm adding it as well 
class Solution1 {
public:
	vector<string> summaryRanges( vector<int>& nums ) {
		vector<string> output_ranges;
		vector<int> current_range;

		// Loop through the vector and collect all the numbers in the range
		// Create an output string
		for (const auto& num : nums) {
			if (isNextNumber( num, current_range )) {
				current_range.push_back( num );
			}
			else {
				// num is not part of the last range. Set the previous range
				// and increment into the next one.
				if (current_range.size() == 1) {
					output_ranges.push_back( format( "{}", current_range.front() ) );
				}
				else {
					output_ranges.push_back( format( "{}->{}", current_range.front(), current_range.back() ) );
				}

				current_range.clear();
				current_range.push_back( num );
			}
		}

		// Resolve the last range group
		if (current_range.size() == 1) {
			output_ranges.push_back( format( "{}", current_range.front() ) );
		}
		else if (current_range.size() != 0) {
			output_ranges.push_back( format( "{}->{}", current_range.front(), current_range.back() ) );
		}

		return output_ranges;
	}

	bool isNextNumber( int num, vector<int>& range ) {
		if (range.size() == 0 || num == range.back() + 1) {
			return true;
		}

		return false;
	}
};