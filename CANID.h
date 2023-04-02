struct RequestCommand{
    int ID; /*Wheel Being Requested*/
    //int DATA;
    int FRAME; /*Frame Being Requested*/

};

struct MotorControlFrame_0{
    int ID;
    int DATA;
    int BATT_V;
    int BATT_C;
    int BATT_C_DIRECTION;
    int MOTOR_C_PEAK_AVERAGE;
    int FET_TEMP;
    int MOTOR_ROTATING_SPEED;
    int PWM_DUTY;
    int LEAD_ANGLE;
};

struct MotorControlFrame_1{
    int ID;
    int DATA;
    int POWER_MODE;
    int MOTOL_CTRL_MODE;
    int ACCEL_POS;
    int REGEN_VR_POS;
    int DIGIT_SW_POS;
    int OUTPUT_TARGET;
    int DRIVE_ACTION_STATUS;
    int REGEN_STATUS;
};

struct MotorControlFrame_2{
    int ID;
    int DATA;
    int ANALOG_SENSOR_ERR;
    int MOTOR_C_SENSOR_U_ERR;
    int MOTOR_C_SENSOR_W_ERR;
    int FET_THERMISTOR_ERR;
    int BATTERY_V_SENSOR_ERR;
    int BATTERY_C_SENSOR_ERR;
    int BATTERY_C_SENSOR_ADJUST_ERR;
    int MOTOR_C_SENSOR_ADJUST_ERR;
    int ACCEL_POS_ERR;
    int CONTROLLER_V_SENSOR_ERR;
    int POWER_SYSTEM_ERR;
    int OVER_CURRENT_ERR;
    int OVER_VOLTAGE_ERR;
    int OVER_CURRENT_LIMIT;
    int MOTOR_SYSTEM_ERR;
    int MOTOR_LOCK;
    int HALL_SENSOR_SHORT;
    int HALL_SENSOR_OPEN;
    int OVER_HEAT_LVL;
};


struct RequestCommand request_command(int ID, int DATA){
    struct RequestCommand can;
    can.ID = ID;
    //can.DATA = DATA;
    can.FRAME = DATA & 7; 
    return(can);
}
struct MotorControlFrame_0 init_mcu_frame0(int ID, int DATA){
    struct MotorControlFrame_0 can;
    can.ID = ID;
    can.DATA = DATA;
    can.BATT_V = DATA & 1023;
    can.BATT_C = DATA & 523264;
    can.BATT_C_DIRECTION = DATA & 524288;
    can.MOTOR_C_PEAK_AVERAGE = DATA & 1072693248; 
    can.FET_TEMP = DATA & 33285996544;
    can.MOTOR_ROTATING_SPEED = DATA & 140703128616960;
    can.PWM_DUTY = DATA & 143974450587500544;
    can.LEAD_ANGLE = DATA & 18302628885633695744; /*Still really bad in hex, keeping it in dec for simplicity*/
    return(can);
}

struct MotorControlFrame_1 init_mcu_frame1(int ID, int DATA){
    struct MotorControlFrame_1 can;
    can.ID = ID;
    can.DATA = DATA;
    can.POWER_MODE = DATA & 1;
    can.MOTOL_CTRL_MODE = DATA & 2;
    can.ACCEL_POS = DATA & 4092;
    can.REGEN_VR_POS = DATA & 258048; 
    can.DIGIT_SW_POS = DATA & 3932160;
    can.OUTPUT_TARGET = DATA & 4290772992;
    can.DRIVE_ACTION_STATUS = DATA & 12884901888;
    can.REGEN_STATUS = DATA & 17179869184; 
    return(can);
}

struct MotorControlFrame_2 init_mcu_frame2(int ID, int DATA){
    struct MotorControlFrame_2 can;
    can.ID = ID;
    can.DATA = DATA;
    can.ANALOG_SENSOR_ERR = DATA & 1;
    can.MOTOR_C_SENSOR_U_ERR = DATA & 2;
    can.MOTOR_C_SENSOR_W_ERR = DATA & 4;
    can.FET_THERMISTOR_ERR = DATA & 8; 
    can.BATTERY_V_SENSOR_ERR = DATA & 32;
    can.BATTERY_C_SENSOR_ERR = DATA & 64;
    can.BATTERY_C_SENSOR_ADJUST_ERR = DATA & 128;
    can.MOTOR_C_SENSOR_ADJUST_ERR = DATA & 256; 
    can.ACCEL_POS_ERR = DATA & 512;
    can.CONTROLLER_V_SENSOR_ERR = DATA & 2048;
    can.POWER_SYSTEM_ERR = DATA & 65536;
    can.OVER_CURRENT_ERR = DATA & 131072;
    can.OVER_VOLTAGE_ERR = DATA & 524288;
    can.OVER_CURRENT_LIMIT = DATA & 2097152;
    can.MOTOR_SYSTEM_ERR = DATA & 16777216;
    can.MOTOR_LOCK = DATA & 33554432;
    can.HALL_SENSOR_SHORT = DATA & 67108864;
    can.HALL_SENSOR_OPEN = DATA & 134217728;
    can.OVER_HEAT_LVL = DATA & 12884901888;
    return(can);
}
