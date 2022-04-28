# 설명
1. start는 timer운용을 초기화 하는 현재 timer1ms 값
2. target은 원하는 시간만큼 기다렸을 때 timer1ms 값
3. jump는 timer1ms가 1식 증가하지 않고 1보다 크게 정도. 만약 2면 timer가 2식 증가한다.

# 초기화
1. 원하는 시간이 0이면 타이머를 운용하지 않는다. `SETTING_ZERO` 출력
2. 현재 시간을 timer1ms를 start에 저장한다.
3. start와 원하는 시간을 더해서 sum에 저장하고 그 값이 현재 시간보다 작으면 overflow 상태임으로
  `overflowFlag = 1` 로 둔다. 만약 그 값이 현재시간보다 크면 overflow상태가 아니므로 `overflowFlag = 0`
4. target에 sum 값을 저장하고, 출력을 `WAITTING`으로 한다.

# timer 확인
1. `overflowFlag = 0`인 상태는 timer1ms 값이 target보다 크거나 같으면 TIME_OVER이다.
2. `overflowFlag = 1`인 상태는 timer1ms 값이 start보다 작아지면, timer1ms가 도달할 수 있는 최대값을 지나서 초기화가 된 것이기 떄문에 `overflowFlag`를 `0`으로 변경한다.

# 문제점
 1. timer1ms에 jump가 발생하면 `timer 확인 2`에서 초기화 된 상황을 놓쳐 무한 루프에 빠질 수 있다.
   예시 1) `timer1ms = 2, target = 0, jump =2`인 경우에서 초기화 후에 상태는 `start =2, overflowFlag = 1`이다. timer1ms가 순차적으로 증가하다가 timer1ms가 0일 때 2로 점프하면, `start =2`와 같은 값이 되어서 `overflowFlag = 0` 조건에 부적합하다. 