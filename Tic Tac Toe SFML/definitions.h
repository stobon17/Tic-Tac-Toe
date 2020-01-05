#pragma once

#define SCREEN_WIDTH 641
#define SCREEN_HEIGHT 948

#define SPLASH_STATE_SHOW_TIME 3
#define SPLASH_STATE_BACKGROUND_FILEPATH R"(Resources/res/Splash Background.png)"
#define SPLASH_STATE_SOUND_FILEPATH "Resources/sounds/ding.wav"

#define MAINMENU_BACKGROUND_FILEPATH R"(Resources/res/Main Menu Background.png)"
#define MAINMENU_TITLE_PATH "Resources/res/Game Title.png"

#define MAINMENU_MENU_PLAY_BUTTON "Resources/res/Play Button.png"

#define MAIN_MENU_PLAY_BUTTON_OUTER "Resources/res/Play Button Outer.png"

//GAME STATE ASSETS
#define GAME_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"
#define PAUSE_BUTTON "Resources/res/Pause Button.png"
#define X_FILEPATH "Resources/res/X.png"
#define CIRCLE_FILEPATH "Resources/res/O.png"

//Line for win
#define X_WINNING "Resources/res/X win.png"
#define CIRCLE_WINNING "Resources/res/O win.png"

//Keep track on grid
#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE O_PIECE //Player will play with circles
#define AI_PIECE X_PIECE

//GAME STATES
#define STATE_PLAYING 98
#define STATE_PAUSE 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92
#define GRID_FILEPATH "Resources/res/Grid.png"

//Pause State Assets
#define PAUSE_BACKGROUND_FILEPATH "Resources/res/Main Menu Background.png"
#define RESUME_BUTTON "Resources/res/Resume Button.png"
#define HOME_BUTTON "Resources/res/Home Button.png"

//GAME OVER STATE ASSETS
#define START_OVER_BUTTON "Resources/res/Retry Button.png"

#define TIME_BEFORE_SHOWING_GAME_OVER_STATE 3