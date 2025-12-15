#pragma once
#include "node.h"
void rg(){
    fm fm1;
    printf("请输入你的名字(小于10个字符)");
    char name1[10];
    scanf("%s",name1);
    printf("请输入你的账号(小于10个字符)");
    char username1[10];
    scanf("%s",username1);
    printf("请输入你的密码(小于10个字符)");
    char passwords1[10];
    scanf("%s",passwords1);
    strcpy(fm1.N,name1);
    strcpy(fm1.U,username1);
    strcpy(fm1.P,passwords1);
}
void savedate(){
    FILE* fp = fopen("user.date","w");
    fwrite(&fm,sizeof(fm),1,fp);s

}