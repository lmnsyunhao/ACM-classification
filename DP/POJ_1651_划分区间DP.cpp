#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int num[105];
int dp[105][105];

int main(){
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        memset(dp, 0, sizeof dp);

        for(int i = 2; i < n; i++){
            for(int j = 0; j < n-i; j++){
                for(int k = j+1; k < j+i; k++){
                    if(dp[j][j+i] == 0)
                        dp[j][j+i] = dp[j][k]+dp[k][j+i]+num[j]*num[k]*num[j+i];
                    else
                        dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k][j+i]+num[j]*num[k]*num[j+i]);
                }
            }
        }

        printf("%d\n", dp[0][n-1]);
    }
    return 0;
}
