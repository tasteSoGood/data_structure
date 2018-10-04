namespace hx {
#ifndef NULL
#define NULL 0
#endif

template <typename T>
class list {
private:
    class node {
    public:
        node *next;
        T value;
        node() : next(NULL) {}
        node(T v) : next(NULL), value(v) {}
    }; // 内部类
    int _size;
    node *_head;
    node *_tail;

public:
    // 构造函数
    list() : _size(0), _head(NULL), _tail(NULL) {}

    // 析构函数
    ~list() {
        clear();
    }

    
    // 迭代器
    typedef node* iterator;
    typedef const node* const_iterator;

    iterator begin() {
        return _head;
    }

    const_iterator begin() const {
        return _head;
    }

    iterator end() {
        return _tail;
    }

    const_iterator end() const {
        return _tail;
    }

    // 接口函数
    int size() {
        return _size;
    }

    bool empty() {
        return _size == 0;
    }

    void push_front(T value) {
        node *new_node = new node(value);
        if(!_head) {
            _head = new_node;
            _tail = new_node;
        }
        else {
            new_node->next = _head;
            _head = new_node;
        }
        _size++;
    }
    
    void push_back(T value) {
        node *new_node = new node(value);
        if(!_head) {
            _head = new_node;
            _tail = new_node;
        }
        else {
            _tail->next = new_node;
            _tail = _tail->next;
        }
        _size++;
    }

    void pop_back() {
        if(_size == 0 || _size == 1)
            clear();
        else {
            node *p = _head;
            while(p->next != _tail)
                p = p->next;
            delete p->next;
            _tail = p;
            _tail->next = NULL;
            _size--;
        }
    }

    void pop_front() {
        if(_size == 0 || _size == 1)
            clear();
        else{
            node *p = _head;
            _head = _head->next;
            delete p;
            _size--;
        }
    }

    void clear() {
        if(!_head)
            return;
        node *p = _head;
        while(p->next) {
            p = p->next;
            _head->next = p->next;
            delete p;
            p = _head;
        }
        delete p;
        _tail = NULL;
        _size = 0;
    }

    const T& back() const {
        return _tail.value;
    }

    const T& top() const {
        return _head.value;
    }

    // 测试函数
    void disp() {
        #include <iostream>
        node *p = _head;
        while(p) {
            std::cout << p->value << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};
} // hx namespace