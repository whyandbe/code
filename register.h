#pragma once
#include "node.h"
mebr* rg(mebr* head){
    printf("请输入你的名字(小于10个字符)");
    char name1[10];
    scanf("%s",name1);
    printf("请输入你的账号(小于10个字符)");
    char username1[10];
    scanf("%s",username1);
    printf("请输入你的密码(小于10个字符)");
    char passwords1[10];
    scanf("%s",passwords1);
    newaddp(head,name1,username1,passwords1,ping);
    pingsavedata(head);
    return head;
}
void pingsavedata(mebr* head){
    FILE* fp = fopen("ping.user.date","w");
    fwrite(head,sizeof(mebr),1,fp);
    fclose(fp);
}
void applsavedata(mebr* head){
    FILE* fp = fopen("appl.user.date","w");
    fwrite(head,sizeof(mebr),1,fp);
    fclose(fp);
}
mebr* pingreaddata(){
    mebr* pinghead =createm();
    FILE* fp =fopen("ping.user.date","r");
    fread(pinghead,sizeof(mebr),1,fp);
    fclose(fp);
    return pinghead;
}
mebr* applreaddata(){
    mebr* applhead =createm();
    FILE* Fp =fopen("appl.user.date","r");
    fread(applhead,sizeof(mebr),1,Fp);
    fclose(Fp); 
    return applhead;
}
int choice(){
    printf("");
}