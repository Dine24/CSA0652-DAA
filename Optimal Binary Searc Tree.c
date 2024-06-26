#include <stdio.h>
#include <limits.h>
double sum(double prob[], int i, int j) {
    double s = 0;
    int k;
    for (k = i; k <= j; k++) {
        s += prob[k];
    }
    return s;
}

void optimalBST(double keys[], double prob[], int n) {
    double cost[n][n]; 
    int root[n][n]; 
	int i,L,r;
    for (i = 0; i < n; i++) {
        cost[i][i] = prob[i];
        root[i][i] = i;
    }
    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (r = i; r <= j; r++) {
                double c = ((r > i) ? cost[i][r - 1] : 0) +
                           ((r < j) ? cost[r + 1][j] : 0) +
                           sum(prob, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Cost of Optimal BST is %.6f\n", cost[0][n - 1]);
    void printOBST(int root[n][n], int i, int j, int parent, char *relation) {
        if (i <= j) {
            int r = root[i][j];
            if (parent == -1) {
                printf("Root of the tree: %d\n", (int)keys[r]);
            } else {
                printf("%d is the %s child of %d\n", (int)keys[r], relation, (int)keys[parent]);
            }
            printOBST(root, i, r - 1, r, "left");
            printOBST(root, r + 1, j, r, "right");
        }
    }
    printOBST(root, 0, n - 1, -1, "root");
}

int main() {
    double keys[] = {10, 20, 30, 40, 50};
    double prob[] = {0.1, 0.2, 0.4, 0.2, 0.1};
    int n = sizeof(keys) / sizeof(keys[0]);

    optimalBST(keys, prob, n);

    return 0;
}

