#ifndef __RECOMP_PORT__
#define __RECOMP_PORT__

#include <span>
#include <string_view>
#include <cstdint>

#ifdef _MSC_VER
inline uint32_t byteswap(uint32_t val) {
    return _byteswap_ulong(val);
}
#else
constexpr uint32_t byteswap(uint32_t val) {
    return __builtin_bswap32(val);
}
#endif

namespace RecompPort {

    struct Function {
        uint32_t vram;
        uint32_t rom;
        const std::span<const uint32_t> words;
        std::string name;
    };


    bool recompile_function(const Function& func, std::string_view output_path);
}

#endif
