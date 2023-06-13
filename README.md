# SoLong
And thanks for all the fish!

<h3 text-align="center"> proyect tree </h3>
'''
.
├── Makefile
├── README.md
├── include
│   └── solong.h
├── libft
├── maps
│   ├── errors
│   │   ├── map_barriertest.ber
│   │   ├── map_counttest.ber
│   │   ├── map_pathtest.ber
│   │   └── map_shapetest.ber
│   ├── map1.ber
│   ├── map2.ber
│   └── map_medium.ber
├── mlx
├── objs
├── sprites
│   ├── coin.png
│   ├── coin.xpm
│   ├── door.png
│   ├── door.xpm
│   ├── floor.png
│   ├── floor.xpm
│   ├── isaac.png
│   ├── isaac.xpm
│   ├── wall.png
│   └── wall.xpm
└── src
    ├── check_walls.c
    ├── ingame.c
    ├── main.c
    ├── mapcheck.c
    ├── mapcreation.c
    ├── pathcheck.c
    ├── playermovement.c
    └── windowconfig.c
´´´


### MAP HANDLING
|to-do|status|
| --- | --- |
|get the map into a char **| done |
|check if its a good map:| done |
|check if there is at least one path| done |
|check if the player is not trapped| done |
|check the map shape| done |


### IMAGES CREATION AND SHOWING
|to-do|status|
| --- | --- |
|choose the theme im going to use (n-c)| done |
|choose the images sprites im going to use (n-c)| done |
|get the images to xpm (n-c)| done |
|create void * to each xpm file of the game| done |

### XPM MANAGEMENT
|to-do|status|
| --- | --- |
|create the window of the game| done |
|establish the right configuration| done |
|create the cases of key_hook| done |
|show the images in the window| done |

### IN-GAME EVENTS
|to-do|status|
| --- | --- |
|Clean a cell and put the player in another one if im moving| done |
|make the coins disapear if i get them| done |

### FINAL PART
|to-do|status|
| --- | --- |
| Check everything passes norminette | done |
| Check there are no leaks | done |