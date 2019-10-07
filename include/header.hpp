// Copyright 2019 Sabitov Egor <q.st.stream@gmail.com>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <cstddef>
#include <memory>

template <typename T>
class Stack {
private:
    size_t num;
    size_t size;
    std::unique_ptr<T[]> data;

public:
    Stack() {
        num = 0;
        size = 1;
        data = std::make_unique<T[]>(size);
    }

    Stack(const Stack<T> &tmp) = delete;

    Stack(Stack<T> &&tmp) noexcept {
        data = std::move(tmp._data);
        tmp._data = nullptr;
        size = tmp.size;
        num = tmp.num;
    }

    ~Stack() {}

    void push(T &&value) {
        if (num == size) {
            num++;
            size = 3 * num / 2 + 1;
            auto buf = std::make_unique<T[]>(size);
            for (size_t i = 0; i < num; i++)
                buf[i] = data[i];
            buf[num - 1] = value;
            data = std::move(buf);
        } else {
            num++;
            data[num - 1] = value;
        }
    }

    void push(const T &value) {
        if (num == size) {
            num++;
            size = 3 * num / 2 + 1;
            auto buf = std::make_unique<T[]>(size);
            for (size_t i = 0; i < num; i++)
                buf[i] = data[i];
            buf[num] = value;
            data = std::move(buf);
        } else {
            num++;
            data[num] = value;
        }
    }

    void pop() {
        if (size != 0)
            num--;
        else
            throw std::logic_error("Out of range");
    }

    const T &head() const {
        return data[num - 1];
    }

    template<typename ... Args>
    void push_emplace(Args &&... value) {
        if (num == size) {
            num++;
            size = 3 * num / 2 + 1;
            auto buf = std::make_unique<T[]>(size);
            for (size_t i = 0; i < num; i++)
                buf[i] = data[i];
            buf[num - 1] = T(value ...);
            data = std::move(buf);
        } else {
            num++;
            data[num - 1] = T(value ...);
        }
    }

    T pop(int) {
        if (size != 0)
            num--;
        else
            throw std::logic_error("Out of range");
        return data[num];
    }
};
#endif // INCLUDE_HEADER_HPP_
