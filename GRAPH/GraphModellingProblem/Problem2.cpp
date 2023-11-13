// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 

/* SHORTEST PATH MODELLING PROBLEM */

/* Problem 2

Statement: You are given an usual undirected graph, 
and you want to find the shortest path from A to B, 
but there is an additional constraint: you must use an even amount of edges.

*/

// Problem Link: https://codeforces.com/blog/entry/45897

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 100000+15;

vector<pair<int,int>> graph[MAX_N];
int n,m;


// defining the graph state for each node;
// creating user defined data types
struct st{
    int vertex;
    int parity;
    int distance;

    st(int vertex, int parity, int distance){
        vertex=vertex;
        parity=parity;
        distance=distance;
    }
    // custom comparator with respect to distance
    // defined inside a struct/class
    bool operator>(const st &s) const { return distance > s.distance; }
};


// Initialize unordered_map for distances
    unordered_map<int, unordered_map<int, int>> dist;  // dist[vertex][parity]

// Time Complexity: O(n*(2))
int dijkstra(){


    priority_queue<st,vector<st>,greater<st>> pq;
    pq.push(st(0,0,0));   // vertex,parity,distance

    while(!pq.empty()){

        st s = pq.top();
        pq.pop();

    // this check just working as visited array check for node with state v and c.
    // TLE nahi aayenga
if (dist[s.vertex].find[pairty]!=dist[s.vertex].end() && dist[s.vertex][s.parity] < s.distance) continue;
dist[s.vertex][s.parity]=s.distance;

// adjacent vertex
for(auto it: graph[s.vertex]){
    int v = it.first;
    int w = it.second;

            if (dist[v].find(s.parity^1) == dist[v].end() || dist[v][s.parity^1] > dist[s.vertex][s.parity]+w) {
                // here instead of using s.distance i have to dist[s.vertex][s.parity] 
                // bcoz s ka distance lekin konsa parity wala wo nahi pata 
                dist[v][s.parity^] = dist[s.vertex][s.parity] + w;
                pq.push(st(v, s.parity^1, dist[s.vertex][s.parity]+w));
        }
    }

}


if(dist[n-1].find(0)==dist[n-1].end()){
    return INF;
}
else {
    return dist[n-1][0];
}


}


void solve(){
    
   
   cin>> n >> m >> C;



   // considering 0-based indexing

   // graph construction 
   for(int i = 0; i<m; i++){

            int u,v,w;
            cin >> u >> v >> w;
            u--;
            v--;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});        
   }

   int res = dijkstra();

   cout << ((res==INF)?-1:res) << endl;


 fflush(stdout);
       cout << flush;

 }
 
int main() {
 
    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif
 
 
// cout<<1<<endl;
ios_base::sync_with_stdio(0);
    cin.tie(0);
 
       solve();
 
       return 0;
}


