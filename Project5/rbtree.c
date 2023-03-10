/*
 * Copyright (c) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/* Our SDK/toolchains integration seems to be inconsistent about
 * whether they expose alloca.h or not.  On gcc it's a moot point as
 * it's always builtin.
 */
#ifdef __GNUC__
#ifndef alloca
#define alloca __builtin_alloca
#endif
#else
#include <alloca.h>
#endif
 
#ifndef ZEPHYR_INCLUDE_SYS_RB_H_
#define ZEPHYR_INCLUDE_SYS_RB_H_
 
#include <stdbool.h>
#include <stdint.h>
 
struct rbnode {
        struct rbnode *children[2];
};
 
/* Theoretical maximum depth of tree based on pointer size. If memory
 * is filled with 2-pointer nodes, and the tree can be twice as a
 * packed binary tree, plus root...  Works out to 59 entries for 32
 * bit pointers and 121 at 64 bits.
 */
#define Z_TBITS(t) ((sizeof(t)) < 8 ? 2 : 3)
#define Z_PBITS(t) (8 * sizeof(t))
#define Z_MAX_RBTREE_DEPTH (2 * (Z_PBITS(int *) - Z_TBITS(int *) - 1) + 1)
 
 
typedef bool (*rb_lessthan_t)(struct rbnode *a, struct rbnode *b);
 
struct rbtree {
        struct rbnode *root;
        rb_lessthan_t lessthan_fn;
        int max_depth;
#ifdef CONFIG_MISRA_SANE
        struct rbnode *iter_stack[Z_MAX_RBTREE_DEPTH];
        unsigned char iter_left[Z_MAX_RBTREE_DEPTH];
#endif
};
 
typedef void (*rb_visit_t)(struct rbnode *node, void *cookie);
 
struct rbnode *z_rb_child(struct rbnode *node, uint8_t side);
int z_rb_is_black(struct rbnode *node);
#ifndef CONFIG_MISRA_SANE
void z_rb_walk(struct rbnode *node, rb_visit_t visit_fn, void *cookie);
#endif
struct rbnode *z_rb_get_minmax(struct rbtree *tree, uint8_t side);
 
void rb_insert(struct rbtree *tree, struct rbnode *node);
 
void rb_remove(struct rbtree *tree, struct rbnode *node);
 
static inline struct rbnode *rb_get_min(struct rbtree *tree)
{
        return z_rb_get_minmax(tree, 0U);
}
 
static inline struct rbnode *rb_get_max(struct rbtree *tree)
{
        return z_rb_get_minmax(tree, 1U);
}
 
bool rb_contains(struct rbtree *tree, struct rbnode *node);
 
#ifndef CONFIG_MISRA_SANE
static inline void rb_walk(struct rbtree *tree, rb_visit_t visit_fn,
                           void *cookie)
{
        z_rb_walk(tree->root, visit_fn, cookie);
}
#endif
 
struct _rb_foreach {
        struct rbnode **stack;
        uint8_t *is_left;
        int32_t top;
};
 
#ifdef CONFIG_MISRA_SANE
#define _RB_FOREACH_INIT(tree, node) {                                  \
        .stack   = &(tree)->iter_stack[0],                              \
        .is_left = &(tree)->iter_left[0],                               \
        .top     = -1                                                   \
}
#else
#define _RB_FOREACH_INIT(tree, node) {                                  \
        .stack   = (struct rbnode **)                                   \
                        alloca((tree)->max_depth * sizeof(struct rbnode *)), \
        .is_left = (uint8_t *)alloca((tree)->max_depth * sizeof(uint8_t)),\
        .top     = -1                                                   \
}
#endif
 
struct rbnode *z_rb_foreach_next(struct rbtree *tree, struct _rb_foreach *f);
 
#define RB_FOR_EACH(tree, node) \
        for (struct _rb_foreach __f = _RB_FOREACH_INIT(tree, node);     \
             (node = z_rb_foreach_next(tree, &__f));                    \
             )
 
#define RB_FOR_EACH_CONTAINER(tree, node, field)                           \
        for (struct _rb_foreach __f = _RB_FOREACH_INIT(tree, node);        \
                        ({struct rbnode *n = z_rb_foreach_next(tree, &__f); \
                         node = n ? CONTAINER_OF(n, __typeof__(*(node)),   \
                                         field) : NULL; }) != NULL;        \
                         )
 
#endif /* ZEPHYR_INCLUDE_SYS_RB_H_ */