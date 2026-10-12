#pragma once
#include "dayOfYear.h"
#include <string>
//lab6
// 2. 클래스1.h 혹은 클래스2.h: 지난 실습에서 만든 클래스에 다음을 추가 
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의합니다. 
// private
// -std::string형 멤버변수
// public
// -생성자 변경: std::string형 멤버변수를 초기화
// -print함수 변경: std::string형 멤버변수도 표준스트림으로 출력
// -input함수 추가: std::string형 멤버변수는 std::string의 getline함수와 입력조작기 std::ws를 사용
// -입력연산자 추가
// -출력연산자 추가
// -접근함수 추가: std::string형 멤버변수 접근함수 (get, set)

namespace KwonMinSung2693018
{
    class holiday
    {
        std::string name;
        dayOfYear date{};
        bool parkingEnforcement{};

    public:
        holiday(const std::string& n = "no name yet",
            dayOfYear d = dayOfYear{1,1}, bool p = false)
            : name{n}, date{ d }, parkingEnforcement{ p }
        {}
 
        void print() const 
        {
            std::cout << name << ": ";
            date.print(); //dayOfYear::print()
            if (parkingEnforcement)
                std::cout << "Parking laws will be enforced.\n";
            else
                std::cout << "Parking laws will Not be enforced\n";
        }

        friend std::ostream& operator<<(std::ostream& os, const holiday& h)
        {
            os << h.name << ":";
            os << h.date;
            if (h.parkingEnforcement)
                os << "Parking laws will be enforced.\n";
            else
                os << "Parking laws will Not be enforced\n";
            return os;
        }

         friend std::istream& operator>>(std::istream& is, holiday& h)
        {
            std::cout << "Enter holiday name: ";
            std::getline(is >> std::ws, h.name);
            is >> h.date;
            std::cout << "Enter parking law enforcement: 1(true) or 0(false)";
            is >> h.parkingEnforcement;
            
            return is;
        }


        void input()
        {
            std::cout << "Enter holiday name: ";
            std::getline(std::cin >> std::ws, name); //std::cin >> name;
            date.input(); //date.conth, date.day
            std::cout << "Enter parking law enforcement: 1(true) or 0(false)";
            std::cin >> parkingEnforcement;
        }

        const std::string& getName() const {return name;}
        void setName(const std::string& n) {name = n;}

        const dayOfYear& getDate() const {return date;}
        void setDate(const dayOfYear& d) {date = d;}

        void setParkingEnforcement(bool p) {parkingEnforcement = p;}
    
    };
}