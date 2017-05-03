#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>
#include <QString>


class ball {

  public:
    ball();
    ball(QString, int);
    ~ball();

  public:
    void resetState();
    void autoMove();
    QRect getRect();
    QImage & getImage();
    bool isDestroyed();
    void setDestroyed(bool);
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();

  private:
    QImage image;
    int xdir;
    int ydir;
    QRect rect;
    bool destroyed;
    float randX, randY;


    static const int INITIAL_X = 1280;
    int INITIAL_Y;
    static const int RIGHT_EDGE = 1280;
    static const int LEFT_EDGE = 0;
    static const int TOP_EDGE = 0;
    static const int BOTTOM_EDGE = 720;
};

#endif // BALL_H
