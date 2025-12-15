 #include "stdlib.h"
 #include "stdio.h"
 #include "malloc.h"
 #include "string.h"
 #pragma once
typedef struct fm{
   char N[10];
   char U[10];
   char P[10];
}fm;
 typedef struct m {
    char name[10];
    char username[10];
    char passwords[10];
    struct m* next;
}mebr;

 mebr* newm1(char name[10],char username[10],char passwords[10]){
    mebr* newm = (mebr*)malloc (sizeof(mebr));
    if(!newm){
        printf("malloc failed");
        return NULL;
    }
    strcpy(newm->name,name);
    strcpy(newm->username,username);
    strcpy(newm->passwords,passwords);
    newm ->next = NULL;
    return newm;
 }
 mebr* createm(){
    mebr* head = (mebr*)malloc(sizeof(mebr));
    if(!head){
        printf("malloc failed");
        return NULL;
    }
    memset(head,0,sizeof(head));
    return head;
 }
 void newadd(mebr*head,char name[10],char username[10],char passwords[10]){
    mebr* list = newm1(name,username,passwords);
    list ->next = head ->next;
    head ->next = head;
 }