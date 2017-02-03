// SortAlgorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

void CreateList(int a[], int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
}

void PrintfList(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i-1])
		{
			int x = a[i];
			int j = i-1;
			a[i] = a[i - 1];
			while (0 < j && x < a[j-1])
			{
				a[j] = a[j-1];
				j--;
			}
			a[j] = x;
		}
	}
}

void ShellInsertSort(int a[], int n, int dk)
{
	for (int i = dk; i < n; i++)
	{
		if (a[i] < a[i - dk])
		{
			int x = a[i];
			int j = i - dk*2;
			a[i] = a[i - dk];
			while (0 <= j && x < a[j])
			{
				a[j+dk] = a[j];
				j-=dk;
			}
			a[j+dk] = x;
		}
	}
}
//ϣ������
void ShellSort(int a[], int n)
{
	int dk = n / 2;
	while (dk >= 1)
	{
		ShellInsertSort(a, n, dk);
		dk = dk / 2;
	}
}

//��i��ʼѡ����С��ֵ���
int SelectMinKey(int a[], int n, int i)
{
	for (int j = i + 1; j < n; j++)
	{
		if (a[i] > a[j])
		{
			i = j;
		}
	}
	return i;
}
//ѡ������
void SelectSort(int a[], int n)
{
	int key, tmp;
	for (int i = 0; i < n; i++)
	{
		key = SelectMinKey(a, n, i);
		if (key != i)
		{
			tmp = a[i];
			a[i] = a[key];
			a[key] = tmp;
		}
	}
}

//����s������
void HeapAdjust(int H[], int s, int length)
{
	int tmp = H[s];
	int child = 2 * s + 1;
	while (child < length)
	{
		if (child +1 < length && H[child]<H[child+1])
		{
			++child;
		}
		if (H[s] < H[child])
		{
			//����ϴ���ӽ����ڸ����
			//��ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
			//��������s ,������������һ������λ��
			H[s] = H[child];
			s = child;
			child = 2 * s + 1;
		}
		else
		{
			break;
		}
		H[s] = tmp;
	}
}

void BuildHeap(int H[], int length)
{
	for (int i = (length - 1) / 2; i >= 0; --i)
	{
		HeapAdjust(H, i, length);
	}
}
//������
void HeapSort(int H[], int length)
{
	BuildHeap(H, length);
	for (int i = length - 1; i > 0; --i)
	{
		//�����Ѷ�Ԫ��H[0]�Ͷ������һ��Ԫ��  
		int tmp = H[i];
		H[i] = H[0];
		H[0] = tmp;
		//ÿ�ν����Ѷ�Ԫ�غͶ������һ��Ԫ��֮�󣬶�Ҫ�Զѽ��е���
		HeapAdjust(H, 0, i);
	}
}
//ð������
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j] < a[j - 1])
			{
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}

int partition(int a[], int low, int high)
{
	int privot = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= privot)
		{
			--high;
		}
		//swap
		{
			int tmp = a[low];
			a[low] = a[high];
			a[high] = tmp;
		}

		while (low < high && a[low] <= privot)
		{
			++low;
		}
		//swap
		{
			int tmp = a[low];
			a[low] = a[high];
			a[high] = tmp;
		}
	}

	return low;
}
//��������
void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int privot = partition(a, low, high);
		QuickSort(a, low, privot - 1);
		QuickSort(a, privot + 1, high);
	}
}

void merge(int a[], int first, int mid, int last, int tmp[])
{
	int i = first, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= last)
	{
		if (a[i]<=a[j])
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[j++];
		}
	}

	while (i <= mid)
	{
		tmp[k++] = a[i++];
	}

	while (j <= last)
	{
		tmp[k++] = a[j++];
	}

	memcpy(&a[first], tmp, sizeof(int)*k);
}

void mergesort(int a[], int first, int last, int tmp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, tmp);
		mergesort(a, mid + 1, last, tmp);
		merge(a, first, mid, last, tmp);
	}
}

void MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
	{
		return;
	}

	mergesort(a, 0, n - 1, p);
	delete[]p;
}

int main()
{
	int iList[18] = { 0 };
	CreateList(iList, 18);
	PrintfList(iList, 18);
	//InsertSort(iList, 18);
	//ShellSort(iList, 18);
	//SelectSort(iList, 18);
	//HeapSort(iList, 18);
	//BubbleSort(iList, 18);
	//QuickSort(iList, 0, 17);
	MergeSort(iList, 18);
	PrintfList(iList, 18);
	system("pause");
    return 0;
}

