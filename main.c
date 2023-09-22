#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "box.h"
#include "main.h"

#define BOX_SPEED 10

// game running 
bool game_is_running = true;

bool init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO != 0))
	{
		printf("Cannot initialize SDl: SDL_Error: %s", SDL_GetError());
		return false;
	}
	return true;
}


void sdl_Window()
{
	window = SDL_CreateWindow("space shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Cannot create a window. SDL_Error: %s \n", SDL_GetError());
		SDL_Quit();
	}
}

void sdl_Render()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Cannot create a renderer. SDL_Error: %s \n", SDL_GetError());
	}
}


void handle_inputs()
{
	SDL_Event event;
	if (SDL_PollEvent(&event) > 0)
	{
		if (event.type == SDL_QUIT)
		{
			printf("Window is close... \n");
			game_is_running = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				box2.y -= BOX_SPEED;
				printf("y: %d \n", box2.y);
				break;
			case SDLK_s:
				box2.y += BOX_SPEED;
				printf("y: %d \n", box2.y);
				break;
			case SDLK_a:
				box2.x -= BOX_SPEED;
				printf("x: %d \n", box2.x);
				break;
			case SDLK_d:
				box2.x += BOX_SPEED;
				printf("x: %d \n", box2.x);
				break;
			}
		}
	}
}



void update_Sdl()
{
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	render_box();
	SDL_RenderPresent(renderer);

}
int main(int argc, char* argv[])
{
	if (!init_sdl())
	{
		return 1;
	}

	sdl_Window();
	sdl_Render();
	object1();
	object2();

	while (game_is_running)
	{
		handle_inputs();
		collision_detection();
		update_Sdl();
	}

	return 0;
}

