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
	//������������arr,�ֱ�����Զ����½������Ե����Ͻ���
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
		//Ϊ����ʹ�������a�ı������������������Ƕ�a��package����Ϊ���һ��aȻ��delete��a ������������O��N���Ŀռ临�Ӷȣ������ֱ�Ӱ�a�ĵ�ַί�и���Ա������̫�á�
		//delete������д�����ָ��ָ�����ݵ��ڴ棬�Լ����������ʶ����ռ���ڴ棬����ε�ַ��д������ݱ�����Ϊ��-572662307 == 0xDDDDDDDD���������ʶ�������Ĳ��ٿ��á���������ڴ����ǿ��Ա�����ָ��ָ���
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
//�Ե����Ͻ�����On��������������η��ʸ������ڵ�
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