#include <iostream>
using namespace std;

int getMax(int h[], int cap) {
    int maxVal = h[0];
    for (int i = 1; i < cap; i++) {
        if (h[i] > maxVal) {
            maxVal = h[i];
        }
    }
    return maxVal;
}

void printChart (int h[], char c[], int cap, int max) {
    for (int row = max; row >= 1; row--) {
        for (int col = 0; col < cap; col++) {
            if (h[col] >= row) {
                cout << c[col] << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int minIndex (int h[], int begInd, int endInd) {
    int min = begInd;
    for (int i = begInd + 1; i <= endInd; i++) {
        if (h[i] < h[min]) {
            min = i;
        }
    }
    return min;
}

void swap (int h[], char c[], int i, int j) {
    int th = h[i];
    h[i] = h[j];
    h[j] = th;
    
    char tc = c[i];
    c[i] = c[j];
    c[j] = tc;
}

void sort (int h[], char c[], int cap) {
    for (int i = 0; i < cap - 1; i++) {
        int index = minIndex(h, i, cap - 1); //Call minIndex
        swap(h, c, i, index);
    }
}

int main() {
    int height[6] = {0,0,0,0,0,0};
    char chars[6];
    cout << "Please enter six non-negative integers.\n";
    for (int i = 0; i < 6; i++) {
        cout << "Integer #" << i << ": ";
        cin >> height[i];
        cout << endl; //Need this line in order to print correctly for auto-grading
        while (height[i] < 0) {
            cout << "Try again. Value must be 0 or greater. ";
            cin >> height[i];
        }
    }

    cout << "Please enter six characters.\n";
    for (int i = 0; i < 6; i++) {
        cout << "Character #" << i << ": ";
        cin >> chars[i];
        cout << endl; //Need this line in order to print correctly for auto-grading        
    }

    int maxHeight = getMax(height, 6);
    cout << "Unsorted bar chart\n";
    printChart(height, chars, 6, maxHeight);
    sort(height, chars, 6);
    cout << "\nSorted bar chart\n";
    printChart(height, chars, 6, maxHeight);

    return 0;
}

