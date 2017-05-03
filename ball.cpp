#include "ball.h"
#include <random>
#include <iostream>

ball::ball() {

}

ball::ball(QString source, int round) {

    image.load(source);
    rect = image.rect();

    INITIAL_Y = qrand() % ((620 + 1) - 100) + 100;
    int x = 0;
    int y = 0;

    if(round == 1){
        x = qrand() % ((-5 + 1) - -10) + -10;
        y = qrand() % ((10 + 1) - -10) + -10;
    }
    if(round == 2){
        x = qrand() % ((-10 + 1) - -15) + -15;
        y = qrand() % ((15 + 1) - -15) + -15;
    }
    if(round == 3){
        x = qrand() % ((-15 + 1) - -20) + -20;
        y = qrand() % ((20 + 1) - -20) + -20;
    }

    xdir = x;
    ydir = y;

    destroyed = false;

    randY = .5;
    randX = .5;


    //randX = rand() % 1;
    //randY = rand() % 1;
    //INITIAL_Y = randY;
    //bVelocity.setX(randX);
    //bVelocity.setY(randY);
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

    if (rect.top() <= 0 || rect.bottom() >= BOTTOM_EDGE)
        ydir = -1*ydir;
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
