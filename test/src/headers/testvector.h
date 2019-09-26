#ifndef TESTVECTOR_H
#define TESTVECTOR_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <string>
#include "../../../src/vector.h"

class TestVector : public CxxTest::TestSuite {
private:
    Vector<int> vINT = {1, 2, 3, 4, 5};
    Vector<double> vDOUBLE = {1.1, 2.2, 3.3, 4.4};
    Vector<char> vCHAR = {'a', 'b', 'c', 'd'};
    Vector<bool> vBOOL = {0, 1, 0, 1};
    Vector<std::string> vSTRING = {"programming", "so", "cool"};

public:
    void testSize();
    void testCapacity();
    void testEmpty();
    void testAt();
    void testFront();
    void testBack();
    void testOperator();
    void testPushBack();
    void testErase();
    void testInsert();
    void testClear();
};

#endif //TESTVECTOR_H