// Temp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;
int BiSearch(int a[],int len,int key)
{
	int low,high,mid;
	low = 0;
	high = len-1;
	int ret = -1;
	while (low <= high)
	{
		//mid = low + (high - low)/2;
		mid = low + ( (key-a[low])/(a[high]-a[low]) )*(high - low);
		if(a[mid]>key)
			high = mid - 1;
		else if(a[mid]<key)
			low = mid + 1;
		else 
			return mid;
	}
	return ret;

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
	
	int ret = BiSearch(a,length,11);
	
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