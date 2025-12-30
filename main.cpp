#include "iostream"
#include "auth.h"
#include "club.h"
#include "utils.h"
#include "time.h"
int money =readmoney();
activ acti[200];
using namespace std;
int i;
int main() {
    while(1){
    i = readi();//活动数量
    readacti(acti,i);
    int sta = 1;
    if (sta == 0)
    {
        printf("社团已被注销\n");
        freeall(&pinghead,&applhead,&rejehead,acti,i);
        return 0;
    }
    int n = choice();
    switch (n)
    {
    case 1://成员注册
    pinghead = rg(pinghead);
    break;
    case 2://成员登录
    {
    if (mebrenty(applhead)){
        printf("登陆成功\n");
        int n2 = choicemebr();
        switch (n2)
        {
            case 1://社团信息
            showclub(applhead);
            break;
            case 2://个人信息
            showself(acti,i);
            break;
            case 3://报名活动
            int ch = showacti(acti,i);
            if(ch == -1)break;
            acti[ch].head =newactimebr(acti,ch);
            saveacti(acti,i);
            printf("您以报名\n");
            break;
        }
    }
    }
    break;
    case 3://管理员登录
    {
    if (enty()) {
        int n3 = choiceappr();
        switch (n3) {
        case 1://审批用户
        appr(pinghead);
        break;
        case 2://审批记录
        record(applhead, rejehead);
        break;
        case 3://社团活动展示
        showactiname(acti,i);
        break;
        case 4://审批经费
        money = apprmoney(money);
        savemoney(money);
        break;
        case 5://经费记录
        costrecord(acti,i,money);
        break;
        case 6://导出财务报表
        putrecord(acti,i,money);
        break;
        case 7://注销社团
        sta = 0;
        freeall(&pinghead,&applhead,&rejehead,acti,i);
        return 0;
        case 8://退出
        return 0;
        }
    }
    }
    break;
    case 4://社长登录
    {
    int n4;
    if(presenty()){
        n4 = choicepres();
    }
    switch(n4)
    {
        case 1://展示社团成员
            showclub(applhead);
            break;
        case 2://个人信息
            ifmtpres(i,acti);
            break;
        case 3://发布活动
        if(actimoney(acti,i,&money)){
            newactc(acti,i);
        }
            break;
        case 4://经费记录
            costrecord(acti,i,money);
            break;
        case 5://申请经费
            readsaid();
            applymoney();
            break;
        case 6://查看社团现有经费
            printf("社团资金:%d\n",money);
            break;
        case 7://退出
            freeall(&pinghead,&applhead,&rejehead,acti,i);
            return 0;
    }
    }
    break;
    case 5://退出程序
        freeall(&pinghead,&applhead,&rejehead,acti,i);
        return 0;
    case 6://清空社团数据
        if(ensure()){
        freeall(&pinghead,&applhead,&rejehead,acti,i);
        cleanall();
        return 0;
        }
        break;
    }
}
}