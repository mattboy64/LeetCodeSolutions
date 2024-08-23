/*
125. Valid Palindrome
Easy

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non - alphanumeric characters, it reads the same forward and backward.Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
	Output : true
	Explanation : "amanaplanacanalpanama" is a palindrome.
	Example 2 :

	Input : s = "race a car"
	Output : false
	Explanation : "raceacar" is not a palindrome.
	Example 3 :

	Input : s = " "
	Output : true
	Explanation : s is an empty string "" after removing non - alphanumeric characters.
	Since an empty string reads the same forward and backward, it is a palindrome.


	Constraints :

	1 <= s.length <= 2 * 105
	s consists only of printable ASCII characters.
*/

/*
Started by trying to clean and remove elements from the string, but that gets complicated and error prone.
It's much easier to just compare chars along the way. If people struggle, might want to simplify it with NO
spaces, non-alphanumeric values, then build on that.
*/

class Solution {
public:
	bool isPalindrome( string s ) {
		// // Remove non-alpha numerics
		// s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !std::isalnum(c);}));

		// // Convert the string to lowercase
		// std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
		//     return std::tolower(c);
		// });

		int i = 0;
		int j = s.size() - 1;

		while (i < j) {
			if (!isalnum( s[i] )) {
				++i;
				continue;
			}
			if (!isalnum( s[j] )) {
				--j;
				continue;
			}

			if (tolower( s[i] ) != tolower( s[j] ))
			{
				return false;
			}

			++i;
			--j;
		}

		return true;
	}
};