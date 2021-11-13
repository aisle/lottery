#include "lottery.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include "lottery_io.h"

const std::vector<std::vector<int>> kAwardLevelRule = {
    {0, 0, 0, 0, 5, 4, 2},
    {6, 6, 6, 5, 4, 3, 1},
};

static void DisplayVector(const std::vector<int>& ivec) {
    for (int i : ivec) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

// NOTE: the parameters must not reference.
static bool IsValidTicket(std::vector<int> ticket) {
    // 位数有效
    if (ticket.size() != 7) return false;
    // 蓝球有效
    if (ticket[6] < 1 || ticket[6] > 16) return false;
    // 红球有效
    ticket.resize(6);
    std::sort(ticket.begin(), ticket.end());
    for (int i = 1; i < 6; i++) {
        if (ticket[i-1] == ticket[i]) {
            return false;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (ticket[i] < 1 || ticket[i] > 33) {
            return false;
        }
    }
    return true;
}

static int VerifyOneTicket(const std::vector<int>& target,
                           const std::vector<int>& ticket) {
    if (!IsValidTicket(target) || !IsValidTicket(ticket)) {
        return -1;
    }
    // 红球
    int red = 0, blue = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (target[i] == ticket[j]) {
                red++;
                break;
            }
        }
    }
    // 蓝球
    if (target[6] == ticket[6]) {
        blue = 1;
    }
    // 中奖级别
    return kAwardLevelRule[blue][red];
}

void VerifyTickets(const std::vector<int>& target) {
    const auto& tickets = GetAllTickets("tickets.txt");
    if (tickets.empty()) {
        std::cout << "请录入购买彩票信息" << std::endl;
        return;
    }

    // 输出基本信息
    std::cout << "已购彩票" << tickets.size() << "张:" << std::endl;
    for (const auto& ivec : tickets) {
        DisplayVector(ivec);
    }
    std::cout << "中奖号码: ";
    DisplayVector(target);

    std::cout << "=============================================================" << std::endl;

    // 验证中奖结果
    for (const auto& ticket : tickets) {
        int ret = VerifyOneTicket(target, ticket);
        if (ret > 0) {
            std::cout << std::endl;
            std::cout << "恭喜你中了 " << ret << " 等奖！，中奖号码是：" << std::endl;
            DisplayVector(ticket);
            std::cout << std::endl;
        } else if (ret == 0) {
            std::cout << "为福利事业做贡献了!" << std::endl;
        } else {
            std::cout << "彩票输入有误，请重试!" << std::endl;
        }
    }
}
