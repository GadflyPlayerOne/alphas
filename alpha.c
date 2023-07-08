#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>


#define SEED 1
#define SEED_Y 42
#define VARIANCE 0.11
#define LIVES 3
#define BUMP 0.1
#define SLEEP_MS 10

int msleep(unsigned int tms) {
  return usleep(tms * 1000);
}

void alpha(int seed, int x, const int start) {

    static int y = SEED_Y;
    static int lives = LIVES;

    unsigned int currentTime = time(NULL);
    // increase x
    x += 1;

    int random = rand() % seed;

    if(x % 2 == 0) {
        random *= -1;
    }

    double delta = VARIANCE * seed;
    int variance = seed + delta;

    // let it grow
    y =  y + random % variance;


    fprintf(stderr, "\r%d: %d", currentTime - start, y);
    // you die
    if(y <= 0 || y == SEED_Y) {


        if(y == SEED_Y) {
            fprintf(stderr, "\r          ");
            fprintf(stderr, "\n\nYou have died an instant death. Your score was: %d\n", currentTime - start);
            return;
        }

        if(lives == 0) {
            fprintf(stderr, "\r          ");
            fprintf(stderr, "\n\nYou have died. Your score was: %d\n", currentTime - start);
            return;
        } else {
            y = seed;
            lives -= 1;

            fprintf(stderr, "\n*ouch* %d lives left.\n",lives);
        }
    }

    // sleep
    msleep(SLEEP_MS);

    alpha(seed, x, start);
}

int main() {

    unsigned int start = time(NULL);

    srand(time(NULL));

    int alphaSeed;

    fprintf(stderr, "Enter an integer:");

    fscanf(stdin, "%d", &alphaSeed);

    int x;
    for (x = 3; x > 0; x--) {
        fprintf(stderr, "\n%d\n", x);

        msleep(1000);
    }

    fprintf(stderr, "\nGo!\n\n");

    alpha(rand() % alphaSeed, 0, time(NULL));
}
