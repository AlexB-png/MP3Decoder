#include "window.h"
#include <QPushButton>
#include <QApplication>

Window::Window(QWidget *parent) :
    QWidget(parent)
{
    // Set size of the window
    setFixedSize(600, 600);

    button = new QPushButton("Hello", this);
    button->setGeometry(10,10,160,30);
    button->setCheckable(true);

    connect(button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
    connect(this, SIGNAL (CounterReached()), QApplication::instance(), SLOT (quit()));

    button_count = 0;
}

void Window::slotButtonClicked(bool checked)
{
    if (checked) {
        button->setText("Click Again To Quit!");
    } else {
        button->setText("Pressed!");
    }

    button_count ++;

    if (button_count == 2) {
        emit CounterReached();
    }
}

