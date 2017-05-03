#include <QApplication>
#include "dodgeball.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  dodgeball window;
  window.setFixedSize(1280, 720);
  window.setWindowTitle("BG Dining Dodgeball");
  window.showMaximized();

  return app.exec();
}
