import os

def rename_c_files_to_bonus(directory_path):
    # Check if the provided path exists and is a directory
    if not os.path.exists(directory_path) or not os.path.isdir(directory_path):
        print(f"Error: '{directory_path}' is not a valid directory.")
        return

    # Recursively traverse the directory and its subdirectories
    for root, _, files in os.walk(directory_path):
        for filename in files:
            if filename.endswith(".c"):
                old_path = os.path.join(root, filename)
                new_filename = filename.replace(".c", "_bonus.c")
                new_path = os.path.join(root, new_filename)
                
                try:
                    os.rename(old_path, new_path)
                    print(f"Renamed '{filename}' to '{new_filename}'")
                except Exception as e:
                    print(f"Error renaming '{filename}': {str(e)}")

if __name__ == "__main__":
    directory_path = input("Enter the directory path: ")
    rename_c_files_to_bonus(directory_path)
