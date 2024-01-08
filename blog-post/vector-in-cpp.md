# Vector In C++
c++로 알고리즘을 풀기 위한 필수 자료형이라 정리해둔다.

### `std::vector`
```cpp
template <class T, class Allocator = allocator<T>>
class vector
```
* 벡터내 원소는 연속적으로 저장되기 때문에 iterator뿐만 아니라 인덱싱도 가능하다
* 벡터의 포인터는 배열 포인터를 파라미터로 하는 함수에 전달될 수 있다
* 벡터는 가변 크기를 가지며 원소가 삽입, 삭제됨에 따라 확장, 축소된다
* 일반적으로 static array보다 많은 메모리를 차지한다 (가변성을 위해)
    * 삽입할 때마다 크기를 재할당하지 않기 위해서이다
    * 메모리가 모두 소진된 경우에만 재할당한다

### Time Complexity
||tc|
|-|-|
|random access|$O(1)$|
|insert (last)|$O(1)$|
|delete (last)|$O(1)$|
|insert|$O(n)$|
|delete|$O(n)$|

### Template Parmeters
|param|description|
|-|-|
|`T`|원소의 타입|
|`Allocator` (optional)| 메모리 자원을 획득/반환하고 원소를 생성/삭제하는 데 사용되는 할당자|

+) `bool` 타입에 대해서는 메모리 효율성을 위해 동적 비트셋*dynamic bitset*으로 특수하게 구현된다.

### Core Member Functions
주요 메소드

#### Element access
|function|description|
|-|-|
|`at`|특정 원소 접근 with bound checking|
|`operator[]`|특정 원소 접근|
|`front`|첫 번째 원소 접근|
|`back`|마지막 원소 접근|

#### Iterators
|function|description|
|-|-|
|`begin`|첫 번째 원소의 iterator|
|`end`|마지막 원소의 iterator|
|`rbegin`|첫 번째 원소의 reversed iterator|
|`rend`|마지막 원소의 reversed iterator|

```cpp
#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6};
    
    for_each(nums.begin(), nums.end(), [](const int n)) {
        cout << n << endl;
    }
}
```

#### Capacity
|function|description|
|-|-|
|`empty`||
|`size`||
|`max_size`||
|`reverse`||
|`capacity`||
|`shrink_to_fit`||

#### Modifier
|function|description|
|-|-|
|`clear`||
|`insert`||
|`insert_range`||
|`emplace`||
|`erase`||
|`push_back`||
|`emplace_back`||
|`append_range`||
|`pop_back`||
|`resize`||
|`swap`||
