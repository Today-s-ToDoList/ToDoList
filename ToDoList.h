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

int createToDoList(ToDoList *t); // ���� �߰� (�����̸�, ���� �ð�, �߿䵵(1-3), �ϷῩ��)
int readToDoList(ToDoList t); // ���� ��� show (�̿Ϸ� ����-�߿䵵!=0 & �Ϸ� ���� ���-�߿䵵 0)
int listToDoList(ToDoList *t[], int count); // ��ü ��ϵ� ��ǰ ����Ʈ ���
int updateToDoList(ToDoList *t); // ���� ����
int deleteToDoList(ToDoList *t[], int count); // �Ϸ�� ���� üũ(����)  : �Ϸ�� ������ �߿䵵 0���� ����
void searchToDoList(ToDoList *t[], int count); // ��ǰ�̸� �˻�
void saveData(ToDoList *t[],int count); // ��¥ ���� ����
int loadData(ToDoList *t[]); // ��¥ ������ �о����
int selectDataNo(ToDoList *t[], int count);
int selectMenu(); // �޴� : �Ʒ� �Լ����� �޴��� ����ϴ� �Լ�
struct tm *currentTime(); // ���� �ð�  : ���� �ð� �ҷ����� �Լ�
int restTimeCal(ToDoList *t); // ���� �ð� ��� : ���� ���� �ҷ����� �Լ�
