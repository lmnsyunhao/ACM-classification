#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char c;

int main(){
    while(~scanf("%d\n", &n)){
        int cntl = 0, cntr = 0, cntu = 0, cntd = 0;
        for(int i = 1; i <= n; i++){
            scanf("%c", &c);
            if(c == 'L') cntl++;
            else if(c == 'R') cntr++;
            else if(c == 'U') cntu++;
            else if(c == 'D') cntd++;
        }
        printf("%d\n", min(cntl, cntr)*2 + min(cntu, cntd)*2);
    }
    return 0;
}
