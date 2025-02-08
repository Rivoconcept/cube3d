# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void init()
{
    glClearColor(0.3,0.3,0.3,0);
    gluOrtho2D(0,1024,512,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 512);
    glutCreateWindow("42_cube3d_project");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return (0);
}