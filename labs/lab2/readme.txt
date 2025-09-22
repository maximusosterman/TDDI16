Bildmatchning
=============

- Ungefärligt antal timmar spenderade på labben (valfritt):


- Vad är tidskomplexiteten på "slow.cpp" och din implementation av "fast.cpp",
  uttryckt i antalet bilder (n).

slow:
fast:


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
| tiny   |           |          |          |
| small  |           |          |          |
| medium |           |          |          |
| large  |           |          |          |
|--------+-----------+----------+----------|


- Testa olika värden på "summary_size" (exempelvis mellan 6 och 10). Hur
  påverkar detta vilka dubbletter som hittas i datamängden "large"?


- Algoritmen som implementeras i "compute_summary" kan ses som att vi beräknar
  en hash av en bild. Det är dock inte helt lätt att hitta en bra sådan funktion
  som helt motsvarar vad vi egentligen är ute efter. Vilken eller vilka
  egenskaper behöver "compute_summary" ha för att vi ska kunna använda den för
  att hitta bilder som liknar varandra? (Dvs. vilka egenskaper förväntar sig
  kod som *använder* "compute_summary"?) Tycker du att den givna funktionen
  uppfyller dessa egenskaper?


- Ser du några problem med metoden för att se om två bilder är lika dana?
  Fundera exempelvis på vilka typer av olikheter som tolereras, och vilka
  typer av olikheter som anses vara för stora. Matchar detta din uppfattning
  om vad som borde vara lika?

  Föreslå en alternativ metod för att åtgärda några av problemen du såg (dvs.
  hur skulle man kunna se till att några av de "för stora" olikheterna betraktas
  som "lika"?) Vad har ditt/dina förslag för för- och nackdelar jämfört med hur
  "compute_summary" fungerar? Fokusera på vilka typer av skillnader som hanteras,
  och ange också ifall det påverkar tidskomplexiteten gentemot "fast". Ditt förslag
  behöver inte vara snabbare än det som föreslås i labben, men du ska komma på
  åtminstone en fördel med din metod.



