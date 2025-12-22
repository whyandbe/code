#include "iostream"
#include "auth.h"
#include "club.h"
#include "utils.h"
mebr* pinghead = readdata("D:/ping.user.data");
mebr* applhead = readdata("D:/appl.user.data");
mebr* rejehead = readdata("D:/reje.user.data");
using namespace std;
int main() {
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
        case 3:
        case 4:
            return 0;
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
            case 2:
                record(applhead, rejehead);
            case 3:
            case 4:
            case 5:
                sta = 0;
                return 0;
            }
        }
        break;
    }
    }
}