/***
                 _________________________
                |                         |         
                |_________________________|         
                |           * *           |         
                |          *@IN*          |         
                |___________*_*___________|         
                |                         |
                |_________________________| 
                                    
                                    ~@Scorpion
**/

#include<bits/stdc++.h>
#include<chrono>
#define BOOSTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REPEAT intll t; cin >> t; for(intll iterator=0; iterator<t; iterator++)
#define isEven(e) ((e%2==0?true:false))

#define BLN 1000000000
#define MLN 1000000
#define LKH 100000

typedef long long intll;
typedef long intl;

using namespace std;
using namespace std::chrono;

template<typename E>
inline void write(const E &tar, string end="\n"){ cout << tar << end; }
template<typename E, typename L>
inline void write(const E *tar, const L len, string end=" "){ for(L i=0; i<len; i++) cout << tar[i] << end; }
template<typename E>
inline void write(const vector<E> &tar, intll len=INT64_MAX, string end=" "){len=min(len, (intll)tar.size());for(intll i=0; i<len; i++) cout << tar[i] << end;}
template<typename E>
inline void read(E &tar){ cin >> tar; }
template<typename E, typename L>
inline void read(E *tar, const L len){ for(L i=0; i<len; i++) cin >> tar[i]; }
template<typename E, typename L>
inline void read(vector<E> &tar, const L len){if(tar.size()>0) for(L i=0; i<tar.size(); i++) cin >> tar[i]; else for(L i=0; i<len; i++){ E temp; cin >> temp; tar.push_back(temp);}}
class File: public fstream{
    public:
        File(){}
        File(string name):fstream(name){}
        template<typename E>
        inline void write(const E &tar, string end="\n"){ (*this)<< tar << end; }
        template<typename E, typename L>
        inline void write(const E *tar, const L len, string end=" "){ for(L i=0; i<len; i++) (*this) << tar[i] << end; }
        template<typename E>
        inline void write(const vector<E> &tar, string end=" "){ for(intll i=0; i<tar.size(); i++) (*this) << tar[i] << end; }
        template<typename E>
        inline void read(E &tar){ (*this) >> tar; }
        template<typename E, typename L>
        inline void read(E *tar, const L len){ for(L i=0; i<len; i++) (*this) >> tar[i]; }
        template<typename E, typename L>
        inline void read(vector<E> &tar, const L len){if(tar.size()>0) for(L i=0; i<tar.size(); i++) (*this) >> tar[i]; else for(L i=0; i<len; i++){ E temp; (*this) >> temp; tar.push_back(temp);}}
};
template<typename E>
E power(E val, intll expo){
    E res = (E)1;
    while(expo > 1LL){
        if(expo % 2LL==0LL) val *= val,  expo/=2LL;
        else res *= val, --expo;
    }
    val *= res;
    return val;
}
template<typename E>
E modPower(E val, intll expo, intll mod=BLN+7){
    E res = (E)1;
    while(expo > 0LL){
        // odd
        if(expo & 1LL) res = (res%mod) * (val%mod)%mod;
        expo >>= 1LL;
        val = (val%mod) * (val%mod) % mod;
    }
    return res%mod;
}
template<typename E>
void cookPrimes(vector<E> &primes, intll upto=MLN){
    bool p[upto];
    memset(p, false, sizeof(p));
    for(intll  i = 2 ;i*i <= upto ; i++){
        intll m = i * i;
        if(p[i] == false){
            while( m <= upto){
                p[m] = true;
                m += i;
            }
        }
    }
    for(intll i = 2 ; i <= upto; i++) if(p[i] == false) primes.push_back(i);
}




int main(){
    BOOSTER
    vector<int> qty;
    int temp;
    intll total_qty=0;
    while(cin>>temp){
        if(temp==0)continue;
        qty.push_back(temp), total_qty+=temp;
    }
    int n=qty.size();
    bool kp[n+1][total_qty+1];

    for(int i=0; i<=n; i++)kp[i][0]=true;
    for(int i=1; i<=total_qty; i++) kp[0][i]=false;

    for(int row=1; row<=n; row++){
        for(int max_qty=1; max_qty<=total_qty; max_qty++){
            kp[row][max_qty]=kp[row-1][max_qty];
            if(qty[row-1]<=max_qty)
                kp[row][max_qty]|=kp[row-1][max_qty-qty[row-1]];
        }
    }
    intll v1_qty=total_qty/2;
    for(; v1_qty and not kp[n][v1_qty] ; v1_qty--);

    write(total_qty - v1_qty);
    return 0;
}
