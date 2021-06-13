#include<stdio.h>
#include<stdlib.h>

typedef struct adj_list {
        int **adj;
        int *adj_sz;
        int v;
}adj_list_t ;

adj_list_t *adj_init(int v) {
        adj_list_t *adj_l = (adj_list_t *) calloc(sizeof(adj_list_t), 1);

        adj_l->v = v;
        adj_l->adj_sz = (int *)calloc(sizeof(int), v);
        adj_l->adj = (int **)calloc(sizeof(int *), v);

        for(int i=0; i < v; i++) {
                adj_l->adj[i] = (int*) calloc(sizeof(int), v);
                adj_l->adj_sz[i] = 0;
        }

        return adj_l;
}

void add_edge(adj_list_t *adj, int x, int y) {
        printf("%d %d\n", adj->adj_sz[x], adj->adj_sz[y]);
        adj->adj[x][ adj->adj_sz[x] ] = y;
        adj->adj[y][ adj->adj_sz[y] ] = x;

        adj->adj_sz[x] += 1;
        adj->adj_sz[y] += 1;

}

/************* Shortest Path in undirected connected graph ************************/
#define SZ 999
struct node_pair {
        int node, parent;
};
struct node_pair queue[SZ];
int s=-1;
int e=0;

int enq(int n, int p) {
        if ( s == SZ-1) {
                return -1;
        }

        s++;
        queue[s].node = n;
        queue[s].parent = p;
        return 0;
}

int deq(int *n, int *p) {
        if ( e - s == 1) {
                return -1;
        }

        *n = queue[e].node;
        *p = queue[e].parent;
        e++;
        return 0;
}

void bfs(adj_list_t *adj, int visited[], int res[]) {
        while (e - s != 1) {
                int node, parent;
                deq(&node, &parent);
                if(visited[node] == 0) {
                        visited[node] = 1;
                        res[node] = res[parent] + 1;
                        for(int i=0; i < adj->adj_sz[node]; i++) {
                                if (visited[ adj->adj[node][i] ] == 0)
                                        enq(adj->adj[node][i], node);
                        }

                }
        }
}

void shortest_path(adj_list_t *adj, int start, int res[]) {
        int *visited = (int*) calloc(sizeof(int), adj->v);

        res[0] = -1;
        enq(0, 0);
        bfs(adj, visited, res);
}

/*
 * Shortest path between 0 to all nodes.
 * Assuming a connected graph with no weightages.
 */
int main() {
        int v = 7;
        adj_list_t *adj = adj_init(v);
        add_edge(adj, 0, 1);
        add_edge(adj, 0, 2);
        add_edge(adj, 1, 3);
        add_edge(adj, 3, 2);
        add_edge(adj, 0, 4);
        add_edge(adj, 4, 5);
        add_edge(adj, 5, 6);
        add_edge(adj, 6, 4);

        int *res = (int*) calloc(sizeof(int), v);
        shortest_path(adj, 0, res);
  
        printf("To reach node(cost) from 0th-node: ");
        for(int i=0; i < adj->v; i++) {
                printf("%d(%d)  ", i, res[i]);
        }
        printf("\n");
}
