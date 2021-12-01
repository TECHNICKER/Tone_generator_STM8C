# STM8 Tools

Šablona projektu pro STM8.

## Klonování

Nejprve si repozitář naklonujte:

```
git clone https://gitlab.com/wykys/stm8-tools.git
```

## Přejmenování

```bash
mv stm8-tools blikac
```

## Základní úkony

Přejmede do slořky s projektem:

```bash
cd blikac
```

Otevřeme si projekt v editoru:

```bash
code .
```

## Kompilace projektu

```bash
make
```

## Nahrání FW do MCU

```bash
make flash
```

## Kombinace předchozích dvou kroků

```bash
make build_and_flash
```
