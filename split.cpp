#include <iostream>
#include <vector>
#include <string>

// 문자열을 괄호를 기준으로 분리하여 벡터로 반환하는 함수
std::vector<std::string> splitStringByParentheses(const std::string& str) {
    std::vector<std::string> result;
    std::string temp;

    for (char ch : str) {
        if (ch == '(' || ch == ')') {
            if (!temp.empty()) {
                result.push_back(temp); // 괄호를 만나면 지금까지의 문자열을 벡터에 추가
                temp.clear();
            }
        } else {
            temp += ch; // 괄호가 아닌 문자는 임시 문자열에 추가
        }
    }

    if (!temp.empty()) {
        result.push_back(temp); // 마지막 남은 문자열 추가
    }

    return result;
}

int main() {
    std::string str = "ac(12)bf";

    // 함수 호출
    std::vector<std::string> result = splitStringByParentheses(str);

    // 결과 출력
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }

    return 0;
}