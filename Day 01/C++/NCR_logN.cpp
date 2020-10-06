//MAXN = 1e6+100;
int fact[MAXN], inf[MAXN];
int po2[MAXN];

void pre() {
  fact[0] = 1;
  po2[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = (i * fact[i - 1]) % mod;
    po2[i] = (2 * po2[i - 1]) % mod;
  }
  inf[MAXN - 1] = inv(fact[MAXN - 1]);

  for (int i = MAXN - 2; i >= 0; --i) {
    inf[i] = (inf[i + 1] * (i + 1)) % mod;
  }
}

inline int ncr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return (fact[n] * ((inf[n - r] * inf[r]) % mod)) % mod;
}

//pre() first and then ncr();