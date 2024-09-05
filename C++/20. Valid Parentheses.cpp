/*
20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true



Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
	bool isValid( string s ) {
		string opening_chars = "([{";
		stack<char> bracket_stack;
		for (const auto& ch : s) {
			// opening brackets
			if (opening_chars.find(ch) != string::npos) {
				bracket_stack.push(ch);
			}
			else {
				// closing brackets
				if (bracket_stack.empty() ||
					(ch == ')' && bracket_stack.top() != '(') ||
					(ch == '}' && bracket_stack.top() != '{') ||
					(ch == ']' && bracket_stack.top() != '[')) {
					return false;
				}
				bracket_stack.pop();
			}
		}

		return bracket_stack.empty();
	}
};