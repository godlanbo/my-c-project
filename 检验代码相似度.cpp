#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *ch1 = (char*)malloc(sizeof(char) * 15000);
char *ch2 = (char*)malloc(sizeof(char) * 15000);
char *ch3 = (char*)malloc(sizeof(char) * 10000);
char *ch4 = (char*)malloc(sizeof(char) * 10000);
//int check[10050][10050] = { 0 };
int count[500] = { 0 };
void check_string(char str1[], char str2[])
{
	int n1 = strlen(str1);
	int n2 = strlen(str2);

	int **check = (int**)malloc(n1 * sizeof(int*) + 50);
	for (int i = 0; i < n1 + 50; i++)
		check[i] = (int*)malloc(n2 * sizeof(int) + 50);

	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			check[i][j] = 0;

	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			if (str1[i] == str2[j])
				check[i][j] = 1;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			if (check[i + 1][j + 1] != 0)
				check[i + 1][j + 1] += check[i][j];
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			if (check[i][j] > 10 && check[i + 1][j + 1] == 0 && check[i][j] < 500)
				count[check[i][j]]++;

	for (int i = 0; i < n1 + 50; i++)
		free(check[i]);
}
void open_file()
{
	char temp[50], file1[50], file2[50];
	int k = 0, j = 0;
	printf("请输入比较的文件1的路径(或已在当前源文件目录下可直接输入文件名),用\\\\隔开:\n");
	gets_s(file1, 50);
	printf("请输入比较的文件2的路径(或已在当前源文件目录下可直接输入文件名),用\\\\隔开:\n");
	gets_s(file2, 50);
	FILE *fp1 = fopen(file1, "r");
	FILE *fp2 = fopen(file2, "r");
	if (fp1 != NULL)
	{
		(fgets(temp, 50, fp1));
		sprintf(ch1, "%s", temp);
		while ((fgets(temp, 50, fp1)) != NULL)
			strcat(ch1, temp);
		for (int i = 0; ch1[i]!='\0'; i++)
		{
			if (ch1[i] == ' ')
				continue;
			else if (ch1[i] == '\t')
				continue;
			else if (ch1[i] == '\n')
				continue;
			else if (ch1[i] == '/')
			{
				if (ch1[i + 1] == '/')
				{
					while (1)
					{
						if (ch1[i++] == '\n')
							break;
					}
				}
				else if (ch1[i + 1] == '*')
				{
					i += 1;
					while (1)
					{
						if (ch1[++i] == '*')
						{
							i += 2;
							break;
						}
					}
				}
				else
					continue;
			}
			else
				ch3[k++] = ch1[i];
			if (k == 9999)
				ch3[k] = '\0';
		}
		ch3[k] = '\0';
	}
	else
		exit(1);
	fclose(fp1);
	if (fp2 != NULL)
	{
		(fgets(temp, 50, fp2));
		sprintf(ch2, "%s", temp);
		while ((fgets(temp, 50, fp2)) != NULL)
			strcat(ch2, temp);
		for (int i = 0; ch2[i] != '\0'; i++)
		{
			if (ch2[i] == ' ')
				continue;
			else if (ch2[i] == '\t')
				continue;
			else if (ch2[i] == '\n')
				continue;
			else if (ch2[i] == '/')
			{
				if (ch2[i + 1] == '/')
				{
					while (1)
					{
						if (ch2[i++] == '\n')
							break;
					}
				}
				else if (ch2[i + 1] == '*')
				{
					i += 1;
					while (1)
					{
						if (ch2[++i] == '*')
						{
							i += 2;
							break;
						}
					}
				}
				else
					continue;
			}
			else
				ch4[j++] = ch2[i];
			if (j == 9999)
				ch4[j] = '\0';
		}
		ch4[j] = '\0';
	}
	else
		exit(1);
	fclose(fp2);
	check_string(ch3, ch4);
}
int main()
{
	open_file();
	double sum = 0;
	for (int i = 0; i < 500; i++)
	{
		if (count[i] == 0)
			continue;
		printf("连续%d个字符串出现次数:%d\n", i, count[i]);
		sum += (i / 100.0)*count[i];
	}
	printf("%lf\n", sum);
	free(ch1);
	free(ch2);
	free(ch3);
	free(ch4);
	system("pause");
	return 0;
}