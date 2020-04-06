//
// Created by Hanyi Wang on 4/5/20.
//

#ifndef PROJECT3_ALARMHANDLER_H
#define PROJECT3_ALARMHANDLER_H

#include "RoutingProtocolImpl.h"

class AlarmHandler {
public:
    AlarmHandler() {
        pingpong_alarm_data = (eAlarmType *) malloc(sizeof(char));
        expire_alarm_data = (eAlarmType *) malloc(sizeof(char));
        dv_update_alarm_data = (eAlarmType *) malloc(sizeof(char));
        ls_update_alarm_data = (eAlarmType *) malloc(sizeof(char));

        *pingpong_alarm_data = PINGPONG_ALARM;
        *expire_alarm_data = EXPIRE_ALARM;
        *dv_update_alarm_data = DV_UPDATE_ALARM;
        *ls_update_alarm_data = LS_UPDATE_ALARM;
    }

    ~AlarmHandler() {
        free(pingpong_alarm_data);
        free(expire_alarm_data);
        free(dv_update_alarm_data);
        free(ls_update_alarm_data);
    }

    void init_alarm(Node * sys, RoutingProtocol * r) {
        sys->set_alarm(r, 10*SECOND, (void*) pingpong_alarm_data);
        sys->set_alarm(r, 30*SECOND, (void*) dv_update_alarm_data);
        sys->set_alarm(r, 1 *SECOND, (void*) expire_alarm_data);
    }

private:
    eAlarmType * pingpong_alarm_data;
    eAlarmType * dv_update_alarm_data;
    eAlarmType * ls_update_alarm_data;
    eAlarmType * expire_alarm_data;
};

#endif //PROJECT3_ALARMHANDLER_H
