#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, x, t;
int grid[100010][15];
int dp[2][15];

int main(){
    while(~scanf("%d", &n), n){
        memset(grid, 0, sizeof grid);
        int mxt = 0;
        for (int i = 0; i < n; i++){
            scanf("%d %d", &x, &t);
            if(t > mxt)
                mxt = t;
            grid[t][x]++;
        }

        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= mxt; i++){
            int l = 0, r = 10, l1 = 0, r1 = 10;
            if(i < 6){
                l = 5-i;
                r = 5+i;
                l1 = l+1;
                r1 = r-1;
            }
            for(int j = l; j <= r; j++){
                if(j-1 >= l1 && j-1 <= r1)
                    dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j-1] + grid[i][j]);
                if(j+1 >= l1 && j+1 <= r1)
                    dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j+1] + grid[i][j]);
                dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][j] + grid[i][j]);
            }
        }

        int mx = 0;
        for(int i = 0; i < 11; i++){
            if(dp[mxt%2][i] > mx)
                mx = dp[mxt%2][i];
        }
        printf("%d\n", mx);
    }
    return 0;
}
