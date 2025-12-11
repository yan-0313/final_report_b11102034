#Mini Search Engine
This project implements a Mini Search Engine using a Binary Search Tree (BST) data structure.
All dictionary entries (word + meaning) are stored inside a BST with case-insensitive ordering, enabling:
● Fast search
● Word insertion
● Word deletion
● Path tracking
● Closest word suggestion (predecessor & successor)
The program loads dictionary data from .txt files and provides an interactive command-line menu.

#Project File Structure
/final_report_b11102034
│
├── main.c
├── bst.c
├── bst.h
├── dict_loader.c
├── dict_loader.h
├── dictionary_data_1.txt
├── dictionary_data_2.txt
└── README.md

#Features
✔ Load dictionary
  Reads word–meaning pairs from a text file and inserts them into a BST.

✔ Show all words (in sorted order)
  Uses inorder traversal to print dictionary in A→Z order (case-insensitive).

✔ Search for a word
  Shows whether the word exists
  Prints search path (all visited nodes)
  Prints comparison count
  If not found → suggests closest words
  ● Predecessor (largest word smaller than query)
  ● Successor (smallest word larger than query)

✔ Add a new word
  Insert or update a word and its meaning.

✔ Delete a word
  Removes the node from the BST while preserving tree structure.

✔ Case-insensitive comparison
  “X-ray”, “x-RAY”, “Bible”, “bible” all map to same BST location.

#How to Compile
Using Visual Studio (Windows, recommended)

Step 1: Create a C Project
  File → New → Project → Empty Project
  Add existing files:
  main.c
  bst.c
  dict_loader.c
  bst.h
  dict_loader.h

