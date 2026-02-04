# [Gold II] 바바와 깃발 게임 - 35185 

[문제 링크](https://www.acmicpc.net/problem/35185) 

### 성능 요약

메모리: 5588 KB, 시간: 4 ms

### 분류

구현, 애드 혹, 시뮬레이션

### 제출 일자

2026년 2월 4일 11:18:30

### 문제 설명

<p>나나는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\times N$</span></mjx-container> 게임판 위에서 진행되는 게임을 하고 있다. 게임판 위에는 한 마리의 바바와 하나의 깃발이 놓여져 있다. 바바와 깃발은 서로 다른 위치에 놓여 있다.</p>

<p>나나는 바바를 L, R 명령어를 이용해 조종할 수 있다. L 명령어는 바바를 한 칸 왼쪽, R 명령어는 바바를 한 칸 오른쪽으로 이동시킨다. 만약 이동하고자 하는 방향이 게임판 바깥이라면, 바바는 이동하지 않는다.</p>

<p>바바를 조종해 바바가 깃발과 같은 칸에 놓이게 되는 순간 게임에서 승리하며 게임은 즉시 종료된다. <strong>게임이 종료된 후에는 추가적인 명령어를 입력할 수 없다</strong>.</p>

<p>옆에서 지켜보고 있던 라라는, 나나가 입력한 명령어들을 끝까지 똑같이 입력해서 승리할 수 있는 게임판이 있는지 궁금해졌다. 라라를 위해서 그런 게임판이 존재하는 지 찾아주자.</p>

### 입력 

 <p>첫 번째 줄에, 게임판의 크기인 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 나나가 입력한 명령어의 개수인 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D43F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>L</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$L$</span></mjx-container>이 공백을 사이에 두고 주어진다.</p>

<p>두 번째 줄에, 나나가 입력한 명령어에 해당하는 길이 L의 문자열이 주어진다.</p>

### 출력 

 <p>문제의 조건을 만족하는 게임판이 존재하지 않는다면, <code>DEFEAT</code>를 출력한다.</p>

<p>게임판이 존재한다면 <code>WIN</code>를 출력하고, 이어지는 줄에 바바의 위치 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>와 깃발의 위치 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D439 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>F</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$F$</span></mjx-container>를 출력한다.</p>

