#include "betterolly_photo_engine.h"
#include <algorithm>
namespace betterolly::photo {
void grayscale(ImageView image){for(std::uint32_t y=0;y<image.height;++y){auto* row=reinterpret_cast<Rgba8*>(reinterpret_cast<std::uint8_t*>(image.pixels)+y*image.stride);for(std::uint32_t x=0;x<image.width;++x){auto&p=row[x];auto v=static_cast<std::uint8_t>(0.2126f*p.r+0.7152f*p.g+0.0722f*p.b);p.r=p.g=p.b=v;}}}
void invert(ImageView image){for(std::uint32_t y=0;y<image.height;++y){auto* row=reinterpret_cast<Rgba8*>(reinterpret_cast<std::uint8_t*>(image.pixels)+y*image.stride);for(std::uint32_t x=0;x<image.width;++x){auto&p=row[x];p.r=255-p.r;p.g=255-p.g;p.b=255-p.b;}}}
void brightness(ImageView image,int amount){for(std::uint32_t y=0;y<image.height;++y){auto* row=reinterpret_cast<Rgba8*>(reinterpret_cast<std::uint8_t*>(image.pixels)+y*image.stride);for(std::uint32_t x=0;x<image.width;++x){auto&p=row[x];p.r=static_cast<std::uint8_t>(std::clamp(int(p.r)+amount,0,255));p.g=static_cast<std::uint8_t>(std::clamp(int(p.g)+amount,0,255));p.b=static_cast<std::uint8_t>(std::clamp(int(p.b)+amount,0,255));}}}
}
