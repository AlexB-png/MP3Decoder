#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;

class Window : public QWidget
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = nullptr);
    signals:
        void CounterReached();
    private slots:
        void slotButtonClicked(bool checked);
    private:
        int button_count = 0;
        // Add new elements classes here //
        QPushButton *button;
};

#endif // WINDOW_H
