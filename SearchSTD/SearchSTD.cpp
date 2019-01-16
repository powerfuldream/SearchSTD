// SearchSTD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int BinarySearch(vector<int> &arr, int key, int low, int high);
bool InsertSort(vector<int> &arr);
bool ShellSort(vector<int> &arr);
void BubbleSort(vector<int > &a);
void BinaryInsertSort(vector<int> &a);
void Selection_Sort(vector<int> &a);
void QuickSort(vector<int> &a,int low,int high);
void QuickSortNor(vector<int> &a, int low, int high);
int Partition(vector<int>&a, int left, int right);
int main()
{
	vector<int> arr = { 2,5,4,7,9,3,6,8,7,1,0 ,10};
	for (auto i : arr)
		cout << i << endl;
	//InsertSort(arr);
	cout << "QuickSort:\n";
	QuickSortNor(arr, 0, arr.size()-1);
	for (auto i : arr)
		cout << i << endl;
	int key;
	cout << "search a key:";
	cin >> key;
	if (BinarySearch(arr, key, 0, arr.size() - 1))
	cout << "yes\n";

	else
		cout << "not in arr\n";
	return 0;
}

int BinarySearch(vector<int> & arr, int key, int low, int high)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == arr[mid])
			return mid;
		else if (key < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

bool InsertSort(vector<int> &arr)
{
	cout << "InsertSort:\n";
	if (arr.empty())
		return false;

	int lengh = arr.size();
	int temp,j;
	for (int i = 1; i <lengh; ++i)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
	return true;
}

bool ShellSort(vector<int> &arr)
{
	cout << "ShellSort:\n";
	int length = arr.size();
	int incratement=length;
	int temp, s;
	do 
	{
		incratement = incratement/3 + 1;
		for (int j = incratement; j < length; j++)
		{
			temp = arr[j];
			s = j - incratement;
			while (s >= 0 &&temp < arr[s])
			{
				arr[s + incratement] = arr[s];
				s -= incratement;
			}
			arr[s + incratement] = temp;
		}
		
	} while (incratement>1);
		
	
	return true;
}

void BubbleSort(vector<int> &a) {
	int n=a.size();
	int temp;
	bool exchange= false;
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;++j)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				exchange= true;
			}
		}
		if(!exchange)
			return;;
	}
}

void BinaryInsertSort(vector<int> &a)
{
    int n=a.size();
    int j,temp,low,high,mid;
    for(int i=1;i<n;++i)
    {
        if(a[i]<a[i-1])
        {
            temp=a[i];
            high=i-1;
            low=0;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(temp<a[mid])
                    high=mid-1;
                else
                    low=mid+1;

            }
            for(j=i-1;j>=low;--j )
            {
                a[j+1]=a[j];
            }
            a[low]=temp;
        }

    }
}

void Selection_Sort(vector<int> &a)
{
	int n=a.size();
	int min,k,temp;
	for(int i=0;i<n;++i)
	{
		min=a[i];
		for(int j=i+1;j<n;++j)
		{
			if(a[j]<min)
			{
				min=a[j];
				k=j;
			}

		}
		if(min!=a[i])
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
}


void QuickSort(vector<int> &a,int low,int high)
{
	if (low >=high)
		return;
	int key=a[low];
	int i = low, j = high;
	while (i < j)
	{
		while (i < j&&key <= a[j])
			--j;
		if(i<j)
		a[i++] = a[j];

		while (i <j&&key >= a[i])
			++i;
		if(i<j)
		a[j++] = a[i];
	}
	a[i] = key;

	QuickSort(a, low, i - 1);
	QuickSort(a, i + 1, high);
}

int Partition(vector<int>&a, int left, int right)
{
	int key = a[left];
	int frist = left, last = right;
	while (frist < right)
	{
		while (frist < right&&key <= a[right])
			--right;
		if (frist < right)
			a[frist] = a[right];

		while (frist < right&&key >= a[frist])
			++frist;
		if (frist < right)
			a[right] = a[frist];
	}
	a[frist] = key;
	return frist;
}

void QuickSortNor(vector<int> &a, int low, int high)
{
	if (low >= high)
		return;

	stack<int> p;
	p.push(low);
	p.push(high);
	int left, right,boundle;
	while (!p.empty())
	{
		right = p.top();
		p.pop();
		left = p.top();
		p.pop();
		if (left < right)
		{
			boundle = Partition(a, left, right);

			p.push(left);
			p.push(boundle-1);

			p.push(boundle + 1);
			p.push(right);
		}
		

	}
}