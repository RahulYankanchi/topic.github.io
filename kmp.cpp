#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the LPS array for the pattern
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0; // length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0; // The LPS array for the first character is always 0

    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1]; // Try the previous longest prefix suffix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP search
void KMPSearch(const string& text, const string& pattern) {
    int M = pattern.length();
    int N = text.length();

    // Create the LPS array for the pattern
    vector<int> lps(M);
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    // Example: Finding a vehicle license plate in a parking lot record
    string parkingLot = "ABC123, XYZ456, ABC123, DEF789, ABC123";
    string licensePlate = "ABC123";

    // Perform KMP search
    KMPSearch(parkingLot, licensePlate);

    return 0;
}
