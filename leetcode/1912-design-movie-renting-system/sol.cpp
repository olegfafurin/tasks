#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <array>

using namespace std;

class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // shop, movie, price
        for (auto &v: entries) {
            int shop = v[0], movie = v[1], price = v[2];
            available[movie].insert({price, shop});
            priceOffer[{shop, movie}] = price;
        }
        
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        result.reserve(5);
        for (auto &x: available[movie]) {
            result.emplace_back(x.second);
            if (result.size() >= 5)
                break;
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = priceOffer.at({shop, movie});
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceOffer.at({shop, movie});
        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        result.reserve(5);
        for (auto const& x: rented) {
            result.emplace_back(std::vector<int>{x[1],x[2]});
            if (result.size() >= 5)
                break;
        }
        return result;
    }
private:
    set<array<int, 3>> rented; // [price, shop_id, movie_id]
    map<int, set<pair<int, int>>> available; // movie_id -> [price, shop_id]
    map<array<int, 2>, int> priceOffer; // [shop_id, movie_id] -> price
};

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<vector<int>> entries {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
    MovieRentingSystem movie_system(n, entries);

    cout << movie_system.search(1) << '\n';

    movie_system.rent(0,1);
    movie_system.rent(1,2);
    movie_system.drop(1,2);
    
    cout << movie_system.search(1) << '\n';

    return 0;
}
