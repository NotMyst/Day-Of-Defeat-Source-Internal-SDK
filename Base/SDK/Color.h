#pragma once

class Color
{
public:
	std::uint8_t color[4];
	float fCol[4];
	int r, g, b, a;
	bool rainbow;

    Color(std::uint8_t R, std::uint8_t G, std::uint8_t B, std::uint8_t A) {
        color[0] = R;
        color[1] = G;
        color[2] = B;
        color[3] = A;
        r = R; g = G; b = B; a = A;
        fCol[0] = (float)R / 255.f; fCol[1] = (float)G / 255.f; fCol[2] = (float)B / 255.f; fCol[3] = (float)A / 255.f;
        rainbow = false;
    }
};