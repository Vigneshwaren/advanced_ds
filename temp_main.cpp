#include "node.hpp"
#include <cstdio>


int main () { 
	struct tree_node *t = get_tree_node();
	if (if_empty_tree(t)) {
		printf ("Empty..\n");
	}
	right_rotate(t);
	if (if_empty_tree(t)) {
		printf ("Empty..\n");
	}
	left_rotate(t);
	if (if_empty_tree(t)) {
		printf ("Empty..\n");
	}
	return 0;
}