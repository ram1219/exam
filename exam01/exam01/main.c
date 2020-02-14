/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* name;
    char* number;
    char* email;
}s_data;

enum BCard {INSERT=1,EDIT,DELETE,PRINT,SEARCH,END};

void input_business_card(char* i_name, char* i_number, char* i_email);
void edit_business_card(int num);
void show_all_cards(s_data* show_data);
void search_business_card(int num);

int cardnumber = 0;
s_data bc_data[50] = { 0 };

// �����Լ�
int main(void) 
{
    int input = 0;
    int num = 0;

    char* m_name = NULL;
    char* m_number = NULL;
    char* m_email = NULL;

    while (1) {

        printf("1.�Է�\t2.����\t3.����\t4.��ü���  5.�˻�\t6.���� : ");
        scanf("%d", &input);

        fgetc(stdin);

        switch (input)
        {   
        case INSERT: {
            printf("�̸��� �Է��ϼ��� : ");
            gets(&m_name);            
            printf("��ȭ��ȣ�� �Է��ϼ��� : ");
            gets(&m_number);           
            printf("�̸����� �Է��ϼ��� : ");
            gets(&m_email);
            
            input_business_card(&m_name, &m_number, &m_email);
        }
        break;
        case EDIT: {
            printf("�˻��� ���Թ�ȣ�� �Է��ϼ��� : ");
            scanf("%d", &num);

            fgetc(stdin);

            edit_business_card(num);
        }
        break;
        case DELETE:
        break;
        case PRINT:
            show_all_cards(bc_data);
        break;
        case SEARCH: {
            if (cardnumber == 0) {
                printf("�˻��� ������ �����ϴ�.\n");
                break;
            }

            printf("�˻��� ���Թ�ȣ�� �Է��ϼ��� : ");
            scanf("%d", &num);

            search_business_card(num);
        }
        break;
        case END: {
            printf("\n�����մϴ�.\n");
            return;
        }
        default:
            printf("�߸��� �Է��Դϴ�.\n");
        break;
        }
        printf("\n");
    }
	system("pause");
	return EXIT_SUCCESS;
}

void input_business_card(char* i_name, char* i_number, char* i_email) {

    if (cardnumber >= 50) {
        printf("�� �̻� �߰��� �� �����ϴ�.\n");
        return;
    }

    cardnumber++;

    bc_data[cardnumber].name = i_name;
    bc_data[cardnumber].number = i_number;
    bc_data[cardnumber].email = i_email;

}

void edit_business_card(int num) {

    char* e_num = 0;
    char* e_email = 0;
    printf("������ ��ȭ��ȣ �Է� : ");
    gets(&e_num);
    printf("������ �̸��� �Է� : ");
    gets(&e_email);

    bc_data[num].number = e_num;
    bc_data[num].email = e_email;
}

void show_all_cards(s_data *show_data) {

    if (cardnumber == 0) {
        printf("����� ������ �����ϴ�.\n");
        return;
    }

    for (int i = 1; i <= cardnumber; i++) {
        printf("���Թ�ȣ : %d / �ѱ� �̸� : %s / ����ȣ : %s / �̸��� : %s\n"
            , i, (show_data +i)->name, (show_data + i)->number, (show_data + i)->email);
    }
}

void search_business_card(int num) {

    if (num > cardnumber || num < 0) {
        printf("������ �����ϴ�.\n");
        return;
    }

    s_data* show_data = bc_data;

    printf("���Թ�ȣ : %d / �ѱ� �̸� : %s / ����ȣ : %s / �̸��� : %s\n"
        , num, (show_data + num)->name, (show_data + num)->number, (show_data + num)->email);

    system("pause");
}

