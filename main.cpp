#include "LinkedList.cpp"
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	LinkedList obj;
	obj.insertAtBegining(1);
	obj.insertAtBegining(2);
	obj.insertAtBegining(3);
	obj.insertAtEnd(4);
	obj.insertAtPos(3,5);
	obj.print();
	cout<<"\nDeleted from begining : "<<"Number is ="<<obj.deleteFromBegining();
	obj.print();
	cout<<"\nDeleted from end : "<<"Number is ="<<obj.deleteFromEnd();
	obj.print();
	cout<<"\n Delete at position 3 "<<" Number is ="<<obj.deleteAtPos(1);
	obj.print();
	cout<<"\n Iterative reverse of Linked list :";obj.iterativeReverse();
	obj.print();
	cout<<"\nsize ="<<obj.size();
}
