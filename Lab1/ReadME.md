# Lab1 – Upravljanje višestrukim prekidima (ESP32)

## Opis

Ovaj projekt demonstrira rad s višestrukim prekidima na ESP32 mikrokontroleru koristeći Wokwi simulator.

Implementirani su:

* prekidi tipkala
* timer prekid
* očitavanje senzora (HC-SR04)
* prioriteti prekida

---

## Prioriteti prekida

1. Timer – najviši prioritet
2. Tipka na pinu 18 – visoki
3. Tipka na pinu 19 – srednji
4. Tipka na pinu 21 – niski

---

## Komponente

* ESP32
* 3 tipkala
* LED diode
* HC-SR04 senzor

---

## Funkcionalnost

* Tipke aktiviraju LED diode
* Timer se aktivira svake sekunde
* Senzor pali alarm LED ako je udaljenost < 100 cm
* Sustav koristi zastavice (flags) za upravljanje prekidima

---

## Testiranje

* Svaka tipka aktivira odgovarajuću LED
* Timer prekid ima najveći prioritet
* Senzor reagira na udaljenost
* Sustav ispravno obrađuje više prekida bez konflikta

---

## Zaključak

Projekt uspješno demonstrira upravljanje višestrukim prekidima i njihovim prioritetima.
