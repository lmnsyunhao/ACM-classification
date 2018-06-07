#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
char c;
int num;
int mark[200005];

int main(){
    while(~scanf("%d\n", &n)){
        for(int i = -1*n; i <= n; i++){
            mark[i+100000] = -2;
        }
        mark[100000] = -1;

        int sum = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            scanf("%c", &c);
            num = c-'0';
            num == 0 ? sum-- : sum++;
            if(mark[100000+sum] != -2){
                res = max(i-mark[100000+sum], res);
            }
            else{
                mark[100000+sum] = i;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
