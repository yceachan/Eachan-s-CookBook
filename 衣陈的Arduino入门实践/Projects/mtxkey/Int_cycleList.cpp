#include "Int_cycleList.h"
pair::pair(int r , int c)
{
  this->r=r;
  this->c=c;
}
List::node::node(int r,int c)
{
	this->r = r;
	this->c = c;
	this->next = 0;
	this->prev = 0;
}

List::List()
{
	head = new node;
	tail = new node;
	head->next = tail;
	tail->prev = head;
	size = 0;
}

void List::push(int r,int c)
{
  for(node* pos=head->next;pos!=tail;pos=pos->next)
  {
    if(r==pos->r && c==pos->c) return;
  }
	node* elem = new node(r,c);
	tail->prev->next = elem;
	elem->prev = tail->prev;
	elem->next = tail;
	tail->prev = elem;
	size++;
}

pair List::front()
{
	node* pos = head->next;
  int r=pos->r,c=pos->c;
  return pair(r,c);
}
void List::pop()
{
  node* pos = head->next;
  pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	pos = 0;
	size--;
}


