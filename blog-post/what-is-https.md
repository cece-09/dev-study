# What is HTTP and HTTPS?

## HTTP (Hypertext Transfer Protocol)
* W3에서 정보를 주고받기 위한 위한 통신 규칙 세트 또는 프로토콜
* 클라이언트와 서버 사이에 이루어지는 요청request과 응답response의 프로토콜
* HTML을 주고받는 데 주로 쓰인다.
* HTTP/1 ~ HTTP/2는 TCP, HTTP/3은 UDP를 사용한다. 포트는 80

### 요청과 응답의 예시
```
[request]
GET /images/logo.jpg HTTP/1.1
Accept-Language: en

[response]
HTTP/1.1 200 OK
Content-Type: text/html
...
```

## SSL (Secure Socket Layer)
* 응용 레이어에서 생성된 데이터를 압축하고 보안을 제공하기 위해 만들어진 프로토콜
* 응용 레이어의 프로토콜이므로 보안을 위해 전송 레이어의 보안 프로토콜을 사용함 (아래)
* 전송 계층 보안(TLS)의 일종, TCP 또는 SCTP를 connection-oriented 프로토콜로 사용함 (?)

* TLS/SSL의 과정
1. 알고리즘을 서로 교환
2. 키 교환, 인증
3. 대칭 키 암호로 암호화하고 메시지 인증
