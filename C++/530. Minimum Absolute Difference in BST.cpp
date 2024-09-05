/*
530. Minimum Absolute Difference in BST
Easy

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105
*/

/*
This one was interesting as I didn't catch that it was a BST and not
just a binary tree. A little tricky so not sure I'd categorize this
as easy, but it wasn't too bad once I was actually comparing the 
correct things.
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> inOrderList;
        int lastValue = INT_MAX;
        int currMinDiff = INT_MAX;
        TraverseBST(root, lastValue, currMinDiff);

        return currMinDiff;
    }

    void TraverseBST(const TreeNode* node, int& lastValue, int& currMinDiff){
        if (node != nullptr){
            TraverseBST(node->left, lastValue, currMinDiff);
            
            currMinDiff = min(currMinDiff, abs(node->val-lastValue));
            lastValue = node->val;
            
            TraverseBST(node->right, lastValue, currMinDiff);
        }
    }
};