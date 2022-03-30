#include <iostream>
#include <cmath>

using namespace std;

int calculate(int k) {
    int n = k / 5;
    int sodu = fmod(k, 5);
    return (n + 1) * (75 * n + 30 * sodu);
}

int main() {
    int k;
    cin >> k;
    cout << calculate(k);
}
