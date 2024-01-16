#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>

const int NUM_ELEMENTS = 1000000; // 테스트에 사용할 요소의 수

// 임의의 데이터를 map에 삽입하는 함수
void populateMap(std::map<int, int>& m) {
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        m[i] = rand();
    }
}

// 임의의 데이터를 unordered_map에 삽입하는 함수
void populateUnorderedMap(std::unordered_map<int, int>& m) {
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        m[i] = rand();
    }
}

// using namespace

int main() {
    std::map<int, int> myMap;
    std::unordered_map<int, int> myUnorderedMap;

    // 데이터 삽입
    populateMap(myMap);
    populateUnorderedMap(myUnorderedMap);

    // 범위 검색 시작 및 끝 정의
    int rangeStart = 500000;
    int rangeEnd = 500100;

    // std::map에서 범위 검색 시간 측정
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = rangeStart; i < rangeEnd; ++i) {
        auto it = myMap.find(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime = end - start;
    std::cout << "💜 map range search time: " << elapsedTime.count() << " ms\n";

    // std::unordered_map에서 범위 검색 시간 측정
    start = std::chrono::high_resolution_clock::now();
    for (int i = rangeStart; i < rangeEnd; ++i) {
        auto it = myUnorderedMap.find(i);
    }
    end = std::chrono::high_resolution_clock::now();
    elapsedTime = end - start;
    std::cout << "💜 unordered_map range search time: " << elapsedTime.count() << " ms\n";

    return 0;
}
