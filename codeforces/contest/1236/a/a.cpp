#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ksc(LL a, LL n, LL mod) {
	LL ret = 0;
	for(;n;n>>=1) {
		if(n&1) {ret += a; if(ret >= mod) ret -= mod;}
		a<<=1; if(a >= mod) a -= mod;
	}
	return ret;
}
LL ksm(LL a, LL n, LL mod) {
	LL ret = 1;
	for(;n;n>>=1) {
		if(n&1) ret=ksc(ret,a,mod);
		a = ksc(a, a, mod);
	}
	return ret;
}
bool millerRabin(LL n) {
	if(n < 2 || (n != 2 && !(n & 1))) return 0;
	LL d = n - 1; for(;!(d&1); d>>=1);
	for(int i = 0; i < 10; ++i) {
		LL a = rand()%(n-1)+1;
		LL t = d, m = ksm(a, d, n);
		for(;t != n-1 && m != 1 && m != n-1; m = ksc(m,m,n),t<<=1);
		if(m!=n-1 && !(t&1)) return 0;
	}
	return 1;
}
const int MAXN = 1e6;
int prime[MAXN], cnt, phi[MAXN], mu[MAXN];
bool isp[MAXN];

int min_pow[MAXN];   //最小质因子最高次幂
int min_sum[MAXN];   //1+p+p^2+...+p^k
int div_sum[MAXN];   //约数和

int min_index[MAXN]; //最小质因子的指数
int div_num[MAXN];   //约数个数
void Euler(int n) {
    mu[1] = phi[1] = div_num[1] = div_sum[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!isp[i]) {
            prime[++cnt] = min_pow[i] = i;
            phi[i] = i - 1;
            mu[i] = -1;
            min_index[i] = 1; div_num[i] = 2;
            div_sum[i] = min_sum[i] = i + 1;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            isp[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                mu[i * prime[j]] = 0;

                min_index[i * prime[j]] = min_index[i] + 1;
                div_num[i * prime[j]] = div_num[i] / (min_index[i] + 1) * (min_index[i * prime[j]] + 1);

                min_sum[i * prime[j]] = min_sum[i] + min_pow[i] * prime[j];
                div_sum[i * prime[j]] = div_sum[i] / min_sum[i] * min_sum[i * prime[j]];
                min_pow[i * prime[j]] = min_pow[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            mu[i * prime[j]] = -mu[i];

            div_num[i * prime[j]] = div_num[i] << 1;
            min_index[i * prime[j]] = 1;

            div_sum[i * prime[j]] = div_sum[i] * (prime[j] + 1);
            min_pow[i * prime[j]] = prime[j];
            min_sum[i * prime[j]] = prime[j] + 1;
        }
    }
}
int main() {
    int n = 1e6;
    Euler(n);
    cout<<"!!!"<<endl;
    for(int i = 2; i < n; i++){
        if(millerRabin(i) == isp[i]) {
            cout<<i<<endl;
            break;
        }
    }
}