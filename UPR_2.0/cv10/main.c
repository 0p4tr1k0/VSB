#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>


int main(){

    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Pogrom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Event event;

    int running = 1;

    int draw_line_1 = 0;
    int draw_line_2 = 0;


    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    running = 0;
                    break;
                }
                case SDL_KEYDOWN:
                {
                    if(event.key.keysym.scancode == SDL_SCANCODE_L){
                        draw_line_1 = !draw_line_1;
                    }
                    if(event.key.keysym.scancode == SDL_SCANCODE_K){
                        draw_line_2 = !draw_line_2;
                    }
                }
            }
        }

        int width = 0;
        int height = 0;

        SDL_GetWindowSize(window, &width, &height);
        
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                int brightness = rand() %256;

                SDL_SetRenderDrawColor(renderer, brightness, brightness, brightness, SDL_ALPHA_OPAQUE);

                SDL_RenderDrawPoint(renderer, x, y);
            }
            
        }
        

        if(draw_line_1){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, 0, 0, width, height);
        }
        if (draw_line_2)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, 0, height, width, 0);
        }
        
        SDL_RenderPresent(renderer);
    }
    


    SDL_Quit();


    return 0;
}