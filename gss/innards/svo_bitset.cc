#include <gss/innards/svo_bitset.hh>

#include <algorithm>

using namespace gss;
using namespace gss::innards;

using std::copy;

SVOBitset::SVOBitset(unsigned size, unsigned bits)
{
    n_words = (size + bits_per_word - 1) / (bits_per_word);
    if (n_words <= svo_size) {
        for (unsigned i = 0; i < svo_size; ++i)
            _data.short_data[i] = bits;
    }
    else {
        _data.long_data = new BitWord[size];
        for (unsigned i = 0; i < size; ++i)
            _data.long_data[i] = bits;
    }
}

#ifdef USE_PORTABLE_SNIPPETS_BUILTIN
#include <portable-snippets/builtin/builtin.h>
#endif

namespace gss::innards {
#ifdef USE_PORTABLE_SNIPPETS_BUILTIN
    int popcount(unsigned long long x)
    {
        return psnip_builtin_popcountll(x);
    }
    int countr_zero(unsigned long long x)
    {
        return psnip_builtin_ctzll(x);
    }
#endif
}
