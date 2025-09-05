#ifndef GLASGOW_SUBGRAPH_SOLVER_GUARD_SRC_LOOOONG_HH
#define GLASGOW_SUBGRAPH_SOLVER_GUARD_SRC_LOOOONG_HH 1

namespace gss
{

    typedef long long loooong;
    inline loooong gcd(loooong a, loooong b) {
        loooong t;
        while (b != 0) {
            t = a;
            a = b;
            b = t%b;
        }
        return a;
    }

}

#endif
