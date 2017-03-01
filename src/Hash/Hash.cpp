// Hash.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
#include <iostream>

using namespace std;

////������ʽ��f(key)=key mod p (p<=m)mΪ��ϣ��������
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define UNSUCCESS 0

#define HASHSIZE 17 /* ����ɢ�б���Ϊ����ĳ��� */
#define NULLKEY -32768 


typedef struct
{
    int *elem; /* ����Ԫ�ش洢��ַ����̬�������� */
    int count; /*  ��ǰ����Ԫ�ظ��� */
}HashTable;

int m=0; /* ɢ�б�������ȫ�ֱ��� */

/*��ʼ��*/
int Init(HashTable *hashTable)
{
    int i;

    m=HASHSIZE;
    hashTable->elem= (int *)malloc(m*sizeof(int)); //�����ڴ�
    hashTable->count=m;
    for (i=0;i<m;i++)
    {
        hashTable->elem[i]=NULLKEY;
    }
    return OK;
}


int Hash(int data)
{
    return data%m;
}

/*����*/
void Insert(HashTable *hashTable,int data)
{
    int hashAddress=Hash(data); //���ϣ��ַ

    //������ͻ
    while(hashTable->elem[hashAddress]!=NULLKEY)
    {
        //���ÿ��Ŷ�ַ������̽�ⷨ�����ͻ
        hashAddress=(++hashAddress)%m;
    }

    //����ֵ
    hashTable->elem[hashAddress]=data;
}

/*����*/
int Search(HashTable *hashTable,int data)
{
    int hashAddress=Hash(data); //���ϣ��ַ

    //������ͻ
    while(hashTable->elem[hashAddress]!=data)
    {
        //���ÿ��Ŷ�ַ������̽�ⷨ�����ͻ
        hashAddress=(++hashAddress)%m;

        if (hashTable->elem[hashAddress]==NULLKEY||hashAddress==Hash(data)) 
			return -1;
    }

    //���ҳɹ�
    return hashAddress;
}

/*��ӡ���*/
void Display(HashTable *hashTable)
{
    int i;
    printf("\n**********չʾ���**********\n");
    for (i=0;i<hashTable->count;i++)
    {
        printf("%d ",hashTable->elem[i]);
    }
    printf("\n**********չʾ���**********\n");
}

int main()
{
    int i,j,result;
    HashTable hashTable;
    int arr[HASHSIZE]={13,29,27,28,26,30,38};

    printf("***************��ϣ����(C���԰�)***************\n");

    //��ʼ����ϣ��
    Init(&hashTable);

    //��������
    for (i=0;i<HASHSIZE;i++)
    {
        Insert(&hashTable,arr[i]);
    }
    Display(&hashTable);


    //��������
    result= Search(&hashTable,60);
    if (result==-1) 
		printf("û���ҵ���");
    else 
		printf("29�ڹ�ϣ���е�λ����:%d",result);

    getchar();

	return 0;
}