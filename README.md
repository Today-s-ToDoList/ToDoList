# ToDoList
![lists-gdb937aa26_1920](https://user-images.githubusercontent.com/46621957/165875070-f9715647-c359-4897-858f-3656eb8cf99b.jpg)

### 프로젝트 주제
  오늘의 일정 관리 시스템
### 프로젝트 소개
  - 당일 일정을 적고 관리할 수 있는 프로그램
### 기능설명
  1. 구조체 : ToDoList
  2. 메뉴 : 아래 함수들을 메뉴로 출력하는 함수
  3. Create to do list : 일정 추가 (일정이름, 일정 시간, 중요도(1-3), 완료여부)
  4. Read to do list : 일정 목록 show (미완료 일정-중요도!=0 & 완료 일정 출력-중요도 0)
  5. Update to do list : 일정 수정 
  6. Delete to do list : 완료된 일정 체크(삭제)  : 완료된 일정의 중요도 0으로 설정
  7. 파일 load : 날짜 파일을 읽어오기
  8. 파일 save : 날짜 파일 저장
  9. 검색 : 날짜 검색
  10. 현재 시간  : 현재 시간 불러오는 함수 (당일 일정만)
  11. 남은 시간 계산 : 남은 시간 불러오는 함수 (당일 일정만)

### 개발환경 및 언어
  Visual Studio Code / C언어
  
### 팀소개 및 팀원이 맡은 역할
  22100478 윤은서 - 일정추가/일정수정 & 파일 불러오기 , 현재 시간 + 남은 시간 계산
  22100493 이다정 - 일정삭제/일정읽기/일정출력 & 파일 저장하기 , 날짜 검색함수, 메뉴
