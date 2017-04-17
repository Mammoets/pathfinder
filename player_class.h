#pragma once
#include <iostream>
using namespace std;


class Player
{
private:
	//Variables to hold the player's position, speed, and direction.
	double player_x, player_y, player_speed;
	int player_dir;

public:
	//Function to set the player's position.
	void set_player_pos(double x, double y);

	//Function to get the player's X position.
	double get_player_x();

	//Function to get the player's Y position.
	double get_player_y();

	//Function to set the player's speed.
	void set_player_speed(double speed);

	//Function to get the player's speed.
	double get_player_speed();

	//Function to set the player's direction.
	void set_player_dir(int direction);

	//Function to get the player's speed.
	double get_player_dir();

	//Functions to move player.
	void step_forward(double framerate);
	void step_backward(double framerate);
	void step_left(double framerate);
	void step_right(double framerate);

	//Functions to turn the player.
	void turn_left(int amount);
	void turn_right(int amount);


};