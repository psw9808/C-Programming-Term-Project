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
		printf("\n<조 편성 프로그램>\n\n");
		printf("------------------\n\n");
		printf("학생정보입력 : 1");
		printf("                    학생들의 성적과 성별을 입력받습니다\n\n");
		printf("학생 정렬 : 2");
		printf("                       저장된 학생 정보를 성적 내림차순으로 정렬합니다 \n\n");
		printf("조원 배정 : 3");
		printf("                       성적을 기반으로 조장과 조원을 배열합니다\n\n");
		printf("학생정보 저장하기 : 4");
		printf("               1번을 통하여 입력한 정보를 텍스트 파일로 저장합니다\n\n");
		printf("학생정보 불러오기 : 5");
		printf("               저장되어 있는 텍스트 파일을 불러옵니다\n\n");
		printf("나가기 : 6");
		printf("                          프로그램을 종료합니다\n\n");
		printf("------------------\n");
		scanf("%d", &m);
		fflush(stdin);


		switch (m)
		{
		case 1:

			system("cls");
			printf("<학생정보입력>\n");
			input(s);
			system("pause");
			goto main;
			break;

		case 2:
			system("cls");
			printf("<학생 정렬>\n\n");
			sort(s);
			output(s);
			system("pause");
			goto main;
			break;

		case 3:
			system("cls");
			printf("<조원 배정>\n");
			jo(s);
			system("pause");
			goto main;
			break;

		case 4:
			system("cls");
			printf("<학생정보 저장하기>\n\n");
			fw(s);
			printf("프로그램이 저장된 폴더에 학생정보를 텍스트 파일로 저장하는데 성공하였습니다\n\n");
			system("pause");
			goto main;
			break;

		case 5:
			system("cls");
			printf("<학생정보 불러오기>\n\n");
			fr(s);
			printf("프로그램 폴더에 위치한 학생 정보 파일을 불러오는데 성공하였습니다\n\n");
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
		printf("학생이름 ? (입력종료:0) :");
		scanf_s("%s", inp[i].name, 7);
		fflush(stdin);
		if (!strcmp(inp[i].name, "0"))
			break;
		printf("성적 ? :");
		scanf("%d", &inp[i].score);
		fflush(stdin);
		printf("성별 ? (남자:0, 여자:1) :");
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
	printf("\n몇 개의 조를 구성할까요? : ");
	scanf("%d", &j);
	fflush(stdin);
	if (j >= c)
	{
		printf("전체 학생수는 %d명 입니다.\n\n", c);

		for (i = 0; i<c; i++)
		{
			printf("%d조	      ", i + 1);
		}

		printf("\n\n");

		for (i = 0; i<c; i++)
		{
			printf("조장:%s      ", jo[i].name);
		}
	}

	else if (j<c)
	{
		for (i = 0; i<j; i++)
		{
			printf("%d조      ", i + 1);
		}

		printf("\n\n");

		for (i = 0; i<j; i++)
		{
			printf("조장:%s      ", jo[i].name);
		}

		printf("\n");

		for (t = 0; t<c / j; t++)
		{
			for (i = 0; i<j&&i + j * (t + 1)<c; i++)
			{
				printf("조원:%s      ", jo[i + j * (t + 1)].name);
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