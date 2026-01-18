#include <iostream>

class Array
{
private:
    int *A;
    int size;
    int length;

public:

    Array(int sz = 10)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display() const
    {
        std::cout << "\nElements are: ";
        for (int i = 0; i < length; i++)
            std::cout << A[i] << " ";
        std::cout << std::endl;
    }

    void setElement(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            A[index] = value;
            if (index >= length)
                length = index + 1;
        }
    }

    void setLength(int len) { length = len; }
    int getLength() const { return length; }
    int getElement(int i) const { return A[i]; }

    static Array *Union(const Array &arr1, const Array &arr2);
    static Array *Intersection(const Array &arr1, const Array &arr2);
};

Array *Array::Union(const Array &arr1, const Array &arr2)
{
    Array *arr3 = new Array(arr1.size + arr2.size);
    int i = 0, j = 0, k = 0;

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }
    for (; i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    return arr3;
}

int main()
{
    Array arr1(10);
    int data1[] = {2, 9, 21, 28, 35};
    for (int i = 0; i < 5; i++)
        arr1.setElement(i, data1[i]);

    Array arr2(10);
    int data2[] = {2, 3, 9, 18, 28};
    for (int i = 0; i < 5; i++)
        arr2.setElement(i, data2[i]);

    Array *arr3 = Array::Union(arr1, arr2);

    arr3->Display();

    delete arr3;
    return 0;
}