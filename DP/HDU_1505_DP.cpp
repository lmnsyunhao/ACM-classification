#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int k, n, m;
char grid[1010][1010];
int verti[1010][1010];
int horiz[1010][1010];

struct node{
    int x, y;
}dp[1010][1010];

node getBorder1(int x, int y){
    int upx, upy;
    if(x == 0 || grid[x-1][y] == 'R'){
        upx = x;
        upy = 0;
    }
    else{
        upx = dp[x-1][y].x;
        upy = dp[x-1][y].y;
    }

    int lftx, lfty;
    if(y == 0 || grid[x][y-1] == 'R'){
        lftx = 0;
        lfty = y;
    }
    else{
        lftx = dp[x][y-1].x;
        lfty = dp[x][y-1].y;
    }

    int upOne = verti[x][y]+1;
    int lftOne = horiz[x][y]+1;

    int cornerx, cornery;
    if(lftx == 0 || upy == 0){
        cornerx = 0;
        cornery = 0;
    }
    else if(grid[lftx-1][upy-1] == 'R'){
        cornerx = lftx;
        cornery = upy;
    }
    else{
        cornerx = dp[lftx-1][upy-1].x;
        cornery = dp[lftx-1][upy-1].y;
    }

    int retx = max(max(cornerx, lftx), upOne);
    int rety = max(max(cornery, upy), lftOne);

    return (node){retx, rety};
}

node getBorder2(int x, int y){
    int lftx, lfty;
    if(y == 0 || grid[x][y-1] == 'R'){
        lftx = 0;
        lfty = y;
    }
    else{
        lftx = dp[x][y-1].x;
        lfty = dp[x][y-1].y;
    }

    int upOne = verti[x][y]+1;

    int retx = max(upOne, lftx);

    return (node){retx, lfty};
}

node getBorder3(int x, int y){
    int upx, upy;
    if(x == 0 || grid[x-1][y] == 'R'){
        upx = x;
        upy = 0;
    }
    else{
        upx = dp[x-1][y].x;
        upy = dp[x-1][y].y;
    }

    int lftOne = horiz[x][y]+1;

    int rety = max(lftOne, upy);

    return (node){upx, rety};
}

int main(){
    scanf("%d", &k);
    while(k--){
        memset(dp, 0, sizeof dp);

        scanf("%d %d", &n, &m);
        getchar();
        char str[5];
        for (int i = 0; i < n; i++){
            int tmp = -1;
            for (int j = 0; j < m; j++){
                scanf("%s", str);
                grid[i][j] = str[0];
                if(grid[i][j] == 'R'){
                    tmp = j;
                }
                horiz[i][j] = tmp;
            }
        }

        for (int i = 0; i < m; i++){
            int tmp = -1;
            for (int j = 0; j < n; j++){
                if(grid[j][i] == 'R'){
                    tmp = j;
                }
                verti[j][i] = tmp;
            }
        }

        int mx = 0;
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] == 'R'){
                    dp[i][j] = (node){-1, -1};
                }
                else{
                    node no1 = getBorder1(i, j);
                    int sz1 = (i-no1.x+1)*(j-no1.y+1);

                    node no2 = getBorder2(i, j);
                    int sz2 = (i-no2.x+1)*(j-no2.y+1);

                    node no3 = getBorder3(i, j);
                    int sz3 = (i-no3.x+1)*(j-no3.y+1);

                    int sz = 0;
                    if(sz1 > sz2){
                        dp[i][j] = no1;
                        sz = sz1;
                    }
                    else{
                        dp[i][j] = no2;
                        sz = sz2;
                    }

                    if(sz3 > sz){
                        dp[i][j] = no3;
                        sz = sz3;
                    }

                    if(sz > mx){
                        mx = sz;
                    }
                }
            }
        }

        printf("%d\n", 3*mx);
    }
    return 0;
}
