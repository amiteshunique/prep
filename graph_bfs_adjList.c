#include<stdio.h>
#include<stdlib.h>

void print_graph(struct adj_list *adj_l);

/***** Adjacency List for undirected graph *****/
struct adj_list {
        int **adj;
        int *adj_sz;
        int v;
};

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

        adj_l->adj_sz[y] += 1;
        int idx_y = adj_l->adj_sz[y];

        //Edges should be added from x->y AND y->x
        adj_l->adj[x][idx_x] = y;
        adj_l->adj[y][idx_y] = x;
}

/************ BFS for undirected disconnected graph *************/
#define SZ 99
int queue[SZ];
int s=-1;
int e=0;

int enq(int i) {
        if (e == SZ-1) {
                return 0;
        }

        s++;
        queue[s] = i;
        return 1;
}

int deq(void) {
        if (e-s == 1) {
                return -1;
        }

        int temp = queue[e];
        e++;
        return temp;
}

void bfs(struct adj_list *adj_l, int visited[]) {
        //Do till queue is empty
        while(e-s != 1) {
                int node = deq();
                if (visited[node] == 1)
                        continue;
                printf("%d ", node);
                int len = adj_l->adj_sz[node];
                for(int i=0; i<=len; i++) {
                        if (visited[i] == 1)
                                continue;
                        enq(i);
                }
                visited[node] = 1;
        }
}

void print_bfs(struct adj_list *adj_l) {
        enq(0);

        int len = adj_l->v;
        int visited[len];
        for(int i=0; i < len ; i++)
                visited[i] = 0;

        /*
         * Run the loop for all nodes
         * If its unvisited, then mark call bfs. This takes care of disconnected graphs as well.
         */
        for(int i=0; i < len; i++) {
                if(visited[i] == 0) {
                        enq(i);
                        bfs(adj_l, visited);
                }
        }
}

int main() {
        int v=7;


        struct adj_list *adj = adj_init(v);

        add_edge(adj, 0, 1);
        add_edge(adj, 0, 2);
        add_edge(adj, 2, 3);
        add_edge(adj, 1, 3);
        add_edge(adj, 4, 5);
        add_edge(adj, 5, 6);
        add_edge(adj, 4, 6);

        print_graph(adj);

        print_bfs(adj);
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
