#include <iostream>

using namespace std;

void findLongestCommonSubstring(string x, string y) {
    int n = x.length();

    
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    
    int maxLength = 0;
    int endIndex = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }

            if (dp[i][j] > maxLength) {
                maxLength = dp[i][j];
                endIndex = i;
            }
        }
    }

    
    string lcs = "";
    while (maxLength > 0) {
        lcs += x[endIndex - 1];
        --endIndex;
        --maxLength;
    }

    reverse(lcs.begin(), lcs.end());

    cout << "Length of the longest substring: " << maxLength << endl;
    cout << "Longest common substring: " << lcs << endl;
}

int main() {
    string x = "PQRS";
    string y = "QRST";

    findLongestCommonSubstring(x, y);

    return 0;
}
