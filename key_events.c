/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:42:46 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/06 04:54:24 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

// Handles zoom functionality for the fractal.
// Parameters:
// - graphics: Pointer to the graphics structure containing fractal data.
// - zoom_factor: Factor by which to zoom in or out.
static void ft_zoom(t_graphics *graphics, double zoom_factor)
{
    double width, height, new_width, new_height;

    // Calculate the current view dimensions in the fractal's coordinate space.
    width = WIDTH / graphics->fractal->zoom;
    height = HEIGHT / graphics->fractal->zoom;

    // Adjust the dimensions based on the zoom factor.
    new_width = width / zoom_factor;
    new_height = height / zoom_factor;

    // Update the fractal's zoom and shift values to maintain center focus.
    graphics->fractal->zoom *= zoom_factor;
    graphics->fractal->shift_x += (width - new_width) / 2.0 / WIDTH;
    graphics->fractal->shift_y += (height - new_height) / 2.0 / HEIGHT;
}

// Handles keyboard input for movement and exiting the program.
// Parameters:
// - keycode: Keycode of the pressed key.
// - graphics: Pointer to the graphics structure containing fractal data.
int ft_key_handler(int keycode, t_graphics *graphics)
{
    double move_step;

    move_step = 0.1 / graphics->fractal->zoom; // Adjust movement step based on zoom level.

    if (keycode == ESC_KEY) // Exit the program.
    {
        mlx_destroy_image(graphics->mlx, graphics->img);
        mlx_destroy_window(graphics->mlx, graphics->win);
        mlx_destroy_display(graphics->mlx);
        free(graphics->mlx);
        exit(0);
    }
    else if (keycode == LEFT_KEY) // Move left.
        graphics->fractal->shift_x -= move_step;
    else if (keycode == RIGHT_KEY) // Move right.
        graphics->fractal->shift_x += move_step;
    else if (keycode == UP_KEY) // Move up.
        graphics->fractal->shift_y -= move_step;
    else if (keycode == DOWN_KEY) // Move down.
        graphics->fractal->shift_y += move_step;

    ft_render_fractal(graphics); // Redraw the fractal after movement.
    return (0);
}

// Handles mouse events for zooming and Julia fractal parameter adjustment.
// Parameters:
// - button: Mouse button pressed.
// - x, y: Mouse position coordinates.
// - graphics: Pointer to the graphics structure containing fractal data.
int ft_mouse_handler(int button, int x, int y, t_graphics *graphics)
{
    (void)x; // Suppress unused parameter warning
    (void)y; // Suppress unused parameter warning

    if (button == MOUSE_SCROLL_UP) // Zoom in.
        ft_zoom(graphics, ZOOM_FACTOR);
    else if (button == MOUSE_SCROLL_DOWN) // Zoom out.
        ft_zoom(graphics, 1.0 / ZOOM_FACTOR);

    ft_render_fractal(graphics); // Redraw the fractal.
    return (0);
}
/*
                             ue$$$$$$$$$e.                                  ,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
                          o$$$P""     "#$$$b                               | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | [ | ] | <-    |
                        d$$$"            ?$$N                             |---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
                      x$$$"               $$$                             | ->| | " | , | . | P | Y | F | G | C | R | L | / | = |  \  |
                     d$$$     .ueeeeeeeeee$$$beeeeeu                      |-----',--',--',--',--',--',--',--',--',--',--',--',--'-----|
                    @$$$     d$            $>      $$                     | Caps | A | O | E | U | I | D | H | T | N | S | - |  Enter |
                   $$$$      $$            $>      4$                     |------'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'--------|
$$$.             .$$$P       $$            $>      4$                     |        | ; | Q | J | K | X | B | M | W | V | Z |          |
?$$$L           z$$$"        $$eeeeeeeeeeee$beeeeeed$                      |------,-',--'--,'---'---'---'---'---'---'---'-,-'---',--,------|
  *$$$e..   .z$$$$"          $$                    4$                     | ctrl |  | alt |                          | alt  |  | ctrl |
    ^#R$$$$$$$*"             $$                    4$                     '------'  '-----'--------------------------'------'  '------'
                             $$                    4$
                             $$                    4$
                             $$                    4$
                             $$                    4$
                             $$                    4$
                             9$                    d$
                              $k                   $F
                               $N                z$"
                                '*$o.         .e$"
                                    "#*$$$$P*""

*/
