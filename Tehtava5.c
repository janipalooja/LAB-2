// Määritellään jokaiselle segmentille oma digitaalipinni.
int a = 3, b = 4, c = 5, d = 6, e = 7, f = 8, g = 9;

// Määritellään 7kpl segmenttejä.
int segmentit[7] = {a, b, c, d, e, f, g};

// Määritellään käytettävät segmentit tulostettaville oktaalilukujen digiteille.
// 0 = segmenttiä ei käytetä digitin tulostamiseen.
int oktaaliDigitit[8][7] = {	// 8 digittiä, käytetään max. 7 segmenttiä.
    {a, b, c, d, e, f, 0}, 	// Oktaali-digitti 0, Järjestysluku = 0
    {0, b, c, 0, 0, 0, 0}, 	// Oktaali-digitti 1, Järjestysluku = 1
    {a, b, 0, d, e, 0, g}, 	// Oktaali-digitti 2, Järjestysluku = 2
    {a, b, c, d, 0, 0, g}, 	// Oktaali-digitti 3, Järjestysluku = 3
    {0, b, c, 0, 0, f, g}, 	// Oktaali-digitti 4, Järjestysluku = 4
    {a, 0, c, d, 0, f, g}, 	// Oktaali-digitti 5, Järjestysluku = 5
    {a, 0, c, d, e, f, g}, 	// Oktaali-digitti 6, Järjestysluku = 6
    {a, b, c, 0, 0, 0, 0} 	// Oktaali-digitti 7, Järjestysluku = 7
};

// Funktio, joka tulostaa Oktaali-digitit 0-7
void naytaDigitti(int digitinJarjestysluku) {
  // For -ilmukka toistaa koodin 8 kertaa (oktaaliDigitit -taulukon rivimäärä).
    for (int i1 = 0; i1 < 8; i1++) {
      // Jos digitin järjestysluku on sama kuin for -silmukan inkrementin arvo, niin suoritetaan uusi for -silmukka
        if (digitinJarjestysluku == i1) {
          // For -ilmukka toistaa koodin 7 kertaa (segmenttien määrä).
            for (int i2 = 0; i2 < 7; i2++) {
              // Sytytetään digitin tulostamiseen tarvittavat segmentit
              // i1 = digitin järjestysluku (oktaaliDigitit -taulukon rivi)
              // i2 = rivillä määritellyt segmentit a,b,c,d,e,f,g
                digitalWrite(oktaaliDigitit[i1][i2], HIGH);
            }
        }
    }
}

// Arduinon oma setup -funktio, jossa määritellään digitaalipinnien tilat.
void setup() {
    for (int i = 0; i < 7; i++) {
      // Asetetaan kaikki aiemmin määrietyt pinnit tulostus-/ulostulotilaan.
      pinMode(segmentit[i], OUTPUT);
    }
}

// Funktio, joka sammuttaa kaikki 7 segmenttiä.
void sammuta() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentit[i], LOW);
    }
}

// Efekti, jossa näytön uloimmat segmentit (6kpl) rullaavat 2s ajan.
// Jokainen segmentti palaaa vuorollaan 333ms ajan.
void efekti(){
  for (int i = 0; i < 6; i++) {
	digitalWrite(segmentit[i], HIGH);
    delay(333); // 2000ms/6=333ms
	sammuta();
     }
}

// Arduinon oma loop -funktio, jossa suoritetaan ohjelmakoodi.
void loop() {
  // Suoritetaan ensin vaadittu visuaalinen efekti.
  efekti();
  // Efektin päätyttyä tulostetaan näytölle sanunnainen oktaali digitti (0-7) 2s ajaksi.
  naytaDigitti(random(8));
  delay(2000);
  sammuta();  
}
