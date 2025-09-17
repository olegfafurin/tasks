Design a food rating system that supports updates and queries for the highest-rated foods by cuisine.  

You are given:  

- An array **foods**, where `foods[i]` is the name of the *i*'th food item.  
- An array **cuisines**, where `cuisines[i]` is the type of cuisine of the *i*'th food.  
- An array **ratings**, where `ratings[i]` is the initial rating of the *i*'th food.  

Implement the **FoodRatings** class with the following methods:  

- `FoodRatings(String[] foods, String[] cuisines, int[] ratings)`  
  Initializes the system.  
- `void changeRating(String food, int newRating)`  
  Updates the rating of the given food.  ["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]`
- `String highestRated(String cuisine)`  
  Returns the food name with the highest rating for the given cuisine.  
  If multiple foods have the same rating, return the lexicographically smaller name.  

A string `x` is lexicographically smaller than `y` if `x` comes before `y` in dictionary order (either `x` is a prefix of `y`, or at the first differing character, `x[i] < y[i]`).  

---

### Example 1:

**Input:**  

`[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]`

**Output:** 

`[null, "kimchi", "ramen", null, "sushi", null, "ramen"]`

**Explanation:**  

    FoodRatings foodRatings = new FoodRatings(
    ["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"],
    ["korean", "japanese", "japanese", "greek", "japanese", "korean"],
    [9, 12, 8, 15, 14, 7]);
    foodRatings.highestRated("korean"); // return "kimchi"
    // "kimchi" has rating 9.
    foodRatings.highestRated("japanese"); // return "ramen"
    // "ramen" has rating 14.
    foodRatings.changeRating("sushi", 16);
    foodRatings.highestRated("japanese"); // return "sushi"
    // "sushi" now has rating 16.
    foodRatings.changeRating("ramen", 16);
    foodRatings.highestRated("japanese"); // return "ramen"
    // Both "sushi" and "ramen" have rating 16,
    // but "ramen" is lexicographically smaller.

---

### Constraints:

- `1 <= n <= 2 * 10^4`  
- `n == foods.length == cuisines.length == ratings.length`  
- `1 <= foods[i].length, cuisines[i].length <= 10`  
- `foods[i], cuisines[i]` consist of lowercase English letters.  
- `1 <= ratings[i] <= 10^8`  
- All strings in `foods` are distinct.  
- `food` in `changeRating` will exist in the system.  
- `cuisine` in `highestRated` will exist in the system.  
- At most `2 * 10^4` calls will be made to `changeRating` and `highestRated`.