#ifndef GLASGOW_SUBGRAPH_SOLVER_GUARD_TIMEOUT_HH
#define GLASGOW_SUBGRAPH_SOLVER_GUARD_TIMEOUT_HH 1

#include <chrono>
#include <memory>
#include <atomic>

namespace gss
{
    class Timeout
    {
    private:
        struct Detail;
        std::unique_ptr<Detail> _detail;
        std::atomic<bool> &cancel;

    public:
        explicit Timeout(const std::chrono::seconds limit, std::atomic<bool> &cancel);
        ~Timeout();

        auto should_abort() const -> bool;
        auto aborted() const -> bool;
        auto stop() -> void;
        auto trigger_early_abort() -> void;
    };
}

#endif
