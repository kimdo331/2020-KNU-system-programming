/**
 * @file snake_lib.h
 * @author Dohyun Kim (00dh.kim@gmail.com)
 * @brief library header file for snake project
 * @version 0.1
 * @date 2020-12-18
 * 
 */

// 한번만 include 하기 위함
#ifndef SNAKE_LIB_H
#define SNAKE_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <termio.h>
#include <curses.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

// define color constants
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define MAP_SIZE 20
#define MAX_SNAKE_LENGTH 100

enum DirectionNumber {
    right = 0, left, down, up
};

// map[][] 에 들어갈 숫자들
enum MapNumber {
    emptyNum = 0, snake1Num, foodNum, wallNum = 9, snake2Num = 4
};

typedef struct pos {
    int i;
    int j;
}pos;

int map[MAP_SIZE + 2][MAP_SIZE + 2] = { 0, }; // 실질적인 지도
pos snake1[MAX_SNAKE_LENGTH + 2] = { 0, };	// 여기에 뱀의 각 부위의 좌표 적을거임. snake1[0]: 머리
pos snake2[MAX_SNAKE_LENGTH + 2] = { 0, }; // 멀티플레이에서만 쓰이는 두번째 뱀 배열
int length1 = 1, length2 = 1;	// 뱀의 길이, 먹이를 먹으면 +1
int death1 = 0, death2 = 0;	// 0이면 생존, 1이면 사망
int grow = 0;	// 1이면 성장할 예정, 매 턴마다 초기화
int di, dj;     // 매 턴마다 초기화
pos food;   // 음식 위치를 담은 변수

int random_(int a, int b);
void set_food_posit();
int print_home();
void init_(int mode);
void set_food_posit();
int input_direction();
void what_is_direction(int direc, int user);
void move_(int user);
void print_map(int mode, int user);
void show_scoreboard();
void single_main_function();
void program_exit(int mode);


#endif /* SNAKE_LIB_H */