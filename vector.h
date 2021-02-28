#ifndef MYCLASSVECTORCPP_VECTOR_H
#define MYCLASSVECTORCPP_VECTOR_H

template<class T> class Vector {
public:
    typedef T *iterator;

    Vector();
    Vector(unsigned int size);

    iterator begin();
    iterator end();

    unsigned int size();

    void push_back(const T & value);
    void pop();
    void resize(unsigned int size);
    void reverse(unsigned int cap);
    void clear();

    T & operator[](unsigned int index) {
        return arr[index];
    }

    ~Vector();

private:
    T * arr;
    unsigned int N;
    unsigned int mSize;
};

template<class T> Vector<T>::Vector() {
    N = 1000;
    mSize = 0;
    arr = new T[N];
}

template<class T> Vector<T>::Vector(unsigned int size) {
    N = size;
    mSize = 0;
    arr = new T[N];
}

template<class T> typename Vector<T>::iterator Vector<T>::begin() {
    return arr;
}

template<class T> typename Vector<T>::iterator Vector<T>::end() {
    return arr + size();
}

template<class T> unsigned int Vector<T>::size() {
    return mSize;
}

template<class T> void Vector<T>::push_back(const T &value) {
    if (mSize >= N) {
        reverse(N * 1.5);
    }

    arr[mSize++] = value;
}

template<class T> void Vector<T>::pop() {
    mSize--;

    if (mSize * 4 < N) {
        reverse(N / 2);
    }
}

template<class T> void Vector<T>::reverse(unsigned int cap) {
    if (arr == 0) {
        mSize = 0;
        N = 1000;
    }

    T * buff = new T[cap];
    unsigned int l_size = cap < mSize ? cap : mSize;

    for (int i = 0; i < l_size; i++) {
        buff[i] = arr[i];
    }

    N = cap;
    delete [] arr;
    arr = buff;
}

template<class T> Vector<T>::~Vector() {
    delete [] arr;
}

#endif //MYCLASSVECTORCPP_VECTOR_H
