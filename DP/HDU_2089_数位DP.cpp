#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int s[10];
int len;
int dp[10][2];

int dfs(int pos, int lim, int prev){
    if(pos < 0) return 1;
    if(lim == -1 && dp[pos][prev == 6] != 0) return dp[pos][prev == 6];

    int up = lim==-1?9:lim;

    int tmp = 0;
    for(int i = 0; i <= up; i++){
        if(i == 4) continue;
        if(i == 2 && prev == 6) continue;
        if(i == lim)
            tmp += dfs(pos-1, s[pos-1], i);
        else
            tmp += dfs(pos-1, -1, i);
    }

    if(lim == -1){
        dp[pos][prev == 6] = tmp;
    }

    return tmp;
}

int solve(int num){
    len = 0;
    memset(s, 0, sizeof s);

    while(num > 0){
        s[len++] = num % 10;
        num /= 10;
    }

    return dfs(len-1, s[len-1], -1);
}

int main(){
    while(~scanf("%d %d", &n, &m)){
        if(n == 0 && m == 0) break;
        memset(dp, 0, sizeof dp);

        printf("%d\n", solve(m)-solve(n-1));
    }
    return 0;
}
