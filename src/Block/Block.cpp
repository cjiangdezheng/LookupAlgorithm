// Temp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;


struct index       //����ṹ��
{
	int start;
	int key;
	int end;
}index[4];//����ṹ�����飬�ֿ�����㷨�Ĵ���������һ������������洢�ռ�


int search(int key,int a[])
{
	int i=0,j;
	while(i<3&&key>index[i].key)   //ͨ����һ��ÿһ���е����ֵ�Ƚϣ�ȷ��Ҫ���ҵ�������һ����
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
	printf("�Ѿ���һ����\n");
	for(i=0;i<15;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	for(i=0;i<3;i++)
	{
		index[i].start=j+1;   //ȷ��ÿһ�鷶Χ����ʼֵ
		j=j+1;
		index[i].end=j+4;   //ȷ��ÿһ��Ľ���ֵ
		j=j+4;
		index[i].key=a[j];  //ȷ��ÿ�鷶Χ��Ԫ�ص����ֵ
	}
	
	key = 998;
	k=search(key,a);//keyΪҪ���ҵ�����a��������
	
	
	if(k>=0)
		printf("��Ҫ���ҵ���%d�������е�λ����%d\n",key,k);
	else
		printf("��ѯʧ�ܣ���Ҫ���ҵ����鲻�������У�");
}
































