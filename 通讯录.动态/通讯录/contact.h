#define _CRT_SECURE_NO_WARRNINGS 1

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_SZ 3

#include<string.h>

#include <stdio.h>

#include<stdlib.h>

struct popinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

void initcontact(struct contact* ps);

//ͨѶ¼����
struct contact
{
	struct popinfo *date;//���һ����Ϣ
	int size;//��¼��ǰ�е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼���������
};

enum option
{
	leave,
	add,
	del,
	search,
	modify,
	show,
	sort,
};

//����һ����Ϣ
void addcontact(struct contact* ps);

//ɾ��һ����Ϣ
void delcontact(struct contact* ps);

//��ʾ������Ϣ
void showcontact(const struct contact* ps);

//������Ϣ
void searchcontact(struct contact* ps);

//�޸���Ϣ
void modifycontact(struct contact* ps);

//������Ϣ
void sortcontact(struct contact* ps);

//����ͨѶ¼
void destorycontact(struct contact* ps);