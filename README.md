# Cub3D - A Raycasting Engine

Cub3D is a simple raycasting engine inspired by the classic game Wolfenstein 3D. This project implements a first-person perspective maze game using raycasting techniques to create a 3D-like environment from a 2D map.

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Map Format](#map-format)
- [Controls](#controls)
- [The Raycasting Technique](#the-raycasting-technique)
- [Project Structure](#project-structure)

## Overview

Cub3D is a project that recreates the mechanics of early 3D games like Wolfenstein 3D and Doom. While these games appeared to be 3D, they actually used clever rendering techniques to create a 3D illusion from 2D maps. This project focuses on understanding and implementing the raycasting technique that made these games revolutionary for their time.

## Installation

To compile the project, simply run:

```bash
make
```

This will compile the executable `cub3D`.

## Usage

To run the program, use:

```bash
./cub3D [map_file.cub]
```

For example:

```bash
./cub3D random_map.cub
```

The program requires a map file with the `.cub` extension that follows the specific format described below.

## Map Format

The map file must have the `.cub` extension and follow this structure:

```
NO [path_to_north_texture]
SO [path_to_south_texture]
EA [path_to_east_texture]
WE [path_to_west_texture]
C [R,G,B]  # Ceiling color
F [R,G,B]  # Floor color

[map]
```

Where:

- Texture paths point to XPM files
- Colors are specified as RGB values (0-255)
- The map is composed of the following characters:
  - `0`: Empty space
  - `1`: Wall
  - `N`, `S`, `E`, `W`: Player starting position and orientation

Example of a valid map:

```
NO ./path_to_texture.xpm
SO ./path_to_texture.xpm
EA ./path_to_texture.xpm
WE ./path_to_texture.xpm
C 10, 10, 10
F 10, 10, 10

111111111111111
100000000000001
100000000000001
100000000000001
1000000N0000001
100000000000001
100000000000001
100000000000001
111111111111111
```

The map must be closed/surrounded by walls (`1`), and the player must be inside the map.

## Controls

- `W`: Move forward
- `S`: Move backward
- `A`: Move left
- `D`: Move right
- `←`: Rotate camera left
- `→`: Rotate camera right
- `ESC`: Exit the game

## The Raycasting Technique

### How Raycasting Creates a 3D Illusion

Raycasting is a rendering technique that creates a 3D perspective from a 2D map. Unlike modern 3D games that use polygons, raycasting is much simpler but was revolutionary in the early 1990s.

Here's how it works:

1. **The Concept**: For each vertical column of the screen, a ray is cast from the player's position in the direction they're facing, plus an offset based on the column's position relative to the center of the screen.

2. **Ray Calculation**: The program calculates where each ray intersects with a wall in the 2D map.

3. **Distance Calculation**: The distance from the player to the wall is calculated (using the Pythagorean theorem, but with a correction to avoid the "fisheye" effect).

4. **Wall Height**: The height of the wall on the screen is inversely proportional to the distance - walls that are farther away appear shorter.

5. **Texturing**: The program determines which texture to use based on which wall was hit (north, south, east, or west facing), and which part of the texture to display based on where exactly the ray hit the wall.

6. **Rendering**: Finally, a vertical line is drawn for each column with the appropriate height and texture.

### Mathematical Foundation

The core of raycasting relies on these key mathematical concepts:

- **Vector Math**: Player direction and camera plane are represented as 2D vectors.
- **DDA Algorithm**: Digital Differential Analysis is used to efficiently find wall intersections.
- **Perspective Correction**: To avoid the fisheye effect, distances are calculated perpendicular to the camera plane.

### Implementation in Cub3D

In our implementation:

1. For each vertical strip of the screen, we calculate a ray direction.
2. We use the DDA algorithm to find where the ray hits a wall.
3. We calculate the distance to that wall and determine how tall the wall should appear.
4. We apply textures based on which wall was hit and where.
5. We render the ceiling and floor with solid colors.

This creates the illusion of moving through a 3D environment, even though we're just rendering a 2D map from a specific perspective.

## Project Structure

The project is organized into several components:

- **Parsing**: Handles reading and validating the map file
- **Raycasting**: Implements the core rendering algorithm
- **Movement**: Manages player movement and rotation
- **Textures**: Handles loading and applying textures
- **Error Handling**: Manages error detection and reporting

## Testing Maps

The `maps/` directory contains various test maps that can be used to test different aspects of the program:

- `random_map.cub`: A standard working map
- Various other maps in the `maps/` directory to test error handling and edge cases

To test a specific map, run:

```bash
./cub3D maps/[map_name].cub
```

## Conclusion

While this implementation is not as refined as modern game engines, it successfully demonstrates the fundamental principles of raycasting that revolutionized early 3D gaming. The main purpose of this project was to understand the mathematical foundations and rendering techniques that made games like Wolfenstein 3D and Doom possible before the era of hardware-accelerated 3D graphics.
