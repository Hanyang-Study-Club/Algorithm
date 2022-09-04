#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// - 가 나오면 다음에 음수가 나오기 전 까지를 괄호친다..
// 55-50-40+100 이면 50 에서 - 만나서 50까지만 빼주고
// - (40 + 100)으로 100은 포함 하는 느낌으로다가..

void parse(vector<int>& numbers, vector<char>& operators)
{
    string expr;
    cin >> expr;

    string s_num;
    int ptr1 = 0, ptr2 = 0;
    for(; ptr2 < expr.size(); ptr2++)
    {
        if(expr[ptr2] == '+' || expr[ptr2] == '-')
        {
            s_num = expr.substr(ptr1, ptr2);
            numbers.push_back(stoi(s_num));
            operators.push_back(expr[ptr2]);
            ptr1 = ptr2 + 1;
        }
    }

    s_num = expr.substr(ptr1, expr.size() - ptr1);
    numbers.push_back(stoi(s_num));
}

int greedy(vector<int>& numbers, vector<char>& operators)
{
    int curr_num, result = numbers[0]; // 맨 앞 숫자100
    bool minus_flag = false;
    char curr_op;
    for(int idx = 1; idx < numbers.size(); idx++)
    {
        curr_num = numbers[idx];
        curr_op = operators[idx-1];

        if(curr_op == '-') // 음수면 그냥 빼주고
        {
            result -= curr_num;
            minus_flag = true;
        }
        else
        {
            if(minus_flag) result -= curr_num;
            else result += curr_num;
        }
    }

    return result;
}


int main() {
    vector<int> numbers; // max heap
    vector<char> operators;

    parse(numbers, operators);

    cout << greedy(numbers, operators);

    return 0;
}
