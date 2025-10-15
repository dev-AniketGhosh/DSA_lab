#include <stdio.h>
#define SIZE 10

int queue[SIZE], front = -1, rear = -1;
int visited[SIZE] = {0};

void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue Full!\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
    }
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    else
        return queue[front++];
}

void bfs(int adj[][SIZE], int n, int start) {
    int i, node;
    front = rear = -1;          // Reset queue
    for(i = 0; i < n; i++)      // Reset visited array
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");

    while ((node = dequeue()) != -1) {
        printf("%d ", node);
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, j, i, start;
    int adj[SIZE][SIZE];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}

