#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
char s[110];
int dp[2][110];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        int len = strlen(s);
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i < len; i++){
            if(s[i] >= 'a'  && s[i] <= 'z'){
                if(i == 0){
                    dp[0][i] = 1;
                    dp[1][i] = 2;
                }
                else{
                    dp[0][i] = min(dp[0][i-1]+1, dp[1][i-1]+2);
                    dp[1][i] = min(dp[1][i-1]+2, dp[0][i-1]+2);
                }
            }
            else{
                if(i == 0){
                    dp[0][i] = 2;
                    dp[1][i] = 2;
                }
                else{
                    dp[0][i] = min(dp[0][i-1]+2, dp[1][i-1]+2);
                    dp[1][i] = min(dp[1][i-1]+1, dp[0][i-1]+2);
                }
            }
        }
        int res = min(dp[0][len-1], dp[1][len-1]+1);
        printf("%d\n", res);
    }
    return 0;
}
