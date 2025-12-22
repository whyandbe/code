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
    printf("1.审批注册新成员 2.查看社团审批记录 3.查看社团活动 4.查看社团花费记录 5.注销社团 6.推出登录");
    scanf("%d", &n);
    return n;
}
int choicemebr() {
    int n;
    printf("1.查看社团信息 2.查看个人信息 3.参加报名活动 4.退出登录\n");
    scanf("%d", &n);
    return n;
}

