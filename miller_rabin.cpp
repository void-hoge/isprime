#include "miller_rabin.hpp"

mpz_class modexp(mpz_class base, mpz_class exp, const mpz_class& mod) {
	mpz_class ans = 1;
	while (exp != 0) {
		if ((exp & 1) == 1) {
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		exp >>= 1;
	}
	return ans;
}

bool check_primality(const mpz_class& num) {
	if (num == 2) return true;
	if (num < 2 or (num & 1) == 0) return false;
	mpz_class m = num - 1;
	std::uint32_t s = mpz_scan1(m.get_mpz_t(), 0);
	mpz_class d = num >> s;
	for (std::int32_t i = 0; i < k; i++) {
		mpz_class a = gmp_rnd.get_z_range(num - 2) + 1;
		mpz_class t = d;
		mpz_class y = modexp(a, t, num);
		while ((t != num - 1) and (y != 1) and (y != num - 1)) {
			y = y * y % num;
			t <<= 1;
		}
		if ((y != num - 1) and ((t & 1) == 0)) {
			return false;
		}
	}
	return true;
}
