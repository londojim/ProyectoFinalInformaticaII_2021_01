#include<QApplication>
#include<Game.h>

#include <QApplication>

//Creamos un objeto tipo Game, que es el que contendrá la escena del juego
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game-> show();
    game->menu();

    return a.exec();
}
