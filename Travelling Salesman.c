#include <stdio.h>
#include <limits.h>
#define N 4
#define INF INT_MAX
int dp[1 << N][N];
int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};
int tsp(int mask, int pos) {
    if (mask == ((1 << N) - 1)) {
        return dist[pos][0];
    }
    
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    
    int ans = INF;
    int city;
    for (city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = ans < newAns ? ans : newAns;
        }
    }
    
    return dp[mask][pos] = ans;
}

int main() {
	int i,j;
    for (i = 0; i < (1 << N); i++) {
        for (j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0);
    printf("The minimum cost of the tour is %d\n", result);

    return 0;
}

