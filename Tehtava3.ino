//Määritellään käytettävät digitaalipinnit ja niitä vastaavat segmentit.
int a = 3, b = 4, c = 5, d = 6, e = 7, f = 8, g = 9;
int segmentit[7] = {a, b, c, d, e, f, g};

void setup() {
    for (int i = 0; i < 7; i++) {
        //Asetetaan kaikki aiemmin määrietyt pinnit (7kpl) tulostus-/ulostulotilaan.
        pinMode(segmentit[i], OUTPUT);
    }
}

//Ehdot kullekkin segmentille. Mikäli ehdot täyttyvät => sytytetään segmentti.
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

void sammuta() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentit[i], LOW); //Sammutetaan kaikki 7 segmenttiä.
    }
}

void loop() {
  //Arvotaan satunnainen numero väliltä 0-6 (yht. 7 eri numeroa).
	int satunnainenNumero = random(7);
  //Uusi numero tulostetaan aina kahden sekunnin välein.
    naytaNumero(satunnainenNumero); delay(2000); sammuta();
}
