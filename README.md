# Automobilių duomenų valdymo sistema (projektinis darbas, nenaudoti realybėje!)

## Projekto tikslas
Šio projektinio darbo tikslas - sukurti veikiančią C++ konsolinę programą, pritaikant struktūrinio programavimo principus, išmoktus studijų kurso metu. 

## Temos aprašymas
Programa imituoja automobilių parko informacinę sistemą. Kiekvienas automobilis turi šiuos duomenis: Unikalų įdentifikatorių (ID), markę, modelį, gamybos metus, kainą bei kuro tipą.

## Programos funkcionalumas (CRUD)
* **Create:** Naujo automobilio pridėjimas su automatiniu unikalaus ID generatoriumi.
* **Read:** Viso sąrašo peržiūra lentelėje arba vieno automobilio paieška pagal jam pritaikytą ID.
* **Update:** Esamo automobilio duomenų keitimas (skliausteliuose rodo senas reikšmes, kurios bus pakeistos)
* **Delete:** Automobilio trynimas iš sąrašo naudojant iteratorius.
* **Apsauga:** Įdiegta įvesties validacija (`cin.fail()`), kuri neleidžia programai vykdyti begalinius ciklus, kai įvesta raidė ar kitas simbolis vietoje skliaustelio.

## Papildomos funkcijos
1. **Filtravimas:** Automobilių atranka ir išvedimas ekrane pagal pasirinktą markę.
2. **Statistika:** Ataskaitos generavimas (skaičiuojama vidutinė kaina, naujausi metai, brangiausias automobilis sąraše).

## Kita informacija
* **automobiliai.txt** - duombazės failas, naudojamas duomenų nuskaitymui startuojant programą, ir įrašomi baigiant ir išsaugant darbą).
* **ataskaita.txt** - tekstinis failiukas, kuriame išsaugoma sugeneruota programos statistika.

Ačiū už skaitymą! c:

