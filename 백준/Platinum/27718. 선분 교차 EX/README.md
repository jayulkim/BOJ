# [Platinum V] 선분 교차 EX - 27718 

[문제 링크](https://www.acmicpc.net/problem/27718) 

### 성능 요약

메모리: 6240 KB, 시간: 336 ms

### 분류

많은 조건 분기, 기하학, 선분 교차 판정

### 제출 일자

2024년 10월 8일 00:26:39

### 문제 설명

<p>주어진 $N$개의 선분 중 중복을 허용하여 두 개를 고르는 모든 경우에 대해, 두 선분이 다음 중 어떤 관계인지 구하는 프로그램을 작성하시오.</p>

<ul>
	<li>0: 교점이 없음</li>
	<li>1: 교점이 정확히 하나 있으며, 그 교점이 적어도 한 선분의 끝점임</li>
	<li>2: 교점이 정확히 하나 있으며, 그 교점이 어느 선분의 끝점도 아님</li>
	<li>3: 교점이 무한히 많이 있음</li>
</ul>

### 입력 

 <p>첫 줄에 $N$이 주어진다. ($1 \leq N \leq 2\,000$)</p>

<p>그 다음 줄부터 한 줄에 한 선분씩, 한 끝점의 $x$ 좌표와 $y$ 좌표, 그리고 다른 끝점의 $x$ 좌표와 $y$ 좌표가 주어진다. 모든 좌표는 정수이고 $-10^9$ 이상 $10^9$ 이하이다. 길이가 $0$인 선분은 없다.</p>

### 출력 

 <p>한 줄에 숫자 $N$개씩 공백 없이 총 $N$줄 출력한다. $i$번째 줄의 $j$번째 숫자는 $i$번째와 $j$번째 선분의 관계를 나타내는 숫자이다.</p>

