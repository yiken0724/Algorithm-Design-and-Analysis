#include <iostream>
#include <time.h>
#include <unistd.h> 
constexpr int INFINITY = 1000000;

typedef struct _graph{
    int vSize;
    int eSize;
    int** AdjM;
}Graph;

//function prototypes;
void dijkstra(Graph, int);
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

    /*
    //fill in the graph (manual generate)
    int w, in, out;
    int end=0;
    while(end!=1){
        printf("Give edge weight, vertex coming from, vertex going to, end(input 1 to end), separated by space \n");
        scanf("%d %d %d %d", &w, &out, &in, &end);
        g.AdjM[out-1][in-1] = w;
        g.eSize++;
    }
    printGraphM(g);
    */

    /*
    //we are creating a complete graph for algorithm analysis (analysing with respect to |V|)
    srand(time(NULL));
    for (int i = 0; i < g.vSize; i++){ 
        for (int j = 0; j < g.vSize; j++){
            if (i == j) //edge cannot connect a node to itself (diagonal entry in g.AdjM should be all 0)
                continue;
            
            int weight = rand()%100 + 1; //+1 is to avoid an edge with 0 weight 

            g.AdjM[i][j] = weight;
            g.eSize++;
        }
    }
    printGraphM(g);
    */
    

   
    //we are not creating complete graph for analysis (analysing with respect to |E|)
    srand(time(NULL)); //analyse |V| = 50, |V| = 100, |V| = 150
    //need to ensure connectivity
    int min_edges = g.vSize - 1; //tree
    int max_edges = g.vSize * (g.vSize - 1) * 0.5; //complete graph
    int edges = 0;
    int *visited = (int*)malloc(g.vSize*sizeof(int));
    for (i=0; i<g.vSize;i++){
        visited[i]=0;
    }

    // printf("Enter number of edges, the minimum number of edges is %d, maximum number of edges is %d: ", min_edges, max_edges);
    // scanf("%d",&edges);

    //assuming that we are doing edges from min to max?
    
    printf("Number of edges\t Time elapsed\n");
    for(int j=min_edges+1; j<=max_edges; j+=10){
        //make connected
        visited[0] = 1;
        for (int v=1; v<g.vSize; v++){
            int u;
            do {
                u = rand()%v;
            }while(!visited[u]);
            g.AdjM[u][v] = rand()%50 + 1;
            g.eSize++;
            visited[v]=1;
        }
        //add in remaining edges
        edges = j-g.eSize;
        for (int i = 0; i < edges; i++){
            int weight;
            int k=0,j=0;
            while(j == k || g.AdjM[j][k] != 0){ //node pointing to itself OR there is weight(visited)
                weight = rand()%50 + 1; //+1 is to avoid an edge with 0 weight 
                j = rand()%(g.vSize);
                k = rand()%(g.vSize);
                // printf("weight: %d, k: %d, k:%d\n", weight,j,k);
            }
            g.AdjM[j][k] = weight;
            g.eSize++;    
        }
        //printGraphM(g);
        
    
        clock_t start = clock();
        //perform dijkstra with adjM and array PQ
        sleep(1); //1 is deducted from outcome later on
        dijkstra(g,1);
        clock_t finish = clock();

        double time_elapsed = (double)(finish-start)/CLOCKS_PER_SEC;

        printf("%d\t %lf\n", j, time_elapsed);
        
        for (i=0; i<g.vSize;i++){
            visited[i]=0;
        }
        for(i=0;i<g.vSize;i++){
            for(int p=0;p<g.vSize;p++){
                g.AdjM[i][p]=0;
            }
        }
        g.eSize=0;
        
    }
}

void dijkstra(Graph g, int source){
    int len = g.vSize;
    int u, i, v;
    int *s = (int*)malloc(len*sizeof(int));
    int *d = (int*)malloc(len*sizeof(int));
    int *PQ = (int*)malloc(len*sizeof(int));
    int *pi = (int*)malloc(len*sizeof(int));
    
    for (i=0; i<len; i++){
        s[i]= 0; //S[i] not visited
        d[i]= INFINITY; //set d[i] to infinity
        pi[i] = -1;  //set p[i] to have no predecessor
        PQ[i] = 0; 
    } 
    
    d[source-1] = 0;

    for (i=1; i<=len; i++){
        PQ[i-1] = i;
        PQsize++;
    }

    while(!isEmpty(PQ)){
        u = peek(PQ);
        dequeue(u, PQ);
        
        s[u-1] = 1;
        for (v=0; v<len; v++){
            if (g.AdjM[u-1][v]>0){
                if(s[v]==0 && d[v]> (d[u-1]+ g.AdjM[u-1][v])){
                    dequeue(v+1, PQ);
                    d[v] = d[u-1]+ g.AdjM[u-1][v];
                    pi[v] = u;
                    enqueue(v+1, d, PQ);
                }
            }
        }
    }
}

void printGraphM(Graph g){
    int i,j;

    for (i=0; i<g.vSize; i++){
        for (j=0; j<g.vSize; j++){
            printf("%d \t", g.AdjM[i][j] );
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
    for (int i = 0; i < PQsize; i++){
        printf("%d ", PQ[i]);
    }
    printf("\n");
}


int peek(int* PQ){
    return PQ[0]; 
}

void enqueue(int v, int* d, int* PQ){ 
    if (PQsize==0){
        PQ[0]=v; 
        PQsize++;
    }
    else
    {
        for(int i=0 ; i<PQsize; i++){
            //insert at i if smaller than current i 
            if (d[v-1]<d[PQ[i]-1]){
                for(int j=PQsize; j>i; j--){
                    PQ[j]=PQ[j-1];
                }
                PQ[i]=v;
                PQsize++;
                break;
            }
            if (i==(PQsize-1)&&(d[v-1]>d[PQ[i]-1])){
                PQ[i+1]=v;
                PQsize++;
                break;
            }
        }
    }
}   


void dequeue(int v, int*PQ){
    if (PQ[PQsize-1]==v){ 
        PQ[PQsize-1]=0;
        PQsize--;
    }
    else{
        for (int i=0; i<PQsize; i++){
            if (PQ[i]==v){
                for (int j=i; j<PQsize; j++){
                    PQ[j] = PQ[j+1];
                }
                PQ[PQsize-1] = 0;
                PQsize--;
                break;
            }
        }
    }
}


int isEmpty(int* PQ){
    if(PQsize==0) 
        return 1;
    else
        return 0;
}

