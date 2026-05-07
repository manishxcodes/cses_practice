#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> seq;

    while (true) {
        seq.push_back(n);
        if (n == 1) break;

        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }

    for (size_t i = 0; i < seq.size(); i++) {
        cout << seq[i] << (i + 1 == seq.size() ? '\n' : ' ');
    }

    return 0;
}