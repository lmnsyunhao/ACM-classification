#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define mod 10007
int t;
char str[1005];
int dp[1005][1005];

int main(){
    scanf("%d\n", &t);
    for(int w = 0; w < t; w++){
        scanf("%s", str);
        memset(dp, 0, sizeof dp);

        int n = strlen(str);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i; j++){
                if(i == 0) dp[j][j+i] = 1;
                else{
                    dp[j][j+i] = (dp[j][j+i-1]+dp[j+1][j+i])%mod;
                    if(str[j] != str[j+i]){
                        dp[j][j+i] -= dp[j+1][j+i-1];
                    }
                    else{
                        dp[j][j+i] += 1;
                    }
                    dp[j][j+i] = (dp[j][j+i]+mod)%mod;
                }
            }
        }
        printf("Case %d: %d\n", w+1, dp[0][n-1]);
    }
    return 0;
}
