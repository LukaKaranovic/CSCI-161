/**
 * @file binarysearchtree.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 14, 2020
 *
 * Defines the functions related to binary search tree of integer key.
 *
 */


#ifndef __BINARY_SEARCH_TREE_HEADER__
#define __BINARY_SEARCH_TREE_HEADER__

#include "singlelinkedlist.h"

class BSTree;
class BSTreeInternalTest;

/*
 * Defining binary search tree node class BSTNode
 * BSTNode will be used to build binary search tree
 */
class BSTNode {
	private:
		int key;
		BSTNode* left = 0;		//Initialized to NULL
		BSTNode* right = 0;		//Initialized to NULL
	public:
		BSTNode(int key): key(key), left(0), right(0) {}
		BSTNode(int key, BSTNode* left, BSTNode* right): key(key), left(left), right(right) {} //Constructor
		~BSTNode() {} 	//Destructor
		
		const int getKey() const {return key;}

		friend class BSTree;
		friend class BSTreeTest;
		

};


class BSTree {
	private:
	 	BSTNode* _root;

		void insert(BSTNode*& root, const int key);
		//Check whether the 'root' is NULL or not.
		//If root is NULL, create a new binary search root node with the 'key'
		//and assign the new node to the root.
		//Otherwise, compare the 'key' with the key of the 'root'.
		//If the 'key' is less than the key of the 'root', insert the key into left sub-tree.
		//Otherwise, insert the key into the right sub-tree.


		BSTNode* search(BSTNode* root, int key) const;
		//Check whether the 'root' is pointing NULL or not.
		//If 'root' is pointing NULL, return NULL.
		//Otherwise, compare 'root' key with parameter 'key'.
		//If they are equal return 'root'.
		//If parameter 'key' is smaller than 'root' key continue search on the left sub-tree.
		//Otherwise, continue search on the right sub-tree.


		BSTNode* minimum(BSTNode* root) const;
		//Check whther the root itself or the left sub-tree is NULL or not.
		//If any of them is NULL, return 'root'.
		//Otherwise, continue to find the minimum on the left sub-tree.


		BSTNode* maximum(BSTNode* root) const;
		//Check whther the root itself or the right sub-tree is NULL or not.
		//If any of them is NULL, return 'root'.
		//Otherwise, continue to find the minimum on the right sub-tree.


		BSTNode* successor(BSTNode* root) const;
		//Check whther the root itself or the right sub-tree is NULL or not.
		//If any of them  is NULL, return NULL.
		//Otherwise, return the minimum from the right sub-tree.


		BSTNode* predecessor(BSTNode* root) const;
		//Check whther the root itself or the left sub-tree is NULL or not.
		//If any of them is NULL, return NULL.
		//Otherwise, return the maximum from the left sub-tree.



		void remove(BSTNode*& root, const int key);
		//Check whether the 'root' is NULL or not.
		//If 'root' is NULL, do nothing.
		//Otherwise, compare 'key' with the key of the 'root'.
		//If the 'key' is less than the key of the 'root', continue to remove on the left sub-tree.
		//If the 'key' is greater than the key of the 'root', continue to remove on the right sub-tree
		//If the 'key' is equal to the key of the 'root', remove this node from the binary search tree.
		//If the node subject to remove has both left and right children, copy its succesor's key to
		//this node and remove the successor node from the right sub-tree.
		//If the node subject to remove has either only left child or only right child, point to that child
		//from the parent's node and release memory from the subject node.
		//If the node subject to remove does not have any child, release memory from the subject node and
		//assign NULL to its pointer.   


		void preorder(BSTNode* root, SingleLinkedList* traversal) const;
		//If the root is NULL, return.
		//Insert a new single linked list node with the key equal to the key of the 
		//current root node into the 'traversal'. 
		//Traverse preorder on the left sub-tree recursively.
		//Traverse preorder on the right sub-tree recursively.
		

		void inorder(BSTNode* root, SingleLinkedList* traversal) const;
		//If the root is NULL, return.
		//Traverse inorder on the left sub-tree recursively.
		//Insert a new single linked list node with the key equal to the key of the 
		//current node into the 'traversal'. 
		//Traverse inorder on the right sub-tree recursively.


		void postorder(BSTNode* root, SingleLinkedList* traversal) const;
		//If the root is NULL, return.
		//Traverse postorder on the left sub-tree recursively.
		//Traverse postorder on the right sub-tree recursively.
		//Insert a new single linked list node with the key equal to the key of the 
		//current node into the 'traversal'. 


		void copy(BSTree& destination, const BSTree& source);
		//Copy the binary search tree pointed by 'source' into 'destination'


		bool equal( BSTNode* bst1, BSTNode* bst2) const;
		//Return true if two binary search trees pointed by 'bast1' and 'bst2'
		//have the same node values and the structure.
		//Return false otherwise.


		bool equivalent(BSTNode* bst1, BSTNode* bst2) const;
		//Return true if two binary search trees pointed by 'bast1' and 'bst2'
		//have the same node values.
		//Return false otherwise.




	public:
		BSTree();				//Default constructor
		BSTree(BSTNode* root);  //Constructor
		~BSTree();				//Destructor

		BSTree(const BSTree& copy); //Copy constructor
		BSTree(BSTree&& temp); 		//Move constructor

		BSTree& operator=(const BSTree& other); //Copy assignment

		BSTree& operator=(BSTree&& temp); 		//Move assignment

		bool isEmpty() const;
		//Return true if the tree is empty, otherwise false.

		void insert(const int key);
		//Insert a new node into the tree

		
		const BSTNode* const search(int key) const;
		//Return the pointer of the tree node whose key is equal to 'key'


		const int minimum() const;
		//Return the minimum key value from the tree.
		//Return -1 if the tree is empty.


		const int maximum() const;
		//Return the maximum key value from the tree.
		//Return -1 if the tree is empty.


		const int successor(const int key) const;
		//Return the successor key of 'key'
		//Return -1, if 'key' does not have any successor.


		const int predecessor(const int key) const;
		//Return the predecessor key of 'key'
		//Return -1, if 'key' does not have any predecessor.


		void remove(const int key);
		//Remove the node whose key is equal to 'key'


		const SingleLinkedList* preorder() const;
		//If the tree is empty, return NULL.
		//Otherwise, dynamically create a SingleLinkedList. 
		//Traverse the tree preorder and insert a new single linked list node 
		//with the key equal to the key of the current tree node into the SingleLinkedList. 
		//Return the pointer of the SingleLinkedList.


		const SingleLinkedList* inorder() const;
		//If the tree is empty, return NULL.
		//Otherwise, dynamically create a SingleLinkedList. 
		//Traverse the tree ineorder and insert a new single linked list node 
		//with the key equal to the key of the current tree node into the SingleLinkedList. 
		//Return the pointer of the SingleLinkedList.


		const  SingleLinkedList* postorder() const;
		//If the tree is empty, return NULL.
		//Otherwise, dynamically create a SingleLinkedList. 
		//Traverse the tree postorder and insert a new single linked list node 
		//with the key equal to the key of the current tree node into the SingleLinkedList. 
		//Return the pointer of the SingleLinkedList.


		void clear();
		//Remove all the nodes from the 'tree' until it is empty.


		bool equal(const BSTree& other) const;
		//Return true if the other binary search tree
		//has the same node values and the structure as this binary search tree.
		//Return false otherwise.


		bool equivalent(const BSTree& other) const;
		//Return true if the other binary search tree
		//has the same node values as this binary search tree.
		//Return false otherwise.

		friend class BSTreeTest;

};


#endif
