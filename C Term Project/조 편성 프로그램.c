#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
#pragma warning (disable : 4996)

typedef struct
{
	char name[7];
	int score;
	int gender;
}student;


void input(student inp[]);
void sort(student sor[]);
void output(student out[]);
void jo(student jo[]);
void fw(student w[]);
void fr(student r[]);

int i, c = 0;

void main()
{
	student s[100];
	int m = 0;

main:
	{
		system("cls");
		printf("\n<�� �� ���α׷�>\n\n");
		printf("------------------\n\n");
		printf("�л������Է� : 1");
		printf("                    �л����� ������ ������ �Է¹޽��ϴ�\n\n");
		printf("�л� ���� : 2");
		printf("                       ����� �л� ������ ���� ������������ �����մϴ� \n\n");
		printf("���� ���� : 3");
		printf("                       ������ ������� ����� ������ �迭�մϴ�\n\n");
		printf("�л����� �����ϱ� : 4");
		printf("               1���� ���Ͽ� �Է��� ������ �ؽ�Ʈ ���Ϸ� �����մϴ�\n\n");
		printf("�л����� �ҷ����� : 5");
		printf("               ����Ǿ� �ִ� �ؽ�Ʈ ������ �ҷ��ɴϴ�\n\n");
		printf("������ : 6");
		printf("                          ���α׷��� �����մϴ�\n\n");
		printf("------------------\n");
		scanf("%d", &m);
		fflush(stdin);


		switch (m)
		{
		case 1:

			system("cls");
			printf("<�л������Է�>\n");
			input(s);
			system("pause");
			goto main;
			break;

		case 2:
			system("cls");
			printf("<�л� ����>\n\n");
			sort(s);
			output(s);
			system("pause");
			goto main;
			break;

		case 3:
			system("cls");
			printf("<���� ����>\n");
			jo(s);
			system("pause");
			goto main;
			break;

		case 4:
			system("cls");
			printf("<�л����� �����ϱ�>\n\n");
			fw(s);
			printf("���α׷��� ����� ������ �л������� �ؽ�Ʈ ���Ϸ� �����ϴµ� �����Ͽ����ϴ�\n\n");
			system("pause");
			goto main;
			break;

		case 5:
			system("cls");
			printf("<�л����� �ҷ�����>\n\n");
			fr(s);
			printf("���α׷� ������ ��ġ�� �л� ���� ������ �ҷ����µ� �����Ͽ����ϴ�\n\n");
			system("pause");
			goto main;
			break;

		case 6:
			break;

		default:
			break;
		}

	}

}

void input(student inp[])
{

	for (i = 0; i<100; i++)
	{
		printf("�л��̸� ? (�Է�����:0) :");
		scanf_s("%s", inp[i].name, 7);
		fflush(stdin);
		if (!strcmp(inp[i].name, "0"))
			break;
		printf("���� ? :");
		scanf("%d", &inp[i].score);
		fflush(stdin);
		printf("���� ? (����:0, ����:1) :");
		scanf("%d", &inp[i].gender);
		fflush(stdin);
		printf("\n");
		c++;
	}
}


void sort(student sor[])
{
	int j, flag;
	student a;
	for (i = 1; i<c; i++)
	{
		flag = 0;
		for (j = 0; j<c - 1; j++)
			if (sor[j].score<sor[j + 1].score)
			{
				a = sor[j];
				sor[j] = sor[j + 1];
				sor[j + 1] = a;
				flag = 1;
			}

		if (flag == 0)
			break;
	}

}

void output(student out[])
{

	for (i = 0; i<c; i++)
	{
		printf("%s , %d , %d\n", out[i].name, out[i].score, out[i].gender);
	}
}

void jo(student jo[])
{
	int j = 0, t;
	printf("\n�� ���� ���� �����ұ��? : ");
	scanf("%d", &j);
	fflush(stdin);
	if (j >= c)
	{
		printf("��ü �л����� %d�� �Դϴ�.\n\n", c);

		for (i = 0; i<c; i++)
		{
			printf("%d��	      ", i + 1);
		}

		printf("\n\n");

		for (i = 0; i<c; i++)
		{
			printf("����:%s      ", jo[i].name);
		}
	}

	else if (j<c)
	{
		for (i = 0; i<j; i++)
		{
			printf("%d��      ", i + 1);
		}

		printf("\n\n");

		for (i = 0; i<j; i++)
		{
			printf("����:%s      ", jo[i].name);
		}

		printf("\n");

		for (t = 0; t<c / j; t++)
		{
			for (i = 0; i<j&&i + j * (t + 1)<c; i++)
			{
				printf("����:%s      ", jo[i + j * (t + 1)].name);
			}
			printf("\n");
		}
	}
}

void fw(student w[])
{
	FILE*fp;
	fp = fopen("student.txt", "w");

	for (i = 0; i<c; i++)
	{
		fprintf(fp, "%s %d %d\n", w[i].name, w[i].score, w[i].gender);
	}
	fclose(fp);
}

void fr(student r[])
{
	FILE*fp;
	fp = fopen("student.txt", "r");

	for (i = 0; !feof(fp); i++)
	{
		fscanf(fp, "%s %d %d\n", &r[i].name, &r[i].score, &r[i].gender);
		c++;
	}
	fclose(fp);

}