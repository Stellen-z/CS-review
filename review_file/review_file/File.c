#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main()
{
	//FILE* fp = fopen("test.txt","w");


	//if (fp == NULL)
	//{
	//	perror("fopen failed!\n");
	//	exit(1);
	//}

	//printf("fopen success\n");

	//for (char ch = 'a'; ch <= 'z'; ch++)
	//{
	//	fputc(ch, fp);
	//}

	//fclose(fp);
	//fp = NULL;

	//fp = fopen("test.txt", "r");
	//for (int i = 0; i < 26; i++)
	//{
	//	char ch = fgetc(fp);
	//	fputc(ch, stdout);
	//		
	//}

	//fclose(fp);
	//fp = NULL;

	//FILE* fp = fopen("test.txt", "w");
	//fputs("kskbl\n", fp);
	//fputs("zdjd\n", fp);

	//fclose(fp);
	//fp = NULL;

	//fp = fopen("test.txt", "r");
	//if (fp == NULL)
	//{
	//	perror("fopen failed!\n");
	//	exit(1);
	//}

	//char arr1[] = "******************";
	//

	//while (fgets(arr1, sizeof(arr1), fp) != NULL)
	//{
	//	printf("%s", arr1);
	//}

	//fclose(fp);
	//fp = NULL;

	//FILE* fp = fopen("test.txt", "w");
	//struct student
	//{
	//	char name[20];
	//	int age;
	//	float score;
	//};

	//struct student s = { "zhangsan",19,85.5 };

	//fprintf(fp, "%s %d %f", s.name, s.age, s.score);

	//fclose(fp);
	//fp = NULL;


	FILE* fp = fopen("test.txt", "r");

	struct student
	{
		char name[20];
		int age;
		float score;
	};

	struct student s = { 0 };

	fscanf(fp, "%s %d %f", s.name, &(s.age), &(s.score));
	fprintf(stdout, "%s %d %f", s.name, s.age, s.score);

	fclose(fp);
	fp = NULL;

	return 0;
}