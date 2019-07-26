//For the Optimal route detection there are majorly Two Algos defined K* and Dijkstra.Here we are using Dijkstra
#include<bits/stdc++.h>
using namespace std;
#define V 12
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) 
{ 
   // Initialize min value 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
   
// A utility function to print the constructed distance array 
int printSolution(int dist[], int n) 
{ 
   //printf("Vertex   Distance from Source\n"); 
   for(int i = 0; i < V; i++) 
      printf(" Optimal distance from source to node %d is %d\n", i, dist[i]); 
} 
   
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void optimal_route(int graph[V][V], int src) 
{ 
     int dist[V];     // The output array.  dist[i] will hold the shortest 
       // distance from src to i 

     bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
                     
     // Initialize all distances as INFINITE and stpSet[] as false 
     for(int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for(int count = 0; count < V-1; count++) 
     { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
       int u = minDistance(dist, sptSet); 
   
       // Mark the picked vertex as processed 
       sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
       for(int v = 0; v < V; v++) 
   
         // Update dist[v] only if is not in sptSet, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
   
     // print the constructed distance array 
     printSolution(dist, V); 
} 
   
//driver program to test above function 
// int main() 
// { 
//    // NETWORK GIVEN IN FIG.25.30(pg no.846)
//     //This code is for Case:1 -------Without any constraint
//    int graph[V][V] = {/*s node*/{0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20}, 
//                       /*q node*/{12, 0, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
//                      /*a node*/ {0, 17, 0, 55, 0, 0, 0, 0, 0, 0, 48, 0}, 
//                      /*b node*/ {0, 0, 55, 0, 40, 0, 0, 0, 0, 63, 0, 0}, 
//                      /*c node*/ {0, 0, 0, 40, 0, 17, 0, 0, 85, 0, 0, 0}, 
//                      /*t node*/ {0, 0, 0, 0, 17, 0, 83, 0, 0, 0, 0, 0}, 
//                      /*g node*/ {0, 0, 0, 0, 0, 83, 0, 28, 0, 0, 0, 0}, 
//                       /*u node*/{0, 0, 0, 0, 0, 0, 28, 0, 15, 0, 0, 0}, 
//                      /*f node*/ {0, 0, 0, 0, 85, 0, 0, 15, 0, 55, 0, 0},
//                      /*d node*/ {0, 0, 0, 63, 0, 0, 0, 0, 55, 0, 43, 0},
//                      /*e node*/ {0, 0, 48, 0, 0, 0, 0, 0, 0, 43, 0, 35},
//                      /*r node*/ {20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 0} 
//                      }; 
   
//     dijkstra(graph, 0); 
   
//     return 0; 
// } 
int main(){
  
   ifstream taken("Case_4_c_to_d_blocked_u_to_f_one_way
    .txt");
   //taken >> V;
   int graph[V][V];
  
   if (!taken) {
    cout << "Error, file couldn't be opened" << endl; 
    return 1; 
  }
  
  for(int i = 0; i < V; i++){
    for(int j = 0; j < V; j++){
      taken >> graph[i][j];
    }
  }
  taken.close();
  optimal_route(graph, 0);
  return 0;
}