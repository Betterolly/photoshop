#pragma once
#include <cstdint>
namespace betterolly::photo {
struct Rgba8 { std::uint8_t r,g,b,a; };
struct ImageView { Rgba8* pixels; std::uint32_t width,height,stride; };
void grayscale(ImageView image);
void invert(ImageView image);
void brightness(ImageView image, int amount);
}
