// C++ code
//

const int sensorPin = A0;
const int sensorPin_1 = A1;
const int buzzerPin = 9; 

const int NUM_READINGS = 10;
int readings[NUM_READINGS];
int readIndex = 0;
int avg;

int pontData;

unsigned long previousLdrMillis = 0; // Κρατάει την ώρα της τελευταίας μέτρησης
const unsigned long ldrInterval = 10; // Κάθε 10ms (100Hz)

unsigned long previousPontMillis = 0; // Κρατάει την ώρα της τελευταίας μέτρησης
const unsigned long pontInterval = 20; // Κάθε 20ms (50Hz)

void setup()
{
  for (int i = 0; i < NUM_READINGS; i++) 
  {
    readings[i] = 0;
  }
  
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis(); // Κοιτάμε τι ώρα είναι τώρα
  
  // Έλεγχος αν πέρασαν 10ms από την τελευταία φορά
  if (currentMillis - previousLdrMillis >= ldrInterval)
  {
    previousLdrMillis = currentMillis; // Ενημερώνουμε την ώρα για τον επόμενο κύκλο
    photoresistorTask(); // Τρέχουμε το 1ο task
    buzzerTask(); //Τρέχουμε το 3ο task
  }
  
    // Έλεγχος αν πέρασαν 20ms από την τελευταία φορά
  if (currentMillis - previousPontMillis >= pontInterval)
  {
    previousPontMillis = currentMillis; // Ενημερώνουμε την ώρα για τον επόμενο κύκλο
    recordPontReadings(sensorPin_1);    // Τρέχουμε το 2ο task
  }
  
 
}

//Συνάρτηση για την ανάγνωση και την αποθήκευση των μετρήσεων σε πίνακα
void recordReadings(int pin)
{ 
  readings[readIndex] = analogRead(pin);
  readIndex = (readIndex + 1)% NUM_READINGS;
}
//Συνάρτηση υπολογισμού του μέσου όρου των τελευταίων δεκα μετρήσεων
int calculateAverage()
{
  long total = 0;
  for(int i = 0; i < NUM_READINGS; i++)
  {
    total += readings[i];
  }
  
  int average  = total/NUM_READINGS;
  
  return average;
}

//Συνάρτηση που συνθέτη τις συναρτήσεις διαβάσματος, καταγραφείς 
//και υπολογισμού των τιμών του σήματος της φωτοαντίστασης
void photoresistorTask()
{
  recordReadings(sensorPin);
  avg = calculateAverage();
}

//Συνάρτηση ανάγνωσης τιμών ποτενσιόμετρου
void recordPontReadings(int pin)
{
  pontData = analogRead(pin);
}

//Συνάρτηση σύγκρισης τιμών φωτοαντίστασης και ποντενσιόμετρου
//και παραγωγής ανάλογου τετράγωνου παλμού
void buzzerTask()
{
  int dutyCycle = map(avg, 0, 1023, 0, 255); // Μετατρέπει τα όρια [0,1023] της φωτοαντίστασης
  											 // σε [0, 255], τα όρια της analogWrite()
  
  if(avg >= pontData)
  {
    analogWrite(buzzerPin, dutyCycle);
  }
  else
  {
    analogWrite(buzzerPin, 0);
  }
}

