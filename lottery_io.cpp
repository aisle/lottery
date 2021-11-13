#include "lottery_io.h"

#include <fstream>
#include <sstream>

static std::vector<std::string> SplitString(std::string s, const std::string& delimiter) {
    size_t pos = 0;
    std::string token;
    std::vector<std::string> ret;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        ret.push_back(token);
        s.erase(0, pos + delimiter.length());
    }

    if (!s.empty()) {
        ret.push_back(s);
    }

    return ret;
}

static std::vector<int> ConvertStringVector2IntVector(std::vector<std::string> svec) {
    std::vector<int> ivec;

    for (const std::string& s : svec) {
        int i = atoi(s.c_str());
        ivec.push_back(i);
    }

    return ivec;
}

std::vector<std::vector<int>> GetAllTickets(const std::string& filename) {
    std::ifstream infile(filename);
    std::vector<std::vector<int>> tickets;
    std::string line;

    while (std::getline(infile, line)) {
        std::vector<std::string> literalTicket = SplitString(line, "-");
        std::vector<int> digitalTicket = ConvertStringVector2IntVector(literalTicket);
        tickets.push_back(digitalTicket);
    }

    return tickets;
}
