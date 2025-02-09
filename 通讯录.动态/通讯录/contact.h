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

//通讯录类型
struct contact
{
	struct popinfo *date;//存放一个信息
	int size;//记录当前有的元素个数
	int capacity;//当前通讯录的最大容量
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

//增加一个信息
void addcontact(struct contact* ps);

//删除一个信息
void delcontact(struct contact* ps);

//显示所有信息
void showcontact(const struct contact* ps);

//查找信息
void searchcontact(struct contact* ps);

//修改信息
void modifycontact(struct contact* ps);

//排序信息
void sortcontact(struct contact* ps);

//销毁通讯录
void destorycontact(struct contact* ps);