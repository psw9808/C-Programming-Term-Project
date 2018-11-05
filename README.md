# 조 편성 프로그램
C프로그래밍과 실습 과목 텀프로젝트로 조 편성 프로그램을 제작하였습니다.\
학생정보를 입력받아 성적순으로 정렬 후 정해진 수만큼 조를 편성하는 프로그램입니다.

# main 함수

메인 함수에서는 프로그램의 기능 목록 화면을 구성하고 기능들에 대한 설명을 나타내었습니다.\
사용자가 원하는 기능의 번호를 입력받아 다음의 switch문으로 각 기능들의 함수를 실행시킵니다.

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

# input 함수

학생의 정보를 저장하는 구조체(이름,성적,성별) 배열에 입력된 정보를 저장합니다.

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

# sort / output 함수

학생들의 성적을 토대로 내림차순으로 정렬하는 기능 및 정렬된 학생정보를 출력해주는 함수입니다.


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


	for (i = 0; i<c; i++)
	{
		printf("%s , %d , %d\n", out[i].name, out[i].score, out[i].gender);
	}


# 조 편성 함수

만들고 싶은 조의 갯수를 입력 받아 학생들을 정해진 조의 갯수만큼 나누어 줍니다.


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

# 파일 입출력 함수

학생 정보를 텍스트 파일로 저장하거나 불러올수 있습니다.

FILE*fp;
	fp = fopen("student.txt", "w");

	for (i = 0; i<c; i++)
	{
		fprintf(fp, "%s %d %d\n", w[i].name, w[i].score, w[i].gender);
	}
	fclose(fp);
  
  
  FILE*fp;
	fp = fopen("student.txt", "r");

	for (i = 0; !feof(fp); i++)
	{
		fscanf(fp, "%s %d %d\n", &r[i].name, &r[i].score, &r[i].gender);
		c++;
	}
	fclose(fp);
