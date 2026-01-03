//
// Created by 86150 on 2026/1/3.
//

#include <cstring>
#include <stdexcept>
#include <cstring>
#include <ctime>
#include <iostream>





//整形数组，把偶数调整到左边，奇数调整到右边
void AdjustArray(int* array, int size) {
    //采用双指针的思路来实现，首先定义双指针
    int* p = array;
    int* q = array+size-1;
    // 交换的逻辑
    // 1.先移动一个，只有左边奇数，右边偶数的时候，才可以交换。
    //左边偶，右边奇数，不动·左边奇数，右边奇数，移动右边
    //左边偶数，右边偶数，移动左边。左边奇数，右边偶数，交换。
    // */
    while (p<q) {
        if (*p%2==0) {
            if (*q%2==0) {
                p++;
            }
            else {
                p++;
                q--;
            }
        }
        else {
            if (*q%2==0) {
                int temp = *p;
                *p = *q;
                *q = temp;
                p++;
                q--;
            }
            else {
                q--;
            }
        }

    }
}

// }
int main() {
    int arr[10] = {0};
    //生成一个随机种子
    srand(time(nullptr));
    for (int & i : arr) {
        i = rand()%100;
    }
    for (int i : arr) {
        std::cout << i << " ";

    }
    std::cout<<std::endl;
    AdjustArray(arr, 10);
    for (int i : arr) {
        std::cout << i << " ";

    }
}



#if 0
// 逆序字符串
void reverse(char arr[], int size) {
    char* p = arr;
    char* q = arr + size -1;
    while (p < q) {
        char t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
}


int main() {
    char arr[] = "hello world";
    reverse(arr, strlen(arr));
    std::cout << arr <<std::endl;
}
#endif










#if 0
class Vector {
public:
    Vector(int size = 10):cur(0),capacity(size) {
        array = new int[capacity];
    }
    ~Vector() {
        delete[] array;
        array = nullptr;
    }
    // 向数组末尾添加元素
    void push_back(int item) {
        if (cur == capacity) {
            resize(capacity *= 2);
        }
        array[cur] = item;
        cur++;
    }
    //从末尾删除元素
    void pop_back() {
        if (cur == 0) {
            throw std::out_of_range("pop_back must be greater than 0");
        }
        cur--;
    }
    //向指定位置插入元素
    void insert(int item, int pos) {
        if (cur == capacity) {
            resize(capacity *= 2);
        }
        if (pos < 0|| pos > cur) {
            throw std::out_of_range("pos invalid");
        }
        for (int i = cur; i > pos; i--) {
            array[i] = array[i - 1];
        }
        array[pos] = item;
        cur++;
    }
    //修改某个列表中某个元素为另外一个值
    void edit(int src, int dst) {
        if (src==dst || find(src)==-1) {
            return;
        }
        array[find(src)] = dst;
    }
    //查找指定元素所在的id
    int find(int item) {
        for (int i = 0; i < cur; i++) {
            if (array[i] == item) {
                return i;
            }
        }
        return -1;
    }

private:

    int* array;//指向数组的指针
    int cur;//当前数组中有效元素的个数
    int capacity;//当前数组的容量
    #define RESIZE capacity *= 2;

    void resize(int size) {
        capacity = size;
        int* p = new int[capacity];
        memcpy(p, array, sizeof(int) * cur);
        delete[] array;//释放旧数据，否则会造成内存泄露
        array = p;
    }
};

int main() {
    try {
        std::cout << "===== Test 1: constructor & push_back =====\n";
        Vector v(2);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3); // 触发扩容

        for (int i = 0; i < 3; ++i) {
            std::cout << v.find(i + 1) << " ";
        }
        std::cout << "\n";

        std::cout << "===== Test 2: insert at head =====\n";
        v.insert(100, 0);
        std::cout << "find(100): " << v.find(100) << "\n";

        std::cout << "===== Test 3: insert at middle =====\n";
        v.insert(200, 2);
        std::cout << "find(200): " << v.find(200) << "\n";

        std::cout << "===== Test 4: insert at tail =====\n";
        v.insert(300, v.find(3) + 1);
        std::cout << "find(300): " << v.find(300) << "\n";

        std::cout << "===== Test 5: edit =====\n";
        v.edit(200, 999);
        std::cout << "find(999): " << v.find(999) << "\n";
        std::cout << "find(200): " << v.find(200) << "\n";

        std::cout << "===== Test 6: pop_back =====\n";
        v.pop_back();
        std::cout << "after pop, find(300): " << v.find(300) << "\n";

        std::cout << "===== Test 7: pop_back until empty =====\n";
        while (true) {
            v.pop_back();
            std::cout << "pop_back ok\n";
        }
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "===== Program end =====\n";
    return 0;
}
#endif

