#ifndef __BSTREE_INTERNAL_TEST_HEADER__
#define __BSTREE_INTERNAL_TEST_HEADER__

#include "singlelinkedlist.h"
#include "binarysearchtree.h"

class BSTreeTest {
    public:

		static void privateInsert(BSTree& tree);

		static bool testInsertedNodes(const BSTree& tree);

		static bool testPrivateInsert(BSTree& tree);


		static bool testPrivateSearch(BSTree& tree);

		static bool testPrivateMinimum(BSTree& tree);

		static bool testPrivateMaximum(BSTree& tree);

		static bool testPrivateSuccessor(BSTree& tree);

		static bool testPrivatePredecessor(BSTree& tree);

		static bool testPrivateRemove(BSTree& tree);

		static SingleLinkedList* privatePreorder(BSTree& tree);

		static SingleLinkedList* privateInorder(BSTree& tree);

		static SingleLinkedList* privatePostorder(BSTree& tree);

		static bool testPrivateCopy(BSTree& dest, BSTree& source);
        
		static bool testPrivateEqual(BSTree& bst1, BSTree& bst2);
		
		static bool testPrivateEquivalent(BSTree& bst1, BSTree& bst2);

        static bool testRemoveNonExistingNode(const BSTree& tree);

        static bool testRemoveLeafNode(const BSTree& tree); 

        static bool testRemoveNonLeafOneChildNode(const BSTree& tree);
		
        static bool testRemoveNonLeafTwoChildrenNode (const BSTree& tree);
		
};

#endif