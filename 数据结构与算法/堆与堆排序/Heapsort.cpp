/*
    VS2022
*/
#include"HeapSTL.hpp"
void up2down();
void down2up();
void heapsay();
#include<Windows.h>
int main()
{
	//给定乱序数组arr,分别设计自顶向下建堆与自底向上建堆
	cout << "Up2Down Bulit heap:\n\n";
	up2down();
	system("pause");
	system("cls");
	cout << "Down2Up Bulit heap:\n\n";
	Sleep(500);	
	down2up();
	system("pause");
}

void up2down()
{
	srand(time(NULL));
	int n = 20;
	for (int x = 0; x < 5; x++)
	{
		int* a = new int[n];
		HeapSTL heap(n);
		for (int j = 0; j < n; j++)
		{
			a[j] = rand() % 100;
		}
		cout << " Test_arr:\n  ";
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		//为避免使用类外的a改变类内数组的情况，我们对a的package方法为深拷贝一份a然后delete掉a 这样是申请了O（N）的空间复杂度，大可以直接把a的地址委托给成员，但不太好。
		//delete：回收写入这个指针指向数据的内存，以及回收这个标识符所占的内存，即这段地址后写入的数据被重置为（-572662307 == 0xDDDDDDDD），这个标识符在下文不再可用——而这段内存仍是可以被其他指针指向的
		heap.package(a, n, 1);
		cout<<"\nI have free `arr` in class,which point to the same & with `a`,so a is:\n";
		for (int i = 0; i < n; i++) cout << a[i] << " ";


		for (int i = 0; i < n; i++) a[i] = heap.pop();
		cout << "\nBut `a` is still alvie and those memories are still acessible";
		cout << "\n Heap_sortarr:\n  ";
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl<<endl;
	//	delete[] a;
	}
}
//自底向上建堆是On，核心问题是如何访问各个父节点
void down2up()
{
	srand(time(NULL));
	int n = 20;
	for (int x = 0; x < 5; x++)
	{
		int* a = new int[n];
		HeapSTL heap(n);
		for (int j = 0; j < n; j++)
		{
			a[j] = rand() % 100;
		}
		cout << " test_arr:\n  ";
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		
		heap.package(a, n, 0);
		
		cout << "\n heap_sortarr:\n  ";
		for (int i = 0; i < n; i++) a[i] = heap.pop();
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl << endl;
	//	delete[] a;
	}
}

void heapsay() {

	
}