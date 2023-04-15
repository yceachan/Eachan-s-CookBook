#include<iostream>
using namespace std;
//创建大顶堆并实现堆排序
class HeapSTL {
public:
	int* array;
	int size;
	int capacity;
	HeapSTL(int n=0);
	//用一份数组建堆，设计两种建堆模式——1.自顶向下，2。自底向上
	void package(int* arr,int len,int mode);
	//插入元素时数组扩容——new一个double长度的arr以装下新的一层，需要深拷贝一份元素组
	int* newarr(int* oldarr);
	//尾插，需扩容,然后上滤到合适位置
	void push_back(int data);
	//弹出树顶元素
	int pop();

	//上下滤
	//经排查，上滤操作中由错误的索引swap了自身
	void heapifyUp(int pos);
	void heapifyDown(int pos);

	//父子节点索引的返回
	int GetLChildIndex(int parent_index);
	int GetRChildIndex(int parent_index);
	int GetParentIndex(int child_index);
	//三个边界判断flag
	bool hasleftchild(int parent_index);
	bool hasrightchild(int parent_index);
	//无论是左右子节点，-1 整除2，均得到了父节点
	bool hasparent(int chlid_index);
};
HeapSTL::HeapSTL(int n)
{
	this->capacity = n;
	this->size = 0;
	this->array = new int[n];
}

inline void HeapSTL::package(int* arr, int len, int mode)
{
	this->size = len;
	this->capacity = len;
	if (mode)
	{
		for (int i = 0; i < len; i++) this->push_back(arr[i]);

	}
	else
	{
		//先储存，从n-1最后一个元素开始，一直--——逆序层次遍历父节点，对每个父节点进行下滤操作
		for (int i = 0; i < len; i++) this->array[i] = arr[i];
		for (int i = len - 1; i >= 0; i--)
		{
			this->heapifyDown(i);
		}
	}
	delete[]arr;
}

int* HeapSTL::newarr(int* oldarr)
{
	int* deepcopy = new int[capacity * 2]{0};
	for (int i = 0; i < this->size; i++) deepcopy[i] = oldarr[i];
	delete[] oldarr;
	return deepcopy;
}

void HeapSTL::push_back(int data)
{
	if (this->size == this->capacity)
	{
		this->array = newarr(this->array);
		this->capacity *= 2;
	}
	this->array[size++] = data;
	this->heapifyUp(size-1);
	
}

int HeapSTL::pop()
{
	int elem = this->array[0];
	this->array[0] = this->array[size - 1];
	//delete &this->array[size - 1];先不delete
	size--;
	heapifyDown(0);
	return elem;
}

void HeapSTL::heapifyUp(int pos)
{
	while (hasparent(pos))
	{
		if (this->array[pos] > this->array[GetParentIndex(pos)])
		{
			swap(array[pos],array[GetParentIndex(pos)]);
			pos = GetParentIndex(pos);
		}
		else break;
	}
}

void HeapSTL::heapifyDown(int pos)
{
	while (hasleftchild(pos))
	{
		//因为父节点需要大于所有子节点，所以要找到子节点中较大的那个，对pos与它进行下滤操作
		int a = this->array[GetLChildIndex(pos)], b = this->array[GetRChildIndex(pos)];
		int child = (a > b) ?     GetLChildIndex(pos) : GetRChildIndex(pos);
		if (this->array[pos] < this->array[child])
		{
			swap(this->array[pos], this->array[child]);
			pos = child;
		}
		else break;
	}
}

int HeapSTL::GetLChildIndex(int parent_index)
{
	return parent_index*2 +1;
}

int HeapSTL::GetRChildIndex(int parent_index)
{
	return parent_index * 2 + 2;
}

int HeapSTL::GetParentIndex(int child_index)
{
	return (child_index -1) /2;
}

bool HeapSTL::hasleftchild(int parent_index)
{
	return (parent_index * 2) + 1 < this->size;
}

bool HeapSTL::hasrightchild(int parent_index)
{
	return (parent_index * 2) + 2 < this->size;
}

bool HeapSTL::hasparent(int child_index)
{
	return (child_index - 1) / 2 >=0;
}
