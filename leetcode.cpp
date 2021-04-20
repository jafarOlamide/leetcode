class Solution {
public:

    /*1. Two Sum (Easy)
	Given an array of integers nums and an integer target, return indices of 
	the two numbers such that they add up to target. You may assume that each 
	input would have exactly one solution, and you may not use the same element 
	twice. You can return the answer in any order.

	Example 1:
	Input: nums = [2,7,11,15], target = 9
	Output: [0,1]
	Output: Because nums[0] + nums[1] == 9, we return [0, 1].

	Example 2:
	Input: nums = [3,2,4], target = 6
	Output: [1,2]

	Example 3:
	Input: nums = [3,3], target = 6
	Output: [0,1]

	Constraints:
	* 2 <= nums.length <= 103
	* -109 <= nums[i] <= 109
	* -109 <= target <= 109
	* Only one valid answer exists.*/

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value to index mapping
        for (int i = 0; i < nums.size(); ++i) {
            int x = target - nums[i]; 
            if (mp.find(x) != mp.end())
                return {mp[x], i};
            mp[nums[i]] = i; 
        }
        return {}; 
    }


	/*7. Reverse Integer (Easy)
	Given a 32-bit signed integer, reverse digits of an integer. Note that 
	assume we are dealing with an environment that could only store integers 
	within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose 
	of this problem, assume that your function returns 0 when the reversed 
	integer overflows.

	Example 1:
	Input: x = 123
	Output: 321

	Example 2:
	Input: x = -123
	Output: -321

	Example 3:
	Input: x = 120
	Output: 21

	Example 4:
	Input: x = 0
	Output: 0

	Constraints: -2^31 <= x <= 2^31 - 1*/

    int reverse(int x) {
        int ans = 0; 
        while (x) { 
            if ((ans > INT_MAX/10) or (ans == INT_MAX/10 and x > INT_MAX%10)) return 0;
            if ((ans < INT_MIN/10) or (ans == INT_MIN/10 and x < INT_MIN%10)) return 0;
            ans = 10*ans + x%10; 
            x /= 10; 
        }
        return ans; 
    }


    /*9. Palindrome Number (Easy)
	Determine whether an integer is a palindrome. An integer is a palindrome 
	when it reads the same backward as forward. 
	Follow up: Could you solve it without converting the integer to a string?

	Example 1:
	Input: x = 121
	Output: true

	Example 2:
	Input: x = -121
	Output: false
	Explanation: From left to right, it reads -121. From right to left, it 
	             becomes 121-. Therefore it is not a palindrome.

	Example 3:
	Input: x = 10
	Output: false
	Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
	
	Example 4:
	Input: x = -101
	Output: false

	Constraints: -2^31 <= x <= 2^31 - 1*/

    bool isPalindrome(int x) {
        if (x < 0) return false; // edge case 
        
        long val = x, rev = 0;
        while (x) {
            rev = 10*rev + x%10; 
            x /= 10; 
        }
        return val == rev; 
    }


    /*13. Roman to Integer (Easy)
	Roman numerals are represented by seven different symbols: I, V, X, L, C, D 
	and M.
	Symbol       Value
	I             1
	V             5
	X             10
	L             50
	C             100
	D             500
	M             1000
	For example, 2 is written as II in Roman numeral, just two one's added 
	together. 12 is written as XII, which is simply X + II. The number 27 is 
	written as XXVII, which is XX + V + II. Roman numerals are usually written 
	largest to smallest from left to right. However, the numeral for four is 
	not IIII. Instead, the number four is written as IV. Because the one is 
	before the five we subtract it making four. The same principle applies to 
	the number nine, which is written as IX. There are six instances where 
	subtraction is used:
	* I can be placed before V (5) and X (10) to make 4 and 9. 
	* X can be placed before L (50) and C (100) to make 40 and 90. 
	* C can be placed before D (500) and M (1000) to make 400 and 900.
	Given a roman numeral, convert it to an integer.

	Example 1:
	Input: s = "III"
	Output: 3

	Example 2:
	Input: s = "IV"
	Output: 4

	Example 3:
	Input: s = "IX"
	Output: 9

	Example 4:
	Input: s = "LVIII"
	Output: 58
	Explanation: L = 50, V= 5, III = 3.

	Example 5:
	Input: s = "MCMXCIV"
	Output: 1994
	Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
	 
	Constraints:
	* 1 <= s.length <= 15
	* s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
	* It is guaranteed that s is a valid roman numeral in the range [1, 3999].*/

    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500}, 
            {'M', 1000}}; 
        int ans = 0; 
        for (int i = 0; i < s.size(); ++i) {
            if (i+1 < s.size() and mp[s[i]] < mp[s[i+1]]) 
                ans -= mp[s[i]];
            else 
                ans += mp[s[i]]; 
        }
        return ans; 
    }


    /*17. Letter Combinations of a Phone Number (Medium)
	Given a string containing digits from 2-9 inclusive, return all possible 
	letter combinations that the number could represent. Return the answer in 
	any order. A mapping of digit to letters (just like on the telephone 
	buttons) is given below. Note that 1 does not map to any letters.

	Example 1:
	Input: digits = "23"
	Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

	Example 2:
	Input: digits = ""
	Output: []

	Example 3:
	Input: digits = "2"
	Output: ["a","b","c"]

	Constraints:
	* 0 <= digits.length <= 4
	* digits[i] is a digit in the range ['2', '9'].*/

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 
        
        const vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""}; 
        for (auto& c : digits) {
            vector<string> tmp; 
            for (auto& x : ans) {
                for (auto& xx : mp[c - '2']) {
                    tmp.push_back(x + xx); 
                }
            }
            ans = tmp; 
        }
        return ans; 
    }


    /*19. Remove Nth Node From End of List (Medium)
	Given the head of a linked list, remove the nth node from the end of the 
	list and return its head. Follow up: Could you do this in one pass?

	Example 1:
	Input: head = [1,2,3,4,5], n = 2
	Output: [1,2,3,5]

	Example 2:
	Input: head = [1], n = 1
	Output: []

	Example 3:
	Input: head = [1,2], n = 1
	Output: [1]

	Constraints:
	* The number of nodes in the list is sz.
	* 1 <= sz <= 30
	* 0 <= Node.val <= 100
	* 1 <= n <= sz*/

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head), *fast = &dummy, *slow = &dummy; 
        while (fast) {
            fast = fast->next; 
            if (n-- < 0) slow = slow->next; 
        }
        ListNode* temp = slow->next; 
        slow->next = slow->next->next; 
        delete temp; 
        return dummy.next; 
    }


    /*20. Valid Parentheses (Easy)
	Given a string s containing just the characters '(', ')', '{', '}', '[' and 
	']', determine if the input string is valid. An input string is valid if:
	* Open brackets must be closed by the same type of brackets.
	* Open brackets must be closed in the correct order.
	 
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
	Input: s = "([)]"
	Output: false

	Example 5:
	Input: s = "{[]}"
	Output: true

	Constraints:
	* 1 <= s.length <= 104
	* s consists of parentheses only '()[]{}'.*/

    bool isValid(string s) {
        stack<char> stk; 
        for (auto& c : s) {
            switch(c) {
                case '(': stk.push(')'); break; 
                case '[': stk.push(']'); break; 
                case '{': stk.push('}'); break; 
                default: 
                    if (stk.empty() or stk.top() != c) return false; 
                    stk.pop(); 
            }
        }
        return stk.empty(); 
    }


    /*21. Merge Two Sorted Lists (Easy)
	Merge two sorted linked lists and return it as a new sorted list. The new 
	list should be made by splicing together the nodes of the first two lists.

	Example 1:
	Input: l1 = [1,2,4], l2 = [1,3,4]
	Output: [1,1,2,3,4,4]

	Example 2:
	Input: l1 = [], l2 = []
	Output: []

	Example 3:
	Input: l1 = [], l2 = [0]
	Output: [0]

	Constraints:
	* The number of nodes in both lists is in the range [0, 50].
	* -100 <= Node.val <= 100
	* Both l1 and l2 are sorted in non-decreasing order.

	Definition for singly-linked list.
	struct ListNode {
	    int val;
	    ListNode *next;
	    ListNode() : val(0), next(nullptr) {}
	    ListNode(int x) : val(x), next(nullptr) {}
	    ListNode(int x, ListNode *next) : val(x), next(next) {}
	};

	*/

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); 
        ListNode* node = &dummy; 
        while (l1 and l2) {
            if (l1->val < l2->val) {
                node->next = l1; 
                l1 = l1->next; 
            } else {
                node->next = l2; 
                l2 = l2->next; 
            }
            node = node->next; 
        }
        node->next = l1 ? l1 : l2; 
        return dummy.next; 
    }


    /*26. Remove Duplicates from Sorted Array (Easy)
	Given a sorted array nums, remove the duplicates in-place such that each 
	element appears only once and returns the new length. Do not allocate extra 
	space for another array, you must do this by modifying the input array in-
	place with O(1) extra memory.

	Clarification:
	Confused why the returned value is an integer but your answer is an array? 
	Note that the input array is passed in by reference, which means a 
	modification to the input array will be known to the caller as well.

	Internally you can think of this:
	// nums is passed in by reference. (i.e., without making a copy)
	int len = removeDuplicates(nums);
	// any modification to nums in your function would be known by the caller.
	// using the length returned by your function, it prints the first len elements.
	for (int i = 0; i < len; i++) {
	    print(nums[i]);
	}
	 
	Example 1:
	Input: nums = [1,1,2]
	Output: 2, nums = [1,2]
	Explanation: Your function should return length = 2, with the first two 
	             elements of nums being 1 and 2 respectively. It doesn't matter 
	             what you leave beyond the returned length.

	Example 2:
	Input: nums = [0,0,1,1,1,2,2,3,3,4]
	Output: 5, nums = [0,1,2,3,4]
	Explanation: Your function should return length = 5, with the first five 
	             elements of nums being modified to 0, 1, 2, 3, and 4 
	             respectively. It doesn't matter what values are set beyond the 
	             returned length.
	
	Constraints:
	* 0 <= nums.length <= 3 * 104
	* -104 <= nums[i] <= 104
	* nums is sorted in ascending order.*/

    int removeDuplicates(vector<int>& nums) {
        int i = 0; 
        for (auto& x : nums) {
            if (i == 0 or nums[i-1] < x) {
                nums[i++] = x; 
            }
        }
        return i; 
    }


    /*28. Implement strStr() (Easy)
	Implement strStr(). Return the index of the first occurrence of needle in 
	haystack, or -1 if needle is not part of haystack. 

	Clarification:
	What should we return when needle is an empty string? This is a great 
	question to ask during an interview. For the purpose of this problem, we 
	will return 0 when needle is an empty string. This is consistent to C's 
	strstr() and Java's indexOf().

	Example 1:
	Input: haystack = "hello", needle = "ll"
	Output: 2

	Example 2:
	Input: haystack = "aaaaa", needle = "bba"
	Output: -1

	Example 3:
	Input: haystack = "", needle = ""
	Output: 0

	Constraints:
	* 0 <= haystack.length, needle.length <= 5 * 104
	* haystack and needle consist of only lower-case English characters.*/

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // edge case 
        
        int n = (int) needle.size(); 
        vector<int> lps(n, 0); // longest prefix-suffix array 
        int k = 0; 
        for (int i = 1; i < n; ++i) {
            while (k > 0 and needle[k] != needle[i]) k = lps[k-1]; 
            if (needle[k] == needle[i]) k++; 
            lps[i] = k; 
        }
        
        int m = (int) haystack.size(); 
        k = 0; 
        for (int i = 0; i < m; ++i) {
            while (k > 0 and needle[k] != haystack[i]) k = lps[k-1]; 
            if (needle[k] == haystack[i]) k++; 
            if (k == n) return i + 1 - n;  
        }
        return -1; 
    }


	/*83. Remove Duplicates from Sorted List (Easy)
	Given the head of a sorted linked list, delete all duplicates such that 
	each element appears only once. Return the linked list sorted as well.

	Example 1:
	Input: head = [1,1,2]
	Output: [1,2]

	Example 2:
	Input: head = [1,1,2,3,3]
	Output: [1,2,3]

	Constraints:
	* The number of nodes in the list is in the range [0, 300].
	* -100 <= Node.val <= 100
	* The list is guaranteed to be sorted in ascending order.*/

    ListNode* deleteDuplicates(ListNode* head) {
        if (head != NULL) {
            ListNode* node = head; 
            while (node->next != NULL) {
                if (node->val == node->next->val) {
                    node->next = node->next->next; 
                } else {
                    node = node->next; 
                }
            }
        }
        return head; 
    }


    /*86. Partition List (Medium)
	Given the head of a linked list and a value x, partition it such that all 
	nodes less than x come before nodes greater than or equal to x. You should 
	preserve the original relative order of the nodes in each of the two 
	partitions.

	Example 1:
	Input: head = [1,4,3,2,5,2], x = 3
	Output: [1,2,2,4,3,5]

	Example 2:
	Input: head = [2,1], x = 2
	Output: [1,2]

	Constraints:
	* The number of nodes in the list is in the range [0, 200].
	* -100 <= Node.val <= 100
	* -200 <= x <= 200*/

    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0), dummy2(0); 
        ListNode *node1 = &dummy1, *node2 = &dummy2, *node = head; 
        
        while (node) {
            if (node->val < x) {
                node1 = node1->next = node;
            } else {
                node2 = node2->next = node;
            }
            node = node->next; 
        }
        node1->next = dummy2.next; 
        node2->next = NULL; 
        return dummy1.next; 
    }


    /*88. Merge Sorted Array (Easy)
	Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as 
	one sorted array. The number of elements initialized in nums1 and nums2 are 
	m and n respectively. You may assume that nums1 has a size equal to m + n 
	such that it has enough space to hold additional elements from nums2.

	Example 1:
	Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
	Output: [1,2,2,3,5,6]

	Example 2:
	Input: nums1 = [1], m = 1, nums2 = [], n = 0
	Output: [1]

	Constraints:
	* nums1.length == m + n
	* nums2.length == n
	* 0 <= m, n <= 200
	* 1 <= m + n <= 200
	* -109 <= nums1[i], nums2[i] <= 10^9*/

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1; 
        for (int k = m+n-1; k >= 0; --k) {
            if (j < 0 || (i >= 0 && nums1[i] > nums2[j])) {
                nums1[k] = nums1[i--]; 
            } else {
                nums1[k] = nums2[j--]; 
            }
        }
    }


    /*94. Binary Tree Inorder Traversal (Medium)
	Given the root of a binary tree, return the inorder traversal of its 
	nodes' values.

	Example 1:
	Input: root = [1,null,2,3]
	Output: [1,3,2]

	Example 2:
	Input: root = []
	Output: []

	Example 3:
	Input: root = [1]
	Output: [1]

	Example 4:
	Input: root = [1,2]
	Output: [2,1]

	Example 5:
	Input: root = [1,null,2]
	Output: [1,2]

	Constraints:
	* The number of nodes in the tree is in the range [0, 100].
	* -100 <= Node.val <= 100

	Follow up: Recursive solution is trivial, could you do it iteratively?*/

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans; 
        TreeNode* node = root; 
        stack<TreeNode*> stk; 
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node); 
                node = node->left; 
            } else {
                node = stk.top(); 
                stk.pop(); 
                ans.push_back(node->val); 
                node = node->right;
            }
        }
        return ans; 
    }


    /*100. Same Tree (Easy)
	Given the roots of two binary trees p and q, write a function to check if 
	they are the same or not. Two binary trees are considered the same if they 
	are structurally identical, and the nodes have the same value.

	Example 1:
	Input: p = [1,2,3], q = [1,2,3]
	Output: true

	Example 2:
	Input: p = [1,2], q = [1,null,2]
	Output: false

	Example 3:
	Input: p = [1,2,1], q = [1,1,2]
	Output: false

	Constraints:
	* The number of nodes in both trees is in the range [0, 100].
	* -10^4 <= Node.val <= 10^4*/

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true; 
        if (p == NULL || q == NULL) return false; 
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }

    
    /*101. Symmetric Tree (Easy)
	Given the root of a binary tree, check whether it is a mirror of itself 
	(i.e., symmetric around its center).

	Example 1:
	Input: root = [1,2,2,3,4,4,3]
	Output: true

	Example 2:
	Input: root = [1,2,2,null,3,null,3]
	Output: false

	Constraints:
	* The number of nodes in the tree is in the range [1, 1000].
	* -100 <= Node.val <= 100

	Follow up: Could you solve it both recursively and iteratively?*/

    bool isSymmetric(TreeNode* root) {
        TreeNode* p, *q; 
        
        stack<TreeNode*> stk; 
        stk.push(root->left);
        stk.push(root->right); 
        
        while (!stk.empty()) {
            p = stk.top(); // stack::pop() doesn't return
            stk.pop(); 
            q = stk.top();
            stk.pop(); 
            if (p == NULL && q == NULL) continue; 
            if (p == NULL || q == NULL || p->val != q->val) return false; 
            stk.push(p->left); 
            stk.push(q->right);
            stk.push(p->right);
            stk.push(q->left); 
        }
        return true; 
    }


    /*104. Maximum Depth of Binary Tree (Easy)
	Given the root of a binary tree, return its maximum depth. A binary tree's 
	maximum depth is the number of nodes along the longest path from the root 
	node down to the farthest leaf node.

	Example 1:
	Input: root = [3,9,20,null,null,15,7]
	Output: 3

	Example 2:
	Input: root = [1,null,2]
	Output: 2

	Example 3:
	Input: root = []
	Output: 0

	Example 4:
	Input: root = [0]
	Output: 1

	Constraints:
	* The number of nodes in the tree is in the range [0, 10^4].
	* -100 <= Node.val <= 100*/

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0; 
        return 1 + max(maxDepth(root->left), maxDepth(root->right)); 
    }


    /*108. Convert Sorted Array to Binary Search Tree (Easy)
	Given an integer array nums where the elements are sorted in ascending 
	order, convert it to a height-balanced binary search tree. A height-
	balanced binary tree is a binary tree in which the depth of the two 
	subtrees of every node never differs by more than one.

	Example 1:
	Input: nums = [-10,-3,0,5,9]
	Output: [0,-3,9,-10,null,5]
	Explanation: [0,-10,5,null,-3,null,9] is also accepted:

	Example 2:
	Input: nums = [1,3]
	Output: [3,1]
	Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

	Constraints:
	* 1 <= nums.length <= 10^4
	* -10^4 <= nums[i] <= 10^4
	* nums is sorted in a strictly increasing order.*/

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

    TreeNode* sortedArrayToBST(vector<int>& nums, int lo = 0, int hi = -1) {
        if (hi == -1) hi = nums.size(); 
        if (lo == hi) return NULL; 
        int mid = lo + (hi - lo)/2; 
        TreeNode *node = new TreeNode(nums[mid]); 
        node->left = sortedArrayToBST(nums, lo, mid); 
        node->right = sortedArrayToBST(nums, mid+1, hi); 
        return node; 
    }


    /*111. Minimum Depth of Binary Tree (Easy)
	Given a binary tree, find its minimum depth. The minimum depth is the 
	number of nodes along the shortest path from the root node down to the 
	nearest leaf node. Note that a leaf is a node with no children.

	Example 1:
	Input: root = [3,9,20,null,null,15,7]
	Output: 2

	Example 2:
	Input: root = [2,null,3,null,4,null,5,null,6]
	Output: 5

	Constraints:
	* The number of nodes in the tree is in the range [0, 10^5].
	* -1000 <= Node.val <= 1000*/

    int minDepth(TreeNode* root) {
        if (root != NULL) {
            int ans = 0; 
            queue<TreeNode*> q; 
            q.push(root); 

            while (!q.empty()) {
                ++ans; 
                for (int i = 0, n = q.size(); i < n; ++i) {
                    TreeNode* node = q.front(); 
                    q.pop(); 
                    if (node->left == NULL && node->right == NULL) return ans; 
                    if (node->left != NULL) q.push(node->left); 
                    if (node->right != NULL) q.push(node->right); 
                }
            }
        }
        return 0; 
    }


    /*144. Binary Tree Preorder Traversal (Medium)
	Given the root of a binary tree, return the preorder traversal of its 
	nodes' values.

	Example 1:
	Input: root = [1,null,2,3]
	Output: [1,2,3]

	Example 2:
	Input: root = []
	Output: []

	Example 3:
	Input: root = [1]
	Output: [1]

	Example 4:
	Input: root = [1,2]
	Output: [1,2]

	Example 5:
	Input: root = [1,null,2]
	Output: [1,2]

	Constraints:
	* The number of nodes in the tree is in the range [0, 100].
	* -100 <= Node.val <= 100

	Follow up: Recursive solution is trivial, could you do it iteratively?*/

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; 
        stack<TreeNode*> stk; 
        stk.push(root); 
        while (!stk.empty()) {
            TreeNode* node = stk.top(); 
            stk.pop(); 
            if (node) {
                ans.push_back(node->val); 
                stk.push(node->right);
                stk.push(node->left); 
            }
        }
        return ans; 
    }


    /*145. Binary Tree Postorder Traversal (Medium)
	Given the root of a binary tree, return the postorder traversal of its 
	nodes' values.

	Example 1:
	Input: root = [1,null,2,3]
	Output: [3,2,1]

	Example 2:
	Input: root = []
	Output: []

	Example 3:
	Input: root = [1]
	Output: [1]

	Example 4:
	Input: root = [1,2]
	Output: [2,1]

	Example 5:
	Input: root = [1,null,2]
	Output: [2,1]

	Constraints:
	* The number of the nodes in the tree is in the range [0, 100].
	* -100 <= Node.val <= 100

	Follow up: Recursive solution is trivial, could you do it iteratively?*/

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; 
        TreeNode *node = root, *prev = NULL; 
        stack<TreeNode*> stk; 
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node); 
                node = node->left; 
            } else {
                node = stk.top(); 
                if (node->right && node->right != prev) 
                    node = node->right; 
                else {
                    ans.push_back(node->val); 
                    stk.pop(); 
                    prev = node; 
                    node = NULL; 
                }
            }
        }
        return ans; 
    }


    /*234. Palindrome Linked List (Easy)
	Given the head of a singly linked list, return true if it is a palindrome.

	Example 1:
	Input: head = [1,2,2,1]
	Output: true

	Example 2:
	Input: head = [1,2]
	Output: false

	Constraints:
	* The number of nodes in the list is in the range [1, 10^5].
	* 0 <= Node.val <= 9

	Follow up: Could you do it in O(n) time and O(1) space?*/

    bool isPalindrome(ListNode* head) {
        // find mid-point
        ListNode *fast = head, *slow = head; 
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next; 
        }
        
        // reverse 2nd half
        ListNode *prev = NULL; 
        while (slow) {
            ListNode* temp = slow->next; 
            slow->next = prev; 
            prev = slow;
            slow = temp; 
        }
        
        // check for palindrome 
        while (head && prev) {
            if (head->val != prev->val) return false; 
            head = head->next; 
            prev = prev->next; 
        }
        return true; 
    }



    /*235. Lowest Common Ancestor of a Binary Search Tree (Easy)
	Given a binary search tree (BST), find the lowest common ancestor (LCA) of 
	two given nodes in the BST. According to the definition of LCA on Wikipedia: 
	“The lowest common ancestor is defined between two nodes p and q as the 
	lowest node in T that has both p and q as descendants (where we allow a 
	node to be a descendant of itself).”

	Example 1:
	Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
	Output: 6
	Explanation: The LCA of nodes 2 and 8 is 6.

	Example 2:
	Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
	Output: 2
	Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant 
	             of itself according to the LCA definition.

	Example 3:
	Input: root = [2,1], p = 2, q = 1
	Output: 2

	Constraints:
	* The number of nodes in the tree is in the range [2, 10^5].
	* -10^9 <= Node.val <= 10^9
	* All Node.val are unique.
	* p != q
	* p and q will exist in the BST.*/

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            TreeNode* temp = p; 
            p = q; 
            q = temp; 
        }
        
        TreeNode* node = root; 
        while (node) {
            if (node->val < p->val) 
                node = node->right; 
            else if (q->val < node->val)
                node = node->left;
            else 
                break; 
        }
        return node; 
    }


    /*237. Delete Node in a Linked List (Easy)
	Write a function to delete a node in a singly-linked list. You will not be 
	given access to the head of the list, instead you will be given access to 
	the node to be deleted directly. It is guaranteed that the node to be 
	deleted is not a tail node in the list.

	Example 1:
	Input: head = [4,5,1,9], node = 5
	Output: [4,1,9]
	Explanation: You are given the second node with value 5, the linked list 
	             should become 4 -> 1 -> 9 after calling your function.

	Example 2:
	Input: head = [4,5,1,9], node = 1
	Output: [4,5,9]
	Explanation: You are given the third node with value 1, the linked list 
	             should become 4 -> 5 -> 9 after calling your function.
	
	Example 3:
	Input: head = [1,2,3,4], node = 3
	Output: [1,2,4]

	Example 4:
	Input: head = [0,1], node = 0
	Output: [1]

	Example 5:
	Input: head = [-3,5,-99], node = -3
	Output: [5,-99]

	Constraints:
	* The number of the nodes in the given list is in the range [2, 1000].
	* -1000 <= Node.val <= 1000
	* The value of each node in the list is unique.
	* The node to be deleted is in the list and is not a tail node*/

    void deleteNode(ListNode* node) {
        ListNode* temp = node->next; 
        node->val = node->next->val;
        node->next = node->next->next; 
        delete temp; 
    }


    /*242. Valid Anagram (Easy)
	Given two strings s and t, return true if t is an anagram of s, and false 
	otherwise.

	Example 1:
	Input: s = "anagram", t = "nagaram"
	Output: true

	Example 2:
	Input: s = "rat", t = "car"
	Output: false

	Constraints:
	* 1 <= s.length, t.length <= 5 * 10^4
	* s and t consist of lowercase English letters.

	Follow up: What if the inputs contain Unicode characters? How would you 
	           adapt your solution to such a case?*/

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; 
        
        vector<int> freq(26, 0); 
        for (int i = 0; i < s.length(); ++i) {
            ++freq[s[i] - 'a']; 
            --freq[t[i] - 'a'];
        }
        
        for (auto x : freq) {
            if (x) return false; 
        }
        return true; 
    }


    /*257. Binary Tree Paths (Easy)
	Given the root of a binary tree, return all root-to-leaf paths in any 
	order. A leaf is a node with no children.

	Example 1:
	Input: root = [1,2,3,null,5]
	Output: ["1->2->5","1->3"]

	Example 2:
	Input: root = [1]
	Output: ["1"]

	Constraints:
	* The number of nodes in the tree is in the range [1, 100].
	* -100 <= Node.val <= 100*/

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans; 
        
        stack<pair<TreeNode*, string>> stk; 
        stk.push(make_pair(root, to_string(root->val))); 
        
        while(!stk.empty()) {
            TreeNode* node = stk.top().first;
            string path = stk.top().second; 
            stk.pop(); 
            
            if (node->left == NULL && node->right == NULL)
                ans.push_back(path); 
            
            if (node->left) {
                stk.push(make_pair(node->left, path+"->"+to_string(node->left->val))); 
            }
            if (node->right) {
                stk.push(make_pair(node->right, path+"->"+to_string(node->right->val))); 
            }
        }
        return ans; 
    }


    /*258. Add Digits (Easy)
	Given an integer num, repeatedly add all its digits until the result has 
	only one digit, and return it.

	Example 1:
	Input: num = 38
	Output: 2
	Explanation: The process is
	38 --> 3 + 8 --> 11
	11 --> 1 + 1 --> 2 
	Since 2 has only one digit, return it.

	Example 2:
	Input: num = 0
	Output: 0

	Constraints: 0 <= num <= 2^31 - 1

	Follow up: Could you do it without any loop/recursion in O(1) runtime?*/

    int addDigits(int num) {
        return 1 + (num - 1) % 9; 
    }


    /*263. Ugly Number (Easy)
	Given an integer n, return true if n is an ugly number. Ugly number is a 
	positive number whose prime factors only include 2, 3, and/or 5.

	Example 1:
	Input: n = 6
	Output: true
	Explanation: 6 = 2 × 3

	Example 2:
	Input: n = 8
	Output: true
	Explanation: 8 = 2 × 2 × 2

	Example 3:
	Input: n = 14
	Output: false
	Explanation: 14 is not ugly since it includes another prime factor 7.

	Example 4:
	Input: n = 1
	Output: true
	Explanation: 1 is typically treated as an ugly number.

	Constraints: -2^31 <= n <= 2^31 - 1*/

    bool isUgly(int n) {
        if (n <= 0) return false; 
        
        while (n > 1) {
            if (n % 2 == 0) n /= 2; 
            else if (n % 3 == 0) n /= 3; 
            else if (n % 5 == 0) n /= 5; 
            else return false;
        }
        return true; 
    }


    /*268. Missing Number (Easy)
	Given an array nums containing n distinct numbers in the range [0, n], 
	return the only number in the range that is missing from the array. 

	Follow up: Could you implement a solution using only O(1) extra space 
	           complexity and O(n) runtime complexity?

	Example 1:
	Input: nums = [3,0,1]
	Output: 2
	Explanation: n = 3 since there are 3 numbers, so all numbers are in the 
	             range [0,3]. 2 is the missing number in the range since it 
	             does not appear in nums.
	
	Example 2:
	Input: nums = [0,1]
	Output: 2
	Explanation: n = 2 since there are 2 numbers, so all numbers are in the 
	             range [0,2]. 2 is the missing number in the range since it 
	             does not appear in nums.
	
	Example 3:
	Input: nums = [9,6,4,2,3,5,7,0,1]
	Output: 8
	Explanation: n = 9 since there are 9 numbers, so all numbers are in the 
	             range [0,9]. 8 is the missing number in the range since it 
	             does not appear in nums.
	
	Example 4:
	Input: nums = [0]
	Output: 1
	Explanation: n = 1 since there is 1 number, so all numbers are in the range 
	             [0,1]. 1 is the missing number in the range since it does not 
	             appear in nums.

	Constraints:
	* n == nums.length
	* 1 <= n <= 10^4
	* 0 <= nums[i] <= n
	* All the numbers of nums are unique.*/

    int missingNumber(vector<int>& nums) {
        int ans = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= i+1; 
            ans ^= nums[i]; 
        }
        return ans; 
    }


    /*278. First Bad Version (Easy)
	You are a product manager and currently leading a team to develop a new 
	product. Unfortunately, the latest version of your product fails the 
	quality check. Since each version is developed based on the previous 
	version, all the versions after a bad version are also bad. Suppose you 
	have n versions [1, 2, ..., n] and you want to find out the first bad one, 
	which causes all the following ones to be bad. You are given an API bool 
	isBadVersion(version) which returns whether version is bad. Implement a 
	function to find the first bad version. You should minimize the number of 
	calls to the API.

	Example 1:
	Input: n = 5, bad = 4
	Output: 4
	Explanation:
	call isBadVersion(3) -> false
	call isBadVersion(5) -> true
	call isBadVersion(4) -> true
	Then 4 is the first bad version.

	Example 2:
	Input: n = 1, bad = 1
	Output: 1

	Constraints: 1 <= bad <= n <= 2^31 - 1*/

    int firstBadVersion(int n) {
        int lo = 1, hi = n; 
        while (lo < hi) {
            int mid = lo + (hi - lo)/2; 
            if (isBadVersion(mid)) {
                hi = mid; 
            } else {
                lo = mid + 1; 
            }
        }
        return lo; 
    }


    /*283. Move Zeroes (Easy)
	Given an integer array nums, move all 0's to the end of it while 
	maintaining the relative order of the non-zero elements. Note that you must 
	do this in-place without making a copy of the array.

	Example 1:
	Input: nums = [0,1,0,3,12]
	Output: [1,3,12,0,0]

	Example 2:
	Input: nums = [0]
	Output: [0]

	Constraints:
	* 1 <= nums.length <= 10^4
	* -2^31 <= nums[i] <= 2^31 - 1

	Follow up: Could you minimize the total number of operations done?*/

    void moveZeroes(vector<int>& nums) {
        int ii = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[ii], nums[i]); 
                ++ii; 
            }
        }
    }


    /*290. Word Pattern (Easy)
	Given a pattern and a string s, find if s follows the same pattern. Here 
	follow means a full match, such that there is a bijection between a letter 
	in pattern and a non-empty word in s.

	Example 1:
	Input: pattern = "abba", s = "dog cat cat dog"
	Output: true

	Example 2:
	Input: pattern = "abba", s = "dog cat cat fish"
	Output: false

	Example 3:
	Input: pattern = "aaaa", s = "dog cat cat dog"
	Output: false

	Example 4:
	Input: pattern = "abba", s = "dog dog dog dog"
	Output: false

	Constraints:
	* 1 <= pattern.length <= 300
	* pattern contains only lower-case English letters.
	* 1 <= s.length <= 3000
	* s contains only lower-case English letters and spaces ' '.
	* s does not contain any leading or trailing spaces.
	* All the words in s are separated by a single space.*/

    bool wordPattern(string pattern, string s) {
        istringstream iss(s); 
        string buf; 
        vector<string> words; 
        while (iss >> buf) {
            words.push_back(buf); 
        }

        if (pattern.size() != words.size()) return false; 
        
        unordered_map<char, int> mpp; 
        unordered_map<string, int> mpw; 
        
        for (int i = 0; i < pattern.length(); ++i) {
            if (mpp[pattern[i]] != mpw[words[i]])
                return false; 
            mpp[pattern[i]] = mpw[words[i]] = i+1; 
        }
        return true; 
    }


    /*292. Nim Game (Easy)
	You are playing the following Nim Game with your friend:
	* Initially, there is a heap of stones on the table.
	* You and your friend will alternate taking turns, and you go first.
	* On each turn, the person whose turn it is will remove 1 to 3 stones from 
	  the heap.
	* The one who removes the last stone is the winner.
	Given n, the number of stones in the heap, return true if you can win the 
	game assuming both you and your friend play optimally, otherwise return 
	false.

	Example 1:
	Input: n = 4
	Output: false
	Explanation: These are the possible outcomes:
	1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
	2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
	3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
	In all outcomes, your friend wins.

	Example 2:
	Input: n = 1
	Output: true

	Example 3:
	Input: n = 2
	Output: true

	Constraints: 1 <= n <= 2^31 - 1*/

    bool canWinNim(int n) {
        return n % 4; 
    }


    /*377. Combination Sum IV (Medium)
	Given an array of distinct integers nums and a target integer target, 
	return the number of possible combinations that add up to target. The 
	answer is guaranteed to fit in a 32-bit integer.

	Example 1:
	Input: nums = [1,2,3], target = 4
	Output: 7
	Explanation:
	The possible combination ways are:
	(1, 1, 1, 1)
	(1, 1, 2)
	(1, 2, 1)
	(1, 3)
	(2, 1, 1)
	(2, 2)
	(3, 1)
	Note that different sequences are counted as different combinations.

	Example 2:
	Input: nums = [9], target = 3
	Output: 0

	Constraints:
	* 1 <= nums.length <= 200
	* 1 <= nums[i] <= 1000
	* All the elements of nums are unique.
	* 1 <= target <= 1000

	Follow up: What if negative numbers are allowed in the given array? How 
	           does it change the problem? What limitation we need to add to 
	           the question to allow negative numbers?*/

    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(1+target, 0); 
        dp[0] = 1; 
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i]) {
                for (auto x: nums) {
                    if (i + x < dp.size()) 
                        dp[i+x] += dp[i]; 
                }
            }
        } 
        return dp.back(); 
    }


    /*504. Base 7 (Easy)
	Given an integer, return its base 7 string representation.

	Example 1:
	Input: 100
	Output: "202"
	
	Example 2:
	Input: -7
	Output: "-10"
	
	Note: The input will be in range of [-1e7, 1e7].*/

    string convertToBase7(int num) {
        if (num == 0) return "0"; // edge case 
        
        string ans; 
        bool neg = num < 0; 
        num = abs(num); 
        while (num) {
            ans = to_string(num%7) + ans; 
            num /= 7; 
        }
        return neg ? "-" + ans : ans; 
    }


    /*559. Maximum Depth of N-ary Tree (Easy)
	Given a n-ary tree, find its maximum depth. The maximum depth is the number 
	of nodes along the longest path from the root node down to the farthest 
	leaf node. Nary-Tree input serialization is represented in their level 
	order traversal, each group of children is separated by the null value (See 
	examples).

	Example 1:
	Input: root = [1,null,3,2,4,null,5,6]
	Output: 3

	Example 2:
	Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
	Output: 5

	Constraints:
	* The depth of the n-ary tree is less than or equal to 1000.
	* The total number of nodes is between [0, 10^4].*/

    int maxDepth(Node* root) {
        if (!root) return 0; // edge case 
        
        queue<Node*> q; 
        q.push(root); 
        int ans = 0; 
        while (!q.empty()) {
            ++ans; 
            for (int i = 0, n = q.size(); i < n; ++i) {
                Node* node = q.front(); 
                q.pop(); 
                for (auto &child : node->children) {
                    q.push(child); 
                }
            }
        }
        return ans; 
    }


    /*561. Array Partition I (Easy)
	Given an integer array nums of 2n integers, group these integers into n 
	pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) 
	for all i is maximized. Return the maximized sum.

	Example 1:
	Input: nums = [1,4,3,2]
	Output: 4
	Explanation: All possible pairings (ignoring the ordering of elements) are:
	1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
	2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
	3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
	So the maximum possible sum is 4.

	Example 2:
	Input: nums = [6,2,6,5,1,2]
	Output: 9
	Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.

	Constraints:
	* 1 <= n <= 10^4
	* nums.length == 2 * n
	* -10^4 <= nums[i] <= 10^4*/

    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int ans = 0; 
        for (int i = 0; i < nums.size(); i += 2)
            ans += nums[i]; 
        return ans; 
    }


    /*566. Reshape the Matrix (Easy)
	In MATLAB, there is a very useful function called 'reshape', which can 
	reshape a matrix into a new one with different size but keep its original 
	data. You're given a matrix represented by a two-dimensional array, and two 
	positive integers r and c representing the row number and column number of 
	the wanted reshaped matrix, respectively. The reshaped matrix need to be 
	filled with all the elements of the original matrix in the same row-
	traversing order as they were. If the 'reshape' operation with given 
	parameters is possible and legal, output the new reshaped matrix; Otherwise, 
	output the original matrix.

	Example 1:
	Input: nums = [[1,2], [3,4]], r = 1, c = 4
	Output:	[[1,2,3,4]]
	Explanation: The row-traversing of nums is [1,2,3,4]. The new reshaped 
	             matrix is a 1 * 4 matrix, fill it row by row by using the 
	             previous list.
	
	Example 2: 
	Input: nums = [[1,2], [3,4]], r = 2, c = 4
	Output: [[1,2],  [3,4]]
	Explanation: There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. 
	             So output the original matrix.
	
	Note:
	* The height and width of the given matrix is in range [1, 100].
	* The given r and c are all positive.*/

    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size(); 
        if (m * n != r * c) return nums; // incompatable 
        
        vector<vector<int>> ans(r, vector<int>(c)); 
        for (int i = 0; i < r*c; ++i) {
            ans[i/c][i%c] = nums[i/n][i%n]; 
        }
        return ans; 
    }


    /*572. Subtree of Another Tree (Easy)
	Given two non-empty binary trees s and t, check whether tree t has exactly 
	the same structure and node values with a subtree of s. A subtree of s is a 
	tree consists of a node in s and all of this node's descendants. The tree s 
	could also be considered as a subtree of itself.

	Example 1:
	Given tree s:

	     3
	    / \
	   4   5
	  / \
	 1   2
	Given tree t:
	   4 
	  / \
	 1   2
	Return true, because t has the same structure and node values with a subtree of s.

	Example 2:
	Given tree s:

	     3
	    / \
	   4   5
	  / \
	 1   2
	    /
	   0
	Given tree t:
	   4
	  / \
	 1   2
	Return false.*/

    /*
    bool check(TreeNode* ss, TreeNode* tt) {
        if (!ss && !tt) return true; 
        if (!ss || !tt) return false; 
        return (ss->val == tt->val) && check(ss->left, tt->left) && check(ss->right, tt->right); 
    }*/
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        stack<TreeNode*> stk; 
        stk.push(s); 
        
        while (!stk.empty()) {
            TreeNode* node = stk.top(); 
            stk.pop();
            if (node) {
                if (check(node, t)) return true; 
                stk.push(node->right); 
                stk.push(node->left); 
            }
        }
        return false; 
    }


    /*575. Distribute Candies (Easy)
	Alice has n candies, where the ith candy is of type candyType[i]. Alice 
	noticed that she started to gain weight, so she visited a doctor. The 
	doctor advised Alice to only eat n / 2 of the candies she has (n is always 
	even). Alice likes her candies very much, and she wants to eat the maximum 
	number of different types of candies while still following the doctor's 
	advice. Given the integer array candyType of length n, return the maximum 
	number of different types of candies she can eat if she only eats n / 2 of 
	them.

	Example 1:
	Input: candyType = [1,1,2,2,3,3]
	Output: 3
	Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 
	             types, she can eat one of each type.

	Example 2:
	Input: candyType = [1,1,2,3]
	Output: 2
	Explanation: Alice can only eat 4 / 2 = 2 candies. Whether she eats types 
	             [1,2], [1,3], or [2,3], she still can only eat 2 different 
	             types.
	
	Example 3:
	Input: candyType = [6,6,6,6]
	Output: 1
	Explanation: Alice can only eat 4 / 2 = 2 candies. Even though she can eat 
	             2 candies, she only has 1 type.

	Constraints:
	* n == candyType.length
	* 2 <= n <= 10^4
	* n is even.
	* -10^5 <= candyType[i] <= 10^5*/

    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> freq; 
        for (auto &x : candyType) {
            ++freq[x]; 
        }
        return min(candyType.size()/2, freq.size()); 
    }


    /*637. Average of Levels in Binary Tree (Easy)
	Given the root of a binary tree, return the average value of the nodes on 
	each level in the form of an array. Answers within 10-5 of the actual 
	answer will be accepted.

	Example 1:
	Input: root = [3,9,20,null,15,7]
	Output: [3.00000,14.50000,11.00000]
	Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, 
	             and on level 2 is 11. Hence return [3, 14.5, 11].

	Example 2:
	Input: root = [3,9,20,15,7]
	Output: [3.00000,14.50000,11.00000]

	Constraints:
	* The number of nodes in the tree is in the range [1, 10^4].
	* -2^31 <= Node.val <= 2^31 - 1*/

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans; 
        
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) {
            double sm = 0, cnt = 0; 
            for (int i = 0, n = q.size(); i < n; ++i) {
                TreeNode* node = q.front(); 
                q.pop(); 
                if (node) {
                    sm += node->val; 
                    ++cnt; 
                    q.push(node->left);
                    q.push(node->right); 
                }
            }
            if (cnt) ans.push_back(sm/cnt); 
        }
        return ans; 
    }


    /*643. Maximum Average Subarray I (Easy)
	Given an array consisting of n integers, find the contiguous subarray of 
	given length k that has the maximum average value. And you need to output 
	the maximum average value.

	Example 1:
	Input: [1,12,-5,-6,50,3], k = 4
	Output: 12.75
	Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75

	Note:
	* 1 <= k <= n <= 30,000.
	* Elements of the given array will be in the range [-10,000, 10,000].*/

    double findMaxAverage(vector<int>& nums, int k) {
        int ans = INT_MIN, sm = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            sm += nums[i]; 
            if (i >= k) sm -= nums[i-k]; 
            if (i >= k-1) ans = max(ans, sm);
        }
        return (double) ans/k; 
    }


    /*653. Two Sum IV - Input is a BST (Easy)
	Given the root of a Binary Search Tree and a target number k, return true 
	if there exist two elements in the BST such that their sum is equal to the 
	given target.

	Example 1:
	Input: root = [5,3,6,2,4,null,7], k = 9
	Output: true

	Example 2:
	Input: root = [5,3,6,2,4,null,7], k = 28
	Output: false

	Example 3:
	Input: root = [2,1,3], k = 4
	Output: true

	Example 4:
	Input: root = [2,1,3], k = 1
	Output: false

	Example 5:
	Input: root = [2,1,3], k = 3
	Output: true

	Constraints:
	* The number of nodes in the tree is in the range [1, 10^4].
	* -10^4 <= Node.val <= 10^4
	* root is guaranteed to be a valid binary search tree.
	* -10^5 <= k <= 10^5*/

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen; 
        stack<TreeNode*> stk; 
        stk.push(root); 
        
        while (!stk.empty()) {
            TreeNode* node = stk.top(); 
            stk.pop(); 
            if (node) {
                if (seen.count(k - node->val)) return true; 
                seen.insert(node->val); 
                stk.push(node->right);
                stk.push(node->left); 
            }
        }
        return false; 
    }


    /*680. Valid Palindrome II (Easy)
	Given a non-empty string s, you may delete at most one character. Judge 
	whether you can make it a palindrome.

	Example 1:
	Input: "aba"
	Output: True
	
	Example 2:
	Input: "abca"
	Output: True
	Explanation: You could delete the character 'c'.
	
	Note: The string will only contain lowercase characters a-z. The maximum 
	length of the string is 50000.*/

    bool validPalindrome(string s) {
        for (int lo = 0, hi = s.size()-1; lo < hi; ++lo, --hi) {
            if (s[lo] != s[hi]) {
                for (int l = lo+1, h = hi; s[l] == s[h]; ++l, --h) 
                    if (l >= h) return true; 
                for (int l = lo, h = hi-1; s[l] == s[h]; ++l, --h) 
                    if (l >= h) return true; 
                return false; 
            }
        }
        return true; 
    }


    /*682. Baseball Game (Easy)
	You are keeping score for a baseball game with strange rules. The game 
	consists of several rounds, where the scores of past rounds may affect 
	future rounds' scores. At the beginning of the game, you start with an 
	empty record. You are given a list of strings ops, where ops[i] is the 
	ith operation you must apply to the record and is one of the following:
	* An integer x - Record a new score of x.
	* "+" - Record a new score that is the sum of the previous two scores. It 
	  is guaranteed there will always be two previous scores.
	* "D" - Record a new score that is double the previous score. It is 
	  guaranteed there will always be a previous score.
	* "C" - Invalidate the previous score, removing it from the record. It is 
	  guaranteed there will always be a previous score.
	Return the sum of all the scores on the record.

	Example 1:
	Input: ops = ["5","2","C","D","+"]
	Output: 30
	Explanation:
	"5" - Add 5 to the record, record is now [5].
	"2" - Add 2 to the record, record is now [5, 2].
	"C" - Invalidate and remove the previous score, record is now [5].
	"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
	"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
	The total sum is 5 + 10 + 15 = 30.

	Example 2:
	Input: ops = ["5","-2","4","C","D","9","+","+"]
	Output: 27
	Explanation:
	"5" - Add 5 to the record, record is now [5].
	"-2" - Add -2 to the record, record is now [5, -2].
	"4" - Add 4 to the record, record is now [5, -2, 4].
	"C" - Invalidate and remove the previous score, record is now [5, -2].
	"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
	"9" - Add 9 to the record, record is now [5, -2, -4, 9].
	"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
	"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
	The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

	Example 3:
	Input: ops = ["1"]
	Output: 1

	Constraints:
	* 1 <= ops.length <= 1000
	* ops[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
	* For operation "+", there will always be at least two previous scores on the record.
	* For operations "C" and "D", there will always be at least one previous score on the record.*/

    int calPoints(vector<string>& ops) {
        vector<int> vec; 
        for (auto& op : ops) {
            if (op == "+") {
                vec.push_back(vec[vec.size()-2] + vec[vec.size()-1]); 
            } else if (op == "D") {
                vec.push_back(vec.back() * 2); 
            } else if (op == "C") {
                vec.pop_back(); 
            } else {
                vec.push_back(stoi(op)); 
            }
        }
        return accumulate(vec.begin(), vec.end(), 0); 
    }


    /*690. Employee Importance (Easy)
	You are given a data structure of employee information, which includes the 
	employee's unique id, their importance value and their direct subordinates' 
	id. For example, employee 1 is the leader of employee 2, and employee 2 is 
	the leader of employee 3. They have importance value 15, 10 and 5, 
	respectively. Then employee 1 has a data structure like [1, 15, [2]], and 
	employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that 
	although employee 3 is also a subordinate of employee 1, the relationship 
	is not direct. Now given the employee information of a company, and an 
	employee id, you need to return the total importance value of this employee 
	and all their subordinates.

	Example 1:
	Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
	Output: 11
	Explanation: Employee 1 has importance value 5, and he has two direct 
	             subordinates: employee 2 and employee 3. They both have 
	             importance value 3. So the total importance value of employee 
	             1 is 5 + 3 + 3 = 11.

	Note:
	* One employee has at most one direct leader and may have several subordinates.
	* The maximum number of employees won't exceed 2000.*/

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp; 
        for (auto& employee : employees) 
            mp.insert({employee->id, employee}); 
        
        stack<int> stk; 
        stk.push(id); 
        int ans = 0; 
        while (!stk.empty()) {
            int id = stk.top(); 
            stk.pop(); 
            Employee* employee = mp[id]; 
            ans += employee->importance; 
            for (auto& x : employee->subordinates) 
                stk.push(x); 
        }
        return ans; 
    }


    /*693. Binary Number with Alternating Bits (Easy)
	Given a positive integer, check whether it has alternating bits: namely, if 
	two adjacent bits will always have different values.

	Example 1:
	Input: n = 5
	Output: true
	Explanation: The binary representation of 5 is: 101

	Example 2:
	Input: n = 7
	Output: false
	Explanation: The binary representation of 7 is: 111.

	Example 3:
	Input: n = 11
	Output: false
	Explanation: The binary representation of 11 is: 1011.

	Example 4:
	Input: n = 10
	Output: true
	Explanation: The binary representation of 10 is: 1010.

	Example 5:
	Input: n = 3
	Output: false

	Constraints: 1 <= n <= 2^31 - 1*/

    bool hasAlternatingBits(int n) {
        long nn = n ^ (n >> 1); 
        return (nn & (nn+1)) == 0;
    }


    /*696. Count Binary Substrings (Easy)
	Give a string s, count the number of non-empty (contiguous) substrings that 
	have the same number of 0's and 1's, and all the 0's and all the 1's in 
	these substrings are grouped consecutively. Substrings that occur multiple 
	times are counted the number of times they occur.

	Example 1:
	Input: "00110011"
	Output: 6
	Explanation: There are 6 substrings that have equal number of consecutive 
	             1's and 0's: "0011", "01", "1100", "10", "0011", and "01". 
	             Notice that some of these substrings repeat and are counted 
	             the number of times they occur. Also, "00110011" is not a 
	             valid substring because all the 0's (and 1's) are not grouped 
	             together.

	Example 2:
	Input: "10101"
	Output: 4
	Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal 
	             number of consecutive 1's and 0's.
	
	Note:
	* s.length will be between 1 and 50,000.
	* s will only consist of "0" or "1" characters.*/

    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, curr = 0; 
        for (int i = 0; i < s.size(); ++i) {
            if (i && s[i-1] != s[i]) {
                prev = curr; 
                curr = 0; 
            }
            if (prev >= ++curr) ans += 1; 
        }
        return ans; 
    }


    /*697. Degree of an Array (Easy)
	Given a non-empty array of non-negative integers nums, the degree of this 
	array is defined as the maximum frequency of any one of its elements. Your 
	task is to find the smallest possible length of a (contiguous) subarray of 
	nums, that has the same degree as nums.

	Example 1:
	Input: nums = [1,2,2,3,1]
	Output: 2
	Explanation: 
	The input array has a degree of 2 because both elements 1 and 2 appear twice.
	Of the subarrays that have the same degree:
	[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
	The shortest length is 2. So return 2.

	Example 2:
	Input: nums = [1,2,2,3,1,4,2]
	Output: 6
	Explanation: 
	The degree is 3 because the element 2 is repeated 3 times.
	So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

	Constraints:
	* nums.length will be between 1 and 50,000.
	* nums[i] will be an integer between 0 and 49,999.*/

    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, seen; 
        int ans = INT_MAX, most = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            seen.insert({nums[i], i}); 
            if (most <= ++freq[nums[i]]) {
                if (most < freq[nums[i]]) ans = i - seen[nums[i]] + 1; 
                else ans = min(ans, i - seen[nums[i]] + 1); 
                most = freq[nums[i]]; 
            }
        }
        return ans; 
    }


    /*700. Search in a Binary Search Tree (Easy)
	You are given the root of a binary search tree (BST) and an integer val. 
	Find the node in the BST that the node's value equals val and return the 
	subtree rooted with that node. If such a node does not exist, return null.

	Example 1:
	Input: root = [4,2,7,1,3], val = 2
	Output: [2,1,3]

	Example 2:
	Input: root = [4,2,7,1,3], val = 5
	Output: []

	Constraints:
	* The number of nodes in the tree is in the range [1, 5000].
	* 1 <= Node.val <= 10^7
	* root is a binary search tree.
	* 1 <= val <= 10^7*/

    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (root->val == val) return root; 
            if (root->val < val) root = root->right; 
            else root = root->left; 
        }
        return NULL; 
    }


    /*709. To Lower Case (Easy)
	Implement function ToLowerCase() that has a string parameter str, and 
	returns the same string in lowercase.

	Example 1:
	Input: "Hello"
	Output: "hello"

	Example 2:
	Input: "here"
	Output: "here"

	Example 3:
	Input: "LOVELY"
	Output: "lovely"*/

    string toLowerCase(string str) {
        for (auto& c : str) {
            if ('A' <= c && c <= 'Z') 
                c += 32; 
        }
        return str; 
    }


    /*717. 1-bit and 2-bit Characters (Easy)
	We have two special characters. The first character can be represented by 
	one bit 0. The second character can be represented by two bits (10 or 11).
	Now given a string represented by several bits. Return whether the last 
	character must be a one-bit character or not. The given string will always 
	end with a zero.

	Example 1:
	Input: bits = [1, 0, 0]
	Output: True
	Explanation: The only way to decode it is two-bit character and one-bit 
	             character. So the last character is one-bit character.
	
	Example 2:
	Input: bits = [1, 1, 1, 0]
	Output: False
	Explanation: The only way to decode it is two-bit character and two-bit 
	             character. So the last character is NOT one-bit character.
	
	Note:
	* 1 <= len(bits) <= 1000.
	* bits[i] is always 0 or 1.*/

    bool isOneBitCharacter(vector<int>& bits) {
        bool ans = false; 
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                ++i; 
                ans = false; 
            } else {
                ans = true; 
            }
        }
        return ans; 
    }


    /*720. Longest Word in Dictionary (Easy)
	Given an array of strings words representing an English Dictionary, return 
	the longest word in words that can be built one character at a time by 
	other words in words. If there is more than one possible answer, return the 
	longest word with the smallest lexicographical order. If there is no answer, 
	return the empty string.

	Example 1:
	Input: words = ["w","wo","wor","worl","world"]
	Output: "world"
	Explanation: The word "world" can be built one character at a time by 
	             "w", "wo", "wor", and "worl".

	Example 2:
	Input: words = ["a","banana","app","appl","ap","apply","apple"]
	Output: "apple"
	Explanation: Both "apply" and "apple" can be built from other words in the 
	             dictionary. However, "apple" is lexicographically smaller than 
	             "apply".

	Constraints:
	* 1 <= words.length <= 1000
	* 1 <= words[i].length <= 30
	* words[i] consists of lowercase English letters.*/

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end()); 
        
        string ans; 
        unordered_set<string> seen = {""}; 
        for (int i = 0; i < words.size(); ++i) {
            int n = words[i].size(); 
            if (seen.count(words[i].substr(0, n-1))) {
                if (n > ans.size())
                    ans = words[i]; 
                seen.insert(words[i]); 
            }
        }
        return ans; 
    }


    /*724. Find Pivot Index (Easy)
	Given an array of integers nums, calculate the pivot index of this array. 
	The pivot index is the index where the sum of all the numbers strictly to 
	the left of the index is equal to the sum of all the numbers strictly to 
	the index's right. If the index is on the left edge of the array, then the 
	left sum is 0 because there are no elements to the left. This also applies 
	to the right edge of the array. Return the leftmost pivot index. If no such 
	index exists, return -1.

	Example 1:
	Input: nums = [1,7,3,6,5,6]
	Output: 3
	Explanation:
	The pivot index is 3.
	Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
	Right sum = nums[4] + nums[5] = 5 + 6 = 11

	Example 2:
	Input: nums = [1,2,3]
	Output: -1
	Explanation:
	There is no index that satisfies the conditions in the problem statement.

	Example 3:
	Input: nums = [2,1,-1]
	Output: 0
	Explanation:
	The pivot index is 0.
	Left sum = 0 (no elements to the left of index 0)
	Right sum = nums[1] + nums[2] = 1 + -1 = 0

	Constraints:
	* 1 <= nums.length <= 10^4
	* -1000 <= nums[i] <= 1000*/

    int pivotIndex(vector<int>& nums) {
        int prefix = 0, suffix = 0; 
        for (auto& x : nums) 
            suffix += x; 
        
        for (int i = 0; i < nums.size(); ++i) {
            suffix -= nums[i]; 
            if (prefix == suffix) return i; 
            prefix += nums[i]; 
        }
        return -1; 
    }


    /*728. Self Dividing Numbers (Easy)
	A self-dividing number is a number that is divisible by every digit it 
	contains. For example, 128 is a self-dividing number because 128 % 1 == 0, 
	128 % 2 == 0, and 128 % 8 == 0. Also, a self-dividing number is not allowed 
	to contain the digit zero. Given a lower and upper number bound, output a 
	list of every possible self dividing number, including the bounds if 
	possible.

	Example 1:
	Input: 
	left = 1, right = 22
	Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
	
	Note: The boundaries of each input argument are 1 <= left <= right <= 10000.*/

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans; 
        for (int x = left, n = 0; x <= right; ++x) {
            for (n = x; n; n /= 10) {
                if (n % 10 == 0 || x % (n%10) != 0) break; 
            }
            if (n == 0) ans.push_back(x); 
        }
        return ans; 
    }


    /*733. Flood Fill (Easy)
	An image is represented by a 2-D array of integers, each integer 
	representing the pixel value of the image (from 0 to 65535). Given a 
	coordinate (sr, sc) representing the starting pixel (row and column) of the 
	flood fill, and a pixel value newColor, "flood fill" the image. To perform 
	a "flood fill", consider the starting pixel, plus any pixels connected 4-
	directionally to the starting pixel of the same color as the starting pixel, 
	plus any pixels connected 4-directionally to those pixels (also with the 
	same color as the starting pixel), and so on. Replace the color of all of 
	the aforementioned pixels with the newColor. At the end, return the 
	modified image.

	Example 1:
	Input: image = [[1,1,1],[1,1,0],[1,0,1]]
	       sr = 1, sc = 1, newColor = 2
	Output: [[2,2,2],[2,2,0],[2,0,1]]
	Explanation: 
	From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
	by a path of the same color as the starting pixel are colored with the new color.
	Note the bottom corner is not colored 2, because it is not 4-directionally connected
	to the starting pixel.
	
	Note:
	* The length of image and image[0] will be in the range [1, 50].
	* The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
	* The value of each color in image[i][j] and newColor will be an integer in [0, 65535].*/

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            int m = image.size(), n = image[0].size(), oldColor = image[sr][sc]; 
            stack<vector<int>> stk; 
            stk.push({sr, sc}); 

            while (!stk.empty()) {
                int i = stk.top()[0], j = stk.top()[1]; 
                stk.pop(); 
                for (auto& d : vector<vector<int>>{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}) {
                    int ii = i + d[0], jj = j + d[1];
                    if (0 <= ii && ii < m && 0 <= jj && jj < n && image[ii][jj] == oldColor) {
                        stk.push({ii, jj}); 
                    }
                }
                image[i][j] = newColor; 
            }
        } 
        return image; 
    }


    /*744. Find Smallest Letter Greater Than Target (Easy)
	Given a list of sorted characters letters containing only lowercase 
	letters, and given a target letter target, find the smallest element in the 
	list that is larger than the given target. Letters also wrap around. For 
	example, if the target is target = 'z' and letters = ['a', 'b'], the answer 
	is 'a'.

	Examples:
	Input: letters = ["c", "f", "j"]
	       target = "a"
	Output: "c"

	Input: letters = ["c", "f", "j"]
	       target = "c"
	Output: "f"

	Input: letters = ["c", "f", "j"]
	       target = "d"
	Output: "f"

	Input: letters = ["c", "f", "j"]
	       target = "g"
	Output: "j"

	Input: letters = ["c", "f", "j"]
	       target = "j"
	Output: "c"

	Input: letters = ["c", "f", "j"]
	       target = "k"
	Output: "c"
	
	Note:
	* letters has a length in range [2, 10000].
	* letters consists of lowercase letters, and contains at least 2 unique 
	  letters.
	* target is a lowercase letter.*/

    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size(); 
        while (lo < hi) {
            int mid = lo + (hi - lo)/2; 
            if (letters[mid] <= target) lo = mid + 1; 
            else hi = mid; 
        }
        return letters[lo % letters.size()]; 
    }


    /*762. Prime Number of Set Bits in Binary Representation (Easy)
	Given two integers L and R, find the count of numbers in the range [L, R] 
	(inclusive) having a prime number of set bits in their binary representation.
	(Recall that the number of set bits an integer has is the number of 1s 
	present when written in binary. For example, 21 written in binary is 10101 
	which has 3 set bits. Also, 1 is not a prime.)

	Example 1:
	Input: L = 6, R = 10
	Output: 4
	Explanation:
	6 -> 110 (2 set bits, 2 is prime)
	7 -> 111 (3 set bits, 3 is prime)
	9 -> 1001 (2 set bits , 2 is prime)
	10->1010 (2 set bits , 2 is prime)

	Example 2:
	Input: L = 10, R = 15
	Output: 5
	Explanation:
	10 -> 1010 (2 set bits, 2 is prime)
	11 -> 1011 (3 set bits, 3 is prime)
	12 -> 1100 (2 set bits, 2 is prime)
	13 -> 1101 (3 set bits, 3 is prime)
	14 -> 1110 (3 set bits, 3 is prime)
	15 -> 1111 (4 set bits, 4 is not prime)

	Note:
	* L, R will be integers L <= R in the range [1, 10^6].
	* R - L will be at most 10000.*/

    int countPrimeSetBits(int L, int R) {
        int ans = 0; 
        for (int x = L; x <= R; ++x) {
            int cnt = __builtin_popcount(x); 
            if (cnt > 1) {
                int d = 2;
                for (; d <= sqrt(cnt); ++d) {
                    if (cnt % d == 0) break; 
                }
                if (d > sqrt(cnt)) ++ans; 
            }
        }
        return ans; 
    }


    /*766. Toeplitz Matrix (Easy)
	Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, 
	return false. A matrix is Toeplitz if every diagonal from top-left to 
	bottom-right has the same elements.

	Example 1:
	Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
	Output: true
	Explanation: In the above grid, the diagonals are:
	"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
	In each diagonal all elements are the same, so the answer is True.

	Example 2:
	Input: matrix = [[1,2],[2,2]]
	Output: false
	Explanation: The diagonal "[1, 2]" has different elements.

	Constraints:
	* m == matrix.length
	* n == matrix[i].length
	* 1 <= m, n <= 20
	* 0 <= matrix[i][j] <= 99
 
	Follow up:
	* What if the matrix is stored on disk, and the memory is limited such that 
	  you can only load at most one row of the matrix into the memory at once?
	* What if the matrix is so large that you can only load up a partial row 
	  into the memory at once?*/

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i-1][j-1] != matrix[i][j]) return false; 
            }
        }
        return true; 
    }


    /*819. Most Common Word (Easy)
	Given a string paragraph and a string array of the banned words banned, 
	return the most frequent word that is not banned. It is guaranteed there is 
	at least one word that is not banned, and that the answer is unique. The 
	words in paragraph are case-insensitive and the answer should be returned 
	in lowercase.

	Example 1:
	Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
	Output: "ball"
	Explanation: 
	"hit" occurs 3 times, but it is a banned word.
	"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
	Note that words in the paragraph are not case sensitive,
	that punctuation is ignored (even if adjacent to words, such as "ball,"), 
	and that "hit" isn't the answer even though it occurs more because it is banned.

	Example 2:
	Input: paragraph = "a.", banned = []
	Output: "a"

	Constraints:
	* 1 <= paragraph.length <= 1000
	* paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
	* 0 <= banned.length <= 100
	* 1 <= banned[i].length <= 10
	* banned[i] consists of only lowercase English letters.*/

    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto& c : paragraph) 
            c = isalpha(c) ? tolower(c) : ' '; 
        
        unordered_map<string, int> freq; 
        unordered_set<string> ss(banned.begin(), banned.end()); 
        
        int cnt = 0; 
        istringstream iss(paragraph); 
        string ans, word; 
        while (iss >> word) {
            if (ss.find(word) == ss.end()) {
                ++freq[word]; 
                if (cnt < freq[word]) {
                    ans = word; 
                    cnt = freq[word]; 
                }
            }
        }
        return ans; 
    }


    /*821. Shortest Distance to a Character (Easy)
	Given a string s and a character c that occurs in s, return an array of 
	integers answer where answer.length == s.length and answer[i] is the 
	distance from index i to the closest occurrence of character c in s. The 
	distance between two indices i and j is abs(i - j), where abs is the 
	absolute value function.

	Example 1:
	Input: s = "loveleetcode", c = "e"
	Output: [3,2,1,0,1,0,0,1,2,2,1,0]
	Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
	The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
	The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 3.
	For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
	The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.

	Example 2:
	Input: s = "aaab", c = "b"
	Output: [3,2,1,0]

	Constraints:
	* 1 <= s.length <= 10^4
	* s[i] and c are lowercase English letters.
	* It is guaranteed that c occurs at least once in s.*/

    vector<int> shortestToChar(string s, char c) {
        vector<int> loc; 
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == c) loc.push_back(i); 
        
        vector<int> ans; 
        int k = 0; 
        for (int i = 0; i < s.size(); ++i) {
            if (k+1 < loc.size() && abs(loc[k+1]-i) < abs(loc[k]-i)) ++k; 
            ans.push_back(abs(loc[k]-i));
        }
        return ans; 
    }


    /*824. Goat Latin (Easy)
	A sentence S is given, composed of words separated by spaces. Each word 
	consists of lowercase and uppercase letters only. We would like to convert 
	the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

	The rules of Goat Latin are as follows:
	* If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end 
	  of the word. For example, the word 'apple' becomes 'applema'.
	* If a word begins with a consonant (i.e. not a vowel), remove the first 
	  letter and append it to the end, then add "ma". For example, the word 
	  "goat" becomes "oatgma".
	* Add one letter 'a' to the end of each word per its word index in the 
	  sentence, starting with 1. For example, the first word gets "a" added to 
	  the end, the second word gets "aa" added to the end and so on.
	Return the final sentence representing the conversion from S to Goat Latin. 

	Example 1:
	Input: "I speak Goat Latin"
	Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

	Example 2:
	Input: "The quick brown fox jumped over the lazy dog"
	Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

	Notes:
	* S contains only uppercase, lowercase and spaces. Exactly one space between each word.
	* 1 <= S.length <= 150.*/

    string toGoatLatin(string S) {
        string ans, word, vowels = "aeiouAEIOU", suffix; 
        istringstream iss(S); 
        ostringstream oss; 
        
        while (iss >> word) {
            suffix.push_back('a'); 
            if (vowels.find(word[0]) == string::npos) 
                word = word.substr(1) + word[0]; 
            oss << " " << word << "ma" << suffix; 
        }
        return oss.str().substr(1); 
    }


    /*830. Positions of Large Groups (Easy)
	In a string s of lowercase letters, these letters form consecutive groups 
	of the same character. For example, a string like s = "abbxxxxzyy" has the 
	groups "a", "bb", "xxxx", "z", and "yy". A group is identified by an 
	interval [start, end], where start and end denote the start and end indices 
	(inclusive) of the group. In the above example, "xxxx" has the interval 
	[3,6]. A group is considered large if it has 3 or more characters. Return 
	the intervals of every large group sorted in increasing order by start index.

	Example 1:
	Input: s = "abbxxxxzzy"
	Output: [[3,6]]
	Explanation: "xxxx" is the only large group with start index 3 and end index 6.

	Example 2:
	Input: s = "abc"
	Output: []
	Explanation: We have groups "a", "b", and "c", none of which are large groups.

	Example 3:
	Input: s = "abcdddeeeeaabbbcd"
	Output: [[3,5],[6,9],[12,14]]
	Explanation: The large groups are "ddd", "eeee", and "bbb".

	Example 4:
	Input: s = "aba"
	Output: []

	Constraints:
	* 1 <= s.length <= 1000
	* s contains lower-case English letters only.*/

    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans; 
        for (int i = 0, ii = 0; i <= s.size(); ++i) {
            if (i == s.size() || (i > 0 && s[i-1] != s[i])) {
                if (i - ii >= 3) 
                    ans.push_back({ii, i-1}); 
                ii = i; 
            }
        }
        return ans; 
    }


    /*832. Flipping an Image (Easy)
	Given an n x n binary matrix image, flip the image horizontally, then 
	invert it, and return the resulting image. To flip an image horizontally 
	means that each row of the image is reversed. For example, flipping 
	[1,1,0] horizontally results in [0,1,1]. To invert an image means that 
	each 0 is replaced by 1, and each 1 is replaced by 0. For example, 
	inverting [0,1,1] results in [1,0,0].

	Example 1:
	Input: image = [[1,1,0],[1,0,1],[0,0,0]]
	Output: [[1,0,0],[0,1,0],[1,1,1]]
	Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
	Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

	Example 2:
	Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
	Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
	Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
	Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

	Constraints:
	* n == image.length
	* n == image[i].length
	* 1 <= n <= 20
	* images[i][j] is either 0 or 1.*/

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            reverse(row.begin(), row.end()); 
            for (auto& x : row) 
                x ^= 1; 
        }
        return image; 
    }


    /*836. Rectangle Overlap (Easy)
	An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where 
	(x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the 
	coordinate of its top-right corner. Its top and bottom edges are parallel 
	to the X-axis, and its left and right edges are parallel to the Y-axis. 
	Two rectangles overlap if the area of their intersection is positive. To be 
	clear, two rectangles that only touch at the corner or edges do not overlap.
	Given two axis-aligned rectangles rec1 and rec2, return true if they 
	overlap, otherwise return false.

	Example 1:
	Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
	Output: true

	Example 2:
	Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
	Output: false

	Example 3:
	Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
	Output: false

	Constraints:
	* rect1.length == 4
	* rect2.length == 4
	* -10^9 <= rec1[i], rec2[i] <= 10^9
	* rec1[0] <= rec1[2] and rec1[1] <= rec1[3]
	* rec2[0] <= rec2[2] and rec2[1] <= rec2[3]*/

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) && max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }


    /*852. Peak Index in a Mountain Array (Easy)
	Let's call an array arr a mountain if the following properties hold:
	* arr.length >= 3
	* There exists some i with 0 < i < arr.length - 1 such that:
	  + arr[0] < arr[1] < ... arr[i-1] < arr[i]
	  + arr[i] > arr[i+1] > ... > arr[arr.length - 1]
	Given an integer array arr that is guaranteed to be a mountain, return any 
	i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > 
	arr[arr.length - 1].

	Example 1:
	Input: arr = [0,1,0]
	Output: 1

	Example 2:
	Input: arr = [0,2,1,0]
	Output: 1

	Example 3:
	Input: arr = [0,10,5,2]
	Output: 1

	Example 4:
	Input: arr = [3,4,5,1]
	Output: 2

	Example 5:
	Input: arr = [24,69,100,99,79,78,67,36,26,19]
	Output: 2

	Constraints:
	* 3 <= arr.length <= 10^4
	* 0 <= arr[i] <= 10^6
	* arr is guaranteed to be a mountain array.

	Follow up: Finding the O(n) is straightforward, could you find an O(log(n)) 
	           solution?*/

    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0; 
        for (; arr[i] < arr[i+1]; ++i) {}
        return i; 
    }


    /*859. Buddy Strings (Easy)
	Given two strings a and b, return true if you can swap two letters in a so 
	the result is equal to b, otherwise, return false. Swapping letters is 
	defined as taking two indices i and j (0-indexed) such that i != j and 
	swapping the characters at a[i] and a[j]. For example, swapping at indices 
	0 and 2 in "abcd" results in "cbad".

	Example 1:
	Input: a = "ab", b = "ba"
	Output: true
	Explanation: You can swap a[0] = 'a' and a[1] = 'b' to get "ba", which is 
	             equal to b.

	Example 2:
	Input: a = "ab", b = "ab"
	Output: false
	Explanation: The only letters you can swap are a[0] = 'a' and a[1] = 'b', 
	             which results in "ba" != b.

	Example 3:
	Input: a = "aa", b = "aa"
	Output: true
	Explanation: You can swap a[0] = 'a' and a[1] = 'a' to get "aa", which is 
	             equal to b.
	
	Example 4:
	Input: a = "aaaaaaabc", b = "aaaaaaacb"
	Output: true

	Constraints:
	* 1 <= a.length, b.length <= 2 * 104
	* a and b consist of lowercase letters.*/

    bool buddyStrings(string a, string b) {
        if (a.size() != b.size()) return false; 
        
        int most = 0; 
        vector<int> loc; 
        unordered_map<char, int> freq; 
        
        for (int i = 0; i < a.size(); ++i) {
            most = max(most, ++freq[a[i]]); 
            if (a[i] != b[i]) loc.push_back(i); 
        }
        if (loc.size() == 0) return most > 1; 
        if (loc.size() == 2) return a[loc[0]] == b[loc[1]] && a[loc[1]] == b[loc[0]]; 
        return false; 
    }


    /*860. Lemonade Change (Easy)
	At a lemonade stand, each lemonade costs $5. Customers are standing in a 
	queue to buy from you, and order one at a time (in the order specified by 
	bills). Each customer will only buy one lemonade and pay with either a $5, 
	$10, or $20 bill.  You must provide the correct change to each customer, 
	so that the net transaction is that the customer pays $5. Note that you 
	don't have any change in hand at first. Return true if and only if you can 
	provide every customer with correct change.

	Example 1:
	Input: [5,5,5,10,20]
	Output: true
	Explanation: 
	From the first 3 customers, we collect three $5 bills in order.
	From the fourth customer, we collect a $10 bill and give back a $5.
	From the fifth customer, we give a $10 bill and a $5 bill.
	Since all customers got correct change, we output true.

	Example 2:
	Input: [5,5,10]
	Output: true

	Example 3:
	Input: [10,10]
	Output: false

	Example 4:
	Input: [5,5,10,10,20]
	Output: false
	Explanation: 
	From the first two customers in order, we collect two $5 bills.
	For the next two customers in order, we collect a $10 bill and give back a $5 bill.
	For the last customer, we can't give change of $15 back because we only have two $10 bills.
	Since not every customer received correct change, the answer is false.

	Note:
	* 0 <= bills.length <= 10000
	* bills[i] will be either 5, 10, or 20.*/

    bool lemonadeChange(vector<int>& bills) {
        int x05 = 0, x10 = 0; 
        for (auto bill : bills) {
            if (bill == 5) ++x05; 
            else if (bill == 10) --x05, ++x10; 
            else if (x10 > 0) --x05, --x10; 
            else x05 -= 3; 
            if (x05 < 0) return false; 
        }
        return true; 
    }


    /*867. Transpose Matrix (Easy)
	Given a 2D integer array matrix, return the transpose of matrix. The 
	transpose of a matrix is the matrix flipped over its main diagonal, 
	switching the matrix's row and column indices.

	Example 1:
	Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
	Output: [[1,4,7],[2,5,8],[3,6,9]]

	Example 2:
	Input: matrix = [[1,2,3],[4,5,6]]
	Output: [[1,4],[2,5],[3,6]]

	Constraints:
	* m == matrix.length
	* n == matrix[i].length
	* 1 <= m, n <= 1000
	* 1 <= m * n <= 10^5
	* -10^9 <= matrix[i][j] <= 10^9*/

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        vector<vector<int>> ans(n, vector<int>(m, 0)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][i] = matrix[i][j]; 
            }
        }
        return ans; 
    }


    /*868. Binary Gap (Easy)
	Given a positive integer n, find and return the longest distance between 
	any two adjacent 1's in the binary representation of n. If there are no two 
	adjacent 1's, return 0. Two 1's are adjacent if there are only 0's 
	separating them (possibly no 0's). The distance between two 1's is the 
	absolute difference between their bit positions. For example, the two 1's 
	in "1001" have a distance of 3.

	Example 1:
	Input: n = 22
	Output: 2
	Explanation: 22 in binary is "10110".
	             The first adjacent pair of 1's is "10110" with a distance of 2.
	             The second adjacent pair of 1's is "10110" with a distance of 1.
	             The answer is the largest of these two distances, which is 2.
	             Note that "10110" is not a valid pair since there is a 1 
	             separating the two 1's underlined.

	Example 2:
	Input: n = 5
	Output: 2
	Explanation: 5 in binary is "101".

	Example 3:
	Input: n = 6
	Output: 1
	Explanation: 6 in binary is "110".

	Example 4:
	Input: n = 8
	Output: 0
	Explanation: 8 in binary is "1000". There aren't any adjacent pairs of 1's 
	             in the binary representation of 8, so we return 0.

	Example 5:
	Input: n = 1
	Output: 0

	Constraints: 1 <= n <= 10^9*/

    int binaryGap(int n) {
        int ans = 0; 
        for (int cnt = -1; n; n /= 2) {
            int x = n % 2; 
            if (x == 1) {
                ans = max(ans, cnt); 
                cnt = 0; 
            }
            if (cnt >= 0) ++cnt; 
        }
        return ans; 
    }


    /*872. Leaf-Similar Trees (Easy)
	Consider all the leaves of a binary tree, from left to right order, the 
	values of those leaves form a leaf value sequence. For example, in the 
	given tree above, the leaf value sequence is (6, 7, 4, 9, 8). Two binary 
	trees are considered leaf-similar if their leaf value sequence is the same.
	Return true if and only if the two given trees with head nodes root1 and 
	root2 are leaf-similar.

	Example 1:
	Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], 
	       root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
	Output: true
	
	Example 2:
	Input: root1 = [1], root2 = [1]
	Output: true

	Example 3:
	Input: root1 = [1], root2 = [2]
	Output: false

	Example 4:
	Input: root1 = [1,2], root2 = [2,2]
	Output: true

	Example 5:
	Input: root1 = [1,2,3], root2 = [1,3,2]
	Output: false

	Constraints:
	* The number of nodes in each tree will be in the range [1, 200].
	* Both of the given trees will have values in the range [0, 200].*/

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        function<void(TreeNode*, vector<int>&)> dfs = [&dfs](TreeNode* node, vector<int>& vec) {
            if (node->left == NULL && node->right == NULL) vec.push_back(node->val); 
            if (node->left) dfs(node->left, vec); 
            if (node->right) dfs(node->right, vec); 
        };
        
        vector<int> vec1, vec2; 
        dfs(root1, vec1); 
        dfs(root2, vec2); 
        return vec1 == vec2; 
    }


    /*874. Walking Robot Simulation (Easy)
	A robot on an infinite XY-plane starts at point (0, 0) and faces north. The 
	robot can receive one of three possible types of commands:
	* -2: turn left 90 degrees,
	* -1: turn right 90 degrees, or
	* 1 <= k <= 9: move forward k units.
	Some of the grid squares are obstacles. The ith obstacle is at grid point 
	obstacles[i] = (xi, yi). If the robot would try to move onto them, the robot 
	stays on the previous grid square instead (but still continues following the 
	rest of the route.) Return the maximum Euclidean distance that the robot will 
	be from the origin squared (i.e. if the distance is 5, return 25).

	Note:
	North means +Y direction.
	East means +X direction.
	South means -Y direction.
	West means -X direction.

	Example 1:
	Input: commands = [4,-1,3], obstacles = []
	Output: 25
	Explanation: The robot starts at (0, 0):
	1. Move north 4 units to (0, 4).
	2. Turn right.
	3. Move east 3 units to (3, 4).
	The furthest point away from the origin is (3, 4), which is 32 + 42 = 25 units away.

	Example 2:
	Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
	Output: 65
	Explanation: The robot starts at (0, 0):
	1. Move north 4 units to (0, 4).
	2. Turn right.
	3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
	4. Turn left.
	5. Move north 4 units to (1, 8).
	The furthest point away from the origin is (1, 8), which is 12 + 82 = 65 units away.

	Constraints:
	* 1 <= commands.length <= 10^4
	* commands[i] is one of the values in the list [-2,-1,1,2,3,4,5,6,7,8,9].
	* 0 <= obstacles.length <= 10^4
	* -3 * 10^4 <= xi, yi <= 3 * 10^4
	* The answer is guaranteed to be less than 2^31.*/

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        struct myhash {
            size_t operator()(const pair<int, int> &x) const {
                return (97 * x.first + x.second) + (x.first ^ x.second); 
            } 
        };
        
        unordered_set<pair<int, int>, myhash> seen; 
        for (auto obstacle : obstacles) {
            seen.insert(make_pair(obstacle[0], obstacle[1])); 
        }
        
        int ans = 0, x = 0, y = 0, dx = 0, dy = 1; 
        for (auto command : commands) {
            if (command == -2) {
                dy *= -1; 
                swap(dx, dy); 
            } else if (command == -1) {
                dx *= -1; 
                swap(dx, dy); 
            } else {
                for (; command; --command) {
                    if (seen.find(make_pair(x+dx, y+dy)) == seen.end()) {
                        x += dx; 
                        y += dy; 
                    } else break; 
                }
            }
            ans = max(ans, x*x + y*y);
        }
        return ans; 
    }


    /*876. Middle of the Linked List (Easy)
	Given a non-empty, singly linked list with head node head, return a middle 
	node of linked list. If there are two middle nodes, return the second 
	middle node.

	Example 1:
	Input: [1,2,3,4,5]
	Output: Node 3 from this list (Serialization: [3,4,5])
	The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
	Note that we returned a ListNode object ans, such that:
	ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

	Example 2:
	Input: [1,2,3,4,5,6]
	Output: Node 4 from this list (Serialization: [4,5,6])
	Since the list has two middle nodes with values 3 and 4, we return the second one.

	Note: The number of nodes in the given list will be between 1 and 100.*/

    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head; 
        while (fast && fast->next) {
            fast = fast->next->next; 
            slow = slow->next; 
        }
        return slow; 
    }


    /*883. Projection Area of 3D Shapes (Easy)
	You are given an n x n grid where we place some 1 x 1 x 1 cubes that are 
	axis-aligned with the x, y, and z axes. Each value v = grid[i][j] 
	represents a tower of v cubes placed on top of the cell (i, j). We view the 
	projection of these cubes onto the xy, yz, and zx planes. A projection is 
	like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. 
	We are viewing the "shadow" when looking at the cubes from the top, the 
	front, and the side. Return the total area of all three projections.

	Example 1:
	Input: grid = [[1,2],[3,4]]
	Output: 17
	Explanation: Here are the three projections ("shadows") of the shape made 
	             with each axis-aligned plane.

	Example 2:
	Input: grid = [[2]]
	Output: 5
	
	Example 3:
	Input: grid = [[1,0],[0,2]]
	Output: 8

	Example 4:
	Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
	Output: 14

	Example 5:
	Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
	Output: 21

	Constraints:
	* n == grid.length
	* n == grid[i].length
	* 1 <= n <= 50
	* 0 <= grid[i][j] <= 50*/

    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0; 
        for (int i = 0; i < n; ++i) {
            int cmx = 0, rmx = 0; 
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) ++ans; 
                cmx = max(cmx, grid[j][i]); 
                rmx = max(rmx, grid[i][j]); 
            }
            ans += cmx + rmx; 
        }
        return ans; 
    }


    /*884. Uncommon Words from Two Sentences (Easy)
	We are given two sentences A and B.  (A sentence is a string of space 
	separated words.  Each word consists only of lowercase letters.) A word is 
	uncommon if it appears exactly once in one of the sentences, and does not 
	appear in the other sentence. Return a list of all uncommon words. You may 
	return the list in any order.

	Example 1:
	Input: A = "this apple is sweet", B = "this apple is sour"
	Output: ["sweet","sour"]

	Example 2:
	Input: A = "apple apple", B = "banana"
	Output: ["banana"]

	Note:
	* 0 <= A.length <= 200
	* 0 <= B.length <= 200
	* A and B both contain only spaces and lowercase letters.*/

    vector<string> uncommonFromSentences(string A, string B) {
        istringstream iss(A + " " + B); 
        unordered_map<string, int> freq; 
        string word; 
        while (iss >> word) ++freq[word]; 
        
        vector<string> ans; 
        for (auto x : freq) {
            if (x.second == 1) ans.push_back(x.first); 
        }
        return ans; 
    }


    /*888. Fair Candy Swap (Easy)
	Alice and Bob have candy bars of different sizes: A[i] is the size of the 
	i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of 
	candy that Bob has. Since they are friends, they would like to exchange one 
	candy bar each so that after the exchange, they both have the same total 
	amount of candy.  (The total amount of candy a person has is the sum of the 
	sizes of candy bars they have.) Return an integer array ans where ans[0] is 
	the size of the candy bar that Alice must exchange, and ans[1] is the size 
	of the candy bar that Bob must exchange. If there are multiple answers, you 
	may return any one of them.  It is guaranteed an answer exists.

	Example 1:
	Input: A = [1,1], B = [2,2]
	Output: [1,2]

	Example 2:
	Input: A = [1,2], B = [2,3]
	Output: [1,2]
	
	Example 3:
	Input: A = [2], B = [1,3]
	Output: [2,3]

	Example 4:
	Input: A = [1,2,5], B = [2,4]
	Output: [5,4]

	Note:
	* 1 <= A.length <= 10000
	* 1 <= B.length <= 10000
	* 1 <= A[i] <= 100000
	* 1 <= B[i] <= 100000
	* It is guaranteed that Alice and Bob have different total amounts of candy.
	* It is guaranteed there exists an answer.*/

    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0); 
        unordered_set<int> seen(A.begin(), A.end()); 
        for (auto x : B) {
            if (seen.find(x + diff/2) != seen.end()) {
                return {x + diff/2, x}; 
            }
        }
        return {}; 
    }


    /*892. Surface Area of 3D Shapes (Easy)
	You are given an n x n grid where you have placed some 1 x 1 x 1 cubes. 
	Each value v = grid[i][j] represents a tower of v cubes placed on top of 
	cell (i, j). After placing these cubes, you have decided to glue any 
	directly adjacent cubes to each other, forming several irregular 3D shapes.
	Return the total surface area of the resulting shapes. Note: The bottom 
	face of each shape counts toward its surface area.

	Example 1:
	Input: grid = [[2]]
	Output: 10

	Example 2:
	Input: grid = [[1,2],[3,4]]
	Output: 34

	Example 3:
	Input: grid = [[1,0],[0,2]]
	Output: 16

	Example 4:
	Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
	Output: 32

	Example 5:
	Input: grid = [[2,2,2],[2,1,2],[2,2,2]]
	Output: 46

	Constraints:
	* n == grid.length
	* n == grid[i].length
	* 1 <= n <= 50
	* 0 <= grid[i][j] <= 50*/

    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ans += 4*grid[i][j] + 2; 
                    if (i) ans -= 2*min(grid[i][j], grid[i-1][j]); 
                    if (j) ans -= 2*min(grid[i][j], grid[i][j-1]); 
                }
            }
        }
        return ans; 
    }


    /*893. Groups of Special-Equivalent Strings (Easy)
	You are given an array A of strings. A move onto S consists of swapping any 
	two even indexed characters of S, or any two odd indexed characters of S. 
	Two strings S and T are special-equivalent if after any number of moves 
	onto S, S == T. For example, S = "zzxy" and T = "xyzz" are special-
	equivalent because we may make the moves "zzxy" -> "xzzy" -> "xyzz" that 
	swap S[0] and S[2], then S[1] and S[3]. Now, a group of special-equivalent 
	strings from A is a non-empty subset of A such that:
	1) Every pair of strings in the group are special equivalent, and;
	2) The group is the largest size possible (ie., there isn't a string S not 
	   in the group such that S is special equivalent to every string in the 
	   group)
	Return the number of groups of special-equivalent strings from A.
	 
	Example 1:
	Input: ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
	Output: 3
	Explanation: One group is ["abcd", "cdab", "cbad"], since they are all 
	             pairwise special equivalent, and none of the other strings are 
	             all pairwise special equivalent to these. The other two groups 
	             are ["xyzz", "zzxy"] and ["zzyx"].  Note that in particular, 
	             "zzxy" is not special equivalent to "zzyx".
	
	Example 2:
	Input: ["abc","acb","bac","bca","cab","cba"]
	Output: 3

	Note:
	* 1 <= A.length <= 1000
	* 1 <= A[i].length <= 20
	* All A[i] have the same length.
	* All A[i] consist of only lowercase letters.*/

    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> seen; 
        for (auto word : A) {
            string even, odd; 
            for (int i = 0; i < word.size(); ++i) {
                if (i&1) odd.push_back(word[i]); 
                else even.push_back(word[i]); 
            }
            sort(even.begin(), even.end()); 
            sort(odd.begin(), odd.end()); 
            seen.insert(even+odd); 
        }
        return seen.size(); 
    }


    /*953. Verifying an Alien Dictionary (Easy)
	In an alien language, surprisingly they also use english lowercase letters, 
	but possibly in a different order. The order of the alphabet is some 
	permutation of lowercase letters. Given a sequence of words written in the 
	alien language, and the order of the alphabet, return true if and only if 
	the given words are sorted lexicographicaly in this alien language.

	Example 1:
	Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
	Output: true
	Explanation: As 'h' comes before 'l' in this language, then the sequence is 
	             sorted.

	Example 2:
	Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
	Output: false
	Explanation: As 'd' comes after 'l' in this language, then 
	             words[0] > words[1], hence the sequence is unsorted.

	Example 3:
	Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
	Output: false
	Explanation: The first three characters "app" match, and the second string 
	             is shorter (in size.) According to lexicographical rules 
	             "apple" > "app", because 'l' > '∅', where '∅' is defined as 
	             the blank character which is less than any other character 
	             (More info).

	Constraints:
	* 1 <= words.length <= 100
	* 1 <= words[i].length <= 20
	* order.length == 26
	* All characters in words[i] and order are English lowercase letters.*/

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp; 
        for (int i = 0; i < order.size(); ++i)
            mp[order[i]] = i; 
        
        for (int i = 1; i < words.size(); ++i) {
            for (int k; k < words[i-1].size(); ++k) {
                if (k == words[i].size()) return false; 
                if (mp[words[i-1][k]] < mp[words[i][k]]) break; 
                if (mp[words[i-1][k]] > mp[words[i][k]]) return false; 
            }
        }
        return true; 
    }


    /*1074. Number of Submatrices That Sum to Target (Hard)
	Given a matrix and a target, return the number of non-empty submatrices 
	that sum to target. A submatrix x1, y1, x2, y2 is the set of all cells 
	matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2. Two submatrices 
	(x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some 
	coordinate that is different: for example, if x1 != x1'.

	Example 1:
	Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
	Output: 4
	Explanation: The four 1x1 submatrices that only contain 0.

	Example 2:
	Input: matrix = [[1,-1],[-1,1]], target = 0
	Output: 5
	Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

	Example 3:
	Input: matrix = [[904]], target = 0
	Output: 0

	Constraints:
	* 1 <= matrix.length <= 100
	* 1 <= matrix[0].length <= 100
	* -1000 <= matrix[i] <= 1000
	* -10^8 <= target <= 10^8*/

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, m = matrix.size(), n = matrix[0].size(); // dimensions 
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0)); 
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) 
                prefix[i+1][j+1] = matrix[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j]; 
            
            for (int ii = 0; ii <= i; ++ii) {
                unordered_map<int, int> freq; 
                freq[0] = 1; 
                for (int j = 0; j < n; ++j) {
                    int diff = prefix[i+1][j+1] - prefix[ii][j+1]; 
                    ans += freq[diff - target]; 
                    ++freq[diff]; 
                }
            }
        }
        return ans;         
    }


    /*1209. Remove All Adjacent Duplicates in String II (Medium)
	Given a string s, a k duplicate removal consists of choosing k adjacent and 
	equal letters from s and removing them causing the left and the right side 
	of the deleted substring to concatenate together. We repeatedly make k 
	duplicate removals on s until we no longer can. Return the final string 
	after all such duplicate removals have been made. It is guaranteed that the 
	answer is unique.

	Example 1:
	Input: s = "abcd", k = 2
	Output: "abcd"
	Explanation: There's nothing to delete.

	Example 2:
	Input: s = "deeedbbcccbdaa", k = 3
	Output: "aa"
	Explanation: 
	First delete "eee" and "ccc", get "ddbbbdaa"
	Then delete "bbb", get "dddaa"
	Finally delete "ddd", get "aa"

	Example 3:
	Input: s = "pbbcggttciiippooaais", k = 2
	Output: "ps"

	Constraints:
	* 1 <= s.length <= 10^5
	* 2 <= k <= 10^4
	* s only contains lower case English letters.*/

    string removeDuplicates(string s, int k) {
        vector<vector<int>> vec; 
        for (auto c : s) {
            if (vec.size() && vec.back()[1] == c) {
                ++vec.back()[0]; 
            } else {
                vec.push_back({1, c}); 
            }
            if (vec.back()[0] == k) vec.pop_back();
        }
        
        string ans; 
        for (auto x : vec) {
            ans += string(x[0], x[1]); 
        }
        return ans; 
    }


    /*1816. Truncate Sentence (Easy)
	A sentence is a list of words that are separated by a single space with no 
	leading or trailing spaces. Each of the words consists of only uppercase 
	and lowercase English letters (no punctuation). For example, "Hello World", 
	"HELLO", and "hello world hello world" are all sentences. You are given a 
	sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains 
	only the first k​​​​​​ words. Return s​​​​​​ after truncating it.

	Example 1:
	Input: s = "Hello how are you Contestant", k = 4
	Output: "Hello how are you"
	Explanation:
	The words in s are ["Hello", "how" "are", "you", "Contestant"].
	The first 4 words are ["Hello", "how", "are", "you"].
	Hence, you should return "Hello how are you".

	Example 2:
	Input: s = "What is the solution to this problem", k = 4
	Output: "What is the solution"
	Explanation:
	The words in s are ["What", "is" "the", "solution", "to", "this", "problem"].
	The first 4 words are ["What", "is", "the", "solution"].
	Hence, you should return "What is the solution".

	Example 3:
	Input: s = "chopper is not a tanuki", k = 5
	Output: "chopper is not a tanuki"

	Constraints:
	* 1 <= s.length <= 500
	* k is in the range [1, the number of words in s].
	* s consist of only lowercase and uppercase English letters and spaces.
	* The words in s are separated by a single space.
	* There are no leading or trailing spaces.*/

    string truncateSentence(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (--k == 0) return s.substr(0, i); 
            }
        }
        return s; 
    }


    /*1817. Finding the Users Active Minutes (Medium)
	You are given the logs for users' actions on LeetCode, and an integer k. 
	The logs are represented by a 2D integer array logs where each 
	logs[i] = [IDi, timei] indicates that the user with IDi performed an action
	at the minute timei. Multiple users can perform actions simultaneously, 
	and a single user can perform multiple actions in the same minute. The 
	user active minutes (UAM) for a given user is defined as the number of 
	unique minutes in which the user performed an action on LeetCode. A minute 
	can only be counted once, even if multiple actions occur during it. You 
	are to calculate a 1-indexed array answer of size k such that, for each j 
	(1 <= j <= k), answer[j] is the number of users whose UAM equals j. Return 
	the array answer as described above.

	Example 1:
	Input: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
	Output: [0,2,0,0,0]
	Explanation:
	The user with ID=0 performed actions at minutes 5, 2, and 5 again. Hence, they have a UAM of 2 (minute 5 is only counted once).
	The user with ID=1 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
	Since both users have a UAM of 2, answer[2] is 2, and the remaining answer[j] values are 0.

	Example 2:
	Input: logs = [[1,1],[2,2],[2,3]], k = 4
	Output: [1,1,0,0]
	Explanation:
	The user with ID=1 performed a single action at minute 1. Hence, they have a UAM of 1.
	The user with ID=2 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
	There is one user with a UAM of 1 and one with a UAM of 2.
	Hence, answer[1] = 1, answer[2] = 1, and the remaining values are 0.

	Constraints:
	* 1 <= logs.length <= 10^4
	* 0 <= IDi <= 10^9
	* 1 <= timei <= 10^5
	* k is in the range [The maximum UAM for a user, 10^5].*/

    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp; 
        for (auto &log : logs) {
            mp[log[0]].insert(log[1]); 
        }
        
        vector<int> ans(k, 0); 
        for (auto &x : mp) {
            if (x.second.size() <= k) 
                ++ans[x.second.size() - 1]; 
        }
        return ans; 
    }


    /*1818. Minimum Absolute Sum Difference (Medium)
	You are given two positive integer arrays nums1 and nums2, both of length n. 
	The absolute sum difference of arrays nums1 and nums2 is defined as the sum 
	of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed). You can replace 
	at most one element of nums1 with any other element in nums1 to minimize 
	the absolute sum difference. Return the minimum absolute sum difference 
	after replacing at most one element in the array nums1. Since the answer 
	may be large, return it modulo 10^9 + 7. |x| is defined as:
	* x if x >= 0, or
	* -x if x < 0.

	Example 1:
	Input: nums1 = [1,7,5], nums2 = [2,3,5]
	Output: 3
	Explanation: There are two possible optimal solutions:
	- Replace the second element with the first: [1,7,5] => [1,1,5], or
	- Replace the second element with the third: [1,7,5] => [1,5,5].
	Both will yield an absolute sum difference of |1-2| + (|1-3| or |5-3|) + |5-5| = 3.

	Example 2:
	Input: nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
	Output: 0
	Explanation: nums1 is equal to nums2 so no replacement is needed. This will result in an 
	absolute sum difference of 0.

	Example 3:
	Input: nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
	Output: 20
	Explanation: Replace the first element with the second: [1,10,4,4,2,7] => [10,10,4,4,2,7].
	This yields an absolute sum difference of |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20

	Constraints:
	* n == nums1.length
	* n == nums2.length
	* 1 <= n <= 10^5
	* 1 <= nums1[i], nums2[i] <= 10^5*/

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s1 = nums1; 
        sort(s1.begin(), s1.end()); 
        
        long ans = 0, bnft = 0; 
        for (int i = 0; i < nums1.size(); ++i) {
            long term = abs(nums1[i] - nums2[i]); 
            ans += term; 
            auto it = lower_bound(s1.begin(), s1.end(), nums2[i]); 
            if (it < s1.end())
                bnft = max(bnft, term - (*it - nums2[i]));
            if (s1.begin() < it) 
                bnft = max(bnft, term - (nums2[i] - *prev(it)));
        }
        return (ans - bnft) % 1'000'000'007; 
    }


    /*1819. Number of Different Subsequences GCDs (Hard)
	You are given an array nums that consists of positive integers. The GCD of 
	a sequence of numbers is defined as the greatest integer that divides all 
	the numbers in the sequence evenly. For example, the GCD of the sequence 
	[4,6,16] is 2. A subsequence of an array is a sequence that can be formed 
	by removing some elements (possibly none) of the array. For example, 
	[2,5,10] is a subsequence of [1,2,1,2,4,1,5,10]. Return the number of 
	different GCDs among all non-empty subsequences of nums.

	Example 1:
	Input: nums = [6,10,3]
	Output: 5
	Explanation: The figure shows all the non-empty subsequences and their GCDs.
	The different GCDs are 6, 10, 3, 2, and 1.

	Example 2:
	Input: nums = [5,15,40,5,6]
	Output: 7

	Constraints:
	* 1 <= nums.length <= 10^5
	* 1 <= nums[i] <= 2 * 10^5*/

    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        auto mx = *max_element(nums.begin(), nums.end()); 
        vector<bool> seen (mx+1, false); 
        for (auto& x : nums) 
            seen[x] = true; 
        
        int ans = 0; 
        for (int x = 1; x <= mx; ++x) {
            int g = 0; 
            for (int xx = x; xx <= mx; xx += x) {
                if (seen[xx]) g = __gcd(g, xx);
            }
            if (g == x) ++ans; 
        }
        return ans; 
    }


    /*1832. Check if the Sentence Is Pangram (Easy)
	A pangram is a sentence where every letter of the English alphabet appears 
	at least once. Given a string sentence containing only lowercase English 
	letters, return true if sentence is a pangram, or false otherwise.

	Example 1:
	Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
	Output: true
	Explanation: sentence contains at least one of every letter of the English alphabet.

	Example 2:
	Input: sentence = "leetcode"
	Output: false

	Constraints:
	* 1 <= sentence.length <= 1000
	* sentence consists of lowercase English letters.*/

    bool checkIfPangram(string sentence) {
        unordered_set<char> seen; 
        for (auto x : sentence) {
            seen.insert(x); 
        }
        return seen.size() == 26; 
    }


    /*1833. Maximum Ice Cream Bars (Medium)
	It is a sweltering summer day, and a boy wants to buy some ice cream bars. 
	At the store, there are n ice cream bars. You are given an array costs of 
	length n, where costs[i] is the price of the ith ice cream bar in coins. 
	The boy initially has coins coins to spend, and he wants to buy as many ice 
	cream bars as possible. Return the maximum number of ice cream bars the boy 
	can buy with coins coins. Note: The boy can buy the ice cream bars in any 
	order.

	Example 1:
	Input: costs = [1,3,2,4,1], coins = 7
	Output: 4
	Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total 
	             price of 1 + 3 + 2 + 1 = 7.

	Example 2:
	Input: costs = [10,6,8,7,7,8], coins = 5
	Output: 0
	Explanation: The boy cannot afford any of the ice cream bars.

	Example 3:
	Input: costs = [1,6,3,1,2,5], coins = 20
	Output: 6
	Explanation: The boy can buy all the ice cream bars for a total price of 
	             1 + 6 + 3 + 1 + 2 + 5 = 18.

	Constraints:
	* costs.length == n
	* 1 <= n <= 10^5
	* 1 <= costs[i] <= 10^5
	* 1 <= coins <= 10^8*/

    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0; 
        sort(costs.begin(), costs.end()); 
        for (int i = 0; i < costs.size(); ++i) {
            if (costs[i] <= coins) {
                ++ans; 
                coins -= costs[i]; 
            } else break; 
        }
        return ans; 
    }


    /*1834. Single-Threaded CPU (Medium)
	You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D 
	integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] 
	means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei 
	and will take processingTimei to finish processing. You have a single-
	threaded CPU that can process at most one task at a time and will act in 
	the following way:
	* If the CPU is idle and there are no available tasks to process, the CPU 
	  remains idle.
	* If the CPU is idle and there are available tasks, the CPU will choose the 
	  one with the shortest processing time. If multiple tasks have the same 
	  shortest processing time, it will choose the task with the smallest index.
	* Once a task is started, the CPU will process the entire task without stopping.
	* The CPU can finish a task then start a new one instantly.
	Return the order in which the CPU will process the tasks.

	Example 1:
	Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
	Output: [0,2,3,1]
	Explanation: The events go as follows: 
	- At time = 1, task 0 is available to process. Available tasks = {0}.
	- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
	- At time = 2, task 1 is available to process. Available tasks = {1}.
	- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
	- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
	- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
	- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
	- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
	- At time = 10, the CPU finishes task 1 and becomes idle.
	
	Example 2:
	Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
	Output: [4,3,2,0,1]
	Explanation: The events go as follows:
	- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
	- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
	- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
	- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
	- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
	- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
	- At time = 40, the CPU finishes task 1 and becomes idle.

	Constraints:
	* tasks.length == n
	* 1 <= n <= 10^5
	* 1 <= enqueueTimei, processingTimei <= 10^9*/

    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) tasks[i].push_back(i); 
        sort(tasks.begin(), tasks.end()); // ascending order 
        
        vector<int> ans; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // min-heap 
        
        for (long i = 0, time = 0; pq.size() || i < tasks.size(); ) {
            for ( ; i < tasks.size() && tasks[i][0] <= time; ++i) {
                pq.emplace(tasks[i][1], tasks[i][2]); 
            }
            
            if (pq.size()) {
                auto [prc, index] = pq.top(); 
                pq.pop(); 
                ans.push_back(index); 
                time += prc; 
            } else {
                time = tasks[i][0]; 
            }
        }
        return ans; 
    }


    /*1835. Find XOR Sum of All Pairs Bitwise AND (Hard)
	The XOR sum of a list is the bitwise XOR of all its elements. If the list 
	only contains one element, then its XOR sum will be equal to this element.
	For example, the XOR sum of [1,2,3,4] is equal to 1 XOR 2 XOR 3 XOR 4 = 4, 
	and the XOR sum of [3] is equal to 3. You are given two 0-indexed arrays 
	arr1 and arr2 that consist only of non-negative integers. Consider the list 
	containing the result of arr1[i] AND arr2[j] (bitwise AND) for every (i, j) 
	pair where 0 <= i < arr1.length and 0 <= j < arr2.length. Return the XOR 
	sum of the aforementioned list.

	Example 1:
	Input: arr1 = [1,2,3], arr2 = [6,5]
	Output: 0
	Explanation: The list = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1].
	The XOR sum = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0.

	Example 2:
	Input: arr1 = [12], arr2 = [4]
	Output: 4
	Explanation: The list = [12 AND 4] = [4]. The XOR sum = 4.

	Constraints:
	* 1 <= arr1.length, arr2.length <= 10^5
	* 0 <= arr1[i], arr2[j] <= 10^9*/

    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        return accumulate(arr1.begin(), arr1.end(), 0, bit_xor()) & accumulate(arr2.begin(), arr2.end(), 0, bit_xor());
    }
};


/*703. Kth Largest Element in a Stream (Easy)
Design a class to find the kth largest element in a stream. Note that it is the 
kth largest element in the sorted order, not the kth distinct element. 
Implement KthLargest class:
* KthLargest(int k, int[] nums) Initializes the object with the integer k and 
  the stream of integers nums.
* int add(int val) Returns the element representing the kth largest element in 
  the stream.

Example 1:
Input: ["KthLargest", "add", "add", "add", "add", "add"]
       [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output: [null, 4, 5, 5, 8, 8]
Explanation: 
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

Constraints:
* 1 <= k <= 10^4
* 0 <= nums.length <= 10^4
* -104 <= nums[i] <= 10^4
* -104 <= val <= 10^4
* At most 10^4 calls will be made to add.
* It is guaranteed that there will be at least k elements in the array when you 
  search for the kth element.*/

class KthLargest {
private: 
    int k = 0; 
    priority_queue<int, vector<int>, greater<int>> pq; // min heap 
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
        for (auto& x : nums) {
            pq.push(x); 
            if (pq.size() > k) 
                pq.pop(); 
        }
    }
    
    int add(int val) {
        pq.push(val); 
        if (pq.size() > k) 
            pq.pop();
        return pq.top(); 
    }
};