Mönsterigenkänning
==================

- Ungefärligt antal timmar spenderade på labben (valfritt):


- Vad är tidskomplexiteten (i ordo-notation) för värstafallstiden av
  programmen som en funktion av N (antal punkter). Ge en kort motivering.

  Matchar brute-lösningen sitt värstafall i praktiken, eller har den ett
  medelfall som är bättre?

brute:

tidskomplexiteten för brute är O(N⁴) i värstafall eftersom då måste vi iterera igenom alla fyra punkter och jämföra. Brute-lösningen matchar inte sitt värstafall i och med att k-loopen bara körs när 3 punkter ligger på (nästan) samma linje vilket ger den ett medelfall på O(N³) i tidskomplexitet. 


fast:

tidskomplexiteten för fast är O(N²*log(n)) eftersom vi först beräknar lutningen för alla punkter i förhållande till origo -> O(N). Detta upprepar vi n antal gånger -> O(N) * O(N) = O(N²)
Sorteringen av listan efter lutningen -> O(log(N)) 
Totalt: O(N²) * O(log(N)) = O(N²log(N))

- Fyll i tabellen nedan med riktiga körtider i sekunder när det känns
  vettigt att vänta på hela beräkningen.
  Ge uppskattningar av körtiden (baserat på tidskomplexiteten)
  i övriga fall.
    
      N       brute       sortering
 ----------------------------------
    150        45ms         5ms
    200        99ms         9ms
    300       322ms         21ms
    400       729ms         29ms
    800       5659ms        99ms
   1600      46957ms       379ms
   3200     ~13min         1341ms
   6400     ~50min         5347ms
  12800     ~6.67tim       22796ms 


- Energianvändning

  Antag att du använder mönsterigenkänningsprogrammet för att analysera
  data från en kamera. Kameran sitter i en byggnad och tar en bild
  på stommen av byggnaden var 30:e minut. Bilden förbehandlas sedan
  lite, innan punkter som representerar stommen skickas till
  mönsterigenkänningsprogrammet. Hittas inte tillräckligt många raka
  linjer så betyder det att något håller på att gå sönder, och
  att byggnaden behöver noggrannare inspektion.

  Hur mycket energi sparar du på ett år om du använder din snabbare
  sorteringslösning i stället för brute-lösningen? Du kan anta följande:
  - Systemet körs 24/7 under hela året.
  - Inget annat körs på det här systemet.
  - Systemet drar 8 W när det inte gör något (idle)
  - Systemet drar 36 W när det arbetar (med 1 kärna )
  - Räkna med att ditt program körs var 30:e minut (= 2 gånger/timme)
  - För- och efterbehandling är snabba, så vi kan bortse från dem
  - Indata till programmet innehåller ca 6400 punkter
  - Det är inte skottår (= 365 dagar)

  Att jämföra med drar en kombinerad kyl/frys ca 200 kWh per år
  (enligt Energimyndigheten).
 
  Kom ihåg: energi mäts ofta i kWh, vilket är:
  energi (kWh) = effekt (kW) * tid (h)

  Tips: ett sätt att räkna på är att först räkna förbrukningen av
  ett system som inte gör något på ett helt år, sedan lägga till
  den extra förbrukningen (36 W - 8 W = 28 W) för tiden som systemet
  är aktiv.

  (Siffrorna är löst baserade på en Intel i9-9900K, vi räknar bara på
  CPU:n för enkelhets skull, besparingarna blir sannolikt större om
  vi räknar på större delar av systemet, även om andra komponenter
  också drar ström i "idle".)


Förbrukning av brute på ett år: ? kWh

  För N = 6400 uppskattas körtiden till ca 50 minuter per körning eftersom 
  programmet tog 46 sekunder vid 1600 körningar och tiden ökar enligt N^3. 
  Detta innebär att i praktiken arbetar programmet kontinuerligt hela året.

  Total förbrukning: 
    Effekt = 36 W = 0.036KW 
    Tid = 8670 h (ett år)
    Energi = 0.036 * 8670 = 315.36 KWh/år

Förbrukning av sotering på ett år: ? kWh

idle förbrukning: 0.008kW*8760 = 70.08 kWh
Extra förbrukning: 0.028kW * (5.347/3600h) * 17520 = 0.728kWh
totalt för sortering: 70.08 + o.728 = 70.88 kWh/år

Skillnad: ? kWh

315.36 - 70.88 = 244.48 kWh/år

Skillnaden är ungefär lika stor som energiförbrukningen för en modern kyl & frys.