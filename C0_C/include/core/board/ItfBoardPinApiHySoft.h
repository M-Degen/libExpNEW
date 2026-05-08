//**************************************************************************************************
/*!
@file       ItfBoardPinApiElec.h
@brief      General layer struct
@note       IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED
@version    1.0.0
*/
//**************************************************************************************************

#ifndef  __ITFBOARDPINAPIHYSOFT__
    #define __ITFBOARDPINAPIHYSOFT__

    #include <ItfTypes.h>

    #if defined(COMPILER_SWITCH_FAM_HYMEB)

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
            TBoolean   boFresh;                       //!< Fresh flag
            EPinStatus eSta;                          //!< Pin status
            TUint16    u16Val;                        //!< Pin value
        }TPinSysVal;

        // System pin list
        typedef struct
        {
            TPinSysVal tBattery_V;                    //!< Virtual Battery Pin
            TPinSysVal tK15Status_D;                  //!< K15 Pin
            TPinSysVal tTemperatur_K;                 //!< Virtual Temperature Pin
        }TSysPinLast;

		#define DIN_UPD_DIN 0x01                      //!< Update mask
        // Voltage input
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boFresh;                       //!< Fresh
            TUint16    u16Din;                        //!< Digital Input
            TBoolean   boDin;                         //!< Digital Input
        }LDin;

        #define VIN_UPD_VIN 0x01                      //!< Update mask
        // Voltage input
        typedef struct
        {
            TUint8     u8Upd;                         //!< Update
            EPinStatus eSta;                          //!< Pin status
            TBoolean   boFresh;                       //!< Fresh
            TUint16    u16Vin;                        //!< Pin value
            TBoolean   boDin;                         //!< Digital Input - for the schmitt trigger
        }LVin;

		#define CIN_UPD_CIN 0x01                      //!< Update mask
        // Voltage input
        typedef struct
        {
        	TUint8     u8Upd;                         //!< Update
        	EPinStatus eSta;                          //!< Pin status
        	TBoolean   boFresh;                       //!< Fresh
        	TUint16    u16Cin;                        //!< Pin value
            TBoolean   boDinVal;                      //!< Digital value - for the schmitt trigger
        }LCin;

		#define DOU_UPD_DOU    0x01                   //!< Update mask
        #define DOU_UPD_CIN    0x02                   //!< Update mask
		// Current Output
		typedef struct
		{
			TUint8     u8Upd;                         //!< Update
			EPinStatus eSta;                          //!< Pin status
	        TBoolean   boFresh;                       //!< Fresh
			TBoolean   boDou;                         //!< Pin digital output value (set value)
			TBoolean   boDin;                         //!< Pin digital input value  (feedback value)
            EPinStatus eCinSta;                       //!< Current input Status
            TBoolean   boCinFresh;                    //!< Current input Fresh
            TUint16    u16CinVal;                     //!< Current input value   TTC5X only with LS-Dou with HS-PWM
		}LDou;

      #define PWM_UPD_OUT    0x01                     //!< Update mask
      #define PWM_UPD_CIN    0x02                     //!< Update mask
      #define PWM_UPD_FIN    0x04                     //!< Update mask

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


        //! Pin Union (NOTE: 'L' stand for Layer of the Union)
        typedef union
        {
            // Inputs
            LDin    lDin;                             //!< Digital output layer
            LVin    lVin;                             //!< Voltage input layer
            LCin    lCin;                             //!< Current input layer
            LDou    lDou;                             //!< Digital output layer
            LPwm    lPwm;                             //!< Pwm output layer
        }UPinLast;

        //! Pin Input
        typedef enum
        {
             PININ_NA,                                //!< Type: [-]      Not available
             PININ_ERR,                               //!< Type: [-]      Pin Init Error
             PININ_DIN,                               //!< Type: [0/1]    Digital input
             PININ_VIN,                               //!< Type: [mV]     Voltage input
             PININ_CIN,                               //!< Type: [mA]     Current input
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

    #endif
    #endif

#endif
