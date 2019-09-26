#include "../headers/testvector.h"

/* method for testing function Vector<T>::size() */
void TestVector::testSize() {
    TS_ASSERT_EQUALS(vINT.size(), 6);
    TS_ASSERT_EQUALS(vDOUBLE.size(), 4);
    TS_ASSERT_EQUALS(vCHAR.size(), 4);
    TS_ASSERT_EQUALS(vBOOL.size(), 4);
    TS_ASSERT_EQUALS(vSTRING.size(), 3);
}

/* method for testing function Vector<T>::capacity() */
void TestVector::testCapacity() {
    TS_ASSERT_EQUALS(vINT.capacity(), 8);
    TS_ASSERT_EQUALS(vDOUBLE.capacity(), 1);
    TS_ASSERT_EQUALS(vCHAR.capacity(), 7);
    TS_ASSERT_EQUALS(vBOOL.capacity(), 16);
    TS_ASSERT_EQUALS(vSTRING.capacity(), 10);
}

/* method for testing function Vector<T>::empty() */
void TestVector::testEmpty() {
    TS_ASSERT_EQUALS(vINT.empty(), false);
    TS_ASSERT_EQUALS(vDOUBLE.empty(), false);
    TS_ASSERT_EQUALS(vCHAR.empty(), false);
    TS_ASSERT_EQUALS(vBOOL.empty(), false);
    TS_ASSERT_EQUALS(vSTRING.empty(), false);
}

/* method for testing function Vector<T>::at() */
void TestVector::testAt() {
    TS_ASSERT_EQUALS(vINT.at(4), 5);
    TS_ASSERT_EQUALS(vDOUBLE.at(3), 4.4);
    TS_ASSERT_EQUALS(vCHAR.at(2), 'c');
    TS_ASSERT_EQUALS(vBOOL.at(1), true);
    TS_ASSERT_EQUALS(vSTRING.at(0), "programming");
}

/* method for testing function Vector<T>::front() */
void TestVector::testFront() {
    TS_ASSERT_EQUALS(vINT.front(), 1);
    TS_ASSERT_EQUALS(vDOUBLE.front(), 1.1);
    TS_ASSERT_EQUALS(vCHAR.front(), 'a');
    TS_ASSERT_EQUALS(vBOOL.front(), false);
    TS_ASSERT_EQUALS(vSTRING.front(), "programming");
}

/* method for testing function Vector<T>::back() */
void TestVector::testBack() {
    TS_ASSERT_EQUALS(vINT.back(), 4);
    TS_ASSERT_EQUALS(vDOUBLE.back(), 4.3);
    TS_ASSERT_EQUALS(vCHAR.back(), 'c');
    TS_ASSERT_EQUALS(vBOOL.back(), false);
    TS_ASSERT_EQUALS(vSTRING.back(), "cold");
}

/* method for testing function Vector<T>::operator[] */
void TestVector::testOperator() {
    TS_ASSERT_EQUALS(vINT[4], 6);
    TS_ASSERT_EQUALS(vDOUBLE[3], 3.3);
    TS_ASSERT_EQUALS(vCHAR[2], '0');
    TS_ASSERT_EQUALS(vBOOL[1], false);
    TS_ASSERT_EQUALS(vSTRING[0], "programmers");
}

/* method for testing function Vector<T>::push_back() */
void TestVector::testPushBack() {
    vINT.push_back(6);
    vDOUBLE.push_back(5.5);
    vCHAR.push_back('e');
    vBOOL.push_back(false);
    vSTRING.push_back("!");

    TS_ASSERT_EQUALS(vINT[5], 6);
    TS_ASSERT_EQUALS(vDOUBLE[4], 5.5);
    TS_ASSERT_EQUALS(vCHAR[4], 'e');
    TS_ASSERT_EQUALS(vBOOL[4], false);
    TS_ASSERT_EQUALS(vSTRING[3], "!");
}

/* method for testing function Vector<T>::erase() */
void TestVector::testErase() {
    vINT.erase(5);
    vDOUBLE.erase(3);
    vCHAR.erase(1);
    vBOOL.erase(0);
    vSTRING.erase(3);

    TS_ASSERT_EQUALS(vINT[4], 5);
    TS_ASSERT_EQUALS(vDOUBLE[3], 5.5);
    TS_ASSERT_EQUALS(vCHAR[1], 'c');
    TS_ASSERT_EQUALS(vBOOL[0], true);
    TS_ASSERT_EQUALS(vSTRING[2], "cool");
}

/* method for testing function Vector<T>::insert() */
void TestVector::testInsert() {
    vINT.insert(5, 6);
    vDOUBLE.insert(3, 4.4);
    vCHAR.insert(1, 'b');
    vBOOL.insert(0, false);
    vSTRING.insert(3, "?");

    TS_ASSERT_EQUALS(vINT[5], 6);
    TS_ASSERT_EQUALS(vDOUBLE[3], 4.4);
    TS_ASSERT_EQUALS(vCHAR[1], 'b');
    TS_ASSERT_EQUALS(vBOOL[0], false);
    TS_ASSERT_EQUALS(vSTRING[3], "?");
}

/* method for testing function Vector<T>::clear() */
void TestVector::testClear() {
    vINT.clear();
    vDOUBLE.clear();
    vCHAR.clear();
    vBOOL.clear();
    vSTRING.clear();

    TS_ASSERT_EQUALS(vINT.empty(), true);
    TS_ASSERT_EQUALS(vDOUBLE.empty(), false);
    TS_ASSERT_EQUALS(vCHAR.empty(), true);
    TS_ASSERT_EQUALS(vBOOL.empty(), false);
    TS_ASSERT_EQUALS(vSTRING.empty(), false);
}
