//**************************************************************************************************
/*!
@file       ItfBoardPinApiUnjo.h
@brief      General layer struct
@note       IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED
@version    1.0.0
*/
//**************************************************************************************************

#ifndef  __ITFBOARDPINAPIUNJO__
    #define __ITFBOARDPINAPIUNJO__

    // System value
    typedef struct
    {
        TBoolean   boUpdate;                      //!< Update flag
        TBoolean   boFresh;                       //!< Fresh flag
        EPinStatus eSta;                          //!< Pin status
        TUint16    u16Val;                        //!< Pin value
    }TPinSysVal;

    // System pin list
    typedef struct
    {
        TPinSysVal tBattery_V;                    //!< Virtual Battery Pin
        TPinSysVal tK15Status_V;                  //!< K15 Pin Analog
        TPinSysVal tK15Status_D;                  //!< K15 Pin Digital
        TPinSysVal tPowerStageEnable;             //!< Virtual Power State Pin
        TPinSysVal tTemperatur_K;                 //!< Virtual Temperature Pin
        TPinSysVal tReferenc_V;                   //!< Virtual Reference Pin
        TPinSysVal tTemperatur_BC;                //!< Virtual Temperature Pin
        TPinSysVal tTemperatur_BD;                //!< Virtual Temperature Pin
        TPinSysVal tTemperatur_IGBT;              //!< Virtual Temperature Pin
        TPinSysVal tTemperatur_MOTOR;             //!< Virtual Temperature Pin
        TPinSysVal tBAT_TRM30;                    //!< Virtual Reference Pin
        TPinSysVal tVBSSNS;                       //!< Virtual Feedback Pin
        TPinSysVal tREF_24V;                      //!< Virtual Reference Pin
        TPinSysVal tREF_3V3;                      //!< Virtual Reference Pin
        TPinSysVal tDC_LNK_V;                     //!< Virtual Link Pin
        TPinSysVal tPHS_CUR_U;                    //!< Virtual Phase Pin
        TPinSysVal tPHS_CUR_V;                    //!< Virtual Phase Pin
        TPinSysVal tPHS_CUR_W;                    //!< Virtual Phase Pin
        TPinSysVal tSTO_1;                        //!< Virtual Safe Torque Pin
        TPinSysVal tSTO_2;                        //!< Virtual Safe Torque Pin
        TPinSysVal tSTO_OTE;                      //!< Virtual Safe Torque Pin
        TPinSysVal tHVIL_IN;                      //!< Virtual HVIL In Pin
        TPinSysVal tHVIL_OUT;                     //!< Virtual HVIL Out Pin
        TPinSysVal tHVIL_CUR;                     //!< Virtual HVIL Current
        TPinSysVal tSPWR5V0;                      //!< Virtual Sensor Supply Pin
        TPinSysVal tSPWRADJ;                      //!< Virtual Sensor Supply Pin

    }TSysPinLast;

    //! Pin Input
    typedef enum
    {
         PININ_NA,                                //!< Type: [-]      Not available
         PININ_ERR,                               //!< Type: [-]      Pin Init Error
         PININ_STA,                               //!< Type: [DEF]    status
         PININ_DIN,                               //!< Type: [0/1]    Digital input
         PININ_VIN,                               //!< Type: [mV]     Voltage input
         PININ_RES,                               //!< Type: [R]      Resistive configuration
         PININ_CIN,                               //!< Type: [mA]     Current input
         PININ_FIN,                               //!< Type: [f]      frequency input
         PININ_DOU_STA,                           //!< Type: [DEF]    For the dou - the status input
         PININ_DOU_CIN,                           //!< Type: [mA]     For the dou - the cin input
         PININ_PWM_STA,                           //!< Type: [DEF]    For the pwm - the status input
         PININ_PWM_CIN                            //!< Type: [mA]     For the pwm - the cin input
    }EEcuPinInTyp;

    //! Pin Output
    typedef enum
    {
         PINOUT_NA,                               //!< Type: [-]     Not available
         PINOUT_ERR,                              //!< Type: [-]      Pin Init Error
         PINOUT_DOU,                              //!< Type: [0/1]   Digital Output
         PINOUT_PWM                               //!< Type: [duty]  PWM Output
    }EEcuPinOutTyp;

    // Voltage input
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        EPinStatus eSta;                          //!< Pin status
        TBoolean   boFresh;                       //!< Fresh
        TUint16    u16Vin;                        //!< Pin value
        TBoolean   boDin;                         //!< Digital Input - for the schmitt trigger
    }LVin;

    //! Resistor Input
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        TUint16    u16Res;                        //!< Resistance value
        EPinStatus eSta;                          //!< Status
        TBoolean   boFresh;                       //!< Fresh
    }LRes;

    // Current input
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        EPinStatus eSta;                          //!< Pin status
        TBoolean   boFresh;                       //!< Fresh
        TUint16    u16Cin;                        //!< Pin value
        TBoolean   boDinVal;                      //!< Digital value - for the schmitt trigger
    }LCin;

    // Digital input
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        EPinStatus eSta;                          //!< Pin status
        TBoolean   boFresh;                       //!< Fresh
        TUint16    u16Din;                        //!< Digital Input
        TBoolean   boDin;                         //!< Digital Input
    }LDin;

    // Digital Output
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        EPinStatus eSta;                          //!< Pin status
        TBoolean   boFresh;                       //!< Fresh
        TBoolean   boDou;                         //!< Pin digital output value (set value)
        TBoolean   boDin;                         //!< Pin digital input value  (feedback value)
        // Input Value
        TUint16    u16VinVal;                     //!< Voltage input value
        EPinStatus eVinSta;                       //!< Voltage input Status
        TBoolean   boVinFresh;                    //!< Voltage input Fresh
        EPinStatus eCinSta;                       //!< Current input Status
        TBoolean   boCinFresh;                    //!< Current input Fresh
        TUint16    u16CinVal;                     //!< Current input value   TTC5X only with LS-Dou with HS-PWM
    }LDou;

    //! PWM Input
    typedef struct
    {
        TUint8     u8Upd;                           //!< Update
        EPinStatus eSta;                            //!< Status
        TBoolean   boFresh;                         //!< Fresh
        TUint16    u16Pwm;                          //!< Pwm value
        EPinStatus eCinSta;                         //!< Current input Status
        TBoolean   boCinFresh;                      //!< Current input Fresh
        TUint16    u16CinVal;                       //!< Current value
    }LPwm;

    //! Frequency Input
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        TUint16    u16Fin;                        //!< Frequency value
        EPinStatus eSta;                          //!< Status
        TBoolean   boFresh;                       //!< Fresh
        TUint16    u16VinVal;                     //!< Voltage value
        EPinStatus eVinSta;                       //!< Voltage Status
        TBoolean   boVinFresh;                    //!< Voltage Fresh
    }LFin;

    //! Led Output
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        TBoolean   boLed;                         //!< Led output value
        EPinStatus eSta;                          //!< Status
        TBoolean   boFresh;                       //!< Fresh
        TUint16    u16Val;                        //!< Value
    }LLed;

    //! Voltage output
    typedef struct
    {
        TUint8     u8Upd;                         //!< Update
        TUint16    u16Vou;                        //!< Voltage output value
        EPinStatus eSta;                          //!< Status
        TBoolean   boFresh;                       //!< Fresh
        TUint16    u16VinVal;                     //!< Voltage input value
        EPinStatus eVinSta;                       //!< Voltage input Status
        TBoolean   boVinFresh;                    //!< Voltage inputFresh
    }LVou;

    //! Pin Union (NOTE: 'L' stand for Layer of the Union)
    typedef union
    {
        // Inputs
        LVin    lVin;                             //!< Voltage input layer
        LRes    lRes;                             //!< Resistive input layer
        LCin    lCin;                             //!< Current input layer
        LDin    lDin;                             //!< Digital input layer
        LDou    lDou;                             //!< Digital output layer
        LPwm    lPwm;                             //!< Pwm output layer
        LFin    lFin;                             //!< Frequency input layer
        LLed    lLed;                             //!< LED output layer
        LVou    lVou;                             //!< Voltage output layer
    }UPinLast;

#endif
