//
// Created by shiqi on 2019/3/24.
//

#ifndef GAS_ANNOTATION_REGISTER_H
#define GAS_ANNOTATION_REGISTER_H

#include <string>
#include <map>

class Register {
    std::map<std::string, int> m;

    void set_eax(int value) {
        m["eax"] = value;
    }

    int get_eax() {
        return m["eax"];
    }

    void set_ecx(int value) {
        m["ecx"] = value;
    }

    int get_ecx() {
        return m["ecx"];
    }

    void set_edx(int value) {
        m["edx"] = value;
    }

    int get_edx() {
        return m["ebx"];
    }

    void set_ebx(int value) {
        m["ebx"] = value;
    }

    int get_ebx() {
        return m["ebx"];
    }

    void set_esi(int value) {
        m["eax"] = value;
    }

    int get_esi() {
        return m["ebx"];
    }

    void set_edi(int value) {
        m["eax"] = value;
    }

    int get_edi() {
        return m["ebx"];
    }

    void set_esp(int value) {
        m["eax"] = value;
    }

    int get_esp() {
        return m["ebx"];
    }

    void set_ebp(int value) {
        m["eax"] = value;
    }

    int get_ebp() {
        return m["ebx"];
    }
};
#endif //GAS_ANNOTATION_REGISTER_H
