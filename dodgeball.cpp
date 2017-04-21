#include <QPainter>
#include <QApplication>
#include "dodgeball.h"

dodgeball::dodgeball(QWidget *parent)
    : QWidget(parent){

  x = 0;
  round = 1;
  score = 0;
  gameOver = false;
  gameWon = false;
  paused = false;
  gameStarted = false;
  banana = new ball(":/resources/banana.png");
  character = new player();

}

dodgeball::~dodgeball(){

 delete character;
 delete banana;
}

void dodgeball::paintEvent(QPaintEvent *e){

  Q_UNUSED(e);

  QPainter painter(this);

  if (gameOver){

    finishGame(&painter, "Game lost");

  } else if(gameWon){

    finishGame(&painter, "Victory");
  } else{

    drawObjects(&painter);
  }
}

void dodgeball::finishGame(QPainter *painter, QString message){

  QFont font("Courier", 15, QFont::DemiBold);
  QFontMetrics fm(font);
  int textWidth = fm.width(message);

  painter->setFont(font);
  int h = height();
  int w = width();

  painter->translate(QPoint(w/2, h/2));
  painter->drawText(-textWidth/2, 0, message);
}

void dodgeball::drawObjects(QPainter *painter){

  painter->drawImage(character->getRect(), character->getImage());
  painter->drawImage(banana->getRect(), banana->getImage());
}

void dodgeball::timerEvent(QTimerEvent *e){

  Q_UNUSED(e);

  moveObjects();
  checkCollision();
  repaint();
}

void dodgeball::moveObjects(){

  banana->autoMove();
  character->move();
}

void dodgeball::mouseMoveEvent(QMouseEvent *e){

    character->setXDir(e->pos().x());
    character->setYDir(e->pos().y());

}

void dodgeball::keyPressEvent(QKeyEvent *e){

    switch (e->key()) {
    case Qt::Key_P:

        pauseGame();
        break;

    case Qt::Key_Space:

        startGame();
        break;

    case Qt::Key_Escape:

        qApp->exit();
        break;

    default:
        QWidget::keyPressEvent(e);
    }
}

void dodgeball::startGame(){

  if (!gameStarted){
    banana->resetState();
    character->resetState();

    gameOver = false;
    gameWon = false;
    gameStarted = true;
    timerId = startTimer(DELAY);
  }
}

void dodgeball::pauseGame(){

  if (paused){

    timerId = startTimer(DELAY);
    paused = false;
  } else{

    paused = true;
    killTimer(timerId);
  }
}

void dodgeball::stopGame(){

  killTimer(timerId);
  gameOver = true;
  gameStarted = false;
}

void dodgeball::victory(){

  killTimer(timerId);
  gameWon = true;
  gameStarted = false;
}

void dodgeball::checkCollision(){

  if(!banana->isDestroyed()){
      if ((banana->getRect()).intersects(character->getRect())){
          score += 100;
          banana->setDestroyed(true);
      }
  }
  else if(banana->isDestroyed()){
      delete banana;
  }
}

