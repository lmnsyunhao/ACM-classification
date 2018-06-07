#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int num[2010];
int dp[4][2010];

int main(){
    while(~scanf("%d", &n)){
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }

        for (int i = 0; i < n; i++){
            if(i == 0){
                if(num[i] == 1){
                    dp[0][i] = 1;
                }
                else{
                    dp[1][i] = 1;
                }
                continue;
            }
            if(num[i] == 1){
                dp[0][i] = dp[0][i-1] + 1;
                dp[1][i] = dp[1][i-1];
                dp[2][i] = max(dp[2][i-1] + 1, dp[1][i-1] + 1);
                dp[3][i] = dp[3][i-1];
            }
            else{
                dp[0][i] = dp[0][i-1];
                dp[1][i] = max(dp[0][i-1] + 1, dp[1][i-1] + 1);
                dp[2][i] = dp[2][i-1];
                dp[3][i] = max(dp[2][i-1] + 1, dp[3][i-1] + 1);
            }
        }
        int res = 0;
        for(int i = 0; i < 4; i++){
            if(res < dp[i][n-1]) res = dp[i][n-1];
        }
        printf("%d\n", res);

    }
    return 0;
}
