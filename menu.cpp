#include"menu.h"

//初始化线性表
void init(sqList*& sq)
{
	sq = (sqList*)malloc(sizeof(sqList));
	sq->number = -1;
}
//读取文件里面的数据
bool initSq(sqList*& sq)
{
	init(sq);
	char name[MAXSIZE];
	char address[MAXSIZE];
	int postal;
	char number[MAXSIZE];
	FILE* pfile;
	if ((pfile = fopen("info.txt", "r")) == NULL)
	{
		printf("文件不存在，请检查文件格式是否正确");
		return false;
	}
	else
	{
		int i;
		for (i = 0; i < 100 && !feof(pfile); i++)
		{
			fscanf(pfile, "%s %s %s %s\n", sq->data[i].address, sq->data[i].name, sq->data[i].number, sq->data[i].postal);
		}
		sq->number = i;
		fclose(pfile);
		return true;
	}
}
//保存数据
void storeData(sqList* sq)
{
	FILE* fp = fopen("info.txt", "w");
	for (int i = 0; i < sq->number; i++)
	{
		fprintf(fp,"%s %s %s %s", sq->data[i].address, sq->data[i].name,  sq->data[i].number, sq->data[i].postal);
		fprintf(fp, "%c", '\n');
	}
	fclose(fp);
}

//菜单
void menu()
{
	printf("*************************\n");
	printf("*** 1.添加通讯录信息 ****\n");
	printf("*** 2.查询通讯录信息 ****\n");
	printf("*** 3.删除通讯录信息 ****\n");
	printf("*** 4.修改通讯录信息 ****\n");
	printf("*** 5.显示通讯录信息 ****\n");
	printf("*** 6.退出程序       ****\n");
	printf("*************************\n");
}
//用户选择
void selectMenu(sqList*& sq)
{
	while (true)
	{
		menu();
		int sw;
		//getchar();
		scanf_s("%d", &sw);
		while (sw > 6 && sw < 1)
		{
			printf("请选择正确的选项");
			getchar();
			scanf_s("%d", &sw);
		}
		switch (sw)
		{
		case 1:
			addInfo(sq);
			break;
		case 2:
			findInfo(sq);
			break;
		case 3:
			deldetInfo(sq);
			break;
		case 4:
			changeInfo(sq);
			break;
		case 5:
			disInfo( sq);
			break;
		case 6:
			exit(0);
		}
	}
}
//1.添加通讯录信息
void addInfo(sqList*& sq)
{
	printf("请输入添加的人数");
	int number;
	scanf_s("%d", &number);
	getchar();
	if (sq->number + number >= MAXSIZE - 1)
	{
		printf("通讯录无空间了");
	}
	else {
		for (int i = 0; i < number; i++)
		{
			bool judge = false;
			while (!judge)
			{
				printf("请输入第%d个人的电话:\n", i + 1);
				gets_s(sq->data[sq->number].number);
				for (int j = 0; j < sq->number ; j++)
					if (strcmp(sq->data[j].number, sq->data[sq->number].number) == 0)
					{
						printf("电话号码已存在，请检查输入是否正确\n");
						judge = false;
						break;
					}
					else
						judge = true;
			}
			printf("请输入第%d个人的名字:\n", i + 1);
			gets_s(sq->data[sq->number].name);
			printf("请输入第%d个人的通信地址:\n", i + 1);
			gets_s(sq->data[sq->number].address);
			printf("请输入第%d个人的邮编:\n", i + 1);
			gets_s(sq->data[sq->number++].postal);
		}
	}
	storeData(sq);
}


//2.查询通讯录信息
void findInfo(sqList* sq)
{
	system("cls");
	printf("1.按姓名查找\n");
	printf("2.按地址查找\n");
	printf("3.按电话号码查找\n");
	printf("4.按邮编查找\n");
	printf("5.退出查找\n");
	char s;
	getchar();
	scanf_s("%c",&s);
	while (s > '5' || s < '0')
	{
		printf("选择有误，请重新选择");
		getchar();
		scanf_s("%c",&s);
	}
	switch (s)
	{
	case '1':
		findNameInfo(sq);
		break;
	case '2':
		findAddressInfo(sq);
		break;
	case '3':
		findNumberInfo(sq);
		break;
	case '4':
		findMailInfo(sq);
		break;
	case '5':
		return;
	}


}
//2.1 按姓名查找
void findNameInfo(sqList* sq)
{
	bool flag=false;
	char name[MAXSIZE];
	int a[MAXSIZE];
	getchar();
	printf("请输入姓名：");
	gets_s(name);
	int count = 0;
	if (name[0] == '\0')
	{
		disInfo(sq);
		return;
	}
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].name,name) == 0)
		{
			flag = true;
			a[count++] = i;
		}
	}
	if (!flag)
		printf("未找到该人，请检查输入是否正确");
	else
	{
		arr_sort(sq, a, count);
		for (int i = 0; i < count; i++)
		{
			printf("姓名：%s   通信地址：%s  电话号码：%s  邮政编码：%s \n", sq->data[a[i]].name, sq->data[a[i]].address, sq->data[a[i]].number, sq->data[a[i]].postal);
		}
	}
}
//2.2 按通信地址查找
void findAddressInfo(sqList* sq)
{
	bool flag=false;
	char address[MAXSIZE];
	printf("请输入通信地址：");
	getchar();
	gets_s(address);
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].address, address) == 0)
		{
			printf("姓名：%s   \t通信地址：%s   电话号码：%s   邮政编码：%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
		}
	}
	if (!flag)
		printf("未找到该人，请检查输入是否正确");
}
//2.3 按电话号码查找
void findNumberInfo(sqList* sq)
{
	bool flag = false;
	char number[MAXSIZE];
	getchar();
	printf("请输入电话号码：");
	gets_s(number);
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].number, number) == 0)
		{
			printf("姓名：%s   \t通信地址：%s   电话号码：%s   邮政编码：%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
		}
	}
	if (!flag)
		printf("未找到该人，请检查输入是否正确");
}
//2.4 按邮编查找
void findMailInfo(sqList* sq)
{
	bool flag = false;
	char postal[MAXSIZE];
	getchar();
	printf("请输入邮编号码：");
	gets_s(postal);
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].postal, postal) == 0)
		{
			printf("姓名：%s   \t通信地址：%s   电话号码：%s   邮政编码：%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
		}
	}
	if (!flag)
		printf("未找到该人，请检查输入是否正确");
}
//2.5 给名字相同的按电话号码排序（希尔排序）
void arr_sort(sqList* sq, int* a, int n)
{
	int step = 0;
	char temp;
	int i, j;
	for (step = n / 2; step > 0; step /= 2)
	{
		for (i = step; i < n; i++)
		{
			temp = a[i];
			for (j = i - step; j >= 0 && strcmp(sq->data[a[j]].number, sq->data[temp].number) == 1; j -= step)
			{
				a[j + step] = a[j];
			}
			a[j + step] = temp;
		}
	}
}
//3 删除通讯录信息
void deldetInfo(sqList*& sq)
{
	bool flag = false;
	char number[MAXSIZE];
	getchar();
	printf("请输入电话号码：");
	gets_s(number);
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].number, number) == 0)
		{
			for (int j = i; j < sq->number; j++)
			{
				sq->data[j] = sq->data[j + 1];
			}
			sq->number--;
			flag = true;
			break;
		}
	}
	if (!flag)
		printf("未找到该人，请检查输入是否正确");
	else
		printf("删除成功");
	storeData(sq);
}
//4 修改通讯录信息
void changeInfo(sqList*& sq)
{
	bool flag = false;
	char number[MAXSIZE];
	getchar();
	printf("请输入电话号码：");
	gets_s(number);
	int i;
	for (i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].number, number) == 0)
		{
			printf("姓名：%s   \t通信地址：%s   电话号码：%s   邮政编码：%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
			break;
		}
	}
	if (!flag)
		printf("未找到该人，请检查输入是否正确");
	else
	{
		while (true)
		{
			printf("****************************\n");
			printf("** 1.姓名      2.电话     **\n");
			printf("** 3.通讯地址  4.邮政编码 **\n");
			printf("** 5.退出修改             **\n");
			printf("****************************\n");
			int select = 0;
			scanf_s("%d", &select);
			getchar();
			switch (select)
			{
			case 1:
				gets_s(sq->data[i].name);
				break;
			case 2:
				gets_s(sq->data[i].number);
				break;
			case 3:
				gets_s(sq->data[i].address);
				break;
			case 4:
				gets_s(sq->data[i].postal);
				break;
			case 5:
				return;
			}
			printf("修改成功");
			printf("姓名：%s   \t通信地址：%s   电话号码：%s   邮政编码：%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			storeData(sq);
		}
	}
}
//5 显示通讯录信息
void disInfo(sqList* sq)
{
	if (sq->number < 0)
	{
		printf("无信息");
		return;
	}
	for (int i = 0; i < sq->number; i++)
	{
		printf("姓名：%s   \t通信地址：%s   电话号码：%s   邮政编码：%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
	}
}