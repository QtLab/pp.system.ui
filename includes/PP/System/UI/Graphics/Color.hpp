/**
 * This file is part of Pixel Polishers' system library.
 * 
 * @author Walter Tamboer <wtamboer@pixelpolishers.com>
 * @file PP/System/UI/Color.hpp
 * @copyright Copyright (c) 2010-2014 Pixel Polishers. http://pixelpolishers.com/licenses
 */

#ifndef PP_SYSTEM_UI_COLOR_HPP
#define PP_SYSTEM_UI_COLOR_HPP

namespace PP
{
    namespace System
    {
        namespace UI
        {
            /**
             * The representation of a color.
             */
            class Color
            {
            public:
                /**
                 * Initializes a new instance of this class.
                 */
                Color();
                
                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] color The color to copy.
                 */
                Color(const Color& color);
                
                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] r The red component of the RGB value.
                 * @param[in] g The green component of the RGB value.
                 * @param[in] b The blue component of the RGB value.
                 */
                Color(int r, int g, int b);

                /**
                 * Initializes a new instance of this class.
                 *
                 * @param[in] r The red component of the RGB value.
                 * @param[in] g The green component of the RGB value.
                 * @param[in] b The blue component of the RGB value.
                 * @param[in] a The alpha component of the RGB value.
                 */
                Color(int r, int g, int b, int a);

                /**
                 * Cleans up all the resources used by this class.
                 */
                ~Color();

                /**
                 * Copies the given color to this color.
                 *
                 * @param[in] color The color to copy.
                 * @return Returns the updated instance of this class.
                 */
                Color& operator =(const Color& color);
                
                /**
                 * Gets the red component of the RGB value.
                 *
                 * @return Returns an integer between 0 and 255.
                 */
                int getRed() const;
                
                /**
                 * Gets the green component of the RGB value.
                 *
                 * @return Returns an integer between 0 and 255.
                 */
                int getGreen() const;
                
                /**
                 * Gets the blue component of the RGB value.
                 *
                 * @return Returns an integer between 0 and 255.
                 */
                int getBlue() const;
                
                /**
                 * Gets the alpha component of the RGB value.
                 *
                 * @return Returns an integer between 0 and 255.
                 */
                int getAlpha() const;

                /** The color AliceBlue with RGBA value "240, 248, 255, 255" */
                static Color AliceBlue;

                /** The color AntiqueWhite with RGBA value "250, 235, 215, 255" */
                static Color AntiqueWhite;

                /** The color Cyan with RGBA value "0, 255, 255, 255" */
                static Color Cyan;

                /** The color Aquamarine with RGBA value "127, 255, 212, 255" */
                static Color Aquamarine;

                /** The color Azure with RGBA value "240, 255, 255, 255" */
                static Color Azure;

                /** The color Beige with RGBA value "245, 245, 220, 255" */
                static Color Beige;

                /** The color Bisque with RGBA value "255, 228, 196, 255" */
                static Color Bisque;

                /** The color Black with RGBA value "0, 0, 0, 255" */
                static Color Black;

                /** The color BlanchedAlmond with RGBA value "255, 235, 205, 255" */
                static Color BlanchedAlmond;

                /** The color Blue with RGBA value "0, 0, 255, 255" */
                static Color Blue;

                /** The color BlueViolet with RGBA value "138, 43, 226, 255" */
                static Color BlueViolet;

                /** The color Brown with RGBA value "165, 42, 42, 255" */
                static Color Brown;

                /** The color BurlyWood with RGBA value "222, 184, 135, 255" */
                static Color BurlyWood;

                /** The color CadetBlue with RGBA value "95, 158, 160, 255" */
                static Color CadetBlue;

                /** The color Chartreuse with RGBA value "127, 255, 0, 255" */
                static Color Chartreuse;

                /** The color Chocolate with RGBA value "210, 105, 30, 255" */
                static Color Chocolate;

                /** The color Coral with RGBA value "255, 127, 80, 255" */
                static Color Coral;

                /** The color CornflowerBlue with RGBA value "100, 149, 237, 255" */
                static Color CornflowerBlue;

                /** The color Cornsilk with RGBA value "255, 248, 220, 255" */
                static Color Cornsilk;

                /** The color Crimson with RGBA value "220, 20, 60, 255" */
                static Color Crimson;

                /** The color DarkBlue with RGBA value "0, 0, 139, 255" */
                static Color DarkBlue;

                /** The color DarkCyan with RGBA value "0, 139, 139, 255" */
                static Color DarkCyan;

                /** The color DarkGoldenrod with RGBA value "184, 134, 11, 255" */
                static Color DarkGoldenrod;

                /** The color DarkGray with RGBA value "169, 169, 169, 255" */
                static Color DarkGray;

                /** The color DarkGreen with RGBA value "0, 100, 0, 255" */
                static Color DarkGreen;

                /** The color DarkKhaki with RGBA value "189, 183, 107, 255" */
                static Color DarkKhaki;

                /** The color DarkMagenta with RGBA value "139, 0, 139, 255" */
                static Color DarkMagenta;

                /** The color DarkOliveGreen with RGBA value "85, 107, 47, 255" */
                static Color DarkOliveGreen;

                /** The color DarkOrange with RGBA value "255, 140, 0, 255" */
                static Color DarkOrange;

                /** The color DarkOrchid with RGBA value "153, 50, 204, 255" */
                static Color DarkOrchid;

                /** The color DarkRed with RGBA value "139, 0, 0, 255" */
                static Color DarkRed;

                /** The color DarkSalmon with RGBA value "233, 150, 122, 255" */
                static Color DarkSalmon;

                /** The color DarkSeaGreen with RGBA value "143, 188, 143, 255" */
                static Color DarkSeaGreen;

                /** The color DarkSlateBlue with RGBA value "72, 61, 139, 255" */
                static Color DarkSlateBlue;

                /** The color DarkSlateGray with RGBA value "47, 79, 79, 255" */
                static Color DarkSlateGray;

                /** The color DarkTurquoise with RGBA value "0, 206, 209, 255" */
                static Color DarkTurquoise;

                /** The color DarkViolet with RGBA value "148, 0, 211, 255" */
                static Color DarkViolet;

                /** The color DeepPink with RGBA value "255, 20, 147, 255" */
                static Color DeepPink;

                /** The color DeepSkyBlue with RGBA value "0, 191, 255, 255" */
                static Color DeepSkyBlue;

                /** The color DimGray with RGBA value "105, 105, 105, 255" */
                static Color DimGray;

                /** The color DodgerBlue with RGBA value "30, 144, 255, 255" */
                static Color DodgerBlue;

                /** The color Firebrick with RGBA value "178, 34, 34, 255" */
                static Color Firebrick;

                /** The color FloralWhite with RGBA value "255, 250, 240, 255" */
                static Color FloralWhite;

                /** The color ForestGreen with RGBA value "34, 139, 34, 255" */
                static Color ForestGreen;

                /** The color Magenta with RGBA value "255, 0, 255, 255" */
                static Color Magenta;

                /** The color Gainsboro with RGBA value "220, 220, 220, 255" */
                static Color Gainsboro;

                /** The color GhostWhite with RGBA value "248, 248, 255, 255" */
                static Color GhostWhite;

                /** The color Gold with RGBA value "255, 215, 0, 255" */
                static Color Gold;

                /** The color Goldenrod with RGBA value "218, 165, 32, 255" */
                static Color Goldenrod;

                /** The color Gray with RGBA value "128, 128, 128, 255" */
                static Color Gray;

                /** The color Green with RGBA value "0, 128, 0, 255" */
                static Color Green;

                /** The color GreenYellow with RGBA value "173, 255, 47, 255" */
                static Color GreenYellow;

                /** The color Honeydew with RGBA value "240, 255, 240, 255" */
                static Color Honeydew;

                /** The color HotPink with RGBA value "255, 105, 180, 255" */
                static Color HotPink;

                /** The color IndianRed with RGBA value "205, 92, 92, 255" */
                static Color IndianRed;

                /** The color Indigo with RGBA value "75, 0, 130, 255" */
                static Color Indigo;

                /** The color Ivory with RGBA value "255, 255, 240, 255" */
                static Color Ivory;

                /** The color Khaki with RGBA value "240, 230, 140, 255" */
                static Color Khaki;

                /** The color Lavender with RGBA value "230, 230, 250, 255" */
                static Color Lavender;

                /** The color LavenderBlush with RGBA value "255, 240, 245, 255" */
                static Color LavenderBlush;

                /** The color LawnGreen with RGBA value "124, 252, 0, 255" */
                static Color LawnGreen;

                /** The color LemonChiffon with RGBA value "255, 250, 205, 255" */
                static Color LemonChiffon;

                /** The color LightBlue with RGBA value "173, 216, 230, 255" */
                static Color LightBlue;

                /** The color LightCoral with RGBA value "240, 128, 128, 255" */
                static Color LightCoral;

                /** The color LightCyan with RGBA value "224, 255, 255, 255" */
                static Color LightCyan;

                /** The color LightGoldenrodYellow with RGBA value "250, 250, 210, 255" */
                static Color LightGoldenrodYellow;

                /** The color LightGray with RGBA value "211, 211, 211, 255" */
                static Color LightGray;

                /** The color LightGreen with RGBA value "144, 238, 144, 255" */
                static Color LightGreen;

                /** The color LightPink with RGBA value "255, 182, 193, 255" */
                static Color LightPink;

                /** The color LightSalmon with RGBA value "255, 160, 122, 255" */
                static Color LightSalmon;

                /** The color LightSeaGreen with RGBA value "32, 178, 170, 255" */
                static Color LightSeaGreen;

                /** The color LightSkyBlue with RGBA value "135, 206, 250, 255" */
                static Color LightSkyBlue;

                /** The color LightSlateGray with RGBA value "119, 136, 153, 255" */
                static Color LightSlateGray;

                /** The color LightSteelBlue with RGBA value "176, 196, 222, 255" */
                static Color LightSteelBlue;

                /** The color LightYellow with RGBA value "255, 255, 224, 255" */
                static Color LightYellow;

                /** The color Lime with RGBA value "0, 255, 0, 255" */
                static Color Lime;

                /** The color LimeGreen with RGBA value "50, 205, 50, 255" */
                static Color LimeGreen;

                /** The color Linen with RGBA value "250, 240, 230, 255" */
                static Color Linen;

                /** The color Maroon with RGBA value "128, 0, 0, 255" */
                static Color Maroon;

                /** The color MediumAquamarine with RGBA value "102, 205, 170, 255" */
                static Color MediumAquamarine;

                /** The color MediumBlue with RGBA value "0, 0, 205, 255" */
                static Color MediumBlue;

                /** The color MediumOrchid with RGBA value "186, 85, 211, 255" */
                static Color MediumOrchid;

                /** The color MediumPurple with RGBA value "147, 112, 219, 255" */
                static Color MediumPurple;

                /** The color MediumSeaGreen with RGBA value "60, 179, 113, 255" */
                static Color MediumSeaGreen;

                /** The color MediumSlateBlue with RGBA value "123, 104, 238, 255" */
                static Color MediumSlateBlue;

                /** The color MediumSpringGreen with RGBA value "0, 250, 154, 255" */
                static Color MediumSpringGreen;

                /** The color MediumTurquoise with RGBA value "72, 209, 204, 255" */
                static Color MediumTurquoise;

                /** The color MediumVioletRed with RGBA value "199, 21, 133, 255" */
                static Color MediumVioletRed;

                /** The color MidnightBlue with RGBA value "25, 25, 112, 255" */
                static Color MidnightBlue;

                /** The color MintCream with RGBA value "245, 255, 250, 255" */
                static Color MintCream;

                /** The color MistyRose with RGBA value "255, 228, 225, 255" */
                static Color MistyRose;

                /** The color Moccasin with RGBA value "255, 228, 181, 255" */
                static Color Moccasin;

                /** The color NavajoWhite with RGBA value "255, 222, 173, 255" */
                static Color NavajoWhite;

                /** The color Navy with RGBA value "0, 0, 128, 255" */
                static Color Navy;

                /** The color OldLace with RGBA value "253, 245, 230, 255" */
                static Color OldLace;

                /** The color Olive with RGBA value "128, 128, 0, 255" */
                static Color Olive;

                /** The color OliveDrab with RGBA value "107, 142, 35, 255" */
                static Color OliveDrab;

                /** The color Orange with RGBA value "255, 165, 0, 255" */
                static Color Orange;

                /** The color OrangeRed with RGBA value "255, 69, 0, 255" */
                static Color OrangeRed;

                /** The color Orchid with RGBA value "218, 112, 214, 255" */
                static Color Orchid;

                /** The color PaleGoldenrod with RGBA value "238, 232, 170, 255" */
                static Color PaleGoldenrod;

                /** The color PaleGreen with RGBA value "152, 251, 152, 255" */
                static Color PaleGreen;

                /** The color PaleTurquoise with RGBA value "175, 238, 238, 255" */
                static Color PaleTurquoise;

                /** The color PaleVioletRed with RGBA value "219, 112, 147, 255" */
                static Color PaleVioletRed;

                /** The color PapayaWhip with RGBA value "255, 239, 213, 255" */
                static Color PapayaWhip;

                /** The color PeachPuff with RGBA value "255, 218, 185, 255" */
                static Color PeachPuff;

                /** The color Peru with RGBA value "205, 133, 63, 255" */
                static Color Peru;

                /** The color Pink with RGBA value "255, 192, 203, 255" */
                static Color Pink;

                /** The color Plum with RGBA value "221, 160, 221, 255" */
                static Color Plum;

                /** The color PowderBlue with RGBA value "176, 224, 230, 255" */
                static Color PowderBlue;

                /** The color Purple with RGBA value "128, 0, 128, 255" */
                static Color Purple;

                /** The color Red with RGBA value "255, 0, 0, 255" */
                static Color Red;

                /** The color RosyBrown with RGBA value "188, 143, 143, 255" */
                static Color RosyBrown;

                /** The color RoyalBlue with RGBA value "65, 105, 225, 255" */
                static Color RoyalBlue;

                /** The color SaddleBrown with RGBA value "139, 69, 19, 255" */
                static Color SaddleBrown;

                /** The color Salmon with RGBA value "250, 128, 114, 255" */
                static Color Salmon;

                /** The color SandyBrown with RGBA value "244, 164, 96, 255" */
                static Color SandyBrown;

                /** The color SeaGreen with RGBA value "46, 139, 87, 255" */
                static Color SeaGreen;

                /** The color SeaShell with RGBA value "255, 245, 238, 255" */
                static Color SeaShell;

                /** The color Sienna with RGBA value "160, 82, 45, 255" */
                static Color Sienna;

                /** The color Silver with RGBA value "192, 192, 192, 255" */
                static Color Silver;

                /** The color SkyBlue with RGBA value "135, 206, 235, 255" */
                static Color SkyBlue;

                /** The color SlateBlue with RGBA value "106, 90, 205, 255" */
                static Color SlateBlue;

                /** The color SlateGray with RGBA value "112, 128, 144, 255" */
                static Color SlateGray;

                /** The color Snow with RGBA value "255, 250, 250, 255" */
                static Color Snow;

                /** The color SpringGreen with RGBA value "0, 255, 127, 255" */
                static Color SpringGreen;

                /** The color SteelBlue with RGBA value "70, 130, 180, 255" */
                static Color SteelBlue;

                /** The color Tan with RGBA value "210, 180, 140, 255" */
                static Color Tan;

                /** The color Teal with RGBA value "0, 128, 128, 255" */
                static Color Teal;

                /** The color Thistle with RGBA value "216, 191, 216, 255" */
                static Color Thistle;

                /** The color Tomato with RGBA value "255, 99, 71, 255" */
                static Color Tomato;

                /** The color Turquoise with RGBA value "64, 224, 208, 255" */
                static Color Turquoise;

                /** The color Violet with RGBA value "238, 130, 238, 255" */
                static Color Violet;

                /** The color Wheat with RGBA value "245, 222, 179, 255" */
                static Color Wheat;

                /** The color White with RGBA value "255, 255, 255, 255" */
                static Color White;

                /** The color WhiteSmoke with RGBA value "245, 245, 245, 255" */
                static Color WhiteSmoke;

                /** The color Yellow with RGBA value "255, 255, 0, 255" */
                static Color Yellow;

                /** The color YellowGreen with RGBA value "154, 205, 50, 255" */
                static Color YellowGreen;

            private:
                /** The red component of the RGB value. */
                int m_red;
                
                /** The green component of the RGB value. */
                int m_green;
                
                /** The blue component of the RGB value. */
                int m_blue;
                
                /** The alpha component of the RGB value. */
                int m_alpha;
            };
        }
    }
}

#endif
