#define _CRT_SECURE_NO_WARRNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"


void initcontact(struct contact* ps)
{
	ps->date = (struct popinfo*) malloc(DEFAULT_SZ*sizeof(struct popinfo));
	if(ps->date== NULL)
	{
		return;
	}
	ps->size= 0;
	ps->capacity= DEFAULT_SZ;


}

void checkcapacity(struct contact* ps)
{
	if(ps->size == ps->capacity)
	{
		//增加容量
		struct popinfo* ptr= (struct popinfo*)realloc(ps->date,(ps->capacity+2)*sizeof(struct popinfo));
		if(ptr != NULL)
		{
			ps->date= ptr;
			ps->capacity+= 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n ");
		}
	}
}
void addcontact(struct contact* ps)
{
	//检测当前通讯录的容量
	//1.如果满了，增加容量
	//如果没满，则无事发生
	checkcapacity(ps);
	printf("请输入姓名：");
	scanf("%s", ps->date[ps->size].name);
	printf("请输入年龄：");
	scanf("%d", &(ps->date[ps->size].age));
	printf("请输入性别：");
	scanf("%s", ps->date[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->date[ps->size].tele);
	printf("请输入地址：");
	scanf("%s", ps->date[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
}


//创建一个独立的查找函数，找到返回元素下标，找不到返回-1
static int findbyname(struct contact* ps,char name[MAX_NAME])
{
	int i;
	for(i=0;i<ps->size;i++)
	{
		if(strcmp(ps->date[i].name,name)==0)
		{
			return i;
		}
	}
	if(i== ps->size)
	{
		return -1;
	}
}
	
void delcontact(struct contact* ps)
{
	int j,pos;
	char name[MAX_NAME];
	printf("请输入要删除的名字\n");
	scanf("%s",name);
	pos=findbyname(ps,name);
	//for(i=0;i<ps->size;i++)
	//{
	//	if(strcmp(ps->date[i].name,name)==0)//////通过创建一个独立的查找函数来实现
	//	{
	//		break;
	//	}
	//}
	if(pos == -1)
		{
			printf("未查找到该联系人\n");
		}
	else
	{
		for(j=pos;j<ps->size-1;j++)
		{
			ps->date[j]=ps->date[j+1];
		}
			ps->size--;
			printf("删除成功\n");
	}
}

void searchcontact(struct contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("请输入要查找的名字\n");
	scanf("%s",name);
	pos = findbyname(ps,name);
	if(pos == -1)
	{
		printf("未查找到该好友\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->date[pos].name,
				ps->date[pos].age,
				ps->date[pos].sex,
				ps->date[pos].tele,
				ps->date[pos].addr);
	}
}

void modifycontact(struct contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("请输入要修改的名字");
	scanf("%s",name);
	pos = findbyname(ps,name);
	if(pos == -1)
	{
		printf("要修改的名字不存在\n");
	}
	else
	{
		printf("修改为：\n");
		printf("请输入姓名：");
		scanf("%s",ps->date[pos].name);
		printf("请输入年龄：");
		scanf("%d",&(ps->date[pos].age));
		printf("请输入性别：");
		scanf("%s",ps->date[pos].sex);
		printf("请输入电话：");
		scanf("%s",ps->date[pos].tele);
		printf("请输入地址：");
		scanf("%s",ps->date[pos].addr);
		printf("修改成功\n");
	}
}


void showcontact(const struct contact* ps)
{
	if(ps->size== 0)
	{
		printf("通讯录为空");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		for(i=0;i<ps->size;i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
}

static int cmpbyage(const void* e1,const void* e2)
{
	struct contact* c1 = (struct contact*)e1;
    struct contact* c2 = (struct contact*)e2;
	return c1->date->age - c2->date->age;
}

void sortcontact(struct contact* ps)
{
	qsort(ps->date,ps->size,sizeof(ps->date[0]),cmpbyage);
}

void destorycontact(struct contact* ps)
{
	free(ps->date);
	ps->date= NULL;
}