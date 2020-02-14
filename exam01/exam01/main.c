/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
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

// 메인함수
int main(void) 
{
    int input = 0;
    int num = 0;

    char* m_name = NULL;
    char* m_number = NULL;
    char* m_email = NULL;

    while (1) {

        printf("1.입력\t2.수정\t3.삭제\t4.전체출력  5.검색\t6.종료 : ");
        scanf("%d", &input);

        fgetc(stdin);

        switch (input)
        {   
        case INSERT: {
            printf("이름을 입력하세요 : ");
            gets(&m_name);            
            printf("전화번호를 입력하세요 : ");
            gets(&m_number);           
            printf("이메일을 입력하세요 : ");
            gets(&m_email);
            
            input_business_card(&m_name, &m_number, &m_email);
        }
        break;
        case EDIT: {
            printf("검색할 명함번호를 입력하세요 : ");
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
                printf("검색할 정보가 없습니다.\n");
                break;
            }

            printf("검색할 명함번호를 입력하세요 : ");
            scanf("%d", &num);

            search_business_card(num);
        }
        break;
        case END: {
            printf("\n종료합니다.\n");
            return;
        }
        default:
            printf("잘못된 입력입니다.\n");
        break;
        }
        printf("\n");
    }
	system("pause");
	return EXIT_SUCCESS;
}

void input_business_card(char* i_name, char* i_number, char* i_email) {

    if (cardnumber >= 50) {
        printf("더 이상 추가할 수 없습니다.\n");
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
    printf("수정할 전화번호 입력 : ");
    gets(&e_num);
    printf("수정할 이메일 입력 : ");
    gets(&e_email);

    bc_data[num].number = e_num;
    bc_data[num].email = e_email;
}

void show_all_cards(s_data *show_data) {

    if (cardnumber == 0) {
        printf("출력할 정보가 없습니다.\n");
        return;
    }

    for (int i = 1; i <= cardnumber; i++) {
        printf("명함번호 : %d / 한글 이름 : %s / 폰번호 : %s / 이메일 : %s\n"
            , i, (show_data +i)->name, (show_data + i)->number, (show_data + i)->email);
    }
}

void search_business_card(int num) {

    if (num > cardnumber || num < 0) {
        printf("정보가 없습니다.\n");
        return;
    }

    s_data* show_data = bc_data;

    printf("명함번호 : %d / 한글 이름 : %s / 폰번호 : %s / 이메일 : %s\n"
        , num, (show_data + num)->name, (show_data + num)->number, (show_data + num)->email);

    system("pause");
}

