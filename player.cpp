#include "player.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>

player::player(){

    image.load(":/resources/character.png");

    rect = image.rect();
    resetState();
}

player::~player() {

}

void player::move() {

    QString x = QString::number(mouse.x());
    QString y = QString::number(mouse.y());

    qDebug() << "Mouse x: " + x + " Mouse y: " + y;

    rect.moveTo(mouse.x(),mouse.y());

}

void player::resetState() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

QRect player::getRect() {

  return rect;
}

QImage & player::getImage() {

  return image;
}

