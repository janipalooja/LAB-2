//Määritellään jokaiselle segmentille oma digitaalipinni.
int a = 3,
    b = 4,
    c = 5,
    d = 6,
    e = 7,
    f = 8,
    g = 9;

//Määritellään 7kpl segmenttejä.
int segmentit[7] = {
    a,
    b,
    c,
    d,
    e,
    f,
    g
};

//Arduinon oma setup -funktio, jossa määritellään digitaalipinnien tilat.
void setup() {
    for (int i = 0; i < 7; i++) {
         
        pinMode(segmentit[i], OUTPUT);
    }
}

/*
Numerokohtaiset ehdot kullekkin segmentille.
Mikäli ehdot täyttyvät => sytytetään segmentti.
*/
void naytaNumero(int numero) {
    //Ehdot segmentille a.
    if (numero != 1 && numero != 4) {
        digitalWrite(a, HIGH);
    }
    //Ehdot segmentille b.
    if (numero != 5 && numero != 6) {
        digitalWrite(b, HIGH);
    }
    //Ehdot segmentille c.
    if (numero != 2) {
        digitalWrite(c, HIGH);
    }
    //Ehdot segmentille d.
    if (numero != 1 && numero != 4 && numero != 7) {
        digitalWrite(d, HIGH);
    }
    //Ehdot segmentille e.
    if (numero == 2 || numero == 6 || numero == 8 || numero == 0) {
        digitalWrite(e, HIGH);
    }
    //Ehdot segmentille f.
    if (numero != 1 && numero != 2 && numero != 3 && numero != 7) {
        digitalWrite(f, HIGH);
    }
    //Ehdot segmentille g.
    if (numero != 0 && numero != 1 && numero != 7) {
        digitalWrite(g, HIGH);
    }

}

//Sammutetaan kaikki 7 segmenttiä.
void sammuta() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentit[i], LOW);
    }
}

//Arduinon oma loop -funktio, jossa suoritetaan ohjelmakoodi.
void loop() {
    for (int i = 0; i < 10; i++) {

        /*
        Jokainen numero (0-9) palaa vuorollaan 1s ajan ja sammuu,
        jonka jälkeen tulostuu seuraava numero.
        Kun kaikki 10 numeroa (0-9) on tulostettu,
        niin ohjelma aloittaa numeroiden tulostamisen alusta 0,1,2,3...
        */

        naytaNumero(i);
        delay(1000);
        sammuta();

    }
}
