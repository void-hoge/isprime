#pragma once

#include <gmp.h>
#include <gmpxx.h>
#include <cstdint>

constexpr std::int32_t k = 100;

static gmp_randclass gmp_rnd(gmp_randinit_default);

bool check_primality(const mpz_class& num);
