/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Graphics/Color.cpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */
 
#include "PP/System/UI/PrecompiledHeader.hpp"
#include "PP/System/UI/Graphics/Color.hpp"

namespace PP
{
    namespace System
    {
        namespace UI
        {
            Color::Color()
                : m_red(255), m_green(255), m_blue(255), m_alpha(255)
            {
            }

            Color::Color(const Color& color)
                : m_red(255), m_green(255), m_blue(255), m_alpha(255)
            {
                *this = color;
            }

            Color::Color(int r, int g, int b)
                : m_red(r), m_green(g), m_blue(b), m_alpha(255)
            {
            }

            Color::Color(int r, int g, int b, int a)
                : m_red(r), m_green(g), m_blue(b), m_alpha(a)
            {
            }

            Color::~Color()
            {
            }

            Color& Color::operator =(const Color& color)
            {
                if (this != &color)
                {
                    m_red = color.m_red;
                    m_green = color.m_green;
                    m_blue = color.m_blue;
                    m_alpha = color.m_alpha;
                }
                return *this;
            }

            int Color::getRed() const
            {
                return m_red;
            }

            int Color::getGreen() const
            {
                return m_green;
            }

            int Color::getBlue() const
            {
                return m_blue;
            }

            int Color::getAlpha() const
            {
                return m_alpha;
            }

            Color Color::AliceBlue = Color(240, 248, 255, 255);
            Color Color::AntiqueWhite = Color(250, 235, 215, 255);
            Color Color::Cyan = Color(0, 255, 255, 255);
            Color Color::Aquamarine = Color(127, 255, 212, 255);
            Color Color::Azure = Color(240, 255, 255, 255);
            Color Color::Beige = Color(245, 245, 220, 255);
            Color Color::Bisque = Color(255, 228, 196, 255);
            Color Color::Black = Color(0, 0, 0, 255);
            Color Color::BlanchedAlmond = Color(255, 235, 205, 255);
            Color Color::Blue = Color(0, 0, 255, 255);
            Color Color::BlueViolet = Color(138, 43, 226, 255);
            Color Color::Brown = Color(165, 42, 42, 255);
            Color Color::BurlyWood = Color(222, 184, 135, 255);
            Color Color::CadetBlue = Color(95, 158, 160, 255);
            Color Color::Chartreuse = Color(127, 255, 0, 255);
            Color Color::Chocolate = Color(210, 105, 30, 255);
            Color Color::Coral = Color(255, 127, 80, 255);
            Color Color::CornflowerBlue = Color(100, 149, 237, 255);
            Color Color::Cornsilk = Color(255, 248, 220, 255);
            Color Color::Crimson = Color(220, 20, 60, 255);
            Color Color::DarkBlue = Color(0, 0, 139, 255);
            Color Color::DarkCyan = Color(0, 139, 139, 255);
            Color Color::DarkGoldenrod = Color(184, 134, 11, 255);
            Color Color::DarkGray = Color(169, 169, 169, 255);
            Color Color::DarkGreen = Color(0, 100, 0, 255);
            Color Color::DarkKhaki = Color(189, 183, 107, 255);
            Color Color::DarkMagenta = Color(139, 0, 139, 255);
            Color Color::DarkOliveGreen = Color(85, 107, 47, 255);
            Color Color::DarkOrange = Color(255, 140, 0, 255);
            Color Color::DarkOrchid = Color(153, 50, 204, 255);
            Color Color::DarkRed = Color(139, 0, 0, 255);
            Color Color::DarkSalmon = Color(233, 150, 122, 255);
            Color Color::DarkSeaGreen = Color(143, 188, 143, 255);
            Color Color::DarkSlateBlue = Color(72, 61, 139, 255);
            Color Color::DarkSlateGray = Color(47, 79, 79, 255);
            Color Color::DarkTurquoise = Color(0, 206, 209, 255);
            Color Color::DarkViolet = Color(148, 0, 211, 255);
            Color Color::DeepPink = Color(255, 20, 147, 255);
            Color Color::DeepSkyBlue = Color(0, 191, 255, 255);
            Color Color::DimGray = Color(105, 105, 105, 255);
            Color Color::DodgerBlue = Color(30, 144, 255, 255);
            Color Color::Firebrick = Color(178, 34, 34, 255);
            Color Color::FloralWhite = Color(255, 250, 240, 255);
            Color Color::ForestGreen = Color(34, 139, 34, 255);
            Color Color::Magenta = Color(255, 0, 255, 255);
            Color Color::Gainsboro = Color(220, 220, 220, 255);
            Color Color::GhostWhite = Color(248, 248, 255, 255);
            Color Color::Gold = Color(255, 215, 0, 255);
            Color Color::Goldenrod = Color(218, 165, 32, 255);
            Color Color::Gray = Color(128, 128, 128, 255);
            Color Color::Green = Color(0, 128, 0, 255);
            Color Color::GreenYellow = Color(173, 255, 47, 255);
            Color Color::Honeydew = Color(240, 255, 240, 255);
            Color Color::HotPink = Color(255, 105, 180, 255);
            Color Color::IndianRed = Color(205, 92, 92, 255);
            Color Color::Indigo = Color(75, 0, 130, 255);
            Color Color::Ivory = Color(255, 255, 240, 255);
            Color Color::Khaki = Color(240, 230, 140, 255);
            Color Color::Lavender = Color(230, 230, 250, 255);
            Color Color::LavenderBlush = Color(255, 240, 245, 255);
            Color Color::LawnGreen = Color(124, 252, 0, 255);
            Color Color::LemonChiffon = Color(255, 250, 205, 255);
            Color Color::LightBlue = Color(173, 216, 230, 255);
            Color Color::LightCoral = Color(240, 128, 128, 255);
            Color Color::LightCyan = Color(224, 255, 255, 255);
            Color Color::LightGoldenrodYellow = Color(250, 250, 210, 255);
            Color Color::LightGray = Color(211, 211, 211, 255);
            Color Color::LightGreen = Color(144, 238, 144, 255);
            Color Color::LightPink = Color(255, 182, 193, 255);
            Color Color::LightSalmon = Color(255, 160, 122, 255);
            Color Color::LightSeaGreen = Color(32, 178, 170, 255);
            Color Color::LightSkyBlue = Color(135, 206, 250, 255);
            Color Color::LightSlateGray = Color(119, 136, 153, 255);
            Color Color::LightSteelBlue = Color(176, 196, 222, 255);
            Color Color::LightYellow = Color(255, 255, 224, 255);
            Color Color::Lime = Color(0, 255, 0, 255);
            Color Color::LimeGreen = Color(50, 205, 50, 255);
            Color Color::Linen = Color(250, 240, 230, 255);
            Color Color::Maroon = Color(128, 0, 0, 255);
            Color Color::MediumAquamarine = Color(102, 205, 170, 255);
            Color Color::MediumBlue = Color(0, 0, 205, 255);
            Color Color::MediumOrchid = Color(186, 85, 211, 255);
            Color Color::MediumPurple = Color(147, 112, 219, 255);
            Color Color::MediumSeaGreen = Color(60, 179, 113, 255);
            Color Color::MediumSlateBlue = Color(123, 104, 238, 255);
            Color Color::MediumSpringGreen = Color(0, 250, 154, 255);
            Color Color::MediumTurquoise = Color(72, 209, 204, 255);
            Color Color::MediumVioletRed = Color(199, 21, 133, 255);
            Color Color::MidnightBlue = Color(25, 25, 112, 255);
            Color Color::MintCream = Color(245, 255, 250, 255);
            Color Color::MistyRose = Color(255, 228, 225, 255);
            Color Color::Moccasin = Color(255, 228, 181, 255);
            Color Color::NavajoWhite = Color(255, 222, 173, 255);
            Color Color::Navy = Color(0, 0, 128, 255);
            Color Color::OldLace = Color(253, 245, 230, 255);
            Color Color::Olive = Color(128, 128, 0, 255);
            Color Color::OliveDrab = Color(107, 142, 35, 255);
            Color Color::Orange = Color(255, 165, 0, 255);
            Color Color::OrangeRed = Color(255, 69, 0, 255);
            Color Color::Orchid = Color(218, 112, 214, 255);
            Color Color::PaleGoldenrod = Color(238, 232, 170, 255);
            Color Color::PaleGreen = Color(152, 251, 152, 255);
            Color Color::PaleTurquoise = Color(175, 238, 238, 255);
            Color Color::PaleVioletRed = Color(219, 112, 147, 255);
            Color Color::PapayaWhip = Color(255, 239, 213, 255);
            Color Color::PeachPuff = Color(255, 218, 185, 255);
            Color Color::Peru = Color(205, 133, 63, 255);
            Color Color::Pink = Color(255, 192, 203, 255);
            Color Color::Plum = Color(221, 160, 221, 255);
            Color Color::PowderBlue = Color(176, 224, 230, 255);
            Color Color::Purple = Color(128, 0, 128, 255);
            Color Color::Red = Color(255, 0, 0, 255);
            Color Color::RosyBrown = Color(188, 143, 143, 255);
            Color Color::RoyalBlue = Color(65, 105, 225, 255);
            Color Color::SaddleBrown = Color(139, 69, 19, 255);
            Color Color::Salmon = Color(250, 128, 114, 255);
            Color Color::SandyBrown = Color(244, 164, 96, 255);
            Color Color::SeaGreen = Color(46, 139, 87, 255);
            Color Color::SeaShell = Color(255, 245, 238, 255);
            Color Color::Sienna = Color(160, 82, 45, 255);
            Color Color::Silver = Color(192, 192, 192, 255);
            Color Color::SkyBlue = Color(135, 206, 235, 255);
            Color Color::SlateBlue = Color(106, 90, 205, 255);
            Color Color::SlateGray = Color(112, 128, 144, 255);
            Color Color::Snow = Color(255, 250, 250, 255);
            Color Color::SpringGreen = Color(0, 255, 127, 255);
            Color Color::SteelBlue = Color(70, 130, 180, 255);
            Color Color::Tan = Color(210, 180, 140, 255);
            Color Color::Teal = Color(0, 128, 128, 255);
            Color Color::Thistle = Color(216, 191, 216, 255);
            Color Color::Tomato = Color(255, 99, 71, 255);
            Color Color::Turquoise = Color(64, 224, 208, 255);
            Color Color::Violet = Color(238, 130, 238, 255);
            Color Color::Wheat = Color(245, 222, 179, 255);
            Color Color::White = Color(255, 255, 255, 255);
            Color Color::WhiteSmoke = Color(245, 245, 245, 255);
            Color Color::Yellow = Color(255, 255, 0, 255);
            Color Color::YellowGreen = Color(154, 205, 50, 255);
        }
    }
}
