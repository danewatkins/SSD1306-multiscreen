# SSD1306-multiscreen

Code to create multiscreen animations on 0.96 SSD1306 and 1.3 SH1106 monochrome OLEDs running from one one Wemos D1. The screens are 128 x 64 pixels. The Wemos D1 uses the Arduino 

## animation
The animations running on the OLEDs are developed in photoshop as animated gifs. I use photoshop and make them the same size as the screens, 128 x 64. The animations can be exported from photoshops as animated gifs.

Converting the photoshop file to xbm 
In order to create animations for small screens create the animation in Photoshop

The code uses the ThingPulse SSD1306 library

1. convert photoshop layers to png  
`convert puke.psd -coalesce puke%d.png`

2. convert png layers to xbm  
`mogrify -resize 128x64 +dither -format xbm *.png`

- convert xbm to file  
`cat *.xbm | sed s/static/const/ | sed s/=/PROGMEM=/  > puke.h ` 



ATOM regex search
char trash(.*)_bits

uint8_t trash$1

List files just by their names, useful for creating arrays

ls -A1
