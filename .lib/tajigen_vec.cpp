#include <iostream>
#include <vector>
using namespace std;

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//

int main(){
    auto dp = make_vec<int>(10, 10, 10, 10);
    dp[0][0][0][0] = 1;

    return 0;
}