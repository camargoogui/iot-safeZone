# 🌧️ SafeZone – Sistema de Monitoramento de Enchentes com IoT

O **SafeZone** é um sistema inteligente de monitoramento de enchentes, desenvolvido com ESP32 simulado no Wokwi, sensores virtuais e dashboard em Node-RED. O projeto visa alertar a população de forma simples e visual sobre o risco de alagamento em tempo real, utilizando tecnologias de IoT.

---

## ❓ Problema

Em áreas urbanas, enchentes são recorrentes e causam prejuízos materiais e até riscos à vida. A falta de monitoramento em tempo real dificulta a prevenção e resposta rápida por parte da população e da Defesa Civil.

---

## 💡 Solução

Criamos um sistema IoT capaz de monitorar o **nível da água** continuamente, utilizando um potenciômetro como sensor simulado. O sistema envia os dados via **protocolo MQTT** para um **dashboard em Node-RED**, que exibe os dados de forma clara e envia alertas visuais e sonoros.

---

## 🛠️ Tecnologias Utilizadas

- ⚙️ **ESP32 (Wokwi)** – simulação do hardware IoT
- 📶 **MQTT (broker.hivemq.com)** – comunicação entre ESP32 e dashboard
- 📊 **Node-RED** – dashboard visual e processamento dos dados
- 🧪 **Potenciômetro + LEDs + Buzzer (simulados)** – sensores e atuadores
- 🔌 **JSON** – formato dos dados transmitidos

---

## 📐 Esquema do Circuito (Wokwi)

<p align="center">
  <img src="img/circuito-wokwi.png" width="500" alt="Circuito montado no Wokwi">
</p>

📸 *Imagem capturada com o potenciômetro simulando um nível de água de aproximadamente **79%**, acionando o LED vermelho.*

**Componentes conectados:**
- Potenciômetro (nível de água simulado)
- LED Verde (nível normal)
- LED Vermelho (nível de alerta)
- Buzzer (nível crítico > 80%)
- ESP32 DevKit-C

🔗 Projeto no Wokwi: [Clique para abrir](https://wokwi.com/projects/432059421462344705)

---

## 🖥️ Dashboard Node-RED

O painel exibe os dados em tempo real, facilitando a visualização e tomada de decisão:

- 🟢 **Gauge** com o nível da água (0 a 100%)
- 📈 **Gráfico histórico** dos níveis
- 🔴 **Status atual** com destaque colorido (Normal, Alerta ou Crítico)
- ⏱️ **Última atualização** (timestamp em tempo real)

> O envio dos dados ocorre a cada 5 segundos via MQTT.

---

## ▶️ Como Executar o Projeto

### 1. Simulação no Wokwi
- Acesse: [https://wokwi.com/projects/432059421462344705](https://wokwi.com/projects/432059421462344705)
- Clique em “Start Simulation”
- Gire o potenciômetro para simular diferentes níveis de água

### 2. Dashboard no Node-RED
- Instale e execute o Node-RED localmente: `http://localhost:1880`
- Importe o arquivo `dashboard_safezone.json`
- Acesse o painel visual: [http://localhost:1880/ui](http://localhost:1880/ui)

---

## 📁 Organização do Projeto

```plaintext
iot-safeZone/
├── sketch.ino               # Código principal do ESP32
├── diagram.json             # Esquema do circuito no Wokwi
├── dashboard_safezone.json  # Flow Node-RED com dashboard
├── img/
│   └── circuito-wokwi.png   # Imagem do circuito simulado
└── README.md                # Documentação do projeto
```

---

## 👥 Integrantes

- RM556270 - **Bianca Vitoria** - 2TDSPZ  
- RM555166 - **Guilherme Camargo** - 2TDSPM  
- RM555131 - **Icaro Americo** - 2TDSPM

---

## ✅ Requisitos Atendidos

- ✅ Simulação 100% funcional no Wokwi
- ✅ Mínimo de 3 dispositivos IoT (potenciômetro, buzzer, LEDs)
- ✅ Dashboard com atualização em tempo real
- ✅ Comunicação via **MQTT** com JSON
- ✅ Gateway e visualização via Node-RED

---

> Projeto desenvolvido para a disciplina *Disruptive Architectures: IoT, IOB & Generative IA* – FIAP, 2025.

