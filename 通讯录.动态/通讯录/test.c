#define _CRT_SECURE_NO_WARRNINGS 1

#include"contact.h"

//���1000��������Ϣ
//  ����
//	�绰
//	�Ա�
//	סַ
//	����

//  ���Ӻ�����Ϣ
//  ɾ��ָ�����ֵĺ�����Ϣ
//  ���Һ�����Ϣ
//  �޸ĺ�����Ϣ
//  ��ӡ������Ϣ
//  ����


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
	struct contact con;//�������dateָ�룬size��capacity
	//��ʼ��ͨѶ¼
	initcontact(&con);
	do
	{
		menu();
		printf("��ѡ��");
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
				printf("�˳�ͨѶ¼\n");
				break;
			default:
				printf("ѡ�����\n");
				break;
		}
	}while(input);
	return 0;
}





