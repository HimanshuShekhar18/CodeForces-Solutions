// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 

/* SHORTEST PATH MODELLING PROBLEM */

/* Problem 1

Statement: You want to travel from city A to city B. There are N cities and M bidirectional roads connecting cities.
Your car can store up to C liters of fuel and the tank is initially full. each road (i,j) has a value Wij that represents the amount of liters of fuel to cross this road.
Also, in every city you can buy fuel, at a price of C[i] dollar / litre.
You must compute the minimum amount of dollars spent with fuel to travel from A to B.


*/

// Problem Link: https://codeforces.com/blog/entry/45897

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 100000+15;

vector<pair<int,int>> graph[MAX_N];
int dist[MAX_N][55];   // dist[vertex][feul]
int n,m,C;   // C --> Limit Fuel
int cost[MAX_N];

// defining the graph state for each node;
// creating user defined data types
struct st{
    int vertex;
    int fuel;
    int dollar;

    st(int vertex, int fuel, int dollar){
        vertex=vertex;
        fuel=fuel;
        dollar=dollar;
    }
    // custom comparator with respect to dollar
    // defined inside a struct/class
    bool operator>(const st &s) const { return dollar > s.dollar; }
};

int dijkstra(){

    // initializing a 2D-array
    fill(&dist[0][0],&dist[0][0]+(MAX_N*55),INF);
    priority_queue<st,vector<st>,greater<st>> pq;
    pq.push(st(0,C,0));   // vertex,remainingfuel,dollar

    while(!pq.empty()){

        st s = pq.top();
        pq.pop();

    // this check just working as visited array check for node with state v and c.
    // TLE nahi aayenga
if (dist[s.vertex][s.fuel] < s.dollar) continue;
dist[s.vertex][s.fuel]=s.dollar;

// adjacent vertex
for(auto it: graph[s.vertex]){
    int v = it.first;
    int w = it.second;

    // Trying out with different remaining fuel upto C limit(0,1,2,3)
    for(int i = C-s.fuel; i>=0&&s.fuel+i-w>=0; i--){
        if(dist[v][s.fuel+i-w]>s.dollar+i*cost[s.vertex]){
            dist[v][s.fuel+i-w]=s.dollar+i*cost[s.vertex];
            pq.push(st(v,s.fuel+i-w,dist[v][s.fuel+i-w]));
        }
    }
 }

}

int res = INF;
for(int i = 0; i<=C; i++){
    res = min(res,dist[n-1][i]);
}

return res;

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


   // cost array for each vertex
   for(int i = 0; i<n; i++){

        cin >> cost[i];

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






// <------------------------------------------------------------------------------USING unordered_map------------------------------------------------------------------------------------>


// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
 

/* SHORTEST PATH MODELLING PROBLEM */

/* Problem 1

Statement: You want to travel from city A to city B. There are N cities and M bidirectional roads connecting cities.
Your car can store up to C liters of fuel and the tank is initially full. each road (i,j) has a value Wij that represents the amount of liters of fuel to cross this road.
Also, in every city you can buy fuel, at a price of C[i] dollar / litre.
You must compute the minimum amount of dollars spent with fuel to travel from A to B.


*/

// Problem Link: https://codeforces.com/blog/entry/45897

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_N = 100000+15;

vector<pair<int,int>> graph[MAX_N];
int n,m,C;   // C --> Limit Fuel
int cost[MAX_N];

// defining the graph state for each node;
// creating user defined data types
struct st{
    int vertex;
    int fuel;
    int dollar;

    st(int vertex, int fuel, int dollar){
        vertex=vertex;
        fuel=fuel;
        dollar=dollar;
    }
    // custom comparator with respect to dollar
    // defined inside a struct/class
    bool operator>(const st &s) const { return dollar > s.dollar; }
};


// Initialize unordered_map for distances
    unordered_map<int, unordered_map<int, int>> dist;  // dist[vertex][remainingfuel]

// Time Complexity: O(n*(C+1))
int dijkstra(){

    priority_queue<st,vector<st>,greater<st>> pq;
    pq.push(st(0,C,0));   // vertex,remainingfuel,dollar

    while(!pq.empty()){

        st s = pq.top();
        pq.pop();

    // this check just working as visited array check for node with state v and c.
    // TLE nahi aayenga
if (dist[s.vertex].find(s.fuel) != dist[s.vertex].end() && dist[s.vertex][s.fuel] < s.dollar) continue;
        dist[s.vertex][s.fuel] = s.dollar;

// adjacent vertex
for(auto it: graph[s.vertex]){
    int v = it.first;
    int w = it.second;

    // Trying out with different remaining fuel upto C limit(0,1,2,3)
    for (int i = C - s.fuel; i >= 0 && s.fuel + i - w >= 0; i--) {
            if (dist[v].find(s.fuel + i - w) == dist[v].end() ||
                dist[v][s.fuel + i - w] > s.dollar + i * cost[s.vertex]) {
                dist[v][s.fuel + i - w] = s.dollar + i * cost[s.vertex];
                pq.push(st(v, s.fuel + i - w, dist[v][s.fuel + i - w]));
            }
        }
 }

}

int res = INF;
for(int i = 0; i<=C; i++){
    if (dist[n - 1].find(i) != dist[n - 1].end()) {
            res = min(res, dist[n - 1][i]);
        }
}

return res;

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


   // cost array for each vertex
   for(int i = 0; i<n; i++){

        cin >> cost[i];

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
