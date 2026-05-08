//**************************************************************************************************
/*!
@file       ItfBoardPinApiElec.h
@brief      General layer struct
@note       IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED
@version    1.0.0
*/
//**************************************************************************************************

#ifndef  __ITFBOARDPINAPIELEC__
    #define __ITFBOARDPINAPIELEC__

    #include <ItfTypes.h>

    #ifdef COMPILER_SWITCH_OEM_HY

    // ==============================================================================================================
    // !! The use of these functions in the application leads immediately to the exclusion of the HYDAC liability. !!
    // !! The use of the entire application with all the components used a call at your own risk.                  !!
    // !! IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED                !!
    // ==============================================================================================================

       #if defined(COMPILER_SWITCH_CORE_BUILD) || defined(COMPILER_SWITCH_PTC_BUILD)
       // Only for the CORE-Build or for the Protocol-Build usable

        //!< Forcing Option
        typedef enum
        {
            PINFORCE_NONE   = 0,                      //!< no Forcing
        }EPinForce;

        // System value
        typedef struct
        {
            TBoolean   boUpdate;                      //!< Update flag
            EPinStatus eSta;                          //!< Pin status
            TUint16    u16Val;                        //!< Pin value
        }TPinSysVal;

        // System pin list
        #ifdef COMPILER_SWITCH_FAM_HYOBE
            typedef struct
            {
                TPinSysVal tBattery_V;                    //!< Virtual Battery Pin
                TPinSysVal tK15Status_D;                  //!< K15 Pin
                TPinSysVal tTemperatur_K;                 //!< Virtual Temperature Pin
                TPinSysVal tReferenc_V;                   //!< Virtual Reference Pin
                TPinSysVal tPowerStage_V;                 //!< Virtual Power Stage Pin
                TPinSysVal tPowerStage1_E;                //!< Virtual Power Stage (P14) Enabled
                TPinSysVal tPowerStage2_E;                //!< Virtual Power Stage (P15) Enabled
                TPinSysVal tPowerStage1_F;                //!< Virtual Power Stage (P14) Fault
                TPinSysVal tPowerStage2_F;                //!< Virtual Power Stage (P15) Fault
                TPinSysVal tReady_F;                      //!< Virtual Pin Ready Fault
                TPinSysVal tP14PowerStageEnable_D;        //!< Enabling power stages for (Power stage)(P14)
                TPinSysVal tP15PowerStageEnable_D;        //!< Enabling power stages for (Power stage)(P15)
            }TSysPinLast;
        #endif

        #ifdef COMPILER_SWITCH_FAM_HYICU
            typedef struct
            {
                TPinSysVal tBattery_V;                    //!< Virtual Battery Pin
                TPinSysVal tK15Status_D;                  //!< K15 Pin
                #ifdef COMPILER_SWITCH_ECU_HYICU_P2
                TPinSysVal tCanStayOn_D;
                #endif
                TPinSysVal tTemperatur_K;                 //!< Virtual Temperature Pin
                TPinSysVal tReferenc_V;                   //!< Virtual Reference Pin
                // TODO COMPILER_SWITCH_ECU_HYICU_P2
                TPinSysVal tP10McMode_D;                  //!< Virtual Motorcontrol Mode Pin
                TPinSysVal tP10McCal_D;                   //!< Virtual Motorcontrol Calibration Pin
                TPinSysVal tP10McLimit_C;                 //!< Virtual Motorcontrol Current Limit Pin
            }TSysPinLast;
        #endif

		#define DIN_UPD_DIN 0x01                          //!< Update mask
        // Voltage input
        typedef struct
        {
            TUint8     u8Upd;                             //!< Update
            EPinStatus eSta;                              //!< Pin status
            TBoolean   boFresh;                           //!< Fresh
            TUint16    u16Din;                            //!< Digital Input
            TBoolean   boDin;                             //!< Digital Input
        }LDin;

        #define VIN_UPD_VIN 0x01                          //!< Update mask
        // Voltage input
        typedef struct
        {
            TUint8     u8Upd;                             //!< Update
            EPinStatus eSta;                              //!< Pin status
            TBoolean   boFresh;                           //!< Fresh
            TUint16    u16Vin;                            //!< Pin value
            TBoolean   boDin;                             //!< Digital Input - for the schmitt trigger
        }LVin;

        #define CIN_UPD_CIN 0x01                          //!< Update mask
        // Voltage input
        typedef struct
        {
            TUint8     u8Upd;                             //!< Update
            EPinStatus eSta;                              //!< Pin status
            TBoolean   boFresh;                           //!< Fresh
            TUint16    u16Cin;                            //!< Pin value
            TBoolean   boDin;                             //!< Digital Input - for the schmitt trigger
        }LCin;

        #define RAW_UPD_VAL 0x01                          //!< Update mask
        // Value input
        typedef struct
        {
            TUint8     u8Upd;                             //!< Update
            EPinStatus eSta;                              //!< Pin status
            TBoolean   boFresh;                           //!< Fresh
            TUint16    u16Raw;                            //!< Pin value
            TBoolean   boDin;                             //!< Digital Input - for the schmitt trigger
        }LRaw;

         #define PERC_UPD_VAL 0x01                        //!< Update mask
        // Percent value
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boFresh;                       //!< Fresh
            TUint16    u16Per;                        //!< Pin value
            TBoolean   boDin;                         //!< Digital Input - for the schmitt trigger
        }LPer;

        #define RAT_UPD_VAL 0x01                      //!< Update mask
        // Ratiometric value
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boFresh;                       //!< Fresh
            TUint16    u16Rat;                        //!< Pin value
            TBoolean   boDin;                         //!< Digital Input - for the schmitt trigger
        }LRat;

        #define SIN_UPD_VAL 0x01                      //!< Update mask
        // Speed value
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boFresh;                       //!< Fresh
            TUint16    u16Sin;                        //!< Pin value
            TBoolean   boDin;                         //!< Digital Input - for the schmitt trigger
        }LSin;

        #define PIN_UPD_VAL 0x01                      //!< Update mask
        // Valve position value
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boFresh;                       //!< Fresh
            TUint16    u16Pin;                        //!< Pin value
            TBoolean   boDin;                         //!< Digital Input - for the schmitt trigger
        }LPin;

        #define POU_UPD_VAL 0x01                      //!< Update mask
        // Valve position value
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TUint16    u16Pou;                        //!< Pin position output value
            TUint16    u16Pin;                        //!< Pin position input value (feedback value)
        }LPou;

        #define DOU_UPD_DOU 0x01                      //!< Update mask
        // Current Output
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boDou;                         //!< Pin digital output value (set value)
            TBoolean   boDin;                         //!< Pin digital input value (feedback value)
        }LDou;

        #define COU_UPD_COU 0x01                      //!< Update mask
        #define COU_UPD_CIN 0x02                      //!< Update mask
        // Current Output
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TUint16    u16Cou;                        //!< Pin current output value (set value)
            TUint16    u16Cin;                        //!< Pin current input value (feedback value)
        }LCou;

        #define VOU_UPD_VOU 0x01                      //!< Update mask
        // Current Output
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TUint16    u16Vou;                        //!< Pin volta output value (set value)
            TUint16    u16Vin;                        //!< Pin current input value (feedback value)
        }LVou;
        #define LED_UPD_OUT 0x01                      //!< Update mask
        // Led output
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boLed;                         //!< Pin value
        }LLed;

        //! Pin Union (NOTE: 'L' stand for Layer of the Union)

        #ifdef COMPILER_SWITCH_FAM_HYOBE
        typedef union
        {
            // Inputs
            LDin    lDin;          //!< Digital output layer
            LVin    lVin;          //!< Voltage input layer
            LCin    lCin;          //!< Current input layer
            LRaw    lRaw;          //!< Value input layer
            LPer    lPer;          //!< Percent input layer
            LDou    lDou;          //!< Digital output layer
            LCou    lCou;          //!< Current output layer
            LVou    lVou;          //!< Voltage output layer
            LLed    lLed;          //!< Led output layer
        }UPinLast;

        //! Pin Input
        typedef enum
        {
             PININ_NA,             //!< Type: [-]      Not available
             PININ_DIN,            //!< Type: [0/1]    Digital input
             PININ_VIN,            //!< Type: [mV]     Voltage input
             PININ_CIN,            //!< Type: [mA]     Current input
             PININ_DOU,            //!< Type: [0/1]    Digital output
             PININ_LED,            //!< Type: [0/1]    LED output
             PININ_VOU,            //!< Type: [mV]     Voltage output
             PININ_RAW,            //!< Type: [raw]    Value input
             PININ_PER,            //!< Type: [%/100]  Value input
             PININ_COU             //!< Type: [mA]     Current output
        }EEcuPinInTyp;

        //! Pin Output
        typedef enum
        {
             PINOUT_NA,             //!< Type: [-]      Not available
             PINOUT_DIN,            //!< Type: [0/1]    Digital input
             PINOUT_VIN,            //!< Type: [mV]     Voltage input
             PINOUT_CIN,            //!< Type: [mA]     Current input
             PINOUT_DOU,            //!< Type: [0/1]    Digital output
             PINOUT_LED,            //!< Type: [0/1]    LED output
             PINOUT_VOU,            //!< Type: [mV]     Voltage output
             PINOUT_RAW,            //!< Type: [raw]    Value input
             PINOUT_PER,            //!< Type: [%/100]  Value input
             PINOUT_COU             //!< Type: [mA]     Current output
        }EEcuPinOutTyp;

        #endif

        #ifdef COMPILER_SWITCH_FAM_HYICU
        typedef union
        {
            // Inputs
            LDin    lDin;                             //!< Digital output layer
            LVin    lVin;                             //!< Voltage input layer
            LCin    lCin;                             //!< Current input layer
            LRaw    lRaw;                             //!< Value input layer
            LRat    lRat;                             //!< Percent input layer
            LDou    lDou;                             //!< Digital output layer
            LCou    lCou;                             //!< Current output layer
            LVou    lVou;                             //!< Voltage output layer
            LLed    lLed;                             //!< Led output layer
            LSin    lSin;
            LPin    lPin;
            LPou    lPou;
        }UPinLast;

        //! Pin Input
        typedef enum
        {
            PININ_NA,                                 //!< Type: [-]      Not Available
            PININ_ERR,                                //!< Type: [-]      Pin Init Error
            PININ_STA,                                //!< Type: [DEF]    status
            PININ_DIN,                                //!< Type: [0/1]    Digital Input
            PININ_VIN,                                //!< Type: [U]      Voltage Input
            PININ_CIN,                                //!< Type: [I]      Current Input
            PININ_RAW,                                //!< Type: [raw]    Raw input
            PININ_RATIO,                              //!< Type: [U]      Rational voltage Input
            PININ_SPEED,                              //!< Type: [1/min]  Revolutions per minute
            PININ_PIN,                                //!< Type: [µm]     Valve position input
            PININ_LED_OUT,                            //!< Type: [0/1]    LED out feedback
            PININ_VOU_OUT,                            //!< Type: [U]      Voltage out feedback
            PININ_DOU,                                //!< Type: [0/1]    Digital Output
            PININ_VOU,                                //!< Type: [U]  	  Voltage Output
            PININ_COU,                                //!< Type: [I]      Current Output
            PININ_LED,                                //!< Type: [0/1]    LED Output
            PININ_POU                                 //!< Type: [µm]     Valve position output
        }EEcuPinInTyp;

        //! Pin Output
        typedef enum
        {
            PINOUT_NA,                                 //!< Type: [-]      Not Available
            PINOUT_ERR,                                //!< Type: [-]      Pin Init Error
            PINOUT_STA,                                //!< Type: [DEF]    status
            PINOUT_DIN,                                //!< Type: [0/1]    Digital Input
            PINOUT_VIN,                                //!< Type: [U]      Voltage Input
            PINOUT_CIN,                                //!< Type: [I]      Current Input
            PINOUT_RAW,                                //!< Type: [raw]    Raw input
            PINOUT_RATIO,                              //!< Type: [U]      Rational voltage Input
            PINOUT_SPEED,                              //!< Type: [1/min]  Revolutions per minute
            PINOUT_PIN,                                //!< Type: [µm]     Valve position input
            PINOUT_LED_OUT,                            //!< Type: [0/1]    LED out feedback
            PINOUT_VOU_OUT,                            //!< Type: [U]      Voltage out feedback
            PINOUT_DOU,                                //!< Type: [0/1]    Digital Output
            PINOUT_VOU,                                //!< Type: [U]  	Voltage Output
            PINOUT_COU,                                //!< Type: [I]      Current Output
            PINOUT_LED,                                //!< Type: [0/1]    LED Output
            PINOUT_POU                                 //!< Type: [µm]     Valve position output
        }EEcuPinOutTyp;

    #endif

   #endif
   #endif

#endif
