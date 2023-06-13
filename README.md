<div align="center">
	<h1> So_Long</h1>
	<p>And thanks for all the fish!</p>
    <br />
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<img src="https://img.shields.io/badge/-100%2F100-important?logo=42&logoColor=fff" />
</div>

<h3 align="center"> PROYECT TREE </h3>

```
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

```


<h2 align="center"> PROYECT ROADMAP </h2>
<h3 align="center">MAP HANDLING</h3>

*  Get the map into a char **
*  Check if it's a good map
*  Check if there is at least one path
*  Check if the player is not trapped
*  Check the map shape

<h3 align="center">IMAGES CREATION AND SHOWING</h3>

*  Choose the theme I'm going to use (n-c)
*  Choose the image sprites I'm going to use (n-c)
*  Get the images to xpm (n-c)
*  Create void * to each xpm file of the game

<h3 align="center">XPM MANAGEMENT</h3>

*  Create the window of the game
*  Establish the right configuration
*  Create the cases of key_hook
*  Show the images in the window

<h3 align="center">IN-GAME EVENTS</h3>

*  Create different functions for each movement key
*  Clean a cell and put the player in another one if I'm moving
*  Have a coin counter so I know how much I need in order to finish

<h3 align="center">FINAL PART</h3>

*  Check everything passes norminette
*  Check there are no leaks