#include "iostream"
#include "auth.h"
#include "club.h"
#include "utils.h"
int i = readi();
mebr* pinghead = readdata("D:/ping.user.data");
mebr* applhead = readdata("D:/appl.user.data");
mebr* rejehead = readdata("D:/reje.user.data");
activ acti[200];
using namespace std;
int main() {
    if(readi() == -1)i=0;
    readacti(acti,i);
    printf("%s",acti[0].head->next->name);
    int sta = 1;
    if (sta == 0)
    {
        printf("社团已被注销\n");
        return 0;
    }
    int n = choice();
    switch (n)
    {
    case 1:
    pinghead = rg(pinghead);
    break;
    case 2:
    {
    if (mebrenty(applhead))printf("登陆成功\n");
    int n2 = choicemebr();
    switch (n2)
    {
    case 1:
    showclub(applhead);
    break;
    case 2:
    showself(acti,i);
    break;
    case 3:
    int ch = showacti(acti,i);
    acti[ch] =newactimebr(acti,ch);
    saveacti(acti,i);
    printf("您以报名\n");
    break;
    }
    break;
    }
    case 3:
    {
    if (enty()) {
        int n3 = choiceappr();
        switch (n3) {
        case 1:
        appr(pinghead);
        break;
        case 2:
        record(applhead, rejehead);
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        sta = 0;
        return 0;
        }
    }
    break;
    }
    case 4:{
    int n4;
    if(presenty()){
        n4 = choicepres();
    }
    switch(n4)
    {
        case 1:
            showclub(applhead);
            break;
        case 2:
            ifmtpres();
            break;
        case 3:
            newactc(acti,i);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            return 0;
    }
    break;
    }
    case 5:
        return 0;
    }
}