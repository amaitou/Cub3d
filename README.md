---
![aJ489](https://github.com/amaitou/Cub3d/assets/49293816/6056a29c-b59d-469a-9867-2ddaa57ab407)

---
# Cub3D
"cub3D" is a popular project that involves creating a simple 3D game engine using the C programming language. This project is often used to teach students various aspects of computer graphics and *raycasting*.

The project consists of two parts, the first one is the `Mandatory Part` where you will build only a 3D game with no further features, whereas the bonus part includes the mandatory part plus a minimap system and the behavior of changing the rotation angle based on the mouse movements additionally to the wall coalition.

---

<p align="center">
	<img src="https://github.com/amaitou/1337/blob/master/Cursus/Images/Cub3d_Team.png" height=80>
	<h3 align="center">
	<a href="https://www.linkedin.com/in/amaitou/">amait-ou</a>
	<span> · </span>
	<a href="https://www.linkedin.com/in/youssef-khalil-21b747269/">ykhalil-</a>
	</h3>
</p>

- ### Project Features
	- `Mini Map System`
	- `Wall Coalition`
	- `Rays hitting the walls to see where your angle is`
	- `3D Graphic with default textures (can be changed based on your choice)`
	---
- ### Collaborators
	This project must be done by two students so, I would welcome this article by thanking my peer [Youssef Khalil](https://github.com/Referee95) since he was my collaborator throughout this project
---

# What is Raycasting?

`Raycasting` is a computer graphics technique used to render two-dimensional or three-dimensional scenes by simulating the path of rays as they interact with objects in a virtual environment. It is commonly used in video games and computer graphics for tasks such as rendering 3D graphics, detecting collisions between objects, and implementing vision or line-of-sight calculations for characters and cameras.

Here's a basic overview of how *raycasting* works:

- `Emitter` -> *Raycasting* starts with an emitter, which is typically a point in space representing the starting point of a ray. In a 2D context, this might be a point on the screen or a specific location in the virtual world. In a 3D context, it could be the position of a camera or any other point in space.
---
- `Rays` -> Rays are projected from the emitter in various directions. These rays represent the paths of light or vision. In 2D *raycasting*, these rays are typically cast in a grid pattern across the screen, while in 3D *raycasting*, they can be cast in a cone or other patterns depending on the application.
---
- `Intersections` -> As rays travel through the virtual environment, they may intersect with objects or surfaces. When an intersection occurs, the *raycasting* algorithm can calculate various properties, such as the distance to the object, the surface normal at the point of intersection, and the material properties of the object.
---
- `Rendering`: *Raycasting* can be used for rendering by determining the color and intensity of the light that reaches the camera or observer at each pixel or sample point. This is done by tracing rays from the camera through the pixel positions and calculating the intersections with objects in the scene. The color and shading of each pixel are then determined based on the properties of the objects and the lighting model used.
---
- `Collision Detection` -> In addition to rendering, raycasting is commonly used for collision detection in games and simulations. By casting rays from a character's position in the direction of movement, it's possible to detect if the character will collide with any objects in its path.
---

Raycasting is computationally efficient for certain applications, particularly for 2D rendering and basic collision detection, because it only traces rays in specific directions rather than simulating the entire path of light as in ray tracing. However, it has limitations and may not provide the same level of visual realism as more advanced rendering techniques like ray tracing.

---

# Installation

Firstly, try to clone the game using the git command:

```sh
git clone https://github.com/amaitou/Cub3d
```
---
Then `cd` to the folder `Cub3D` and cmake the mlx library (it comes included with the repository)

```sh
cd Cub3d
cd mlx
cmake -B build
cmake --build build -j4
cd ../
```
---
Once you have all of these requirements done, start making the game by using each of these two commands according to what you want (mandatory bonus part)

```sh
# Making mandatory part
make
# Making bonus part
make bonus
```
---
After making the game just type

```sh
# ./cub3D map_path (you will find them in ./maps/valid_maps/)
# - ./cub3d -> for mandatory part
# - ./cub3d_bonus for bonus part
./cub3D ./maps/valid_maps/chaotic.cub
# or just type :
make run # it will run a default map for mandatory part
make run_bonus # it will run a default map for the bonus part
```
---
> Enjoy playing and discovering raycasting
---

- # **Contact Me**

* [Twitter][_1]
* [Instagram][_2]

[_1]: https://twitter.com/amait0u
[_2]: https://www.instagram.com/amait0u
