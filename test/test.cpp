//
// Created by shiqi on 2019/3/23.
//

#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "../src/dataType.h"
#include "../src/uility.h"


namespace apple{
    void printResiter(std::ostream &out) {
        out << "caller:\t| eax |" << std::endl;
        out << "\t\t| ecx |" << std::endl;
        out << "\t\t| edx |" << std::endl;
        out << "callee:\t| ebx |" << std::endl;
        out << "\t\t| esi |" << std::endl;
        out << "\t\t| edi |" << std::endl;
        out << "\t\t| esp |" << std::endl;
        out << "\t\t| ebp |" << std::endl;
    }


    std::string parseMOVL(const std::string &source, const std::string &destination) {
        std::string result = "传送双字节，";

        dataType *src, *des;
        if(source[0] == '%') {
            src = new Register();
            result.append("从");
        } else if(source[0] == '$'){
            src = new Immediate();
        } else {
            src = new Memory();
            result.append("从");
        }

        if(destination[0] == '%') {
            des = new Register();
        } else if(source[0] == '$'){
            src = new Immediate();
        } else {
            src = new Memory();
        }


        src->setOperand(source);
        des->setOperand(destination);
        result.append(src->toString());
        result.append(" 到");
        result.append(des->toString());
        return result;
    }

    std::string parse(std::ostream &out, const std::string& input) {
        size_t pos = input.find("movl");
        if(pos != std::string::npos) {
            size_t last = input.find_last_of(',');
            std::string src = trim(input.substr(pos+4, last-pos-4));
            std::string des = trim(input.substr(last+1));
            return parseMOVL(src, des);
        }
        return "";
    }
}



TEST(first, test1) {
    apple::printResiter(std::cout);

    auto actual = apple::parse(std::cout, "movl %ebp, %esp");
    std::string expected = "传送双字节，从寄存器 %ebp 到寄存器 %esp";

    EXPECT_EQ(actual, expected);
}

TEST(first, test2) {

    auto actual = apple::parse(std::cout, "\tmovl\t%ebp, %esp");
    std::string expected = "传送双字节，从寄存器 %ebp 到寄存器 %esp";

    EXPECT_EQ(actual, expected);
}

TEST(first, test3) {
    auto actual = apple::parse(std::cout, "movl $0x4050, %eax");
    std::string expected = "传送双字节，立即数 $0x4050 到寄存器 %eax";

    EXPECT_EQ(actual, expected);
}

TEST(first, test4) {
    auto actual = apple::parse(std::cout, "movl 0x104, %eax");
    std::string expected = "传送双字节，从存储器地址 0x104 到寄存器 %eax";

    EXPECT_EQ(actual, expected);
}

TEST(first, test5) {
    auto actual = apple::parse(std::cout, "movl (%ecx), %eax");
    std::string expected = "传送双字节，从存储器寻址 (%ecx) 到寄存器 %eax";

    EXPECT_EQ(actual, expected);
}

TEST(first, test6) {
    auto actual = apple::parse(std::cout, "movl 4(%ecx), %eax");
    std::string expected = "传送双字节，从存储器寻址 (%ecx + 4) 到寄存器 %eax";

    EXPECT_EQ(actual, expected);
}

TEST(first, test7) {
    auto actual = apple::parse(std::cout, "movl 4(%ecx, %edx), %eax");
    std::string expected = "传送双字节，从存储器寻址 (%ecx + %edx + 4) 到寄存器 %eax";

    EXPECT_EQ(actual, expected);
}

TEST(first, test8) {
    auto actual = apple::parse(std::cout, "movl 4(%ecx, %edx, 8), %eax");
    std::string expected = "传送双字节，从存储器寻址 (%ecx + %edx*8 + 4) 到寄存器 %eax";

    EXPECT_EQ(actual, expected);
}


