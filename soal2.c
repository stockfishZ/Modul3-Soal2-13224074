#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int check(int g1, int g2, int target){
    if (target > (g1 > g2 ? g1 : g2)) return -1;

    int q[10000][3], front = 0, rear = 0;

    bool visited[g1+1][g2+1];

    for (int i = 0; i <= g1; i++){
        for (int j =0 ; j <= g2; j++){
            visited[i][j] = false;
        }
    }

    q[rear][0] = 0;
    q[rear][1] = 0;
    q[rear][2] = 0;

    rear++;
    visited[0][0] = true;

    while (front != rear){
        int j1 = q[front][0];
        int j2 = q[front][1];
        int steps = q[front][2];
        front++;

        if (j1 == target || j2 == target) return steps;

        if (!visited[g1][j2]){
            visited[g1][j2] = true;
            q[rear][0] = g1;
            q[rear][1] = j2;
            q[rear][2] = steps+1;
            rear++;
        }

        if (!visited[j1][g2]){
            visited[j1][g2] = true;
            q[rear][0] = j1;
            q[rear][1] = g2;
            q[rear][2] = steps+1;
            rear++;
        }

        if (!visited[0][j2]){
            visited[0][j2] = true;
            q[rear][0] = 0;
            q[rear][1] = j2;
            q[rear][2] = steps+1;
            rear++;
        }

        if (!visited[j1][0]){
            visited[j1][0] = true;
            q[rear][0] = j1;
            q[rear][1] = 0;
            q[rear][2] = steps+1;
            rear++;
        }

        int pour1to2 = j1 < (g2-j2) ? j1 : (g2-j2);
        if (!visited[j1-pour1to2][j2+pour1to2]){
            visited[j1-pour1to2][j2+pour1to2] = true;
            q[rear][0] = j1 - pour1to2;
            q[rear][1] = j2 + pour1to2;
            q[rear][2] = steps+1;
            rear++;
        }

        int pour2to1 = j2 < (g1-j1) ? j2 : (g1-j1);
        if (!visited[j1+pour2to1][j2-pour2to1]){
            visited[j1+pour2to1][j2-pour2to1] = true;
            q[rear][0] = j1 + pour2to1;
            q[rear][1] = j2 - pour2to1;
            q[rear][2] = steps+1;
            rear++;
        } 
    }
    return -1;
}

int main(){
    int g1, g2, target;
    scanf("%d %d %d", &g1, &g2, &target);

    if (g1 == target || g2 == target) return 1;

    int result = check(g1, g2, target);

    printf("%d", result);
    return 0;
}

//referensi
//https://www.geeksforgeeks.org/dsa/two-water-jug-puzzle/
