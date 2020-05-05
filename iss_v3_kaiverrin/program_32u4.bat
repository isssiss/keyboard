REM FUSE 16MHz kide, HFUSE=DF on oletus
REM c:\apps\programming\winavr\bin\avrdude.exe -c usbtiny -p m88 -v -U lfuse:w:0xCE:m -U hfuse:w:0xDF:m 

REM SOFTAUS
c:\apps\bin\avr_program.bat atmega32u4 -v -U flash:w:iss_lufa_v3.hex:i -U eeprom:w:iss_lufa_v3.eep


PAUSE