### Definition
```c
typedef TreeNode Tree;
struct Tree {
	int val;
	Tree *left;
	Tree *right;
};
```

---

### Find Subtree
Given two binary trees `S` & `T`, check whether one tree is a subtree of the other.

Steps to solve this problem:
- Traverse the tree `T` in preorder fashion;
- For every visited node in the traversal, see if the subtree rooted with this node is identical to `S`;
- To check the subtree is identical or not traverse on the tree `S` and `T` simultaneously;
- If a visited node is not equal then return false else continue traversing the whole tree `S` is traversed.

```c
/* 
 * Time Complexity: O(m*n)
 *                  Traversing subtree S of size 'm', every 'n' node of root T.
 * Space Complexity: O(n)
*/
bool areIdentical(Tree *T, Tree* S) {
	if (T == NULL && S == NULL) return true;
	if (T == NULL || S == NULL) return false;

    /* Traverse and check if node->vals are the same */
	return (T->val == S->val
	        && areIdentical(T->left,  S->left)
	        && areIdentical(T->right, S->right));
}

bool isSubtree(Tree *root, Tree *subtree) {
    if (root == NULL) return false;
    if (subtree == NULL) return true;
    if (areIdentical(root, subtree)) return true;

    /* Traverse root and compare for equality against subtree */
    return isSubtree(root->left, subtree) || isSubtree(root->right, subtree);
}
```

