#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, q, l, r;
int dp[5005][5005];

void calc(){
    for (int i = 2; i <= n; i++){
        for(int j = 0; j < n-i+1; j++){
            int x = j+1, y = i+j;
            dp[x][y] = dp[x+1][y] ^ dp[x][y-1];
            dp[y][x] = max(dp[x][y], max(dp[y][x+1], dp[y-1][x]));
        }
    }
}

int main(){
    while(~scanf("%d", &n)){
        for (int i = 1; i <= n; i++){
            scanf("%d", &dp[i][i]);
        }
        calc();
        scanf("%d", &q);
        for (int w = 0; w < q; w++){
            scanf("%d%d", &l, &r);
            printf("%d\n", dp[r][l]);
        }
    }
    return 0;
}
