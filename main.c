#include "ToDoList.h"

int main(void){
    ToDoList *t[100]; //포인터변수 선언
    int count = 0, menu;
    int num;

    count += loadData(t);

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1) {
            if(count > 0)
                listToDoList(t,count);
            else   
                printf("데이터가 없습니다.\n");
        }
        else if (menu == 2) {
            t[count] = (ToDoList *)malloc(sizeof(ToDoList)); //메모리 동적할당
            count += createToDoList(t[count]);
            printf("=> 추가됨!\n");
        }
        else if (menu == 3) {
            num = selectDataNo(t,count);
            if(num == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateToDoList(t[num-1]);
        }
        else if (menu == 4) {
            num = selectDataNo(t,count);
            if(num == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(t[num-1]) free(t[num-1]); //동적할당 해제
                t[num-1] = NULL; //포인터 해제
                printf("=> 삭제됨!\n");
            }
        }
        else if (menu == 5) {
            searchToDoList(t, count);
        }
        else if (menu == 6) {
            saveData(t,count);
            printf("=> 저장됨!\n\n");
        }
        else if (menu == 7) {
            // 날짜 계산 함수
        }
    }
    printf("종료됨!\n");
    return 0;
}
