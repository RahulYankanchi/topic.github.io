#include <iostream>
#include <algorithm>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[minIdx], arr[i]);
    }
}

int main() {
    int chargingStations[] = {50, 30, 20, 40, 60}; // Example distances (in kilometers)
    int n = sizeof(chargingStations) / sizeof(chargingStations[0]);

    cout << "Charging Stations before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << chargingStations[i] << " ";
    }

    selectionSort(chargingStations, n);

    cout << "\nCharging Stations after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << chargingStations[i] << " ";
    }

    return 0;
}
