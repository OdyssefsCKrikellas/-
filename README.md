<img width="1738" height="806" alt="Project 2 __ Κρικέλλας Οδυσσέας" src="https://github.com/user-attachments/assets/2dd4a49b-d4ed-4944-88bc-4e03d98a5e52" /># 🔊 Arduino Light-Controlled Buzzer (PWM)

![Platform](https://img.shields.io/badge/Platform-Arduino%20UNO-00979D?style=flat&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![Simulation](https://img.shields.io/badge/Simulation-Tinkercad-FF6F00?style=flat)

[🇬🇧 English](#english) | [🇬🇷 Ελληνικά](#ελληνικά)

---

## English

An **Arduino UNO** project (simulated in Tinkercad) that reads and processes analog sensor signals to control a piezo buzzer with a variable PWM Duty Cycle.

### ⚙️ How it Works
* **Photoresistor (LDR):** Samples light intensity at **100Hz** (`10ms`) and applies a 10-sample moving average filter using a circular buffer.
* **Potentiometer:** Sampled at **50Hz** (`20ms`) without filtering to dynamically set the activation threshold.
* **Piezo Buzzer:** When the filtered LDR value exceeds the potentiometer threshold, it outputs a PWM square wave with a Duty Cycle that scales proportionally to the light level using `map()`.
* **Non-blocking Timing:** Uses `millis()` instead of `delay()` so both the `10ms` and `20ms` tasks run independently without blocking execution.

### 🔌 Pinout & Connections

| Component | Arduino Pin | Notes |
| :--- | :---: | :--- |
| **Photoresistor (LDR)** | `A0` | Voltage divider with a `10kΩ` resistor |
| **Potentiometer (250kΩ)** | `A1` | Middle pin (wiper) for threshold control |
| **Piezo Buzzer** | `D9` | PWM output (`~`) for variable Duty Cycle |

### 🛠️ Components
* Arduino UNO R3
* Photoresistor (LDR) & `10kΩ` Resistor
* Potentiometer (`250kΩ`)
* Piezo Buzzer
* Breadboard & Jumper Wires


---

## Ελληνικά

Project σε **Arduino UNO** (δοκιμασμένο στο Tinkercad) για την ανάγνωση και επεξεργασία αναλογικών σημάτων και τον έλεγχο ενός piezo buzzer με μεταβαλλόμενο Duty Cycle.

### ⚙️ Τι κάνει
* **Φωτοαντίσταση (LDR):** Διαβάζει την ένταση του φωτός στα **100Hz** (`10ms`) και υπολογίζει τον κινητό μέσο όρο των τελευταίων 10 δειγμάτων με κυκλικό πίνακα (circular buffer).
* **Ποτενσιόμετρο:** Διαβάζεται στα **50Hz** (`20ms`) χωρίς φιλτράρισμα και ορίζει δυναμικά το κατώφλι (threshold) ενεργοποίησης.
* **Piezo Buzzer:** Όταν η φιλτραρισμένη τιμή της φωτοαντίστασης ξεπεράσει το όριο του ποτενσιόμετρου, παράγει τετραγωνικό παλμό (PWM) με το Duty Cycle να αλλάζει αναλογικά με το φως μέσω της `map()`.
* **Χρονισμός:** Χρησιμοποιείται η `millis()` αντί για `delay()`, ώστε τα tasks των `10ms` και `20ms` να τρέχουν ανεξάρτητα χωρίς να μπλοκάρει ο κώδικας.

### 🔌 Συνδεσμολογία (Pinout)

| Εξάρτημα | Pin Arduino | Σημειώσεις |
| :--- | :---: | :--- |
| **Φωτοαντίσταση (LDR)** | `A0` | Διαιρέτης τάσης με αντίσταση `10kΩ` |
| **Ποτενσιόμετρο (250kΩ)** | `A1` | Μεσαίος ακροδέκτης (δρομέας) για το κατώφλι |
| **Piezo Buzzer** | `D9` | Έξοδος PWM (`~`) για μεταβολή του Duty Cycle |

### 🛠️ Υλικά
* Arduino UNO R3
* Φωτοαντίσταση (LDR) & Αντίσταση `10kΩ`
* Ποτενσιόμετρο (`250kΩ`)
* Piezo Buzzer
* Breadboard & Καλώδια σύνδεσης (Jumpers)
