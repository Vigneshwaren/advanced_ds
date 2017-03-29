#ifndef __NODE_H
#define __NODE_H

#include <cstdlib>

#define if_leaf_node(n) (n->right == NULL)
#define if_empty_tree(n) (n->left == NULL && n->right == NULL)

typedef int key_t;
typedef int object_t;


struct tree_node {
	key_t key;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node *get_tree_node (void) {
	struct tree_node *tmp;
	tmp = (struct tree_node *) malloc (sizeof(struct tree_node));
	tmp -> left = tmp -> right = NULL; 
	if (tmp) return tmp;
	return NULL;
}

void left_rotate (struct tree_node *t) {
	if (if_leaf_node(t) || if_empty_tree(t)) return;
	struct tree_node *tmp = t->left;
	t->left = t->right;
	t->right = t->left->right;
	t->left->right = t->left->left;
	t->left->left = tmp;
	key_t k = t->key;
	t->key = t->left->key;
	t->left->key = k;
}

void right_rotate (struct tree_node *t) {
	if (if_leaf_node(t) || if_empty_tree(t)) return;
	struct tree_node *tmp = t->right;
	t->right = t->left;
	t->left = t->right->left;
	t->right -> left = t->right->right;
	t->right->right = tmp;
	key_t k = t->key;
	t->key = t->right->key;
	t->right->key = k;
}

object_t *find (struct tree_node *t, key_t k) {
	if (if_empty_tree(t)) return NULL;
	struct tree_node *tmp = t;
	while (!if_leaf_node(tmp)) {
		if (t->key> k) {
			tmp = tmp->left;
		}
		else tmp = tmp->right;
	}
	if (tmp->key == k) return (object_t *) tmp->left;
	else return NULL;
}

int insert (struct tree_node *t, key_t k, object_t *o) {
	
}

#endif
















