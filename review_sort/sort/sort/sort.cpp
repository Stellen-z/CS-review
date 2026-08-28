#include <iostream>
#include <stack>
#include <vector>

using namespace std;



void InsertSort(int* a,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//单趟
		int end = i;
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
				break;
			}
		}
		//处理循环结束 + 合适位置
		a[end + 1] = tmp;
	}	
}

void TestInsertSort()
{
	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

void ShellSort(int* a, int n)
{
	//预排序+插入排序
	//int gap = n;
	//while (gap > 1)
	//{
	//	gap = gap / 3 + 1;
	//	for (int j = 0; j < gap; j++)
	//	{
	//		for (int i = j; i < n - gap; i += gap)
	//		{
	//			//单趟
	//			int end = i;
	//			int tmp = a[end + gap];
	//			while (end >= 0)
	//			{
	//				if (tmp < a[end])
	//				{
	//					a[end + gap] = a[end];
	//					end -= gap;
	//				}
	//				else break;
	//			}
	//			a[end + gap] = tmp;
	//		}
	//	}
	//}

	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			//单趟
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else break;
			}
			a[end + gap] = tmp;
		}

	}
}

void TestShellSort()
{
	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

void SelectSort(int*a ,int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		//找到未排序序列中最小和最大的元素
		int maxi = left, mini = right;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] > a[maxi]) maxi = i;
			if (a[i] < a[mini]) mini = i;
		}
		swap(a[left], a[mini]);
		if (left == maxi) maxi = mini;
		swap(a[right], a[maxi]);
		++left;
		--right;
	}

}

void TestSelectSort()
{
	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

	void AdjustDown(int* a,int n,int parent)
	{
		int child = parent * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n && a[child + 1] > a[child]) ++child;
			if (a[parent] < a[child])
			{
				swap(a[parent], a[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else break;
		}
	}

	void HeapSort(int* a,int n)
	{
		//建堆
		for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		{
			AdjustDown(a, n, i);
		}

		//排序
		int end = n - 1;
		while (end >= 0)
		{
			swap(a[0], a[end]);
			AdjustDown(a, end, 0);
			--end;
		}

}

void TestHeapSort()
{
	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

void BubbleSort(int* a,int n)
{
	//for (int j = 0; j < n - 1; j++)
	//{
	//	//单趟
	//	for (int i = 0; i < n - j - 1; i++)
	//	{
	//		if (a[i] > a[i + 1])
	//		{
	//			swap(a[i], a[i + 1]);
	//		}
	//	}
	//}

	for (int j = 1; j <= n - 1; j++)
	{
		//单趟
		for (int i = 0; i < n - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
			}
		}
	}

}

void TestBubbleSort()
{
	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

int GetMid(int* a,int left,int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[right])
	{
		if (a[mid] < a[left]) return left;
		else if (a[right] < a[mid]) return right;
		else return mid;
	}
	else
	{
		if (a[mid] > a[left]) return left;
		else if (a[right] > a[mid]) return right;
		else return mid;
	}
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;

	//三数取中
	int keyi = GetMid(a,left,right);
	swap(a[keyi], a[left]);

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
		swap(a[begin], a[end]);
	}
	swap(a[keyi], a[begin]);

	//[left,begin - 1] begin [begin + 1,right]
	QuickSort(a, left, begin - 1);
	QuickSort(a, begin + 1, right);

}

void TestQuickSort()
{

	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, n - 1);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

int PartSort(int* a,int left,int right)
{
	int keyi = GetMid(a, left, right);
	swap(a[keyi], a[left]);

	int begin = left, end = right;

	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi]) --end;
		while (begin < end && a[begin] <= a[keyi]) ++begin;

		swap(a[begin], a[end]);
	}
	swap(a[keyi], a[begin]);

	return begin;
}

void QuickSortNonR(int* a,int left,int right)
{
	stack<int> st;

	st.push(right);
	st.push(left);

	while (!st.empty())
	{
		int begin = st.top(); st.pop();
		int end = st.top(); st.pop();

		//划分区间
		
		int keyi = PartSort(a, begin, end);

		//[begin,keyi - 1] keyi [keyi + 1,end]

		if (end - keyi > 1)
		{
			st.push(end);
			st.push(keyi + 1);
		}

		if (keyi - begin > 1)
		{
			st.push(keyi - 1);
			st.push(begin);
		}
	}
	
}

void TestQuickSortNonR()
{
	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a, 0, n - 1);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

void _MergeSort(int* a, vector<int>& tmp, int left, int right)
{
	if (left >= right) return;

	int mid = (left + right) / 2;
	//[left,mid] [mid + 1,right]

	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int cur = left;
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2]) tmp[cur++] = a[begin1++];
		else tmp[cur++] = a[begin2++];
	}

	while (begin1 <= end1) tmp[cur++] = a[begin1++];
	while (begin2 <= end2) tmp[cur++] = a[begin2++];

	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a,int n)
{
	//辅助数组
	vector<int> tmp(n);

	int left = 0, right = n - 1;
	_MergeSort(a, tmp, left, right);
}

void TestMergeSort()
{
	int a[] = { 2,5,8,3,0,7,6,1,4,9 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a, n);

	for (auto e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

void MergeSortNonR(int* a, int n)
{
	vector<int> tmp(n);
	
	//gap为归并的一组数据个数
	int gap = 1;
	while (gap < n)
	{
		//每次跳过这两组,i表示每次归并的起始位置
		for (int i = 0; i < n; i += 2 * gap)
		{
			int cur = i;
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			//如果end1越界，那么begin2也越界，此时就直接break
			//如果end1没越界，那就不管;只需判断begin2即可

			//第二组全部越界，第一组已经有序
			if (begin2 >= n) break;

			//此时begin2没越界，那么end1也没越界，那就只有end2可能越界
			//第二组end2越界，修正即可
			if (end2 >= n) end2 = n - 1;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2]) tmp[cur++] = a[begin1++];
				else tmp[cur++] = a[begin2++];
			}

			while (begin1 <= end1) tmp[cur++] = a[begin1++];
			while (begin2 <= end2) tmp[cur++] = a[begin2++];

			//归并一组，拷贝一组
			//如果整体拷贝，遇到越界就会把原有元素覆盖
			for (int j = i; j <= end2; j++)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}

	
}
void TestMergeSortNonR()
{

}



int main()
{
	//TestInsertSort();
	//TestShellSort();

	//TestSelectSort();

	//TestHeapSort();

	//TestBubbleSort();

	//TestQuickSort();
	//TestQuickSortNonR();

	TestMergeSort();




	return 0;;
}