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
		//��������
		struct popinfo* ptr= (struct popinfo*)realloc(ps->date,(ps->capacity+2)*sizeof(struct popinfo));
		if(ptr != NULL)
		{
			ps->date= ptr;
			ps->capacity+= 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n ");
		}
	}
}
void addcontact(struct contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1.������ˣ���������
	//���û���������·���
	checkcapacity(ps);
	printf("������������");
	scanf("%s", ps->date[ps->size].name);
	printf("���������䣺");
	scanf("%d", &(ps->date[ps->size].age));
	printf("�������Ա�");
	scanf("%s", ps->date[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->date[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->date[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n");
}


//����һ�������Ĳ��Һ������ҵ�����Ԫ���±꣬�Ҳ�������-1
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
	printf("������Ҫɾ��������\n");
	scanf("%s",name);
	pos=findbyname(ps,name);
	//for(i=0;i<ps->size;i++)
	//{
	//	if(strcmp(ps->date[i].name,name)==0)//////ͨ������һ�������Ĳ��Һ�����ʵ��
	//	{
	//		break;
	//	}
	//}
	if(pos == -1)
		{
			printf("δ���ҵ�����ϵ��\n");
		}
	else
	{
		for(j=pos;j<ps->size-1;j++)
		{
			ps->date[j]=ps->date[j+1];
		}
			ps->size--;
			printf("ɾ���ɹ�\n");
	}
}

void searchcontact(struct contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�����\n");
	scanf("%s",name);
	pos = findbyname(ps,name);
	if(pos == -1)
	{
		printf("δ���ҵ��ú���\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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
	printf("������Ҫ�޸ĵ�����");
	scanf("%s",name);
	pos = findbyname(ps,name);
	if(pos == -1)
	{
		printf("Ҫ�޸ĵ����ֲ�����\n");
	}
	else
	{
		printf("�޸�Ϊ��\n");
		printf("������������");
		scanf("%s",ps->date[pos].name);
		printf("���������䣺");
		scanf("%d",&(ps->date[pos].age));
		printf("�������Ա�");
		scanf("%s",ps->date[pos].sex);
		printf("������绰��");
		scanf("%s",ps->date[pos].tele);
		printf("�������ַ��");
		scanf("%s",ps->date[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}


void showcontact(const struct contact* ps)
{
	if(ps->size== 0)
	{
		printf("ͨѶ¼Ϊ��");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
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