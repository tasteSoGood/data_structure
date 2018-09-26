const int DEFAULT_CAPACITY = 32;                  // 定义一个默认的数组长度
typedef int Rank;                                 // 此数据类型用于限定长度以及坐标

template<class T>
class vector {
private:
    Rank _size;
    int _capacity;
    T *_items;

protected:
    void _copy(const T *arr, Rank lo, Rank hi) {
        _size = 0;
        _items = new T[_capacity = 2 * (hi - lo)];
        while(lo < hi)
            _items[_size++] = arr[lo++];
    }

    void _copy(vector<T> arr, Rank lo, Rank hi) {
    }

public:
    // 构造函数
    vector(int c = DEFAULT_CAPACITY) {
        _items = new T[_capacity = c];
        _size = 0;
    }

    vector(const T *arr, Rank lo, Rank hi) {
        _copy(arr, lo, hi);
    }
    
    vector(vector<T> arr, Rank lo, Rank hi) {
        _copy(arr, lo, hi);
    }

    vector(vector<T> &arr) {
        _copy(arr);
    }

    // 析构函数
    ~vector() {
        delete _items;
    }

    // 外部接口
};