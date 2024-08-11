// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
#define ll long long 

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


/*-----------------------------------------------------------------functions--------------------------------------------------------------*/


void solve(){
 
        string S;
        cin >> S; 
        string str;
        cin >> str;
        cin >> k;

        n = S.length();

        unordered_set<string> st;

        for(int i = 0; i<n; i++){

            long long hash1 = 0, hash2 = 0;
            long long P1 = 31, P2 = 29;
            long p_pow1 = 1, p_pow2 = 1;
            int badcount = 0;

            for(int j = i; j<n; j++){

                badcount+=str[S[j]-'a']=='0'?1:0;
                if(badcount>k) break;

                hash1 = (hash1 + (S[j]-'a'+1)*p_pow1)%MOD;
                hash2 = (hash2 + (S[j]-'a'+1)*p_pow2)%MOD;
                p_pow1 = (p_pow1*P1)%MOD;
                p_pow2 = (p_pow2*P2)%MOD;

                st.insert(to_string(hash1)+","+to_string(hash2));
            }
        }

        cout << st.size() << endl;


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


