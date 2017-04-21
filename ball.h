#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>
#include <QString>

class ball {

  public:
    ball();
    ball(QString);
    ~ball();

  public:
    void resetState();
    void autoMove();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();
    bool isDestroyed();
    void setDestroyed(bool);

  private:
    int xdir;
    int ydir;
    int randX;
    int randY;
    bool destroyed;
    QImage image;
    QRect rect;
    static const int INITIAL_X = 810;
    static const int INITIAL_Y = 750;
    static const int RIGHT_EDGE = 800;
    static const int LEFT_EDGE = 0;
    static const int TOP_EDGE = 0;
    static const int BOTTOM_EDGE = 480;
};

#endif // BALL_H
