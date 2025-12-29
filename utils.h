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
    int need;
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
        int ret =scanf("%d", &ch);
        while(ret !=1){
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n');
            ret =scanf("%d", &ch);
        }
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
        fprintf(fp,"%d ",acti[j].need);
        am* head = acti[j].head;
        if(head->next){
            head = head->next;
            while(head){
                fprintf(fp,"%s ",head->name);
                head =head->next;
            }
            }
            fprintf(fp,"//end// ");
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
    char end[] = {"//end//"};
    createacti(acti,i);
    if(fp ==0)return;
    for(int j=0;j<=i;j++){
        char name[10];
        int need;
        am* tial = acti[j].head;
        if(fscanf(fp,"%s",acti[j].name)==1&&fscanf(fp,"%d",&acti[j].need)==1){
            while(fscanf(fp,"%s",name) ==1){
                if(strcmp(end,name) ==0)break;
                am* newhead =(am*)malloc(sizeof(am));
                strcpy(newhead->name,name);
                    tial ->next =newhead;
                    tial = newhead;
            }
        }
        tial->next =0;
    }
    fclose(fp);
}
void newactc(activ a[],int i){
    if(readi() ==-1)i=0;
    printf("请输入活动名\n");
    scanf("%s",a[i].name);
    i++;
    savei(i);
    saveacti(a,i);
}
am* newactimebr(activ a[],int j){
    am* newone =(am*)malloc(sizeof(am));
    newone ->next =0;
    am* tial = a[j].head;
    strcpy(newone->name,namenow);
    if(a[j].head->next == 0){
        a[j].head->next =newone;
    }
    else{
        while(tial->next != 0){
            tial =tial->next;
        }
        tial ->next =newone;
    }
    return a[j].head;
}
void savemoney(int money){
    FILE* fp =fopen("D:/money","w");
    fprintf(fp,"%d",money);
    fclose(fp);
}
int readmoney(){
    int money;
    FILE* fp =fopen("D:/money","r");
    fscanf(fp,"%d",&money);
    fclose(fp);
    return money;
}
void applymoney(){
    int wants;
    printf("请输入要申请的经费\n");
    int ret = scanf("%d",&wants);
    while(ret !=1){
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n');
            ret =scanf("%d", &wants);
        }
    FILE* fp =fopen("D:/applymoney","w");
    fprintf(fp,"%d",wants);
    fclose(fp);
    printf("%d元正在审批中\n",wants);
}
int apprmoney(int money){
    while(1){
        int ch;
        int addmoney;
        FILE* fp =fopen("D:/applymoney","r");
        fscanf(fp,"%d",&addmoney);
        fclose(fp);
        if(addmoney == 0){
            printf("暂无经费需要审批\n");
            FILE* fp =fopen("D:/applymoney","w");
            fprintf(fp,"%d",0);
            fclose(fp);
            return money;
        }
        while(1){
        printf("社长申请了%d元\n是否同意-----(1/2)\n",addmoney);
        int ret = scanf("%d",&ch);
        if(ret == 1&&(ch == 1||ch == 2))return ch;
        else{
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n');
        }
        }
        if(ch == 2){
            FILE* fp =fopen("D:/applymoney","w");
            fprintf(fp,"%d",0);
            fclose(fp);
            FILE* Fp = fopen("D:/said","w");
            fprintf(Fp,"%s","被管理员驳回了\n");
            fclose(Fp);
            return 0;
        }
        else if(ch == 1){
            FILE* fp =fopen("D:/applymoney","w");
            fprintf(fp,"%d",0);
            fclose(fp);
            return money+addmoney;
        }
        else{
            printf("请重新输入(1/2)\n");
        }
    }
}
void readsaid(){
    char said[100];
    FILE* fp =fopen("D:/said","r");
    if(fscanf(fp,"%s",said) == 1){
        printf("%s\n",said);
    }
    fclose(fp);
}
int actimoney(activ a[],int i,int* money){
     while(1){
        printf("请输入活动要花费的经费\n");
        int ret = scanf("%d",&a[i].need);
        if(ret == 1){
            if(a[i].need>*money){
            printf("该活动要求%d\n经费不足\n",a[i].need);
            return 0;
        }
        else{
            printf("活动花费%d元",a[i].need);
            *money -= a[i].need;
            return 1;
        }
    savemoney(*money);
        }
        else{
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n');
        }
        }
}
void costrecord(activ a[],int i){
    if(i == 0){
        printf("暂无花费记录\n");
        return;
    }
    for(int j=0;j<i;j++){
       printf("%s : -%d\n",a[j].name,a[j].need); 
    }
}
void cleanall(){
    FILE* fp = fopen("D:/applymoney","w");
    fclose(fp);
    FILE* fp1 = fopen("D:/ping.user.data","w");
    fclose(fp1);
    FILE* fp2 = fopen("D:/reje.user.data","w");
    fclose(fp2);
    FILE* fp3 = fopen("D:/appl.user.data","w");
    fclose(fp3);
    FILE* fp4 = fopen("D:/newact","w");
    fclose(fp4);
    FILE* fp5 = fopen("D:/i","w");
    fclose(fp5);
    FILE* fp6 = fopen("D:/money","w");
    fclose(fp6);
    FILE* fp7 = fopen("D:/said","w");
    fclose(fp7);
    printf("已全部清除\n");
}
void freelistmebr(mebr* a){
    while(a){
        mebr* head = a;
        a =a->next;
        free(head);
    }
}
void freelistacti(am* a){
    while(a){
        am* head = a;
        a =a->next;
        free(head);
    }
}
void freeall(mebr* a,mebr* b,mebr* c,activ d[],int i){
    freelistmebr(a);
    freelistmebr(b);
    freelistmebr(c);
    for(int j =0;j<i;j++){
        freelistacti(d[j].head);
    }
}