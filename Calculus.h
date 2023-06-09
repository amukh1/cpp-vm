#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

// FIX THIS ERROR WAITING TO HAPPEN! MOVE DEFINITIONS TO .cpp FILE

float h = 0.0001;

float derivative(float (*fn)(float), float x) {
    return (float) (fn(x + h) - fn(x)) / h;
}

float riemann(float (*fn)(float), float a, float b, int n) {
    
        float sum = 0;
        float h = (b - a) / n;
    
        for (int i = 0; i < n; i++) {
            sum += fn(a + i * h);
        }
    
        return sum * h;
}

float limit(float (*fn)(float), float a) {
        return fn(a - h) + ((fn(a + h) - fn(a - h))/2);
}