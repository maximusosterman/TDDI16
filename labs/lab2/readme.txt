Bildmatchning
=============

- Ungefärligt antal timmar spenderade på labben (valfritt):


- Vad är tidskomplexiteten på "slow.cpp" och din implementation av "fast.cpp",
  uttryckt i antalet bilder (n).

slow: O(n²)
fast: O(n)


- Hur lång tid tar det att köra "slow.cpp" respektive "fast.cpp" på de olika
  datamängderna?
  Tips: Använd flaggan "--nowindow" för enklare tidsmätning.
  Tips: Det är okej att uppskatta tidsåtgången för de fall du inte orkar vänta
  på att de blir klara.
  Tips: Vid uppskattning av körtid för "slow.cpp" är det en bra idé att beräkna
  tiden det tar att läsa in (och skala ner) bilderna separat från tiden det tar att
  jämföra bilderna. (Varför?)

|--------+-----------+----------+----------|
|        | inläsning | slow.cpp | fast.cpp |
|--------+-----------+----------+----------|
| tiny   |   125ms   |  211ms   |   176ms  |
| small  |   76ms    |  810ms   |   819ms  |
| medium |   2231ms  |  3052ms  |   2662ms |
| large  |   26ms    |  530s    |   60s    |
|--------+-----------+----------+----------|


- Testa olika värden på "summary_size" (exempelvis mellan 6 och 10). Hur
  påverkar detta vilka dubbletter som hittas i datamängden "large"?

  6 i summer_size gav 9 matches, medan 10 i summer_size gav 5


- Algoritmen som implementeras i "compute_summary" kan ses som att vi beräknar
  en hash av en bild. Det är dock inte helt lätt att hitta en bra sådan funktion
  som helt motsvarar vad vi egentligen är ute efter. Vilken eller vilka
  egenskaper behöver "compute_summary" ha för att vi ska kunna använda den för
  att hitta bilder som liknar varandra? (Dvs. vilka egenskaper förväntar sig
  kod som *använder* "compute_summary"?) Tycker du att den givna funktionen
  uppfyller dessa egenskaper?

  compute_summary behöver vara stabil, effektiv och ge liknande resultat för liknande bilder samt olika resultat för olika bilder. Funktionen uppfyller det viktigaste kravet med pixeljämförning

- Ser du några problem med metoden för att se om två bilder är lika dana?
  Fundera exempelvis på vilka typer av olikheter som tolereras, och vilka
  typer av olikheter som anses vara för stora. Matchar detta din uppfattning
  om vad som borde vara lika?

  Metoden fungerar bra och är enkel men har begränsningar. Den tolererar små skillnader i ljusstyrka och upplösning. Däremot om bilen är roterad eller beskuren så kanske vår lösning inte är optimal.

  Föreslå en alternativ metod för att åtgärda några av problemen du såg (dvs.
  hur skulle man kunna se till att några av de "för stora" olikheterna betraktas
  som "lika"?) Vad har ditt/dina förslag för för- och nackdelar jämfört med hur
  "compute_summary" fungerar? Fokusera på vilka typer av skillnader som hanteras,
  och ange också ifall det påverkar tidskomplexiteten gentemot "fast". Ditt förslag
  behöver inte vara snabbare än det som föreslås i labben, men du ska komma på
  åtminstone en fördel med din metod.

  En algoritum som också jämför varje bilds hörn och kanter och mittpunkt.
  Detta skulle kräva ett par extra for-loopar, vilket bara ändra konstanten framför n i tidskomplexiteten. Detta resulterar i att trotts denna ändring så är tidskomplexiteten densamma..

  En nackdel är att det blir mer komplex implementation i compute_summary.
