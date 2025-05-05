// Implement adjacency matrix
#include<cstdio>
#include<cstdlib>
class AdjMatrix{
    private:
        int size;
        int** matrix;
    public:
        AdjMatrix(int n){
            size = n;
            matrix = (int**)malloc(size * sizeof(int* ));
            for(int i =0;i<size;i++){
                matrix[i] = (int*)malloc(size * sizeof(int));
                for(int j =0;j<size;j++){
                    matrix[i][j]=0;
                }
            }
        }
        ~AdjMatrix() {
            for (int i = 0; i < size; i++)
                free(matrix[i]);
            free(matrix);
        }
        void display();
        void insertEdge(int src,int dest);
        void deleteEdge(int src,int dest);
        int searchEdge(int src,int dest);
        bool validIndex(int idx);
};
int main() {
    int sizeArr;
    printf("Enter number of nodes: ");
    scanf("%d", &sizeArr);

    AdjMatrix graph(sizeArr);
    int choice, src, dest,res;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Search Edge\n");
        printf("4. Display Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination: ");
                scanf("%d%d", &src, &dest);
                graph.insertEdge(src, dest);
                break;
            case 2:
                printf("Enter source and destination: ");
                scanf("%d%d", &src, &dest);
                graph.deleteEdge(src, dest);
                break;
            case 3:
                printf("Enter source and destination: ");
                scanf("%d%d", &src, &dest);
                res = graph.searchEdge(src, dest);
                if(res==1){
                    printf("No edge exists between %d and %d.\n", src, dest);
                }else if(res == 2){
                    printf("Invalid node indices.\n");
                }
                break;
            case 4:
                graph.display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
// Function to check if the vertex is valid
bool AdjMatrix::validIndex(int idx) {
    return (idx >= 0 && idx < size);
}
// Function to display matrix
void AdjMatrix::display() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
// Function to search if edge exists between two vertex
int AdjMatrix::searchEdge(int src, int dest) {
    if (validIndex(src) && validIndex(dest)) {
        if (matrix[src][dest]){
            printf("Edge exists between %d and %d.\n", src, dest);
            return 0;
        }
        else{
            return 1;
        }
    }else {
        return 2;
    }
}
// Function to delete edge between 2 vertex
void AdjMatrix::deleteEdge(int src, int dest) {
    if (validIndex(src) && validIndex(dest)) {
        matrix[src][dest] = 0;
        // matrix[dest][src] = 0; // For undirected graph
        printf("Edge deleted between %d and %d.\n", src, dest);
    } else {
        printf("Invalid node indices.\n");
    }
}
// Function to insert edge between 2 vertex
void AdjMatrix::insertEdge(int src, int dest) {
    if (validIndex(src) && validIndex(dest)) {
        matrix[src][dest] = 1;
        // matrix[dest][src] = 1; // For undirected graph
        printf("Edge inserted between %d and %d.\n", src, dest);
    } else {
        printf("Invalid node indices.\n");
    }
}


