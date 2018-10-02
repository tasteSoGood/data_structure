/*
 * 由于模板在编译期间必须被实例化，所以hpp和cpp的类与方法相分离的处理方法
 * 在这里并不适用，而且暂时没有找到更好的解决办法，既然无法分离，那么不如
 * 把所有的方法都写进类里面，这样能把注意力更多地集中在算法上
 */

#ifndef NULL
#define NULL 0
#endif

template <typename T>
class vector {
private:
    int _size;
    int _capacity;
    T *_items;

public:
    // 常量的定义
    enum {
        // 在C++的类构造中，如果需要使用到常量，建议使用enum枚举类型
        // 在其他程序构造的时候，常量尽量使用const关键字，尽量避免使用#define
        DEFAULT_CAPACITY = 32 
    };

    // 构造函数
    explicit vector(int size = 0) {
        // explicit关键字指定该构造方法只能被明确地调用，不能作为类型转换操作符被隐含地使用
        _size = size;
        _items = new T[_capacity = DEFAULT_CAPACITY];
    }
    vector(const vector &new_vector) {
        _items = NULL;
        operator=(new_vector);
    }

    // 析构函数
    ~vector() {
        delete[] _items;
    }

    // 运算符重载
    const vector &operator=(const vector &new_vector) {
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
    T &operator[](int index) {
        return _items[index];
    }
    const T &operator[](int index) const {
        return _items[index];
    }

    // 迭代器
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() {
        return &_items[0];
    }
    const_iterator bagin() const {
        return &_items[0];
    }
    iterator end() {
        return &_items[_size - 1];
    }
    const_iterator end() const {
        return &_items[_size - 1];
    }

    // 接口函数
    void resize(int size) {
        if(size > _capacity)
            reserve(size * 2 + 1);
        _size = size;
    }
    void reserve(int capacity) {
        if(capacity < _size)
            return;
        T *old_vector = _items;
        _items = new T[_capacity = capacity];
        for(int i = 0; i < _size; i++)
            _items[i] = old_vector[i];
        delete[] old_vector;
    }
    bool empty() const {
        return _size == 0;
    }
    int size() const {
        return _size;
    }
    int capacity() const {
        return _capacity;
    }
    void push_back(const T &x) {
        if(_size == _capacity)
            reserve(_size * 2 + 1);
        _items[_size++] = x;
    }
    void pop_back() {
        _size--;
    }
    const T &back() const {
        return _items[_size - 1];
    }
};