/**
 * @file binarysearchtree.cpp
 * @author Luka Karanovic, 665778833, S24N02, CSCI 161, VIU
 * @version 1.0.0
 * @date March 9, 2024
 *
 * Implements the functions of BinarySearchTree class defined in binarysearchtree.h header file.
 *
 */
 
#include <iostream>
#include <fstream>

#include "binarysearchtree.h"
#include "singlelinkedlist.h"

/** @brief Inserts a new node with a given value into the binary search tree
 *
 *  Dynamically creates a new node and assigns it's key to the value passed.
 *  The new node will always be a leaf node inserted in the correct position.
 *
 *  @param root The address of the root node of the subtree.
 *  @param key The value assigned to the node being added.
 *  @return Void.
 */

void BSTree::insert(BSTNode*& root, const int key) {
    if (root == nullptr) {
        BSTNode* node = new BSTNode(key);
        root = node; 
    } else if (key < root->key) {
        insert(root->left, key);
    } else if (key > root->key) {
        insert(root->right, key);
    } 
}

/** @brief Searches for and returns a node with the target key in the binary search tree
 *
 *  @param root The address of the root node of the subtree.
 *  @param key The value of the node being searched for.
 *  @return The address of the node with value key.
 */

BSTNode* BSTree::search(BSTNode* root, int key) const {
    if (root == nullptr) {
        return nullptr;
    } else if (root->key == key) {
        return root;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

/** @brief Searches for and returns a node with the smallest key value.
 *
 *  @param root The address of the root node of the subtree.
 *  @return The address of the node with the smallest value key.
 */

BSTNode* BSTree::minimum(BSTNode* root) const {
    if(root == nullptr || root->left == nullptr) {
        return root;
    }
    return minimum(root->left);
}

/** @brief Searches for and returns a node with the largest key value.
 *
 *  @param root The address of the root node of the subtree.
 *  @return The address of the node with the largest value key.
 */

BSTNode* BSTree::maximum(BSTNode* root) const {
    if(root == nullptr || root->right == nullptr) {
        return root;
    }
    return maximum(root->right);
}

/** @brief Searches for and returns the smallest value node in the right subtree.
 *
 *  @param root The address of the root node of the subtree.
 *  @return The successor node of the parameter node.
 */

BSTNode* BSTree::successor(BSTNode* root) const {
    if (root == nullptr || root->right == nullptr) {
        return nullptr;
    }
    return minimum(root->right);
}

/** @brief Searches for and returns the largest value node in the left subtree.
 *
 *  @param root The address of the root node of the subtree.
 *  @return The predecessor node of the parameter node.
 */

BSTNode* BSTree::predecessor(BSTNode* root) const {
    if (root == nullptr || root->left == nullptr) {
        return nullptr;
    }
    return maximum(root->left);
}

/** @brief Deletes a node with a given value from the binary search tree.
 *
 *  If the tree is empty, the function will terminate. If the target node has one child node,
 *  it will be replaced with its successor node. If the target node is a leaf node, it will be 
 *  removed.
 *
 *  @param root The address of the root node of the subtree.
 *  @param key The target value of the node being deleted.
 *  @return Void.
 */

void BSTree::remove(BSTNode*& root, const int key) {
    if (root == nullptr) {
        return;
    }
    if (key < root->key) {
        remove(root->left, key);
    } else if (key > root->key) {
        remove(root->right, key);
    } else {
        if (root->left != nullptr && root->right != nullptr) {
            root->key = successor(root)->key;
            remove(root->right, root->key);
        } else {
            BSTNode* temp = root;
            root = (root->left != nullptr) ? root->left : root->right;
            delete temp;
        }
    }
}

/** @brief Traverses the binary search tree with the preorder traversal.
 *
 *  Creates a single linked list ordering the nodes in the preorder way. 
 *  In preorder, the root node is first, then the left subtree, then the
 *  right subtree.
 *
 *  @param root The address of the root node of the subtree.
 *  @param traversal The single linked list containing the order of traversal.
 *  @return Void.
 */

void BSTree::preorder(BSTNode* root, SingleLinkedList* traversal) const {
    if (root == nullptr) {
        return;
    }
    traversal->pushBack(root->key);
    preorder(root->left, traversal);
    preorder(root->right, traversal);
}

/** @brief Traverses the binary search tree with the inorder traversal.
 *
 *  Creates a single linked list ordering the nodes in the inorder way. 
 *  In inorder, the nodes are listed from least to greatest in terms of key values.
 *
 *  @param root The address of the root node of the subtree.
 *  @param traversal The single linked list containing the order of traversal.
 *  @return Void.
 */

void BSTree::inorder(BSTNode* root, SingleLinkedList* traversal) const {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, traversal);
    traversal->pushBack(root->key);
    inorder(root->right, traversal);
}

/** @brief Traverses the binary search tree with the postorder traversal.
 *
 *  Creates a single linked list ordering the nodes in the postorder way. 
 *  In postorder, the left subtree is first, then the right subtree, then
 *  the root node.
 *
 *  @param root The address of the root node of the subtree.
 *  @param traversal The single linked list containing the order of traversal.
 *  @return Void.
 */

void BSTree::postorder(BSTNode* root, SingleLinkedList* traversal) const {
    if (root == nullptr) {
        return;
    }
    postorder(root->left, traversal);
    postorder(root->right, traversal);
    traversal->pushBack(root->key);
}

/** @brief Copies the nodes and structure of a source BST to a destination BST.
 *
 *  The destination linked list is cleared. Then, the source BST is traversed and
 *  copied into the sourceData linked list. This linked list is used to create the
 *  destination BST.
 *
 *  @param destination The address of the destination binary search tree data structure.
 *  @param source The address of the source binary search tree data structure.
 *  @return Void.
 */

void BSTree::copy(BSTree& destination, const BSTree& source) {
    destination.clear();
    if (source._root == nullptr) {
        return;
    }
    SingleLinkedList* sourceData = new SingleLinkedList;
    preorder(source._root, sourceData);
    while (!sourceData->empty()) {
        insert(destination._root, sourceData->front());
        sourceData->popFront();
    }
    sourceData->clear();
}

/** @brief Compares two binary search trees or subtrees to see if they are equal.
 *
 *  For two binary search trees to be equal, they must have the same nodes with the 
 *  same values in the same structure. Both root nodes are compared, then left subtrees,
 *  then right subtrees.
 *
 *  @param bst1 The address of the root node of the first subtree being compared.
 *  @param bst2 The address of the root node of the second subtree being compared.
 *  @return True if the BSTs are equal, false if they are not.
 */

bool BSTree::equal(BSTNode* bst1, BSTNode* bst2) const {
    if (bst1 == nullptr && bst2 == nullptr) {
        return true;
    } else if (bst1 == nullptr || bst2 == nullptr) {
        return false;
    } else if (bst1->left != nullptr && bst2->left != nullptr) {
        if (bst1->key != bst2->key) {
            return false;
        } else {
            equal(bst1->left, bst2->left);
        }
    } else if (bst1->right != nullptr && bst2->right != nullptr) {
        if (bst1->key != bst2->key) {
            return false;
        } else {
            equal(bst1->right, bst2->right);
        }
    }
    return true;
}

/** @brief Compares two binary search trees or subtrees to see if they contain nodes 
 *         with the same key values.
 *
 *  For two binary search trees to be equivalent, they must have the same node values. 
 *  If one tree has a node value that another tree doesn't have, they are not equivalent.
 *
 *  @param bst1 The address of the root node of the first subtree being compared.
 *  @param bst2 The address of the root node of the second subtree being compared.
 *  @return True if the BSTs are equivalent, false if they are not.
 */

bool BSTree::equivalent(BSTNode* bst1, BSTNode* bst2) const {
    if (bst1 == nullptr && bst2 == nullptr) {
        return true;
    } else if (bst1 == nullptr || bst2 == nullptr) {
        return false;
    } else {
        SingleLinkedList* bst1list = new SingleLinkedList;
        SingleLinkedList* bst2list = new SingleLinkedList;
        inorder(bst1, bst1list);
        inorder(bst2, bst2list);
        return bst1list->equal(*bst2list);
        delete bst1list;
        delete bst2list;
    }

}

/** @brief Default Constructor
 *
*/

BSTree::BSTree(): _root(0) {}

/** @brief Regular Constructor 
 * 
 *  @param root The pointer to the root node of the BST.
*/

BSTree::BSTree(BSTNode* root): _root(root) {}

/** @brief Destructor. Clears every new node from the binary search tree.
 * 
*/

BSTree::~BSTree() {
    clear();
}

/** @brief Copy constructor. Deep copies from another binary search tree.
 *
 *  Clears the newly constructed BST's pointers, ensuring it is empty before copying.
 *  Copies node values in the same structure from a source BST to the newly
 *  created BST. The two BSTs should be equal after the copy.
 *
 *  @param copy The source binary search tree data structure.   
 */

BSTree::BSTree(const BSTree& copy) {
    this->_root = nullptr;
    this->copy(*this, copy);
}

/** @brief Move constructor. Shallow copies from another binary search tree.
 *
 *  Copies an R-value BST's root node pointer, assigning it a new name.
 *
 *  @param temp An R-value BST data structure containing the root node pointer.
 */

BSTree::BSTree(BSTree&& temp): _root(temp._root) {}


/** @brief Copy assignment. Deep copies from another binary search tree.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Clears the newly constructed BST, ensuring it is empty before copying.
 *  Copies node values in the same structure from a source BST to the newly
 *  created BST. The two BSTs should be equal after the copy.
 *
 *  @param other The source binary search tree data structure.  
 *  @return The updated version of the binary search tree. 
 */

BSTree& BSTree::operator = (const BSTree& other) {
    if (this == &other) {
        return *this;
    }
    this->clear();
    copy(*this, other);
    return *this;
}

/** @brief Move assignmnt. Shallow copies from binary search tree.
 *
 *  Overloads the assignment (=) operator so that it does the following:
 *  Copies an R-value BST's root node pointer, assigning it a new name.
 *  Ensures the temporary R-value BST is empty after assignment.
 *
 *  @param temp An R-value BST data structure containing the root node pointer.
 *  @return The updated version of the binary search tree
 */

BSTree& BSTree::operator = (BSTree&& temp) {
    if (this == &temp) {
        return *this;
    }
    this->clear();
    _root = temp._root;
    temp._root = nullptr;
    return *this;
}

/** @brief Checks if the binary search tree is empty or not. Returns true if empty
 *         and false if not empty.
 *
 *  If the root node pointer is null, the tree is empty. Otherwise, there are existing
 *  nodes in the tree, therefore the tree is not empty.
 *
 *  @return The boolean value stating whether the tree is empty or not.
 */

bool BSTree::isEmpty() const {
    return _root == nullptr;
}

/** @brief Inserts a new node with a given value into the binary search tree
 *
 *  Dynamically creates a new node and assigns it's key to the value passed.
 *  The new node will always be a leaf node inserted in the correct position.
 *
 *  @param key The value assigned to the node being added.
 *  @return Void.
 */

void BSTree::insert(const int key) {
    insert(_root, key);
}

/** @brief Searches for and returns a node with the target key in the binary search tree
 *
 *  @param key The value of the node being searched for.
 *  @return The address of the node with value key.
 */

const BSTNode* const BSTree::search(int key) const {
    return search(_root, key);
}

/** @brief Searches for and returns the smallest key value in the tree.
 *
 *  @return The smallest value key. If the tree is empty, will return -1.
 */

const int BSTree::minimum() const {
    BSTNode* result = minimum(_root);
    if (result == nullptr) {
        return -1;
    } else {
        return result->key;
    }
}

/** @brief Searches for and returns the largest key value in the tree.
 *
 *  @return The largest value key. If the tree is empty, will return -1.
 */

const int BSTree::maximum() const {
    BSTNode* result = maximum(_root);
    if (result == nullptr) {
        return -1;
    } else {
        return result->key;
    }
}

/** @brief Searches for and returns the smallest value node in the right subtree.
 *
 *  @param key The key value of the root node of the subtree.
 *  @return The key value of the successor node of the parameter node. 
 *          If the tree is empty, will return -1.
 */

const int BSTree::successor(const int key) const {
    BSTNode* node = search(_root, key);
    node = successor(node);
    if (node == nullptr) {
        return -1;
    } else {
        return node->key;
    }
}

/** @brief Searches for and returns the largest value node in the left subtree.
 *
 *  @param key The key value of the root node of the subtree.
 *  @return The key value of the predecessor node of the parameter node. 
 *          If the tree is empty, will return -1.
 */

const int BSTree::predecessor(const int key) const {
    BSTNode* node = search(_root, key);
    node = predecessor(node);
    if (node == nullptr) {
        return -1;
    } else {
        return node->key;
    }
}

/** @brief Deletes a node with a given value from the binary search tree.
 *
 *  If the tree is empty, the function will terminate. If the target node has one child node,
 *  it will be replaced with its successor node. If the target node is a leaf node, it will be 
 *  removed.
 *
 *  @param key The target value of the node being deleted.
 *  @return Void.
 */

void BSTree::remove(const int key) {
    remove(_root, key);
}

/** @brief Traverses the binary search tree with the preorder traversal.
 *
 *  Creates a single linked list ordering the nodes in the preorder way. 
 *  In preorder, the root node is first, then the left subtree, then the
 *  right subtree.
 *
 *  @return The single linked list containing the order of traversal.
 */

const SingleLinkedList* BSTree::preorder() const {
    if (isEmpty()) {
        return NULL;
    } else {
        SingleLinkedList* preorderTraversal = new SingleLinkedList;
        preorder(_root, preorderTraversal);
        return preorderTraversal;
    }
}

/** @brief Traverses the binary search tree with the inorder traversal.
 *
 *  Creates a single linked list ordering the nodes in the inorder way. 
 *  In inorder, the nodes are listed from least to greatest in terms of key values.
 *
 *  @return The single linked list containing the order of traversal.
 */

const SingleLinkedList* BSTree::inorder() const {
    if (isEmpty()) {
        return NULL;
    } else {
        SingleLinkedList* inorderTraversal = new SingleLinkedList;
        inorder(_root, inorderTraversal);
        return inorderTraversal;
    }
}

/** @brief Traverses the binary search tree with the postorder traversal.
 *
 *  Creates a single linked list ordering the nodes in the postorder way. 
 *  In postorder, the left subtree is first, then the right subtree, then
 *  the root node.
 *
 *  @return The single linked list containing the order of traversal.
 */

const SingleLinkedList* BSTree::postorder() const {
    if (isEmpty()) {
        return NULL;
    } else {
        SingleLinkedList* postorderTraversal = new SingleLinkedList;
        postorder(_root, postorderTraversal);
        return postorderTraversal;
    }
}

/** @brief Clears the binary search tree of all of it's nodes.
 * 
 *  @return Void.
 */

void BSTree::clear() {
    while (!isEmpty()) {
        remove(_root, _root->key);
    }
}

/** @brief Compares two binary search trees or subtrees to see if they are equal.
 *
 *  For two binary search trees to be equal, they must have the same nodes with the 
 *  same values in the same structure. Both root nodes are compared, then left subtrees,
 *  then right subtrees.
 *
 *  @param other The address of the other binary search tree being compared.
 *  @return True if the BSTs are equal, false if they are not.
 */

bool BSTree::equal(const BSTree& other) const {
    return equal(_root, other._root);
}

/** @brief Compares two binary search trees or subtrees to see if they contain nodes 
 *         with the same key values.
 *
 *  For two binary search trees to be equivalent, they must have the same node values. 
 *  If one tree has a node value that another tree doesn't have, they are not equivalent.
 *
 *  @param other The address of the other binary search tree being compared.
 *  @return True if the BSTs are equivalent, false if they are not.
 */

bool BSTree::equivalent(const BSTree& other) const {
    return equivalent(_root, other._root);
}