# 🌀 Fract-ol

**Fract-ol** is a project from the 42 curriculum designed to introduce students to the fundamentals of graphics programming through the rendering of mathematical fractals using the **MiniLibX** library.

## 📌 Objective

The primary goal of this project is to generate and display fractal sets, specifically:

- **Mandelbrot Set**
- **Julia Set**

Users can interact with the fractals by zooming in/out and navigating the fractal space using keyboard and mouse inputs.

## 🧑‍💻 Features

- Render **Mandelbrot** and **Julia** fractals.
- Zoom in and out with mouse scroll functionality.
- Navigate the fractal space using the arrow keys.
- Dynamically adjust Julia set parameters with mouse movement (Julia Set only).
- Close the application using the `ESC` key or the window's close button.

## 🧰 Technologies

- **Programming Language**: C
- **Graphics Library**: MiniLibX
- **Supported Operating Systems**: macOS or Linux (with X11)

## ⚙️ Installation & Usage

### Prerequisites

Ensure that you have the required dependencies installed on your system:
- **MiniLibX** library
- **X11** libraries (for Linux users)

### Steps to Build and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/3tmvne/fractol.git
   cd fractol
   ```

2. Build the project using `make`:
   ```bash
   make
   ```

3. Run the program with one of the following options:
   - Mandelbrot Set:
     ```bash
     ./fractol mandelbrot
     ```
   - Julia Set:
     ```bash
     ./fractol julia -0.8 0.156
     ```

4. Interact with the fractal:
   - Use the arrow keys to navigate.
   - Scroll with the mouse to zoom in and out.
   - Use the `ESC` key to exit.

## 🎮 Controls

| Action                    | Input                            |
|---------------------------|----------------------------------|
| Zoom In/Out              | Mouse Scroll                    |
| Navigate Fractal Space   | Arrow Keys                      |
| Adjust Julia Parameters  | Mouse Movement (Julia Set only) |
| Exit the Program          | ESC Key or Close Window         |

## 🛠️ Development

This project was developed as part of the curriculum at **42 School**. It serves as an introduction to graphical programming, focusing on mathematical visualizations and user interaction.
