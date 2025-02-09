#define _CRT_SECURE_NO_WARRNINGS 1

#include"contact.h"

//存放1000个好友信息
//  名字
//	电话
//	性别
//	住址
//	年龄

//  增加好友信息
//  删除指定名字的好友信息
//  查找好友信息
//  修改好友信息
//  打印好友信息
//  排序


void menu()
{
	printf("****************************************\n");
	printf("********1.add           2.del   ********\n");
	printf("********3.search        4.modify********\n");
	printf("********5.show          6.sort  ********\n");
	printf("********0.leave                  ********\n");
	printf("****************************************\n");
}

int main()
{
	int input= 0;
	int size= 0;
	struct contact con;//里面包含date指针，size和capacity
	//初始化通讯录
	initcontact(&con);
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
			case add:
				addcontact(&con);
				break;
		    case del:
				delcontact(&con);
				break;
            case search:
				searchcontact(&con);
				break;
            case modify:
				modifycontact(&con);
				break;
            case show:
				showcontact(&con);
				break;
            case sort:
				sortcontact(&con);
				break;
            case leave:
				destorycontact(&con);
				printf("退出通讯录\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	}while(input);
	return 0;
}





