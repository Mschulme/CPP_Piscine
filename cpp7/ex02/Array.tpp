#ifndef ARRAY_TPP
#define ARRAY_TPP

template <class T>
Array<T>::Array() : size_array(0), data(0) {}

template <class T>
Array<T>::Array(unsigned int size) : size_array(size), data(0)
{
    data = new T[size_array]();
}

template <class T>
Array<T>::Array(const Array<T> &other) : size_array(other.size_array), data(0)
{
    data = new T[size_array];
    for (unsigned int i = 0; i < size_array; ++i)
        data[i] = other.data[i];
}

template <class T>
Array<T>::~Array()
{
    delete[] data;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
    if (this != &other) {
        T* newData = new T[other.size_array];
        for (unsigned int i = 0; i < other.size_array; ++i)
            newData[i] = other.data[i];

        delete[] data;
        data = newData;
        size_array = other.size_array;
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= size_array)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= size_array)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <class T>
unsigned int Array<T>::size() const
{
    return size_array;
}

#endif // ARRAY_TPP
