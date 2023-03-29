#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

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