#pragma once
#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"
#include "string.h"
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
    memset(head, 0, sizeof(head));
    head->next = 0;
    return head;
}
mebr* newadd(mebr* head, char name[10], char username[10], char passwords[10], sta sta) {
    mebr* list = newm1(name, username, passwords, sta);
    if (head) {
        list->next = head->next;
        head->next = list;
    }
    return head;
}
void savedata(mebr* head, const char* ass) {
    FILE* fp = fopen(ass, "w");
    head = head->next;
    while (head) {
        fprintf(fp, "%s %s %s %d", head->name, head->username, head->passwords, head->sta);
        head = head->next;
    }
    fclose(fp);
}
void show(mebr* head) {
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
void appr(mebr* pinghead) {
    int count = 0;
    mebr* applhead1 = createm();
    mebr* rejehead1 = createm();
    if (pinghead->next == 0) {
        printf("暂无人员需要审批\n");
        return;
    }
    while (pinghead->next) {
        mebr* q = pinghead->next;
        count++;
        printf("第%d个待审批成员信息", count);
        printf("姓名：%s\n账号：%s\n密码：%s\n", q->name, q->username, q->passwords);
        printf("是否审批通过-------( 1 / 2 )");
        int ch;
        scanf("%d", &ch);
        if (ch == 1) {
            applhead1 = newadd(applhead1, q->name, q->username, q->passwords, appl);
            if (q->next) {
                pinghead->next = q->next;
                pinghead = pinghead->next;
                printf("%s已被通过", q->name);
            }
            free(q);
            pinghead->next = 0;
        }
        else if (ch == 2) {
            rejehead1 = newadd(rejehead1, q->name, q->username, q->passwords, reje);
            if (q->next) {
                pinghead->next = q->next;
                pinghead = pinghead->next;
                printf("%s同学已被拒绝", pinghead);
            }
            free(q);
            pinghead->next = 0;
        }
    }
    savedata(applhead1, "D:/appl.user.data");
    savedata(rejehead1, "D:/reje.user,data");
    savedata(pinghead, "D:/ping.user.data");
}
void record(mebr* applhead, mebr* rejehead) {
    printf("以下同学已被拒绝\n");
    show(applhead);
    printf("以下同学已被同意\n");
    show(rejehead);
}
