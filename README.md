# Small Containers

Represents `SmallArray` and `SmallMap` containers. \
Has zero memory overhead and the same size as c array. \
Can be constexpr constructed, converted and used. \
Can be stored on static mamory or stack.

Added additional `VirtualSmallArray/AbstractArray` and `VirtualSmallMap/AbstractMap` containers that can hide their sizes. \
Has memory overhead of poiner to virtual table.