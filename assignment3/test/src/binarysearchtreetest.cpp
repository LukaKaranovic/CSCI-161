/**
 * @file binarysearchtreetest.cpp
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date April 14, 2023
 *
 * Performs unit tests on the functions of BinarySearchTree class.
 *
 */


#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE assignment3_single_linked_list

#include <boost/test/unit_test.hpp>

#include <iostream>
#include "singlelinkedlist.h"
#include "binarysearchtree.h"
#include "binarysearchtreetest.h"



void BSTreeTest::privateInsert(BSTree& tree) {
	tree.clear();
	int values[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9, 14};
	int size = 12;
    for(int i=0; i<size; i++ ) {
		tree.insert(tree._root, values[i]);
    }
}


bool BSTreeTest::testInsertedNodes(const BSTree& tree) {
            BSTNode* root = tree._root;
            return (root != 0 && root->key == 15 && 
				root->left != 0 && root->left->key == 6 && 
				root->left->left != 0 && root->left->left->key == 3 &&
				root->left->left->left != 0 &&
				root->left->left->left->key == 2 &&
				root->left->left->left->left == 0 &&
				root->left->left->left->right == 0 &&
				root->left->left->right != 0 &&
				root->left->left->right->key == 4 &&
				root->left->left->right->left == 0 && 
				root->left->left->right->right == 0 &&
				root->left->right != 0 &&
				root->left->right->key == 7 &&
				root->left->right->left == 0 &&
				root->left->right->right != 0 &&
				root->left->right->right->key == 13 &&
				root->left->right->right->left != 0 &&
				root->left->right->right->left->key == 9 &&
				root->left->right->right->left->left == 0 &&
				root->left->right->right->left->right == 0 &&
				root->left->right->right->right != 0 &&
				root->left->right->right->right->key == 14 &&
				root->left->right->right->right->left == 0 &&
				root->left->right->right->right->right == 0 &&
				root->right != 0 && root->right->key == 18 &&
				root->right->left != 0 && root->right->left->key == 17 &&
				root->right->left->left == 0 &&
				root->right->left->right == 0 &&
				root->right->right != 0 &&
				root->right->right->key == 20 &&
				root->right->right->left == 0 &&
				root->right->right->right == 0) ;

        }



bool BSTreeTest::testPrivateInsert(BSTree& tree) {
	privateInsert(tree);
    return testInsertedNodes(tree);
}

bool BSTreeTest::testPrivateSearch(BSTree& tree) {
   
    int searchKey = 22;
	BSTNode* node = tree.search(tree._root, searchKey);
    if(node != 0) {
        return false;
    }
    searchKey = 13;
    node = tree.search(tree._root, searchKey);
    if(node == 0) {
        return false;
    }
    if(node->key != searchKey) {
        return false;
    }

    return true;
}

bool BSTreeTest::testPrivateMinimum(BSTree& tree) {
    BSTNode* node = tree.minimum(tree._root);
    return (node != 0 && node->key == 2);
}

bool BSTreeTest::testPrivateMaximum(BSTree& tree) {
    BSTNode* node = tree.maximum(tree._root);
    return (node != 0 && node->key == 20);
}

bool BSTreeTest::testPrivateSuccessor(BSTree& tree) {
    BSTNode* node = tree.successor(tree._root);
    return (node != 0 && node->key == 17);
}

bool BSTreeTest::testPrivatePredecessor(BSTree& tree) {
    BSTNode* node = tree.predecessor(tree._root);
    return (node != 0 && node->key == 14);
}


bool BSTreeTest::testRemoveNonExistingNode(const BSTree& tree) {
            BSTNode* root = tree._root;

            return (root != 0 && root->key == 15 && 
				root->left != 0 && root->left->key == 6 && 
				root->left->left != 0 && root->left->left->key == 3 &&
				root->left->left->left != 0 &&
				root->left->left->left->key == 2 &&
				root->left->left->left->left == 0 &&
				root->left->left->left->right == 0 &&
				root->left->left->right != 0 &&
				root->left->left->right->key == 4 &&
				root->left->left->right->left == 0 && 
				root->left->left->right->right == 0 &&
				root->left->right != 0 &&
				root->left->right->key == 7 &&
				root->left->right->left == 0 &&
				root->left->right->right != 0 &&
				root->left->right->right->key == 13 &&
				root->left->right->right->left != 0 &&
				root->left->right->right->left->key == 9 &&
				root->left->right->right->left->left == 0 &&
				root->left->right->right->left->right == 0 &&
				root->left->right->right->right != 0 &&
				root->left->right->right->right->key == 14 &&
				root->left->right->right->right->left == 0 &&
				root->left->right->right->right->right == 0 &&
				root->right != 0 && root->right->key == 18 &&
				root->right->left != 0 && root->right->left->key == 17 &&
				root->right->left->left == 0 &&
				root->right->left->right == 0 &&
				root->right->right != 0 &&
				root->right->right->key == 20 &&
				root->right->right->left == 0 &&
				root->right->right->right == 0);

}


bool BSTreeTest::testRemoveLeafNode(const BSTree& tree) {
            BSTNode* root = tree._root;
            return (root != 0 && root->key == 15 && 
				root->left != 0 && root->left->key == 6 && 
				root->left->left != 0 && root->left->left->key == 3 &&
				root->left->left->left != 0 &&
				root->left->left->left->key == 2 &&
				root->left->left->left->left == 0 &&
				root->left->left->left->right == 0 &&
				root->left->left->right == 0 &&
				root->left->right != 0 &&
				root->left->right->key == 7 &&
				root->left->right->left == 0 &&
				root->left->right->right != 0 &&
				root->left->right->right->key == 13 &&
				root->left->right->right->left != 0 &&
				root->left->right->right->left->key == 9 &&
				root->left->right->right->left->left == 0 &&
				root->left->right->right->left->right == 0 &&
				root->left->right->right->right != 0 &&
				root->left->right->right->right->key == 14 &&
				root->left->right->right->right->left == 0 &&
				root->left->right->right->right->right == 0 &&
				root->right != 0 && root->right->key == 18 &&
				root->right->left != 0 && root->right->left->key == 17 &&
				root->right->left->left == 0 &&
				root->right->left->right == 0 &&
				root->right->right != 0 &&
				root->right->right->key == 20 &&
				root->right->right->left == 0 &&
				root->right->right->right == 0);
}

bool BSTreeTest::testRemoveNonLeafOneChildNode(const BSTree& tree) {
            BSTNode* root = tree._root;
            return (root != 0 && root->key == 15 && 
				root->left != 0 && root->left->key == 6 && 
				root->left->left != 0 && root->left->left->key == 3 &&
				root->left->left->left != 0 &&
				root->left->left->left->key == 2 &&
				root->left->left->left->left == 0 &&
				root->left->left->left->right == 0 &&
				root->left->left->right == 0 &&
				root->left->right != 0 &&
				root->left->right->key == 13 &&
				root->left->right->left != 0 &&
				root->left->right->left->key == 9 &&
				root->left->right->left->left == 0 &&
				root->left->right->left->right == 0 &&
				root->left->right->right != 0 &&
				root->left->right->right->key == 14 &&
				root->left->right->right->left == 0 &&
				root->left->right->right->right == 0 &&
				root->right != 0 && root->right->key == 18 &&
				root->right->left != 0 && root->right->left->key == 17 &&
				root->right->left->left == 0 &&
				root->right->left->right == 0 &&
				root->right->right != 0 &&
				root->right->right->key == 20 &&
				root->right->right->left == 0 &&
				root->right->right->right == 0);
}

bool BSTreeTest::testRemoveNonLeafTwoChildrenNode (const BSTree& tree) {
            BSTNode* root = tree._root;
            return (root != 0 && root->key == 15 && 
				root->left != 0 && root->left->key == 6 && 
				root->left->left != 0 && root->left->left->key == 3 &&
				root->left->left->left != 0 &&
				root->left->left->left->key == 2 &&
				root->left->left->left->left == 0 &&
				root->left->left->left->right == 0 &&
				root->left->left->right == 0 &&
				root->left->right != 0 &&
				root->left->right->key == 13 &&
				root->left->right->left != 0 &&
				root->left->right->left->key == 9 &&
				root->left->right->left->left == 0 &&
				root->left->right->left->right == 0 &&
				root->left->right->right != 0 &&
				root->left->right->right->key == 14 &&
				root->left->right->right->left == 0 &&
				root->left->right->right->right == 0 &&
				root->right != 0 && root->right->key == 20 &&
				root->right->left != 0 && root->right->left->key == 17 &&
				root->right->left->left == 0 &&
				root->right->left->right == 0 &&
				root->right->right == 0 );
}

bool BSTreeTest::testPrivateRemove(BSTree& tree) {
    tree.remove(tree._root, 22);
    bool isNonExistingRemove = testRemoveNonExistingNode(tree);
    tree.remove(tree._root, 4);
    bool isRemoveLeafNode = testRemoveLeafNode(tree);
    tree.remove(tree._root, 7);
    bool isRemoveNonLeafOneChildNode = testRemoveNonLeafOneChildNode(tree);
    tree.remove(tree._root, 18);
    bool isRemoveNonLeafTwoChildrenNode = testRemoveNonLeafTwoChildrenNode(tree);
    return (isNonExistingRemove && isRemoveLeafNode &&  
            isRemoveNonLeafOneChildNode && isRemoveNonLeafTwoChildrenNode);
}



SingleLinkedList* BSTreeTest::privatePreorder(BSTree& tree) {
    SingleLinkedList* traversal = new SingleLinkedList();
    tree.preorder(tree._root, traversal);
    return traversal;
}

SingleLinkedList* BSTreeTest::privateInorder(BSTree& tree) {
    SingleLinkedList* traversal = new SingleLinkedList();
    tree.inorder(tree._root, traversal);
    return traversal;
}

SingleLinkedList* BSTreeTest::privatePostorder(BSTree& tree) {
    SingleLinkedList* traversal = new SingleLinkedList();
    tree.postorder(tree._root, traversal);
    return traversal;
}


bool BSTreeTest::testPrivateCopy(BSTree& dest, BSTree& source) {
	privateInsert(source);
	source.copy(dest, source);
	return (testInsertedNodes(source) && testInsertedNodes(dest));
}

bool BSTreeTest::testPrivateEqual(BSTree& bst1, BSTree& bst2) {
	privateInsert(bst1);
	bst1.copy(bst2, bst1);
	return (bst1.equal(bst1._root, bst2._root) == (testInsertedNodes(bst1) && testInsertedNodes(bst2)));
}

bool BSTreeTest::testPrivateEquivalent(BSTree& bst1, BSTree& bst2) {
	privateInsert(bst1);
	SingleLinkedList* traversal = new SingleLinkedList();
    bst1.inorder(bst1._root, traversal);
	while(traversal->empty()==false) {
		bst2.insert(bst2._root, traversal->front());
		traversal->popFront();
	}
	return ((testInsertedNodes(bst1) != testInsertedNodes(bst2)) && bst1.equivalent(bst1._root, bst2._root));
}




/*
 * Test suite for BinarySearchTree class
 */
BOOST_AUTO_TEST_SUITE(assignment3_test_suite)


bool isEqualElements(const int* array1, const int* array2, const int size) {
	for(int i=0; i<size; i++) {
		if(array1[i] != array2[i]) {
			return false;
		}
	}
	return true;
}



void insertIntoBST(BSTree& tree, const int* array, const int size) {
	for(int i=0; i<size; i++) {
		tree.insert(array[i]);
	}
}



int size = 12;
int treeNodeValues[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9, 14};
int testPreorder[] = {15, 6, 3, 2, 4, 7, 13, 9, 14, 18, 17, 20};
int testInorder[] = {2, 3, 4, 6, 7, 9, 13, 14, 15, 17, 18, 20};
int testPostorder[] = {2, 4, 3, 9, 14, 13, 7, 6, 17, 20, 18, 15 };

BSTree createBST() {
	BSTree tree;
	for(int i=0; i<size; i++) {
		tree.insert(treeNodeValues[i]);
	}
	return tree;
}

/**
 * Test case to test functions of binary search tree.
 */
BOOST_AUTO_TEST_CASE(binary_search_tree) {

	

	BSTree tree;

	BOOST_CHECK_MESSAGE(tree.isEmpty(), "TEST: BinarySearchTree - Empty");


	/*
	 * Testing private insert() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateInsert(tree),
				"TEST: BinarySearchTree - Private Insert");
	BOOST_CHECK_MESSAGE(tree.isEmpty() == false, "TEST: BinarySearchTree - Not empty");

	/*
	 * Testing private search() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateSearch(tree),
						"TEST: BinarySearchTree - Private Search");

	/*
	 * Testing private minimum() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateMinimum(tree),
						"TEST: BinarySearchTree - Private Minimum");

	/*
	 * Testing private maximum() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateMaximum(tree),
						"TEST: BinarySearchTree - Private Maximum");

	
	/*
	 * Testing private successor() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateSuccessor(tree),
						"TEST: BinarySearchTree - Private Successor");
	
	
	/*
	 * Testing private predecessor() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivatePredecessor(tree),
						"TEST: BinarySearchTree - Private Predecessor");
	
	
	/*
	 * Testing private remove() functuon
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateRemove(tree),
						"TEST: BinarySearchTree - Private Remove");


	/*
	 * Testing clear() function
	 */
	tree.clear();
	BOOST_CHECK_MESSAGE(tree.isEmpty(), "TEST: BinarySearchTree - Clear, tree empty");
	BOOST_REQUIRE(BSTreeTest::testPrivateInsert(tree));
	BOOST_REQUIRE(tree.isEmpty() == false);


	/*
	 * Testing private preorder() function
	 */
	SingleLinkedList* traversal = 0;
	traversal = BSTreeTest::privatePreorder(tree);
	BOOST_REQUIRE(traversal != 0);
	const int* traversalArray = traversal->array();
	BOOST_REQUIRE(traversalArray != 0);
	BOOST_CHECK_MESSAGE( traversal->size() == size &&
						isEqualElements(traversalArray, testPreorder, size),
						"TEST: BinarySearchTree - Private Preorder traversal");
	
	/*
	 * Testing private inorder() function
	 */
	delete traversal;
	traversal = 0;
	delete [] traversalArray;
	traversalArray = 0;
	traversal = BSTreeTest::privateInorder(tree);
	BOOST_REQUIRE(traversal != 0);
	traversalArray = traversal->array();
	BOOST_REQUIRE(traversalArray != 0);
	BOOST_CHECK_MESSAGE(traversal->size() == size &&
						isEqualElements(traversalArray, testInorder, size),
						"TEST: BinarySearchTree - Private Inorder traversal");

	
	/*
	 * Testing private postorder() function
	 */
	delete traversal;
	traversal = 0;
	delete [] traversalArray;
	traversalArray = 0;
	traversal = BSTreeTest::privatePostorder(tree);
	BOOST_REQUIRE(traversal != 0);
	traversalArray = traversal->array();
	BOOST_REQUIRE(traversalArray != 0);
	BOOST_CHECK_MESSAGE(traversal->size() == size &&
						isEqualElements(traversalArray, testPostorder, size),
						"TEST: BinarySearchTree - Private Postorder traversal");
	
	delete traversal;
	traversal = 0;
	delete [] traversalArray;
	traversalArray = 0;

	tree.clear();
	BOOST_REQUIRE(tree.isEmpty());


	/*
	 * Testing private copy() function
	 */
	BSTree copy;
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateCopy(copy, tree), "TEST: BinarySearchTree - Private Copy");
	copy.clear();
	tree.clear();


	/*
	 * Testing private equal() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateEqual(tree, copy), "TEST: BinarySearchTree - Private Equal");
	copy.clear();
	tree.clear();

	/*
	 * Testing private equivalent() function
	 */
	BOOST_CHECK_MESSAGE(BSTreeTest::testPrivateEquivalent(tree, copy), "TEST: BinarySearchTree - Private Equivalent");
	copy.clear();
	//tree.clear();

	/*
	 * Testing copy constructor
	 */
	BSTree copyConstructed(tree);
	BOOST_CHECK_MESSAGE(copyConstructed.equal(tree), "TEST: BinarySearchTree - Copy Constructor");
	copyConstructed.clear();

	/*
	 * Testing move constructor
	 */
	BSTree moveConstructed = createBST();
	BOOST_CHECK_MESSAGE(moveConstructed.equal(tree), "TEST: BinarySearchTree - Move Constructor");
	moveConstructed.clear();

	/*
	 * Testing copy assignment
	 */
	BSTree copyAssigned;
	copyAssigned = tree;
	BOOST_CHECK_MESSAGE(copyAssigned.equal(tree), "TEST: BinarySearchTree - Copy Assignment");
	copyAssigned.clear();


	/*
	 * Testing move assignment
	 */
	BSTree moveAssigned;
	moveAssigned = createBST();
	BOOST_CHECK_MESSAGE(moveAssigned.equal(tree), "TEST: BinarySearchTree - Move Assignment");
	moveAssigned.clear();



	/*
	 * Testing insert() function
	 */
	tree.clear();
	BOOST_REQUIRE(tree.isEmpty());
	insertIntoBST(tree, treeNodeValues, size);
	BOOST_REQUIRE(tree.isEmpty() == false);
	BOOST_CHECK_MESSAGE(BSTreeTest::testInsertedNodes(tree),
				"TEST: BinarySearchTree - Insert");
	



	/*
	 * Testing search() function
	 */
	int searchKey = 9;
	const BSTNode* const foundBSTNode = tree.search(searchKey);
	BOOST_CHECK_MESSAGE(foundBSTNode != 0 && foundBSTNode->getKey() == searchKey,
			"TEST: BinarySearchTree - Search existing key");

	searchKey = 22;
	const BSTNode* const notFoundBSTNode =  tree.search(searchKey);
	BOOST_CHECK_MESSAGE(notFoundBSTNode == 0, "TEST: BinarySearchTree - Search non-existing key");


	/*
	 * Testing minumum() function
	 */
	int testMin = 2;
	const int min = tree.minimum();
	BOOST_CHECK_MESSAGE(min == testMin,"TEST: BinarySearchTree - Minimum");
       
	/*
	 * Testing maximum() function
	 */
	int testMax = 20;
	const int max = tree.maximum();
	BOOST_CHECK_MESSAGE(max == testMax, "TEST: BinarySearchTree - Maximum");
       
	
	/*
	 * Testing successor() function
	 */
	int testSuccessor = 17;
	const int succ = tree.successor(15);
	BOOST_CHECK_MESSAGE(succ == testSuccessor, "TEST: BinarySearchTree - Successor");
       
	/*
	 * Testing predecessor() function
	 */
	int testPredecessor = 14;
	const int pred = tree.predecessor(15);
	BOOST_CHECK_MESSAGE(pred == testPredecessor, "TEST: BinarySearchTree - Predecessor");


	/*
	 * Trsting remove() function
	 */
	tree.remove(22);
	BOOST_CHECK_MESSAGE(BSTreeTest::testRemoveNonExistingNode(tree), 
						"TEST: BinarySearchTree - Remove non-existing key");

	tree.remove(4);
	BOOST_CHECK_MESSAGE(BSTreeTest::testRemoveLeafNode(tree), 
				"TEST: BinarySearchTree - Remove leaf node");

	tree.remove(7);
	BOOST_CHECK_MESSAGE(BSTreeTest::testRemoveNonLeafOneChildNode(tree),  
				"TEST: BinarySearchTree - Remove non-leaf one child node");


	tree.remove(18);
	BOOST_CHECK_MESSAGE(BSTreeTest::testRemoveNonLeafTwoChildrenNode(tree), 
				"TEST: BinarySearchTree - Remove non-leaf two children node");

	
	tree.clear();
	BOOST_REQUIRE(tree.isEmpty());

	insertIntoBST(tree, treeNodeValues, size);
	BOOST_REQUIRE(BSTreeTest::testInsertedNodes(tree));
	BOOST_REQUIRE(tree.isEmpty() == false);

	/*
	 * Testing preorder() function
	 */
	const SingleLinkedList* preorderTraversal = tree.preorder();
	BOOST_REQUIRE(preorderTraversal != 0);
	const int* preorderArray = preorderTraversal->array();
	BOOST_REQUIRE(preorderArray != 0);
	
	BOOST_CHECK_MESSAGE(preorderTraversal->size() == size &&
						isEqualElements(preorderArray, testPreorder, size),
						"TEST: BinarySearchTree - Preorder traversal");

	delete preorderTraversal;
	delete [] preorderArray;


	/*
	 * Testing inorder() function
	 */
	const SingleLinkedList* inorderTraversal = tree.inorder();
	BOOST_REQUIRE(inorderTraversal != 0);
	const int* inorderArray = inorderTraversal->array();
	BOOST_REQUIRE(inorderArray != 0);
	BOOST_CHECK_MESSAGE(inorderTraversal->size() == size &&
						isEqualElements(inorderArray, testInorder, size),
						"TEST: BinarySearchTree - Inorder traversal");

	delete inorderTraversal;
	delete [] inorderArray;


	/*
	 * Testing postorder() function
	 */
	const SingleLinkedList* postorderTraversal = tree.postorder();
	BOOST_REQUIRE(postorderTraversal != 0);
	const int* postorderArray = postorderTraversal->array();
	BOOST_REQUIRE(postorderArray != 0);
	BOOST_CHECK_MESSAGE(postorderTraversal->size() == size &&
						isEqualElements(postorderArray, testPostorder, size),
						"TEST: BinarySearchTree - Postorder traversal");

	delete postorderTraversal;
	delete [] postorderArray;

	/*
	 * Testing equal() function
	 */
	BSTree equalTree;
	insertIntoBST(equalTree, treeNodeValues, size);
	BOOST_CHECK_MESSAGE(tree.equal(equalTree), "TEST: BinarySearchTree - Equal");
	
	
	/*
	 * Testing equivalent() function
	 */
	SingleLinkedList* inorderTraversal2 = const_cast<SingleLinkedList*>(tree.inorder());
	BSTree equivalentTree;
	while(inorderTraversal2->empty() == false) {
		equivalentTree.insert(inorderTraversal2->front());
		inorderTraversal2->popFront();
	}
	BOOST_CHECK_MESSAGE(tree.equivalent(equivalentTree) && tree.equal(equivalentTree) == false, 
						"TEST: BinarySearchTree - Equivalent");

	delete inorderTraversal2;
	tree.clear();
	equalTree.clear();
	equivalentTree.clear();


}



BOOST_AUTO_TEST_SUITE_END()


