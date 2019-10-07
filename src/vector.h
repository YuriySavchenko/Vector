#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>
#include <initializer_list>
#include <iterator>
#include <functional>
#include <stdexcept>
#include <cmath>

template <typename T>
class Vector {
private:
    std::unique_ptr<T []> ARRAY;
    std::size_t LENGTH;
    std::size_t CAPACITY;

public:
    Vector();
    Vector(const std::size_t &, const T &);
    Vector(std::initializer_list<T>);
    ~Vector();

public:
    constexpr std::size_t size() const noexcept;
    constexpr std::size_t capacity() const noexcept;
    constexpr bool empty() const noexcept;
    constexpr void clear();

private:
    constexpr void reserve();

public:
    constexpr T & at(const std::size_t &);
    constexpr const T & at(const std::size_t &) const;
    constexpr T & front();
    constexpr const T & front() const;
    constexpr T & back();
    constexpr const T & back() const;
    constexpr T & operator[](const std::size_t &);
    constexpr const T & operator[](const std::size_t &) const;

public:
    constexpr void push_back(const T &);
    constexpr void push_back(T &&);
    constexpr void insert(const std::size_t &, const T &);
    constexpr void insert(const std::size_t &, T &&);
    constexpr void erase(const std::size_t &);
    constexpr void erase(std::size_t &&);

};

/* implementation of the basic constructor */
template <typename T>
Vector<T>::Vector() {
    this->LENGTH = 0;
    this->CAPACITY = 0;
}

/* constructor for creating vector by count of elements and particular value */
template <typename T>
Vector<T>::Vector(const std::size_t &count, const T & value) {
    this->LENGTH = count;
    this->reserve();

    for (int i=0; i < LENGTH; i++)
        (*ARRAY)[i] = value;

}

/* constructor for creating vector by initializer list */
template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) {
    this->LENGTH = init.size();
    this->reserve();

    std::size_t index = 0;

    for (auto & value : init) {
        ARRAY[index] = value;
        index++;
    }
}

/* implementation of the basic destructor */
template <typename T>
Vector<T>::~Vector() {
    this->clear();
}

/* function for returning size of the vector */
template <typename T>
constexpr std::size_t Vector<T>::size() const noexcept {
    return LENGTH;
}

/* function for returning capacity of the Vector */
template <typename T>
constexpr std::size_t Vector<T>::capacity() const noexcept {
    return CAPACITY;
}

/* function for checking if vector are empty */
template <typename T>
constexpr bool Vector<T>::empty() const noexcept {
    return (this->ARRAY == nullptr) ? true : false;
}

/* method for clearing of the Vector */
template <typename T>
constexpr void Vector<T>::clear() {
    this->ARRAY.~unique_ptr();
    this->LENGTH = 0;
}

/* method which allows to find a capacity and create new array */
template <typename T>
constexpr void Vector<T>::reserve() {
    const std::size_t size = LENGTH;

    std::function<int()> pow2 = [size]() {
        for (int i=0; i < size; i++)
            if (pow(2, i) >= size)
                return pow(2, i);
    };

    std::unique_ptr<T []> array(new T[pow2()]);

    if (LENGTH != 0 && !this->empty()) {
        for (int i=0; i < LENGTH-1; i++)
            array[i] = ARRAY[i];

        this->clear();
    }

    this->ARRAY = std::move(array);
    this->LENGTH = size;
    this->CAPACITY = pow2();
}

/* function for returning specified elelement from vector, also allows change element by index */
template <typename T>
constexpr T & Vector<T>::at(const std::size_t & index) {
    if (index < LENGTH)
        return ARRAY[index];
    else
        throw std::out_of_range("\e[31m[!] Index out of the range.\e[0m");
}

/* functiom for returning specified element from vector */
template <typename T>
constexpr const T & Vector<T>::at(const std::size_t & index) const {
    return this->at(index);
}

/* method for returning a first element from vector, also allows to change it */
template <typename T>
constexpr T & Vector<T>::front() {
    return this->at(0);
}

/* method for returning a first element from vector */
template <typename T>
constexpr const T & Vector<T>::front() const {
    return this->at(0);
}

/* method for returning the last element from vector, also allows to change it */
template <typename T>
constexpr T & Vector<T>::back() {
    return this->at(this->LENGTH-1);
}

/* method for returning the last element from vector */
template <typename T>
constexpr const T & Vector<T>::back() const {
    return this->at(this->LENGTH-1);
}

/* functiom for returning specified element from vector, also allows to change it */
template <typename T>
constexpr T & Vector<T>::operator[](const std::size_t & index) {
    return this->at(index);
}

/* functiom for returning specified element from vector */
template <typename T>
constexpr const T & Vector<T>::operator[](const std::size_t & index) const {
    return this->at(index);
}

/* method for inserting value into the end of the vector */
template <typename T>
constexpr void Vector<T>::push_back(const T & value) {
    this->LENGTH++;

    if (LENGTH > CAPACITY)
        this->reserve();

    ARRAY[LENGTH-1] = value;
}

/* method for inserting value into the end of the vector */
template <typename T>
constexpr void Vector<T>::push_back(T && value) {
    this->LENGTH++; 

    if (LENGTH > CAPACITY)
        this->reserve();

    ARRAY[LENGTH-1] = value;
}

/* method for inserting element into vector by index */
template <typename T>
constexpr void Vector<T>::insert(const std::size_t &index, const T & value) {
    if (index > LENGTH)
        throw std::out_of_range("\e[31m[!] Index out of the range.\e[0m");
    
    else {
        this->LENGTH++;

        if (LENGTH > CAPACITY)
            this->reserve();

        if (index != LENGTH-1) {
            for (int i=LENGTH-1; i > index; i--)
                ARRAY[i] = ARRAY[i-1];
            
            ARRAY[index] = value;
        }

        else {
            ARRAY[index] = value;
        }
    }
}

/* method for inserting element into vector by index */
template <typename T>
constexpr void Vector<T>::insert(const std::size_t &index, T && value) {
    this->insert(index, value);
}

/* method for removing element from the vector by index */
template <typename T>
constexpr void Vector<T>::erase(const std::size_t & index) {
    if (index >= LENGTH)
        throw std::out_of_range("\e[31m[!] Index out of the range.\e[0m");

    else {
        if (index == LENGTH-1)
            this->LENGTH--;

        else {
            for (int i=index; i < LENGTH-1; i++) {
                ARRAY[i] = ARRAY[i+1];
            }

            this->LENGTH--;
        }
    }
}

/* method for removing element from the vector by index */
template <typename T>
constexpr void Vector<T>::erase(std::size_t && index) {
    this->erase(index);
}

#endif //VECTOR_H