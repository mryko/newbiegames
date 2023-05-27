#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100

typedef struct {
    int health;
} Player;

typedef struct {
    int is_running;
    Player player;
} Game;

void print_menu();
void start_quest(Game *game);
void restore_health(Game *game);
void view_player_details(Game *game);

int main() {
    srand(time(NULL));
    Game game;
    game.is_running = 1;
    game.player.health = MAX_HEALTH;

    while (game.is_running) {
        print_menu();
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                start_quest(&game);
                break;
            case 2:
                restore_health(&game);
                break;
            case 3:
                view_player_details(&game);
                break;
            case 4:
                game.is_running = 0;
                break;
            default:
                printf("\nInvalid option, try again\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\nWelcome, what would you like to do?\n");
    printf("1. Start Quest\n");
    printf("2. Restore Health\n");
    printf("3. View Player Details\n");
    printf("4. Quit Game\n");
    printf("Select an option: ");
}

void start_quest(Game *game) {
    printf("\nStarting Quest...\n");

    int is_quest_successful = rand() % 2;
    if (is_quest_successful) {
        printf("\nQuest Completed Successfully! Gained 10 health!\n");
        game->player.health += 10;
    } else {
        printf("\nQuest Failed! Lost 5 health!\n");
        game->player.health -= 5;
    }
}

void restore_health(Game *game) {
    game->player.health += 10;
    printf("\nHealth Restored! Current Health: %d\n", game->player.health);
}

void view_player_details(Game *game) {
    printf("\nPlayer Health: %d\n", game->player.health);
}
