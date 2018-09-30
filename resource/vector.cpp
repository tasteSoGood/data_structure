#include "vector.hpp"

// 构造函数
template <typename T>
vector<T>::vector(int size) {
    // explicit关键字指定该构造方法只能被明确地调用，不能作为类型转换操作符被隐含地使用
    _size = size;
    _items = new T[_capacity = DEFAULT_CAPACITY];
}
template <typename T>
vector<T>::vector(const vector &new_vector) {
    _items = NULL;
    operator=(new_vector);
}

// 析构函数
template <typename T>
vector<T>::~vector() {
    delete[] _items;
}

// 运算符重载
template <typename T>
const typename vector<T>::vector &vector<T>::operator=(const vector &new_vector) {
    if(this != &new_vector) {
        delete[] _items;
        _size = new_vector.size();
        _items = new T[_capacity = new_vector.capacity()];
        for(int i = 0; i < _size; i++)
            _items[i] = new_vector[i];
    }
    return *this; // this是一个常量指针，用来指代类自身
    // return this返回当前对象的地址
    // return *this返回当前对象的克隆或者自身
}
template <typename T>
T &vector<T>::operator[](int index) {
    return _items[index];
}
template <typename T>
const T &vector<T>::operator[](int index) const {
    return _items[index];
}

// 迭代器
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
    return &_items[0];
}
template <typename T>
typename vector<T>::const_iterator vector<T>::bagin() const {
    return &_items[0];
}
template <typename T>
typename vector<T>::iterator vector<T>::end() {
    return &_items[_size - 1];
}
template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
    return &_items[_size - 1];
}

// 接口函数
template <typename T>
void vector<T>::resize(int size) {
    if(size > _capacity)
        reserve(size * 2 + 1);
    _size = size;
}
template <typename T>
void vector<T>::reserve(int capacity) {
    if(capacity < _size)
        return;
    T *old_vector = _items;
    _items = new T[_capacity = capacity];
    for(int i = 0; i < _size; i++)
        _items[i] = old_vector[i];
    delete[] old_vector;
}
template <typename T>
bool vector<T>::empty() const {
    return _size == 0;
}
template <typename T>
int vector<T>::size() const {
    return _size;
}
template <typename T>
int vector<T>::capacity() const {
    return _capacity;
}
template <typename T>
void vector<T>::push_back(const T &x) {
    if(_size == _capacity)
        reserve(_size * 2 + 1);
    _items[_size++] = x;
}
template <typename T>
void vector<T>::pop_back() {
    _size--;
}
template <typename T>
const T &vector<T>::back() const {
    return _items[_size - 1];
}