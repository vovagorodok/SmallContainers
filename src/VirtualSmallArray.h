#pragma once
#include "VirtualSmallArrayBase.h"
#include "AbstractArray.h"

template <typename T, size_t N>
class VirtualSmallArray : public VirtualSmallArrayBase<T, N>,
                          public AbstractArray<T>
{
public:
    using Base = AbstractArray<T>;
    using reference = typename Base::reference;
    using const_reference = typename Base::const_reference;
    using VirtualSmallArrayBase<T, N>::VirtualSmallArrayBase;

    const_reference operator[](size_t pos) const override
    {
        return this->array[pos];
    }
    reference operator[](size_t pos) override
    {
        return this->array[pos];
    }
    bool contains(const T& value) const override
    {
        for (size_t pos = 0; pos < this->size(); pos++)
            if (this->array[pos] == value)
                return true;
        return false;
    }
};