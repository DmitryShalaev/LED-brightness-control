#include "MainWindow.h"

void MainWindow::TimeCheck()
{
    if((QTime::currentTime() >= OnTime) && (QTime::currentTime() <= OffTime)){

        if(!TheTimeHasCome){

            TheTimeHasCome = true;

            qDebug() << "TheTimeHasCome";

            if(MaintainLuxLevelIsChecked && !TurnOffLightIsChecked){

                RequestLuxTimer->start(RequestLuxTime);
            }
        }

    }else{

        qDebug() << "TheTimeNotCome";

        BufSend[1] = ALLPWM;

        BufSend[2] = 0;

        Send();

        RequestLuxTimer->stop();

        TheTimeHasCome = false;

    }
}
