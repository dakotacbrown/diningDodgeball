#include "player.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>

player::player(){

    xdir = 1;
    ydir = -1;

    image.load(":/resources/character.png");

    rect = image.rect();
    resetState();
}

player::~player() {

}

void player::move() {
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

void player::resetState() {
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

void player::setXDir(int x) {
    xdir = x;
}

void player::setYDir(int y) {
    ydir = y;
}

int player::getXDir() {
    return xdir;
}

 int player::getYDir() {
     return ydir;
}

QRect player::getRect(){
    return rect;
}

QImage & player::getImage() {
    return image;
}

