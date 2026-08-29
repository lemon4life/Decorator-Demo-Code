# Decorator Pattern Demo

A short C++ console demo of the **Decorator** pattern based on the RPG character equipment and buff system in `Decorator.md`.

The decorators dynamically attach new equipment (weapons, armor, accessories) and stat modifiers to a `BaseHero` at runtime by wrapping it in decorator objects sharing the same `Character` interface.

## Project Structure

```text
Decorator-Demo-Code/
|-- main.cpp
|-- Character.h
|-- README.md
|-- AI chat log.md
`-- Character/
    |-- BaseHero.cpp
    |-- CharacterDecorator.cpp
    `-- EquipmentDecorators.cpp
```

## Pattern Roles

- `Character`: Component interface
- `BaseHero`: ConcreteComponent
- `CharacterDecorator`: Abstract Decorator
- `SwordDecorator`, `ShieldDecorator`, `MagicRingDecorator`: ConcreteDecorators
- `main.cpp`: Client demo

## Build and Run

Open a terminal in the `Decorator-Demo-Code` folder and run:

```bash
g++ main.cpp -std=c++17 -Wall -Wextra -pedantic -o main.exe
```

Then run:

- On Windows:
  ```powershell
  .\main.exe
  ```
- On macOS / Linux:
  ```bash
  ./main.exe
  ```

The output shows baseline stats, runtime wrapping with single items, layered combinations, and arbitrary stacking (e.g., dual-wielding swords).
