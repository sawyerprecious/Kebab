#include "linkedlist.h"

// Copies a provided list.
// - parameters: ll - the list to be copied.
void LinkedList::copyList(const LinkedList& ll){
	if (ll.front == NULL)
	{
		length = 0;
		front = NULL;
		back = NULL;
	}else{
		for (Node* curr = ll.front; curr != NULL; curr->next)
		{
			this->insertBack(curr->data);
		}
	}
}

// deletes the list.
void LinkedList::deleteList(){
	Node* curr = front;
	while (curr != NULL)
	{
		Node* curr2 = curr->next;
		delete curr;
		curr = curr2;
	}
	front = NULL;
}

// creates an empty list.
LinkedList::LinkedList(){
	length = 0;
	front = NULL;
	back = NULL;
}

// Copy constructor.
// - parameters: ll - list to be copied.
LinkedList::LinkedList(const LinkedList& ll){
	copyList(ll);
}

// Destructor for the list.
LinkedList::~LinkedList(){
	this->deleteList();
}

// Inserts an item at the front of the list.
// - parameters: item - the item to be put at the front of the list.
void LinkedList::insertFront(Kebab* item){
	Node* newNode = new Node(item);
	Node* prevFirst = front;
	newNode->next = prevFirst;
	length = length + 1;
	front = newNode;
	if (length == 1)
	{
		back = newNode;
	}
}

// Inserts an item at the back of the list.
// - parameters: item - the item to be inserted.
void LinkedList::insertBack(Kebab* item){

	Node* newNode = new Node(item);
	length = length + 1;
	if (length == 1)
	{
		front = newNode;
		back = newNode;
	}else{
		Node* prevLast = back;
		prevLast->next = newNode;
		back = newNode;
	}

}

// Inserts an item at a specified position in the list.
// - parameters: item - the item to be inserted.
//					p - the position to insert item at
bool LinkedList::insertAt(Kebab* item, unsigned int p){
	if (p < length)
	{
		length = length +1;
		if (p == 0)
		{
			Node* prevFirst = front;
			Node* toBeInserted = new Node(item);
			toBeInserted->next = prevFirst;
			front = toBeInserted;
			if (length == 1)
			{
				back = toBeInserted;
			}
			return true;
		}else{
			Node* temp = front;
			int i = 1;
			while (p != i){
				i = i+1;
				temp = temp->next;
			}

			Node* toBeInserted = new Node(item);
			Node* oneAfter = temp->next;
			temp->next = toBeInserted;
			toBeInserted->next = oneAfter;
			if (oneAfter == NULL)
			{
				back = toBeInserted;
			}
			return true;
		}
	}else{
		return false;
	}
}

// Removes a member of the list at a desired position.
// - parameters: p - the position of the item to be removed.
Kebab* LinkedList::removeAt(unsigned int p){
	if (length > p)
	{
		if (length == 1 && p == 0)
		{
			Node* removal = front;
			length = 0;
			front = NULL;
			back = NULL;
			return removal->data;
		}
		if (p == 0)
		{
			Node* getRidOf = front;
			length = length - 1;
			front = getRidOf->next;
			return getRidOf->data;
		}else{
			length = length - 1;
			int i = 0;

    		Node* temp = front;

    		while (p != i+1) {
    			i = i+1;
        		temp = temp->next;
    		}

    		Node* removeThis = temp->next;

    		Node* oneAfter = removeThis->next;

    		temp->next = oneAfter;

    		return removeThis->data;
    	}
    }else{
		return NULL;
	}
}

// Getter for length.
unsigned int LinkedList::size() const{
	return length;
}

// Returns true if list is empty, false otherwise.
bool LinkedList::isEmpty() const{
	if (length == 0)
	{
		return true;
	}else{
		return false;
	}
}

// Returns true if k has the same data as an item in the list
// - parameters: k - the kebab to be compared with list items.
bool LinkedList::contains(Kebab& k) const{
	Node* currNode = front;
	for (int i = 0; i < length; ++i)
	{
		if (currNode->data->hasSameIngredients(k))
		{
			return true;
		}else{
			currNode = currNode->next;
		}
	}
	return false;
}

// Returns a pointer to the item at a specified position.
// - parameters: p - the position of an item to return a pointer to
Kebab* LinkedList::elementAt(unsigned int p) const{
	Node* currNode = front;
	if (length > p)
	{
		Kebab* tempK = new Kebab();
		Node *temp = new Node(tempK);
		int i = 0;

    	temp = front;

    	while (p != i) {
    		i = i+1;
        	temp = temp->next;
    	}

    	return temp->data;
	}else{
		return NULL;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& ll){

	if (this == &ll)
	{
		return *this;
	}else{

	}
	return *this;
}