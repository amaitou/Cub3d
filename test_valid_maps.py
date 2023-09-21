
from os import system
x = ["creepy.cub", "hole.cub", "library.cub", "maze.cub", "random.cub", "square.cub", "subject.cub", "works.cub"]
for i in x:
    print(f"[*]{i}")
    system(f"./cub3D ./maps/valid_maps/{i}")

