#include<iostream>
#include<stdio.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
};
Node* head;
Node* insert(Node* head,int data){
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
	return head;
	
}
void insertAtN(Node* head,int data,int pos)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if(pos==1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for(int i=0; i<pos-2;i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void deleteFromBegning()
{
	Node* temp = head;
	if(head==NULL)
	{
		cout<<"LinkedList is empty";
		return;
	}
	head=temp->next;
	delete temp;
}
void deleteFromNth(int n)
{
	Node* temp1 = head;
	if(n==1) deleteFromBegning();
	for(int i=0 ; i< n-2; i++)
	{
		temp1 = temp1->next;
	}	
	Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete temp2;
}
void print(Node* head)
{
	Node* temp = head;
	while(temp!= NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;		
	}	
	cout<<"\n";
}
void reverse()
{
	Node *current,*prev,*next;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

int main()
{
	head = NULL;
	cout<<"How many number you want to enter \n";
	int n,i,x;
	cin>>n;
	for(int i=0; i<n;i++)
	{
		cout<<"Enter a number :\n";
		cin>>x;
		head = insert(head,x);
		print(head);
	}
	cout<<"Insert at Nth position function testing ";
	cout<<"Enter the number";
	int data;
	cin>>data;
	cout<<"Enter the postiton";
	int pos;
	cin>>pos;
	insertAtN(head,data,pos);
	print(head);
	deleteFromBegning();
	print(head);
	deleteFromNth(3);
	print(head);
	cout<<"Reversing linkedList :";
	reverse();
	cout<<"Reversed(iterative): ";
	print(head);
	return 0;
	
}
