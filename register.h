#pragma once
#include "node.h"
mebr* rg(mebr* head){
    printf("请输入你的名字(小于10个字符)");
    char name1[10];
    scanf("%s",name1);
    getchar();
    printf("请输入你的账号(小于10个字符)");
    char username1[10];
    scanf("%s",username1);
    getchar();
    printf("请输入你的密码(小于10个字符)");
    char passwords1[10];
    scanf("%s",passwords1);
    getchar();
    head = newadd(head,name1,username1,passwords1,ping);
    savedata(head,"D:/ping.user.data");
    printf("管理员审批中\n");
    return head;
}
mebr* readdata(const char *ass){
    char name[50], username[50], passwords[50];
    sta sta;
    mebr* head =createm();
    FILE* fp =fopen(ass,"r");
    if(fp ==0)return head;
    while(fscanf(fp,"%s %s %s %d",name,username,passwords,&sta) == 4){
        head = newadd(head,name,username,passwords,sta);
    } 
    fclose(fp);
    return head;
}
int choice(){
    int num;
    printf("1.成员注册 2.成员登录 3.管理员登陆 4.社长登录 5.推出\n");
    scanf("%d",&num);
    return num;
}
void appr(mebr* pinghead){
    int count =0;
    mebr* applhead1 =createm();
    mebr* rejehead1 =createm();
    if(pinghead ->next == 0){
        printf("暂无人员需要审批\n");
        return;
    }
    while(pinghead->next){
        mebr*q = pinghead->next;
        count++;
        printf("第%d个待审批成员信息",count);
        printf("姓名：%s\n账号：%s\n密码：%s\n",q->name,q->username,q->passwords);
        printf("是否审批通过-------( 1 / 2 )");
        int ch;
        scanf("%d",&ch);
        if(ch == 1){
        applhead1 = newadd(applhead1,q->name,q->username,q->passwords,appl);
        if(q->next){
            pinghead->next =q->next;
            pinghead =pinghead->next;
            printf("%s已被通过",q->name);
        }
        free(q);
        pinghead ->next =0;
        }
        else if(ch ==2){
        rejehead1 = newadd(rejehead1,q->name,q->username,q->passwords,reje);
        if(q->next){
            pinghead->next =q->next;
            pinghead =pinghead->next;
            printf("%s同学已被拒绝",pinghead);
        }
        free(q);
        pinghead->next =0;
        }
    }
savedata(applhead1,"D:/appl.user.data");
savedata(rejehead1,"D:/reje.user,data");
savedata(pinghead,"D:/ping.user.data");
    }
int enty(){
    char usn[] ={"1"};
    char pas[] ={"1"};
    char usn1[10];
    char pas1[10];
    do{
        printf("请输入账号\n");
        scanf("%s",usn1);
        getchar();
        printf("请输入密码\n");
        scanf("%s",pas1);
        if(strcmp(usn1,usn) !=0)printf("账号错误\n");
        if(strcmp(pas1,pas) !=0)printf("密码错误\n");
    }while(strcmp(usn1,usn) !=0||strcmp(pas1,pas));
    printf("登陆成功\n");
    return 1;
}int choiceappr(){
    int n;
    printf("1.审批注册新成员 2.查看社团审批记录 3.查看社团活动 4.查看社团花费记录 5.注销社团");
    scanf("%d",&n);
    return n;
}
void record(mebr* applhead,mebr* rejehead){
    printf("以下同学已被拒绝\n");
    show(applhead);
    printf("以下同学已被同意\n");
    show(rejehead);
}
int mebrenty(mebr* applhead){
    char name[10];
    char usn1[10];
    char pas1[10];
    printf("请输入你的名字\n");
    scanf("%s",name);
    getchar();
    printf("请输入账号\n");
    scanf("%s",usn1);
    getchar();
    printf("请输入密码\n");
    scanf("%s",pas1);
    applhead =applhead->next;
    while(applhead){\
        int t1=0,t2 =0;
        if(strcmp(applhead->name,name) != 0){
            applhead =applhead->next;
        }
        else{
            if(strcmp(applhead->username,usn1) !=0){
                printf("账号错误\n");
            }
            else{
                t1 =1;
            }
            if(strcmp(applhead->passwords,pas1) !=0){
                printf("密码错误\n");
            }
            else{
                t2 =1;
            }
        }
        if(t1 ==1&&t2 ==1)return 1;
    }

}