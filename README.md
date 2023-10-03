# isprime
- A command-line primality test tool

**DO NOT USE IT FOR CRYPTOGRAPHIC PURPOSES**

## Synopsis
1. `isprime`
   - The input taken from the stdin.
   - The head of lines are interpreted as decimal number, then output whole line to stdout if the number is prime.
2. `isprime <number>`
   - The input taken from 1st command-line argument, and interpreted as decimal.
   - If the number is prime, print `prime` to stdout.
   - If composite, print `composite`.
   - If less than 2, print `not prime`.
3. `isprime <number> <count>`
   - The input taken from 1st and 2nd command-line argument, and interpreted as decimal.
   - If `<count>` is positive, print minimum `<count>` prime numbers larger or equals to `<number>` to stdout.
   - If `<count>` is negative, print maximum `<count>` prime numbers less or equals to `<number>`.
4. `pyeval <expression>`
   - Eval `<expression>` as a python expression and print to stdout.
   - If the result of evaluation is iterable, print it line by line.
   
## Requirement
- GMP: The GNU Multiple Precision Arithmetic Library
  - https://gmplib.org/

## Examples
```
$ isprime 1 25
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
$ isprime 100 -25
97
89
83
79
73
71
67
61
59
53
47
43
41
37
31
29
23
19
17
13
11
7
5
3
2
$ pyeval '[f\'{(1<<i)-1} ({i} th Mercenne number) is a prime number.\' for i in range(1000)]' | isprime
3 (2 th Mercenne number) is a prime number.
7 (3 th Mercenne number) is a prime number.
31 (5 th Mercenne number) is a prime number.
127 (7 th Mercenne number) is a prime number.
8191 (13 th Mercenne number) is a prime number.
131071 (17 th Mercenne number) is a prime number.
524287 (19 th Mercenne number) is a prime number.
2147483647 (31 th Mercenne number) is a prime number.
2305843009213693951 (61 th Mercenne number) is a prime number.
618970019642690137449562111 (89 th Mercenne number) is a prime number.
162259276829213363391578010288127 (107 th Mercenne number) is a prime number.
170141183460469231731687303715884105727 (127 th Mercenne number) is a prime number.
6864797660130609714981900799081393217269435300143305409394463459185543183397656052122559640661454554977296311391480858037121987999716643812574028291115057151 (521 th Mercenne number) is a prime number.
531137992816767098689588206552468627329593117727031923199444138200403559860852242739162502265229285668889329486246501015346579337652707239409519978766587351943831270835393219031728127 (607 th Mercenne number) is a prime number.
$ pyeval '[f\'{"1"*i} ({i} th Repunit number) is a prime number.\' for i in range(1000)]' | isprime
11 (2 th Repunit number) is a prime number.
1111111111111111111 (19 th Repunit number) is a prime number.
11111111111111111111111 (23 th Repunit number) is a prime number.
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111 (317 th Repunit number) is a prime number.
```

## Reference
- https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test

## Author
- Mugi Noda (void-hoge)

## License
- LGPLv3
