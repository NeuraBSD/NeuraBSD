#include <QApplication>
#include <QWidget>
#include <QPalette>
#include <QColor>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("NeuraBSD CoreSeed - Initializing...");
    window.resize(800, 600);

    // Das NeuraBSD-Blau aus deinem Design-Konzept
    QPalette pal = window.palette();
    pal.setColor(QPalette::Window, QColor("#0a0d10"));
    window.setPalette(pal);
    window.setAutoFillBackground(true);

    window.show();
    return app.exec();
}
