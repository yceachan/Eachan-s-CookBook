#include "List.h"
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
  head->prev=tail;
  tail->next=head;
	size = 0;
}
bool List::empty()
{
  return head->next==tail;
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

List::node* List::front()
{
	return this->head->next;
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
void List::clear()
{
   while(!empty()) pop();
   size=0;
}