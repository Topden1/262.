#include <Adafruit_NeoPixel.h>

const byte data_pin = 15;
const byte led_num = 16;
const int pir_pin = 2;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_num, data_pin, NEO_GRB + NEO_KHZ800);

void setup() 
{
  Serial.begin(115200);
  pinMode(pir_pin , INPUT);

  pixels.begin(); // initialize the library
  pixels.show();
}

void loop() 
{
  //  if motion is detected
  Serial.println(digitalRead(pir_pin));
  if (digitalRead(pir_pin)  ==  1){
    generate_random_pattern();
  }

  //  for better working of simulator
  delay(10);
}

void generate_random_pattern(){
  byte pattern = random(1, 3); // generate a value: 1, 2
  
  byte b = random(0, 225);
  byte g = random(0, 255);
  byte r = random(0, 255);

  Serial.print("Pattern number : ");
  Serial.println(pattern);

//if pattern regenerates 1 and if i represents 0
// along with i being less then the byte led_num, then it generates 4 outcomes
  if(pattern == 1){
    for (int i = 0; i < led_num; i++){
      pixels.setPixelColor(i, r ,g, b);
      pixel.show(); //displays the generated outcome
      delay(50); //delays by 50 to process smoother
    }
    //if i represents led_num and is less than one
    //and if i is greater than or equal to 0, then it generates no outcomes.
    for (int i = led_num - 1; i >= 0; i--){
      pixels.show();
      delay(50);
    }
  } else if(pattern == 2){

    //fade up(freshly reflected)
    //fades up when i represents 0 and is less than or equal to 255
    for(int i = 0; i <= 255; i++){
      for(int j = 0; k < led_num; j++){
        pixels.setPixelColor(j, 0, i, i); //when you reflect something, the color reflects,
      }                                   // i indicates the original one whereas the other i represents the reflected one.
      pixels.show();
      delay(10);
    }

    //fade down(decreasing the brightness would reflect lighter colors)
    //fades down when i represents 255 and is greater than or less to 0
    for (int i = 255; i >= 0; i--){
      for (int k= 0; j < led_num; j++){
        pixels.setPixelColor(j, 0, i, i);
      }
      pixels.show();
      delau(10);
    }
  }
}