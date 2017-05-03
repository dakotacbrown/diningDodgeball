#include <QPainter>
#include <QApplication>
#include "dodgeball.h"
#include <random>

dodgeball::dodgeball(QWidget *parent)
    : QWidget(parent){

  x = 0;
  round = 1;
  score = 0;
  gameOver = false;
  gameWon = false;
  paused = false;
  gameStarted = false;
  character = new player();

  if(round >= 1){
      for(int i = 0; i < 10; i++)
        banana[i] = new ball(":/resources/banana.png", round);
      for(int i = 0; i < 10; i++)
        soda[i] = new ball(":/resources/r1ball.png", round);
      if(round >= 2){
          for(int i = 0; i < 8; i++)
            orange[i] = new ball(":/resources/orange.png", round);
          for(int i = 0; i < 8; i++)
            chips[i] = new ball(":/resources/r2ball.png", round);
          if(round >= 3){
              for(int i = 0; i < 6; i++)
                raspberry[i] = new ball(":/resources/raspberry.png", round);
              for(int i = 0; i < 6; i++)
                candy[i] = new ball(":/resources/r3ball.png", round);
          }
      }
  }

}

dodgeball::~dodgeball(){
    delete character;

    if(round >= 1){
        for(int i = 0; i < 10; i++)
            delete banana[i];
        for(int i = 0; i < 10; i++)
          delete soda[i];

        if(round >= 2){
            for(int i = 0; i < 8; i++)
              delete orange[i];
            for(int i = 0; i < 8; i++)
               delete chips[i];

            if(round >= 3){
                for(int i = 0; i < 6; i++)
                  delete raspberry[i];
                for(int i = 0; i < 6; i++)
                  delete candy[i];
            }
        }
    }




}

void dodgeball::paintEvent(QPaintEvent *e){

  Q_UNUSED(e);

  QPainter painter(this);

  if (gameOver){

    finishGame(&painter, "Game Over!");

  } else if(gameWon){

    finishGame(&painter, "High Score!");
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

    if(round >= 1){
        for(int i = 0; i < 10; i++)
            if(!banana[i]->isDestroyed())
                painter->drawImage(banana[i]->getRect(), banana[i]->getImage());
        for(int i = 0; i < 10; i++)
            if(!soda[i]->isDestroyed())
                painter->drawImage(soda[i]->getRect(), soda[i]->getImage());
        if(round >= 2){
            for(int i = 0; i < 8; i++)
                if(!orange[i]->isDestroyed())
                    painter->drawImage(orange[i]->getRect(), orange[i]->getImage());
            for(int i = 0; i < 8; i++)
                if(!chips[i]->isDestroyed())
                    painter->drawImage(chips[i]->getRect(), chips[i]->getImage());
            if(round >= 3){
                for(int i = 0; i < 6; i++)
                    if(!raspberry[i]->isDestroyed())
                        painter->drawImage(raspberry[i]->getRect(), raspberry[i]->getImage());
                for(int i = 0; i < 6; i++)
                    if(!candy[i]->isDestroyed())
                        painter->drawImage(candy[i]->getRect(), candy[i]->getImage());
            }
        }
    }
}

void dodgeball::timerEvent(QTimerEvent *e){

  Q_UNUSED(e);

    if(score >= 7500)
        round = 2;
    if(score >= 15000)
        round = 3;


  moveObjects();
  checkCollision();
  repaint();
}

void dodgeball::moveObjects(){

      character->mouse = mapFromGlobal(QCursor::pos());

      if(round >= 1){
          for(int i = 0; i < 10; i++)
              if(!banana[i]->isDestroyed())
                  banana[i]->autoMove();
          for(int i = 0; i < 10; i++)
              if(!soda[i]->isDestroyed())
                  soda[i]->autoMove();

           if(round >= 2){
               for(int i = 0; i < 8; i++)
                   if(!orange[i]->isDestroyed())
                       orange[i]->autoMove();
               for(int i = 0; i < 8; i++)
                   if(!chips[i]->isDestroyed())
                       chips[i]->autoMove();

               if(round >= 3){
                   for(int i = 0; i < 6; i++)
                       if(!raspberry[i]->isDestroyed())
                           raspberry[i]->autoMove();
                   for(int i = 0; i < 6; i++)
                       if(!candy[i]->isDestroyed())
                           candy[i]->autoMove();
               }
           }
      }

    character->move();

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

      if(round >= 1){
          for(int i = 0; i < 10; i++)
              if(!banana[i]->isDestroyed())
                  banana[i]->resetState();
          for(int i = 0; i < 10; i++)
              if(!soda[i]->isDestroyed())
                  soda[i]->resetState();

          if(round >= 2){
              for(int i = 0; i < 8; i++)
                  if(!orange[i]->isDestroyed())
                      orange[i]->resetState();
              for(int i = 0; i < 8; i++)
                  if(!chips[i]->isDestroyed())
                      chips[i]->resetState();

              if(round >= 3){
                  for(int i = 0; i < 6; i++)
                      if(!raspberry[i]->isDestroyed())
                          raspberry[i]->resetState();
                  for(int i = 0; i < 6; i++)
                      if(!candy[i]->isDestroyed())
                          candy[i]->resetState();
              }
          }
      }
    character->resetState();

    gameOver = false;
    gameWon = false;
    gameStarted = true;
    timerId = startTimer(DELAY);
  }

  if(round >= 1){
      for(int i = 0; i < 10; i++)
        banana[i] = new ball(":/resources/banana.png", round);
      for(int i = 0; i < 10; i++)
        soda[i] = new ball(":/resources/r1ball.png", round);
      if(round >= 2){
          for(int i = 0; i < 8; i++)
            orange[i] = new ball(":/resources/orange.png", round);
          for(int i = 0; i < 8; i++)
            chips[i] = new ball(":/resources/r2ball.png", round);
          if(round >= 3){
              for(int i = 0; i < 6; i++)
                raspberry[i] = new ball(":/resources/raspberry.png", round);
              for(int i = 0; i < 6; i++)
                candy[i] = new ball(":/resources/r3ball.png", round);
          }
      }
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


    if(round >= 1){
        for(int i = 0; i < 10; i++){
            if(!banana[i]->isDestroyed())
                if ((banana[i]->getRect()).intersects(character->getRect())){
                    score += 100;
                    banana[i]->setDestroyed(true);
                    banana[i] = new ball(":/resources/banana.png", round);
                }

                if(banana[i]->getRect().left() < 0){
                    banana[i]->setDestroyed(true);
                    banana[i] = new ball(":/resources/banana.png", round);
                }
        }

        for(int i = 0; i < 10; i++){
            if(!soda[i]->isDestroyed())
                if ((soda[i]->getRect()).intersects(character->getRect())){
                    score -= 100;
                    soda[i]->setDestroyed(true);
                    soda[i] = new ball(":/resources/r1ball.png", round);
                }

                if(soda[i]->getRect().left() < 0){
                    soda[i]->setDestroyed(true);
                    soda[i] = new ball(":/resources/r1ball.png", round);
                }
        }
        if(round >= 2){
            for(int i = 0; i < 8; i++){
                if(!orange[i]->isDestroyed())
                    if ((orange[i]->getRect()).intersects(character->getRect())){
                        score += 200;
                        orange[i]->setDestroyed(true);
                        orange[i] = new ball(":/resources/orange.png", round);
                    }

                    if(orange[i]->getRect().left() < 0){
                        orange[i]->setDestroyed(true);
                        orange[i] = new ball(":/resources/orange.png", round);
                    }
            }
            for(int i = 0; i < 8; i++){
                if(!chips[i]->isDestroyed())
                    if ((chips[i]->getRect()).intersects(character->getRect())){
                        score += 200;
                        chips[i]->setDestroyed(true);
                        chips[i] = new ball(":/resources/r2ball.png", round);
                    }

                    if(chips[i]->getRect().left() < 0){
                        chips[i]->setDestroyed(true);
                        chips[i] = new ball(":/resources/r2ball.png", round);
                    }
            }
            if(round >=3){
                for(int i = 0; i < 6; i++){
                    if(!raspberry[i]->isDestroyed())
                        if ((raspberry[i]->getRect()).intersects(character->getRect())){
                            score += 300;
                            raspberry[i]->setDestroyed(true);
                            raspberry[i] = new ball(":/resources/raspberry.png", round);
                        }

                        if(raspberry[i]->getRect().left() < 0){
                            raspberry[i]->setDestroyed(true);
                            raspberry[i] = new ball(":/resources/raspberry.png", round);
                        }
                }
                for(int i = 0; i < 6; i++){
                    if(!candy[i]->isDestroyed())
                        if ((candy[i]->getRect()).intersects(character->getRect())){
                            score += 100;
                            candy[i]->setDestroyed(true);
                            candy[i] = new ball(":/resources/r3ball.png", round);
                        }

                        if(candy[i]->getRect().left() < 0){
                            candy[i]->setDestroyed(true);
                            candy[i] = new ball(":/resources/r3ball.png", round);
                        }
                }
            }
        }
    }
}

