#include <stdio.h>

void Print(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a,int n)
{
	int end = 0;
	int tmp = a[end + 1];

	while (end >= 0)
	{
		if (tmp < a[end])
		{
			a[end + 1] = a[end];
			--end;
		}
		else
		{
			a[end + 1] = tmp;
		}
	}
}

void Swap(int* x,int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}

	Print(a, n);

}

void AdjustDown(int* a,int n,int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找到最大孩子
		if ((child + 1 < n) && (a[child] < a[child + 1])) ++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}

void HeapSort(int* a, int n, int parent)
{
	//1.建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//2.排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int GetMidi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[right])
	{
		if (a[mid] < a[left]) return left;
		else if (a[right] > a[mid]) return mid;
		else return right;
	}
	else
	{
		if (a[mid] < a[right]) return right;
		else if (a[mid] > a[left]) return left;
		else return mid;
	}
}
void QuickSort(int* a,int left,int right)
{
	if (left >= right) return;

	int midi = GetMidi(a, left, right);
	Swap(&a[midi], &a[left]);

	int keyi = left;
	int begin = left, end = right;

	while (begin < end)
	{
		//右边找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		//左边找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);

	//[left,begin-1] begin [begin+1,end]
	QuickSort(a, left, begin - 1);
	QuickSort(a, begin+1, right);
}


void Test_QuickSort()
{
	int arr[] = { 2,5,3,8,9,3,8,0,1,7 };
	Print(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	Print(arr, sizeof(arr) / sizeof(arr[0]));
}


int main()
{
	int arr[] = { 2,5,3,8,9,3,8,0,1,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//InsertSort(arr, sz);
	//BubbleSort(arr, sz);
	Test_QuickSort(arr, 0, sz - 1);
	return 0;
}