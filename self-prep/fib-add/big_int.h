//
// Created by user on 4/23/2026.
//

#ifndef TASKS_BIG_INT_H
#define TASKS_BIG_INT_H

#include <iostream>
#include <vector>

struct BigInteger {
    static constexpr int32_t base = 1'000'000'000;

    std::vector<int32_t> storage;

    BigInteger(int32_t value = 0);

    BigInteger(const BigInteger &other);

    BigInteger &operator=(const BigInteger &other);

    BigInteger &operator+=(const BigInteger &other);

    BigInteger &operator*=(BigInteger other);

    BigInteger &operator*=(int32_t other);

    BigInteger operator*(int32_t other) const;

    BigInteger &operator<<=(size_t shift);

    friend BigInteger operator+(BigInteger lhs, const BigInteger &rhs);

    friend BigInteger operator*(BigInteger lhs, const BigInteger &rhs);

    friend std::ostream &operator<<(std::ostream &stream, const BigInteger &rhs);
};


#endif //TASKS_BIG_INT_H
