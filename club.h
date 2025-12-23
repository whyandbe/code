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
    printf("1.审批注册新成员 2.查看社团审批记录 3.查看社团活动\n 4.查看社团花费记录 5.注销社团 6.退出登录\n");
    scanf("%d", &n);
    return n;
}
int choicemebr() {
    int n;
    printf("1.查看社团信息 2.查看个人信息 3.参加报名活动 4.退出登录\n");
    scanf("%d", &n);
    return n;
}
int choicepres(){
    int n;
    printf("1.查看社团信息 2.查看个人信息 3.发布活动\n4.查看社团花费记录 5.申请社团经费 6.退出登录\n");
    scanf("%d", &n);
    return n;
}
void ifmtpres(){
    printf("社团身份:社长\n");
    printf("发布过的活动\n");

}
int showacti(activ a[],int i){
    int ch;
    if(i == 0)printf("社长暂未发布活动");
    else{
        for(int j=1;j<=i;j++){
            printf("第%d个活动:%s\n",j,a[j-1].name);
        }
        printf("请输入你要参加第几个活动");
        scanf("%d",&ch);
    }
    return ch-1;
}
void showself(activ a[],int i){
    int f =0;
    printf("您的名字:%s\n",namenow);
    printf("您的职务:成员\n");
    printf("您参加的活动\n");
    for(int j=0;j<i;j++){
        if(strcmp(a[j].head->next->name,namenow) == 0){
            printf("%s\n",a[j].name);
            f =1;
        }
    }
    if(f == 0)printf("您未参与过社团活动\n");
}