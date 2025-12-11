#define _CRT_SECURE_NO_WARNINGS
#ifndef BST_H
#define BST_H

#include <stddef.h>

#define MAX_WORD_LEN     128
#define MAX_MEANING_LEN  512
#define MAX_PATH_LEN     256

typedef struct Entry {
    char word[MAX_WORD_LEN];
    char meaning[MAX_MEANING_LEN];
} Entry;

typedef struct TreeNode {
    Entry data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void insertNode(TreeNode** root, const Entry* e);
void inorder(TreeNode* root);

/* 搜尋 + 記錄路徑與比較次數 */
TreeNode* searchNode(TreeNode* root,
                     const char* key,
                     char path[][MAX_WORD_LEN],
                     int* path_len,
                     int* comparisons);

/* 找最接近 key 的前驅 / 後繼 */
void findClosest(TreeNode* root,
                 const char* key,
                 TreeNode** pred,
                 TreeNode** succ);

/* 刪除單字 */
void deleteNode(TreeNode** root, const char* key);

/* 釋放整棵樹（可選） */
void freeTree(TreeNode* root);

#endif
