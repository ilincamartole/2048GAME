#pragma once

#include "Block.h"

template <typename T>
bool poateFiCombinat(const Block<T>& a, const Block<T>& b)
{
    return !a.esteGol() && !b.esteGol() && a.getValoare() == b.getValoare();
}
