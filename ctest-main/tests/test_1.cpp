#include <cassert>
#include "task.h"

void test_correct(){
    assert(countNumbersWithoutConsecutiveOnes(5)==5);
}

int main(){
    test_correct();
}