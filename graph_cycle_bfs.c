#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/***** Adjacency List for directed graph *****/
struct adj_list {
        int **adj;
        int *adj_sz;
        int v;
};

void print_graph(struct adj_list *adj_l);

struct adj_list *adj_init(int v) {
        struct adj_list *adj_l = (struct adj_list *) calloc(sizeof(struct adj_list), 1);

        //Allocate the adj-list
        adj_l->adj = (int **) calloc(sizeof(int *) , v);
        for(int i=0; i<v; i++) {
                adj_l->adj[i] = (int *) calloc(sizeof(int), v);
        }

        //Adj list sizes
        adj_l->adj_sz = (int *) calloc(sizeof(int), v);
        for(int i=0; i<v; i++) {
                adj_l->adj_sz[i] = -1;
        }

        //Total number of vertices
        adj_l->v = v;
        return adj_l;
}

void add_edge(struct adj_list *adj_l, int x, int y) {
        adj_l->adj_sz[x] += 1;
        int idx_x = adj_l->adj_sz[x];

        //Edges should be added from x->y
        adj_l->adj[x][idx_x] = y;
}
/****** DFS *****/
int dfs(int node, struct adj_list *adj_l, int visited[], int rec_stack[]) {
        visited[node] = 1;
        rec_stack[node] = 1;
        printf("%d ", node);

        for(int i=0; i <= adj_l->adj_sz[node]; i++) {
                if (visited[ adj_l->adj[node][i] ]  == 0 && dfs(adj_l->adj[node][i], adj_l, visited, rec_stack) ) {
                                return 1;
                } else if (rec_stack[ adj_l->adj[node][i]  ] == 1) {
                        printf("FOUND A LOOP for %d\n", adj_l->adj[node][i]);
                        return 1;
                }
        }

        rec_stack[node] = 0;
        return 0;
}

int detect_loop(struct adj_list *adj_l) {
        int len = adj_l->v;
        int visited[len];
        int rec_stack[len];     //recursion stack.
        for(int i=0; i<len; i++) {
                visited[i] = 0;
                rec_stack[i] = 0;
        }

        printf("\nDFS: \n");
        //We loop for all non-visited nodes to catch the disconnected parts of the graphs.
        for(int i=0; i < len; i++) {
                if(visited[i] == 0) {
                        if (dfs(i, adj_l, visited, rec_stack) == 1) {
                                return 1;
                        }
                }
        }
        printf("\n");
        return 0;
}

int main() {
        int v=7;

        struct adj_list *adj = adj_init(v);

        add_edge(adj, 0, 1);
        add_edge(adj, 2, 1);
        add_edge(adj, 2, 3);
        add_edge(adj, 3, 4);
        add_edge(adj, 4, 5);
        add_edge(adj, 5, 3);

        print_graph(adj);


        printf("Detect loop: %d ", detect_loop(adj));
        return 0;
}

void print_graph(struct adj_list *adj_l) {
        int v = adj_l->v;

        for(int i=0; i<v ; i++) {
                int len = adj_l->adj_sz[i];
                printf("(%d): ", i);
                for(int j=0; j<=len; j++) {
                        printf("%d-> ", adj_l->adj[i][j]);
                }
                printf("()\n");
        }
}

