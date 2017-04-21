#include "ball.h"
#include <random>
#include <iostream>

ball::ball() {

}

ball::ball(QString source) {

  xdir = 1;
  ydir = -1;
  randX = qrand() % ((-5 + 1) - -10) + -10;
  randY = qrand() % ((-10 + 1) - -10) + -10;

  image.load(source);

  rect = image.rect();
  resetState();
}

ball::~ball() {

}

bool ball::isDestroyed() {

  return destroyed;
}

void ball::setDestroyed(bool destr) {

  destroyed = destr;
}

void ball::autoMove() {

  rect.translate(xdir, ydir);

  if (rect.left() == LEFT_EDGE) {
      xdir = 1;
  }
  if (rect.right() == RIGHT_EDGE) {
      xdir = -1;
  }
  if (rect.top() == TOP_EDGE) {
      ydir = 1;
  }
  if (rect.bottom() == BOTTOM_EDGE) {
      ydir = -1;
  }
}

void ball::resetState() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

void ball::setXDir(int x) {

  xdir = x;
}

void ball::setYDir(int y) {

  ydir = y;
}

int ball::getXDir() {

  return xdir;
}

int ball::getYDir() {

  return ydir;
}

QRect ball::getRect() {

  return rect;
}

QImage & ball::getImage() {

  return image;
}
