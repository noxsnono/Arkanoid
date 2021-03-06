/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 22:11:38 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 22:11:56 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJET_H
# define PROJET_H

# include "../glfw/include/GLFW/glfw3.h"
# include "../libft/includes/libft.h"

# define LOG_PATH		"logs/debugg.log"
# define SPEED			70000

# define MAP_X			50
# define MAP_Y			45

# define WIN_WIDHT		1250
# define WIN_HEIGHT		540

# define BLOCK_WIDTH	25
# define BLOCK_HEIGHT	12

# define WALL			'#'
# define SIMPLE			'-'
# define OBSTACLE		'@'
# define EMPTY			' '
# define PLAYER			'_'
# define SPEC			'0'
# define BALL			'o'
# define LEFT			1
# define RIGHT			2

typedef struct			s_case
{
	char				type;
	int					state;
}						t_case;

typedef struct			s_ball
{
	int					posx;
	int					posy;
	int					dir;
}						t_ball;

typedef struct			s_data
{

	int					fd_log;
	char				**p_av;
	int					i_args;
	int					fd_level;
	int					level;
	t_case				**map;
	t_ball				ball;
	int					player_pos;
	int					run;
	int					pause;
	int					score;

	unsigned short int	op_log;
	GLFWwindow			*windows;
}						t_data;

int						error(char const *str);
int						init_start(t_data **d, int ac, char **av);
int						open_log(t_data *d);
t_data					*get_data(void);
void					w_log(char const *str);

int						get_level_file(t_data *d);
int						fill_map(t_data *d);
int						init_map(t_data *d);
void					move(t_data *d, int move);
void					game(t_data *d);
int						run_the_game(t_data *d);
void					exit_free(void);
int						collide(t_data *d);
int						adv_move(t_data *d, int side);
void					do_dmg(t_data *d, int newdir, int posx, int posy);
void					basic_move(t_data *d);

/*
** Render glfw
*/
int						render_init(t_data *d);
void					render_draw(t_data *d);
void					render_keyboard(GLFWwindow *window, int key,
							int scancode, int action, int mods);
void					render_close(t_data *d);
void					render_draw_case(t_data *d, int life,
							int posx, int posy);
void					render_draw_player(t_data *d, int posx, int posy);
void					render_score(t_data *d);

#endif
