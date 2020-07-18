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
    int n;
    read(n);
    int numbers[n];
    read(numbers, n);
    vector<pair<int, int>> hashTable(10);

    int d1,d2,d3, mn, mx, bit_score;
    for(int i=0; i<n; i++){
        d1=numbers[i]/100;
        d2=numbers[i]/10 % 10;
        d3=numbers[i]%10;
        mx=max(d1, max(d2, d3));
        mn=min(d1, min(d2, d3));
        bit_score = mx*11+mn*7;
        if(i%2==0) hashTable[bit_score / 10 % 10].first++;
        else hashTable[bit_score / 10 % 10].second++;
    }
    intll ans=0;
    int temp;
    for(auto e: hashTable){
        temp=max(e.first, e.second);
        if(temp==2)ans++;
        else if(temp>2) ans+=2;
    }
    write(ans);
    return 0;
}
