@ECHO OFF

ECHO Set serial port mode 1200
mode COM9:1200,N,8,1,P

ECHO Wait 2 seconds
ping -n 2 localhost

ECHO Program
D:\programming\arduino\ide\hardware\tools\avr\bin\avrdude -V "-CD:\programming\arduino\ide\hardware\tools\avr\etc\avrdude.conf" -v -patmega32u4 -cavr109 -PCOM9 -b57600 -D "-Uflash:w:iss_lufa_v3.hex:i" "-Ueeprom:w:iss_lufa_v3.eep"
