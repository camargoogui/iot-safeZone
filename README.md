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

![Wokwi](https://wokwi.com/assets/logo/logo-only-light.png)

🔗 Projeto no Wokwi: [Clique aqui para abrir](https://wokwi.com/projects/432059421462344705)

Componentes:
- Potenciômetro (nível de água simulado)
- LED Verde (nível normal)
- LED Vermelho (nível de alerta)
- Buzzer (nível crítico > 80%)

---

## 🖥️ Dashboard Node-RED

O painel exibe:

- 🟢 **Gauge** com o nível da água (0 a 100%)
- 📈 **Gráfico histórico** em tempo real
- 🔴 **Status do nível** (Normal, Alerta ou Crítico)
- ⏱️ **Última atualização** em tempo real

> O envio de dados é feito a cada 5 segundos. O buzzer e LED mudam conforme o nível.

---

## ▶️ Como Executar o Projeto

### 1. Simulação no Wokwi
- Acesse o link: [https://wokwi.com/projects/432059421462344705](https://wokwi.com/projects/432059421462344705)
- Clique em "Start Simulation"
- Gire o potenciômetro para simular o nível da água

### 2. Node-RED
- Instale e execute Node-RED localmente (`http://localhost:1880`)
- Importe o arquivo `dashboard_safezone.json`
- Acesse o painel em: [http://localhost:1880/ui](http://localhost:1880/ui)

---

## 📁 Organização do Projeto

```plaintext
iot-safeZone/
├── sketch.ino              # Código principal do ESP32
├── diagram.json            # Esquema do circuito (Wokwi)
├── dashboard_safezone.json # Flow Node-RED com dashboard
└── README.md               # Documentação do projeto
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

