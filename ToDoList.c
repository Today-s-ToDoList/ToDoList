#include "ToDoList.h"

//22100478 ������ - �����߰�/��������

int createToDoList(ToDoList *t) { //�����߰� (���� �̸�, ���� �ð�, �߿䵵(1-3))
    getchar();
    printf("���� �̸���? ");
    fgets(t->Todo,MAX-1,stdin);
    t->Todo[strlen(t->Todo)-1]='\0';
    printf("���� �ð���? ");
    fgets(t->time,MAX-1,stdin);
    t->time[strlen(t->time)-1]='\0';
    printf("�߿䵵��?(1-3) ");
    scanf("%d", &t->impo);
    t->end=0;
    printf("=> �߰���!\n");
    return 1;
}
int updateToDoList(ToDoList *t) { //�������� (���� �̸�, ���� �ð�, �߿䵵(1-3))
    printf("���� �̸���? ");
    getchar();
    fgets(t->Todo,MAX-1,stdin);
    t->Todo[strlen(t->Todo)-1]='\0';
    printf("���� �ð���? ");
    fgets(t->time,MAX-1,stdin);
    t->time[strlen(t->time)-1]='\0';
    printf("�߿䵵��?(1-3) ");
    scanf("%d", &t->impo);
    printf("=> ��������!\n");
    return 1;
}

// 22100493 �̴��� - ��������/�����б� & ���� �����ϱ� , ��¥ �˻��Լ�, �޴�

int readToDoList(ToDoList t) { // ���� ��� show (�̿Ϸ� ����-�߿䵵!=0 & �Ϸ� ���� ���-�߿䵵 0)
    printf("%s  %s  %d",t.Todo,t.time,t.impo);
    if(t.end == 1) printf(" �Ϸ�\n");
    else printf(" �̿Ϸ� \n");
    return 0;
}

int listToDoList(ToDoList *t[], int count){ // ��ü ��ϵ� ��ǰ ����Ʈ ���
    printf("%-15s %-5s %-5s %-5s\n","�� ��", "����", "�߿䵵", "�ϷῩ��");
    printf("---------------------------------------------------------------------------------\n");
    for(int i=0;i<count;i++)
    {
        if(t[i]==NULL) continue;
        printf("%2d ",i+1);
        readToDoList(*t[i]);
    }
    return 0;
}

int deleteToDoList(ToDoList *t[], int count){ // �Ϸ�� ���� üũ(����)  : �Ϸ�� ������ �߿䵵 0���� ����
    int num;
    listToDoList(t, count);
    printf("����� �����Ͻðڽ��ϱ�? (���:0)? ");  //������ ��ǰ ��ȣ ����
    scanf("%d",&num);

    //���� ���
    if(num == 0) {
        printf("=> ��ҵ�!\n");
        return 0;
    }
    int deleteok;
    printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
    scanf("%d",&deleteok);
    //���� ����
    if(deleteok == 1){
        t[num-1]->impo=0;
        t[num-1]->end=1;
        // if(t[num-1]) free(t[num-1]);
        // t[num-1] = NULL;
        // count--;
        printf("=> ������!\n");
    }
    return 0;
}

void searchToDoList(ToDoList *t[], int count){ //�� �� �˻�
    int scnt =0, num;
    char search[MAX];

    printf("�˻��ϰ� ���� �޴���?(1.�� �� ���� 2.����, 3.�߿䵵 4.�ϷῩ��) "); //��ǰ�˻��� ��� ����
    scanf("%d",&num);

    //1. �� �� �������� �˻�
    if(num==1){
        printf("�˻��ϰ� ���� �� ���� ������? ");
        getchar();
        fgets(search,MAX-1,stdin);

        printf("%s %s %s %s\n","�� ��", "����", "�߿䵵", "�ϷῩ��");
        printf("---------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(t[i]==NULL) continue;
            if(strstr(search,t[i]->Todo)) {
                printf("%2d ",i+1);
                readToDoList(*t[i]);
                scnt++;
            }
        }
    }

    //2. �� ���� �������� �˻�
    else if(num==2){
        printf("�˻��ϰ� ���� �� ���� ������? ");
        getchar();
        fgets(search,MAX-1,stdin);

        printf("%s %s %s %s\n","�� ��", "����", "�߿䵵", "�ϷῩ��");
        printf("---------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(t[i]==NULL) continue;
            if(strstr(search,t[i]->time)) {
                printf("%2d ",i+1);
                readToDoList(*t[i]);
                scnt++;
            }
        }
    }
    // �� ���� �߿䵵�� �˻�
    else if(num==3){
        printf("�˻��ϰ� ���� �� ���� �߿䵵��? ");
        scanf("%d",&num);

        printf("%s %s %s %s\n","�� ��", "����", "�߿䵵", "�ϷῩ��");
        printf("---------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(t[i]==NULL) continue;
            if(num==t[i]->impo) {
                printf("%2d ",i+1);
                readToDoList(*t[i]);
                scnt++;
            }
        }
    }
    //4. �ϷῩ�η� �˻�
    else if(num==4){
        printf("�˻��ϰ� ���� �� ���� �ϷῩ�δ�?(�̿Ϸ�:1,�Ϸ�:2) ");
        scanf("%d",&num);

        printf("%s %s %s %s\n","�� ��", "����", "�߿䵵", "�ϷῩ��");
        printf("---------------------------------------------\n");
        for(int i=0;i<count;i++)
        {
            if(t[i]==NULL) continue;
            if(num-1 == t[i]->end) {
                printf("%2d ",i+1);
                readToDoList(*t[i]);
                scnt++;
            }
        }
    }
    if(scnt==0) printf("=> �˻��� ������ ����!");
    printf("\n");
}

void saveData(ToDoList *t[],int count){ // ��¥ ���� ����
    FILE *fp = fopen("TodoList.txt","wt");

    for(int i=0;i<count;i++){
        if(t[i]==NULL) continue;
        fprintf(fp, "%s;%s;%d;%d;",t[i]->Todo,t[i]->time,t[i]->impo,t[i]->end);
    }
    fclose(fp);
    printf("==> �����!\n\n");
}

int selectMenu(){ // �޴� : �Ʒ� �Լ����� �޴��� ����ϴ� �Լ�
    int menu;
    printf("\n*** TO DO LIST ***\n");
    printf("1. ������ �� �� ��ȸ\n");
    printf("2. �� �� �߰�\n");
    printf("3. �� �� ����\n");
    printf("4. �� �� ����\n");
    printf("5. �� �� �˻�\n");
    printf("6. �� �� ��� ���Ͽ� ����\n");
    printf("7. �� �� �ð� ��� (����)\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}
int selectDataNo(ToDoList *t[], int count){
    int num;

    listToDoList(t,count);
    printf("��ȣ�� (���:0)? ");
    scanf("%d",&num);
    return num;
}

//  22100478 ������ - �����߰�/�������� & ���� �ҷ����� , ���� �ð� + ���� �ð� ���

int loadData(ToDoList *t[]){
    char *ptr;
    char str[256];
    int count=0;
    FILE *fp = fopen("TodoList.txt","rt");

    if(fp==NULL) {
        printf("==> ���� ����! \n\n");
        return 0;
    }

    while(!feof(fp)){
        fgets(str,255,fp);
        
        t[count] = (ToDoList *)malloc(sizeof(ToDoList)); //�޸� �����Ҵ�

        ptr = strtok(str,";");
        strcpy(t[count]->Todo,ptr);
        ptr = strtok(NULL,";");
        strcpy(t[count]->time,ptr);
        ptr = strtok(NULL,";");
        t[count]->impo = atoi(ptr);
        ptr = strtok(NULL,";");
        t[count]->end = atoi(ptr);
        ptr = strtok(NULL,";");
        count++;
    }
    fclose(fp);

    printf("==> �ε� �Ϸ�! \n\n");
    return count;
}

struct tm *currentTime() {
    time_t timer;
    timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
    struct tm *time = localtime(&timer);
    return time;
}
/*int restTimeCal(ToDoList *t) {
    rest_hour=24-tm.tm_hour;
    rest_min=60-tm-tm_min;
}*/
