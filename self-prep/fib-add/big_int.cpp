//
// Created by user on 4/23/2026.
//

#include "big_int.h"
#include <algorithm>
#include <iomanip>


BigInteger::BigInteger(int32_t value) {
    storage.push_back(value);
}

BigInteger::BigInteger(const BigInteger &other) {
    storage = other.storage;
}

BigInteger &BigInteger::operator=(const BigInteger &other) {
    storage = other.storage;
    return *this;
}

BigInteger &BigInteger::operator+=(const BigInteger &other) {
    size_t n = storage.size();
    size_t m = other.storage.size();
    int carry = 0;
    storage.resize(std::max(n, m));
    for (int i = 0; i < std::max(n, m); ++i) {
        int digit1 = i < n ? storage[i] : 0;
        int digit2 = i < m ? other.storage[i] : 0;
        int digit = digit1 + digit2 + carry;
        carry = digit / base;
        digit %= base;
        storage[i] = digit;
    }
    if (carry) {
        storage.push_back(carry);
    }
    return *this;
}

BigInteger &BigInteger::operator*=(BigInteger other) {
    BigInteger sum(0);
    for (int digit: storage) {
        sum += other * digit;
        other <<= 1;
    }
    return *this = sum;
}

BigInteger &BigInteger::operator*=(int32_t other) {
    int32_t carry = 0;
    for (int &bucket: storage) {
        int64_t digit = bucket;
        int64_t new_digit = digit * other + carry;
        carry = static_cast<int32_t>(new_digit / base);
        new_digit %= base;
        bucket = static_cast<int32_t>(new_digit);
    }
    if (carry) {
        storage.push_back(carry);
    }
    return *this;
}

BigInteger BigInteger::operator*(int32_t other) const {
    BigInteger lhs(*this);
    lhs *= other;
    return lhs;
}

BigInteger &BigInteger::operator<<=(size_t shift) {
    storage.insert(storage.begin(), shift, 0);
    return *this;
}

BigInteger operator+(BigInteger lhs, const BigInteger &rhs) {
    return lhs += rhs;
}

BigInteger operator*(BigInteger lhs, const BigInteger &rhs) {
    return lhs *= rhs;
}

std::ostream &operator<<(std::ostream &stream, const BigInteger &rhs) {

    for (int i = rhs.storage.size() - 1; i >= 0; --i) {
        if (i == rhs.storage.size() - 1) {
            stream << rhs.storage[i];
            continue;
        }
        stream << std::setfill('0') << std::setw(9) << rhs.storage[i];
    }
    return stream;
}
