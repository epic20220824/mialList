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
//初始化线性表
void init(sqList*& sq);
//读取文件里面的数据
bool initSq(sqList*& sq);
//保存数据
void storeData(sqList* sq);


//菜单
void menu();
//用户选择
void selectMenu(sqList*& sq);
//1.添加通讯录信息
void addInfo(sqList*& sq);

//2.查询通讯录信息
void findInfo(sqList* sq);
//2.1按姓名查找
void findNameInfo(sqList* sq);
//2.2按通信地址查找
void findAddressInfo(sqList* sq);
//2.3 按电话号码查找
void findNumberInfo(sqList* sq);
//2.4 按邮编查找
void findMailInfo(sqList* sq);
//2.5 给名字相同的按电话号码排序
void arr_sort(sqList* sq, int* a, int n);


//3 删除通讯录信息
void deldetInfo(sqList* &sq);
//4 修改通讯录信息
void changeInfo(sqList*& sq);
//5 显示通讯录信息
void disInfo(sqList* sq);