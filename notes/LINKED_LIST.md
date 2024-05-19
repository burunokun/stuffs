### Definition
```c
typedef struct Node Node;
struct Node {
    int val;
    Node *next;
};
```

---
### Insert Node
```c
Node *insert_node(Node *head, int val) {
	Node *temp = malloc(sizeof(*temp));
	temp->val = val;
	temp->next = NULL;
	if (!head) {
		head = temp;
	} else {
		Node *p = head;
		while (p->next) {
			p = p->next;
		}
		 p->next = temp;
	}
	return head;
}
```

---
### Remove Node
```c
void removeNode(Node *node) {
    Node *temp = node->next;
    *node = *node->next;
    free(temp);
}
```
The above is just the same as
```c
void removeNode(Node *node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
```

---
### Reorder list
Group and reorder linked list by odd and even indices. 
```c
/*
 * head = [1, 2, 3, 4, 5]
 * return [1, 3, 5, 2, 4]
*/
Node *oddEvenList(Node *head) {
    // if head is null or single element
    // there's nothing to reorder
	if (!head || !head->next) return head;
    
    // create two pointers for:
    // odd indices
	Node *odd = head;
    // even inidices, starting one element ahead of odd index pointer
	Node *even = head->next;
    // and a pointer to the beginning of the even list
	Node *res = even;

	while (even && even->next) {
        // odd->next will be whatever even->next points to
		odd->next = even->next;
        // advance odd
		odd = odd->next;
        // even->next will be whatever odd->next points to
		even->next = odd->next;
        // advance even
		even = even->next;
	}

    // odd  = [1, 3, 5]
    //               ^  (odd pointer)
    // even = [2, 4]
    //            ^     (even pointer)
    // res  = [2, 4]
    //         ^        (res pointer)
	odd->next = res;
    // odd->next now pointing to the beginning of even

    // head = [1, 3, 5, 2, 4]
	return head;
}
```

---
### Find and remove middle element
- Keep two pointers: `slow` and `fast` pointer;
- `slow` pointer moves 1 element at a time;
- `fast` pointer moves 2 elements at a time;
- When the `fast` pointer reaches the end `slow` will be at the middle;
```c
Node *deleteMiddle(Node *head) {
    // list to return 
    Node *res = malloc(sizeof(*res));
    res->val = -1;
    res->next = head;
    
    // slow pointer that moves one element at a time
    Node *slow = res;
    // fast pointer that moves two elements at a time
    Node *fast = head;
    
    // while fast is not null, update both pointers
    while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
    }

    // by the end of fast, slow should be pointing one element before middle
    // update slow->next with slow->next->next to skip and remove middle
    slow->next = slow->next->next;
    return res->next;
}
```

---
### Remove Nth Node from the end
Given the `head` of a linked list, remove `nth` node from the end of the list and return its head.

- Keep two pointers and update one with the delay of `n` steps;
```c
/*
 * head = [1, 2, 3, 4, 5], n = 2
 * return [1, 2, 3, 5]
 * 4 is the 2nd from number counting from the end of the list
*/
Node *removeNthFromEnd(Node *head, int n) {
    // list to return
	Node *res = malloc(sizeof(*res));
	res->val = 0; 
	res->next = head;
	
    // advance head 'n' count of steps
	int count = 0;
	while (count != n) {
	    head = head->next;
	    count++;
	}

    // while head is not null, update dummy list
	while (head) {
	    head = head->next;
	    dummy = dummy->next;
	}
    // as head reached the end, dummy next node is the node to remove
    // udpate dummy->next pointing to dummy->next->next 
	dummy->next = dummy->next->next;
	
    // res->next == head first node
	return res->next;
}
```