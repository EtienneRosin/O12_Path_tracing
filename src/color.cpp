#include "color.hpp"

Color Color::as_bytes() const
{
    return Color(
        static_cast<int>(std::clamp(r() * 255.0, 0.0, 255.0)),
        static_cast<int>(std::clamp(g() * 255.0, 0.0, 255.0)),
        static_cast<int>(std::clamp(b() * 255.0, 0.0, 255.0)));
};
