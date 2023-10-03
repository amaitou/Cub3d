from os import system
invalid_maps = ["./maps/valid_maps/chaotic.cub","./maps/valid_maps/maze.cub","./maps/valid_maps/eagle.cub","./maps/valid_maps/works.cub","./maps/valid_maps/library.cub","./maps/valid_maps/subject.cub","./maps/valid_maps/random.cub","./maps/valid_maps/whitespaces.cub","./maps/valid_maps/enchanted_passage.cub","./maps/valid_maps/square.cub","./maps/valid_maps/creepy.cub","./maps/valid_maps/player_top.cub"]
for i in invalid_maps:
	print(f"[-] {i}")
	system(f"./cub3D {i}")
