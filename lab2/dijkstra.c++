#include <iostream>
constexpr int INFINITY = 1000000;

typedef struct _graph{
    int vSize;
    int eSize;
    int** AdjM;
}Graph;

//function prototypes;

void dijkstra(Graph);
void printPQ(int*);
void printGraphM(Graph);
void printDijkstraOutcome(int*, int*, int*, int);
int peek(int*);
void enqueue(int, int*, int*);
void dequeue(int, int*);
int isEmpty(int*);

//global variable 
int PQsize = 0;

int main(){
    //create new graph
    Graph g;
    int i,j;

    //initialise vSize
    printf("Enter the number of vertices:\n");
    scanf("%d",&g.vSize);

    //initialise eSize
    g.eSize = 0;

    //initialise adjM
    g.AdjM = (int **)malloc(g.vSize*sizeof(int*));
    for(i=0;i<g.vSize;i++){
        g.AdjM[i] = (int*)malloc(g.vSize*sizeof(int));
    }

    for(i=0;i<g.vSize;i++){
        for(j=0;j<g.vSize;j++){
            g.AdjM[i][j]=0;
        }
    }

    //fill in the graph
    int w, in, out;
    int end=0;
    while(end!=1){
        printf("Give edge weight, vertex coming from, vertex going to, end(input 1 to end), separated by space \n");
        scanf("%d %d %d %d", &w, &out, &in, &end);
        g.AdjM[out-1][in-1] = w;
        g.eSize++;
    }
    
    //print graph matrix
    printGraphM(g);

    //perform dijkstra with adjM and array PQ
}

//implement dijkstra algo
void dijkstra(Graph g, int source){
    int len = g.vSize;
    int *s, *d, *pi, *PQ;
    int u, i, v;
    
    for (i=0; i<len; i++){
        s[i]= 0; //S[i] not visited
        d[i]= INFINITY; //set d[i] to infinity
        pi[i] = NULL;  //set p[i] to have no predecessor
        PQ[i] = NULL; 
    } //initialize arrays

    s[source-1] = 1;
    d[source-1] = 0;
    pi[source-1] = NULL;
    
    //put all vertices in PQ in increasing order of d[v]
    for (i=1; i<=len; i++){
        enqueue(i, d, PQ);
    }

    while(!isEmpty(PQ)){
        u = peek(PQ);
        s[u-1] = 1;
        for (v=0; v<len; v++){
            if (g.AdjM[u-1][v]>0){
                if(s[v]==0 && d[v]> (d[u]+ g.AdjM[u-1][v])){
                    dequeue(v+1, PQ);
                    d[v] = d[u]+ g.AdjM[u-1][v];
                    pi[v] = u-1;
                    enqueue(v, d, PQ);
                }
            }
        }
    }
    printDijkstraOutcome(s,d,pi,len);
}

//implement printGraphMatrix
void printGraphM(Graph g){
    int i,j;

    for (i=0; i<g.vSize; i++){
        for (j=0; j<g.vSize; j++){
            printf("%d", g.AdjM[i][j] );
            printf("\t");
        }
        printf("\n");
    }
}

void printDijkstraOutcome(int* s, int* d, int* pi, int len){
    printf("s: ");
    for (int i=0; i<len; i++){
        printf("%d \t", s[i]);
    }
    printf("\n");

    printf("d: ");
    for (int i=0; i<len; i++){
        printf("%d \t", d[i]);
    }
    printf("\n");

    printf("pi: ");
    for (int i=0; i<len; i++){
        printf("%d \t", pi[i]);
    }
    printf("\n");
}

void printPQ(int* PQ){
    printf("Priority queue: \n");
    printf("The nodes are sorted from highest priority to lowest priority:\n");
    for (int i = 0; i < PQsize; i++){
        printf("%d ", PQ[i]);
    }
}

//give the vertex with lowest d, the one at the head of the queue 
//(can return the num on the graph, no need the -1 form)
int peek(int* PQ){
    return PQ[0]; //return the first vertex in PQ (first slot PQ[0])
}

//put vertice, v in priority queue, PQ, in increasing order of d[v], the i passed in is havent -1 de
void enqueue(int v, int* d, int* PQ){ //one for loop is needed only as one vertex is added at a time to back of PQ (PQ[PQsize])

    //insert into last slot of PQ
    PQ[PQsize] = v; //d[v-1] is the weight of the newly added vertex
    PQsize ++;

    for(int i = PQsize; i>0; i--){           
        if(d[i] < d[i-1]){
            int temp_d = d[i];
            d[i] = d[i-1];
            d[i-1] = temp_d; //how to sort PQ when PQ and d are different arrays? :)
        }
        else
            break;
    }
}

//remove vertice that is of index passed in, index passed in is havent -1 de
void dequeue(int v, int*PQ){
    int index = v-1;
    
    for (int i = index; i < PQsize; i++)
        PQ[i] = PQ[i+1];

    PQsize-=1;
}

//return if PQ is empty, 1 means empty
int isEmpty(int* PQ){
    if (peek(PQ) == 0) //PQ is empty when the first slot vertex PQ[0] is 0 (our vertex starts form 1)
        return 1;
    else
        return 0;
}