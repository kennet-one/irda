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

void setup() {

  Serial.begin(9600);

  mesh.init( MESH_PREFIX, MESH_PASSWORD, MESH_PORT );
  //mesh.onReceive(&receivedCallback);

  IrReceiver.begin(4, ENABLE_LED_FEEDBACK);
}


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
    // else if (irda == A15EFF00) {
    // mesh.sendSingle(624315197,"next_eff");
    // }
    // else if (irda == A15EFF00) {
    // mesh.sendSingle(624315197,"next_eff");
    // }


    // Выводим их в монитор порта (отладка)
    Serial.println(irda,HEX);
    

    IrReceiver.resume();
  }
}
