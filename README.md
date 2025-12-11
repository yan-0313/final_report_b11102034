[TOC]  
<br>\

# Mini Search Engine<br> 
This project implements a Mini Search Engine using a Binary Search Tree (BST) data structure.<br> 
All dictionary entries (word + meaning) are stored inside a BST with case-insensitive ordering, enabling:<br> 
* Fast search<br> 
* Word insertion<br> 
* Word deletion<br> 
* Path tracking<br> 
* Closest word suggestion (predecessor & successor)<br> 
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
+ Load dictionary<br> 
  Reads word–meaning pairs from a text file and inserts them into a BST.<br> 

+ Show all words (in sorted order)<br> 
  Uses inorder traversal to print dictionary in A→Z order (case-insensitive).<br> 

+ Search for a word<br> 
  Shows whether the word exists<br> 
  Prints search path (all visited nodes)<br> 
  Prints comparison count<br> 
  If not found → suggests closest words<br>
    + Predecessor (largest word smaller than query)<br>
    + Successor (smallest word larger than query)<br> 

+ Add a new word<br> 
  Insert or update a word and its meaning.<br> 

+ Delete a word<br> 
  Removes the node from the BST while preserving tree structure.<br> 

+ Case-insensitive comparison<br> 
  “X-ray”, “x-RAY”, “Bible”, “bible” all map to same BST location.<br> 

#How to Compile<br> 
Using Visual Studio (Windows, recommended)<br> 

# How to Run<br> 
<br> After executing the program, you will see the main menu
<img width="1582" height="789" alt="image" src="https://github.com/user-attachments/assets/fdce65e8-a78a-498c-966a-b2d278422bb0" />

### Load dictionary<br> 
<img width="1582" height="789" alt="image" src="https://github.com/user-attachments/assets/cab94693-121c-43df-b572-04a37714fc2f" />
<img width="1582" height="789" alt="image" src="https://github.com/user-attachments/assets/d5f37743-fb24-4c2b-95cf-9e5fd9b6030a" />

### Show all dictionary data<br> 
<img width="1582" height="789" alt="image" src="https://github.com/user-attachments/assets/57c4bb4b-c001-4811-9950-9b258bc51453" />

### Search<br> 
<img width="1582" height="789" alt="image" src="https://github.com/user-attachments/assets/dd3b3622-7b7e-4729-84c2-eded7c750991" />

### Search for a non-existing word<br> 
<img width="1582" height="789" alt="image" src="https://github.com/user-attachments/assets/9e45a585-f823-44d0-9f59-568611ba467c" />

### Add a word and search<br> 
<img width="1582" height="845" alt="image" src="https://github.com/user-attachments/assets/d84e650a-cbfa-4fae-9f75-94429bb2e0a1" />

### Delete a word<br> 
<img width="1582" height="845" alt="image" src="https://github.com/user-attachments/assets/cbbd5992-2361-43b3-8787-278607019ce2" />

# Dictionary Format<br> 
Every line must contain:
`word<TAB>meaning`<br> 
Example:
`accord	[n] 一致、符合  
Bible	[n]《聖經》  
X-ray	X光  
apple	[n] 蘋果`
