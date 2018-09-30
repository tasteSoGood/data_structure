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
    explicit vector(int = 0);
    vector(const vector &);

    // 析构函数
    ~vector();

    // 运算符重载
    const vector &operator=(const vector &);
    T &operator[](int);
    const T &operator[](int) const;

    // 迭代器
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin();
    const_iterator bagin() const;
    iterator end();
    const_iterator end() const;

    // 接口函数
    void resize(int);
    void reserve(int);
    bool empty() const;
    int size() const;
    int capacity() const;
    void push_back(const T &);
    void pop_back();
    const T &back() const;
};