#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <experimental/filesystem>
#include <Windows.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "Collision.h"
#include <cstdlib>

using namespace std;
using namespace sf;

class Game
{
public:
	
	   Image icon;
	 
	   RenderWindow window;

	   Event event;

	   Font font_default;

	   const unsigned int WINDOW_X_SIZE = 840;
	   const unsigned int WINDOW_Y_SIZE = 650;

    /// GAME OVER ///

	   void configure_game_over();
	   void game_over();
	   void check_highest_score();

	   Texture texture_game_over;

	   Sprite sprite_game_over;

	   Text text1, text2, text3;

	   SoundBuffer sound_buffer_crash, sound_buffer_applause;

	   Sound sound_crash, sound_applause;

	   string line;

	   int highest_score;

	   const float TEXT_X = 50;
	   const float TEXT_Y = 550;
	   const float GAME_OVER_X_ORIGIN = 250;
	   const float GAME_OVER_Y_ORIGIN = 80;
	   const float GAME_OVER_X_POSITION = 410;
	   const float GAME_OVER_Y_POSITION = 200;

	   bool isHigherScore = false;

	/// GAME OVER * ///

	/// PROCESS ///

	   void configure_process();
	   void process();
	   void random_numbers();
	   void set_van();
	   void set_taxi();
	   void set_viper();

	   Texture texture_background, texture_car, texture_van, texture_taxi, texture_viper, texture_rectangular;

	   Sprite background, background2, car, van, taxi, viper, rectangular;

	   Text text_score, text_points;

	   SoundBuffer sound_buffer_background;

	   Sound sound_background;

	   float background_y_position1 = 0;
	   float background_y_position2 = -650;

	   const float CAR_X_ORIGIN = 50;
	   const float CAR_Y_ORIGIN = 114;
	   const float BACKGROUND_BORDER_LEFT = 180;
	   const int BACKGROUND_BORDER_RIGHT = 670;
	   const float BACKGROUND_BORDER_UP = -100;
	   const float BACKGROUND_BORDER_DOWN = 660;
	   const float VAN_X_ORIGIN = 45;
	   const float VAN_Y_ORIGIN = 115;
	   const float TAXI_X_ORIGIN = 57;
	   const float TAXI_Y_ORIGIN = 104;
	   const float VIPER_X_ORIGIN = 54;
	   const float VIPER_Y_ORIGIN = 105;
	   const float RECTANGULAR_X_ORIGIN = 65;
	   const float RECTANGULAR_Y_ORIGIN = 40;
	   const float VEHICLE_POSITION_01 = 200;
	   const float VEHICLE_POSITION_02 = 350;
	   const float VEHICLE_POSITION_03 = 450;
	   const float VEHICLE_POSITION_04 = 550;
	   const float VEHICLE_POSITION_05 = 650;
	   const int how_many_numbers = 5;

	   int random_number[5], i, i1, i2, x, score;

	   string how_many_points;

	   float CAR_X_POSITION = 420;
	   float CAR_Y_POSITION = 500;

	/// PROCESS * //

    /// TIP ///

	   void configure_tip();
	   void tip();

	   Texture texture_wsad_keys, texture_arrow_keys;

	   Sprite arrow_keys, wsad_keys;

	   Text text_timepiece;

	   SoundBuffer sound_buffer_time_sound;

	   Sound sound_time_sound;

	   const float ARROW_KEYS_X_POSITION_TIP = 200;
	   const float ARROW_KEYS_Y_POSITION_TIP = 300;
	   const float WSAD_KEYS_X_ORIGIN = 135;
	   const float WSAD_KEYS_Y_ORIGIN = 95;
	   const float ARROW_KEYS_X_ORIGIN = 320;
	   const float ARROW_KEYS_Y_ORIGIN = 215;

	   int seconds[5];

	   string which_second;

    /// TIP * ///

	/// MENU ///

	   void configure_menu();
	   void menu();

	   Texture texture_button_start, texture_button_start_selected, texture_button_info, texture_button_info_selected, texture_button_exit, texture_button_exit_selected, texture_cursor;

	   Sprite button_start, button_start_selected, button_info, button_info_selected, button_exit, button_exit_selected, cursor;

	   SoundBuffer sound_buffer_sound_button, sound_buffer_clicked_sound, empty;

	   Sound sound_sound_button, sound_clicked_sound;

	   Vector2i mousePos;

	   Clock clock01, clock02, clock03;

	   int which_chosen = 0;

	   const float BUTTON_X_ORIGIN = 190;
	   const float BUTTON_Y_ORIGIN = 70;
	   const float BUTTON_X_POSITION = 415;
	   const float BUTTON_Y_POSITION = 120;
	   const float CURSOR_X_ORIGIN = 17;
	   const float CURSOR_Y_ORIGIN = 21;

	   bool isSelected_Button_start = false;
	   bool isSelected_Button_info = false;
	   bool isSelected_Button_exit = false;

	/// MENU * ///

	/// INTEGRITY VALIDATOR ///

	   void check_integrity();

	/// INTEGRITY VALIDATOR * ///
};

