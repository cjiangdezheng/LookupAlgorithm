// Temp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;


struct index       //定义结构体
{
	int start;
	int key;
	int end;
}index[4];//定义结构体数组，分块查找算法的代价是增加一个辅助的数组存储空间


int search(int key,int a[])
{
	int i=0,j;
	while(i<3&&key>index[i].key)   //通过逐一与每一块中的最大值比较，确定要查找的数在哪一块中
		i++;
	if(i>3)
		return -1;
	j=index[i].start;
	while(j<=index[i].end && a[j]!=key)
		j++;
	if(j>index[i].end)
		j=-1;
	return j;
}

void main()
{
	int i,j=-1,k,key;
	int a[]={42,63,82,89,111,146,219,254,325,336,348,795,876,951,998};
	printf("已经有一组数\n");
	for(i=0;i<15;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	for(i=0;i<3;i++)
	{
		index[i].start=j+1;   //确定每一块范围的起始值
		j=j+1;
		index[i].end=j+4;   //确定每一块的结束值
		j=j+4;
		index[i].key=a[j];  //确定每块范围中元素的最大值
	}
	
	key = 998;
	k=search(key,a);//key为要查找的数，a代表数组
	
	
	if(k>=0)
		printf("你要查找的数%d在数组中的位置是%d\n",key,k);
	else
		printf("查询失败！您要查找的数组不在数组中！");
}
































