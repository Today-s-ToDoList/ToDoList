#include "ToDoList.c"

int main(void) {
    ToDoList *t[100]; //�����ͺ��� ����
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
                printf("�����Ͱ� �����ϴ�.\n");
        }
        else if (menu == 2) {
            t[count] = (ToDoList *)malloc(sizeof(ToDoList)); //�޸� �����Ҵ�
            count += createToDoList(t[count]);
            printf("=> �߰���!\n");
        }
        else if (menu == 3) {
            num = selectDataNo(t,count);
            if(num == 0) {
                printf("=> ��ҵ�!\n");
                continue;
            }
            updateToDoList(t[num-1]);
        }
        else if (menu == 4) {
            num = selectDataNo(t,count);
            if(num == 0) {
                printf("=> ��ҵ�!\n");
                continue;
            }
            int deleteok;
            printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(t[num-1]) free(t[num-1]); //�����Ҵ� ����
                t[num-1] = NULL; //������ ����
                printf("=> ������!\n");
            }
        }
        else if (menu == 5) {
            searchToDoList(t, count);
        }
        else if (menu == 6) {
            saveData(t,count);
            printf("=> �����!\n\n");
        }
        else if (menu == 7) {
            struct tm *t = currentTime(t[num-1]);
            //restTimeCal(t[num-1]);
            printf("���� �ð� : %d�� %d��\n", t->tm_hour, t->tm_min);
            // ��¥ ��� �Լ�
        }
    }
    printf("�����!\n");
    return 0;
}
