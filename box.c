#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "main.h"
#include "box.h"

#define BOX1_SIZE 100
#define BOX2_SIZE 50


void boxIntersect_pic()
{
	tImage = load_image("C:\\Users\\Golden\\Desktop\\hit.png", renderer); // change this image of your pic.
	if (tImage == NULL)
	{
		printf("Failed to render an image. SDL_Erro:%s\n", SDL_GetError());
	}
	else
	{
		collision_pic.x = (WIDTH - BOX1_SIZE) / 2;
		collision_pic.y = (HEIGHT - BOX1_SIZE) / 2 - 90;
		collision_pic.w = 100;
		collision_pic.h = 100;
	}
}

SDL_Texture* load_image(const char* filaname, SDL_Renderer* ren)
{
	int flags = IMG_INIT_PNG;
	if (IMG_Init(flags) != flags)
	{
		printf("Failed to initialize image. SDL_Error:%s\n", SDL_GetError());
	}

	surface = IMG_Load(filaname);
	if (surface == NULL)
	{
		printf("Failed to create a surface. SDL_ERROR:%s\n", SDL_GetError());
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL)
	{
		printf("Failed to load the texture. SDL_ERROR:%s\n", SDL_GetError());
	}

	return texture;
}

void object1()
{
	box1.x = (WIDTH - BOX1_SIZE) / 2;
	box1.y = (HEIGHT - BOX1_SIZE) / 2;
	box1.w = BOX1_SIZE;
	box1.h = BOX1_SIZE;

	printf("X value : %d \n", box1.x);
	printf("Y value: %d \n", box1.y);	

}

void object2()
{
	box2.x = 0;
	box2.y = 0;
	box2.w = BOX2_SIZE;
	box2.h = BOX2_SIZE;
}

// implementing AABB algorithm
bool collision_detection()
{
	// Calculate the right and bottom edges of both boxes
	int box1_right = box1.x + box1.w;
	int box1_bottom = box1.y + box1.h;


	int box2_right = box2.x + box2.w;
	int box2_bottom = box2.y + box2.h;

	// Check for collision
	if (box1.x < box2_right && box1_right > box2.x && 
		box1.y < box2_bottom && box1_bottom > box2.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void render_box()
{
	SDL_RenderClear(renderer);
	if (collision_detection())
	{
		//box1
		SDL_SetRenderDrawColor(renderer, 172, 50, 50, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &box1);

		//box2
		SDL_SetRenderDrawColor(renderer, 172, 50, 50, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &box2);

		boxIntersect_pic();
		SDL_RenderCopy(renderer, tImage, NULL, &collision_pic);




	}
	else
	{	
		//box1
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawRect(renderer, &box1);

		//box2
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &box2);
	}




}