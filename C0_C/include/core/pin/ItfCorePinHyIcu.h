//**************************************************************************************************
/*!
@file       ItfCorePinHyIcu.h
@brief      PIN Interface
@date       14.11.2014
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREPINHYICU__
    #define __ITFCOREPINHYICU__

    #include <autoconfig.h>
    #include <ItfCoreBoard.h>

  #ifdef COMPILER_SWITCH_FAM_HYICU


    #define ADC_SYS_START   ADC_SYS_UB_ECU_MAX        //!< Start of ADC system input
    #define DAC_SYS_START   DAC_SYS_K15               //!< Start of DAC system output

    //! Adc types

    //! PIN Status
    typedef enum
    {
        PINSTA_OK          =  0,                      //!< PIN is OK
        //PINSTA_OPEN      =  1,                      //!< PIN is open
        //PINSTA_SCGND     =  2,                      //!< PIN is short circuit to ground
        //PINSTA_SCPOW     =  3,                      //!< PIN is short circuit to power
        PINSTA_UNDEF       =  4,                      //!< PIN is undefined ( no PIN update since ecu start )
        PINSTA_ERRINIT     =  5,                      //!< PIN not installed / PIN don't support the request
        PINSTA_ERRUNDEF    =  6,                      //!< PIN status in undefined error
        PINSTA_ERRINUSED   =  7,                      //!< Output PIN has been used in that cycle
        PINSTA_SAFESTATE   = 12,                      //!< PIN is in "safe state"
        PINSTA_NA          = 31                       //!< PIN Status a not applicable [5 Bits]
    }EPinStatus;

    typedef enum
    {// RANGE  0 - 32767
        #ifdef COMPILER_SWITCH_ECU_HYICU_P1
        ADC_DIN_D                 =  0,               //!< [0/1]    Digital info           (Enable)                 (P02)
        #endif
        ADC_VIN_V                 =  1,               //!< [mV]     Analogue in voltage    (Analog input)           (P03,P10)
        ADC_VIN_D                 =  3,               //!< [0/1]    Digital info           (Analog input)           (P03,P10)
        ADC_CIN_C                 =  4,               //!< [mA]     Analogue in current    (Analog input)           (P03,P10)
        ADC_CIN_D                 =  5,               //!< [0/1]    Digital info           (Analog input)           (P03,P10)
        ADC_RAW_V                 =  6,               //!< [raw]    raw value              (Pressure sensor)        (P01,P04,P10)
        ADC_RAW_D                 =  7,               //!< [0/1]    Digital info           (Pressure sensor)        (P01,P04,P10)
        ADC_RATIO_V               =  8,               //!< [mV]     Analogue in in voltage (Radiometric Vin/Vcc)    (P03)
        ADC_RATIO_D               =  9,               //!< [0/1]    Digital info           (Radiometric Vin/Vcc)    (P03)
        #ifdef COMPILER_SWITCH_ECU_HYICU_P1
        ADC_SPEED_V               =  10,              //!< [1/min]  Revolutions per minute (Motor speed)            (P10)
        ADC_SPEED_D               =  11,              //!< [0/1]    Digital info           (Motor speed)            (P10)
        #endif
        ADC_PIN_V                 =  12,              //!< [µm]     Absolute value         (Valve position)         (P10)
        ADC_PIN_D                 =  13,              //!< [0/1]    Digital info           (Valve position)         (P10)
        ADC_LED_OUT_D             =  14,              //!< [ON/OFF] Give the set LED value (LED)                    (P20,P21)
        ADC_VOU_OUT_V             =  15,               //!< [mV]     Output Value of DAC_VOU_V
        // === ECU board info ===
        // only system group as PIN always PIN_SYS
        ADC_SYS_UB_ECU_MAX        =  16,               //!< [mV]     Ecu battery operate value  [24000]
        ADC_SYS_BAT_OPERATE       =  17,               //!< [mV]     Ecu battery operate value  [24000]
        ADC_SYS_BAT_CURRENT       =  18,               //!< [mV]     Ecu battery current value  (not supported)
        ADC_SYS_K15_D             =  19,               //!< [ON/OFF] Ignition
        ADC_SYS_TEMP              =  20,               //!< [K]      Temperature (°C = x - ADC_KELVIN_OFFSET)
        ADC_SYS_REF_VOLTAGE       =  21                //!< [mV]     Reference voltage (Processor voltage)
    }EAdcTyp;

    //! DAC types
    typedef enum
    {
        #ifdef COMPILER_SWITCH_ECU_HYICU_P1
        DAC_DOU_D                     = 0,             //!< [0/1]    Digital Out               (P02,P07)
        #endif
        DAC_VOU_V                     = 1,             //!< [V]      Voltage Out               (P07)
        DAC_COU_C                     = 2,             //!< [mA]     Current Out               (Motorcontrol)(P10)
        DAC_LED_D                     = 3,             //!< [ON/OFF] LED output                (LED)         (P20,P21)
        DAC_POU_V                     = 4,             //!< [µm]     Valve Position Out        (Motorcontrol)(P10)
        DAC_SYS_K15                   = 5              //!< [ON/OFF] K15                       (Virtual)     (-)
        #ifdef COMPILER_SWITCH_ECU_HYICU_P1
        , DAC_SYS_MC_MODE               = 6            //!< [O/1/2]  Set Motorcontrol Mode OFF/Position/Torque (P10)
        , DAC_SYS_MC_CAL                = 7            //!< [ON/OFF] Motor Control Calibration (P10)
        , DAC_SYS_MC_LIMIT              = 8             //!< [mA]     Set motor current limit   (P10)
        #endif
    }EDacTyp;

    typedef enum {
        MC_STOPPED_0    = 0,  //!< Der Motor wurde noch nicht gestartet.
        MC_ALIGNING_0   = 1,  //!< Der Motor wurde gestartet und führt das erste Alignment durch.
        MC_RUNNING      = 2,  //!< Der Motor läuft.
        MC_STOPPED      = 3,  //!< Der Motor ist gestoppt.
        MC_ALIGNING     = 4,  //!< Der Motor führt ein Alignment durch.
        MC_FAULT        = 5   //!< Es liegt ein Fehler an.
    }EMcMotorState;


    typedef struct {
        TInt16 i16Kp;       //!< P-Anteil Gain.
        TInt16 i16Ki;       //!< I-Anteil Gain.
        TUint16 u16KpDiv;   //!< P-Anteil Divisor. Muss eine 2er Potenz sein.
        TUint16 u16KiDiv;   //!< I-Anteil Divisor. Muss eine 2er Potenz sein.
    }TMcPiStruct;
    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Adc value - simple
    //! @param[in]  eAdcType   - [ENU] ADC selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @retval     PIN status - [ENU] is the PINSTA convert to a U16-Value (e.g ADC_PWM_S)
    //! @retval     Adc value  - [VAL] if the PINSTA == PINSTA_OK give the ADC value (e.g ADC_PWM_C)
    //! @retval                  [ERR] if the PINSTA != PINSTA_OK the value is 0
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreAdcGetPin( EAdcTyp eAdcType, EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Adc Value
    //! @param[in]  eAdcType   - ADC_DIN_D, ADC_VIN_D, ADC_VIN_V, ADC_RES_R, ...
    //! @param[in]  ePin       - Pin Index
    //! @retval     Pin status - [ENU] is the PINSTA convert to a I16-Value (e.g ADC_PWM_S)
    //! @retval     Adc value  - [VAL] if the PINSTA == PINSTA_OK give the ADC value (e.g ADC_PWM_C
    //! @retval                  [ERR] if the PINSTA != PINSTA_OK the value is 0
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CoreAdcGetPin( EAdcTyp eAdcType, EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Get Adc value
    //! @note        a. Request of a adc value e.g. ADC_DOU_C give the Dou current on the value pointer back and the
    //!                 PIN status of Dou current as the return value
    //!              b. Request of a status e.g ADC_DOU_CS give the status on the value pointer back and as a return value
    //! @param[in]   eAdcType   - [ENU] ADC type selector
    //! @param[in]   ePin       - [ENU] Ecu-PIN or system PIN
    //! @param[out]  pu16Val    - [VAL] Value
    //! @param[out]  pboFresh   - [DEF] In a correct pin access, the value is always TRUE (Keep the compatibility)
    //!                                 (only if the pin is incorrect the value is false)
    //! @return      EPinStauts - [ENU] PIN status
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinFreshFb( EAdcTyp eAdcType, EPin ePin, TUint16 *pu16Val, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set DAC PIN
    //! @param[in]  eDacType   - [ENU] ADC type selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @param[in]  u16Val     - [...] Set value
    //! @param[out]  pboFresh  - [DEF] In a correct pin access, the value is always TRUE (Keep the compatibility)
    //!                                (only if the pin is incorrect the value is false)
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreDacSetPinFreshFb( EDacTyp eDacType, EPin ePin, TUint16 u16Val, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set DAC PIN
    //! @param[in]  eDacType   - [ENU] ADC type selector
    //! @param[in]  ePin       - [ENU] Ecu PIN or system PIN
    //! @param[in]  u16Val     - [...] Set value
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreDacSetPin( EDacTyp eDacType, EPin ePin, TUint16 u16Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set ecu output power stages and the safety switch status
    //! @param[in]  boOn       On:ON or Off: OFF
    //! @retval     R_OKAY     success
    //! @retval     R_UNKNOWN  no success
    //--------------------------------------------------------------------------------------------------
    extern  ERetVal eCoreSetEcuOutPowSta( TBoolean boOn);

    //--------------------------------------------------------------------------------------------------
    //! @brief     Deinstall the Pin
    //! @param[in] ePin     Pin
    //! @retval    R_OKAY   Pin is deinstall / [if the pin is free it will return also R_OKAY]
    //! @retval    !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallPin( EPin ePin);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVin -> Voltage input
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallVin( EPin ePin);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallCin -> Current input
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallCin( EPin ePin);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallRaw -> Current input
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallRaw( EPin ePin);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallRat -> Rational Voltage input
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallRat( EPin ePin);

    #ifdef COMPILER_SWITCH_ECU_HYICU_P1
    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallDin -> Digital input
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallDin( EPin ePin);
    #endif

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallPin -> Position
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPin( EPin ePin);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallSin -> Speed
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallSin( EPin ePin);

    #ifdef COMPILER_SWITCH_ECU_HYICU_P1
    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallDou -> Digital output
    //! @param[in]  ePin          PIN
    //! @param[in]  eRange        Pin resolution
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallDou( EPin ePin, EPinRsl eRange );
    #endif

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVou -> Voltage output
    //! @param[in]  ePin          PIN
    //! @param[in]  eRange        Pin resolution
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallVou( EPin ePin, EPinRsl eRange );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallCou -> Current output
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallCou( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallPou -> Position output
    //! @param[in]  ePin          PIN
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPou( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallLed
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallLed( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the Motorcontrol torque value
    //! @param[in]  i16TorqueVal - [mA]  Set the torque value [-10A..+10A]
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eSetTorqueValue( TInt16 i16TorqueVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Current limit
    //! @param[out] pi32CurrVal - [mA]  current limit
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eMcGetCurrLimit( TInt32* pi32CurrVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the Motorcontrol valve position
    //! @param[in]  i16PosVal - [µm]  Set the position value
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eSetPosition( TInt16 i16PosVal );


#ifdef COMPILER_SWITCH_ECU_HYICU_P1_
    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the I part of the PI flow controller
    //! @param[out] pu16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetCurrentKI ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the I part of the PI flow controller
    //! @param[in]  u16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetCurrentKI ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the P part of the PI flow controller
    //! @param[out] pu16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetCurrentKP ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the P part of the PI flow controller
    //! @param[in]  u16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetCurrentKP ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the I part of the position controller
    //! @param[out] pu16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetThetaKI ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the I part of the position controller
    //! @param[in]  u16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetThetaKI ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Null and pole compensation together with parameter ZP1_PARA_B
    //! @param[out] pu16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetZp1ParaA ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set Null and pole compensation together with parameter ZP1_PARA_B
    //! @param[in]  u16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetZp1ParaA ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Null and pole compensation together with parameter ZP1_PARA_A
    //! @param[out] pu16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetZp1ParaB ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set Null and pole compensation together with parameter ZP1_PARA_A
    //! @param[in]  u16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetZp1ParaB ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Null and pole compensation together with parameter ZP2_PARA_B
    //! @param[out] pu16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetZp2ParaA ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set Null and pole compensation together with parameter ZP2_PARA_B
    //! @param[in]  u16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetZp2ParaA ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Null and pole compensations together with parameter ZP2_PARA_A
    //! @param[out] pu16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetZp2ParaB ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set Null and pole compensations together with parameter ZP2_PARA_A
    //! @param[in]  u16Value - range [0..65535]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetZp2ParaB ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get start ramp of position controller  [U/min]
    //! @param[out] pu16Value - range [0..32767]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetSpdP1 ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set start ramp of position controller  [U/min]
    //! @param[in]  u16Value - range [0..32767]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetSpdP1 ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get mid speed of position controller  [U/min]
    //! @param[out] pu16Value - range [0..32767]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetSpdP2 ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set mid speed of position controller  [U/min]
    //! @param[in]  u16Value - range [0..32767]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetSpdP2 ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get end speed of position controller  [U/min]
    //! @param[out] pu16Value - range [0..32767]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetSpdUpP3 ( TUint16 * pu16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set end speed of position controller  [U/min]
    //! @param[in]  u16Value - range [0..32767]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetSpdUpP3 ( TUint16 u16Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get revolutions of position controller at end speed [U/min]
    //! @param[out] pu8Value - range [0..255]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetCycleP ( TUint8 * pu8Value );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set revolutions of position controller at end speed [U/min]
    //! @param[in]  u8Value - range [0..255]
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetCycleP ( TUint8 u8Value );
#else
    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcStartMotor - Start the Motor
    //! @return     ERetVal
    //! @return         R_OKAY      - Motor is/was started
    //! @return         R_BUSY      - Motor control is busy
    //! @return         R_CONFIG    - This function is in current state not available.
    //! @return         R_UNKNOWN   - Error: Motor could not be started
    //! @return         R_UNKNOWN   - ICU is in diag mode. The function is not possible now.
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcStartMotor( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcStopMotor - Stop the Motor
    //! @return     ERetVal
    //! @return         R_OKAY      - Motor is/was stopped
    //! @return         R_BUSY      - Motor control is busy
    //! @return         R_CONFIG    - This function is in current state not available.
    //! @return         R_UNKNOWN   - Error: Motor could not be stopped
    //! @return         R_UNKNOWN   - ICU is in diag mode. The function is not possible now.
    //--------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcStopMotor( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcSetCurrent - Set the target current
    //! @param[in]  pi32IqVal - Iq current in mA
    //! @param[in]  pi32IdVal - Id current in mA
    //! @return     ERetVal
    //! @return         R_OKAY      - Alignment started
    //! @return         R_UNKNOWN   - ICU is in diag mode. The function is not possible now.
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetCurrent( TInt32 i32IqVal, TInt32 i32IdVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcGetCurrent - Get the actual current
    //!                             If the motor is stopped Iq and Id is 0mA.
    //! @param[in]  pi32IqVal - Iq current in mA
    //! @param[in]  pi32IdVal - Id current in mA
    //! @return     ERetVal
    //! @return         R_OKAY      - Alignment started
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetCurrent( TInt32* pi32IqVal, TInt32* pi32IdVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcAlign    - Motor alignment
    //! @return     ERetVal
    //! @return         R_OKAY      - Alignment started
    //! @return         R_BUSY      - Motor control is busy
    //! @return         R_CONFIG    - This function is in current state not available.
    //! @return         R_UNKNOWN   - Error: Alignment could not be started
    //! @return         R_UNKNOWN   - ICU is in diag mode. The function is not possible now.
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcAlign( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcAckFaults - Faults acknowledgement
    //! @return     ERetVal
    //! @return         R_OKAY      - Faults were acknowledged
    //! @return         R_BUSY      - Motor control is busy
    //! @return         R_CONFIG    - This function is in current state not available.
    //! @return         R_UNKNOWN   - Errors could not be acknowledged
    //! @return         R_UNKNOWN   - ICU is in diag mode. The function is not possible now.
    //! @created    07.04.2020  HYDAC/FRI
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcAckFaults( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      u32McGetFaults - Faults acknowledgement
    //! @return     TUint32        - All occured errors coded in bit field
    //! @return         0x000U     - BiosMcFault_NoFaults
    //! @return         0x001U     - BiosMcFault_VDC_OCP...Overcurrent detected by gate driver
    //! @return         0x002U     - BiosMcFault_GDF.......Gate driver fault condition (e.g. short to gnd)
    //! @return         0x004U     - BiosMcFault_UVLO......Undervoltage lockout gate driver (< 5,6 V)
    //! @return         0x008U     - BiosMcFault_OTW.......Overtemperature warning gate driver (Tdie > 150°C)
    //! @return         0x010U     - BiosMcFault_OTSD......Overtemperature shutdown gate driver (Tdie > 170°C)
    //! @return         0x020U     - BiosMcFault_CPUV......Charge pump undervoltage gate driver
    //! @return         0x040U     - BiosMcFault_FOC.......FOC rate to high
    //! @return         0x080U     - BiosMcFault_BreakIn...Overcurrent detected by motor control lib
    //! @return         0x100U     - BiosMcFault_SwError...Software error motor control lib
    //! @return         0x200U     - BiosMcFault_MGLH......Magnetic field hall sensor out of range
    //! @return         0x400U     - BiosMcFault_Undefined
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32McGetFaults( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcGetMotorState    - Faults acknowledgement
    //! @return     EMcMotorState       - Current Motor state
    //--------------------------------------------------------------------------------------------------
    extern EMcMotorState eMcGetMotorState( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcSetPI    - Set new Pi parameters
    //! @param[in]  TMcPiStruct - Pi parameter struct
    //! @return     ERetVal
    //! @return         R_OKAY      - Parameters are accepted
    //! @return         R_PARAMETER - Parameters are not valid
    //! @return         R_UNKNOWN   - ICU is in diag mode. The function is not possible now.
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcSetPI( const TMcPiStruct* cptPiVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcGetPI    - Get current Pi parameters
    //! @param[out] TMcPiStruct - Pi parameter struct
    //! @return     ERetVal
    //! @return         R_OKAY      - Parameters okay
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetPI( TMcPiStruct* ptPiVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcGetPhaseCurrAmpl - Get phase current amplitude
    //! @param[out] pi32PhaCurr         - Amplitude of phase current [mA]
    //! @return     ERetVal
    //! @return         R_SUPPORT       - This function is not supported in that version
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetPhaseCurrAmpl ( TInt32* pi32PhaCurr);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcGetPhaseVoltAmpl - Get phase voltage amplitude
    //! @param[out] pi32PhaVolt         - Amplitude of phase voltage [V]
    //! @return     ERetVal
    //! @return         R_SUPPORT       - This function is not supported in that version
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetPhaseVoltAmpl ( TInt32* pi32PhaVolt);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eMcGetPosition      - Get current position
    //! @param[out] pi32Pos             - Current position [µm]
    //! @return     ERetVal
    //! @return         R_OKAY       - Position call was ok
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eMcGetPosition( TInt32* pi32Pos);


#endif

    //**************************************************************************************************
    // HPI functions
    //**************************************************************************************************
    //--------------------------------------------------------------------------------------------------
    //! @brief      i8CoreHpiGetSensorCnt - Get the HPI sensor count
    //! @return     i8HpiCnt
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8CoreHpiGetSensorCnt (void);

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetMinPress - Get the HPI minimal pressure
    //! @param[in]  ePin         - HPI index
    //! @param[out] pi32MinPress - HPI sensor digit pressure value
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_BUSY    - minimal pressure was requested, wait for valid value
    //! @return         R_RANGE   - index out of range
    //! @return         R_SUPPORT - no HPI sensors available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetMinPress( EPin ePin, TInt32* pi32MinPress );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetMaxPress - Get the HPI maximal pressure
    //! @param[in]  ePin         - HPI index
    //! @param[out] pi32MaxPress - HPI sensor digit pressure value
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_BUSY    - maximal pressure was requested, wait for valid value
    //! @return         R_RANGE   - index out of range
    //! @return         R_SUPPORT - no HPI sensors available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetMaxPress( EPin ePin, TInt32* pi32MaxPress );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetTemp - Get the HPI sensor temperature
    //! @param[in]  ePin         - HPI index
    //! @param[out] pi32Temp     - HPI sensor temperature
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_BUSY    - temperature was requested, wait for valid value
    //! @return         R_RANGE   - index out of range
    //! @return         R_SUPPORT - no HPI sensors available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetTemp( EPin ePin, TInt32* pi32Temp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetRange - Get the HPI sensor range
    //! @param[in]  ePin         - HPI index
    //! @param[out]  tRange      - HPI sensor range
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_RANGE   - index or frequency out of range
    //! @return         R_SUPPORT - no HPI sensors or measurement information available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetRange( EPin ePin, THpiRange* ptRange );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiConvPressure - Convert pressure digit value to physical value
    //! @param[in]  ePin         - HPI index
    //! @param[in]  i32DigVal    - digit value
    //! @param[out] pi32PhyVal   - physical value
    //! @param[out] ptRange      - HPI sensor range
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_RANGE   - index or frequency out of range
    //! @return         R_SUPPORT - no HPI sensors or measurement information available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiConvPressure( EPin ePin, TInt32 i32DigVal, TInt32* pi32PhyVal, THpiRange* ptRange );

    #ifdef COMPILER_SWITCH_TAR_PC

        //--------------------------------------------------------------------------------------------------
        //! @brief  Suppress the internal ecu PIN control logic. E.g. the SafeState reaction of all PIN's
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSimSuppressEcuLogic( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set Adc value - a bypass for the simulation [only for the PC-VERSION]
        //! @brief      call eCoreSimAdcSetPinFresh( eAdcType, ePin, TRUE )
        //! @param[in]  eAdcType   - [ENU] ADC type selector
        //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
        //! @param[in]  u16Val     - [...] PIN value
        //! @retval     R_OKAY
        //! @retval     R_RANGE
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreSimAdcSetPin( EAdcTyp eAdcType, EPin ePin, TUint16 u16Val );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get DAC PIN Value back - a bypass for the simulation [only for the PC-VERSION]
        //! @param[in]  eDacType   - [ENU] ADC type selector
        //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
        //! @retval     u16Val     - [...] Get the value
        //--------------------------------------------------------------------------------------------------
        extern TUint16 u16CoreSimDacGetPin( EDacTyp eDacType, EPin ePin );

    #endif // COMPILER_SWITCH_TAR_PC

  #endif // COMPILER_SWITCH_FAM_HYICU

#endif
