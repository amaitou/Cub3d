---
![sPP2N](https://github.com/amaitou/Cub3d/assets/49293816/04119940-8172-4bd0-b0af-117769653c94)

---
# Cub3d
"cub3D" is a popular project that involves creating a simple 3D game engine using the C programming language. This project is often used to teach students various aspects of computer graphics and *raycasting*.

The project consists of two parts, the first one is the `Mandatory Part` where you will build only a 3D game with no further features, whereas the bonus part includes the mandatory part plus a minimap system and the behavior of changing the rotation angle based on the mouse movements additionally to the wall coalition.

---
- ### Project Features
	- `Mini Map System`
	- `Wall Coalition`
	- `Rays hitting the walls to see where your angle is`
	- `3D Graphic with default textures (can be changed based on your choice)`
	---
- ### Collaborators
	This project must be done by two students so, I would welcome this article by thanking my peer [Youssef Khalil](https://github.com/Referee95) since he was my collaborator throughout this project
---

# What is Raycasting ?

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