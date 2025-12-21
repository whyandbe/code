 #include "stdlib.h"
 #include "stdio.h"
 #include "malloc.h"
 #include "string.h"
 #pragma once
typedef enum{
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
 mebr* newm1(char name[10],char username[10],char passwords[10],sta sta){
    mebr* newm = (mebr*)malloc (sizeof(mebr));
    if(!newm){
        printf("malloc failed");
        return NULL;
    }
    strcpy(newm->name,name);
    strcpy(newm->username,username);
    strcpy(newm->passwords,passwords);
    newm ->sta =sta;
    newm ->next = NULL;
    return newm;
 }
 mebr* createm(){
    mebr* head = (mebr*)malloc(sizeof(mebr));
    memset(head,0,sizeof(head));
    head->next =0;
    return head;
 }
 mebr* newadd(mebr*head,char name[10],char username[10],char passwords[10],sta sta){
    mebr* list = newm1(name,username,passwords,sta);
    if(head){
      list->next =head->next;
      head->next = list;
    }
    return head;
 }
 void savedata(mebr* head,const char *ass){
    FILE* fp = fopen(ass,"w");
    head =head->next;
    while(head){
      fprintf(fp,"%s %s %s %d",head->name,head->username,head->passwords,head->sta);
      head =head->next;
    }
    fclose(fp);
}
 void show(mebr* head){
   while(head !=0){
      printf("%s\n",head->name);
      head=head->next;
   }
 }