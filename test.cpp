//#include<stdio.h>
//#include<malloc.h>
//#define MAXSIZE 50
//
//typedef struct
//{
//	char name[MAXSIZE];
//	char address[MAXSIZE];
//	char postal[MAXSIZE];
//	char number[MAXSIZE];
//}mail;
//typedef struct
//{
//	mail data[MAXSIZE];
//	int number;
//}sqList;
//void scanner(char* ch)
//{
//	int i = 0;
//	char c;
//	//ch = ; // �������ʼ��s[]��ϵͳ���Զ���ֵ
//	scanf_s("%c", &c);
//	while (c != '\n') {
//		ch[i] = c;
//		i++;
//		scanf_s("%c", &c);
//	}
//	ch[i] = '\0';
//	//printf("%s\n", ch);
//}
//
//int main()
//{
//	//int i = 0;
//	//char ch[7];
//	//char ch1[7] = { "������" };
//	//char c1;
//	//char c2;
//	//printf("�����룺");
//	//gets_s(ch);
//	///*scanf_s("%c%c", &c1, &c2);
//	//while (c2 != '\0') {
//	//	ch[i++] = c1;
//	//	ch[i++] = c2;
//	//	scanf_s("%c%c", &c1, &c2);
//	//}
//	//ch[i] = '\0';*/
//	//
//	//for (int i = 0; i < 6; i++)
//	//{
//	//	if (ch[i] == ch1[i] && ch[++i] == ch1[i])
//	//		printf("%c%c\n", ch[i-1], ch[i]);
//	//	
//	//}
//	char ch[10];
//	gets_s(ch);
//	if (ch == "\n")
//		printf("\\n");
//	else if (ch[0] == '\0')
//		printf("\0");
//	else if (ch == NULL)
//		printf("NULL");
//	else
//		printf("������");
//	return 0;
//}