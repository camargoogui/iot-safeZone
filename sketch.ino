#include <WiFi.h>
#include <PubSubClient.h>

#define LED_VERDE 4
#define LED_VERMELHO 2
#define BUZZER 5
#define POTENCIOMETRO 34

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttTopic = "safezone/leituras";

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
int nivelAnterior = -1;

void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando-se ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" conectado!");
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(BUZZER, LOW);

  setup_wifi();
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    while (!client.connected()) {
      Serial.println("Conectando ao broker MQTT...");
      if (client.connect("SafeZoneESP32")) {
        Serial.println("Conectado ao MQTT!");
      } else {
        delay(1000);
      }
    }
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

    int leitura = analogRead(POTENCIOMETRO);
    int nivel = map(leitura, 0, 4095, 0, 100);

    if (nivel != nivelAnterior) {
      Serial.print("Nível da água: ");
      Serial.print(nivel);
      Serial.println("%");

      if (nivel <= 60) {
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(BUZZER, LOW);
      } else if (nivel <= 80) {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_VERMELHO, HIGH);
        digitalWrite(BUZZER, LOW);
      } else {
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_VERMELHO, HIGH);
        digitalWrite(BUZZER, HIGH);
      }

      // Publica no MQTT
      char payload[128];
      snprintf(payload, sizeof(payload),
               "{\"local_id\":\"zona_leste_01\",\"nivel\":%d}", nivel);
      client.publish(mqttTopic, payload);

      nivelAnterior = nivel;
    }
  }
}
