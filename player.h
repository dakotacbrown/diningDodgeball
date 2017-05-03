#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QCursor>

class player{

public:
      player();
      ~player();
      void resetState();
      void move();
      QRect getRect();
      QImage & getImage();
      QPoint mouse;

private:

    QImage image;
    QRect rect;
    static const int INITIAL_X = 0;
    static const int INITIAL_Y = 240;
    static const int RIGHT_EDGE = 1280;
    static const int LEFT_EDGE = 0;
    static const int TOP_EDGE = 0;
    static const int BOTTOM_EDGE = 720;

};


#endif // PLAYER_H
