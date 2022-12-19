#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string>
#include<io.h>
#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
	char name[MAXSIZE];
	char address[MAXSIZE];
	char postal[MAXSIZE];
	char number[MAXSIZE];
}mail;
typedef struct
{
	mail data[MAXSIZE];
	int number;
}sqList;
//��ʼ�����Ա�
void init(sqList*& sq);
//��ȡ�ļ����������
bool initSq(sqList*& sq);
//��������
void storeData(sqList* sq);


//�˵�
void menu();
//�û�ѡ��
void selectMenu(sqList*& sq);
//1.���ͨѶ¼��Ϣ
void addInfo(sqList*& sq);

//2.��ѯͨѶ¼��Ϣ
void findInfo(sqList* sq);
//2.1����������
void findNameInfo(sqList* sq);
//2.2��ͨ�ŵ�ַ����
void findAddressInfo(sqList* sq);
//2.3 ���绰�������
void findNumberInfo(sqList* sq);
//2.4 ���ʱ����
void findMailInfo(sqList* sq);
//2.5 ��������ͬ�İ��绰��������
void arr_sort(sqList* sq, int* a, int n);


//3 ɾ��ͨѶ¼��Ϣ
void deldetInfo(sqList* &sq);
//4 �޸�ͨѶ¼��Ϣ
void changeInfo(sqList*& sq);
//5 ��ʾͨѶ¼��Ϣ
void disInfo(sqList* sq);