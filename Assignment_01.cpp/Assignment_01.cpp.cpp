// 스타터 20조 김종원 1번 과제 (상태창 구현)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;

	return;
}

int main(void)
{
	enum Estatus
	{
		HP,
		MP,
		ATK,
		DEF
	};
	
	int status[4];
	status[HP] = 0;
	status[MP] = 0;
	status[ATK] = 0;
	status[DEF] = 0;

	int HPPotion;
	int MPPotion;

	setPotion(5, &HPPotion, &MPPotion);

	while(1)
	{
		printf("HP와 MP를 입력하세요 : ");
		scanf("%d %d", &status[HP],&status[MP]);
		printf("\n");
		if (status[HP] <= 50 || status[MP] <= 50)
		{
			printf("HP와 MP는 50을 초과해야 합니다.\n\n");
			continue;
		}
		break;
	};

	while (1)
	{
		printf("ATK와 DEF를 입력하세요 : ");
		scanf("%d %d", &status[ATK], &status[DEF]);
		printf("\n");
		if (status[ATK] <= 0 || status[DEF] <= 0)
		{
			printf("ATK와 DEF는 0을 초과해야 합니다.\n\n");
			continue;
		}
		break;
	}

	int menu;

	while (1)
	{
		printf("[1]HP UP [2]MP UP [3]ATK UP [4]DEF UP [5]현재 능력치 [6]Level UP [0]나가기\n\n실행할 메뉴의 숫자를 입력하세요 : ");
		scanf("%d", &menu);
		printf("\n");

		switch (menu)
		{
		case 1:
			if (HPPotion <= 0)
			{
				printf("사용할 수 없습니다.\nHP Potion이 없습니다.\n\n");
				break;
			}

			status[HP] += 20;
			HPPotion--;
			printf("HP Potion을 1개 사용하였습니다.\n HP 20증가 / 남은 수량 %d개\n\n", HPPotion);
			break;
		
		case 2:
			if (MPPotion <= 0)
			{
				printf("사용할 수 없습니다.\nMP Potion이 없습니다.\n\n");
				break;
			}
			status[MP] += 20;
			MPPotion--;
			printf("MP Potion을 1개 사용하였습니다.\n MP 20증가 / 남은 수량 %d개\n\n", MPPotion);
			break;

		case 3:
			status[ATK] *= 2;
			printf("공격력이 2배가 되었습니다.\n\n");
			break;

		case 4:
			status[DEF] *= 2;
			printf("방어력이 2배가 되었습니다.\n\n");
			break;

		case 5:
			printf("[현재 능력치]\n");
			printf("HP : %d ", status[HP]);
			printf("MP : %d ", status[MP]);
			printf("ATK : %d ", status[ATK]);
			printf("DEF : %d\n\n", status[DEF]);

			break;

		case 6:
			HPPotion += 1;
			MPPotion += 1;
			printf("[Level UP]\nHP,MP 포션을 각 1개씩 획득합니다.\n");
			printf("HP Potion 수량 : %d개 ", HPPotion);
			printf("MP Potion 수량 : %d개\n\n", MPPotion);
			break;

		case 0:
			return 0;

		}

	}

	return 0;
}
