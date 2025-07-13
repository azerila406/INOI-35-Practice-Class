import random
import subprocess
import os

N = random.randint(3, int(1.5e5))

binary_array = [str(random.randint(0, 1)) for _ in range(N)]

use_long_tree = random.random() < 0.1

generator_name = "long-tree" if use_long_tree else "tree"
generator_path = os.path.join("..", "scripts", generator_name)

try:
    result = subprocess.run(
        [generator_path, str(N)],
        check=True,
        capture_output=True,
        text=True
    )

    print(N)
    print(' '.join(binary_array))
    print(result.stdout.strip())

except FileNotFoundError:
    print(f"Error: {generator_name} not found in Scripts/")
except subprocess.CalledProcessError as e:
    print(f"{generator_name} exited with error code {e.returncode}")
