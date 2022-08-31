#ifndef ID_PUSHBUTTON_H
#define ID_PUSHBUTTON_H

#include <QObject>
#include <QPushButton>

// We need the button to transmit its number when pressed
// so this class implements an expansion of QPushButton

class ID_PushButton : public QPushButton
{
    Q_OBJECT
public:
    int m_ID;
    ID_PushButton(int ID, QWidget * parent = nullptr);

//retClickedID and retranslateClick transforms standart clicked() signal into signal with ID
signals:
    void retClickedID(int clID);

public slots:
    void retranslateClick();

};

#endif // ID_PUSHBUTTON_H
