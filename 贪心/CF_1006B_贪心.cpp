#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k;
int num[2010];
int cnt[2010];
int res[2010];

int main(){
    scanf("%d%d", &n, &k);
    memset(cnt, 0, sizeof cnt);
    memset(res, 0, sizeof res);
    for (int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        cnt[num[i]]++;
    }

    int minval = 0;
    int tmp = 0;
    int cur = 2000;
    int ret = 0;
    while(tmp < k){
        while(!cnt[cur])
            cur--;
        tmp += cnt[cur];
        if(tmp >= k){
            cnt[cur] -= tmp-k;
            minval = cur;
        }
        ret += cur*cnt[cur];
        cur--;
    }
    printf("%d\n", ret);

    int rescur = 0;
    for(int i = 0; i < n; i++){
        if(num[i] >= minval && cnt[num[i]]){
            cnt[num[i]]--;
            res[rescur]++;
            if(rescur < k-1)
                rescur++;
        }
        else{
            res[rescur]++;
        }
    }
    for(int i = 0; i <= rescur; i++){
        printf("%d", res[i]);
        i == rescur ? printf("\n") : printf(" ");
    }
    return 0;
}
