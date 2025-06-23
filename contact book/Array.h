#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
using namespace std;

template <typename T>
class Array
{
private:

    T* a;
    size_t length;
    size_t capacity;

    // resize the capacity of array
    void resize(size_t newCapacity)
    {
        T* NEW = new T[newCapacity];
        for (size_t i = 0; i < length; i++)
        {
            NEW[i] = a[i];
        }
        delete[] a;
        a = NEW;
        capacity = newCapacity;
    }


public:


    Array() : length(0), capacity(2)
    {
        a = new T[capacity] ;
    }


    // Copy Constructor
    Array(const Array& obj) : length(obj.length), capacity(obj.capacity)
    {
        a = new T[capacity] ;
        for (size_t i = 0; i < length; i++)
        {
            a[i] = obj.a[i];
        }
    }


    // Operator Overloading
    Array& operator=(const Array& obj)
    {
        if (this == &obj) return *this;
        delete[] a;
        length = obj.length;
        capacity = obj.capacity;
        a = new T[capacity];
        for (size_t i = 0; i < length; i++)
        {
            a[i] = obj.a[i];
        }
        return *this;
    }


    ~Array()
    {
        delete[] a;
    }


    // Add element at end
    void append(const T& element)
    {
        if (length >= capacity)
        {
            size_t newCapacity = capacity * 2;
            resize(newCapacity);
        }
        a[length++] = element;
    }


    // Insert element at a certain location
    void insert(size_t index, const T& element)
    {
        if (index > length)
        {
            throw out_of_range("\t\t\t\t\t\t\ The Entered Index isn't existed for insert ");
        }
        if (length >= capacity)
        {
            resize(capacity * 2);
        }
        for (size_t i = length; i > index; i--)
        {
            a[i]=a[i-1];
        }
        a[index] = element;
        length++;
    }

    //reverse contacts
    void reverse()
    {
        size_t first=0;
        size_t last=length-1;
        while(first<last)
        {
            T temp=a[first];
            a[first]=a[last];
            a[last]=temp;
            first ++;
            last --;
        }
    }

    //share
    void share(size_t index)
    {
        if (index < length)
        {
            cout << "\t\t\t\t\t\t\ Sharing contact: " << a[index] << endl;
        }
        else
        {
            cout << "\t\t\t\t\t\t\ It isn't avaliable." << endl;
        }
    }


    // Remove element at index


    void removeAt(size_t index)
    {
        if (index >= length)
        {
            throw out_of_range("\t\t\t\t\t\t\ Index out of range for remove ");
        }
        for (size_t i = index; i < length - 1; i++)
        {
            a[i] = a[i + 1];
        }
        length--;
    }

    // Find element at specific location

    T& getAt(size_t index)
    {
        if (index < length)
        {
            return a[index];
        }
        throw out_of_range("\t\t\t\t\t\t\ Index out of range");
    }

    const T& getAt(size_t index) const
    {
        if (index < length)
        {
            return a[index];
        }
        throw out_of_range("\t\t\t\t\t\t\ Index out of range");
    }

    // Access element at index


    T& operator[](size_t index)
    {
        return getAt(index);
    }

    const T& operator[](size_t index) const
    {
        return getAt(index);
    }

    // Clear array elements

    void reset()
    {
        delete[] a;
        a = nullptr;
        length = 0;
        capacity = 0;
    }

    // Get size of array


    size_t getSize() const
    {
        return length;
    }

    // Display array elements

    void display() const
    {
        for (size_t i = 0; i < length; i++)
        {
            std::cout << std::setw(5) << a[i] << " ";
        }
        std::cout << std::endl;
    }


    // Resize array to a new capacity



};

#endif // ARRAY_H_INCLUDED
