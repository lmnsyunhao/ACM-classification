#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[105][105];
char str[105];

int main(){
    while(~scanf("%s", str)){
        if(str[0] == 'e') break;
        int n = strlen(str);
        memset(dp, 0, sizeof dp);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i; j++){
                for(int k = j; k < j+i; k++){
                    dp[j][j+i] = max(dp[j][j+i], dp[j][k]+dp[k+1][j+i]);
                }
                if((str[j] == '(' && str[j+i] == ')') || (str[j] == '[' && str[j+i] == ']'))
                    dp[j][j+i] = max(dp[j][j+i], dp[j+1][j+i-1]+2);
            }
        }

        printf("%d\n", dp[0][n-1]);
    }
    return 0;
}
