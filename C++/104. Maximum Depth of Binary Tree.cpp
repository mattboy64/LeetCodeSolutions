/*
104. Maximum Depth of Binary Tree
Solved
Easy
Topics
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2


Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr){
			return 0;
		}

		int currDepth = 1;

		// Same as below (no longer needed)
		//int leftDepth = 0;
		//int rightDepth = 0;

		// We don't need to check for nullptr because we had to check that
		// as a base case anyways
		// if (root->left != nullptr){
		//     leftDepth = maxDepth(root->left);    
		// }
		// if (root-> right != nullptr){
		//     rightDepth = maxDepth(root->right);
		// }

		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);

		return currDepth + max(leftDepth, rightDepth);
	}
};