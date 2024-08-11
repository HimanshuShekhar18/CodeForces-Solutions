// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>

using namespace std;


#define ll long long 

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


/*-----------------------------------------------------------------functions--------------------------------------------------------------*/

vector<long long> p_pow;
vector<long long> inv_p_pow;
const int P = 173ll; 
const int MOD = 1000000021ll;

ll expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res%MOD;
}

void ComputePower() {
        

        int N = n;
        p_pow.resize(N, 1);
        for (int i = 1; i < N; i ++)
            p_pow[i] = (p_pow[i-1] * P) % MOD;
        
        inv_p_pow.resize(N, 1);
        
        inv_p_pow[N-1] = expo(p_pow[N-1], MOD-2);
        for (int i = N-2; i > 0; i --)
            inv_p_pow[i] = (inv_p_pow[i+1] * P) % MOD;

}




void solve(){


        
        string S;
        cin >> S; 
        n = S.length();

        ComputePower();

        // Prefix Hashing the String RABIN KARP Algorithm
        vector<long long> hash_S(n+1,0);

        for(int i = 0; i<n; i++){
             
            hash_S[i+1] = (hash_S[i] + (S[i]-'a'+1)*p_pow[i])%MOD;
        }

        

        ans = 0;
        for(int i = 0; i<n-1; i++){

            long long prefix = hash_S[i+1];
            long long suffix = (hash_S[n]-hash_S[n-i-1]+MOD)%MOD;



            if((prefix*p_pow[n-i-1])%MOD == suffix){
                int len = i+1;
                for(int j = 1; j+len-1<=n-2; j++){
                    long long midvalue = (hash_S[j+len]-hash_S[j]+MOD)%MOD;
                    if((prefix*p_pow[j])%MOD==midvalue){
                        ans = i+1;
                        break;
                    }
                }
            }

        }



        if(ans==0){
            cout << "Just a legend" << endl;
        }
        else{
            cout << S.substr(0,ans) << endl;
        }


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



ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     
       solve();


       return 0;
}
