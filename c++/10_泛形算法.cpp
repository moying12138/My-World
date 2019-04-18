#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;
void vec_init(vector<int> &vec, int size) {  
    //back_insert_iterator<vector<int, allocator<int> > > it = back_inserter(vec);    //vs 不能用auto...回去g++试试    
    auto it = back_inserter(vec);    //vs 不能用auto...回去g++试试      , g++ 好用
    while(size--) it = rand() % 10000;    
}

void vec_output(vector<int> &vec) {  
    ostream_iterator<int> out(cout, " ");  
    copy(vec.begin(), vec.end(), out);  
    cout << endl;
}

void vec_sum() {  
    istream_iterator<int> in(cin), eof;           //遇到第一个非int退出  
    cout << accumulate(in, eof, 0) << endl;      
}

void vec_rever(vector<int> &vec) {  
    reverse(vec.begin(), vec.end());  
}

int cmp(int x, int y) {  
    if(x % 10 > y % 10) return 1;  
    return 0;
}

int main() {  
    #define CNT 10  
    srand(time(0));  
    vector<int> vec;  
    vec_init(vec, CNT);  
    vec_output(vec);  
    vec_rever(vec);  
    vec_output(vec);  
    //vec_sum();    
    sort(vec.rbegin(), vec.rend(), cmp);  
    vec_output(vec);  
    sort(vec.begin(), vec.end(), bind(cmp, _1, _2));      //vc++  不支持  g++  c++11支持
    vec_output(vec);  
    return 0;
}
