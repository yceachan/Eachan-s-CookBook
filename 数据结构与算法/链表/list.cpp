//1、	已知A、B、C为3个递增有序的线性表，现要求对A表进行如下操作：删去那些既属于B，又属于C的元素。试对单链表编写算法，并且同一表中的元素值各不相同。
//链表中元素可以比较，如int、float、char

#include<map>
#include<iostream>
template<typename T>
class node
{public:
	T data;
	node* nxt;
	node() : nxt(nullptr) {}
	node(T data) :data(data), nxt(nullptr) {}
};

//在仅有头结点的情况下：删去A链表中BC的交集  故写空间复杂度on的算法
template<typename T>
node<T>* rmmult(node<T>* A, node<T>* B, node<T>* C)
{
	node<T>* ans = A;
	std::map<T, bool> bvis, cvis;
	while (B!=nullptr)
    {
		bvis[B->data] = 1;
		B = B->nxt;
	}
	while (C != nullptr)
	{
		cvis[C->data] = 1;
		C = C->nxt;
	}
	while (A->nxt != nullptr)  //与从链表中pop某一节点，需要获得它的前驱指针
	{
		if (bvis[A->nxt->data] && cvis[A->nxt->data]) {

			node<T>* tmp = A->nxt->nxt;
			delete A->nxt;
			A->nxt = tmp;
		}
		else A = A->nxt;
	}
	return ans;
}

template<typename T>
class List {
public:
	List() {
		head = new node<T>;
		tail = head;
	}
	node<T>* head;
	node<T>* tail;
	void push(T data) {
		node<T>* elem = new node<T>(data);
		tail->nxt = elem;
		tail = elem;
	}
	void ptf() {
		for (auto it = head->nxt; it; it = it->nxt) std::cout << it->data << " ";
		std::cout << "\n\n";
	}
};

void test() {
	List<int> a, b, c;
	for (int i = 1; i <= 9; i++) a.push(i);
	for (int i = 3; i <= 6; i++) b.push(i);
	for (int i = 5; i <= 7; i++) c.push(i);
	a.ptf();
	b.ptf();
	c.ptf();
	rmmult(a.head, b.head->nxt, c.head->nxt);
	a.ptf();
}
int main()
{
	test();
	return 0;
}