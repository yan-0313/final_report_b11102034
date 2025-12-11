#define _CRT_SECURE_NO_WARNINGS
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 大小寫不分字串比較：<0: a<b, 0: a==b, >0: a>b */
static int ciCompare(const char* a, const char* b) {
    unsigned char ca, cb;
    while (*a && *b) {
        ca = (unsigned char)tolower((unsigned char)*a);
        cb = (unsigned char)tolower((unsigned char)*b);
        if (ca < cb) return -1;
        if (ca > cb) return 1;
        ++a;
        ++b;
    }
    if (*a == *b) return 0;
    return *a ? 1 : -1;
}

/* ===== 插入節點（不分大小寫排序） ===== */
void insertNode(TreeNode** root, const Entry* e) {
    if (root == NULL || e == NULL) return;

    if (*root == NULL) {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        if (!node) return;
        node->data = *e; /* 結構直接指定即可 */
        node->left = node->right = NULL;
        *root = node;
        return;
    }

    TreeNode* cur = *root;
    while (1) {
        int cmp = ciCompare(e->word, cur->data.word);
        if (cmp < 0) {
            if (cur->left == NULL) {
                TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
                if (!node) return;
                node->data = *e;
                node->left = node->right = NULL;
                cur->left = node;
                break;
            }
            cur = cur->left;
        } else if (cmp > 0) {
            if (cur->right == NULL) {
                TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
                if (!node) return;
                node->data = *e;
                node->left = node->right = NULL;
                cur->right = node;
                break;
            }
            cur = cur->right;
        } else {
            /* key 相同（不分大小寫）→ 更新 meaning */
            cur->data = *e;
            break;
        }
    }
}

/* ===== Inorder 印出（排序後） ===== */
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%s : %s\n", root->data.word, root->data.meaning);
    inorder(root->right);
}

/* ===== 搜尋節點 + 紀錄路徑 ===== */
TreeNode* searchNode(TreeNode* root,
                     const char* key,
                     char path[][MAX_WORD_LEN],
                     int* path_len,
                     int* comparisons) {
    if (!key) return NULL;
    if (path_len) *path_len = 0;
    if (comparisons) *comparisons = 0;

    TreeNode* cur = root;
    while (cur) {
        if (path && path_len && *path_len < MAX_PATH_LEN) {
            strncpy(path[*path_len], cur->data.word, MAX_WORD_LEN - 1);
            path[*path_len][MAX_WORD_LEN - 1] = '\0';
            (*path_len)++;
        }
        if (comparisons) (*comparisons)++;

        int cmp = ciCompare(key, cur->data.word);
        if (cmp == 0) {
            return cur;
        } else if (cmp < 0) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return NULL;
}

/* ===== 找子樹中最小的節點（給 delete 用） ===== */
static TreeNode* findMin(TreeNode* node) {
    if (!node) return NULL;
    while (node->left) {
        node = node->left;
    }
    return node;
}

/* ===== 找最接近 key 的前驅 / 後繼 ===== */
void findClosest(TreeNode* root,
                 const char* key,
                 TreeNode** pred,
                 TreeNode** succ) {
    if (pred) *pred = NULL;
    if (succ) *succ = NULL;
    if (!key) return;

    TreeNode* cur = root;
    while (cur) {
        int cmp = ciCompare(key, cur->data.word);
        if (cmp < 0) {
            if (succ) *succ = cur;
            cur = cur->left;
        } else if (cmp > 0) {
            if (pred) *pred = cur;
            cur = cur->right;
        } else {
            /* 理論上 search 找不到才會呼叫 findClosest，這裡先簡化忽略 */
            break;
        }
    }
}

/* ===== 刪除節點 ===== */
void deleteNode(TreeNode** root, const char* key) {
    if (!root || !*root || !key) return;

    int cmp = ciCompare(key, (*root)->data.word);
    if (cmp < 0) {
        deleteNode(&((*root)->left), key);
    } else if (cmp > 0) {
        deleteNode(&((*root)->right), key);
    } else {
        /* 找到了要刪的節點 *root */

        /* Case 1: 無子節點 */
        if (!(*root)->left && !(*root)->right) {
            free(*root);
            *root = NULL;
        }
        /* Case 2: 只有右子樹 */
        else if (!(*root)->left) {
            TreeNode* tmp = *root;
            *root = (*root)->right;
            free(tmp);
        }
        /* Case 2: 只有左子樹 */
        else if (!(*root)->right) {
            TreeNode* tmp = *root;
            *root = (*root)->left;
            free(tmp);
        }
        /* Case 3: 左右子樹都有 */
        else {
            TreeNode* succ = findMin((*root)->right);
            if (succ) {
                (*root)->data = succ->data;
                deleteNode(&((*root)->right), succ->data.word);
            }
        }
    }
}

/* ===== 釋放整棵樹 ===== */
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
