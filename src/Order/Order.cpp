// Temp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;
int Order(int a[],int len,int key)
{
	for(int i = 0;i < len; i++)
	{
		if (key == a[i])
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	
	int length = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	int ret = Order(a,length,10);
	
	cout << "location is :" << ret << endl;
	
	cout << endl;
    return 0;
}
































/*

int InsertionSearch(int a[], int value, int low, int high)
{
    int mid = low+(value-a[low])/(a[high]-a[low])*(high-low);
    if(a[mid]==value)
        return mid;
    if(a[mid]>value)
        return InsertionSearch(a, value, low, mid-1);
    if(a[mid]<value)
        return InsertionSearch(a, value, mid+1, high);
}*/