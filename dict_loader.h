#define _CRT_SECURE_NO_WARNINGS
#ifndef DICT_LOADER_H
#define DICT_LOADER_H

#include "bst.h"

/* 回傳 1 表成功，0 失敗 */
int loadDictionary(const char* filename, TreeNode** root);

#endif
