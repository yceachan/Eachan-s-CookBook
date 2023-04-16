class pair{
  public:
  pair(int r,int c);
  int r,c;
};

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
	void push(int r,int c);
	pair front();
  void pop();
};
