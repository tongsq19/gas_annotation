//
// Created by shiqi on 2019/3/24.
//

#ifndef GAS_ANNOTATION_DATATYPE_H
#define GAS_ANNOTATION_DATATYPE_H

#include <string>
#include "uility.h"

class dataType {
public:
    virtual void setOperand(const std::string& operand) = 0;
    virtual std::string toString() = 0;
};

class Immediate : public dataType {
//        "$";
public:
    void setOperand(const std::string& operand) override {
        this->operand = operand;
    }

    std::string toString() override {
        std::string result = "立即数 ";
        result.append(operand);
        return result;
    }
private:
    std::string operand;
};

class Memory : public dataType {
public:
    void setOperand(const std::string& operand) override {
        this->operand = operand;
    }

    std::string toString() override {
        std::string result = "存储器";
        if (operand[0] == '0') {
            result.append("地址 ");
            result.append(operand);
            return result;
        }

        result.append("寻址 ");

        size_t pos1 = operand.find('(');

        if(pos1 == std::string::npos) {
            result.append(operand);
        } else {
            size_t pos2 = operand.find(')');
            std::string sub = operand.substr(pos1, pos2-pos1);

            auto vec = split(sub, ',');

            if(vec.size() == 3){
                vec[2] = vec[1].append("*").append(vec[2]);
                vec.pop_back();
            }

            if(pos1 != 0) {
                vec.push_back(operand.substr(0, pos1));
            }

            result.append(join(vec, " + "));
            result.append(")");
        }

        return result;
    }

private:
    std::string operand;
};

class Register : public dataType {
public:
    void setOperand(const std::string& operand) override {
        this->operand = operand;
    }

    std::string toString() override {
        std::string result =  "寄存器 ";
        result.append(operand);
        return result;
    }

private:
    std::string operand;
};

#endif //GAS_ANNOTATION_DATATYPE_H
