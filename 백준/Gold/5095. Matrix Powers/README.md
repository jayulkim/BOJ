# [Gold IV] Matrix Powers - 5095 

[문제 링크](https://www.acmicpc.net/problem/5095) 

### 성능 요약

메모리: 1312 KB, 시간: 264 ms

### 분류

분할 정복을 이용한 거듭제곱, 선형대수학, 수학

### 제출 일자

2024년 10월 7일 20:44:31

### 문제 설명

<p>Your task is to write a program to raise an integer matrix to a given power using modulo arithmetic. There is no back story here; at least not one that can be told. The application is too confidential (spying and military intelligence and all that) to be described in public.</p>

<p>For example, to raise the 2 by 2 matrix </p>

<p>\[\begin{pmatrix}  1&2  \\  3&4  \end{pmatrix}\]</p>

<p>to the power 2 using modulo 17 arithmetic </p>

<p>\[\begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix}\times \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix} = \begin{pmatrix}(1 \times 1 + 2 \times 3) \text{ mod } 17 & (1 \times 2 + 2 \times 4) \text{ mod } 17 \\ (3 \times 1 + 4 \times 3) \text{ mod } 17 & (3 \times 2 + 4 \times 4) \text{ mod } 17  \end{pmatrix} = \begin{pmatrix} 7 & 10 \\ 15 & 5 \end{pmatrix}\]</p>

### 입력 

 <p>The input consists of a number of problems. Each problem starts with a line holding three numbers (N, M, and P) separated by single spaces. 1 ≤ N ≤ 100 is the size (N by N) of the matrix to be processed. 1 ≤ M ≤ 32000 is the modulo base and 1 ≤ P ≤ 32000 is the power to which the matrix must be raised. Following this line are N lines, each holding the n integer values of successive rows of the matrix as a series of positive integers i: 0 ≤ i < M separated by single spaces. Input is terminated by a line with three zeros.</p>

### 출력 

 <p>Output for each problem consists of the N rows of the result matrix, followed by a blank line. Each row is output on a single line as a sequence of integer values separated by single spaces. It doesn’t matter that lines may be quite long – no-one will be allowed to read them anyway.</p>

