// SearchSTD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int BinarySearch(vector<int> &arr, int key, int low, int high);
bool InsertSort(vector<int> &arr);
bool ShellSort(vector<int> &arr);
void BubbleSort(vector<int > &a);
void BinaryInsertSort(vector<int> &a);
void Selection_Sort(vector<int> &a);
int main()
{
	vector<int> arr = { 929,505,209,109,41,19,5,1,0 };
	for (auto i : arr)
		cout << i << endl;
	//InsertSort(arr);
	ShellSort(arr);
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
