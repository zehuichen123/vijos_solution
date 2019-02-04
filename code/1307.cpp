//Problem 1307: 黑皮的正方形 
//Status: Accepted 
//Used Time: 23ms 
//Peak Memory: 384.0 KiB
#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    cout << (n)*(n+1)*(2*n+1) / 6;
}