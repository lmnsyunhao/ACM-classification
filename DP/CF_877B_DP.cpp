#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char str[5005];
int dp[5005][3];

int main(){
    while(~scanf("%s", str)){
        int len = strlen(str);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= len; i++){
            if(str[i-1] == 'a'){
                dp[i][0] = dp[i-1][0]+1;
                dp[i][1] = dp[i-1][1];
                dp[i][2] = max(dp[i-1][1]+1, dp[i-1][2]+1);
            }
            else{
                dp[i][0] = dp[i-1][0];
                dp[i][1] = max(dp[i-1][0]+1, dp[i-1][1]+1);
                dp[i][2] = dp[i-1][2];
            }
        }
        printf("%d\n", max(dp[len][0], max(dp[len][1], dp[len][2])));
    }
    return 0;
}
