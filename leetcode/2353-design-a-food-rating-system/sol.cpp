#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;


class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodType[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i];
            storage[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string type = foodType[food];
        int oldRating = rating[food];
        rating[food] = newRating;
        storage[type].erase({-oldRating, food});
        storage[type].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        pair<int, string> element = *storage[cuisine].begin();
        return element.second;
    }

private:
    unordered_map<string, string> foodType;
    unordered_map<string, int> rating;
    unordered_map<string, set<pair<int,string>>> storage;
};

// int main(int argc, char const *argv[])
// {
//     vector<string> foods {"tapas", "empanadas"};
//     vector<string> cuisines {"spanish", "spanish"};
//     vector<int> ratings {4, 4};

//     FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);

//     cout << obj->highestRated("spanish") << '\n';

//     obj->changeRating("empanadas", 2);

//     cout << obj->highestRated("spanish") << '\n';

//     obj->changeRating("tapas", 2);

//     cout << obj->highestRated("spanish") << '\n';
//     return 0;
// }


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */