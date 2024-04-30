/**
 * @file singlelinkedlist.h
 * @author Humayun Kabir, Instructor, CSCI 161, VIU
 * @version 1.0.0
 * @date July 14, 2020
 *
 * SingleLinkedList class definition.
 *
 */



#ifndef __SINGLE_LINKED_LIST_HEADER__
#define __SINGLE_LINKED_LIST_HEADER__

/*
 * SingleLinkedListNode class definition
 * SingleLinkedListNode objects are being used to build a single linked list.
 */
class SingleLinkedListNode {
	private:
		int _data;									//Data of the node
		SingleLinkedListNode* _next;					//Pointer to the next node
	public:
		SingleLinkedListNode(int data, SingleLinkedListNode* next):		//Constructor 
			_data(data), _next(next) {}

		~SingleLinkedListNode() {}					//Destructor
		
		const int getData() const { return _data;}
		
		friend class SingleLinkedList;
		friend class SingleLinkedListTest;
};


/*
 * SingleLinkedList class definition
 */
class SingleLinkedList {
	private:
		
		SingleLinkedListNode* _front; 	//Front of the list
		SingleLinkedListNode* _back;
		int _size; 		    	//Keeps track current size of the list			
		
		SingleLinkedListNode* previousNode(const int value);
		//Iterate through the list starting from list front.
		//Return the pointer of a node from the list whose next node has the value equal to 'value'.
		//Return NULL if the front node value is equal to 'value' or
		//no node in the list has value equal to 'value'.
		
		void deepCopy(const SingleLinkedList& other);
		//Copy all the nodes from source to the destination.


	public:
		SingleLinkedList(); // Default Constructor
		//Create an empty list with its front pointing to NULL.


		~SingleLinkedList(); // Destructor
		//Remove all the nodes from the linked list and release memory from them.


		SingleLinkedList(const SingleLinkedList&); //Copy Constructor
		//Copy all the nodes from the given linked list into a new linked list

		SingleLinkedList(SingleLinkedList&&);	//Move Constructor
		//Assign all the nodes of the temporary linked list to the new linked list

		SingleLinkedList& operator = (const SingleLinkedList&); //Copy Assignment
		//Copy all the nodes from the right side linked list into left side linked list

		SingleLinkedList& operator = (SingleLinkedList&&);	//Move Assignment
		//Assign all the nodes from the temporary linked list to left side linked list.

		
		int size() const;
		//Return current size of the list.


		bool empty() const;
		//Return true, if the list is empty.
		//Return false, otherwise.

		
		void show() const;
		//Loop through the list and print the data on the same line sperated by sapces.

		
		void pushFront(const int data);
		//Insert the 'data' at the beginning of the list.


		void pushBack(const int data);
		//Insert the 'data' at the end of the list.



		bool insert(const int before, const int data);
		//Loop through the list to find a node whose data is equal to parameter 'before'.
		//If no such node is found, do nothing.
		//Otherwise, create a new node using 'data' and insert the new node before the
		//found node.
		
		
		
		SingleLinkedListNode* search(const int data) const;
		//Loop through the list and campare the data of each node with parameter 'data'
		//If a node matches, return it.
		//Otherwise, return NULL.
		
	
		const int front() const;
		//Return data from the front node of the list, if the list is not empty.
		//Return -1, if the list is empty.


		const int back() const;
		//Return data from the last node of the list, if the list is not empty.
		//Return -1, if the list is empty.


		void popFront();
		//Remove a node fromt the beginning of the list and release memory from the removed node.


		void popBack();
		//Remove a node from the end of the list and release memory from the removed node.
				
		
		void remove(const int data);
		//Search the list to find a node whose data is equal to parameter 'data'
		//Do nothing if no such node is found.
		//Otherwise, remove the macthed node from the list and release its memory.
		
		
		void clear();
		//Remove all data from the list and release memory from all nodes.


		const int* array() const;
		//Return an array of integers copying the data from all the nodes of the list.
		//Start from the front node and end at the back node.


		bool equal(const SingleLinkedList& other) const;
		//Return true if 'other' linked list has same size
		//and each node in this list has matching
		//data of the corresponding node in 'other' list.
		//Return false, otherwise.


		void load(const char* fileName);
		//Open the file named 'filename' in read only mode.
		//Read the data from the file and insert them at the end of the list.
		//Close the file after all data have been inserted.


		void save(const char* fileName);
		//Open the file named 'filename' in write only mode.
		//Write the data from the linked list into the file on a single line and separated by spaces.


		friend class SingleLinkedListTest;


};


#endif

