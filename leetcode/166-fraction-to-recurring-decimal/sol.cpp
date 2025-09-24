#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


string fractionToDecimal(int numerator, int denominator) {
    long long a = numerator, b = denominator;
    // cout << "fraction: " << a << '/' << b << '\n';
    string sign = "";
    long long q = 0;
    if (a == 0) {
        return "0";
    }
    if (a < 0 && b > 0) {
        sign = '-';
        a *= -1;
    }
    if (b < 0 && a > 0) {
        sign = '-';
        b *= -1;
    }
    a = abs(a);
    b = abs(b);
    if (a >= b) {
        q += a / b;
        a %= b;
    }
    unordered_map<long long, int> rems;
    string r = "";
    if (a > 0) {
        long long rem = a;
        do {
            rems[rem] = r.size();
            // cout << "added " + to_string(rem) + '\n';
            rem *= 10;
            r += to_string(rem / b);
            rem %= b;
        }
        while (rem != 0 && !rems.contains(rem));
        // cout << "repeated rem: " << to_string(rem) << ' ' << rems[rem] << '\n';
        if (rem != 0) {
            r.insert(rems[rem], 1, '(');
            r += ')';
            // r += "(" + to_string(rems[rem]) + ")";
        }
    } else {
        return sign + to_string(q);
    }
    return sign + to_string(q) + '.' + r;
}


int main(int argc, char const *argv[])
{
    cout << fractionToDecimal(3,7) << '\n';
    cout << fractionToDecimal(-2,7) << '\n';
    cout << fractionToDecimal(-4, -7) << '\n';

    cout << '\n';

    cout << fractionToDecimal(0,-8) << '\n';
    cout << fractionToDecimal(0,1) << '\n';
    cout << fractionToDecimal(0,-1) << '\n';
    cout << fractionToDecimal(0,5) << '\n';
    cout << fractionToDecimal(0,139139139) << '\n';

    cout << '\n';

    for (int i = 0; i < 7; ++i) {
        cout << fractionToDecimal(i, 7) << '\n';
    }

    cout << '\n';

    cout << fractionToDecimal(1,30) << '\n';
    cout << fractionToDecimal(-1,30) << '\n';
    cout << fractionToDecimal(-1,-30) << '\n';
    cout << fractionToDecimal(1,-30) << '\n';

    cout << '\n';

    cout << fractionToDecimal(123134,1) << '\n';
    cout << fractionToDecimal(123134,-1) << '\n';
    cout << fractionToDecimal(-123134,-1) << '\n';
    cout << fractionToDecimal(-123134,1) << '\n';

    cout << fractionToDecimal(2147483647,1) << '\n'; // 2147483647
    cout << fractionToDecimal(2147483647,-1) << '\n';
    cout << fractionToDecimal(-2147483647,-1) << '\n';
    cout << fractionToDecimal(-2147483647,1) << '\n';


    cout << fractionToDecimal(-2147483648,1) << '\n'; // -2147483648
    cout << fractionToDecimal(-2147483648,-1) << '\n'; // 2147483648

    cout << fractionToDecimal(-2147483648,2147483647) << '\n';
    cout << fractionToDecimal(-2147483647,2147483647) << '\n';
    cout << fractionToDecimal(2147483647,-2147483648) << '\n';
    cout << fractionToDecimal(2147483647,-729) << '\n';
    cout << fractionToDecimal(-729,729) << '\n';
    cout << fractionToDecimal(-1,729) << '\n';
    cout << fractionToDecimal(0,729) << '\n';
    cout << fractionToDecimal(1,729) << '\n';
    cout << fractionToDecimal(-2,729) << '\n';

    cout << '\n';

    cout << fractionToDecimal(1,10) << '\n';
    cout << fractionToDecimal(1,40) << '\n';
    cout << fractionToDecimal(1,10240) << '\n';
    cout << fractionToDecimal(1,625) << '\n';
    cout << fractionToDecimal(1,3125) << '\n';
    cout << fractionToDecimal(1,312500) << '\n';
    cout << fractionToDecimal(1,5) << '\n';

    cout << '\n';

    cout << fractionToDecimal(-1,10) << '\n';
    cout << fractionToDecimal(-1,40) << '\n';
    cout << fractionToDecimal(-1,10240) << '\n';
    cout << fractionToDecimal(-1,625) << '\n';
    cout << fractionToDecimal(-1,3125) << '\n';
    cout << fractionToDecimal(-1,312500) << '\n';
    cout << fractionToDecimal(-1,5) << '\n';

    cout << '\n';

    cout << fractionToDecimal(9,10) << '\n';
    cout << fractionToDecimal(11,40) << '\n';
    cout << fractionToDecimal(147,10240) << '\n';
    cout << fractionToDecimal(1024,625) << '\n';
    cout << fractionToDecimal(-160,3125) << '\n';
    cout << fractionToDecimal(1,312500) << '\n';
    cout << fractionToDecimal(1,5) << '\n';

    cout << fractionToDecimal(20,40) << '\n';
    cout << fractionToDecimal(800,40) << '\n';
    cout << fractionToDecimal(-40,40) << '\n';
    cout << fractionToDecimal(274274,13) << '\n';

    cout << '\n';

    cout << fractionToDecimal(1,15) << '\n';
    cout << fractionToDecimal(1,60) << '\n';
    cout << fractionToDecimal(13535251,15) << '\n';
    cout << fractionToDecimal(-13535251,150) << '\n';
    cout << fractionToDecimal(-2,4375) << '\n';

    return 0;
}