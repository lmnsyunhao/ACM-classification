#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n, l, k;
int val[6005];
vector<int> tr[6005];
int dp[6005][2];

void dfs(int idx, int fa){
    dp[idx][0] = 0;
    dp[idx][1] = val[idx];

    if(tr[idx].size() == 1 && fa != 0) return;

    for(int i = 0; i < tr[idx].size(); i++){
        if(tr[idx][i] == fa) continue;
        dfs(tr[idx][i], idx);
    }

    for(int i = 0; i < tr[idx].size(); i++){
        if(tr[idx][i] == fa) continue;
        dp[idx][0] += max(dp[tr[idx][i]][0], dp[tr[idx][i]][1]);
        dp[idx][1] += dp[tr[idx][i]][0];
    }
}

int main(){
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; i++) tr[i].clear();
        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n; i++){
            scanf("%d", &val[i]);
        }
        while(scanf("%d %d", &l, &k)){
            if(l == 0 && k == 0) break;
            tr[l].push_back(k);
            tr[k].push_back(l);
        }

        dfs(1, 0);
        printf("%d\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}
