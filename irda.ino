// Node ID: 635036282
//
//добавити управленіє пректором вклл ндмі2 і вкл викл
// добавити ше один ір модуль на прийом
// пульт від проектора
    // ok F40BFC03
    // up F609FC03
    // вниз FE01FC03
    // вліво F708FC03
    // вправо F50AFC03
    // мут FD02FC03
    // перемотка вліво FA05FC03
    // перемотка вправо F807FC03
    // плей пауза E619FC03
    // + E619FC03
    // - EA15FC03
    // назад F20DFC03
    // меню E11EFC03
    // источнік? E01FFC03
    // вклвикл E21DFC03

#include <IRremote.h>
#include "painlessMesh.h"
#include "mash_parameter.h"

painlessMesh  mesh;
IRsend irsend;

void receivedCallback( uint32_t from, String &msg ) {

  String str1 = msg.c_str();
  String str2 = "irpon";
  //String str3 = "irpof";

  if (str1.equals(str2)) {
    Serial.println("Receiving 'irpon' command. Sending IR signal...");
    irsend.sendNEC(0xE21DFC03, 32); // Відправка ІЧ-команди
    Serial.println("IR signal sent.");
  }

  //if (str1.equals(str3)) {
  //  irsend.sendNEC(0xB847FF00, 32);
  //}
}

void setup() {

  Serial.begin(9600);

  mesh.init( MESH_PREFIX, MESH_PASSWORD, MESH_PORT );
  mesh.onReceive(&receivedCallback);

  //IrReceiver.begin(4, ENABLE_LED_FEEDBACK);
  irsend.begin(4); // Ініціалізація передавача
}

void loop() {

  mesh.update();


  //if (IrReceiver.decode()) {
    // Получаем сырые данные и сохраняем в переменную нужна кнопка на пульта
    //uint32_t irda = IrReceiver.decodedIRData.decodedRawData;

    // if (irda == 0xB946FF00 ) {
    //   mesh.sendSingle(2224853816,"garland");
    // } 
    // else if (irda == 0xA15EFF00) {
    //   mesh.sendSingle(624315197,"next_eff");
    // }
    // else if (irda == 0xA55AFF00) {
    //   mesh.sendSingle(624315197,"red_led_bri+");
    // }
    // else if (irda == 0xF708FF00) {
    //   mesh.sendSingle(624315197,"red_led_bri-");
    // }


    // Выводим их в монитор порта (отладка)
    // Serial.println(irda,HEX);

    //IrReceiver.resume();
  //}
}
