#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char str[110];
int dp[3][110];

int main(){
    while(~scanf("%s", str)){
        memset(dp, 0, sizeof dp);
        int len = strlen(str);
        for(int i = 0; i < len; i++){
            if(i == 0){
                if(str[i] == 'Q'){
                    dp[0][i] = 1;
                }
                continue;
            }
            if(str[i] == 'Q'){
                dp[0][i] = dp[0][i-1] + 1;
                dp[1][i] = dp[1][i-1];
                dp[2][i] = dp[2][i-1] + dp[1][i-1];
            }
            else if(str[i] == 'A'){
                dp[0][i] = dp[0][i-1];
                dp[1][i] = dp[0][i-1] + dp[1][i-1];
                dp[2][i] = dp[2][i-1];
            }
            else{
                dp[0][i] = dp[0][i-1];
                dp[1][i] = dp[1][i-1];
                dp[2][i] = dp[2][i-1];
            }
        }
        printf("%d\n", dp[2][len-1]);
    }
    return 0;
}
