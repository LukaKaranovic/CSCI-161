/**
 * @file singlelinkedlistmain.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 14, 2020
 *
 * Performs test usages of test functions of SingleLinkedList class.
 *
 */



#include <iostream>
#include "singlelinkedlist.h"
#include "binarysearchtree.h"

using namespace std;


void insertIntoBST(BSTree& tree, int* keys, int size) {
	for(int i=0; i<size; i++) {
		tree.insert(keys[i]);
	}
}

BSTree createBST(int* keys, int size) {
	BSTree tree;
	insertIntoBST(tree, keys, size);
	return tree;
}


int main(int argc, char** argv) {

		
	/*
	 * Testing Binary Search Tree
	 */

	cout<<endl<<".................................... Binary Search Tree ..............................."<<endl<<endl;

	BSTree tree = NULL;

	if(tree.isEmpty()){
		cout<<"BST is empty"<<endl;
	}
	else {
		cout<<"BST is not empty"<<endl;
	}
	
	int treeKeySize = 12;
	int treeKeys[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9, 14};

	cout<<"Inserting elements into Binary Search Tree"<<endl;
	insertIntoBST(tree, treeKeys, treeKeySize);
	if(tree.isEmpty()){
		cout<<"BST is empty"<<endl;
	}
	else {
		cout<<"BST is not empty"<<endl;
	}
	cout<<endl;


	cout<<"Preorder Traversal of Binary Search Tree"<<endl;
	const SingleLinkedList* preTraversal = tree.preorder();
	if(preTraversal != 0) {
		preTraversal->show();
		delete preTraversal;
	}
	cout<<endl;

	cout<<"Inorder Traversal of Binary Search Tree"<<endl;
	const SingleLinkedList* inTraversal = tree.inorder();
	if(inTraversal != 0) {
		inTraversal->show();
		delete inTraversal;
	}
	cout<<endl;

	cout<<"Postorder Traversal of Binary Search Tree"<<endl;
	const SingleLinkedList* postTraversal = tree.postorder();
	if(postTraversal != 0) {
		postTraversal->show();
		delete postTraversal;
	}
	cout<<endl;

	cout<<"Using copy constructor of Binary Search Tree"<<endl;
	BSTree copyConstructedTree(tree);
	const SingleLinkedList* copyConstructedInTraversal = copyConstructedTree.inorder();
	if(copyConstructedInTraversal !=0 ) {
		copyConstructedInTraversal->show();
		delete copyConstructedInTraversal;
	}
	copyConstructedTree.clear();
	cout<<endl;

	cout<<"Using move constructor of Binary Search Tree"<<endl;
	BSTree moveConstructedTree = createBST(treeKeys, treeKeySize);
	const SingleLinkedList* moveConstructedInTraversal = moveConstructedTree.inorder();
	if(moveConstructedInTraversal !=0 ) {
		moveConstructedInTraversal->show();
		delete moveConstructedInTraversal;
	}
	moveConstructedTree.clear();
	cout<<endl;


	cout<<"Using copy assignment of Binary Search Tree"<<endl;
	BSTree copyAssignedTree;
	copyAssignedTree = tree;
	const SingleLinkedList* copyAssignedInTraversal = copyAssignedTree.inorder();
	if(copyAssignedInTraversal !=0 ) {
		copyAssignedInTraversal->show();
		delete copyAssignedInTraversal;
	}
	copyAssignedTree.clear();
	cout<<endl;

	cout<<"Using move assignment of Binary Search Tree"<<endl;
	BSTree moveAssignedTree;
	moveAssignedTree = createBST(treeKeys, treeKeySize);
	const SingleLinkedList* moveAssignedInTraversal = moveAssignedTree.inorder();
	if(moveAssignedInTraversal !=0 ) {
		moveAssignedInTraversal->show();
		delete moveAssignedInTraversal;
	}
	moveAssignedTree.clear();
	cout<<endl;


	int searchKey = 9;
	cout<<"Searching "<<searchKey<<" in Binary Search Tree"<<endl;
	const BSTNode* const foundBSTNode = tree.search(searchKey);
	if(foundBSTNode != NULL) {
		cout<<"Found: "<<foundBSTNode->getKey()<<endl;
	}
	else {
		cout<<"Search for "<<searchKey <<" faild"<<endl;
	}

	cout<<"Getting Minimum from Binary Search Tree"<<endl;
	const int minimum = tree.minimum();
	cout<<"Minimum is: "<<minimum<<endl;

	
	cout<<"Getting Maximum from Binary Search Tree"<<endl;
	const int maximum = tree.maximum();
	cout<<"Maximum is: "<<maximum<<endl;
	
	
	int key = 15;
	const int successor = tree.successor(key);
	cout<<"Successor of "<<key<<" is "<<successor<<endl;
	
	const int predecessor = tree.predecessor(key);
	cout<<"Predecessor of "<<key<<" is "<<predecessor<<endl;
	

	cout<<"Removing "<<searchKey<<" from Binary Search Tree"<<endl;
	tree.remove(searchKey);
	cout<<"After removing "<<searchKey<<endl;

	const BSTNode* const notFoundBSTNode = tree.search(searchKey);
	if(notFoundBSTNode == NULL) {
		cout<<"Not found "<<searchKey<<endl;
	}
	else {
		cout<<"Found "<<searchKey<<endl;
	}

	cout<<"Re-inserting "<<searchKey<<" into Binary Search Tree"<<endl;
	tree.insert(searchKey);
	cout<<"After re-inserting "<<searchKey<<endl;

	const BSTNode* const foundBSTNodeAfterReInsert = tree.search(searchKey);
	if(foundBSTNodeAfterReInsert != NULL) {
		cout<<"Found "<<foundBSTNodeAfterReInsert->getKey()<<endl;
	}
	else {
		cout<<"Not found "<<searchKey<<endl;
	}
	cout<<endl;

	cout<<"Clearing the tree"<<endl;
	tree.clear();
	cout<<"After clearing the tree"<<endl;

	if(tree.isEmpty()) {
		cout<<"Tree is empty"<<endl;
	}
	else {
		cout<<"Tree is not empty"<<endl;
	}

	

	return 0;
}

