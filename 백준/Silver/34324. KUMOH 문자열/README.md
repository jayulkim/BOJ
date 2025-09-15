# [Silver III] KUMOH 문자열 - 34324 

[문제 링크](https://www.acmicpc.net/problem/34324) 

### 성능 요약

메모리: 4268 KB, 시간: 32 ms

### 분류

구현, 문자열

### 제출 일자

2025년 9월 15일 16:14:23

### 문제 설명

<p>보경이는 문자열을 가지고 노는 것을 좋아한다. 특히 <span style="color:#e74c3c;"><code>KUMOH</code></span>라는 문자열을 아주 좋아한다.</p>

<p>매번 세로와 가로로 <span style="color:#e74c3c;"><code>KUMOH</code></span>를 찾는 것이 지루했던 보경이는, 이번에는 대각선으로 읽어 <span style="color:#e74c3c;"><code>KUMOH</code></span>를 찾기로 하였다.</p>

<p>우선 $N$개의 행과 $1\,000$개의 열로 이루어진 격자를 준비한다. $(i,j)$는 위에서부터 $i$번째 행, 왼쪽에서부터 $j$번째 열이 교차하는 칸을 나타낸다. 모든 칸에는 최초에 아무 문자도 적혀있지 않다.</p>

<p><span style="color:#e74c3c;"><code>K</code></span>, <span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>M</code></span>, <span style="color:#e74c3c;"><code>O</code></span>, <span style="color:#e74c3c;"><code>H</code></span>로 이루어진 $N$개의 문자열 $S_1,S_2,\cdots,S_N$이 주어진다. 보경이는 문자열 $S_i$의 $j$번째 문자를 $(i,j)$에 적었다.</p>

<p>보경이는 다음과 같이 문자열을 읽어 나갈 것이다.</p>

<ul>
	<li>먼저 $1$번째 열의 모든 칸을 위에서 아래 순서로 나열하고, 이어서 $N$번째 행의 모든 칸을 왼쪽에서 오른쪽 순서로 나열한다. 단, $(N,1)$칸은 한 번만 포함한다.</li>
	<li>이렇게 만들어진 칸들의 순서열을 $A_1, A_2, \cdots , A_k$라고 하자.</li>
	<li>모든 $1\le t\le k$에 대해 다음 과정을 반복한다.
	<ul>
		<li>칸 $A_t$로 이동하고, 빈 문자열 $T$를 지정한 뒤, 다음 과정을 반복한다.
		<ul>
			<li>현재 위치한 칸에 적힌 문자가 있다면, $T$의 맨 뒤에 이어 붙인다.</li>
			<li>$(i,j)$에 위치한 경우 $(i-1,j+1)$로 이동한다. 만약 격자를 벗어났다면 종료한다.</li>
		</ul>
		</li>
		<li>문자열 $T$를 앞에서부터 읽었을 때 나타나는 연속한 부분문자열 <span style="color:#e74c3c;"><code>KUMOH</code></span>의 개수를 $X$라 하자.</li>
		<li>문자열 $T$를 뒤에서부터 읽었을 때 나타나는 연속한 부분문자열 <span style="color:#e74c3c;"><code>KUMOH</code></span>의 개수를 $Y$라 하자.</li>
		<li>$\max \{X, Y\}$가 $t$번째 대각선에서 <span style="color:#e74c3c;"><code>KUMOH</code></span>의 등장 횟수 $B_t$가 된다.</li>
	</ul>
	</li>
	<li>$B_1 + B_2 + \cdots + B_k$가 <span style="color:#e74c3c;"><code>KUMOH</code></span> 문자열의 총등장 횟수가 된다.</li>
</ul>

<p>막상 규칙을 세워 보니, 보경이에게는 모든 대각선을 따라 <span style="color:#e74c3c;"><code>KUMOH</code></span> 문자열의 모든 등장 횟수를 직접 세는 것은 너무 어려운 일이었다.</p>

<p>문자열을 꼭 읽고 싶었던 보경이는 코딩을 잘하는 여러분에게 도움을 청했다. 여러분이 대신 <span style="color:#e74c3c;"><code>KUMOH</code></span> 문자열이 총 몇 번 등장하는지 구해 주자!</p>

### 입력 

 <p>첫째 줄에 문자열의 개수를 나타내는 정수 $N$이 주어진다. $(1\le N\le 1000)$</p>

<p>둘째 줄부터 $N$개의 줄에 걸쳐 문자열 $S_i$가 주어진다. $(1\le |S_i|\le 1000)$</p>

<p>각 문자열은 <span style="color:#e74c3c;"><code>K</code></span>, <span style="color:#e74c3c;"><code>U</code></span>, <span style="color:#e74c3c;"><code>M</code></span>, <span style="color:#e74c3c;"><code>O</code></span>, <span style="color:#e74c3c;"><code>H</code></span>로만 구성된다.</p>

### 출력 

 <p><span style="color:#e74c3c;"><code>KUMOH</code></span> 문자열의 총등장 횟수를 출력한다.</p>

