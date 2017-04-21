#include <QApplication>
#include "dodgeball.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  dodgeball window;

  window.resize(800, 480);
  window.setWindowTitle("BG Dining Dodgeball");
  window.show();

  return app.exec();
}
