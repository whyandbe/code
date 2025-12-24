#pragma once
#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"
#include "string.h"
#include "auth.h"
char namenow[10];
typedef enum {
    ping,
    appl,
    reje
}sta;
typedef struct m {
    char name[10];
    char username[10];
    char passwords[10];
    sta sta;
    struct m* next;
}mebr;
typedef struct activmebr{
    char name[10];
    struct activmebr* next;
}am;
typedef struct a{
    char name[10];
    am* head;
}activ;
mebr* newm1(char name[10], char username[10], char passwords[10], sta sta) {
    mebr* newm = (mebr*)malloc(sizeof(mebr));
    if (!newm) {
        printf("malloc failed");
        return NULL;
    }
    strcpy(newm->name, name);
    strcpy(newm->username, username);
    strcpy(newm->passwords, passwords);
    newm->sta = sta;
    newm->next = NULL;
    return newm;
}
mebr* createm() {
    mebr* head = (mebr*)malloc(sizeof(mebr));
    memset(head, 0, sizeof(mebr));
    head->next = 0;
    return head;
}
mebr* newadd(mebr* head, char name[10], char username[10], char passwords[10], sta sta) {
    mebr* list = newm1(name, username, passwords, sta);
    mebr* tial = (mebr*)malloc(sizeof(mebr));
    tial =head;
    while(tial->next){
        tial =tial ->next;
    }
    if (tial) {
        tial ->next =list;
    }
    return head;
}
void savedata(mebr* head, const char* ass) {
    FILE* fp = fopen(ass, "w");
    head = head->next;
    while (head) {
        fprintf(fp, "%s %s %s %d ", head->name, head->username, head->passwords, head->sta);
        head = head->next;
    }
    fclose(fp);
}
void show(mebr* head) {
    head=head->next;
    while (head != 0) {
        printf("%s\n", head->name);
        head = head->next;
    }
}
mebr* readdata(const char* ass) {
    char name[50], username[50], passwords[50];
    sta sta;
    mebr* head = createm();
    FILE* fp = fopen(ass, "r");
    if (fp == 0)return head;
    while (fscanf(fp, "%s %s %s %d", name, username, passwords, &sta) == 4) {
        head = newadd(head, name, username, passwords, sta);
    }
    fclose(fp);
    return head;
}
mebr* pinghead = readdata("D:/ping.user.data");
mebr* applhead = readdata("D:/appl.user.data");
mebr* rejehead = readdata("D:/reje.user.data");
void appr(mebr* pinghead) {
    int count = 0;
    if (pinghead->next == 0) {
        printf("暂无人员需要审批\n");
        return;
    }
    mebr* q =pinghead->next;
    while (q) {
        count++;
        printf("第%d个待审批成员信息", count);
        printf("姓名：%s\n账号：%s\n密码：%s\n", q->name, q->username, q->passwords);
        printf("是否审批通过-------( 1 / 2 )\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 1) {
            applhead = newadd(applhead, q->name, q->username, q->passwords, appl);
            if (q->next) {
                q = q->next;
                printf("%s已被通过\n", q->name);
            }
            else{
                pinghead->next = 0;
                break;
            }
        }
        else if (ch == 2) {
            rejehead = newadd(rejehead, q->name, q->username, q->passwords, reje);
            if (q->next) {
                q = q->next;
                printf("%s同学已被拒绝", pinghead);
            }
            else{
                pinghead->next = 0;
                break;
            }
        }
    }
    free(q);
    savedata(applhead, "D:/appl.user.data");
    savedata(rejehead, "D:/reje.user.data");
    savedata(pinghead, "D:/ping.user.data");
}
void record(mebr* applhead, mebr* rejehead) {
    if(applhead->next){
        printf("以下同学已被同意\n");
        show(applhead);
    }
    if(rejehead->next){
        printf("以下同学已被拒绝\n");
        show(rejehead);
    }
}
void savei(int i){
    FILE* fp = fopen("D:/i","w");
    fprintf(fp,"%d",i);
    fclose(fp);
}
int readi(){
    int i;
    FILE* fp = fopen("D:/i","r");
    if(fp == 0)return -1;
    if(fscanf(fp,"%d",&i) == 0)return -1;
    fclose(fp);
    return i;
}
void saveacti(activ acti[],int i){
    FILE* fp =fopen("D:/newact","w");
    for(int j=0;j<i;j++){
        fprintf(fp,"%s ",acti[j].name);
        am* head = acti[j].head;
        if(head->next){
            head = head->next;
            while(head){
                fprintf(fp,"%s ",head->name);
                head =head->next;
            }
            }
    }
    fclose(fp);
}
void createacti(activ a[],int i){
    for(int j=0;j<=i;j++){
        a[j].head= (am*)malloc(sizeof(am));
        memset(a[j].head,0,sizeof(am));
        a[j].head->next =0;
    }
}
void readacti(activ acti[],int i){
    FILE* fp =fopen("D:/newact","r");
    createacti(acti,i);
    if(fp ==0)return;
    for(int j=0;j<=i;j++){
        char name[10];
        if(fscanf(fp,"%s",acti[j].name)==1){
            am* new1 =acti[j].head;
            while(fscanf(fp,"%s",name) ==1){
                am* newhead =(am*)malloc(sizeof(am));
                strcpy(newhead->name,name);
                am* tial = (am*)malloc(sizeof(am));
                if(acti[j].head->next == 0){
                    tial = newhead;
                    acti[j].head->next = newhead;
                    tial  = newhead;
                }
                else{
                    tial ->next =newhead;
                    tial = newhead;
                }
            }
            acti[j].head =new1;
        }

    }
    fclose(fp);
}
activ newact(){
    activ a;
    printf("请输入活动名\n");
    scanf("%s",a.name);
    a.head = (am*)malloc(sizeof(am));
    a.head->next =0;
    return a;
}
void newactc(activ acti[],int i){
    if(readi() ==-1)i=0;
    acti[i] = newact();
    i++;
    savei(i);
    saveacti(acti,i);
}
activ newactimebr(activ a[],int j){
    am* newone =(am*)malloc(sizeof(am));
    am* tial = a[j].head;
    strcpy(newone->name,namenow);
    if(a[j].head->next == 0){
        a[j].head->next =newone;
    }
    else{
        while(tial->next){
            tial =tial->next;
        }
        tial ->next =newone;
        tial = newone;
    }
    return a[j];
}