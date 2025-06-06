# [Silver I] Inherited disease - 10897 

[문제 링크](https://www.acmicpc.net/problem/10897) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 수학, 트리

### 제출 일자

2024년 12월 31일 14:55:11

### 문제 설명

<p>정민이라는 생물을 아는가? <strong>JMPABU</strong>(JeongMin is Paramecium & Amoeba Based Unicellular organism)라는 말을 보면 알겠지만, 정민은 단세포생물이다. 나는 1여년간 정민이라는 생물에 대해 연구하면서 다음과 같은 특징들을 찾아내었다.</p>

<ul>
	<li>D세대의 정민이 자식을 낳으면 그 자식은 D+1세대가 되는 것이다. D세대인 정민은 살면서 정확히 D+1명의 자식을 남긴다. 그 이후에는 죽는다.</li>
	<li>정민은 특이한 유전자를 가지고 있는데, 이 유전자는 정민이 태어난 순서에 따라 유전병을 일으키는 유전자가 될 수도 있다.</li>
</ul>

<p>나는 0 세대인 정민을 한 마리 가지고 있고, 이 정민에게 0 번을 붙이기로 하였다.또한 이 정민의 자손들에게도 편의를 위해 번호를 붙이기로 하였다. 번호를 붙이는 과정은 아직 자식들에게 번호가 붙지 않은 정민들 중에 가장 작은 번호인 정민을 뽑아 그 자식들에게 태어난 순서대로 아직 붙여지지 않은 가장 작은 번호를 붙이는 것을 반복하기로 하였다. 그렇게 하면 아래와 같게 번호가 붙을 것이다.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10897/pic1.png" style="height:192px; width:387px"></p>

<p>나는 정민이 어떤 순서로 태어나야 유전병에 걸리게 되는지 실험을 계속하고 있다. 실험방법은 간단하다. 각 정민이 태어난 순서를 따라가는 것이다. 예를 들어서 0세대에서 1번째로 태어난 자식에게서 2번째로 태어난 자식의 1번째로 태어난 자식... 과 같이 보면서 유전병이 있는지 검사하는 것이다. 위와 같이 할 경우 보게 되는 정민의 번호는 순서대로 1,3,7이 된다. 그러나 이 과정이 세대수가 커지면 커질수록 번호가 너무 커져서 힘들어지게 되었다. 당신의 도움이 필요하다.</p>

### 입력 

 <p>첫 번째 줄에 조사하고자 하는 정민의 세대 D(1 ≤ D ≤ 100)가 주어진다.</p>

<p>두 번째 줄에는 D개의 정수가 주어지는데, 차례대로 d<sub>i</sub> (1 ≤ i ≤ D,1 ≤ d<sub>i</sub> ≤ i)가 공백으로 구분되어 주어지며, d<sub>i</sub>는 i−1 세대의 정민이 d<sub>i</sub>번째로 낳은 자식을 보겠다는 의미이다.</p>

### 출력 

 <p>출력은 D개의 줄로 이루어진다. k번째 줄에는 주어진 입력을 따라 가면서 보게 되는 세대가 k인 정민의 번호를 출력하면 된다. 번호가 매우 커질 수 있으므로 번호를 1,000,000,007로 나눈 나머지를 출력한다.</p>

