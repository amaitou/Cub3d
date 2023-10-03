from os import system
invalid_maps = ["./maps/invalid_maps/consecutive_nl.cub","./maps/invalid_maps/empty_file.cub","./maps/invalid_maps/missing_map.cub","./maps/invalid_maps/corners_with_zeros.cub","./maps/invalid_maps/missing_colors.cub","./maps/invalid_maps/invalid_texture_format.cub","./maps/invalid_maps/player_besides_space.cub","./maps/invalid_maps/invalid_colors.cub","./maps/invalid_maps/invalid_textures.cub","./maps/invalid_maps/rgb_range.cub","./maps/invalid_maps/wall_with_zeros.cub","./maps/invalid_maps/missing_textures.cub","./maps/invalid_maps/map_first.cub"]
for i in invalid_maps:
	system(f"./cub3D {i}")
