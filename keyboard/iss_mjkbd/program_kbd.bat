@ECHO OFF

REM ECHO Set serial port mode 1200
REM mode COM23:1200,N,8,1,P

REM ECHO Wait 2 seconds
REM ping -n 2 localhost

ECHO Program
D:\programming\arduino\ide\hardware\tools\avr\bin\avrdude -V "-CD:\programming\arduino\ide\hardware\tools\avr\etc\avrdude.conf" -v -patmega32u4 -cavr109 -PCOM24 -b57600 -D "-Uflash:w:iss_mjkbd_lufa_tkl_v2.hex:i" "-Ueeprom:w:iss_mjkbd_lufa_tkl_v2.eep"
