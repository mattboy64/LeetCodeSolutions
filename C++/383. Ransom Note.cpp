/*
383. Ransom Note
Easy

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true


Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/

class Solution {
public:
	bool canConstruct( string ransomNote, string magazine ) {
		// First populate a hashtable with all the options from the magazine
		unordered_map<char, int> magazine_letters;
		for (const auto& letter : magazine) {
			magazine_letters[letter]++;
		}

		// Next removed needed values from the magazine.
		// If we run out of, we can not construct it, return false
		for (const auto& letter : ransomNote) {
			int remaining_letters = --magazine_letters[letter];

			if (remaining_letters < 0) {
				return false;
			}
		}

		return true;
	}
};