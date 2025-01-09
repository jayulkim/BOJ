#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int* dp = (int*)malloc(sizeof(int) * N);
    int* sc = (int*)malloc(sizeof(int) * N);
    
    for(int i = 0; i < N; i++) cin >> sc[i];
    
    dp[0] = sc[0];
    dp[1] = sc[0] + sc[1];
    dp[2] = max(sc[0], sc[1]) + sc[2];
    
    for(int i = 3; i < N; i++) {
        dp[i] = max(sc[i-1] + dp[i-3] + sc[i], dp[i-2] + sc[i]);
    }
    
    cout << dp[N - 1];
}