/*
36. Valid Sudoku
Medium

Determine if a 9 x 9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :

Each row must contain the digits 1 - 9 without repetition.
Each column must contain the digits 1 - 9 without repetition.
Each of the nine 3 x 3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
Note :

	A Sudoku board( partially filled ) could be valid but is not necessarily solvable.
	Only the filled cells need to be validated according to the mentioned rules.


	Example 1:


Input: board =
	[["5", "3", ".", ".", "7", ".", ".", ".", "."]
	, ["6", ".", ".", "1", "9", "5", ".", ".", "."]
	, [".", "9", "8", ".", ".", ".", ".", "6", "."]
	, ["8", ".", ".", ".", "6", ".", ".", ".", "3"]
	, ["4", ".", ".", "8", ".", "3", ".", ".", "1"]
	, ["7", ".", ".", ".", "2", ".", ".", ".", "6"]
	, [".", "6", ".", ".", ".", ".", "2", "8", "."]
	, [".", ".", ".", "4", "1", "9", ".", ".", "5"]
	, [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
	   Output: true
		   Example 2 :

		   Input : board =
		   [["8", "3", ".", ".", "7", ".", ".", ".", "."]
		   , ["6", ".", ".", "1", "9", "5", ".", ".", "."]
		   , [".", "9", "8", ".", ".", ".", ".", "6", "."]
		   , ["8", ".", ".", ".", "6", ".", ".", ".", "3"]
		   , ["4", ".", ".", "8", ".", "3", ".", ".", "1"]
		   , ["7", ".", ".", ".", "2", ".", ".", ".", "6"]
		   , [".", "6", ".", ".", ".", ".", "2", "8", "."]
		   , [".", ".", ".", "4", "1", "9", ".", ".", "5"]
		   , [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
			   Output: false
				   Explanation : Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


				   Constraints :

				   board.length == 9
				   board[i].length == 9
				   board[i][j] is a digit 1 - 9 or '.'.
*/


class Solution {
public:
	bool isValidSudoku( vector<vector<char>>& board ) {
		for (int i = 0; i < 9; ++i) {
			if (!isRowValid( i, board )) {
				return false;
			}
			if (!isColumnValid( i, board )) {
				return false;
			}
			if (!isSubBoxValid( i, board )) {
				return false;
			}
		}

		return true;
	}

	bool isRowValid( int row, const vector<vector<char>>& board ) {
		std::unordered_map<char, int> cell_bins;

		for (auto val : board[row]) {
			cell_bins[val]++;
		}

		for (const auto& pair : cell_bins) {
			if (pair.first != '.' && pair.second > 1) {
				return false;
			}
		}

		return true;
	}

	bool isColumnValid( int column, const vector<vector<char>>& board ) {
		std::unordered_map<char, int> cell_bins;

		for (const auto& row : board) {
			cell_bins[row[column]]++;
		}

		for (const auto& pair : cell_bins) {
			if (pair.first != '.' && pair.second > 1) {
				return false;
			}
		}

		return true;
	}

	bool isSubBoxValid( int subbox, const vector<vector<char>>& board ) {
		std::unordered_map<char, int> cell_bins;

		// Get the sub box index coordinates based on the subbox we pass in.
		int x_mod = subbox % 3;
		int y_mod = subbox / 3;
		int row_start_index = x_mod * 3;
		int row_end_index = row_start_index + 2;
		int column_start_index = y_mod * 3;
		int column_end_index = column_start_index + 2;

		for (int i = row_start_index; i <= row_end_index; ++i) {
			for (int j = column_start_index; j <= column_end_index; ++j)
				cell_bins[board[i][j]]++;
		}

		for (const auto& pair : cell_bins) {
			if (pair.first != '.' && pair.second > 1) {
				return false;
			}
		}

		return true;
	}
};