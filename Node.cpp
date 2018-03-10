#include "Node.h"
void Node::setData(int data)
{
	this->data = data;
}

int Node::getData()
{
	return data;
}

void Node::setNext(Node* temp)
{
	next = temp;
}

Node* Node::getNext()
{
	return next;
}
