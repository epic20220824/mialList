#include"menu.h"

//��ʼ�����Ա�
void init(sqList*& sq)
{
	sq = (sqList*)malloc(sizeof(sqList));
	sq->number = -1;
}
//��ȡ�ļ����������
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
		printf("�ļ������ڣ������ļ���ʽ�Ƿ���ȷ");
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
//��������
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

//�˵�
void menu()
{
	printf("*************************\n");
	printf("*** 1.���ͨѶ¼��Ϣ ****\n");
	printf("*** 2.��ѯͨѶ¼��Ϣ ****\n");
	printf("*** 3.ɾ��ͨѶ¼��Ϣ ****\n");
	printf("*** 4.�޸�ͨѶ¼��Ϣ ****\n");
	printf("*** 5.��ʾͨѶ¼��Ϣ ****\n");
	printf("*** 6.�˳�����       ****\n");
	printf("*************************\n");
}
//�û�ѡ��
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
			printf("��ѡ����ȷ��ѡ��");
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
//1.���ͨѶ¼��Ϣ
void addInfo(sqList*& sq)
{
	printf("��������ӵ�����");
	int number;
	scanf_s("%d", &number);
	getchar();
	if (sq->number + number >= MAXSIZE - 1)
	{
		printf("ͨѶ¼�޿ռ���");
	}
	else {
		for (int i = 0; i < number; i++)
		{
			bool judge = false;
			while (!judge)
			{
				printf("�������%d���˵ĵ绰:\n", i + 1);
				gets_s(sq->data[sq->number].number);
				for (int j = 0; j < sq->number ; j++)
					if (strcmp(sq->data[j].number, sq->data[sq->number].number) == 0)
					{
						printf("�绰�����Ѵ��ڣ����������Ƿ���ȷ\n");
						judge = false;
						break;
					}
					else
						judge = true;
			}
			printf("�������%d���˵�����:\n", i + 1);
			gets_s(sq->data[sq->number].name);
			printf("�������%d���˵�ͨ�ŵ�ַ:\n", i + 1);
			gets_s(sq->data[sq->number].address);
			printf("�������%d���˵��ʱ�:\n", i + 1);
			gets_s(sq->data[sq->number++].postal);
		}
	}
	storeData(sq);
}


//2.��ѯͨѶ¼��Ϣ
void findInfo(sqList* sq)
{
	system("cls");
	printf("1.����������\n");
	printf("2.����ַ����\n");
	printf("3.���绰�������\n");
	printf("4.���ʱ����\n");
	printf("5.�˳�����\n");
	char s;
	getchar();
	scanf_s("%c",&s);
	while (s > '5' || s < '0')
	{
		printf("ѡ������������ѡ��");
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
//2.1 ����������
void findNameInfo(sqList* sq)
{
	bool flag=false;
	char name[MAXSIZE];
	int a[MAXSIZE];
	getchar();
	printf("������������");
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
		printf("δ�ҵ����ˣ����������Ƿ���ȷ");
	else
	{
		arr_sort(sq, a, count);
		for (int i = 0; i < count; i++)
		{
			printf("������%s   ͨ�ŵ�ַ��%s  �绰���룺%s  �������룺%s \n", sq->data[a[i]].name, sq->data[a[i]].address, sq->data[a[i]].number, sq->data[a[i]].postal);
		}
	}
}
//2.2 ��ͨ�ŵ�ַ����
void findAddressInfo(sqList* sq)
{
	bool flag=false;
	char address[MAXSIZE];
	printf("������ͨ�ŵ�ַ��");
	getchar();
	gets_s(address);
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].address, address) == 0)
		{
			printf("������%s   \tͨ�ŵ�ַ��%s   �绰���룺%s   �������룺%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
		}
	}
	if (!flag)
		printf("δ�ҵ����ˣ����������Ƿ���ȷ");
}
//2.3 ���绰�������
void findNumberInfo(sqList* sq)
{
	bool flag = false;
	char number[MAXSIZE];
	getchar();
	printf("������绰���룺");
	gets_s(number);
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].number, number) == 0)
		{
			printf("������%s   \tͨ�ŵ�ַ��%s   �绰���룺%s   �������룺%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
		}
	}
	if (!flag)
		printf("δ�ҵ����ˣ����������Ƿ���ȷ");
}
//2.4 ���ʱ����
void findMailInfo(sqList* sq)
{
	bool flag = false;
	char postal[MAXSIZE];
	getchar();
	printf("�������ʱ���룺");
	gets_s(postal);
	for (int i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].postal, postal) == 0)
		{
			printf("������%s   \tͨ�ŵ�ַ��%s   �绰���룺%s   �������룺%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
		}
	}
	if (!flag)
		printf("δ�ҵ����ˣ����������Ƿ���ȷ");
}
//2.5 ��������ͬ�İ��绰��������ϣ������
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
//3 ɾ��ͨѶ¼��Ϣ
void deldetInfo(sqList*& sq)
{
	bool flag = false;
	char number[MAXSIZE];
	getchar();
	printf("������绰���룺");
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
		printf("δ�ҵ����ˣ����������Ƿ���ȷ");
	else
		printf("ɾ���ɹ�");
	storeData(sq);
}
//4 �޸�ͨѶ¼��Ϣ
void changeInfo(sqList*& sq)
{
	bool flag = false;
	char number[MAXSIZE];
	getchar();
	printf("������绰���룺");
	gets_s(number);
	int i;
	for (i = 0; i < sq->number; i++)
	{
		if (strcmp(sq->data[i].number, number) == 0)
		{
			printf("������%s   \tͨ�ŵ�ַ��%s   �绰���룺%s   �������룺%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			flag = true;
			break;
		}
	}
	if (!flag)
		printf("δ�ҵ����ˣ����������Ƿ���ȷ");
	else
	{
		while (true)
		{
			printf("****************************\n");
			printf("** 1.����      2.�绰     **\n");
			printf("** 3.ͨѶ��ַ  4.�������� **\n");
			printf("** 5.�˳��޸�             **\n");
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
			printf("�޸ĳɹ�");
			printf("������%s   \tͨ�ŵ�ַ��%s   �绰���룺%s   �������룺%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
			storeData(sq);
		}
	}
}
//5 ��ʾͨѶ¼��Ϣ
void disInfo(sqList* sq)
{
	if (sq->number < 0)
	{
		printf("����Ϣ");
		return;
	}
	for (int i = 0; i < sq->number; i++)
	{
		printf("������%s   \tͨ�ŵ�ַ��%s   �绰���룺%s   �������룺%s \n", sq->data[i].name, sq->data[i].address, sq->data[i].number, sq->data[i].postal);
	}
}