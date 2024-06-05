#include <cassert>
#include <iostream>
#include "task.h"


int main() {
    std::cout << "Тесты задания 1: \n";
    assert(findPersonWithBroom(82, 26)==27);
    std::cout << "OK\n";
    assert(findPersonWithBroom(6, 8)==3);
    std::cout << "OK\n";
    assert(findPersonWithBroom(18, 38)==5);
    std::cout << "OK\n";


    std::cout << "Тесты задания 2: \n";
    assert(canReachTarget(1, 2, 1, 2, 1)==false);
    std::cout << "OK\n";
    assert(canReachTarget(1, 1, 3, 3, 9) == true);
    std::cout << "OK\n";
    assert(canReachTarget(1, 1, 1, 5,8) == true);
    std::cout << "OK\n";


    std::cout << "Тесты заданяи 3: \n";
    assert(solveEquation("-x=1") == "x=-1");
    std::cout << "OK\n";
    assert(solveEquation("99x=99") == "x=1");
    std::cout << "OK\n";
    assert(solveEquation("-x+x+3x=2x-x+x") == "x=0");
    std::cout << "OK\n";


    std::cout << "Тесты заданяи 4: \n";
    assert(findMinTimeDiff({"00:00", "23:59"})==1);
    std::cout << "OK\n";
    assert(findMinTimeDiff({"00:00", "00:00"})==0);
    std::cout << "OK\n";
    assert(findMinTimeDiff({"00:00", "01:00", "23:30"})==30);
    std::cout << "OK\n";


    std::cout << "Тесты задания 5: \n";
    assert(canReach(536870912, 536870912)==true);
    std::cout << "OK\n";
    assert(canReach(6, 9) == false);
    std::cout << "OK\n";
    assert(canReach(4, 7)==true);
    std::cout << "OK\n";


    std::cout << "Тесты задания 6: \n";
    assert(calculateExpression("1+9")==10);
    std::cout << "OK\n";
    assert(calculateExpression("     90                             ")==90);
    std::cout << "OK\n";
    assert(calculateExpression("1")==1);
    std::cout << "OK\n";

    return 0;
}