#include "dict_loader.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 去除字串尾端的 \r\n 空白 */
static void rtrim(char* s) {
    int len = (int)strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r' || isspace((unsigned char)s[len - 1]))) {
        s[len - 1] = '\0';
        --len;
    }
}

int loadDictionary(const char* filename, TreeNode** root) {
    FILE* fp;
#ifdef _MSC_VER
    fopen_s(&fp, filename, "r");
#else
    fp = fopen(filename, "r");
#endif
    if (!fp) {
        printf("Failed to open dictionary file: %s\n", filename);
        return 0;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        rtrim(line);
        if (line[0] == '\0')
            continue;

        /* 格式：word<空白/Tab>meaning */
        char* p = line;
        while (*p && isspace((unsigned char)*p)) p++; /* skip leading spaces */

        char word[MAX_WORD_LEN] = {0};
        char meaning[MAX_MEANING_LEN] = {0};

        /* 讀取單字直到分隔的空白或 Tab */
        int i = 0;
        while (*p && !isspace((unsigned char)*p) && i < MAX_WORD_LEN - 1) {
            word[i++] = *p++;
        }
        word[i] = '\0';

        while (*p && isspace((unsigned char)*p)) p++; /* skip spaces after word */
        strncpy(meaning, p, MAX_MEANING_LEN - 1);
        meaning[MAX_MEANING_LEN - 1] = '\0';

        if (word[0] != '\0') {
            Entry e;
            strncpy(e.word, word, MAX_WORD_LEN);
            e.word[MAX_WORD_LEN - 1] = '\0';
            strncpy(e.meaning, meaning, MAX_MEANING_LEN);
            e.meaning[MAX_MEANING_LEN - 1] = '\0';

            insertNode(root, &e);
        }
    }

    fclose(fp);
    return 1;
}
