#include <string>
#include <bitset>
#include "task.h"


int countNumbersWithoutConsecutiveOnes(int n) {
    int count = 0;
    for (int i = 0; i <= n; ++i) {
        bool hasConsecutiveOnes = false;
        for (int j = 0; j < 31; ++j) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                hasConsecutiveOnes = true;
                break;
            }
        }
        if (!hasConsecutiveOnes) {
            count++;
        }
    }
    return count;
}