/*
* 设有一个双向循环链表，每个结点中除有prior、data、next三个域外，还增设一个访问频度freq。
* 在链表启用之前，频度域freq值均为0，每次对链表进行查询后LOCATE(L，x)后，频度值增1，并调整链表，使其更靠近表头。
* Environment: MSVC sln Project,c++20
* Author:衣陈
* date：20230319
* README：泛型双向链表，实现push，insert，pop，print方法。
*/
#include<iostream>
template<typename T>
class node {
public:
	node() :data(0), freq(0), prev(0), nxt(0) {}
	
	node(T data,int freq=0) :data(data), freq(freq), prev(0), nxt(0) {}
	T data;
	int freq;
	node* prev;
	node* nxt;
};

template<typename T>
class List {
public:
	List() {
		head = new node<T>;
		tail = new node<T>;
		head->prev = tail;
		head->nxt = tail;
		tail->prev = head;
		tail->nxt = head;
	}
	void push_back(T data) {
		node<T>* elem = new node<T>(data);
		elem->nxt = tail;
		elem->prev = tail->prev;
		tail->prev->nxt = elem;
		tail->prev = elem;
	}

	void insert(node<T>* pos,node<T>* elem) {
		elem->prev = pos;
		elem->nxt = pos->nxt;
		pos->nxt->prev = elem;
		pos->nxt = elem;
	}
	void pop(node<T>* elem) {
		elem->prev->nxt = elem->nxt;
		elem->nxt->prev = elem->prev;
		delete elem;
		elem = 0;

	}
	void Locate(T x) {
		for (node<T>* it = head->nxt; it != tail; it = it->nxt) {
			if (it->data == x) {
				it->freq++;

				it->prev->nxt = it->nxt;
				it->nxt->prev = it->prev;
				
				node<T>* mey = it->prev;
				for (node<T>* jt = head; jt->nxt != it; jt = jt->nxt) {
					if (jt->nxt->freq < it->freq ) {
						insert(jt, it);
						break;
					}
				}
				
			}
		}
	}
	void ptf(){
		for (node<T>* it = head->nxt; it != tail; it = it->nxt) {
			printf("(v:%d,f:%d)->", it->data, it->freq);
		}
		std::cout << "\n\n";
	}
	~List() {
		while (head->nxt != tail) pop(head->nxt);
		delete head;
		delete tail;
		//不置空
	}
private:
	node<T>* head;//不用写T，可自动内联，但成员方法的定义就不行了，useless
	node<T>* tail;


};

int main()
{
	List<int> mylist;

	for (int i = 1; i <= 9; i++) mylist.push_back(i);
	mylist.ptf();

	//实验结果：每个被locate的node freq++，并到插入到lowwer_bound(node->data)处
	for (int i = 9; i >= 1; i--) {
		mylist.Locate(i);
		mylist.ptf();
	}
	//mylist.~List(); // 析构并没有写错，但显式调用析构后，main进程结束后又会执行一次析构
	return 0;//此断点步进后，若显式调用析构，此断点步入后，发生pop野指针问题。



}