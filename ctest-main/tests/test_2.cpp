#include <cassert>
#include "task.h"

void test_correct(){
    assert(countNumbersWithoutConsecutiveOnes(10)==8);
}

int main(){
    test_correct();
}