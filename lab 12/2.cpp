// Implement adjacency list 
#include<cstdio>
#include<cstdlib>
#include <list>
using namespace std;

class AdjList{
    private:
        int tableSize;
        list<int>* table;
    public:
        AdjList(int size){
            tableSize=size;
            table = new list<int>[tableSize];
        }
        void insertEdge(int src, int dest);
        void deleteEdge(int src,int dest);
        int searchEdge(int src,int dest);
        bool validIndex(int idx);
        void display();
        ~AdjList(){
            delete [] table;
        }
};
int main() {
    int sizeList;
    printf("Enter number of nodes: ");
    scanf("%d", &sizeList);

    AdjList graph(sizeList);
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
                if(res==-1){
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
bool AdjList::validIndex(int idx) {
    return (idx >= 0 && idx < tableSize);
}
// Function to insert edge between 2 vertices
void AdjList::insertEdge(int src,int dest){
    if (validIndex(src) && validIndex(dest)) {
        for (int x : table[src]) {
            if (x == dest) {
                printf("Edge already exists between %d and %d.\n", src, dest);
                return;
            }
        }
        table[src].push_back(dest);
        // table[dest].push_back(src); // For undirected graph
        printf("Edge inserted between %d and %d.\n", src, dest);
    } else {
        printf("Invalid node indices.\n");
    }
}
// Function to search if ther exists link between 2 vertices
int AdjList::searchEdge(int src, int dest){
    if (validIndex(src) && validIndex(dest)) {
        for (int x : table[src]) {
            if (x == dest) {
                printf("Edge exists between %d and %d.\n", src, dest);
                return 0;
            }
        }
        return -1;
    }else{
        return 2;
    }
}
// Function to delete edge between 2 vertex
void AdjList::deleteEdge(int src, int dest){
    if (validIndex(src) && validIndex(dest)){
        if (searchEdge(src,dest) == -1){
            printf("There is no edge between vertex %d and %d\n",src,dest);
        }else{
            table[src].remove(dest);  
        }
    }else {
        printf("Invalid node indices.\n");
    }
}
// Function to display adjacency list
void AdjList::display(){
    printf("Adjacency list:\n");
    for (int i = 0; i < tableSize; i++) {
        printf("[%d] : ", i);
        for (int key : table[i]) {
            printf("%d ", key);
        }
        printf("\n");
    }
}

