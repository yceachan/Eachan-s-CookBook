#include<iostream>
using namespace std;
//�����󶥶Ѳ�ʵ�ֶ�����
class HeapSTL {
public:
	int* array;
	int size;
	int capacity;
	HeapSTL(int n=0);
	//��һ�����齨�ѣ�������ֽ���ģʽ����1.�Զ����£�2���Ե�����
	void package(int* arr,int len,int mode);
	//����Ԫ��ʱ�������ݡ���newһ��double���ȵ�arr��װ���µ�һ�㣬��Ҫ���һ��Ԫ����
	int* newarr(int* oldarr);
	//β�壬������,Ȼ�����˵�����λ��
	void push_back(int data);
	//��������Ԫ��
	int pop();

	//������
	//���Ų飬���˲������ɴ��������swap������
	void heapifyUp(int pos);
	void heapifyDown(int pos);

	//���ӽڵ������ķ���
	int GetLChildIndex(int parent_index);
	int GetRChildIndex(int parent_index);
	int GetParentIndex(int child_index);
	//�����߽��ж�flag
	bool hasleftchild(int parent_index);
	bool hasrightchild(int parent_index);
	//�����������ӽڵ㣬-1 ����2�����õ��˸��ڵ�
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
		//�ȴ��棬��n-1���һ��Ԫ�ؿ�ʼ��һֱ--���������α������ڵ㣬��ÿ�����ڵ�������˲���
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
	//delete &this->array[size - 1];�Ȳ�delete
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
		//��Ϊ���ڵ���Ҫ���������ӽڵ㣬����Ҫ�ҵ��ӽڵ��нϴ���Ǹ�����pos�����������˲���
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
