/*
141. Linked List Cycle
Easy

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list.Otherwise, return false.



Example 1:


Input: head = [3, 2, 0, -4], pos = 1
	Output : true
	Explanation : There is a cycle in the linked list, where the tail connects to the 1st node( 0 - indexed ).
	Example 2 :


	Input : head = [1, 2], pos = 0
	Output : true
	Explanation : There is a cycle in the linked list, where the tail connects to the 0th node.
	Example 3 :


	Input : head = [1], pos = -1
	Output : false
	Explanation : There is no cycle in the linked list.


	Constraints :

	The number of the nodes in the list is in the range[0, 104].
	- 105 <= Node.val <= 105
	pos is - 1 or a valid index in the linked - list.


	Follow up : Can you solve it using O( 1 ) (i.e.constant) memory ?
*/



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		// base case
		if (head == nullptr){
			return false;
		}

		ListNode* curr_node1 = head;
		ListNode* curr_node2 = head->next;

		while (curr_node1 != nullptr && curr_node2 != nullptr){
			// See if we found a loop
			if (curr_node1 == curr_node2){
				return true;
			}

			// Increment node1
			curr_node1 = curr_node1->next;

			// Increment node2
			if (curr_node2->next == nullptr || curr_node2->next->next == nullptr)
				curr_node2 = nullptr;
			else{
				curr_node2 = curr_node2->next->next;
			}

		}

		return false;
	}
};

/*
Here's someone else's solution. I like how it's more compact
and simplifies some of the logic.
*/
class Solution2 {
public:
	bool hasCycle(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return false;
		}
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast != slow) {
			if (fast->next == NULL || fast->next->next == NULL) {
				return false;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}
};

/*
Here's a hashmap solution. Interesting solution and good to keep in mind.
*/

class Solution3 {
public:
	bool hasCycle(ListNode* head) {
		if (head == NULL) {
			return false;
		}
		map<ListNode*, bool> visited;
		ListNode* temp = head;

		while (temp != NULL) {
			if (visited[temp] == true) {
				return true;
			}
			visited[temp] = true;
			temp = temp->next;
		}
		return false;
	}
};