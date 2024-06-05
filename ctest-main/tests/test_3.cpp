#include <cassert>
#include "task.h"

void test_correct(){
    assert(countNumbersWithoutConsecutiveOnes(1024)==145);
}

int main(){
    test_correct();
}