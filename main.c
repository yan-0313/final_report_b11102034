#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "bst.h"
#include "dict_loader.h"

static void clearLineBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* 丟掉這一行剩下的東西 */
    }
}

int main(void) {
    TreeNode* root = NULL;
    int choice;

    while (1) {
        printf("\n===== Mini Search Engine =====\n");
        printf("1. Load dictionary\n");
        printf("2. Show all words\n");
        printf("3. Search a word\n");
        printf("4. Add a new word\n");
        printf("5. Delete a word\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clearLineBuffer();
            continue;
        }

        if (choice == 1) {
            char filename[256];
            printf("Enter dictionary file (e.g., dictionary_data_1.txt): ");
            if (scanf("%255s", filename) != 1) {
                printf("Invalid filename.\n");
                clearLineBuffer();
                continue;
            }

            if (loadDictionary(filename, &root))
                printf("Dictionary loaded successfully.\n");
        }
        else if (choice == 2) {
            if (!root) {
                printf("Please load dictionary first.\n");
            } else {
                inorder(root);
            }
        }
        else if (choice == 3) {
            if (!root) {
                printf("Please load dictionary first.\n");
                continue;
            }

            char query[MAX_WORD_LEN];
            printf("Enter word to search: ");
            if (scanf("%127s", query) != 1) {
                printf("Invalid input.\n");
                clearLineBuffer();
                continue;
            }

            char path[MAX_PATH_LEN][MAX_WORD_LEN];
            int path_len = 0;
            int comparisons = 0;

            TreeNode* result = searchNode(root, query, path, &path_len, &comparisons);

            printf("Search path: ");
            if (path_len == 0) {
                printf("(empty)");
            } else {
                int i;
                for (i = 0; i < path_len; ++i) {
                    if (i > 0) printf(" -> ");
                    printf("%s", path[i]);
                }
            }
            printf("\nComparisons: %d\n", comparisons);

            if (result) {
                printf("Found: %s : %s\n", result->data.word, result->data.meaning);
            } else {
                printf("Not found.\n");

                TreeNode* pred = NULL;
                TreeNode* succ = NULL;
                findClosest(root, query, &pred, &succ);

                printf("Closest suggestions:\n");
                if (pred) {
                    printf("  Previous (smaller): %s : %s\n", pred->data.word, pred->data.meaning);
                }
                if (succ) {
                    printf("  Next (larger):     %s : %s\n", succ->data.word, succ->data.meaning);
                }
                if (!pred && !succ) {
                    printf("  (No close words found in dictionary)\n");
                }
            }
        }
        else if (choice == 4) {
            /* Add a new word */
            Entry e;
            clearLineBuffer(); /* 清掉前一個 scanf 留下的換行 */

            printf("Enter new word: ");
            if (!fgets(e.word, sizeof(e.word), stdin)) {
                printf("Input error.\n");
                continue;
            }
            /* 去掉 \n */
            e.word[strcspn(e.word, "\r\n")] = '\0';

            printf("Enter meaning: ");
            if (!fgets(e.meaning, sizeof(e.meaning), stdin)) {
                printf("Input error.\n");
                continue;
            }
            e.meaning[strcspn(e.meaning, "\r\n")] = '\0';

            if (e.word[0] == '\0') {
                printf("Word cannot be empty.\n");
            } else {
                insertNode(&root, &e);
                printf("Word inserted/updated successfully.\n");
            }
        }
        else if (choice == 5) {
            if (!root) {
                printf("Dictionary is empty.\n");
                continue;
            }

            char word[MAX_WORD_LEN];
            printf("Enter word to delete: ");
            if (scanf("%127s", word) != 1) {
                printf("Invalid input.\n");
                clearLineBuffer();
                continue;
            }

            char dummyPath[MAX_PATH_LEN][MAX_WORD_LEN];
            int dummyLen = 0;
            int dummyCmp = 0;
            TreeNode* found = searchNode(root, word, dummyPath, &dummyLen, &dummyCmp);

            if (!found) {
                printf("Word not found. Nothing deleted.\n");
            } else {
                deleteNode(&root, word);
                printf("Word deleted successfully.\n");
            }
        }
        else if (choice == 6) {
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    freeTree(root);
    return 0;
}
