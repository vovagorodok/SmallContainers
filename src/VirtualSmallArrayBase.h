#pragma once
#include "AbstractArrayBase.h"
#include <initializer_list>

template <typename T, size_t N>
class VirtualSmallArrayBase : virtual public AbstractArrayBase<T>
{
public:
    using Base = AbstractArrayBase<T>;
    using iterator = typename Base::iterator;
    using const_iterator = typename Base::const_iterator;

    constexpr VirtualSmallArrayBase() = default;
    constexpr VirtualSmallArrayBase(const VirtualSmallArrayBase& other) = default;
    constexpr VirtualSmallArrayBase(VirtualSmallArrayBase&& other) = default;
    constexpr VirtualSmallArrayBase(T&& arg) :
        array{arg}
    {}
    template<typename... Types>
    constexpr VirtualSmallArrayBase(T&& arg0, T&& arg1, Types&&... args) :
        array{arg0, arg1, args...}
    {}
    template<typename Converter, typename OtherT, typename... OtherTypes>
    constexpr VirtualSmallArrayBase(Converter&& converter, OtherT&& arg, OtherTypes&&... args) :
        array{converter(arg), converter(args)...}
    {}
    inline VirtualSmallArrayBase(std::initializer_list<T> list) :
        array{}
    {
        size_t pos = 0;
        for (const T& el: list)
        {
            array[pos] = el;
            pos++;
        }
    }
    template<typename Converter, typename OtherT>
    inline VirtualSmallArrayBase(Converter&& converter, std::initializer_list<OtherT> list) :
        array{}
    {
        size_t pos = 0;
        for (const OtherT& el: list)
        {
            array[pos] = converter(el);
            pos++;
        }
    }
    inline VirtualSmallArrayBase& operator=(const VirtualSmallArrayBase& other) = default;
    inline VirtualSmallArrayBase& operator=(VirtualSmallArrayBase&& other) = default;

    const_iterator cbegin() const override
    {
        return array;
    }
    const_iterator begin() const override
    {
        return array;
    }
    iterator begin() override
    {
        return array;
    }
    const_iterator cend() const override
    {
        return array + N;
    }
    const_iterator end() const override
    {
        return array + N;
    }
    iterator end() override
    {
        return array + N;
    }
    size_t size() const override
    {
        return N;
    }

protected:
    T array[N];
};