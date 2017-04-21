#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QMouseEvent>

class player{

public:
    player();
    ~player();
    void resetState();
    void move();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

private:
  int xdir;
  int ydir;
  QImage image;
  QRect rect;
  static const int INITIAL_X = 0;
  static const int INITIAL_Y = 240;
  static const int RIGHT_EDGE = 800;
  static const int LEFT_EDGE = 0;
  static const int TOP_EDGE = 0;
  static const int BOTTOM_EDGE = 480;

};


#endif // PLAYER_H
