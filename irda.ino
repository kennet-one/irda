// Node ID: 635036282
//
//
//uint32_t nodeId = mesh.getNodeId();
//Serial.print("Node ID: ");
//Serial.println(nodeId);


#include <IRremote.h>
#include "painlessMesh.h"

#define   MESH_PREFIX     "kennet"
#define   MESH_PASSWORD   "kennet123"
#define   MESH_PORT       5555

painlessMesh  mesh;
IRsend irsend;

void receivedCallback( uint32_t from, String &msg ) {

  String str1 = msg.c_str();
  String str2 = "ir_ledOn";
  String str3 = "ir_ledOf";

  if (str1.equals(str2)) {
    irsend.sendNEC(0xBA45FF00, 32); // 32 - кількість бітів у ІЧ коді
  }

  if (str1.equals(str3)) {
    irsend.sendNEC(0xB847FF00, 32);
  }
}

void setup() {

  Serial.begin(9600);

  mesh.init( MESH_PREFIX, MESH_PASSWORD, MESH_PORT );
  //mesh.onReceive(&receivedCallback);

  IrReceiver.begin(4, ENABLE_LED_FEEDBACK);
}
// до висилання BA45FF00 це вкл, B847FF00 викл

void loop() {

  mesh.update();


  if (IrReceiver.decode()) {
    // Получаем сырые данные и сохраняем в переменную         B946FF00 нужна кнопка на пу
    uint32_t irda = IrReceiver.decodedIRData.decodedRawData;

    if (irda == 0xB946FF00 ) {
      mesh.sendSingle(2224853816,"garland");
    } 
    else if (irda == 0xA15EFF00) {
      mesh.sendSingle(624315197,"next_eff");
    }
    else if (irda == 0xA55AFF00) {
      mesh.sendSingle(624315197,"red_led_bri+");
    }
    else if (irda == 0xF708FF00) {
      mesh.sendSingle(624315197,"red_led_bri-");
    }


    // Выводим их в монитор порта (отладка)
    Serial.println(irda,HEX);
    

    IrReceiver.resume();
  }
}
