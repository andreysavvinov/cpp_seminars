#include <iostream>
#include <array>
#include <string>

// template <typename T1, typename T2, typename T3, typename T4, typename T5>
// size_t X(T1 a, T2 b, T3 c, T4 d, T5 e) {
//     return std::max({sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e)});
//     //return max sizeof of params.
// }

// template <typename T1, typename T2, typename T3, typename T4>
// size_t X(T1 a, T2 b, T3 c, T4 d) {
//     return std::max({sizeof(a), sizeof(b), sizeof(c), sizeof(d)});
//     //return max sizeof of params.
// }

// template <typename T1, typename T2, typename T3>
// size_t X(T1 a, T2 b, T3 c) {
//     return std::max({sizeof(a), sizeof(b), sizeof(c)});
//     //return max sizeof of params.
// }

// template <typename T1, typename T2>
// size_t X(T1 a, T2 b) {
//     return std::max({sizeof(a), sizeof(b)});
//     //return max sizeof of params.
// }

// template <typename T1>
// size_t X(T1 a) {
//     return sizeof(a);
//     //return max sizeof of params.
// }

template <typename T1>
size_t X(T1 a){
    return sizeof(a);
}

template <typename T1, typename T2>
size_t X(T1 a, T2 b){
    return std::max(sizeof(a), sizeof(b));
}

template <typename T1, typename T2, typename T3>
size_t X(T1 a, T2 b, T3 c){
    return std::max(sizeof(a), X(b, c));
}

template <typename T1, typename T2, typename T3, typename T4>
size_t X(T1 a, T2 b, T3 c, T4 d){
    return std::max(sizeof(a), X(b, c, d));
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
size_t X(T1 a, T2 b, T3 c, T4 d, T5 e){
    return std::max(sizeof(a), X(b, c, d, e));
}

// template<typename... Args>
// size_t X(Args... args) {
//     constexpr size_t count = sizeof...(args);
    
//     // Определение максимального размера
//     size_t max_size = std::max({sizeof(args)...});  // Ищем максимальный размер среди параметров
//     return max_size;
// }

int main() {
    int a = 10;
    float b = 10;
    std::string c = "ads";
    std::array<int, 100> d = {};
    const int* e = nullptr;
    
    std::cout << X(a) << std::endl;
    std::cout << X(a, b) << std::endl;
    std::cout << X(a, b, c) << std::endl;
    std::cout << X(a, b, c, d) << std::endl;
    std::cout << X(a, b, c, d, e) << std::endl;
}