#ifndef ENTERSIGN_H
#define ENTERSIGN_H

#include <QWidget>

namespace Ui {
class EnterSign;
}

class EnterSign : public QWidget
{
    Q_OBJECT

public:
    explicit EnterSign(QWidget *parent = 0);
    ~EnterSign();

    QWidget *m_wgtVideo;


private slots:
    void on_pbtn_enter_clicked();

    void on_pbt_zhuce_clicked();

    void on_pBtn_for_clicked();

private:
    Ui::EnterSign *ui;
};

#endif // ENTERSIGN_H
