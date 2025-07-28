# Dune2 Remake

Dune2 Remake is a real-time strategy (RTS) game inspired by the classic Dune II. This project utilizes the raylib library for graphics and audio, providing a simple and efficient way to create games in C++.

## Project Structure

```
Dune2Remake
├── src
│   ├── main.cpp		# Entry point of the application
│   ├── game.cpp		# Game class implementation
│   ├── Input.cpp	   # User Input handling
│   └── utils.cpp	   # Utility functions
├── include
│   ├── Game.h		  # Game class header
│   ├── Input.h		 # Input handling functions header
│   └── utils.h		 # Utility functions header
├── assets
│   ├── sprites		 # Sprite images
│   ├── audio		   # Audio files for sound effects and music
│   └── maps			# Map files defining game levels
├── build.bat		   # Batch file for compiling the project
└── README.md		   # Project documentation
```

## Setup Instructions

1. **Clone the repository**:
   ```
   git clone <repository-url>
   cd Dune2Remake
   ```

2. **Install raylib**:
   Follow the instructions on the raylib website to install the library on your system.

3. **Compile the project**:
   Run the `build.bat` file to compile the project. This will link the necessary libraries, including raylib.

4. **Run the game**:
   After compilation, execute the generated binary to start playing the game.

## Gameplay

In Dune2 Remake, players will manage resources, build structures, and command units to defeat their opponents. The game features various levels and challenges, inspired by the original Dune II gameplay mechanics.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests to improve the game.