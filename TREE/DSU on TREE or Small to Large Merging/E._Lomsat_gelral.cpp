// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200 * 1000 + 13;

vector<int> graph[MAX_N];

#define int long long

int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum;

vector<int> vect[MAX_N];
int colors[MAX_N];
int ans[MAX_N];
int cnt[MAX_N];
int res[MAX_N];
int sz[MAX_N];

// slize calculation for each node
void dfs(int source , int parent ){

      sz[source]=1;

      for(auto it: graph[source]){
         if(it!=parent){
            dfs(it,source);
            sz[source]+=sz[it];
         }
      }
}

void update(int source, int& mx, int x){
   ans[cnt[colors[source]]] -=colors[source];
   cnt[colors[source]]+=x;
   ans[cnt[colors[source]]] +=colors[source];
   mx=max(mx,cnt[colors[source]]);
}

// 2nd Coding Style
// TC: O(n*log(n))
int merge(int source, int parent, int keep){
   int mx=0;
   int maxi = -1;
   int maxiNode = -1;

   for(auto it: graph[source]){
      if(it!=parent)
      {
         if(sz[it]>maxi) 
         {
            maxiNode=it;
            maxi=sz[it];
         }
      }
   }

   // smaller child
   for(auto it : graph[source]){
       if(it!=parent && it!=maxiNode){
           merge(it,source,0);
       }
   }

   // Bigger child
   if(maxiNode!=-1){
      mx=max(mx,merge(maxiNode,source,1));
      swap(vect[source],vect[maxiNode]);
   }

   vect[source].push_back(source);

   update(source,mx,1);

   // for smaller child
   for(auto it: graph[source]){
      if(it!=parent && it!=maxiNode){
            for(auto color: vect[it]){
               update(color,mx,1);
               vect[source].push_back(color);
            }
      }
   }

   // ans store karlo
   res[source]=ans[mx];

   // space khali kardo sare childs ka
   if(keep==0){
      for(auto it: vect[source]){
        update(it,mx,-1);
      }
   }

   return mx;
   
}

void solve(){

   cin>> n;

   for(int i = 1; i<=n; i++){
      cin >> colors[i];
   }


   for(int i = 1; i<n; i++){
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   dfs(1,-1);
   merge(1,-1,0);

   for(int i = 1; i<=n; i++){
      cout << res[i] << " ";
   }

       fflush(stdout);
       cout << flush;
    }


int32_t main() {

    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

ios_base::sync_with_stdio(0);
    cin.tie(0);

       solve();

       return 0;
}



