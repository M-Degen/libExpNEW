//**************************************************************************************************
/*!
@file       ItfBoardPinApiTtc2xxx.h
@brief      General layer struct
@note       IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED
@version    1.0.0
*/
//**************************************************************************************************

#ifndef  __ITFBOARDPINAPITTC2XXX__
    #define __ITFBOARDPINAPITTC2XXX__

    #include <ItfTypes.h>
    #include <autoconfig.h>

    #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX

    // ==============================================================================================================
    // !! The use of these functions in the application leads immediately to the exclusion of the HYDAC liability. !!
    // !! The use of the entire application with all the components used a call at your own risk.                  !!
    // !! IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED                !!
    // ==============================================================================================================

    #if defined(COMPILER_SWITCH_CORE_BUILD) || defined(COMPILER_SWITCH_PTC_BUILD)
    // Only for the CORE-Build or for the Protocol-Build usable

        // System value
        typedef struct
        {
            TBoolean   boUpdate;                    //!< Update flag
            TBoolean   boFresh;                     //!< Fresh flag
            EPinStatus eSta;                        //!< Pin status
            TUint16    u16Val;                      //!< Pin value
        }TPinSysVal;

        #define SYS_UPD_TEMP        0x01            //!< Update mask bit for forcing temperature
        #define SYS_UPD_BAT         0x02            //!< Update mask bit for forcing battery voltage
        #define SYS_UPD_K15         0x04            //!< Update mask bit for forcing k15 status
        #define SYS_UPD_SAFE        0x08            //!< Update mask bit for forcing safestate
        #define SYS_UPD_SEN0        0x10            //!< Update mask bit for forcing sensory supply 0
        #define SYS_UPD_SEN1        0x20            //!< Update mask bit for forcing sensory supply 1
        #define SYS_UPD_SEN2        0x40            //!< Update mask bit for forcing sensory supply 2
        #define SYS_UPD_POWSTAGE    0x80            //!< Update mask bit for forcing power stage enable[d]

        // System pin list
        typedef struct
        {
            TPinSysVal tK15Status_D;                //!< K15 Pin - Digital
            TPinSysVal tK15Status_V;                //!< K15 Pin - Voltage
            TPinSysVal tSafeState_D;                //!< Virtual Safe State Pin
            TPinSysVal tBattery_V;                  //!< Virtual Battery Pin
            TPinSysVal tWakeUp;                     //!< Wake up pin
            #ifdef COMPILER_SWITCH_FAM_TTC23XX
            TPinSysVal tWakeUp_V;                   //!< Wake up pin voltage in
            #endif
            TPinSysVal tSafetySw0;                  //!< Safety Switch 0
            #ifdef COMPILER_SWITCH_FAM_TTC23XX
            TPinSysVal tSafetySw1;                  //!< Safety Switch 1
            #endif
            TPinSysVal tTemperatur_K;               //!< Virtual Temperature Pin
            TPinSysVal tReferenc_V;                 //!< Virtual Reference Pin

            TPinSysVal tSensor0_V;                  //!< Sensor Supply 0
            #ifdef COMPILER_SWITCH_FAM_TTC23XX
            TPinSysVal tSensor1_V;                  //!< Sensor Supply 1
            TPinSysVal tSensorVar_V;                //!< Sensor Supply Variable

            #endif
            TPinSysVal tBatPower_V;                 //!< Battery power
            TPinSysVal tBatCpu_V;                   //!< Battery cpu
            TPinSysVal tCanWakeUp;                  //!< Wake up pin
        }TSysPinLast;

        //! Pin Input
        typedef enum
        {
            PININ_NA,                               //!< Type: [-]      Not Available
            PININ_ERR,                              //!< Type: [-]      Pin Init Error
            PININ_STA,                              //!< Type: [DEF]    status
            PININ_DIN,                              //!< Type: [0/1]    Digital Input
            PININ_VIN,                              //!< Type: [U]      Voltage Input
            PININ_RES,                              //!< Type: [R]      Resistive configuration
            PININ_CIN,                              //!< Type: [I]      Current Input
            PININ_CNT,                              //!< Type: [cnt]    incremental input pin
            PININ_INC,                              //!< Type: [cnt+/-] incremental input dual pin
            PININ_CPX,                              //!< Type: [STU]    complex input struct
            PININ_DOU_STA,                          //!< Type: [DEF]    For the dou - the status input
            PININ_DOU_VIN,                          //!< Type: [mV]     For the dou - the vin input
            PININ_DOU_CIN,                          //!< Type: [mA]     TTC5X: For the dou - the cin input - Genau LowSide Cin-Messung mit einen PWM-Pin
            PININ_DOU_VCIN,                         //!< Type: [mV,mA]  For the dou - the vin and cin input
            PININ_PWM_STA,                          //!< Type: [DEF]    For the pwm - the status input
            PININ_PWM_VIN,                          //!< Type: [mV]     For the pwm - the vin input
            PININ_PWM_CIN,                          //!< Type: [mA]     For the pwm - the cin input
            PININ_LED_STA,                          //!< Type: [DEF]    For the led - the status input
            PININ_PVG_STA,                          //!< Type: [DEF]    For the pvg - the status input
            PININ_VOU_STA,                          //!< Type: [DEF]    For the vou - the status input
            PININ_VOU_VIN,                          //!< Type: [mV]     For the vou - the vin input
            #ifdef COMPILER_SWITCH_FAM_TTC23XX
            PININ_EOU_STA,                          //!< Type: [DEF]    For the eso out - the status input
            PININ_EOU_VIN                           //!< Type: [mV]     For the eso out - the vin input
            #endif
        }EEcuPinInTyp;

        //! Pin Output
        typedef enum
        {//
             PINOUT_NA                              //!< Type: [-]     Not Available
            ,PINOUT_ERR                             //!< Type: [-]     Pin Init Error
            ,PINOUT_DOU                             //!< Type: [0/1]   Digital Output
            ,PINOUT_PWM                             //!< Type: [duty]  PWM Output
            ,PINOUT_LED                             //!< Type: [0,1]   LED driver
            ,PINOUT_PVG                             //!< Type: [%/100] Percent of UBat
            ,PINOUT_VOU                             //!< Type: [mV]    Voltage Output
            #ifdef COMPILER_SWITCH_FAM_TTC23XX
            ,PINOUT_EOU                             //!< Type: [mV]    Emergency Shutoff Output
            #endif
        }EEcuPinOutTyp;

        #define DIN_UPD_BSP_DIN 0x01                //!< Update mask
        #define DIN_UPD_DIN_STA 0x02                //!< Update mask


        //!< Digital Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TBoolean   boDin;                       //!< Din value
        }LDin;

        #define VIN_UPD_BSP_VIN 0x01                //!< Update mask
        #define VIN_UPD_VIN_STA 0x02                //!< Update mask
        #define VIN_UPD_DIN     0x04                //!< Update mask

        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Vin;                      //!< Voltage Input
            TBoolean   boDin;                       //!< Digital Input - for the schmitt trigger
        }LVin;

        #define RES_UPD_BSP_RES 0x01                //!< Update mask
        #define RES_UPD_RES_STA 0x02                //!< Update mask

        //! Resister Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Res;                      //!< Resister value
            TUint32    u32Res;                      //!< Resister value
        }LRes;

        #define CIN_UPD_BSP_CIN 0x01                //!< Update mask
        #define CIN_UPD_CIN_STA 0x02                //!< Update mask
        #define CIN_UPD_DIN     0x04                //!< Update mask

        //! Current Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Cin;                      //!< Current value
            TBoolean   boDinVal;                    //!< Digital value - for the schmitt trigger
        }LCin;

        #define FIN_UPD_VIN          0x01           //!< Update mask
        #define FIN_UPD_FIN          0x02           //!< Update mask
        #define FIN_UPD_FIN_STA      0x08           //!< Update mask

        //! Frequency Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Fin;                      //!< Frequency value
            EPinStatus eVinSta;                     //!< Voltage Status
            TBoolean   boVinFresh;                  //!< Voltage Fresh
            TUint16    u16VinVal;                   //!< Voltage value
        }LFin;

        #define PUL_UPD_HT  0x01                    //!< Update mask

        //! Pull input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint32    u32Ht;                       //!< High time value
        }LPul;

        #define CNT_UPD_BSP_CNT  0x01               //!< Update mask
        #define CNT_UPD_BSP_VIN  0x02               //!< Update mask  (HW read with one call)
        #define CNT_UPD_BSP_DIN  0x04               //!< Update mask  (HW read with one call)
        #define CNT_UPD_CNT_STA  0x08               //!< Update mask
        #define CNT_UPD_VIN      0x10               //!< Update mask  (HW read with one call)
        #define CNT_UPD_DIN      0x20               //!< Update mask  (HW read with one call)

        //! Counter Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint32    u32Cnt;                      //!< Counter value
            TUint16    u16Vin;                      //!< Voltage value
        }LCnt;

        #define PWM_UPD_BSP_PWM  0x01               //!< Update mask
        #define PWM_UPD_BSP_CIN  0x02               //!< Update mask
        #define PWM_UPD_BSP_FIN  0x04               //!< Update mask
        #define PWM_UPD_CIN_STA  0x08               //!< Update ADC
        #define PWM_UPD_HT       0x10               //!< Update ADC
        #define PWM_UPD_PER      0x20               //!< Update ADC
        #define PWM_UPD_VIN      0x40               //!< Update ADC

        //! PWM Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Pwm;                      //!< Pwm value
            // Input Value
            TUint16    u16Ht;                       //!< High time
            TUint16    u16Periode;                  //!< Period

            EPinStatus eCinSta;                     //!< Current input Status
            TBoolean   boCinFresh;                  //!< Current input Fresh
            TUint32    u32CinVal;                   //!< Current value

            EPinStatus eVinSta;                     //!< Voltage input Status
            TBoolean   boVinFresh;                  //!< Voltage input Fresh
            TUint16    u16VinVal;                   //!< Voltage value

            TUint16    u16Fin;                      //!< Frequency value
            TBoolean   boProtectTimeReport;         //!< Protect time report
            TBoolean   boResolveFinish;             //!< resolve finish

        }LPwm;

        #define DOU_UPD_BSP_DOU    0x01             //!< Update mask
        #define DOU_UPD_BSP_VIN    0x02             //!< Update mask
        #define DOU_UPD_BSP_CIN    0x08             //!< Update mask
        #define DOU_UPD_VIN_STA    0x10             //!< Update ADC
        #define DOU_UPD_CIN_STA    0x20             //!< Update ADC

        //! Dou Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TBoolean   boDou;                       //!< Digital output value
            // Input Value
            EPinStatus eVinSta;                     //!< Voltage input Status
            TBoolean   boVinFresh;                  //!< Voltage input Fresh
            TUint16    u16VinVal;                   //!< Voltage input value
            EPinStatus eCinSta;                     //!< Current input Status
            TBoolean   boCinFresh;                  //!< Current input Fresh
            TUint16    u16CinVal;                   //!< Current input value   TTC5X only with LS-Dou with HS-PWM
            TBoolean   boProtectTimeReport;         //!< Protection time report
        }LDou;

        #define LED_UPD_BSP_LED    0x01             //!< Update mask
        #define LED_UPD_BSP_VAL    0x02             //!< Update mask
        #define LED_UPD_VAL_STA    0x04             //!< Update mask

        //! Led Input
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TBoolean   boLed;                       //!< Led output value
        }LLed;

        #define PVG_UPD_BSP_PVG    0x01             //!< Update mask
        #define PVG_UPD_BSP_VIN    0x02             //!< Update mask
        #define PVG_UPD_PVG_STA    0x04             //!< Update mask
        #define PVG_UPD_VIN_STA    0x08             //!< Update mask

        //! PVG Output
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Pvg;                      //!< PVG output value
            EPinStatus eVinSta;                     //!< Voltage input Status
            TBoolean   boVinFresh;                  //!< Voltage input Fresh
            TUint16    u16VinVal;                   //!< Voltage input value
        }LPvg;

        #define VOU_UPD_BSP_VOU    0x01             //!< Update mask
        #define VOU_UPD_BSP_VIN    0x02             //!< Update mask
        #define VOU_UPD_VIN_STA    0x04             //!< Update mask

        // Voltage output
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Vou;                      //!< Voltage output value
            EPinStatus eVinSta;                     //!< Voltage input Status
            TBoolean   boVinFresh;                  //!< Voltage inputFresh
            TUint16    u16VinVal;                   //!< Voltage input value
        }LVou;

        #define CPX_UPD_BSP       0x01
        #define CPX_UPD_BSP_CIN   0x02
        #define CPX_UPD_FIN_STA   0x04
        #define CPX_UPD_PULWID    0x08  // 32-Bit
        #define CPX_UPD_VIN       0x10
        #define CPX_UPD_CNT       0x20
        #define CPX_UPD_FINMIL    0x40
        #define CPX_UPD_CIN_STA   0x80

        //Complex Input
        typedef struct
        {
            TUint8        u8Upd;                    //!< Update
            ERetVal       eRetVal;                  //!< Return Value
            TComplexVal   tCpx;                     //!< Complex Structure
        }LXCpx;

        #define INC_UPD_BSP     0x01
        #define INC_UPD_CNT_STA 0x02
        #define INC_UPD_VINMAS  0x04
        #define INC_UPD_VINSLA  0x08
        #define INC_UPD_DINMAS  0x10
        #define INC_UPD_DINSLA  0x20

        // Increment Input
        typedef struct
        {
            TUint8        u8Upd;                    //!< Update
            ERetVal       eRetVal;                  //!< Status
            TFinIncValue  tInc;                     //!< Fresh
        }LXInc;

        #define EOU_UPD_BSP_EOU    0x01             //!< Update mask
        #define EOU_UPD_BSP_VIN    0x02             //!< Update mask
        #define EOU_UPD_VIN_STA    0x04             //!< Update mask

        // Emergency Shutoff output
        typedef struct
        {
            TUint8     u8Upd;                       //!< Update
            EPinStatus eSta;                        //!< Status
            TBoolean   boFresh;                     //!< Fresh
            TUint16    u16Eou;                      //!< Emergency shutoff output
            EPinStatus eVinSta;                     //!< Voltage input Status
            TBoolean   boVinFresh;                  //!< Voltage inputFresh
            TUint16    u16VinVal;                   //!< Voltage input value
        }LEou;

        //! Pin Union (NOTE: 'L' stand for Layer of the Union)
        typedef union
        {
            // Inputs
            LDin    lDin;                           //!< Digital input layer
            LVin    lVin;                           //!< Voltage input layer
            LRes    lRes;                           //!< Resister input layer
            LCin    lCin;                           //!< Current input layer
            LFin    lFin;                           //!< Frequenzy input layer
            LCnt    lCnt;                           //!< Count input layer
            LPul    lPul;                           //!< Pull input layer
            LXInc   lXInc;                          //!< Extended Increment input layer
            LXCpx   lXCpx;                          //!< Extended Complexe input layer
            // Outputs                              //!<
            LPwm    lPwm;                           //!< PWM output layer
            LDou    lDou;                           //!< Digital output layer
            LLed    lLed;                           //!< LED output layer
            LPvg    lPvg;                           //!< PVG output layer
            LVou    lVou;                           //!< Voltage output layer
            LEou    lEou;                           //!< Emergency shutOff output
        }UPinLast;

    #endif

 #endif // COMPILER_SWITCH_PLATFORM_TTC2XXX

#endif //__ITFBOARDPINAPITTC2XXX__
