#ifndef BIN_EXP_H
#define BIN_EXP_H

template<typename T>
T power(T b, int e) {
    T acc = T::identity();
    T mult = b;
    while (e > 0) {
        if (e % 2) {
            acc *= mult;
        }
        mult *= mult;
        e /= 2;
    }
    return acc;
}

#endif
