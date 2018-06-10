#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int num[1005];
int dp[1005][1005];

int main(){
    while(~scanf("%d", &n)){
        if(!n) break;
        for(int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        memset(dp, 0, sizeof dp);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i; j++){
                if(i == 0) dp[j][j+i] = 1;
                else{
                    dp[j][j+i] = max(dp[j+1][j+i], dp[j][j+i-1]);
                    if(num[j] == num[j+i]){
                        dp[j][j+i] = max(dp[j][j+i], dp[j+1][j+i-1]+2);
                    }
                }
            }
        }

        int res = 1;
        for(int i = 0; i < n-1; i++){
            res = max(res, dp[0][i] + dp[i+1][n-1]);
        }
        printf("%d\n", res);
    }
    return 0;
}
