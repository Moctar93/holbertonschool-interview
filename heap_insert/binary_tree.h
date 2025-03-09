#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

void binary_tree_print(const binary_tree_t *tree);
int binary_tree_height(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */

