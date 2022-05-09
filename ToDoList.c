#include "ToDoList.h"

//22100478 윤은서 - 일정추가/일정수정

int createToDoList(ToDoList *t) { //일정추가 (일정 이름, 일정 시간, 중요도(1-3))
    getchar();
    printf("일정 이름은? ");
    fgets(t->Todo,MAX-1,stdin);
    t->Todo[strlen(t->Todo)-1]='\0';
    printf("일정 시간은? ");
    fgets(t->time,MAX-1,stdin);
    t->time[strlen(t->time)-1]='\0';
    printf("중요도는?(1-3) ");
    scanf("%d", &t->impo);
    t->end=0;
    printf("=> 추가됨!\n");
    return 1;
}
int updateToDoList(ToDoList *t) { //일정수정 (일정 이름, 일정 시간, 중요도(1-3))
    printf("일정 이름은? ");
    getchar();
    fgets(t->Todo,MAX-1,stdin);
    t->Todo[strlen(t->Todo)-1]='\0';
    printf("일정 시간은? ");
    fgets(t->time,MAX-1,stdin);
    t->time[strlen(t->time)-1]='\0';
    printf("중요도는?(1-3) ");
    scanf("%d", &t->impo);
    printf("=> 수정성공!\n");
    return 1;
}

// 22100493 이다정 - 일정삭제/일정읽기 & 파일 저장하기 , 날짜 검색함수, 메뉴

int readToDoList(ToDoList t) { // 일정 목록 show (미완료 일정-중요도!=0 & 완료 일정 출력-중요도 0)
    printf("%s  %s  %d",t.Todo,t.time,t.impo);
    if(t.end == 1) printf(" 완료\n");
    else printf(" 미완료 \n");
    return 0;
}

int listToDoList(ToDoList *t[], int count){ // 전체 등록된 제품 리스트 출력
    printf("%-15s %-5s %-5s %-5s\n","할 일", "기한", "중요도", "완료여부");
    printf("---------------------------------------------------------------------------------\n");
    for(int i=0;i<count;i++)
    {
        if(t[i]==NULL) continue;
        printf("%2d ",i+1);
        readToDoList(*t[i]);
    }
    return 0;
}

int deleteToDoList(ToDoList *t[], int count){ // 완료된 일정 체크(삭제)  : 완료된 일정의 중요도 0으로 설정
    int num;
    listToDoList(t, count);
    printf("몇번을 삭제하시겠습니까? (취소:0)? ");  //삭제할 제품 번호 묻기
    scanf("%d",&num);

    //삭제 취소
    if(num == 0) {
        printf("=> 취소됨!\n");
        return 0;
    }
    int deleteok;
    printf("정말로 삭제하시겠습니까?(삭제 :1)");
    scanf("%d",&deleteok);
    //삭제 진행
    if(deleteok == 1){
        t[num-1]->impo=0;
        t[num-1]->end=1;
        // if(t[num-1]) free(t[num-1]);
        // t[num-1] = NULL;
        // count--;
        printf("=> 삭제됨!\n");
    }
    return 0;
}

void searchToDoList(ToDoList *t[], int count){ //할 일 검색
    int scnt =0, num;
    char search[MAX];

    printf("검색하고 싶은 메뉴는?(1.할 일 제목 2.기한, 3.중요도 4.완료여부) "); //제품검색할 방법 묻기
    scanf("%d",&num);

    //1. 할 일 제목으로 검색
    if(num==1){
        printf("검색하고 싶은 할 일의 제목은? ");
        getchar();
        fgets(search,MAX-1,stdin);

        printf("%s %s %s %s\n","할 일", "기한", "중요도", "완료여부");
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

    //2. 할 일의 기한으로 검색
    else if(num==2){
        printf("검색하고 싶은 할 일의 기한은? ");
        getchar();
        fgets(search,MAX-1,stdin);

        printf("%s %s %s %s\n","할 일", "기한", "중요도", "완료여부");
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
    // 할 일의 중요도로 검색
    else if(num==3){
        printf("검색하고 싶은 할 일의 중요도는? ");
        scanf("%d",&num);

        printf("%s %s %s %s\n","할 일", "기한", "중요도", "완료여부");
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
    //4. 완료여부로 검색
    else if(num==4){
        printf("검색하고 싶은 할 일의 완료여부는?(미완료:1,완료:2) ");
        scanf("%d",&num);

        printf("%s %s %s %s\n","할 일", "기한", "중요도", "완료여부");
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
    if(scnt==0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void saveData(ToDoList *t[],int count){ // 날짜 파일 저장
    FILE *fp = fopen("TodoList.txt","wt");

    for(int i=0;i<count;i++){
        if(t[i]==NULL) continue;
        fprintf(fp, "%s;%s;%d;%d;",t[i]->Todo,t[i]->time,t[i]->impo,t[i]->end);
    }
    fclose(fp);
    printf("==> 저장됨!\n\n");
}

int selectMenu(){ // 메뉴 : 아래 함수들을 메뉴로 출력하는 함수
    int menu;
    printf("\n*** TO DO LIST ***\n");
    printf("1. 오늘의 할 일 조회\n");
    printf("2. 할 일 추가\n");
    printf("3. 할 일 수정\n");
    printf("4. 할 일 삭제\n");
    printf("5. 할 일 검색\n");
    printf("6. 할 일 목록 파일에 저장\n");
    printf("7. 할 일 시간 계산 (당일)\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
int selectDataNo(ToDoList *t[], int count){
    int num;

    listToDoList(t,count);
    printf("번호는 (취소:0)? ");
    scanf("%d",&num);
    return num;
}

//  22100478 윤은서 - 일정추가/일정수정 & 파일 불러오기 , 현재 시간 + 남은 시간 계산

int loadData(ToDoList *t[]){
    char *ptr;
    char str[256];
    int count=0;
    FILE *fp = fopen("TodoList.txt","rt");

    if(fp==NULL) {
        printf("==> 파일 없음! \n\n");
        return 0;
    }

    while(!feof(fp)){
        fgets(str,255,fp);
        
        t[count] = (ToDoList *)malloc(sizeof(ToDoList)); //메모리 동적할당

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

    printf("==> 로딩 완료! \n\n");
    return count;
}

struct tm *currentTime() {
    time_t timer;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    struct tm *time = localtime(&timer);
    return time;
}
/*int restTimeCal(ToDoList *t) {
    rest_hour=24-tm.tm_hour;
    rest_min=60-tm-tm_min;
}*/
