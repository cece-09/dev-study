# Abstract Data Structure

### 1분 답변 정리
사용자 관점에서 자료+이에대한 연산을 명시한 것.
자료구조와는 구현 방법을 포함하지 않는다는 점에서 다름 ex. 스택을 예를 들어 설명해도 좋음

#### Q1. 추상 자료형이란 무엇인가요?
사용자의 관점에서 자료들과 자료들에 대한 연산을 명기한 것이다.

#### Q2. 추상 자료형은 자료구조와 어떤 점에서 다른가요?
구현 방법을 명시하고 있지 않다는 점에서 다르다. 자료구조로서 stack, queue는 각 연산의 구현 방법을 포함하지만, ADT는 이를 포함하지 않는다.

#### Q3. 추상 자료형과 구체적 자료구조는 어떻게 다른가요? 예를 들어 설명해주세요.
* 추상적 자료구조 Abstract Data Type
* 구체적 자료구조 Concrete Data Structure

구체적 자료구조는 자료구조의 구현 방법을 포함하는 반면, 추상적 자료구조는 구현에는 관심이 없다. 예를 들어 ADT 스택은 pop, push, size 등의 연산 정의로 구성되어 있다. 반면 Concrete 자료구조로서의 스택은 구현을 위해 배열을 사용할지, 연결 리스트를 사용할지 등과 관련이 있다. 배열로 구현할 경우, MAX_SIZE와 같은 고정된 크기로 구현되는 반면, 리스트로 구현할 경우 가변적인 길이를 가질 수 있다.

#### Q4. 추상 자료형은 왜 중요하다고 생각하나요? 예를 들어 설명해주세요.
효율적인 알고리즘을 설계할 때 중요하다고 생각한다. 예를 들어, 핀토스에서 하나의 프로세스에 대한 가상메모리를 관리할 때 할당된 메모리를 리스트로 관리하는 것보다 주소값을 키로 하는 맵 형태로 관리하면 해당 주소값을 갖는 메모리에 상수 시간 안에 접근할 수 있어 효율적이다. 반면, 시스템의 모든 프로세스에 대해 전역적으로 존재하는 프레임 테이블은 리스트로 구현하기도 하는데, 이는 스왑 아웃 할 프레임을 고르기 위해 Clock 알고리즘을 구현할 때 용이하기 때문이다. 이렇듯 추상자료형을 잘 선택하는 것은 효율적인 알고리즘 설계에 중요하다.

#### Q5. 정글 과정에서 어떤 자료구조들을 사용했나요? 예를 들어 한 가지만 설명해주세요.
Web Proxy 과제를 하면서 한 번 요청한 응답을 캐싱하는 캐시 테이블에 doubly linked list를 사용했다. 만약 캐시 테이블이 가득 찬 경우, 가장 이전에 참조된 캐시를 할당 해제하는 LRU 알고리즘을 구현하기 위해서였다. 리스트의 헤드에서부터 캐시를 쌓고, 캐싱된 요청이 들어올 경우 리스트에서 중간 삭제 후 맨 뒤로 push하도록 처리했다. 이를 통해 캐시 미스가 발생했는데 테이블이 가득 찬 경우, 맨 앞에 있는 캐시를 할당 해제하는 식으로 LRU를 구현했다.

Pintos에서 프레임 테이블을 circular doubly linked list로 구현했다. Clock 알고리즘을 구현하기 위해서였다. 리스트를 원형으로 순회하는 알고리즘이라, 핀토스에서 기본 제공되는 이중 연결 리스트 코드를 약간 커스텀해서 circular queue를 만들어 사용했다.
* clock hand, 즉 이전에 탐색을 마친 부분에서 시작해서 프레임 리스트를 순회한다.
* 만약 dirty bit가 세팅되어 있으면 0으로 바꾸고 다음으로 넘어간다.
* 그렇지 않으면 evict frame으로 선택하고 리턴한다.

또 다른 경우들?
* Pintos에서 보조 페이지 테이블을 HashMap으로 구현 → lazy load등과 같은 경우에서, 해당 가상주소가 페이지 테이블에 있는지 없는지, 그 유무를 체크해야 했음. 이를 위해 전체 테이블을 순회하지 않고도 상수 시간 복잡도로 체킹할 수 있도록 해시맵 사용.
* Pintos에서 swap disk 가용여부를 체크하는 테이블은 BitMap으로 구현 → 디스크 섹터 번호를 인덱스로 하는 비트맵으로 구현했음. 해당 섹터가 사용 가능한지 아닌지만 보면 되었기 때문.

#### Q6. ADT map을 구현하는 방법에는 어떤 것이 있나요?

Abstract Data Type으로서 map은 키-값 쌍으로 이루어진 컬렉션을 저장하는 자료형으로, dictionary, associative array, symbol table 등으로도 불린다. 대표적인 구현 방법에는 해시 테이블과 균형 이진 탐색 트리가 있다.

* Hash Table: 해시 테이블은 값을 버킷 혹은 슬롯에 저장하는데, 이 버킷의 인덱스 즉 해시 코드를 계산하기 위해 해시 함수를 사용한다. 데이터와 버킷 인덱스가 해시 함수를 통해 직접 매핑되므로 삽입/삭제/검색에 $O(1)$ 시간복잡도가 소요된다.
* Self-balancing BST: 이진 탐색 트리는 키를 기준으로 데이터를 정렬해 관리함으로써 값의 삽입/삭제/검색에 $O(logN)$ 시간복잡도가 소요된다.

||Pros|Cons|
|Hash Table|시간복잡도가 최저이다|해시 충돌의 위험이 있다, 범위 탐색에 불리하다|
|Self-balancing BST|범위 탐색에 유리하다|시간복잡도가 Hash대비 높다|

**메모리 관점에서 양자 비교**

해시 테이블은 해시 충돌을 피하기 위해 실제 저장된 값 대비 버킷의 수를 충분히 크게 할당받는다. 반면, Red Black Tree와 같은 균형 이진 탐색 트리는 기본적으로 실제 저장된 값 만큼의 노드를 갖고, nil node를 갖는다. nil node는 리프 노드마다 서로 다르게 갖지 않고 단일한 sentinel node로서 구현될 수 있기 때문에 사실상 저장된 값 만큼의 노드를 할당받는다고 볼 수 있다. 물론 노드의 내부 구현에 따라 약간 단편화가 발생할 수 있지만 (자식 노드 포인터가 필요하므로), 일반적으로 해시 테이블 대비 균형 이진 탐색 트리가 메모리 이용도가 높은 편이라고 볼 수 있다.

**범위 검색 관점에서 양자 비교**

균형 이진 탐색 트리가 값을 순서 있게 저장하는 반면, 해시 테이블은 정렬된 상태로 저장하지 않는다. 따라서 범위를 검색하는 상황에서 균형 BST는 $O(logN + M)$ (M은 찾고자 하는 노드 수), 해시 테이블은 $O(N)$ 시간복잡도가 걸린다. 따라서 범위를 검색하는 경우에 균형 이진 탐색 트리가 해시 테이블보다 높은 성능을 낼 수 있다.

```c
// Binary Search Tree
void range_lookup(Node* root, int _a, int _b) {
    // use inorder traversal
    if(root == NULL) {
        return;
    }

    if(root->key > _a) {
        range_lookup(root->left, _a, _b);
    }

    if(root->key > _a && root->key < _b) {
        printf("%d\n", root->key); // print
    }

    if(root->key < _b) {
        range_lookup(root->right, _a, _b);
    }
}
```

```c
// Hash Map (with chaining)
void range_lookup(Slot* buckets, int bucket_size, int _a, int _b) {
    for(int i = 0; i < bucket_size; i++) {
        Node* node = buckets[i].head; // head node of linked list
        while(node != NULL) {
            if(node->key > _a && node->key < _b) {
                printf("%d\n", node->key);
            }
            node = node->next; // next
        }
    }
}
```

+) **Treeify in HashMap** Java 8부터 HashMap에서 같은 버킷 내 노드를 관리하기 위해 링크드 리스트가 아닌 Red Black Tree를 사용한다. 오버헤드를 줄이기 위해 `TREEIFY_THRESHOLD`와 같은 상수값을 두고 이를 넘어가는 경우만 리스트에서 트리로 변환한다.

![image](https://miro.medium.com/v2/resize:fit:1026/format:webp/1*5WkSuCZ3VcNOQwYktFGlJA.png)

[The Secret Improvement of HashMap in Java 8](https://runzhuoli.me/2018/08/31/the-secret-improvement-of-hashmap-in-java8.html)

[A Deep Dive into Java 8 HashMap](https://medium.com/geekculture/a-deep-dive-into-java-8-hashmap-a976aca22f9b)


+) **Dictionary Problem**은 associative array를 구현하기 위한 효율적인 자료구조를 설계하는 고전적인 문제이다. 두 가지 주요 솔루션은 해시 테이블과 탐색 트리이다. 탐색 트리에는 BST, B-Tree, Ternary Search Tree 등 다양한 트리 자료구조가 포함될 수 있다.