#pragma once
//链表的元素构成和声明方式,使用之前请确定元素构成已更改
typedef struct list
{
	char no[20];
	char name[20];
	list *pNext;
}list;

//判断变量
char adjust[2];

//获取一个新的节点
list* getnode()
{
	list *pNew = (list*)malloc(sizeof(list));
	if (pNew == NULL)
	{
		printf("failed get newmode\n");
		return NULL;
	}
	printf("enter no:");
	rewind(stdin);
	gets_s(pNew->no, 20);
	printf("enter name:");
	gets_s(pNew->name, 20);
	return pNew;
}

//输出节点
void printnode(list *node)
{
	puts(node->no);
	puts(node->name);
}

//尾插法创建链表
list* creat()
{
	list *pHead = NULL;
	list *pNew = NULL, *pEnd = NULL;
	
	while (1)
	{
		printf("continue(y/n)?:");
		gets_s(adjust, 2);
		if (strcmp(adjust, "n") == 0 || strcmp(adjust, "N") == 0)
			break;

		if ((pNew = getnode()) != NULL)
		{
			if (pHead == NULL)
			{
				pNew->pNext = NULL;
				pEnd = pNew;
				pHead = pNew;
			}
			else
			{
				pNew->pNext = NULL;
				pEnd->pNext = pNew;
				pEnd = pNew;
			}
		}
	}
	return pHead;
}

//一次性输出链表
void printlist(list *pHead)
{
	if (pHead == NULL)
	{
		printf("nothing in here\n");
		return;
	}
	while (pHead != NULL)
	{
		printnode(pHead);
		pHead = pHead->pNext;
	}
}

//在链表的头部添加一个节点
list* inserthead(list *pHead)
{
	list *pNew;
	pNew = getnode();

	pNew->pNext = pHead;
	pHead = pNew;
	return pHead;
}

//在链表中删除一个节点
list* deletelist(list *pHead,char *no)
{
	list *pTemp = pHead;
	list *pDel;
	//判断空列表
	if (pHead == NULL)
	{
		printf("nothing in here\n");
		return NULL;
	}
	//首指针后满足条件的节点删除
	while (strcmp(pHead->no, no) == 0)
	{
		pDel = pHead;
		pHead = pDel->pNext;
		free(pDel);
	}
	//中间及末尾节点的删除
	while (pTemp ->pNext != NULL)
	{
		if (strcmp(pTemp->pNext->no, no) == 0)
		{
			pDel = pTemp->pNext;
			pTemp->pNext = pDel->pNext;
			free(pDel);
			continue;
		}
		pTemp = pTemp->pNext;
	}
	return pHead;
}

//向链表插入一个节点(有序插入)
list* insertlist(list *pHead,list *pNewnode)
{
	list *pTemp = pHead;

	if (strcmp(pNewnode->no, pHead->no) < 0)
	{
		pNewnode->pNext = pHead;
		pHead = pNewnode;
	}

	while (pTemp != NULL)
	{
		if (strcmp(pNewnode->no, pTemp->no) > 0 && strcmp(pNewnode->no, pTemp->pNext->no) < 0)
		{
			pNewnode->pNext = pTemp->pNext;
			pTemp->pNext = pNewnode;
		}
		pTemp = pTemp->pNext;
	}
	
	/*while (pTemp->pNext != NULL && strcmp(pTemp->pNext->no, pNewnode->no) < 0)
		pTemp = pTemp->pNext;
	pNewnode->pNext = pTemp->pNext;
	pTemp->pNext = pNewnode;*/
	return pHead;
}

//释放链表
void freelist(list *pHead)
{
	list *pTemp;
	while (pHead != NULL)
	{
		pTemp = pHead;
		pHead = pHead->pNext;
		free(pTemp);
	}
}

//将链表保存在文件中
void savelist(list *pHead, char *filename)
{
	FILE *fp;
	if ((fp = fopen(filename, "ab+")) == NULL)
	{
		printf("can't open file\n");
		return;
	}
	while (pHead != NULL)
	{
		if (fwrite(pHead, sizeof(list), 1, fp) == 1)
			pHead = pHead->pNext;
		else
		{
			printf("can't enter file\n");
			return;
		}
	}
	fclose(fp);
}

//读取文件来创建链表
list* loadlist(char *filename)
{
	FILE *fp;
	if ((fp = fopen(filename, "ab+")) == NULL)
	{
		printf("can't open file\n");
		return NULL;
	}
	rewind(fp);
	list *pHead = NULL;
	list *pNew = NULL;
	list *pEnd = pNew;
	
	while (!feof(fp))
	{
		pNew = (list*)malloc(sizeof(list));
		if (pNew == NULL)
		{
			free(pNew);
			printf("failed get node's room\n");
			return NULL;
		}
		if (fread(pNew, sizeof(list), 1, fp) == 1)
		{
			if (pHead == NULL)
			{
				pNew->pNext = NULL;
				pHead = pNew;
				pEnd = pNew;
			}
			else
			{
				pNew->pNext = NULL;
				pEnd->pNext = pNew;
				pEnd = pNew;
			}
		}
		else
			free(pNew);
	}
	fclose(fp);
	return pHead;
}

//查找指定的节点
list* searchlist(list *pHead, char *no)
{
	list *pTemp = pHead;
	while (pTemp != NULL)
	{
		if (strcmp(pTemp->no, no) == 0)
			return pTemp;
		pTemp = pTemp->pNext;
	}
	return NULL;
}

//修改指定节点
void nodifylist(list *pHead, char *no)
{
	list *pNode = searchlist(pHead, no);
	if (pNode != NULL)
	{
		printf("please modify imformation\n");
		rewind(stdin);
		gets_s(pNode->no, 20);
		printf("enter name:");
		gets_s(pNode->name, 20);
	}
	else
	{
		printf("can't find the node\n");
		return;
	}
}
