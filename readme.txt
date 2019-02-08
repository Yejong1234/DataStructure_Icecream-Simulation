<문제 1>

1) Purpose of this code

doubly linked node로 구성된 stack을 만들고 ADT를 수행하는 함수를 만드는 것

2) Input and Output 

push 함수를 통해 여러개의 숫자를 넣고 pop을 통해 빼기 연산을 진행 후 결과 출력

3) variables I used

구조체 변수를 rlink와 llink 둘 다 선언해서 각각의 link를 유용하게 사용해 push, pop연산이 쉽게 가능하도록 하였다.

<문제 2>

1) Purpose of this code

은행에 2명의 스태프들이 있고 10분동안 고객들이 계속 들어올 때 wait time이 어느정도 될 지 알아보는 프로그램

2) Input and Output 
Input은 10분동안 매 1분마다 rand를 사용해서 고개들이 오는지 안오는지 체크하였고 output은 프로그램에 따라
고객들이 얼마나 기다린 후에 서비스를 받았는지를 출력

3) variables I used
프로그램을 짜기 위해서 다양한 variables를 구성했다. 우선 고객들의 id, service time, arrival time들을 담은 구조체를 선언
또한 고객들이 있는 대기실을 queue로 선언해서 먼저 온 고객이 나올 수 있도록 하였다.