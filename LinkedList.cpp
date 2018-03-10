#include "LinkedList.h"
#include<iostream>
using namespace std;
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

LinkedList::~LinkedList()
{
	cout<<"\nInside dtor";
	Node* temp = NULL;
	while(head!=NULL)
	{
		temp = head;
		head = temp->getNext();
		delete temp;
	}
}

int LinkedList::size()
{
	return count;
}

bool LinkedList::empty()
{
	return (NULL==head && NULL==tail);
}

bool LinkedList::insertAtBegining(int ele)
{
	bool bsuccess = false;
	Node* temp = new Node();
	temp->setData(ele);
	if(empty())
	{
		temp->setNext(NULL);
		head = temp;
		tail = temp;
		count++;
		bsuccess = true;
	}
	else
	{
		temp->setNext(head);
		head = temp;
		count++;
		bsuccess = true;
	}
	return bsuccess;
}

bool LinkedList::insertAtEnd(int ele)
{
	bool bsuccess = false;
	Node* temp = new Node();
	temp->setData(ele);
	if(empty())
	{
		temp->setNext(NULL);
		head = temp;
		tail = temp;
		count++;
		bsuccess = true;
	}
	else
	{
		temp->setNext(NULL);
		tail->setNext(temp);
		tail = temp;
		count++;
		bsuccess = true;
	}
	return bsuccess;
 } 
 
 bool LinkedList::insertAtPos(int pos,int ele)
 {
 	bool bsuccess = false;
 	Node* temp = new Node();
 	temp->setData(ele);
 	if(pos==1)
 	{
 		bsuccess = insertAtBegining(ele);
	 }
	 else
	 {
	 	Node* temp2 = head;
	 	for(int i=0;i<pos-2;i++)
	 	{
	 		temp2 = temp2->getNext();
		 }
		 temp->setNext(temp2->getNext());
		 temp2->setNext(temp);
		 count++;
		 bsuccess = true;
	 }
	 return bsuccess;
 }
 
 void LinkedList::print()
 {
 	if(empty())
 	{
 		cout<<"Linked list is empty";
 		return;
	 }
	 else
	 {
	 	Node* temp = head;
	 	cout<<"\nLinked list content :";
	 	while(temp!=NULL)
	 	{
	 		cout<<temp->getData()<<"--->";
	 		temp = temp->getNext();
		 }
	 }
	 cout<<"NULL";
 }
 
 int LinkedList::deleteFromBegining()
 {
 	int data;
 	if(!empty())
 	{
 		data = head->getData();
 		Node* temp = head;
 		if(head == tail)
 		{
 			head = NULL;
 			tail = NULL;
 			count--;
 			delete temp;
		 }
		 else
		 {
		 	data = head->getData();
		 	head= head->getNext();
		 	delete temp;
		 	count--;
		 }
	 }
	 return data;
 }
 int LinkedList::deleteFromEnd()
 {
 	int data;
 	if(!empty())
 	{
 		data = tail->getData();
 		Node* temp = tail;
 		if(head == tail)
 		{
 			head = NULL;
 			tail = NULL;
 			count--;
 			delete temp;
		 }
		 else
		 {
		 	 Node *t = head;
	 		while(t->getNext() != tail) 
	 		{
 	   			t = t->getNext();
	 		}
			data=tail->getData();
         	t->setNext(NULL);
			delete tail;
         	count--;
			tail = t;
		 }
	 }
	 return data;
 	
 }
 
 int LinkedList::deleteAtPos(int pos)
 {
 	int data;
 	if(!empty())
 	{
 		Node* temp = head;
 		if(pos == 1)
 		{
 			data = deleteFromBegining();
		 }
		 else
		 {
		 	
		 	for(int i=0; i< pos-2;i++)
		 	{
		 		temp = temp->getNext();
			 }
			 Node *temp2 = temp->getNext();
			 temp->setNext(temp2->getNext());
			 data = temp2->getData();
			 delete temp2;
			 count--;
		 }
	 }
	 return data;
 }
 void LinkedList::iterativeReverse()
 {
 	bool bSuccess = false;
  if(!empty())
  {
	Node *nhead = head,*t=NULL;
	head = head->getNext();
	nhead->setNext(NULL);
	tail = nhead;
	
	while(head != NULL)
	{
	   t= head;
	   head = head->getNext();
	   t->setNext(nhead);
	   nhead =t;
    }
        head = nhead;
	bSuccess = true;
  }
 }
