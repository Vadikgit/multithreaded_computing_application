#include "id_pushbutton.h"

ID_PushButton::ID_PushButton(int ID, QWidget * parent) : QPushButton(parent), m_ID{ID}
{
    connect(this,SIGNAL(clicked()),this,SLOT(retranslateClick()));
}

void ID_PushButton::retranslateClick(){
    setEnabled(false);
    emit retClickedID(m_ID);
}
