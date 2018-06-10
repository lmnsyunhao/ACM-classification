#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int n, num;
int stk[400005];
int cur;
int cnt[200005];
vector<int> tr[200005];

void dfs(int idx, int fa){
    stk[cur++] = idx;
    if(tr[idx].size() == 1 && fa != 0) return;

    for(int i = 0; i < tr[idx].size(); i++){
        if(tr[idx][i] == fa) continue;
        dfs(tr[idx][i], idx);
    }

    stk[cur++] = idx;
    if(cnt[idx] % 2 == 0){
        printf("%d\n", idx);
        cnt[idx] = -1;
        cnt[fa]--;
        cur--;

        while(cur && stk[cur-1] != idx){
            if(cnt[stk[cur-1]] != -1){
                printf("%d\n", stk[cur-1]);
                cnt[stk[cur-1]] = -1;
            }
            cur--;
        }
        cur--;
    }
}

int main(){
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; i++) tr[i].clear();
        memset(cnt, 0, sizeof cnt);
        cur = 0;

        for(int i = 1; i <= n; i++){
            scanf("%d", &num);
            if(num != 0){
                cnt[i]++;
                cnt[num]++;
                tr[i].push_back(num);
                tr[num].push_back(i);
            }
        }

        if(n%2==0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            dfs(1, 0);
            while(cur){
                if(cnt[stk[cur-1]] != -1){
                    printf("%d\n", stk[cur-1]);
                    cnt[stk[cur-1]] = -1;
                }
                cur--;
            }
        }
    }
    return 0;
}
