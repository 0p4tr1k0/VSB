// **************************************************************************
//
//               Demo program for APPS labs
//
// Subject:      Computer Architectures and Parallel systems
// Author:       Petr Olivka, petr.olivka@vsb.cz, 02/2025
// Organization: Department of Computer Science, FEECS,
//               VSB-Technical University of Ostrava, CZ
//
// File:         Main program for LCD module
//
// **************************************************************************

/**
 * @file    main-lcd.cpp
 * @brief   Application entry point.
 */

#include <stdio.h>
#include <functional>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#define LCD_WIDTH 480
#define LCD_HEIGHT 320

/* TODO: insert other include files here. */
#include "font16x26_lsb.h"
#include "graph_class.hpp"

#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_mrt.h"
#include "fsl_lpspi.h"

#include "mcxn-kit.h"
#include "lcd_lib.h"
#include "cts_lib.h"

// **************************************************************************
//! System initialization. Do not modify it!!!
void _mcu_initialization() __attribute__(( constructor( 0x100 ) ));

void _mcu_initialization()
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();
    CLOCK_EnableClock( kCLOCK_Gpio0 );
    CLOCK_EnableClock( kCLOCK_Gpio1 );
    CLOCK_EnableClock( kCLOCK_Gpio2 );
    CLOCK_EnableClock( kCLOCK_Gpio3 );
    CLOCK_EnableClock( kCLOCK_Gpio4 );
}
// **************************************************************************

//! Global data

//! LEDs on MCXN-KIT - instances of class DigitalOut
DigitalOut g_led_P3_16( P3_16 );
DigitalOut g_led_P3_17( P3_17 );

//! Button on MCXN-KIT - instance of class DigitalIn
DigitalIn g_but_P3_18( P3_18 );
DigitalIn g_but_P3_19( P3_19 );
DigitalIn g_but_P3_20( P3_20 );
DigitalIn g_but_P3_21( P3_21 );

RGB green = {0, 255, 0};
RGB red = {255, 0, 0};
RGB blue = {0, 0, 255};
RGB white = {255, 255, 255};
RGB background = {0, 0, 0};

enum COLOR {RED, GREEN, BLUE, WHITE};
COLOR active_color = RED;

RGB vrat_barvu(COLOR active_color){
	switch(active_color){
	case RED:
		return {255, 0, 0};
		break;
	case GREEN:
		return {0, 255, 0};
		break;
	case BLUE:
		return {0, 0, 255};
		break;
	case WHITE:
		return {255, 255, 255};
		break;
	}
	return {0, 0, 0};
}

void drawTriangle(Point2D center, int sideLength, RGB fgColor, RGB bgColor){
	Point2D p1 = {center.x, center.y - (sideLength / 2)};
	Point2D p2 = {center.x - (sideLength / 2), center.y + (sideLength / 2)};
	Point2D p3 = {center.x + (sideLength / 2), center.y + (sideLength / 2)};

	Line line1(p1, p2, fgColor, bgColor);
	Line line2(p2, p3, fgColor, bgColor);
	Line line3(p3, p1, fgColor, bgColor);

	line1.draw();
	line2.draw();
	line3.draw();
}

void selectedColor(Point2D pozice, RGB color){
	int radius = 20;

	Circle pismeno_circle(pozice, radius, color, background);

	pismeno_circle.draw();
}

void vystrel(RGB color){
	int radius = 5;

	int x = 240;

	int y = 200;

	Circle koule(Point2D{x,y}, radius, color, background);

	koule.draw();

	koule.fill();
}

void scroll(RGB color){
	Line scrollbar_leftline(Point2D{240, 265}, Point2D{240, 300}, color, background);
	scrollbar_leftline.draw();

	Line scrollbar_rightline(Point2D{290, 265}, Point2D{290, 300}, color, background);
	scrollbar_rightline.draw();

	Line scrollbar_upline(Point2D{240, 265}, Point2D{290, 265}, color, background);
	scrollbar_upline.draw();

	Line scrollbar_downline(Point2D{240, 300}, Point2D{290, 300}, color, background);
	scrollbar_downline.draw();
}


int main()
{
	PRINTF( "LCD demo program started...\r\n" );

	lcd_init();
	if ( cts_init() < 0 )
	{
		PRINTF( "Touch Screen not detected!\r\n" );
	}

	Point2D pozice_R = {57, 23};
	Character pismeno_R(Point2D{50, 10}, 'R', red, background);
	pismeno_R.draw();

	Point2D pozice_G = {107, 23};
	Character pismeno_G(Point2D{100, 10}, 'G', green, background);
	pismeno_G.draw();

	Point2D pozice_B = {157, 23};
	Character pismeno_B(Point2D{150, 10}, 'B', blue, background);
	pismeno_B.draw();

	Point2D pozice_W = {207, 23};
	Character pismeno_W(Point2D{200, 10}, 'W', white, background);
	pismeno_W.draw();

	Character pismeno_S(Point2D{300, 10}, 'S', white, background);
	pismeno_S.draw();

	Character pismeno_C(Point2D{320, 10}, 'C', white, background);
	pismeno_C.draw();

	Character pismeno_O(Point2D{340, 10}, 'O', white, background);
	pismeno_O.draw();

	Character pismeno_R2(Point2D{360, 10}, 'R', white, background);
	pismeno_R2.draw();

	Character pismeno_E(Point2D{380, 10}, 'E', white, background);
	pismeno_E.draw();

	Character cislo(Point2D{420, 10}, '0', white, background);

	Character pismeno_F(Point2D{50, 270}, 'F', white, background);
	pismeno_F.draw();

	Character pismeno_I(Point2D{70, 270}, 'I', white, background);
	pismeno_I.draw();

	Character pismeno_R3(Point2D{90, 270}, 'R', white, background);
	pismeno_R3.draw();

	Character pismeno_E2(Point2D{110, 270}, 'E', white, background);
	pismeno_E2.draw();

	Character pismeno_vykricnik(Point2D{130, 270}, '!', white, background);
	pismeno_vykricnik.draw();

	Line tlacitko_leftline(Point2D{40, 260}, Point2D{40, 305}, white, background);
	tlacitko_leftline.draw();

	Line tlacitko_rightline(Point2D{155, 260}, Point2D{155, 305}, white, background);
	tlacitko_rightline.draw();

	Line tlacitko_upline(Point2D{40, 260}, Point2D{155, 260}, white, background);
	tlacitko_upline.draw();

	Line tlacitko_downline(Point2D{40, 305}, Point2D{155, 305}, white, background);
	tlacitko_downline.draw();

	static int vystrel_x = LCD_WIDTH/2;
	static int vystrel_y = 200;

	Line zakladna_hlavni(Point2D{vystrel_x, vystrel_y}, Point2D{LCD_WIDTH/2, 250}, white, background);
	zakladna_hlavni.draw();

	Circle zakladna(Point2D{LCD_WIDTH/2, 250}, 10, white, background);
	zakladna.draw();
	zakladna.fill();

	Line scrollbar_leftline(Point2D{180, 260}, Point2D{180, 305}, white, background);
	scrollbar_leftline.draw();

	Line scrollbar_rightline(Point2D{460, 260}, Point2D{460, 305}, white, background);
	scrollbar_rightline.draw();

	Line scrollbar_upline(Point2D{180, 260}, Point2D{460, 260}, white, background);
	scrollbar_upline.draw();

	Line scrollbar_downline(Point2D{180, 305}, Point2D{460, 305}, white, background);
	scrollbar_downline.draw();

	scroll(white);

	drawTriangle(Point2D{150, LCD_HEIGHT/2}, 50, white, background);
	drawTriangle(Point2D{300, 150}, 50, white, background);

	cts_points_t l_tpoints;
	l_tpoints.m_points[ 0 ].size = 0;
	selectedColor(pozice_R, red);

	// read data from Touch Screen
	while( 1 )
	{
		int l_num = cts_get_ts_points( &l_tpoints );

		if ( l_num > 0 )
		{
			PRINTF( "TS Points: %d\r\n", l_num );
			for ( int p = 0; p < l_num; p++ )
			{
				PRINTF( "Point [%d]: x=%d y=%d size=%d\r\n",
						p, l_tpoints.m_points[ p ].x, l_tpoints.m_points[ p ].y, l_tpoints.m_points[ p ].size );
				if(l_tpoints.m_points[p].x > 50 && l_tpoints.m_points[p].x < 90 && l_tpoints.m_points[p].y > 10 && l_tpoints.m_points[p].y < 40){
					selectedColor(pozice_R, red);
					active_color = RED;
					selectedColor(pozice_G, background);
					selectedColor(pozice_B, background);
					selectedColor(pozice_W, background);
				}
				if(l_tpoints.m_points[p].x > 200 && l_tpoints.m_points[p].x < 240 && l_tpoints.m_points[p].y > 10 && l_tpoints.m_points[p].y < 40){
					selectedColor(pozice_W, white);
					active_color = WHITE;
					selectedColor(pozice_R, background);
					selectedColor(pozice_G, background);
					selectedColor(pozice_B, background);
				}
				if(l_tpoints.m_points[p].x > 150 && l_tpoints.m_points[p].x < 190 && l_tpoints.m_points[p].y > 10 && l_tpoints.m_points[p].y < 40){
					selectedColor(pozice_B, blue);
					active_color = BLUE;
					selectedColor(pozice_R, background);
					selectedColor(pozice_G, background);
					selectedColor(pozice_W, background);
								}
				if(l_tpoints.m_points[p].x > 100 && l_tpoints.m_points[p].x < 140 && l_tpoints.m_points[p].y > 10 && l_tpoints.m_points[p].y < 40){
					selectedColor(pozice_G, green);
					active_color = GREEN;
					selectedColor(pozice_R, background);
					selectedColor(pozice_B, background);
					selectedColor(pozice_W, background);
								}
				if(l_tpoints.m_points[p].x > 40 && l_tpoints.m_points[p].x < 155 && l_tpoints.m_points[p].y > 260 && l_tpoints.m_points[p].y < 305){
					vystrel(vrat_barvu(active_color));
				}
			}
		}
	}
}

