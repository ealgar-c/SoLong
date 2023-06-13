<div align="center">
	<h1> So Long </h1>
	<p>And thanks for all the fish!</p>
	<img src="https://wakatime.com/badge/user/a0e860d2-9914-4fed-8143-b9fd5cf5e6c1/project/519129ef-1651-45c9-b77c-ca3fb8622a1e.svg?style=flat"/>
	<br />
	<img src="https://img.shields.io/badge/norme-OK-success?style=flat"/>
	<img src="https://img.shields.io/badge/leaks-CLEAR-success?style=flat"/>
	<img src="https://img.shields.io/badge/-100%2F100-success?style=flat&logo=42&logoColor=000" />
</div>

<h2 align="center">📜 PROYECT DESCRIPTION 📜</h2>

El proyecto So_Long consiste en la creación un programa en C que sea capaz de cargar mapas aleatorios de un archivo y permita al jugador moverse por el mapa. El objetivo principal es familiarizarte con la manipulación de archivos, el manejo de memoria y la programación en C.

<h2 align="center">🌲 PROYECT TREE 🌲</h2>

```
.
├── Makefile
├── README.md
├── include/
│   └── solong.h
├── libft/
├── maps/
│   ├── errors/
│   │   ├── map_barriertest.ber
│   │   ├── map_counttest.ber
│   │   ├── map_pathtest.ber
│   │   └── map_shapetest.ber
│   ├── map1.ber
│   ├── map2.ber
│   └── map_medium.ber
├── mlx/
├── objs/
├── sprites/
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
└── src/
    ├── check_walls.c
    ├── ingame.c
    ├── main.c
    ├── mapcheck.c
    ├── mapcreation.c
    ├── pathcheck.c
    ├── playermovement.c
    └── windowconfig.c

```

<h2 align="center">🚶🏻‍♂️ PROYECT ROADMAP 🚶</h2>

<h3 align="center">🗺 MAP HANDLING</h3>

*  Take the map and create a vector of it
*  Check the map shape
*  Check if it's a good map
*  Check if there is at least one path
*  Check if the player is not trapped

<h3 align="center">🖼 IMAGES CREATION AND SHOWING</h3>

*  Choose a theme
*  Search the images and convert them to xpm with the right size
*  Take each xpm file and convert them to images that mlx can show on a window

<h3 align="center">🤡 MINILIBX MANAGEMENT</h3>

*  Create the game window
*  Establish the right configuration for the window
*  Show images in the game window
*  Implement key_hook cases for player movement and closing the window

<h3 align="center">🕹 IN-GAME EVENTS</h3>

*  Implement logic for player movement within the map
*  Allow the player to collect objects placed on the map
*  Keep track of the number of collected objects
*  Keep track of the number of movements

<h3 align="center">🥬 EXTRA THINGS TO CONSIDER</h3>

*  Ensure proper memory deallocation
*  Check that everyting passes norminette
*  Create the Makefile and make sure it doesnt relink

<h2 align="center">⚙️ PROYECT GENERAL PROCEDURE ⚙️</h2>

