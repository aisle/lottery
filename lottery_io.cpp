#include "lottery_io.h"

// 开奖号码
const std::vector<int> kTarget =
    // add new lottery targets here.
    // {1, 6, 12, 18, 22, 24, 3}; // 2020092
    // {4, 5, 10, 13, 15, 19, 15}; // 2020093
    // {10, 15, 17, 27, 29, 31, 8}; // 2020094
    {1, 20, 23, 26, 27, 32, 15}; // 2020096

// 彩票号码
const std::vector<std::vector<int>> kTickets = {
    {2, 11, 17, 22, 28, 33, 7}, // default
//    {2, 3, 13, 17, 19, 25, 2},
//    {5, 9, 13, 25, 28, 33, 11},
//    {12, 19, 24, 25, 31, 33, 9},
//    {6, 12, 16, 22, 30, 33, 13},
//    {9, 17, 22, 23, 27, 28, 11},
//    {15, 18, 21, 22, 27, 29, 13},
//    {7, 10, 14, 16, 17, 30, 8},
//    {1, 2, 9, 18, 21, 28, 8},
//    {2, 23, 24, 25, 28, 32, 11},
//    {1, 10, 19, 23, 24, 26, 12},
};
