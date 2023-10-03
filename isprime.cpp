#include "miller_rabin.hpp"

#include <iostream>
#include <sstream>

int main(const int argc, const char **argv) {
	if (argc == 1) {
		std::string line;
		while (std::getline(std::cin, line)) {
			std::stringstream ss(line);
			std::string str;
			ss >> str;
			mpz_class num;
			mpz_set_str(num.get_mpz_t(), str.data(), 10);
			if (check_primality(num)) {
				std::cout << line << std::endl;
			}
		}
	}else if (argc == 2) {
		mpz_class num;
		mpz_set_str(num.get_mpz_t(), argv[1], 10);
		if (num <= 1) {
			std::cout << "not prime" << std::endl;
		}else if (check_primality(num)) {
			std::cout << "prime" << std::endl;
		}else {
			std::cout << "composite" << std::endl;
		}
	}else if (argc >= 3) {
		mpz_class num;
		mpz_set_str(num.get_mpz_t(), argv[1], 10);
		std::int32_t count = std::stoi(argv[2]);
		std::int32_t increment = count < 0 ? -1 : 1;
		count = count < 0 ? -count : count;
		while (count > 0) {
			if (num < 0) {
				break;
			}
			if (check_primality(num)) {
				std::cout << num << std::endl;
				count--;
			}
			num += increment;
		}
	}
	return 0;
}
