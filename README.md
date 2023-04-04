# Shogi with linked list in C

HAVE FUN!

109503510_通訊三_龍芃如

## INTRODUCTION

日本將旗程式

* 判斷行法是否違規

* 有儲存棋譜功能

* 可以悔棋

* 支援棋譜重播功能
-------------------------------------
# Getting Started!

## Compile & Run & Play

```sh
# Compile
cd 109503510_assignment_2/
gcc -o main src/main.c inc/move.h inc/init.h inc/print.h inc/rule.h 
# Run
./main -n -s [filename.txt]
# Play(數字1~9)
動哪個(段) (筋):
去哪裡(段) (筋):
輸入f繼續玩 or 輸入b反悔 or 輸入q離開:
# FOR EXAMPLE
動哪個(段) (筋):3 1
去哪裡(段) (筋):4 1
輸入f繼續玩 or 輸入b反悔 or 輸入q離開:f

# 重播棋譜
./main -l [filename.txt]
```

## Reference
https://shogi.hk/Gameplay-of-Japanese-Chess-Shogi/

