# 1 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino"
# 1 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino"
//  includes
# 3 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 4 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 5 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 6 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 7 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 8 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 9 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 10 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
# 11 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino" 2
//#include <Adafruit_SSD1306.h>
//#include <stringz.h>
/*******************************PinMap***************************************

pinName         pinTo
0               RXD
1               TXD
2               DC      8
3               CS      9
4               DIR
5               STP
6               MS3
7               MS2
8               MS1
9               EN
10              
11              MOSI
12              MISO
13              SCK
A0              OLED_RESET
A1              Z_HOME
A2              M_UP
A3              M_DOWN
A4              SDA
A5              SCL
**********************************************************************************/
/*****************Commands definition*******************************************
 * A Request Acknowledgement
 * B Cycle to initial Base Layer at input
 * C Request current Status
 * D Set Delay (Breathe) time (ms)
 * E Set "settle" Delay time(ms)
 * F Release and move to final position at input 
 * G Goto Z position at input 
 * H Reset the projectors native X Resolution //
 * I Reset the projectors native Y Resolution //
 * J Set Cycle Ready Gap
 * K Set Print Cycle Raise Speed
 * L Set Print Cycle Lower Speed
 * M Toggle Manual Contol Activation
 * N Release and Position to build next Layer
 * O Set the current position to xxxx, use with caution!
 * P Projector Power & Mode commands
 * Q Set Broadcast interval in milliseconds, 0 = disabled
 * R Reset Home
 * S Stop all motion, activate manual controls
 * T Toggle verbose Text Comments
 * U Reset the projectors calibrated xy pixel size in microns //
 * V Set Vat Position (0 - 100 %) //
 * W Set Print Cycle Opening Speed \ * X Set Print Cycle Closing Speed \ * Y Reset z Axis home reference
nce
 * Z Set Z Axis speed
 * $ Reset Projector's Half Life value //
 * # \ * @ Set DLP current
t
 * 
 * 
 * */


// EEPROM (used for storing calibrated Z home offset
# 80 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino"
// Optical sensor inputs
//#define X_HOME    A0  //18

//define slider INIT_DONE
// #define INIT_DOWN 10
// Manual Toggle switch inputs


// defines



//#define OLED_CS    9

//#define OLED_RESET 11
//Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// #define OLED_DC 8
// #define OLED_CS 9
// #define OLED_RESET A0
// Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

// #if (SSD1306_LCDHEIGHT != 32)
// #error("Height incorrect, please fix Adafruit_SSD1306.h!");
// #endif
// Stepper Motor Outputs

// #define Z_MS1 2
// #define Z_MS2 4
// #define Z_MS3 3



// Projector's RS-232 Port I/O pins
// #define PROJECTOR_RX 12
// #define PROJECTOR_TX 13

// Stepper Mode






// Stepper Direction



// Stepper speeds in RPM





// Print Cycle states
# 145 "C:\\Users\\Jason\\Desktop\\Printer\\PrinterV1\\PrinterV1.ino"
// Maximum time spent in print cycle without
// a command before we shut off projector as a saftey precaution


// Z Movement states




// Motion state variables
int iZStatus = 1;
//int iSlideStatus = SLIDE_ARRIVED;
bool bReset = false;

// Persistent Calibration and setup settings





int iNativeX = 0;
int iNativeY = 0;
int iXYPixelSize = 0;
int iHalfLife = 2000;

// Z Axis Position & Movement variables

int iRefZeroOffset = -1; // Load persistant value from EEPROM during setup
int iUpperZLimit = 32000;
int iLowerZLimit = -500;
int iCurPos = 0;
int iLastCurPos = 0;
int iTargetPos = 0;
int iZDriveSpeedCmd = 300;
int lastStepPulse = 0x0;

unsigned long ulLastInteruptTime = millis();


// Event Flags
boolean bFindZero = false;
boolean bEnableManual = true;

// Cycle variables
int iCycle = 0;
int iLastCuredPos = 0;
int iNextCurePos = 0;

// Raise during print variables
int iReadyGap = 0; // 100 = .025"
unsigned long ulBreatheStart = millis();
unsigned long ulBreatheDur = 0;
unsigned long ulSettleStart = millis();
unsigned long ulSettleDur = 0;
int iRaiseSpeed = 120;
int iLowerSpeed = 120;

// Projector RS-232 interface & status variables
// b9SoftwareSerial projectorSerial = b9SoftwareSerial(PROJECTOR_RX, PROJECTOR_TX);
// unsigned long ulLastProjectorQueryTime = millis();
// unsigned long ulLastProjectorMsgRcvdTime = millis();
// bool bFirstProjectorQuery = true;
// We can only do one factory reset once the projector is turned on because it leaves us in an
// unknown menu state and we can not repeat the key stroke sequence again.
// So we only allow for one reset per power on command.
// This reset can be commanded manually with P7 or automaticaly with the B (base) command
//bool bProjectorNeedsReset = false;
//bool bIsMirrored = false;
int iProjectorPwr = -1; // 0 = OFF, 1 = ON, -1 = ?
int iLampHours = -1; // reported lamp hours, -1 = ?
unsigned long ulLastCmdReceivedTime = millis(); // reset every time we get a cmd from the host

// Broadcast variables
int iBC_Interval = 1000;//5000; //millisecs between broadcasts, set to 0 to disable broadcasts
unsigned long ulLastTimedBroadcastTime = millis();
bool bVerbose = false; // Send comments to Serial stream

// Function Declarations
void BC_C(const __FlashStringHelper *s, String sVariable = "");
void BC_String(const __FlashStringHelper *s, String sVariable = "");

bool DLP = false;


//set LED current, current goes with the value the MAXIUM is 0xFF
char Red = 255; // 0xD8 defult is 0x97
char Green = 255; // 0xD7 defult is 0x78
char Blue = 255; // 0xDC defult is 0x7D
char current[3] = {Red, Green, Blue};

//for LED breath, breathing till raspi startup
int FLAG_raspiStartup =0;


// String characters = "Initializing";

///////////////////////////////////////////////////////
//
// Program Setup
//
// void Display_logic(String characters, int size)
//         {
//                 display.clearDisplay();
//                 display.setTextSize(size);
//                 display.setTextColor(WHITE);
//                 display.setCursor(0, 0);
//                 display.println(characters);
//                 display.display(); 
//                 characters = "";
//         }
void setup()
{

        // Set up the IO pins and interupts

        setupIO();

        // set up Serial library at 115200 bps
        Serial.begin(115200);
        // display.begin(SSD1306_SWITCHCAPVCC);
        // Display_logic(F("Initializing..."),1);
        delay(50);

        //I2C start
        Wire.begin();
        //I2C Transportation Set LED Current
        Wire.beginTransmission(26);
        Wire.write(byte(0xCB)); // write 0x4B 3 bytes to Set LED Current
        Wire.write(current, 3);
        Wire.endTransmission();
        delay(50);
        SetDLP(DLP);
        //digitalWrite(OLED_RESET,1);
        // display.clearDisplay();
        // display.setTextSize(3);
        // display.setTextColor(WHITE);
        // display.setCursor(0, 4);
        // display.println(F("NEPHO3D"));
        // display.display();
        // delay(50);
        // set the data rate for the b9SoftwareSerial port
        // projectorSerial.begin(9600);
        ulLastCmdReceivedTime = millis(); // initilized
        // ulLastProjectorMsgRcvdTime = millis();

        // set up stepper motor timer, iZDriveSpeedCmd is in RPM's
        // if iZDriveSpeedCmd =120 RPM then that's 2 Revs per second
        // The timer must fire twice per step (rise/fall) and there are 200 steps per rev
        // So for 120 RPM, thats 2 revs per sec, which is 400 steps per sec and each step requires the timer to fire twice
        // giving us a requirement to fire 800 time per second so the timer must fire every 0.00125 seconds which is once
        // every 1250 micro seconds (1 million micro seconds in a second).  1250 * 120 = 150,000.
        Timer1.initialize(150000 / iZDriveSpeedCmd);
        // attach the motor intrupt service routine here
        Timer1.attachInterrupt(updateMotors);
        setZSpeed(iZDriveSpeedCmd);
        // setZStepMode(Z_STEP_HALF);
        ZStepRelease();

        // Read EEPROM stored settings
        loadEEPromSettings();

        // Hello World....
        BC_V();
        bVerbose = false;
        BC_A(); // Projector control
        BC_I(); // Printer Units PU
        BC_J(); // Shutter available
        BC_K(); // Lamp Half Life
        BC_M(); // Max allowed Z position in PU
        BC_R(); // Reset Status


// #if (SSD1306_LCDHEIGHT != 32)
// #error("Height incorrect, please fix Adafruit_SSD1306.h!");
// #endif
        BC_Y(); // Z Home Reference
        BC_Z(); // Current Z Position
        BC_D(); // Projector's X Resolution
        BC_E(); // Projector's Y Resolution
        BC_H(); // Calibrated XY Pixel Size in Microns
}

///////////////////////////////////////////////////////
//
// Main Event Loop
//

void loop()
{

        LED_Breath(FLAG_raspiStartup);

        // Handle Manual input events
        if (bEnableManual == true)
        {

                // Control Z axis Stepper
                if (!digitalRead(A0 /*21*/))
                { // Commanded to go lower, -Z
                        iTargetPos = iCurPos - 1;
                        iZStatus = 0;
                }
                else if (!digitalRead(A1 /*20*/))
                { // Commanded to higher, +Z
                        iTargetPos = iCurPos + 1;
                        iZStatus = 0;
                        //val1=4;DUOJI=true;
                }
        }

        // Have we arrived at a target Z Position?
        if (iZStatus == 2)
        {
                iZStatus = 1;
                BC_Z();
        }

        // Reset Home requested?
        if (bFindZero == true)
        { // This is the main reset event
                bReset = false;
                bFindZero = false;
                setZero(false);
                //    resetSlideUnknown();
                //    setSlideZero();
                bReset = true;
                iLastCuredPos = 0;
                iZStatus = 2;
                BC_R();
        }

        // Handle Build Cycles
        HandleBuildCycles();

        // Any news from the Projector?
        //  if((iZStatus != Z_MOVING)&&(iSlideStatus != SLIDE_POWERED)) // Only check if we're not busy with moving parts!
        // if ((iZStatus != Z_MOVING)) // Only check if we're not busy with moving parts!
                // HandleProjectorComm_Vivitek_D535();

        // Handle Time Based Broadcasts
        HandleTimedBroadcasts();
}

//////////////////////////////////////////////////////////////
//
// SerialEvent occurs whenever a new data comes in the
// hardware serial RX.  This routine is run each
// time loop() runs, so using delay inside loop can delay
// response.  Multiple bytes of data may be available.
//
void serialEvent()
{
        int i, iDiff;
        char cInChar;
        float fPercent, fRange, fPos;
        int iNewPos;
        ulLastCmdReceivedTime = millis(); // set to time of serialEvent

        if (Serial.available())
        {
                // get the new byte:
                cInChar = (char)Serial.read();
                switch (cInChar)
                {

                        case 'a': // Request Acknowledgement
                        case 'A':
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command:  Acknowledge"); &__c[0];})))));
                                BC_V(); // Version & Model info
                                BC_A(); // Projector control
                                BC_J(); // Shutter available
                                BC_I(); // Printer Units PU
                                BC_K(); // Lamp Half Life
                                BC_M(); // Max allowed Z position in PU
                                BC_R(); // Reset Status
                                BC_Y(); // Z Home Reference
                                //        BC_S();  // Current Slide Position
                                BC_Z(); // Current Z Position
                                BC_D(); // Projector's X Resolution
                                BC_E(); // Projector's Y Resolution
                                BC_H(); // Calibrated XY Pixel Size in Microns
                                break;

                        case 'b': // Position to build Base layer
                        case 'B':
//                                projectorReset();
                                bEnableManual = false;
                                iLastCuredPos = 0;
                                iNextCurePos = SerialReadInt();
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Cycle to initial Base Layer at: "); &__c[0];})))), String(iNextCurePos));
                                //        iSlideSpeed = iSlideOpenSpeed;
                                //        iSlideTargetPos = SLIDEOPEN;
                                //        iSlideStatus = SLIDE_POWERED;
                                iCycle = 1;
                                //Display_logic(F("StartPrinting..."),1);
                                break;

                        case 'c': // Request current Status
                        case 'C':
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command:  Request Current Status"); &__c[0];})))));
                                BC_Z();
                                //        BC_S();
                                break;

                        case 'd': // Set Delay (Breathe) time, a pause before opening shutter
                        case 'D':
                                i = SerialReadInt();
                                if (i >= 0 && i <= 60000)
                                        ulBreatheDur = i;
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Breathe Delay set to "); &__c[0];})))), String(ulBreatheDur));
                                break;

                        case 'e': // Set "settle" Delay time, a pause before sending "Cycle Complete"
                        case 'E':
                                i = SerialReadInt();
                                if (i >= 0 && i <= 60000)
                                        ulSettleDur = i;
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Settle Delay set to "); &__c[0];})))), String(ulSettleDur));
                                break;

                        case 'f': // Position after building Final layer
                        case 'F':
                                bEnableManual = false;
                                iLastCuredPos = iNextCurePos;
                                iNextCurePos = SerialReadInt();
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Release and move to final position at: "); &__c[0];})))), String(iNextCurePos));
                                //        iSlideSpeed = iSlideCloseSpeed;
                                //        iSlideTargetPos = SLIDECLOSED;
                                //        iSlideStatus = SLIDE_POWERED;
                                iCycle = 8;
                                break;

                        case 'g': // Goto Z position
                        case 'G':
                                setZSpeed(iZDriveSpeedCmd);
                                i = SerialReadInt();
                                while (lastStepPulse == 0x1)
                                {
                                        delay(1);
                                } // wait until step LOW
                                iTargetPos = i;

                                if (iTargetPos > iUpperZLimit)
                                        iTargetPos = iUpperZLimit;
                                else if (iTargetPos < iLowerZLimit)
                                        iTargetPos = iLowerZLimit;
                                iZStatus = 0;
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Goto Z position at: "); &__c[0];})))), String(iTargetPos));
                                break;

                        // case 'h': // Reset the projectors native X Resolution
                        // case 'H':
                        //         i = SerialReadInt();
                        //         if (i >= 0)
                        //         {
                        //                 iNativeX = i;
                        //                 storeRefNativeX(); // store new value in persistant EEPROM
                        //         }
                        //         BC_C(F("Command: Native X Resolution Set To "), String(iNativeX));
                        //         break;

                        case 'i': // Reset the projectors native Y Resolution
                        case 'I':
                                i = SerialReadInt();
                                if (i >= 0)
                                {
                                        iNativeY = i;
                                        storeRefNativeY(); // store new value in persistant EEPROM
                                }
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Native Y Resolution Set To "); &__c[0];})))), String(iNativeY));
                                break;

                        case 'j': // Set Cycle Ready Gap
                        case 'J':
                                i = SerialReadInt();
                                if (i >= 0 && i <= 1500)
                                        iReadyGap = i;
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Reposition Gap set to: "); &__c[0];})))), String(iReadyGap));
                                break;

                        case 'k': // Set Print Cycle Raise Speed
                        case 'K':
                                i = SerialReadInt();
                                if (i >= 1 && i <= 300)
                                {
                                        // float dPercent = (float)i/100.0;
                                        //float dRange = Z_MAXSPEED - Z_MINSPEED;
                                        // iRaiseSpeed = (dPercent * dRange) + Z_MINSPEED;
                                        iRaiseSpeed = i;
                                        //BC_C(F("Command: Percent Raise Speed Set To "), String(i));
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: RPM Raise Speed Set To "); &__c[0];})))), String(iRaiseSpeed));
                                }
                                else
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Error, Percent Raise Speed Out of Range"); &__c[0];})))));
                                }
                                break;

                        case 'l': // Set Print Cycle Lower Speed
                        case 'L':
                                i = SerialReadInt();
                                if (i > 1 && i <= 300)
                                {
                                        //float dPercent = (float)i/100.0;
                                        //float dRange = Z_MAXSPEED - Z_MINSPEED;
                                        //iLowerSpeed = (dPercent * dRange) + Z_MINSPEED;
                                        iLowerSpeed = i;
                                        //BC_C(F("Command: Percent Lower Speed Set To "), String(i));
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: RPM Lower Speed Set To "); &__c[0];})))), String(iLowerSpeed));
                                }
                                else
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Error, Percent Lower Speed Out of Range"); &__c[0];})))));
                                }
                                break;

                        case 'm': // Toggle Manual Contol Activation
                        case 'M':
                                i = SerialReadInt();
                                if (i > 0)
                                {
                                        bEnableManual = true;
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Manual Controls Activated."); &__c[0];})))));
                                }
                                else
                                {
                                        bEnableManual = false;
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Manual Controls Deactivated."); &__c[0];})))));
                                }
                                break;

                        case 'n': // Release and Position to build next Layer
                        case 'N':
                                bEnableManual = false;
                                iDiff = iNextCurePos - iLastCuredPos; // The last increment, we should be similar this time
                                iLastCuredPos = iNextCurePos;
                                iNextCurePos = SerialReadInt();
                                if (iNextCurePos < iLastCuredPos)
                                { // This should never happen, but if it does reset iNextCurePos to use the last increment
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("ERROR:  Invalid Command: Release and cycle to Next Layer at: "); &__c[0];})))), String(iNextCurePos));
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("NOTE:  Reset Next Cure Position to last cure position + last increment."); &__c[0];})))));
                                        iNextCurePos = iLastCuredPos + iDiff;
                                }
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Release and cycle to Next Layer at: "); &__c[0];})))), String(iNextCurePos));
                                //        iSlideSpeed = iSlideCloseSpeed;
                                iCycle = 5;
                                //        iSlideTargetPos = SLIDECLOSED;
                                //        iSlideStatus = SLIDE_POWERED;
                                break;

                        case 'o': // Set the current position to xxxx, use with caution!
                        case 'O':
                                i = SerialReadInt();
                                if (i >= -1000 && i <= iUpperZLimit)
                                { // 1 to iUpperZLimit valid range
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Resetting current Z position to: "); &__c[0];})))), String(i));
                                        iTargetPos = iCurPos = i;
                                        iNextCurePos = iLastCuredPos = i; //Reseting this incase we're in the middle of a print
                                        bReset = true; // not realy, but we are tricking the system into believing it knows where it's at
                                        BC_Z();
                                }
                                else
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Error: Reset current Z position value out of limits.  Ignored."); &__c[0];})))));
                                }
                                break;

                        case 'p': // Projector Power & Mode commands
                        case 'P':
                                i = SerialReadInt();
                                if (i == 0)
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Turning Projector OFF"); &__c[0];})))));
                                        // projectorSerial.write("\r$pow=off#\r");
                                        //            projectorSerial.write("V99S0002");//poweroff
                                        DLP = false;
                                        SetDLP(DLP);
                                        FLAG_raspiStartup = 1;
                                }
                                else if (i == 1)
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Turning Projector ON"); &__c[0];})))));
                                        // projectorSerial.write("\r$pow=on#\r");
                                        //projectorSerial.write("V99S0001\r");//poweron
                                        //iProjectorPwr =1;
                                        DLP = true;
                                        SetDLP(DLP);
                                }
                                break;

                        case 'q': // Set Broadcast interval in milliseconds, 0 = disabled
                        case 'Q':
                                i = SerialReadInt();
                                if (i == 0)
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Turning Broadcasts OFF"); &__c[0];})))));
                                        iBC_Interval = i;
                                }
                                else if (i > 999 && i < 60001)
                                { // 1 to 60 sec valid range
                                        iBC_Interval = i;
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Broadcast Interval set to: "); &__c[0];})))), String(iBC_Interval));
                                        ulLastTimedBroadcastTime = 0;
                                }
                                else
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Broadcast Interval is: "); &__c[0];})))), String(iBC_Interval));
                                }
                                break;

                        case 'r': // Reset Home
                        case 'R':
                                i = SerialReadInt();
                                if (i == 99)
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Reset Factory Defaults"); &__c[0];})))));
                                        resetFactoryDefaults();
                                }
                                else
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Reset Home Positions"); &__c[0];})))));
                                        bFindZero = true;
                                        iCycle = 0;
                                        bEnableManual = true;
                                        //Display_logic(F("StartPrinting..."),1);

                                }
                                break;

                        case 's': // Stop all motion, activate manual controls
                        case 'S':
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: STOP"); &__c[0];})))));
                                iCycle = 0;
                                bEnableManual = true;
                                //        iSlideTargetPos = iSlideCurPos;
                                while (lastStepPulse == 0x1)
                                {
                                        delay(1);
                                } // wait until step LOW
                                //Display_logic(F("Paused..."),2);
                                iTargetPos = iCurPos;
                                break;

                        case 't': // Toggle verbose Text Comments
                        case 'T':
                                i = SerialReadInt();
                                if (i > 0)
                                {
                                        bVerbose = true;
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Verbose Text Comments Activated."); &__c[0];})))));
                                }
                                else
                                {
                                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Verbose Text Comments Deactivated."); &__c[0];})))));
                                        bVerbose = false;
                                }
                                break;

                        // case 'u': // Reset the projectors calibrated xy pixel size in microns
                        // case 'U':
                        //         i = SerialReadInt();
                        //         if (i >= 0)
                        //         {
                        //                 iXYPixelSize = i;
                        //                 storeRefXYPixelSize(); // store new value in persistant EEPROM
                        //         }
                        //         BC_C(F("Command: Calibrated XY Pixel Size Set To "), String(iXYPixelSize));
                        //         break;

                        // case 'v': // Set Vat Position (0 - 100 %)
                        // case 'V':
                        //         if (!bReset)
                        //         {
                        //                 BC_C(F("ERROR: Must reset home first!"));
                        //                 return;
                        //         }; //Must reset first
                        //         BC_C(F("Hello how are you!"));
                        //         break;

                        case 'w': // Set Print Cycle Opening Speed
                        case 'W':
                                i = SerialReadInt();
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Hello how are W"); &__c[0];})))));
                                break;

                        case 'x': // Set Print Cycle Closing Speed
                        case 'X':
                                i = SerialReadInt();
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Hello how are x"); &__c[0];})))));
                                break;

                        case 'y': // Reset z Axis home reference
                        case 'Y':
                                i = SerialReadInt();
                                iDiff = i - iRefZeroOffset;
                                if (i > 0)
                                {
                                        iCurPos += iDiff;
                                        iTargetPos = iCurPos;
                                        iRefZeroOffset = i;
                                        storeRefZOffset(); // store new value in persistant EEPROM
                                }
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Command: Z Home Reference Set To "); &__c[0];})))), String(iRefZeroOffset));
                                break;

                        case 'z': // Set Z Axis speed
                        case 'Z':
                                i = SerialReadInt();
                                if (i >= 1 && i <= 300)
                                        iZDriveSpeedCmd = i;
                                setZSpeed(iZDriveSpeedCmd);
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Current z Drive Speed set to "); &__c[0];})))), String(iZDriveSpeedCmd));
                                break;

                        // case '$': // Reset Projector's Half Life value
                        //         i = SerialReadInt();
                        //         if (i > 0)
                        //         {
                        //                 iHalfLife = i;
                        //                 storeHalfLife(); // store new value in persistant EEPROM
                        //         }
                        //         BC_C(F("Command: Lamp Half Life Set to: "), String(iHalfLife));
                        //         break;
                        case '#':
                                break;
                        case '@':
                                i = SerialReadInt();
                                if (i >= 0 && i <= 255)
                                {

                                        if (0 == i || i == current[2])
                                        {
                                            DLP = (i == 0)?false:true;
                                            SetDLP(DLP);
                                        }
                                        else
                                        {
                                            current[0] = 255;
                                            current[1] = 255;
                                            current[2] = 255 - i;
                                            Wire.beginTransmission(26);
                                            Wire.write(byte(0xCB));
                                            Wire.write(current, 3);
                                            Wire.endTransmission(true);
                                            SetDLP(true);
                                        }

                                }
                                else
                                        break;
                                break;
                        default:
                                break;
                }
        }
}

///////////////////////////////////////////////////////
//
//  Handle Build Cycles
//
void HandleBuildCycles()
{
        switch (iCycle)
        {
                case 1:
                        //      if(iSlideStatus==SLIDE_ARRIVED){
                        // We've reached the open position
                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Shutter Open"); &__c[0];})))));
                        if (iCurPos != iNextCurePos)
                        { // we need to lower down to the next cure position
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Lowering Platform to next layer position."); &__c[0];})))));
                                iTargetPos = iNextCurePos;
                                setZSpeed(iLowerSpeed);
                                iZStatus = 0;
                        }
                        iCycle = 2;
                        //      }
                        break;

                case 2:
                        if (iCurPos == iTargetPos)
                        {
                                // We've reached the Lowered position
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Lowered.  Pausing for settle..."); &__c[0];})))));
                                ulSettleStart = millis();
                                iCycle = 3;
                                //myservo.write(90);
                        }
                        break;

                case 3:

                        if (millis() - ulSettleStart > ulSettleDur)
                        {
                                // We've reached the end of our settling duration
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Settle Pause Finished.  Ready to Expose."); &__c[0];})))));
                                BC_F();
                                iCycle = 4;
                                DLP = true;
                                SetDLP(DLP);
                        }
                        break;

                case 5:

                        //      if(iSlideStatus==SLIDE_ARRIVED){
                        // We've reached the closed position
                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Released, Shutter Closed"); &__c[0];})))));
                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Raising Platform to next layer position + clearance Gap."); &__c[0];})))));
                        iTargetPos = iNextCurePos + iReadyGap; // Never lower with a part in process!
                        if (iTargetPos < 0)
                                iTargetPos = 0;
                        setZSpeed(iRaiseSpeed);
                        iZStatus = 0;
                        iCycle = 6;
                        DLP = false;
                        SetDLP(DLP);
                        //      }
                        break;

                case 6:
                        if (iCurPos == iTargetPos)
                        {
                                // We've reached the Raised position
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Raised.  Pausing for breathe..."); &__c[0];})))));
                                ulBreatheStart = millis();
                                iCycle = 7;
                                //myservo.write(0);
                        }
                        break;

                case 7:
                        if (millis() - ulBreatheStart > ulBreatheDur)
                        {
                                // We've reached the end of our breathing duration
                                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Breathe Pause Finished.  Opening Shutter."); &__c[0];})))));
                                //        iSlideSpeed = iSlideOpenSpeed;
                                //        iSlideTargetPos = SLIDEOPEN;
                                //        iSlideStatus = SLIDE_POWERED;
                                iCycle = 1;
                        }
                        break;

                case 8:
                        //      if(iSlideStatus==SLIDE_ARRIVED){
                        // We've reached the closed position
                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Released"); &__c[0];})))));
                        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Raising Platform to final position."); &__c[0];})))));
                        if (iNextCurePos > iCurPos)
                                iTargetPos = iNextCurePos; // Never lower with a part in process!
                        setZSpeed(iRaiseSpeed);
                        iZStatus = 0;
                        iCycle = 0;
                        //      }
                        DLP = false;
                        SetDLP(DLP);
                        // projectorSerial.write("\r$pow=off#\r");
                        //projectorSerial.write("V99S0002");//poweroff
                        break;

                case 4:
                        break;

                case 0:
                        if (iCurPos == iTargetPos && bEnableManual == false)
                        {
                                // We've reached the Raised position, last step of the F command
                                bEnableManual = true;
                                setZSpeed(iZDriveSpeedCmd);
                                BC_F();
                        }
                        break;

                default:
                        break;
        }
}

///////////////////////////////////////////////////////
//
// Initialize the IO parameters
void setupIO()
{
        // pinMode(INIT_DOWN, INPUT_PULLUP);

        // Projector RS-232 serial I/O
        // pinMode(PROJECTOR_RX, INPUT);
        // PCintPort::attachInterrupt(PROJECTOR_RX, &projectorRxChange, CHANGE);
        // pinMode(PROJECTOR_TX, OUTPUT);

        pinMode(A0 /*21*/, 0x2); // DOWN
        // digitalWrite(B_DOWN, HIGH); // Set pull up resistor
        pinMode(A1 /*20*/, 0x2); // UP
        // digitalWrite(B_UP, HIGH);   // Set pull up resistor

        pinMode(8 /*19*/, 0x2); // Z = zero sensor
        // pinMode(OLED_RESET, OUTPUT);     // Z = zero sensor
        // digitalWrite(Z_HOME, HIGH); // Set pull up resistor

        pinMode(4, 0x1);
        pinMode(5, 0x1);
        pinMode(6, 0x1);

        // pinMode(Z_MS1, OUTPUT);
        // pinMode(Z_MS2, OUTPUT);
        // pinMode(Z_MS3, OUTPUT);
        //LEDBREATH_CONFIG
        pinMode(11, 0x1);

}


///////////////////////////////////////////////////////
//
// setZero moves the build table to find the optical
// switch reference point.
//
void setZero(bool bFromAbove)
{
        setZSpeed(200);
        if (digitalRead(8 /*19*/))
        {
                // Below zero
                do
                {
                        if (digitalRead(8 /*19*/) && iTargetPos != iCurPos + 1)
                                iTargetPos = iCurPos + 1;
                } while (digitalRead(8 /*19*/));
                do
                {
                        delay(1);
                } while (iTargetPos != iCurPos);
                setZero(true); // Always find zero from above
                return;
        }
        else
        {
                // Above zero
                do
                {
                        if (!digitalRead(8 /*19*/) && iTargetPos != iCurPos - 1)
                                iTargetPos = iCurPos - 1;
                } while (!digitalRead(8 /*19*/));
                do
                {
                        delay(1);
                } while (iTargetPos != iCurPos);
                if (!bFromAbove)
                {
                        setZero(false);
                        return;
                }
        }
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Found Zero at:  "); &__c[0];})))), String(iCurPos));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Reset Zero to:  "); &__c[0];})))), String(iRefZeroOffset));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Difference of:  "); &__c[0];})))), String(iCurPos - iRefZeroOffset));
        if (bReset)
                BC_X(iCurPos - iRefZeroOffset);
        else
                BC_X(0);

        iCurPos = iRefZeroOffset;
        iTargetPos = iCurPos;
        setZSpeed(iZDriveSpeedCmd);
        ZStepRelease();
}

///////////////////////////////////////////////////////
//
// Drive iCurPos towards iTargetPos
// Drive iSlideCurPos towards iSlideTargetPos
// Called 800 times per second when z speed is 120 rpm
// Called 66.7 times per second when z speed is 10 rpm
// Called 933.3 times per second when z speed is 140 rpm
void updateMotors()
{
        if (iCurPos > iTargetPos) // We need to head down, -Z
        {
                digitalWrite(4, 0x0);
                ZStep(0x1);
        }
        else if (iCurPos < iTargetPos) // We need to head up, +Z
        {
                digitalWrite(4, 0x0);
                ZStep(0x0);
        }
        else if ((iCurPos == iTargetPos) && (iZStatus == 0))
        {
                delay(8);
                ZStepRelease();
                delay(5);
                iZStatus = 2;
        }
}

///////////////////////////////////////////////////////
//
// Reset the timer for stepper motor updates to
// control rpm
void setZSpeed(int iRPM)
{
        Timer1.setPeriod(150000 / iRPM);
}

///////////////////////////////////////////////////////
//
// Release the Z Stepper Motor
//
void ZStepRelease()
{
        //while(lastStepPulse==HIGH){delay(1);} // wait until step LOW
        digitalWrite(4, 0x1);
        digitalWrite(6, 0x0);
        digitalWrite(5, 0x0);
        lastStepPulse = 0x0;
}

///////////////////////////////////////////////////////
//
// Step once, update position
//
void ZStep(int iDir)
{
        if (lastStepPulse == 0x0)
        {
                digitalWrite(6, iDir);
                digitalWrite(4, 0x0);
                digitalWrite(5, 0x1);
                lastStepPulse = 0x1;
        }
        else
        {
                digitalWrite(6, iDir);
                digitalWrite(4, 0x0);
                digitalWrite(5, 0x0);
                lastStepPulse = 0x0;
                if (iDir == 0x1)
                        iCurPos--;
                else
                        iCurPos++;
        }
}

///////////////////////////////////////////////////////
//
// Set the Z Stepper mode
//

// void setZStepMode(int iMode)
// {
//         switch (iMode)
//         {
//                 default:
//                 case Z_STEP_FULL:
//                         digitalWrite(Z_MS1, LOW);
//                         digitalWrite(Z_MS2, LOW);
//                         digitalWrite(Z_MS3, LOW);
//                         break;
//                 case Z_STEP_HALF:
//                         digitalWrite(Z_MS1, HIGH);
//                         digitalWrite(Z_MS2, LOW);
//                         digitalWrite(Z_MS3, LOW);
//                         break;
//                 case Z_STEP_QTR:
//                         digitalWrite(Z_MS1, LOW);
//                         digitalWrite(Z_MS2, HIGH);
//                         digitalWrite(Z_MS3, LOW);
//                         break;
//                 case Z_STEP_8TH:
//                         digitalWrite(Z_MS1, HIGH);
//                         digitalWrite(Z_MS2, HIGH);
//                         digitalWrite(Z_MS3, LOW);
//                         break;
//                 case Z_STEP_16TH:
//                         digitalWrite(Z_MS1, HIGH);
//                         digitalWrite(Z_MS2, HIGH);
//                         digitalWrite(Z_MS3, HIGH);
//                         break;
//         }
// }

///////////////////////////////////////////////////////
//
// pull and return an int off the serial stream
//
int SerialReadInt()
{
        // The string we read from Serial will be stored here:
        char task[7];
        char str[32];
        str[0] = '\0';
        int i = 0;
        int j = 0;
        while (true)
        {
                // See if we have serial data available:
                if (Serial.available() > 0)
                {

                        str[i] = Serial.read();

                if (str[i] == 'C' )
                {
                        str[i]='\0';
                        j = i + 1;
                }
                else if (str[i] == 'A')
                {
                        //Display_logic(F("Aborted"),2);
                }
                else if (str[i] == 'F')
                {
                        //Display_logic(F("Finished"),2);
                }
                else if (str[i] == '\n' || str[i] == '\0' || i == 31)
                {
                        str[i] = '\0';
                        break;
                }
                i++;

                }

        }
        if(j>1)//from j = i + 1
        {
               String current_layer = "";
               String time_left = "";
               int t = 0;
               while (j < 31)
               { if (str[j] != 'T' && t == 0)
                        {
                                current_layer += str[j];
                        }
                        else if(str[j] != '\0' && str[i] != '\n')
                        {
                                t = j + 1;
                                time_left += str[t];
                        }
                        else break;
                        j++;

               }
              //Display_logic("Layer:"+current_layer+"\n"+"TimeRemaining:"+time_left,1);

        }

        return (atoi(str));
}


//////////////////////////////////////////////////////////////
//
// Handle the time based regular broadcasts
//
void HandleTimedBroadcasts()
{
        if (iBC_Interval > 0 && millis() - ulLastTimedBroadcastTime > iBC_Interval)
        {
                ulLastTimedBroadcastTime = millis();

                BC_P(); // Broadcast Power Status
                //     BC_String(F("P1"));
                //     BC_String(F("P0"));
                BC_L(); // Broadcast Lamp Hours (if Power is on)

                // If we are in a print cycle and the exposure time exceeds the watchdog limit
                // Then we abort the print cycle
                if (iCycle != 0 && millis() - ulLastCmdReceivedTime > 240000 /* 240 seconds*/)
                {
                        BC_Q(); // Broadcast Print Cycle Abort Watchdog alert
                        iCycle = 0; // abort the print cycle, Stop z axis motion, close the Shutter
                        iCycle = 0;
                        //      projectorSerial.write("~PF\r");  // Power down the projector
                        //projectorSerial.write("\r$pow=off#\r");
                        delay(1000);
                        //      iSlideTargetPos = SLIDECLOSED;
                        while (lastStepPulse == 0x1)
                        {
                                delay(1);
                        } // wait until step LOW
                        iTargetPos = iCurPos;
                        bEnableManual = true;
                }
        }
}


void loadEEPromSettings()
{
        int schema;
        EEPROM_readAnything(0, schema);

        // Set defaults
        iRefZeroOffset = 3100;
        iNativeX = 1024;
        iNativeY = 768;
        iXYPixelSize = 100;
        iHalfLife = 2000 /* Hours before projector lamp output is reduced to 1/2 original value*/;

        if (schema > 99 && schema < 112)
        { // Load interesting old schema data first
                EEPROM_readAnything(2, iRefZeroOffset);
                EEPROM_readAnything(4, iNativeX);
                EEPROM_readAnything(6, iNativeY);
                EEPROM_readAnything(8, iXYPixelSize);
                EEPROM_readAnything(10, iHalfLife);
        }

        if (iNativeX < 1024 || iNativeY < 768)
        { //The interesting old data has been corrupted?  Restore defaults
                iRefZeroOffset = 3100;
                iNativeX = 1024;
                iNativeY = 768;
                iXYPixelSize = 100;
                iHalfLife = 2000 /* Hours before projector lamp output is reduced to 1/2 original value*/;
                schema = -1; // force storeDefaults()
        }

        if (schema != 112)
        {
                storeDefaults();
        }
        else
        { // load current defaults
                EEPROM_readAnything(2, iRefZeroOffset);
                EEPROM_readAnything(4, iNativeX);
                EEPROM_readAnything(6, iNativeY);
                EEPROM_readAnything(8, iXYPixelSize);
                EEPROM_readAnything(10, iHalfLife);
                // Add more default loads here...
        }
}

void storeDefaults()
{
        // Default never burned.  Store the defaults
        EEPROM_writeAnything(0, 112);
        EEPROM_writeAnything(2, iRefZeroOffset);
        EEPROM_writeAnything(4, iNativeX);
        EEPROM_writeAnything(6, iNativeY);
        EEPROM_writeAnything(8, iXYPixelSize);
        EEPROM_writeAnything(10, iHalfLife);
        // Add more defaults here... Make sure address accounts for size of data stored
}

void resetFactoryDefaults()
{
        iRefZeroOffset = 3100;
        iNativeX = 1024;
        iNativeY = 768;
        iXYPixelSize = 100;
        iHalfLife = 2000 /* Hours before projector lamp output is reduced to 1/2 original value*/;
        storeDefaults();
}

void storeRefZOffset()
{
        EEPROM_writeAnything(2, iRefZeroOffset);
}
void storeRefNativeX()
{
        EEPROM_writeAnything(4, iNativeX);
}
void storeRefNativeY()
{
        EEPROM_writeAnything(6, iNativeY);
}
void storeRefXYPixelSize()
{
        EEPROM_writeAnything(8, iXYPixelSize);
}
void storeHalfLife()
{
        EEPROM_writeAnything(10, iHalfLife);
}

//////////////////////////////////////////////////////////////
//
// Broadcast Commands
//

//////////////////////////////////////////////////////////////
void BC_String(String sString)
{
        Serial.println(sString);
}

//////////////////////////////////////////////////////////////
void BC_String(const __FlashStringHelper *s, String sVariable)
{
        Serial.print(s);
        Serial.println(sVariable);
}

//////////////////////////////////////////////////////////////
void BC_A()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("A1"); &__c[0];})))));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Projector Control:  Available"); &__c[0];})))));
}

//////////////////////////////////////////////////////////////
void BC_C(String sComment)
{
        if (bVerbose)
        {
                BC_String("C" + sComment);
        }
}
void BC_C(const __FlashStringHelper *s, String sVariable)
{
        if (bVerbose)
        {
                Serial.print("C");
                Serial.print(s);
                Serial.println(sVariable);
        }
}

//////////////////////////////////////////////////////////////
void BC_D()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("D"); &__c[0];})))), String(iNativeX));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Projector's Native X Resolution: "); &__c[0];})))), String(iNativeX));
}

//////////////////////////////////////////////////////////////
void BC_E()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("E"); &__c[0];})))), String(iNativeY));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Projector's Native Y Resolution: "); &__c[0];})))), String(iNativeY));
}

//////////////////////////////////////////////////////////////
void BC_F()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("F"); &__c[0];})))));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Cycle Finished."); &__c[0];})))));
}

//////////////////////////////////////////////////////////////
void BC_H()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("H"); &__c[0];})))), String(iXYPixelSize));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Calibrated XY Pixel Size in Microns: "); &__c[0];})))), String(iXYPixelSize));
}

//////////////////////////////////////////////////////////////
void BC_I()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("I1000"); &__c[0];}))))); //BC_String(F("I635"));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Printer Unit: 1000"); &__c[0];}))))); //BC_C(F("Printer Unit: 635"));
}

//////////////////////////////////////////////////////////////
void BC_J()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("J1"); &__c[0];})))));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Shutter Control: Available"); &__c[0];})))));
}

//////////////////////////////////////////////////////////////
void BC_K()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("K"); &__c[0];})))), String(iHalfLife));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Estimated hours before lamp output is 1/2 of original value: "); &__c[0];})))), String(iHalfLife));
}

//////////////////////////////////////////////////////////////
void BC_L()
{
        if (iLampHours >= 0 && iProjectorPwr > 0)
        {
                BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("L"); &__c[0];})))), String(iLampHours));
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Lamp Hours: "); &__c[0];})))), String(iLampHours));
        }
}

//////////////////////////////////////////////////////////////
void BC_M()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("M"); &__c[0];})))), String(iUpperZLimit));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Maximum Z in PU: "); &__c[0];})))), String(iUpperZLimit));
}

//////////////////////////////////////////////////////////////
void BC_P()
{
        if (iProjectorPwr < 1)
        {
                BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("P0"); &__c[0];})))));
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Projector is Off"); &__c[0];})))));
                //SetDLP(false);
        }
        else
        {
                BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("P1"); &__c[0];})))));
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Projector is On"); &__c[0];})))));
        }
}

//////////////////////////////////////////////////////////////
void BC_Q()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Q"); &__c[0];})))));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Print Cycle ABORT.  Host COMM Lost"); &__c[0];})))));
}

//////////////////////////////////////////////////////////////
void BC_R()
{
        if (bReset)
        {
                BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("R0"); &__c[0];})))));
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Needs Reset: NO"); &__c[0];})))));
        }
        else
        {
                BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("R1"); &__c[0];})))));
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Needs Reset: YES"); &__c[0];})))));
        }
}

//////////////////////////////////////////////////////////////
//void BC_S() {
//  float fRange = SLIDEOPEN - SLIDECLOSED;
//  int iPercentOpen = (int)(100.0 * (float)iSlideCurPos / fRange);
//  BC_String(F("S"), String(iPercentOpen));
//  BC_C(F("Current Slide Percent Open is: "), String(iPercentOpen));
//}

//////////////////////////////////////////////////////////////
void BC_U(int iFault)
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("U"); &__c[0];})))), String(iFault));
        if (iFault == 1)
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("ERROR:  Runaway X Mtr, Counter Clockwise"); &__c[0];})))));
        if (iFault == 2)
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("ERROR:  Runaway X Mtr, Clockwise"); &__c[0];})))));
        if (iFault == 3)
                BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("ERROR:  Runaway X Mtr, Bad Sensor"); &__c[0];})))));
}

//////////////////////////////////////////////////////////////
void BC_V()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("V1 1 2"); &__c[0];})))));
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("WB9C1"); &__c[0];})))));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Nepho3D Firmware version 1.1.2 running on a Nepho3D Model"); &__c[0];})))));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Copyright 2018, 2019 Nepho3D, LLC"); &__c[0];})))));
       // BC_C(F("B9Creations(tm) and B9Creator(tm) are trademarks of B9Creations, LLC"));
       // BC_C(F("This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License."));
       // BC_C(F("To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/"));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("For updates and to download the lastest version, visit http://Nepho3d.com"); &__c[0];})))));
}

//////////////////////////////////////////////////////////////
void BC_X(int iDiff)
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("X"); &__c[0];})))), String(iDiff));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Reset Compelete with Z Diff of:"); &__c[0];})))), String(iDiff));
}

//////////////////////////////////////////////////////////////
void BC_Y()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Y"); &__c[0];})))), String(iRefZeroOffset));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Current Z Home Value:"); &__c[0];})))), String(iRefZeroOffset));
}

//////////////////////////////////////////////////////////////
void BC_Z()
{
        BC_String((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Z"); &__c[0];})))), String(iCurPos));
        BC_C((reinterpret_cast<const __FlashStringHelper *>((__extension__({static const char __c[] __attribute__((__progmem__)) = ("Current Z Position is: "); &__c[0];})))), String(iCurPos));
}
// define the DLP mode
void SetDLP(bool DLP)
{
        if(DLP==true)
        {
         Wire.beginTransmission(26);
         Wire.write(byte(0x90));//LED_Enable 0x10 write 0x4 to turn on the Blue LED display
         Wire.write(byte(0x04));
         Wire.endTransmission(true);
        //  Serial.println("I2C second");
         //BC_V();
        }
        else
        {
         Wire.beginTransmission(26);
         Wire.write(byte(0x90));//LED_Enable 0x10 write 0x0 to turn off all colors of LEDs
         Wire.write(byte(0x00));
         Wire.endTransmission(true);
        //  Serial.println("I2C third"); 
         //BC_V();
        }
}

void LED_Breath(int FLAG_raspiStartup)
{
        //
        for (int value = 1 ; (value < 255) && (FLAG_raspiStartup == 0); value++){
                analogWrite(11, value);
                delay(5);
        }
        for (int value = 255 ; (value >1) && (FLAG_raspiStartup == 0); value--){
                analogWrite(11, value);
                delay(5);
        }
        analogWrite(11, 255);
}
