#include "Game.h"

void Game::check_highest_score()
{
    ifstream file("highest.score");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            highest_score = atoi(line.c_str());
        }
        file.close();
    }

    if (score > highest_score)
    {
        isHigherScore = true;
        highest_score = score;
        ofstream file;
        file.open("highest.score");
        file << highest_score;
        file.close();
    }

    configure_game_over();
}

void Game::game_over()
{
    if (!isHigherScore) sound_crash.play();

    if (isHigherScore)
    {
        sound_applause.play();
        text2.setColor(Color::Red);
        isHigherScore = false;
    }

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);
            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                CAR_X_POSITION = 420;
                CAR_Y_POSITION = 500;
                car.setPosition(Vector2f(CAR_X_POSITION, CAR_Y_POSITION));
                sound_crash.stop();
                sound_applause.stop();
                process();
            }
        }

        window.clear();
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(sprite_game_over);
        window.display();
    }
}

void Game::configure_game_over()
{

    texture_game_over.loadFromFile("graphics/game_over.png");

    sound_buffer_crash.loadFromFile("audio/crash.wav");
    sound_buffer_applause.loadFromFile("audio/applause.wav");

// ---------------------------------------------------------------------------------------- //

    text1.setFont(font_default);
    text1.setCharacterSize(35);
    text1.setString("Press ENTER to continue or ESCAPE to exit");
    text1.setStyle(Text::Bold);
    text1.setPosition(TEXT_X, TEXT_Y);

    text2.setFont(font_default);
    text2.setCharacterSize(35);
    text2.setString("Your highest score: " + to_string(highest_score));
    text2.setStyle(Text::Bold);
    text2.setPosition(TEXT_X + 200, TEXT_Y - 100);
    text2.setColor(Color::White);

    text3.setFont(font_default);
    text3.setCharacterSize(35);
    text3.setString("Score: " + to_string(score));
    text3.setStyle(Text::Bold);
    text3.setPosition(TEXT_X + 300, TEXT_Y - 180);

    sound_crash.setBuffer(sound_buffer_crash);
    sound_applause.setBuffer(sound_buffer_applause);
    sound_applause.setLoop(true);

    sprite_game_over.setTexture(texture_game_over);
    sprite_game_over.setOrigin(GAME_OVER_X_ORIGIN, GAME_OVER_Y_ORIGIN);
    sprite_game_over.setPosition(GAME_OVER_X_POSITION, GAME_OVER_Y_POSITION);

    game_over();
}

void Game::process()
{
    score = 0;

    sound_background.play();

    random_numbers();
    set_van();
    set_taxi();
    set_viper();

    while (window.isOpen())
    {
        background.setPosition(0, background_y_position1);
        background2.setPosition(0, background_y_position2);

        if (score < 20)
        {
            if (background_y_position2 >= 0)
            {
                background_y_position1 = 0;
                background_y_position2 = -650;
            }
            background_y_position1 += 10;
            background_y_position2 += 10;
            van.move(Vector2f(0, 10));
            taxi.move(Vector2f(0, 8));
            viper.move(Vector2f(0, 6));
        }
        else if (score >= 20 && score < 40)
        {
            if (background_y_position2 >= 0)
            {
                background_y_position1 = -10;
                background_y_position2 = -660;
            }
            background_y_position1 += 12;
            background_y_position2 += 12;
            van.move(Vector2f(0, 12));
            taxi.move(Vector2f(0, 10));
            viper.move(Vector2f(0, 8));
        }
        else if (score >= 40 && score < 60)
        {
            if (background_y_position2 >= 0)
            {
                background_y_position1 = -8;
                background_y_position2 = -658;
            }
            background_y_position1 += 14;
            background_y_position2 += 14;
            van.move(Vector2f(0, 14));
            taxi.move(Vector2f(0, 12));
            viper.move(Vector2f(0, 10));
        }
        else if (score >= 60 && score < 80)
        {
            if (background_y_position2 >= 0)
            {
                background_y_position1 = -6;
                background_y_position2 = -656;
            }
            background_y_position1 += 16;
            background_y_position2 += 16;
            van.move(Vector2f(0, 16));
            taxi.move(Vector2f(0, 14));
            viper.move(Vector2f(0, 12));
        }
        else if (score >= 80 && score < 100)
        {
            if (background_y_position2 >= 0)
            {
                background_y_position1 = +2;
                background_y_position2 = -648;
            }
            background_y_position1 += 18;
            background_y_position2 += 18;
            van.move(Vector2f(0, 18));
            taxi.move(Vector2f(0, 16));
            viper.move(Vector2f(0, 14));
        }
        else if (score >= 100)
        {
            if (background_y_position2 >= 0)
            {
                background_y_position1 = -10;
                background_y_position2 = -660;
            }
            background_y_position1 += 20;
            background_y_position2 += 20;
            van.move(Vector2f(0, 20));
            taxi.move(Vector2f(0, 18));
            viper.move(Vector2f(0, 16));
        }

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);

        }

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            CAR_X_POSITION -= 5;
            car.move(Vector2f(-5, 0));
        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            CAR_X_POSITION += 5;
            car.move(Vector2f(5, 0));
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            CAR_X_POSITION -= 5;
            car.move(Vector2f(-5, 0));
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            CAR_X_POSITION += 5;
            car.move(Vector2f(5, 0));
        }

        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            CAR_Y_POSITION -= 5;
            car.move(Vector2f(0, -5));
        }

        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            CAR_Y_POSITION -= 5;
            car.move(Vector2f(0, -5));
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            CAR_Y_POSITION += 5;
            car.move(Vector2f(0, 5));
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            CAR_Y_POSITION += 5;
            car.move(Vector2f(0, 5));
        }


        window.clear();
        window.draw(background);
        window.draw(background2);
        window.draw(car);
        window.draw(van);
        window.draw(taxi);
        window.draw(viper);
        window.draw(rectangular);
        window.draw(text_score);
        window.draw(text_points);
        window.display();

        if (CAR_X_POSITION == BACKGROUND_BORDER_LEFT)
        {
            sound_background.stop();
            check_highest_score();
        }
        if (CAR_X_POSITION == BACKGROUND_BORDER_RIGHT)
        {
            sound_background.stop();
            check_highest_score();
        }
        if (CAR_Y_POSITION == BACKGROUND_BORDER_UP)
        {
            sound_background.stop();
            check_highest_score();
        }
        if (CAR_Y_POSITION == BACKGROUND_BORDER_DOWN)
        {
            sound_background.stop();
            check_highest_score();
        }
        if (Collision::PixelPerfectTest(car, van))
        {
            sound_background.stop();
            check_highest_score();
        }
        if (Collision::PixelPerfectTest(car, taxi))
        {
            sound_background.stop();
            check_highest_score();
        }
        if (Collision::PixelPerfectTest(car, viper))
        {
            sound_background.stop();
            check_highest_score();
        }

        if (van.getPosition().y > 800)
        {
            score++;
            van.setPosition(-150, -10000);
        }
        if (taxi.getPosition().y > 800)
        {
            score++;
            taxi.setPosition(-150, -10000);
        }
        if (viper.getPosition().y > 800)
        {
            score++;
            random_numbers();
            set_van();
            set_taxi();
            set_viper();
        }

        how_many_points = to_string(score);
        text_points.setString(how_many_points);
    }
}

void Game::configure_process()
{
    texture_background.loadFromFile("graphics/background.png");

    texture_rectangular.loadFromFile("graphics/rectangular.png");

    sound_buffer_background.loadFromFile("audio/background.wav");

    Collision::CreateTextureAndBitmask(texture_car, "graphics/audi.png");

    Collision::CreateTextureAndBitmask(texture_van, "graphics/van.png");

    Collision::CreateTextureAndBitmask(texture_taxi, "graphics/taxi.png");

    Collision::CreateTextureAndBitmask(texture_viper, "graphics/viper.png");

// ---------------------------------------------------------------------------------------- //

    car.setTexture(texture_car);
    van.setTexture(texture_van);
    taxi.setTexture(texture_taxi);
    viper.setTexture(texture_viper);

    background.setTexture(texture_background);
    background2.setTexture(texture_background);

    sound_background.setBuffer(sound_buffer_background);
    sound_background.setLoop(true);

    car.setPosition(Vector2f(CAR_X_POSITION, CAR_Y_POSITION));

    car.setOrigin(CAR_X_ORIGIN, CAR_Y_ORIGIN);
    van.setOrigin(VAN_X_ORIGIN, VAN_Y_ORIGIN);
    taxi.setOrigin(TAXI_X_ORIGIN, TAXI_Y_ORIGIN);
    viper.setOrigin(VIPER_X_ORIGIN, VIPER_Y_ORIGIN);

    rectangular.setOrigin(RECTANGULAR_X_ORIGIN, RECTANGULAR_Y_ORIGIN);
    rectangular.setTexture(texture_rectangular);
    rectangular.setPosition(800, 20);

    text_score.setFont(font_default);
    text_score.setCharacterSize(20);
    text_score.setPosition(736, 15);
    text_score.setString("Score: ");
    text_score.setStyle(Text::Bold);
    text_score.setColor(Color::White);
    text_points.setFont(font_default);
    text_points.setCharacterSize(20);
    text_points.setPosition(802, 16);
    text_points.setString("");
    text_points.setStyle(Text::Bold);
    text_points.setColor(Color::White);

    sprite_game_over.scale(2, 2);

    process();
}

void Game::set_viper()
{
    if (random_number[4] == 1) viper.setPosition(Vector2f(VEHICLE_POSITION_01, -900));
    else if (random_number[4] == 2) viper.setPosition(Vector2f(VEHICLE_POSITION_02, -900));
    else if (random_number[4] == 3) viper.setPosition(Vector2f(VEHICLE_POSITION_03, -900));
    else if (random_number[4] == 4) viper.setPosition(Vector2f(VEHICLE_POSITION_04, -900));
    else if (random_number[4] == 5) viper.setPosition(Vector2f(VEHICLE_POSITION_05, -900));
}

void Game::set_taxi()
{
    if (random_number[2] == 1) taxi.setPosition(Vector2f(VEHICLE_POSITION_01, -600));
    else if (random_number[2] == 2) taxi.setPosition(Vector2f(VEHICLE_POSITION_02, -600));
    else if (random_number[2] == 3) taxi.setPosition(Vector2f(VEHICLE_POSITION_03, -600));
    else if (random_number[2] == 4) taxi.setPosition(Vector2f(VEHICLE_POSITION_04, -600));
    else if (random_number[2] == 5) taxi.setPosition(Vector2f(VEHICLE_POSITION_05, -600));
}

void Game::set_van()
{
    if (random_number[0] == 1) van.setPosition(Vector2f(VEHICLE_POSITION_01, -300));
    else if (random_number[0] == 2) van.setPosition(Vector2f(VEHICLE_POSITION_02, -300));
    else if (random_number[0] == 3) van.setPosition(Vector2f(VEHICLE_POSITION_03, -300));
    else if (random_number[0] == 4) van.setPosition(Vector2f(VEHICLE_POSITION_04, -300));
    else if (random_number[0] == 5) van.setPosition(Vector2f(VEHICLE_POSITION_05, -300));
}

void Game::random_numbers()
{
    for (i = 0; i < how_many_numbers; i++) random_number[i] = i + 1;

    for (i = 10 * how_many_numbers; i > 0; i--)
    {
        i1 = rand() % how_many_numbers;
        i2 = rand() % how_many_numbers;
        x = random_number[i1];
        random_number[i1] = random_number[i2];
        random_number[i2] = x;
    }
}

void Game::tip()
{
    while (window.isOpen())
    {


        for (int i = 0; i <= 3; i++)
        {

            seconds[i] = 3 - i;
            which_second = to_string(seconds[i]);
            text_timepiece.setString(which_second);


            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);
            }

            window.clear();
            window.draw(arrow_keys);
            window.draw(wsad_keys);
            window.draw(text_timepiece);
            window.display();

            sound_time_sound.play();

            Sleep(1000);
        }

        configure_process();
    }

}

void Game::configure_tip()
{
    font_default.loadFromFile("fonts/arial.ttf");

    texture_wsad_keys.loadFromFile("graphics/wsad_keys.png");
    texture_arrow_keys.loadFromFile("graphics/arrow_keys.png");

    sound_buffer_time_sound.loadFromFile("audio/time_sound.wav");

// ---------------------------------------------------------------------------------------- //

    text_timepiece.setFont(font_default);
    text_timepiece.setCharacterSize(100);
    text_timepiece.setPosition(380, 0);
    text_timepiece.setColor(Color::White);

    arrow_keys.setTexture(texture_arrow_keys);
    arrow_keys.setOrigin(ARROW_KEYS_X_ORIGIN, ARROW_KEYS_Y_ORIGIN);
    arrow_keys.setPosition(ARROW_KEYS_X_POSITION_TIP, ARROW_KEYS_Y_POSITION_TIP);
    wsad_keys.setTexture(texture_wsad_keys);
    wsad_keys.setOrigin(WSAD_KEYS_X_ORIGIN, WSAD_KEYS_Y_ORIGIN);
    wsad_keys.setPosition(ARROW_KEYS_X_POSITION_TIP + 400, ARROW_KEYS_Y_POSITION_TIP);
    arrow_keys.scale( 0.4, 0.4 );

    sound_time_sound.setBuffer(sound_buffer_time_sound);

    tip();
}

void Game::menu()
{
    window.create(VideoMode(WINDOW_X_SIZE, WINDOW_Y_SIZE, 32), "The car 1.1", Style::Close);
    window.setActive(true);
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) exit(0);

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Down)
                {
                    if (!button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
                        sound_sound_button.play();
                    }
                    which_chosen++;
                    if (which_chosen >= 4)
                    {
                        which_chosen = 1;
                    }
                }
                if (event.key.code == Keyboard::Up)
                {
                    if (!button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))
                        && !button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
                        sound_sound_button.play();
                    }
                    which_chosen--;
                    if (which_chosen <= -1 || which_chosen <= 0)
                    {
                        which_chosen = 3;
                    }
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                if (which_chosen == 1)
                {
                    sound_clicked_sound.play();
                    Sleep(500);
                    configure_tip();
                }
                if (which_chosen == 2)
                {
                    ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
                    sound_clicked_sound.play();
                    Sleep(500);
                    ShellExecute(0, 0, L"info.txt", 0, 0, SW_SHOW);
                    ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
                }
                if (which_chosen == 3)
                {
                    sound_clicked_sound.play();
                    Sleep(500);
                    window.close();
                    exit(0);
                }
            }
        }

        if (button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            if (! (which_chosen == 0))
            {
                which_chosen = 0;
            }
            isSelected_Button_start = true;
            isSelected_Button_info = false;
            isSelected_Button_exit = false;
            if (clock01.getElapsedTime().asMilliseconds() > 20)
            {
                sound_sound_button.setLoop(false);
            }
            else
            {
                sound_sound_button.play();
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound_clicked_sound.play();
                Sleep(500);
                configure_tip();
            }
        }
        else
        {
            sound_sound_button.setLoop(false);
            clock01.restart();
        }

        if (!button_start.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) isSelected_Button_start = false;

        if (button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            if (! (which_chosen == 0))
            {
                which_chosen = 0;
            }
            isSelected_Button_start = false;
            isSelected_Button_info = true;
            isSelected_Button_exit = false;
            if (clock02.getElapsedTime().asMilliseconds() > 20)
            {
                sound_sound_button.setLoop(false);
            }
            else
            {
                sound_sound_button.play();
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
                sound_clicked_sound.play();
                Sleep(500);
                ShellExecute(0, 0, L"info.txt", 0, 0, SW_SHOW);
                ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
            }

        }
        else
        {
            sound_sound_button.setLoop(false);
            clock02.restart();
        }

        if (!button_info.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) isSelected_Button_info = false;

        if (button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            if (!(which_chosen == 0))
            {
                which_chosen = 0;
            }
            isSelected_Button_start = false;
            isSelected_Button_info = false;
            isSelected_Button_exit = true;
            if (clock03.getElapsedTime().asMilliseconds() > 20)
            {
                sound_sound_button.setLoop(false);
            }
            else
            {
                sound_sound_button.play();
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                sound_clicked_sound.play();
                Sleep(500);
                window.close();
                exit(0);
            }

        }
        else
        {
            sound_sound_button.setLoop(false);
            clock03.restart();
        }

        if (!button_exit.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) isSelected_Button_exit = false;

        if (which_chosen == 1)
        {
            if (isSelected_Button_start == false)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = false;
                isSelected_Button_start = true;
            }
            else if (isSelected_Button_start == true)
            {
                isSelected_Button_info = true;
                isSelected_Button_exit = false;
                isSelected_Button_start = false;
            }
        }

        if (which_chosen == 2)
        {
            if (isSelected_Button_info == false)
            {
                isSelected_Button_info = true;
                isSelected_Button_exit = false;
                isSelected_Button_start = false;
            }
            else if (isSelected_Button_info == true)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = true;
                isSelected_Button_start = false;
            }
        }

        if (which_chosen == 3)
        {
            if (isSelected_Button_exit == false)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = true;
                isSelected_Button_start = false;
            }
            else if (isSelected_Button_start == true)
            {
                isSelected_Button_info = false;
                isSelected_Button_exit = false;
                isSelected_Button_start = true;
            }
        }

        if (isSelected_Button_start == true)
        {
            window.draw(button_start_selected);
        }
        else
        {
            window.draw(button_start);
        }
        if (isSelected_Button_info == true)
        {
            window.draw(button_info_selected);
        }
        else
        {
            window.draw(button_info);
        }
        if (isSelected_Button_exit == true)
        {
            window.draw(button_exit_selected);
        }
        else
        {
            window.draw(button_exit);
        }

        mousePos = Mouse::getPosition(window);
        cursor.setPosition((float)mousePos.x, (float)mousePos.y);
        window.draw(cursor);
        window.display();
        window.clear();

    }
}

void Game::configure_menu()
{
	texture_button_start.loadFromFile("graphics/button_start.jpg");
	texture_button_start_selected.loadFromFile("graphics/button_start_selected.jpg");
	texture_button_info.loadFromFile("graphics/button_info.jpg");
	texture_button_info_selected.loadFromFile("graphics/button_info_selected.jpg");
	texture_button_exit.loadFromFile("graphics/button_exit.jpg");
	texture_button_exit_selected.loadFromFile("graphics/button_exit_selected.jpg");

	sound_buffer_sound_button.loadFromFile("audio/sound_button.wav");
	sound_buffer_clicked_sound.loadFromFile("audio/clicked_sound.wav");

	texture_cursor.loadFromFile("graphics/cursor.png");

    icon.loadFromFile("icon.png");

// ---------------------------------------------------------------------------------------- //

	cursor.setTexture(texture_cursor);
	cursor.setOrigin(CURSOR_X_ORIGIN, CURSOR_Y_ORIGIN);

	button_start.setTexture(texture_button_start);
	button_start_selected.setTexture(texture_button_start_selected);
	button_info.setTexture(texture_button_info);
	button_info_selected.setTexture(texture_button_info_selected);
	button_exit.setTexture(texture_button_exit);
	button_exit_selected.setTexture(texture_button_exit_selected);

	sound_sound_button.setBuffer(sound_buffer_sound_button);
	sound_clicked_sound.setBuffer(sound_buffer_clicked_sound);

	button_start.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
	button_start_selected.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
	button_info.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
	button_info_selected.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
	button_exit.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);
	button_exit_selected.setOrigin(BUTTON_X_ORIGIN, BUTTON_Y_ORIGIN);

	button_start.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION);
	button_start_selected.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION);
	button_info.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 200);
	button_info_selected.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 200);
	button_exit.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 400);
	button_exit_selected.setPosition(BUTTON_X_POSITION, BUTTON_Y_POSITION + 400);

}

void Game::check_integrity()
{
	if (!experimental::filesystem::exists("icon.ico"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("info.txt"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("audio/background.wav"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("audio/clicked_sound.wav"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("audio/crash.wav"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("audio/sound_button.wav"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("audio/time_sound.wav"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("fonts/arial.ttf"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/arrow_keys.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/audi.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/background.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/button_exit.jpg"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/button_exit_selected.jpg"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/button_info.jpg"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/button_info_selected.jpg"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/button_start.jpg"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/button_start_selected.jpg"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/game_over.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/taxi.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/van.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/viper.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/wsad_keys.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/cursor.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
	if (!experimental::filesystem::exists("graphics/rectangular.png"))
	{
		MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
		ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
		exit(0);
	}
    if (!experimental::filesystem::exists("audio/applause.wav"))
    {
        MessageBox(NULL, L"Brak jednego lub wiêcej plików. Pobierz program ponownie ze strony https://www.hansik.pl/", L"Nie uda³o siê otworzyæ pliku!", MB_ICONERROR | MB_OK);
        ShellExecute(0, 0, L"https://www.hansik.pl/", 0, 0, SW_SHOW);
        exit(0);
    }
	if (!experimental::filesystem::exists("highest.score"))
	{
		ofstream file("highest.score");
		file << 0;
		file.close();
	}
}