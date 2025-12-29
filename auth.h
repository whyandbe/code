#pragma once
#include "utils.h"
mebr* rg(mebr* head) {
    printf("请输入你的名字(小于10个字符)");
    char name1[10];
    scanf("%s", name1);
    getchar();
    printf("请输入你的账号(小于10个字符)");
    char username1[10];
    scanf("%s", username1);
    getchar();
    printf("请输入你的密码(小于10个字符)");
    char passwords1[10];
    scanf("%s", passwords1);
    getchar();
    head = newadd(head, name1, username1, passwords1, ping);
    savedata(head, "D:/ping.user.data");
    printf("管理员审批中\n");
    return head;
}
int choice() {
    int n;
    while(1){
        printf("1.成员注册 2.成员登录 3.管理员登陆 4.社长登录 5.退出 6.清空全部数据\n");
        int ret = scanf("%d", &n);
        if(ret == 1)return n;
        else if(ret == 0){
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n'){}
    }
}
}
int enty() {
    char usn[] = { "1" };
    char pas[] = { "1" };
    char usn1[10];
    char pas1[10];
    do {
        printf("请输入账号\n");
        scanf("%s", usn1);
        getchar();
        printf("请输入密码\n");
        scanf("%s", pas1);
        if (strcmp(usn1, usn) != 0)printf("账号错误\n");
        if (strcmp(pas1, pas) != 0)printf("密码错误\n");
    } while (strcmp(usn1, usn) != 0 || strcmp(pas1, pas));
    printf("登陆成功\n");
    return 1;
}
int mebrenty(mebr* applhead) {
    char usn1[10];
    char pas1[10];
    if(applhead ->next  == 0){
        printf("社团暂无成员，请注册\n");
        return 0; 
      }
    applhead = applhead->next;
    while (applhead) {
        int f =0;
        int t1 = 0, t2 = 0;
        printf("请输入你的名字\n");
        scanf("%s", namenow);
        getchar();
        printf("请输入账号\n");
        scanf("%s", usn1);
        getchar();
        printf("请输入密码\n");
        scanf("%s", pas1);
        while(strcmp(applhead->username, namenow) != 0&&applhead->next !=0){
            applhead =applhead->next;
        }
            if (strcmp(applhead->username, usn1) != 0) {
                printf("账号错误\n");
            }
            else {
                t1 = 1;
            }
            if (strcmp(applhead->passwords, pas1) != 0) {
                printf("密码错误\n");
            }
            else {
                t2 = 1;
            }
            if (t1 == 1 && t2 == 1)return 1;
        }
    }
int presenty(){
    char usn1[10] = {"1"};
    char pas1[10] = {"1"};
    char usn[10];
    char pas[10];
    while(1){
        printf("请输入您的账号\n");
        scanf("%9s",usn);
        getchar();
        printf("请输入您的密码\n");
        scanf("%9s",pas);
        int r1 = strcmp(usn1,usn);
        int r2 = strcmp(pas1,pas);
        if(r1 == 0&&r2 == 0)return 1;
        if(r1 != 0)printf("您非社长,请选择其他方式登录\n");
        if(r2 != 0)printf("密码错误\n");
    }
}
int ensure(){
    int n;
    while(1){
        printf("你确定吗?(0/1)\n");
        int ret = scanf("%d", &n);
        if(ret == 1)return n;
        else if(ret == 0){
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n'){}
    }
}
}