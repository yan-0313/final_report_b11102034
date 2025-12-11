# Mini Search Engine<br> 
This project implements a Mini Search Engine using a Binary Search Tree (BST) data structure.<br> 
All dictionary entries (word + meaning) are stored inside a BST with case-insensitive ordering, enabling:<br> 
● Fast search<br> 
● Word insertion<br> 
● Word deletion<br> 
● Path tracking<br> 
● Closest word suggestion (predecessor & successor)<br> 
The program loads dictionary data from .txt files and provides an interactive command-line menu.<br> 
<br> 
# Project File Structure<br> 
/final_report_b11102034<br> 
│<br> 
├── main.c<br> 
├── bst.c<br> 
├── bst.h<br> 
├── dict_loader.c<br> 
├── dict_loader.h<br> 
├── dictionary_data_1.txt<br> 
├── dictionary_data_2.txt<br> 
└── README.md<br> 
<br> 
# Features<br> 
✔ Load dictionary<br> 
  Reads word–meaning pairs from a text file and inserts them into a BST.<br> 

✔ Show all words (in sorted order)<br> 
  Uses inorder traversal to print dictionary in A→Z order (case-insensitive).<br> 

✔ Search for a word<br> 
  Shows whether the word exists<br> 
  Prints search path (all visited nodes)<br> 
  Prints comparison count<br> 
  If not found → suggests closest words<br> 
  ● Predecessor (largest word smaller than query)<br> 
  ● Successor (smallest word larger than query)<br> 

✔ Add a new word<br> 
  Insert or update a word and its meaning.<br> 

✔ Delete a word<br> 
  Removes the node from the BST while preserving tree structure.<br> 

✔ Case-insensitive comparison<br> 
  “X-ray”, “x-RAY”, “Bible”, “bible” all map to same BST location.<br> 

#How to Compile<br> 
Using Visual Studio (Windows, recommended)<br> 

# How to Run<br> 
After executing the program, you will see the main menu:
<img width="1583" height="789" alt="image" src="https://github.com/user-attachments/assets/5b0173d6-d4fb-4072-b15b-6f29bc764512" />
Load dictionary<br> 
<img width="1583" height="789" alt="image" src="https://github.com/user-attachments/assets/3cba9c04-c40e-4b2c-afa9-14694576959a" />
Show all dictionary data<br> 
<img width="1583" height="789" alt="image" src="https://github.com/user-attachments/assets/261efcdb-3cec-4965-ba96-7ed9941c74b3" />
Search<br> 
<img width="1583" height="945" alt="image" src="https://github.com/user-attachments/assets/c490919d-0941-45d9-9ac2-f49c7c944004" />


