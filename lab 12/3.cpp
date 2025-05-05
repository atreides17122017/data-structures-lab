#include <cstdio>
#include <cstdlib>
#define INF 999999

class graph{
    private:
        int vertices;
        int **adj;
        struct edge{
            int src, dest, weight;
        };
    public:
        graph(int v){
            vertices = v;
            adj = (int **)malloc(vertices * sizeof(int *));
            for (int i = 0; i < vertices; i++)
            {
                adj[i] = (int *)malloc(vertices * sizeof(int));
                for (int j = 0; j < vertices; j++)
                    adj[i][j] = 0;
            }
        }
        void insert_edge(int src, int dest, int weight);
        void display();
        void prims();
        int find_parent(int *parent, int vertex);
        void union_set(int *parent, int vertex1, int vertex2);
        void kruskal();
        void dijkstra(int src);
        ~graph(){
            for (int i = 0; i < vertices; i++)
                free(adj[i]);
            free(adj);
        }
};

int main(){
    int src, dest, weight;
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    if (v <= 0){
        printf("Invalid number of vertices!\n");
        return 0;
    }

    graph g(v);
    int choice;
    while(1){
        printf("\n----Graph Menu-----\n");
        printf("1. Insert Edge\n");
        printf("2. Display\n");
        printf("3. Prim's Algorithm\n");
        printf("4. Kruskal's Algorithm\n");
        printf("5. Dijkstra's Algorithm\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            
            printf("Enter source, destination, and weight: ");
            scanf("%d %d %d", &src, &dest, &weight);
            g.insert_edge(src, dest, weight);
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.prims();
            break;
        case 4:
            g.kruskal();
            break;
        case 5:
            
            printf("Enter source vertex: ");
            scanf("%d", &src);
            g.dijkstra(src);
            break;
        case 6:
            printf("Terminating program...\n");
            return 0;
        default:
            printf("Invalid choice...Try again...\n");
        }
    }
}
//Function to Insert edge
void graph::insert_edge(int src, int dest, int weight){
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices){
        printf("Invalid vertices.Vertices must be in range 0 to %d\n", vertices - 1);
        return;
    }
    adj[src][dest] = weight;
    adj[dest][src] = weight;
    printf("Edge inserted between %d and %d with weight %d\n", src, dest, weight);
}
// Function to display the adjacency matrix
void graph::display(){
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
// Function to implement Prim's algorithm
void graph:: prims(){
    int *key = (int *)malloc(vertices * sizeof(int));
    int *parent = (int *)malloc(vertices * sizeof(int));
    int *mstSet = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++){
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++){
        int min = INF, next_vertex = -1;
        for (int v = 0; v < vertices; v++){
            if (mstSet[v] == 0 && key[v] < min){
                min = key[v];
                next_vertex = v;
            }
        }
        if (next_vertex == -1){
            printf("Graph is disconnected!\n");
            return;
        }
        mstSet[next_vertex] = 1;
        for (int v = 0; v < vertices; v++){
            if (adj[next_vertex][v] && mstSet[v] == 0 && adj[next_vertex][v] < key[v]){
                key[v] = adj[next_vertex][v];
                parent[v] = next_vertex;
            }
        }
    }

    printf("Prim's MST:\n");
    printf("Edge\tWeight\n");
    int total = 0;
    for (int i = 1; i < vertices; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, adj[i][parent[i]]);
        total += adj[i][parent[i]];
    }
    printf("Total weight: %d\n", total);

    free(key);
    free(parent);
    free(mstSet);
}
// Function to find the parent 
int graph::find_parent(int *parent, int vertex){
    if (parent[vertex] == vertex)
        return vertex;
    return find_parent(parent, parent[vertex]);
}
// Function to merge two disjoint sets
void graph::union_set(int *parent, int vertex1, int vertex2){
    int parent1 = find_parent(parent, vertex1);
    int parent2 = find_parent(parent, vertex2);
    parent[parent1] = parent2;
}
// Function to implement Kruskal's algorithm
void graph:: kruskal(){
    struct edge *edges = (struct edge *)malloc(vertices * vertices * sizeof(struct edge));
    int edgeCount = 0;
    for (int i = 0; i < vertices; i++){
        for (int j = i + 1; j < vertices; j++){
            if (adj[i][j] != 0){
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = adj[i][j];
                edgeCount++;
            }
        }
    }
    for (int i = 0; i < edgeCount - 1; i++){
        for (int j = 0; j < edgeCount - i - 1; j++){
            if (edges[j].weight > edges[j + 1].weight){
                struct edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int *parent = (int *)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    printf("Kruskal's MST:\n");
    int total = 0, count = 0;

    for (int i = 0; i < edgeCount; i++){
        int src_vertex = edges[i].src;
        int dest_vertex = edges[i].dest;
        int src_parent = find_parent(parent, src_vertex);
        int dest_parent = find_parent(parent, dest_vertex);

        if (src_parent != dest_parent){
            printf("%d - %d : %d\n", src_vertex, dest_vertex, edges[i].weight);
            total += edges[i].weight;
            union_set(parent, src_parent, dest_parent);
            count++;
            if (count == vertices - 1)
                break;
        }
    }
    printf("Total weight: %d\n", total);

    free(edges);
    free(parent);
}
// Function to implement Dijkstra's algorithm
void graph:: dijkstra(int src){
    int *dist = (int *)malloc(vertices * sizeof(int));
    int *visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++){
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++){
        int min = INF, currVertex = -1;
        for (int v = 0; v < vertices; v++){
            if (!visited[v] && dist[v] <= min){
                min = dist[v];
                currVertex = v;
            }
        }

        if (currVertex == -1){
            printf("Graph is disconnected!\n");
            return;
        }

        visited[currVertex] = 1;

        for (int v = 0; v < vertices; v++){
            if (!visited[v] && adj[currVertex][v] && dist[currVertex] + adj[currVertex][v] < dist[v])
            {
                dist[v] = dist[currVertex] + adj[currVertex][v];
            }
        }
    }

    printf("Dijkstra's shortest paths from source %d:\n", src);
    printf("Vertex\tDistance\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }

    free(dist);
    free(visited);
}


