// Määritellään jokaiselle segmentille oma digitaalipinni.
int a = 3, b = 4, c = 5, d = 6, e = 7, f = 8, g = 9;

// Määritellään 7kpl segmenttejä.
int segmentit[7] = {a, b, c, d, e, f, g};

// Arduinon oma setup -funktio, jossa määritellään digitaalipinnien tilat.
void setup() {
    for (int i = 0; i < 7; i++) {
      // Asetetaan kaikki aiemmin määrietyt pinnit tulostus-/ulostulotilaan.
      pinMode(segmentit[i], OUTPUT);
    }
}

// Määritellään käytettävät segmentit tulostettaville hex-digiteille.
// 0 = segmenttiä ei käytetä, digitin tulostamiseen.
int hexDigitit[16][7] = {	// 16 digittiä, käytetään max. 7 segmenttiä.
    {a, b, c, d, e, f, 0}, 	// Hex-digitti 0, Järjestysluku = 0
    {0, b, c, 0, 0, 0, 0}, 	// Hex-digitti 1, Järjestysluku = 1
    {a, b, 0, d, e, 0, g}, 	// Hex-digitti 2, Järjestysluku = 2
    {a, b, c, d, 0, 0, g}, 	// Hex-digitti 3, Järjestysluku = 3
    {0, b, c, 0, 0, f, g}, 	// Hex-digitti 4, Järjestysluku = 4
    {a, 0, c, d, 0, f, g}, 	// Hex-digitti 5, Järjestysluku = 5
    {a, 0, c, d, e, f, g}, 	// Hex-digitti 6, Järjestysluku = 6
    {a, b, c, 0, 0, 0, 0}, 	// Hex-digitti 7, Järjestysluku = 7
    {a, b, c, d, e, f, g}, 	// Hex-digitti 8, Järjestysluku = 8
    {a, b, c, d, 0, f, g},	// Hex-digitti 9, Järjestysluku = 9
    {a, b, c, 0, e, f, g}, 	// Hex-digitti A, Järjestysluku = 10
    {0, 0, c, d, e, f, g}, 	// Hex-digitti b, Järjestysluku = 11
    {a, 0, 0, d, e, f, 0}, 	// Hex-digitti C, Järjestysluku = 12
    {0, b, c, d, e, 0, g}, 	// Hex-digitti d, Järjestysluku = 13
    {a, 0, 0, d, e, f, g}, 	// Hex-digitti E, Järjestysluku = 14
    {a, 0, 0, 0, e, f, g}  	// Hex-digitti F, Järjestysluku = 15
};

// Funktio, joka tulostaa hex-digitit 0-9 ja A-F
void naytaDigitti(int digitinJarjestysluku) {
  // For -ilmukka toistaa koodin 16 kertaa (hexDigitit -taulukon rivimäärä).
    for (int i1 = 0; i1 < 16; i1++) {
      // Jos digitin järjestysluku on sama kuin for -silmukan inkrementin arvo, niin suoritetaan uusi for -silmukka
        if (digitinJarjestysluku == i1) {
          // For -ilmukka toistaa koodin 7 kertaa (segmenttien määrä).
            for (int i2 = 0; i2 < 7; i2++) {
              // Sytytetään digitin tulostamiseen tarvittavat segmentit
              // i1 = digitin järjestysluku (hexDigitit -taulukon rivi)
              // i2 = rivillä määritellyt segmentit a,b,c,d,e,f,g
                digitalWrite(hexDigitit[i1][i2], HIGH);
            }
        }
    }
}

// Funktio, joka sammuttaa kaikki 7 segmenttiä.
void sammuta() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentit[i], LOW);
    }
}

// Arduinon oma loop -funktio, jossa suoritetaan ohjelmakoodi.
void loop() {
    for (int i = 0; i < 16; i++) {
        naytaDigitti(i);
        delay(1000);
        sammuta();
    }
}
