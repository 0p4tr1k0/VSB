#include "lcd_lib.h"

// Simple graphic interface

struct Point2D
{
    int32_t x, y;
};


struct RGB
{
    uint8_t r, g, b;
};


class GraphElement
{
public:
    // foreground and background color
    RGB m_fg_color, m_bg_color;

    // constructor
    GraphElement( RGB t_fg_color, RGB t_bg_color ) :
        m_fg_color( t_fg_color ), m_bg_color( t_bg_color ) {}

    // ONLY ONE INTERFACE WITH LCD HARDWARE!!!
    void drawPixel( int32_t t_x, int32_t t_y ) { lcd_put_pixel( t_x, t_y, convert_RGB888_to_RGB565( m_fg_color ) ); }

    // Draw graphics element
    virtual void draw() = 0;

    // Hide graphics element
    virtual void hide() { swap_fg_bg_color(); draw(); swap_fg_bg_color(); }
private:
    // swap foreground and backgroud colors
    void swap_fg_bg_color() { RGB l_tmp = m_fg_color; m_fg_color = m_bg_color; m_bg_color = l_tmp; }

    // IMPLEMENT!!!
    // conversion of 24-bit RGB color into 16-bit color format
    uint16_t convert_RGB888_to_RGB565(RGB t_color) {
            uint16_t r = (t_color.r >> 3) & 0x1F; // 5 bits
            uint16_t g = (t_color.g >> 2) & 0x3F; // 6 bits
            uint16_t b = (t_color.b >> 3) & 0x1F; // 5 bits

            return (r << 11) | (g << 5) | b;
        }
};


class Pixel : public GraphElement
{
public:
    // constructor
    Pixel( Point2D t_pos, RGB t_fg_color, RGB t_bg_color ) : GraphElement( t_fg_color, t_bg_color ), m_pos( t_pos ) {}
    // Draw method implementation
    virtual void draw() { drawPixel( m_pos.x, m_pos.y ); }
    // Position of Pixel
    Point2D m_pos;
};


class Circle : public GraphElement {
public:
    // Center of circle
    Point2D m_center;
    // Radius of circle
    int32_t m_radius;

    Circle(Point2D t_center, int32_t t_radius, RGB t_fg, RGB t_bg) :
        GraphElement(t_fg, t_bg), m_center(t_center), m_radius(t_radius) {}

    void draw() override {
        int32_t x = 0;
        int32_t y = m_radius;
        int32_t d = 3 - 2 * m_radius;

        while (y >= x) {
            // Eight symmetrical points for the circle
            drawPixel(m_center.x + x, m_center.y + y);
            drawPixel(m_center.x - x, m_center.y + y);
            drawPixel(m_center.x + x, m_center.y - y);
            drawPixel(m_center.x - x, m_center.y - y);
            drawPixel(m_center.x + y, m_center.y + x);
            drawPixel(m_center.x - y, m_center.y + x);
            drawPixel(m_center.x + y, m_center.y - x);
            drawPixel(m_center.x - y, m_center.y - x);

            ++x;
            if (d > 0) {
                --y;
                d = d + 4 * (x - y) + 10;
            } else {
                d = d + 4 * x + 6;
            }
        }
    }

    void fill() {
        for (int32_t y = -m_radius; y <= m_radius; ++y) {
            for (int32_t x = -m_radius; x <= m_radius; ++x) {
                if (x * x + y * y <= m_radius * m_radius) {
                    // Fill with background color
                    drawPixel(m_center.x + x, m_center.y + y);
                }
            }
        }
    }
};


class Character : public GraphElement
{
public:
    // position of character
    Point2D m_pos;
    // character
    char m_character;
    int m_cislo;

    Character( Point2D t_pos, char t_char, RGB t_fg, RGB t_bg ) :
      GraphElement( t_fg, t_bg ), m_pos( t_pos ), m_character( t_char ) {};

    void draw() {
        // Získání indexu pro znak
        uint8_t index = m_character;


        for (int row = 0; row < 26; row++) {
            uint16_t row_data = font[index][row];

            // Každý bit v řádku představuje jeden pixel
            for (int col = 0; col < 16; col++) {
                // Pokud je bit v řádku nastavený (pixel je zapnutý), vykreslíme ho
                if (row_data & (1 << col)) {
                    // Vykreslíme pixel na pozici (x, y) s ohledem na výšku znaku (řádek)
                    drawPixel(m_pos.x + col , m_pos.y + row);
                }
            }
        }
    }
 // IMPLEMENT!!!
};


class Line : public GraphElement
{
public:
    // the first and the last point of line
    Point2D m_pos1, m_pos2;

    Line( Point2D t_pos1, Point2D t_pos2, RGB t_fg, RGB t_bg ) :
      GraphElement( t_fg, t_bg ), m_pos1( t_pos1 ), m_pos2( t_pos2 ) {}

    void draw() {
        int32_t dx = abs(m_pos2.x - m_pos1.x);
        int32_t dy = abs(m_pos2.y - m_pos1.y);
        int32_t sx = (m_pos1.x < m_pos2.x) ? 1 : -1;
        int32_t sy = (m_pos1.y < m_pos2.y) ? 1 : -1;
        int32_t err = dx - dy;

        while (true) {
            drawPixel(m_pos1.x, m_pos1.y);

            if (m_pos1.x == m_pos2.x && m_pos1.y == m_pos2.y) break;

            int32_t e2 = 2 * err;

            if (e2 > -dy) {
                err -= dy;
                m_pos1.x += sx;
            }
            if (e2 < dx) {
                err += dx;
                m_pos1.y += sy;
            }
        }
    }
 // IMPLEMENT!!!
};
