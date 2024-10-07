# [Silver I] ESC - 30991 

[문제 링크](https://www.acmicpc.net/problem/30991) 

### 성능 요약

메모리: 1112 KB, 시간: 0 ms

### 분류

미적분학, 다이나믹 프로그래밍, 수학

### 제출 일자

2024년 10월 8일 00:38:12

### 문제 설명

<p>함수를 미분해 보자!</p>

<p>어떤 미분가능한 함수 $f(x)$가 주어졌을 때, 미분한 결과를 $f'(x)$라고 표현한다. 만약 $f'(x)$도 미분가능하다면 미분하여 함수 $f{'}{'}(x)$를 얻을 수 있다. 만약 $f(x)$를 여러 번 미분할 수 있다면 $f^{(n)}(x)$$(=f{\overbrace {{'}{'}{}^{\cdots }{'}} ^{n}}(x))$는 $f(x)$ 함수를 $n$번 미분한 결과라고 정의할 수 있다. 예를 들어 다음 $3$개의 함수를 미분해 보자.</p>

<ul>
	<li>미분가능한 함수 $E(x) = e^x$가 있을 때, $e^x$를 미분한 결과는 $e^x$이므로 $E'(x)=e^x$이다.</li>
	<li>미분가능한 함수 $S(x) = \sin x$가 있을 때, $\sin x$를 미분한 결과는 $\cos x$이므로 $S'(x)=\cos x$이다.</li>
	<li>미분가능한 함수 $C(x) = \cos x$가 있을 때, $\cos x$를 미분한 결과는 $-\sin x$이므로 $C'(x)=-\sin x$이다.</li>
</ul>

<p>신기하게도 위에서 소개한 $3$개의 함수는 원하는 만큼 미분을 해도 항상 미분가능한 함수가 나타난다. 이 $3$개의 함수를 모두 곱한 $\text{ESC}(x) = e^x \sin x \cos x$ 함수도 원하는 만큼 미분을 해도 계속 미분이 가능할까? 놀랍게도 계속 미분이 가능하다! 한 번 미분을 시도해 보자. 미분가능한 세 함수 $f(x)$, $g(x)$, $h(x)$가 있을 때 $f(x) \times g(x) \times h(x)$를 미분한 결과는 다음과 같다.</p>

<ul>
	<li>$[f(x)g(x)h(x)]'= f'(x)g(x)h(x)+f(x)g'(x)h(x)+f(x)g(x)h'(x)$</li>
</ul>

<p>그러므로 $\text{ESC}'(x) = e^x \sin x \cos x + e^x \cos x \cos x + e^x \sin x (-\sin x)$ 이다. 한편 $\cos x \cos x$는 $\cos^2 x$로, $\sin x (-\sin x)$는 $-\sin^2 x$로 표현할 수 있으므로 정리하면 $\text{ESC}'(x) = e^x \sin x \cos x + e^x \cos^2 x - e^x \sin^2 x$으로 표현할 수 있다. $\text{ESC}'(x)$를 한 번 더 미분해 보자.</p>

<ul>
	<li>$[e^x \sin x \cos x]'= e^x \sin x \cos x + e^x \cos^2 x - e^x \sin^2 x$</li>
	<li>$[e^x \cos x \cos x]' = e^x \cos x \cos x + e^x (-\sin x) \cos x + e^x \cos x (-\sin x) = e^x \cos^2 x - 2 e^x \sin x \cos x$</li>
	<li>$[e^x \sin x \sin x]'= e^x \sin x \sin x + e^x \cos x \sin x + e^x \sin x \cos x = e^x \sin^2 x + 2 e^x \sin x \cos x$</li>
</ul>

<p>이므로 $\text{ESC}{'}{'}(x) = - 2 e^x \sin^2 x + 2 e^x \cos^2 x - 3 e^x \sin x \cos x$ 이다. 그러므로 $\text{ESC}(x)$ 함수는 계속 미분가능하고, 미분한 결과는 $e^x \sin x \cos x$, $e^x \cos^2 x$, $e^x \sin^2 x$를 각각 상수배한 후 합쳐서 표현할 수 있다! 따라서 $\text{ESC}^{(n)}(x)$를 다음과 같이 표현할 수 있다.</p>

<ul>
	<li>$\text{ESC}^{(n)}(x)=a_n e^x \sin ^2 x + b_n e^x \cos ^2 x + c_n e^x \sin x \cos x$ (단, $a_n$, $b_n$, $c_n$은 정수)</li>
</ul>

<p>$n$이 주어지면 $a_n + b_n + c_n$의 값을 구하는 프로그램을 작성해 보자.</p>

### 입력 

 <p>첫 번째 줄에 정수 $n$이 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 $a_n + b_n + c_n$ 값을 출력한다.</p>

