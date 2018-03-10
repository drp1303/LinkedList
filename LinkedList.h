#include "Node.cpp"

class LinkedList
{
	Node* head;
	Node* tail;
	int count;
	
	public:
		LinkedList();
		~LinkedList();
		int size();
		bool empty();
		bool insertAtBegining(int ele);
		bool insertAtEnd(int ele);
		bool insertAtPos(int pos,int ele);
		int deleteFromBegining();
		int deleteFromEnd();
		int deleteAtPos(int pos);
		void print();
		void recursivePrint();
		void recursiveReversePrint();
		void iterativeReverse();
		void recursiveReverse();
};
