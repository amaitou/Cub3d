import os
x = ["consecutive_nl.cub",  "empty_file.cub", "invalid_colors.cub", "invalid_texture_format.cub", "invalid_textures.cub", "map_first.cub", "missing_colors.cub", "missing_map.cub", "missing_textures.cub", "rgb_range.cub"]
for i in x:
    print(f"[*] {i}", end = "\n")
    os.system(f"./cub3D ./maps/invalid_maps/{i}")
