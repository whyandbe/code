#pragma once
#include "auth.h"
#include "utils.h"
#include "stdio.h"
void showclub(mebr* applhead) {
    printf("社团创建于:2025.12.12\n");
    printf("社团管理员:administrator\n");
    printf("社长:president\n");
    printf("社团成员信息\n");
    show(applhead);
}
int choiceappr() {
    int n;
    while(1){
        printf("1.审批注册新成员 2.查看社团审批记录 3.查看社团活动\n 4.审批经费 5.查看社团花费记录 6. 导出财务表 7.注销社团 8.退出登录\n");
        int ret = scanf("%d", &n);
        if(ret == 1)return n;
        else if(ret == 0){
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n'){}
    }
}
}
int choicemebr() {
    int n;
    while(1){
        printf("1.查看社团信息 2.查看个人信息 3.参加报名活动 4.退出登录\nn");
        int ret = scanf("%d", &n);
        if(ret == 1)return n;
        else if(ret == 0){
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n'){}
    }
}
}
int choicepres(){
    int n;
    while(1){
        printf("1.查看社团信息 2.查看个人信息 3.发布活动\n4.查看社团花费记录 5.申请社团经费 6.查看经费\n7.退出登录\n");
        int ret = scanf("%d", &n);
        if(ret == 1)return n;
        else if(ret == 0){
            printf("输入错误，请重新输入\n");
            while(getchar() != '\n'){}
    }
}
}
void ifmtpres(int i,activ a[]){
    printf("社团身份:社长\n");
    if(i == 0){
        printf("您暂未发布过活动\n");
        return;
    }
    printf("发布过的活动\n");
    for(int j =0;j<i;j++){
        printf("%s\n",a[j].name);
    }
}
int showacti(activ a[],int i){
    int is_part[100];
    int ch =0;
    int f =0;
    if(i == 0)printf("社长暂未发布活动\n");
    else{
        for(int j=1;j<=i;j++){
            am* tial = a[j-1].head;
            while(tial->next){
                tial =tial->next;
                if(strcmp(tial->name,namenow) == 0){
                    is_part[j-1] =1;
                    break;
                }
                else{
                    f =1;
                }
            }
            if(is_part[j-1] == 0){
                printf("第%d个活动:%s----未报名\n",j,a[j-1].name);
                if(i == j){
                    printf("请输入你要参加第几个活动\n");
                    int ret = scanf("%d",&ch);
                    while(ret !=1){
                        printf("输入错误，请重新输入\n");
                        while(getchar() != '\n');
                            ret =scanf("%d", &ch);
        }
                    return ch-1;
                }
            }
            else{
                printf("第%d个活动:%s----已报名\n",j,a[j-1].name);
                if(f == 0&&i == j){
                    printf("--------已无活动供您参加\n");
                }
            }
        }
    }
    return -1;
}
void showself(activ a[],int i){
    printf("您的名字:%s\n",namenow);
    printf("您的职务:成员\n");
    printf("您参加的活动\n");
    for(int j=0;j<i;j++){
        am* tial =a[j].head;
            while(tial->next){
                tial =tial->next;
                if(strcmp(tial->name,namenow) == 0){
                    printf("您已参加:%s\n",a[j].name);
                    break;
                }
            }
    }
}
void showactiname(activ a[],int i){
    if(i == 0){
        printf("并没有任何活动\n");
        return;
    }
    printf("一共有%d个活动\n",i);
    for(int j=0;j<i;j++){
        am* head = a[j].head->next;
        printf("%s:",a[j].name);
        while(head){
            printf("%s ",head->name);
            head =head->next;
        } 
        printf("\n");
    }
}