#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

#include "ray_window.h"
#include "wall_object.h"
#include "ray_caster.h"

// GLOBAL CONSTANTS

#define RESOLUTION_X 640
#define RESOLUTION_Y 480

#define CUBE_SIDE_LENGTH 100

#define FIELD_OF_VIEW 70 

// HELPER FUNCTIONS

double get_elapsed_time();

/*
Unfinished raycast engine.

Check events stops the engine until a key is pressed.

Spin around the map as a demo for things to come.

Chris: 	Look in the ray_window.cpp file for the check_events function.
	Thats where you'll want to read events from.

John:	Look in the ray_caster.cpp file. See what the best way to implement
	your maze class is in the get_raycast_array function.
*/

int main()
{
	ray_window cast_display(RESOLUTION_X, RESOLUTION_Y);

	keyboard_input inputs;

	wall_object rays[RESOLUTION_X];

	// Set default values for all the wall_objects in the rays array
	for(int i = 0; i < RESOLUTION_X; i++)
	{
		// Set the max height of a ray
		rays[i].set_max(RESOLUTION_Y);
		// Define wall units
		rays[i].set_unit(CUBE_SIDE_LENGTH);
		// Set the actual size of the way, using distance.
		// Will have to change later
		rays[i].set_size(i);
		// Set the color of the wall
		rays[i].set_base_hex_color(0xFF,0x00,0x00);
	}


	ray_caster caster;

	float angle = 0;
	float time = 0;
	int pos_x = 200;
	int pos_y = 400;

	double frame_rate;

	// Game loop
	while(1)
	{
		frame_rate = get_elapsed_time();

		// Get the sizes of the walls to be drawn
		caster.get_raycast_array(rays, RESOLUTION_X,
                                 pos_x, pos_y,
                                 FIELD_OF_VIEW, angle,
                                 CUBE_SIDE_LENGTH);
	
		// Draw the ceiling
		cast_display.draw_rectangle_to_buffer(0,0, RESOLUTION_X - 1,
				RESOLUTION_Y / 2, 0xFFFFFF);

		// Draw the floor
		cast_display.draw_rectangle_to_buffer(0, RESOLUTION_Y / 2, 
				RESOLUTION_X - 1, RESOLUTION_Y - 1, 0xBA924E);
		// Draw the wall
		cast_display.line_cast_to_buffer(rays);
		
		cast_display.draw_rectangle_to_buffer(
			(RESOLUTION_X / 2) - 4,
			(RESOLUTION_Y / 2) - 4,
			(RESOLUTION_X / 2) + 4,
			(RESOLUTION_Y / 2) + 4,
			0x000000);

		cast_display.draw_rectangle_to_buffer(
			(RESOLUTION_X / 2) - 2,
			(RESOLUTION_Y / 2) - 2,
			(RESOLUTION_X / 2) + 2,
			(RESOLUTION_Y / 2) + 2,
			0xFFFFFF);

		// Draw the buffer to the screen
		cast_display.draw_buffer();

		cast_display.read_events(inputs);
/*
		if(inputs.W_FORWARD)
			pos_x += frame_rate;
		if(inputs.W_BACKWARD)
			pos_x -= frame_rate;
		if(inputs.W_LEFT)
			pos_y += frame_rate;
		if(inputs.W_RIGHT)
			pos_y -= frame_rate;
*/
		// Time & angle tracking for example
		time += frame_rate;
		angle += frame_rate * 50.0f;
	}
}

double get_elapsed_time()
{
	static clock_t begin = 10;
	clock_t end = clock();
	
	double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;

	begin = clock();
}
