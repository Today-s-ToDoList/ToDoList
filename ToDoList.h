#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 256

 typedef struct{
    char Todo[MAX-1];
    char time[MAX-1];
    int impo;
    int end;
 }ToDoList;

int createToDoList(ToDoList *t); // 일정 추가 (일정이름, 일정 시간, 중요도(1-3), 완료여부)
int readToDoList(ToDoList t); // 일정 목록 show (미완료 일정-중요도!=0 & 완료 일정 출력-중요도 0)
int listToDoList(ToDoList *t[], int count); // 전체 등록된 제품 리스트 출력
int updateToDoList(ToDoList *t); // 일정 수정
int deleteToDoList(ToDoList *t[], int count); // 완료된 일정 체크(삭제)  : 완료된 일정의 중요도 0으로 설정
void searchToDoList(ToDoList *t[], int count); // 제품이름 검색
void saveData(ToDoList *t[],int count); // 날짜 파일 저장
int loadData(ToDoList *t[]); // 날짜 파일을 읽어오기
int selectDataNo(ToDoList *t[], int count);
int selectMenu(); // 메뉴 : 아래 함수들을 메뉴로 출력하는 함수
struct tm *currentTime(); // 현재 시간  : 현재 시간 불러오는 함수
int restTimeCal(ToDoList *t); // 남은 시간 계산 : 남은 기한 불러오는 함수
