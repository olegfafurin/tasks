#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Robot {
private:
	int w, h;
	int steps, modulo;
public:
    Robot(int width, int height) {
    	w = width;
    	h = height;
        steps = 0;
        modulo = 2 * (w + h - 2);
    }
    
    void step(int num) {
        steps += num;
    }
    
    vector<int> getPos() {
        if (steps == 0) {
        	return {0,0};
        }
        int rem = (steps - 1) % modulo + 1;
        if (rem <= w - 1) {
        	return {rem, 0};
        } else if (rem <= w + h - 2) {
        	return {w - 1, rem + 1 - w};
        } else if (rem <= 2 * w + h - 3) {
        	return {2 * w + h  - 3 - rem, h - 1};
        } else {
            return {0, modulo - rem};
        }
    }
    
    string getDir() {
        if (steps == 0) {
            return "East";
        }
        int rem = (steps - 1) % modulo + 1;
        if (rem <= w - 1) {
            return "East";
        } else if (rem <= w + h - 2) {
            return "North";
        } else if (rem <= 2 * w + h - 3) {
            return "West";
        } else {
            return "South";
        }
    }
};