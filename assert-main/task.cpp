#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>

int findPersonWithBroom(int n, int time) {
    int person = 1;  // Начинаем с первого человека
    bool moveForward = true;  // Направление движения швабры
    
    while (time > 0) {
        if (moveForward) {
            person++;
            if (person >= n) {
                person = n;
                moveForward = false;
            }
        } else {
            person--;
            if (person <= 1) {
                person = 1;
                moveForward = true;
            }
        }
        time--;
    }
    
    return person;
}

//2
bool canReachTarget(int sx, int sy, int fx, int fy, unsigned int t) {
    int distance = abs(fx - sx) + abs(fy - sy); // Расстояние между начальной и конечной точкой

    if (t >= distance && (t - distance) % 2 == 0) {
        return true; // Если оставшееся количество ходов четное и достаточно для достижения цели, то цель достижима
    }
    
    while(t>0){
        if (t > 0 && sx < fx && sy < fy) {
            sx++;
            sy++;
            t--;
        }
        else if (sx < fx) {
            sx++;
            t--;
        }
        else if (sy < fy) {
            sy++;
            t--;
        }
        else if (sx == fx && sy == fy && t>1)
            return true;
        else 
            return false;
        if (sx == fx && sy == fy && t==0) {
            return true; // Если достигли конечной точки, то цель достижима
        }
        
    }
    return false; // В остальных случаях цель недостижима
}

//3
std::string solveEquation(const std::string &equation) {
    int lhs_coefficient = 0, lhs_constant = 0;  // хранение костант и коэффециентов при x в левой части
    int rhs_coefficient = 0, rhs_constant = 0;  // хранение костант и коэффециентов при x в правой части
    bool is_rhs = false;

    std::istringstream ss(equation);
    std::string part;
    
    // Split equation into left and right parts
    while (std::getline(ss, part, '=')) {
        std::istringstream part_stream(part);
        int coefficient = 0, constant = 0;
        char op = '+';
        while (part_stream) {
            int num = 0;
            char ch = part_stream.peek();
            if (ch == '+' || ch == '-') {
                part_stream >> op;
            } else if (isdigit(ch)) {
                part_stream >> num;
                if (part_stream.peek() == 'x') {
                    part_stream >> ch; // consume 'x'
                    if (op == '-') num = -num;
                    coefficient += num;
                } else {
                    if (op == '-') num = -num;
                    constant += num;
                }
            } else if (ch == 'x') {
                part_stream >> ch; // consume 'x'
                num = 1;
                if (op == '-') num = -num;
                coefficient += num;
            } else {
                break;
            }
        }

        if (!is_rhs) {
            lhs_coefficient += coefficient;
            lhs_constant += constant;
        } else {
            rhs_coefficient += coefficient;
            rhs_constant += constant;
        }
        
        is_rhs = true;
    }

    // Combine both sides into a single equation of form ax + b = 0
    int total_coefficient = lhs_coefficient - rhs_coefficient;
    int total_constant = rhs_constant - lhs_constant;

    if (total_coefficient == 0) {
        if (total_constant == 0) return "Infinite";
        else return "NO";
    }

    int result = total_constant / total_coefficient;
    if (total_constant % total_coefficient != 0) return "NO"; // Check for non-integer solution
    return "x=" + std::to_string(result);
}


//4
int timeToMinutes(const std::string& time) {
    int hours, minutes;
    char colon;
    std::istringstream ss(time);
    ss >> hours >> colon >> minutes;
    return hours * 60 + minutes;
}

int findMinTimeDiff(const std::vector<std::string>& times) {
    std::vector<int> minutes;
    for (const auto& time : times) {
        minutes.push_back(timeToMinutes(time));
    }
    
    std::sort(minutes.begin(), minutes.end()); // Сортировка временных значений для удобства нахождения минимальной разницы
    
    int minDiff = minutes[0] + 1440 - minutes.back(); // Инициализация минимальной разницы разницей между первым и последним временем
    
    for (int i = 1; i < minutes.size(); i++) {
        int diff = minutes[i] - minutes[i-1]; // Вычисление разницы между текущим и предыдущим временем
        minDiff = std::min(minDiff, diff); // Обновление минимальной разницы
    }

    return minDiff;
}

//5
bool canReach(unsigned int fx, unsigned int fy) {
    // Пока не достигнута точка (1, 1)
    while (fx != 1 || fy != 1) {
        // Если fx или fy равны 0, то точка недостижима
        if (fx == 0 || fy == 0) {
            return false;
        }

        // Проверяем условия для обратных операций
        if (fx > fy) {
            // Если fx больше fy и fx делится на 2, то переходим к (fx/2, fy)
            if (fx % 2 == 0) {
                fx /= 2;
            } else {
                // Иначе, если fx больше fy и fx - fy больше 0, переходим к (fx - fy, fy)
                fx -= fy;
            }
        } else {
            // Если fy больше fx и fy делится на 2, переходим к (fx, fy/2)
            if (fy % 2 == 0) {
                fy /= 2;
            } else {
                // Иначе, если fy больше fx и fy - fx больше 0, переходим к (fx, fy - fx)
                fy -= fx;
            }
        }
    }

    // Достигли точки (1, 1)
    return true;
}

//6
int calculateExpression(const std::string& expression) {
    std::stack<int> operands;
    std::stack<char> operators;

    int num = 0;
    int result = 0;
    int sign = 1;

    for (char c : expression) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            operands.push(result);
            operators.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            result *= operators.top();
            result += operands.top();
            operands.pop();
            operators.pop();
            num = 0;
        }
    }

    return result + sign * num;
}