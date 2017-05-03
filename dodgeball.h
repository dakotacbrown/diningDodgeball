#ifndef DODGEBALL_H
#define DODGEBALL_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include "ball.h"
#include "player.h"

class dodgeball : public QWidget {

  Q_OBJECT

  public:
    dodgeball(QWidget *parent = 0);
    ~dodgeball();

  protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    //void mouseMoveEvent(QMouseEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();
    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();
    void roundCheck();

  private:
    int x;
    int timerId;
    int round;
    int score;
    static const int DELAY = 10;
    static const int LEFT_EDGE = 0;
    static const int TOP_EDGE = 0;
    static const int BOTTOM_EDGE = 480;
    player *character;
    ball *banana[10];
    ball *orange[8];
    ball *raspberry[6];
    ball *soda[10];
    ball *chips[8];
    ball *candy[6];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
};


#endif // DODGEBALL_H
