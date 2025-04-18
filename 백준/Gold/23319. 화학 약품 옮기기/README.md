# [Gold II] 화학 약품 옮기기 - 23319 

[문제 링크](https://www.acmicpc.net/problem/23319) 

### 성능 요약

메모리: 2368 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 배낭 문제

### 제출 일자

2025년 3월 24일 16:05:32

### 문제 설명

<p>한 회사에서 연구실에 보관되어 있는 화학 약품들을 옮기기로 결정하였다. 이 회사에는 두 개의 연구실(각각 A, B 연구실이라 하자)이 있고, 각 연구실에는 n가지 종류의 화학 약품들이 보관되어 있다. 연구실의 크기 문제 등으로 각 연구실에는 n가지 화학 약품밖에 보관할 수 없기 때문에, A 연구실의 화학 약품들을 같은 개수의 B 연구실의 화학 약품들과 바꾸어야 한다.</p>

<p>화학 약품이 보관되어 있는 연구실을 바꾸는 것은 회사의 기밀이 새 나가는 것을 막아주는 효과가 있기 때문에, 회사측에서는 최대한 많은 화학 약품들을 옮기려고 한다. 하지만 문제가 있는데, 일부 화학 약품은 같은 연구실에 보관할 경우 안전사고가 발생할 위험이 있다. 또한 화학 약품을 옮기는 과정에서도 안전사고가 발생할 수 있기 때문에, n/2 종류를 초과해서 화학 약품을 바꾸지는 않기로 하였다.</p>

<p>같은 연구실에 보관할 수 없는 화학 약품들의 목록이 주어졌을 때, 옮길 수 있는 화학 약품의 최대 종류수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 두 정수 n(1 ≤ n ≤ 200), m(0 ≤ m ≤ n<sup>2</sup>)이 주어진다. m은 같은 연구실에 보관할 수 없는 약품들의 쌍의 개수이다. 다음 m개의 줄에는 두 정수 a, b(1 ≤ a, b ≤ n)가 주어진다. 이는 A 연구실에 보관되어 있는 a번 약품을 B 연구실의 b번 약품과 함께 보관할 수 없다는 의미이다.</p>

### 출력 

 <p>첫째 줄에 옮길 수 있는 화학 약품의 최대 종류수를 출력한다.</p>

