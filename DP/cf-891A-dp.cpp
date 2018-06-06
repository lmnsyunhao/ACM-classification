#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int dp[2005][2005];

int main(){
    while(~scanf("%d", &n)){
        memset(dp, 0, sizeof dp);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &dp[i][i]);
            if(dp[i][i] == 1){
                cnt++;
            }
        }
        if(cnt > 0){
            printf("%d\n", n-cnt);
        }
        else{
            int ans = 0;
            bool flag = false;
            for (int i = 1; i < n; i++){
                for (int j = 0; j+i < n; j++){
                    dp[j][j+i] = __gcd(dp[j][j+i-1], dp[j+i][j+i]);
                    if(dp[j][j+i] == 1){
                        flag = true;
                        ans = i;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag)
                printf("%d\n", n-1+ans);
            else
                printf("-1\n");
        }
    }
    return 0;
}
