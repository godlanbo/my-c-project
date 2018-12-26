#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

/*int count = 0;

student* creat()
{
	student *pHead = NULL;
	student *pNew, *pEnd;
	pEnd = pNew = (student*)malloc(sizeof(student));
	printf("please first enter Name,then Number\n");
	scanf_s("%s", pNew->cName,20);
	scanf_s("%d", &pNew->iNumber);
	while (pNew->iNumber != 0)
	{
		count++;
		if (count == 1)
		{
			pNew->pNext = pHead;
			pEnd = pNew;
			pHead = pNew;
		}
		else
		{
			pNew->pNext = NULL;
			pEnd->pNext = pNew;
			pEnd = pNew;
		}
		pNew = (student*)malloc(sizeof(student));
		scanf_s("%s", pNew->cName,20);
		scanf_s("%d", &pNew->iNumber);
	}
	free(pNew);
	return pHead;
}

void print(student *pHead)
{
	student *pTemp;
	int index = 1;

	printf("---the list has %d members:---\n", count);
	printf("\n");
	pTemp = pHead;

	while (pTemp != NULL)
	{
		printf("the NO.%d member is:\n", index);
		printf("the name is: %s\n", pTemp->cName);
		printf("the number is: %d\n", pTemp->iNumber);
		printf("\n");
		pTemp = pTemp->pNext;
		index++;
	}
}

student* print_head(student *pHead)
{
	student *pNew;
	printf("---input memeber at first---\n");
	pNew = (student*)malloc(sizeof(student));

	scanf_s("%s", pNew->cName, 20);
	scanf_s("%d", &pNew->iNumber);

	pNew->pNext = pHead;
	pHead = pNew;
	count++;
	return pHead;
}

void Delete(student *pHead,int index)
{
	int i;
	student *pTemp;
	student *pPre;
	pTemp = pHead;
	pPre = pTemp;

	printf("---delete NO.%d member---\n", index);
	for (i = 1; i < index; i++)
	{
		pPre = pTemp;
		pTemp = pTemp->pNext;
	}
	pPre->pNext = pTemp->pNext;
	free(pTemp);
	count--;
}*/

int main()
{
	list *pHead=NULL, *node;
	list *pHead1 = NULL;
	char del[10], filename[50];
	gets_s(filename, 50);

	pHead = creat();
	printlist(pHead);

	savelist(pHead, filename);
	

	/*freelist(pHead);
	printlist(pHead);*/

	pHead1 = loadlist(filename);
	printlist(pHead1);

	/*node = getnode();
	pHead = insertlist(pHead, node);

	printlist(pHead);

	printf("del?:");
	rewind(stdin);
	gets_s(del, 10);
	pHead = deletelist(pHead, del);
	printlist(pHead);*/

	return 0;
}