`Linked List`
```c
typedef struct Node Node;
struct Node {
	int val;
	Node *next;
};
```

`insert_node`
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

`remove_node`
```c
Node *remove_node(Node *head, int val) {
	Node *curr = malloc(sizeof(*curr));
	curr->val = -1;
	curr->next = head;
	
	Node *p = curr;
	while(p->next) {
		if (p->next->val == val) {
			p->next = p->next->next;
		} else {
			p = p->next;
		}
	}
	
	return curr->next;
}
```

`print_nodes`
```c
void print_nodes(Node *head) {
	while (head->next) {
		printf("%d", head->val);
		head = head->next;
		if (head->next) printf("->");
	}
}
```