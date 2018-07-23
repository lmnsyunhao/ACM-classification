#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int n;
int num[105];
int dp[105][105];

int main(){
    while(~scanf("%d", &t)){
        for(int w = 1; w <= t; w++){
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                scanf("%d", &num[i]);
            }

            memset(dp, 0, sizeof dp);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n-i; j++){
                    dp[j][j+i] = i+1;

                    if(num[j] == num[j+i]){
                        dp[j][j+i] = min(dp[j][j+i], dp[j+1][j+i-1]+1);
                    }

                    for(int k = j; k < j+i; k++){
                        dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k+1][j+i]);
                        if(k != j && k != j+i && num[k] == num[j] && num[k] == num[j+i]){
                            dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k+1][j+i]-1);
                        }
                    }
                }
            }

            printf("Case %d: %d\n", w, dp[0][n-1]);
        }
    }
    return 0;
}
