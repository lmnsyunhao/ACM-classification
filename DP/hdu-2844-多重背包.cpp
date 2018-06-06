#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int v[105];
int c[105];
int dp[100005];

void init(int m){
    for(int i = 1; i <= m; i++){
        dp[i] = -1000000000;
    }
    dp[0] = 0;
}

void completepack(int m, int c, int v){
    for(int i = c; i <= m; i++){
        dp[i] = max(dp[i], dp[i-c]+v);
    }
}

void O1pack(int m, int c, int v){
    for(int i = m; i >= c; i--){
        dp[i] = max(dp[i], dp[i-c]+v);
    }
}

void multiplepack(int m, int c, int v, int num){
    if(c*num >= m){
        completepack(m, c, v);
        return ;
    }
    for(int i = 1; i <= num; i*=2){
        O1pack(m, c*i, v*i);
        num -= i;
    }
    if(num){
        O1pack(m, c*num, v*num);
    }
}

int main(){
    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &c[i]);
        }

        init(m);

        if(m > 0){
            for(int i = 0; i < n; i++){
                multiplepack(m, v[i], 1, c[i]);
            }
        }

        int ret = 0;
        for(int i = 1; i <= m; i++){
            if(dp[i] > 0){
                ret++;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
