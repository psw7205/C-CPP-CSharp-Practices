#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structList.h"
#include "functionList.h"

int main()
{
	INFO info[64];
	NODE *cinema = initCinema();
	VIEW view;
	int menu, menu2, num = 0;
	char ch;
	initView(&view);

	printf("���� ������ �ҷ����ðڽ��ϱ�? (Y/N) ");
	scanf("%c", &ch);
	if (ch == 'Y')
		fileLoad(info, &view, &num);

	while (1)
	{
		printf("\n������ȭ�� ���� �ý����Դϴ�.\n");
		printf("[1.����] [2.��ȸ] [3.�������] [4.����]\n");
		printf("��ȣ�� �Է��ϼ��� : ");
		scanf("%d", &menu);
		getchar();

		if (menu == 4)
		{
			fileStore(&view, cinema, info, &num);
			break;
		}

		switch (menu)
		{
		case 1:
			reservation(&view, info, cinema, &num);
			break;
		case 2:
			printf("��ȸ-> [1.��ü ��ȸ] [2.�̸� �� ��ȸ]\n");
			printf("��ȣ�� �Է��ϼ��� : ");

			scanf("%d", &menu2);
			getchar();

			switch (menu2)
			{
			case 1:
				printCinema(&view, cinema);
				break;
			case 2:
				sortByName(info, &num);
				printInfo(info, &num);
				break;
			default:
				break;
			}
			break;
		case 3:
			printf("������ �̸��� �Է��ϼ��� : ");
			deleteList(&view, info, &num);
			break;
		default:
			printf("�߸��� �޴��Դϴ�. �ٽ� �Է��ϼ���\n");
			while (getchar() != '\n');
			break;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		NODE *tmp = cinema;
		cinema = cinema->next;
		free(tmp);
	}
	
	return 0;
}