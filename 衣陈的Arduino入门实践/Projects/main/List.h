#ifndef LIST
#define LIST
class List {
public:
	class node {
	public:
		node(int r=-1,int c=-1);
		int r,c;
		node* prev;
		node* next;
	};

	node* head;
	node* tail;
	int size;
	List();
	void push(int r,int c);//后端入队
	node* front();//查看队首
  void pop();//前端出队
  bool empty();
  void clear();
};
extern List buffer;
#endif