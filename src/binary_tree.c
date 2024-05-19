#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;
struct Tree {
    int val;
    Tree *left;
    Tree *right;
};

Tree *create_node(int val) {
    Tree *new_node = malloc(sizeof(*new_node));
    assert(new_node != NULL);

    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Tree *generate_tree(size_t level, int *counter) {
    if (level == 0) {
        return NULL;
    } else {
        Tree *node = create_node(*counter);
        *counter += 1;
        node->left  = generate_tree(level-1, counter);
        node->right = generate_tree(level-1, counter);
        return node;
    }
}

Tree *invert_tree(Tree *root) {
    if (!root) {
        return NULL;
    } else {
        Tree *node = create_node(root->val);
        node->left  = invert_tree(root->right);
        node->right = invert_tree(root->left);
        return node;
    }
}

void preorder(Tree *root) {
    if (root) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Tree *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

void print_tree(Tree *root, size_t level) {
    if (root) {
        print_tree(root->left, level+1);
        for (size_t i = 0; i < level; ++i) {
            printf("  ");
        }
        printf("%d\n", root->val);
        print_tree(root->right, level+1);
    }
}

void free_tree(Tree *root) {
    if (root) {
        free_tree(root->right);
        free_tree(root->left);
        free(root);
    }
}

int main(void) {
    int counter = 1;

    Tree *root = generate_tree(3, &counter);
    print_tree(root, 0);

    printf("----------------------------\n");

    Tree *inv_root = invert_tree(root);
    print_tree(inv_root, 0);


    free_tree(root);
    free_tree(inv_root);
    return 0;
}
