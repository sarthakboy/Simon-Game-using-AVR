# 🎮 Simon Memory Game — AVR Microcontroller

<p align="center">
  <strong>Watch the sequence. Remember the pattern. Repeat it to win!</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-Embedded%20C%2FC%2B%2B-blue?style=for-the-badge" alt="Embedded C/C++" />
  <img src="https://img.shields.io/badge/MCU-AVR-orange?style=for-the-badge" alt="AVR Microcontroller" />
  <img src="https://img.shields.io/badge/Simulation-Proteus-purple?style=for-the-badge" alt="Proteus Simulation" />
</p>

## 📌 Overview

The **Simon Memory Game** is an embedded systems project developed using AVR register-level programming in C/C++. Inspired by the classic Simon electronic game, it challenges players to memorize and reproduce an increasingly long sequence of LED signals using push buttons.

The microcontroller generates a sequence, displays it through four LEDs, and checks the player's button inputs against the expected pattern. A wrong input resets the game to its starting sequence length.

This project demonstrates practical understanding of **GPIO configuration, digital input detection, bitwise operations, timing delays, and embedded game logic**.

## 🎥 Project Demo

### Simulation Video

Add your simulation recording or GIF here.

<!-- Option 1: Embed a GIF stored in your repository -->
<p align="center">
  <img src="https://github.com/sarthakboy/Simon-Game-using-AVR/blob/main/simon%20game%20gif.gif" alt="Simon Memory Game simulation demonstration" width="850"/>
</p>


## ✨ Features

- 🔴 **Four LED outputs** — Displays the generated sequence using four individual LEDs.
- 🔘 **Four push-button inputs** — Allows the player to reproduce the displayed sequence.
- 🧠 **Progressive memory challenge** — Adds a new step to the sequence after each successful round.
- ✅ **Input validation** — Checks each button press against the expected sequence.
- ❌ **Game-over detection** — Detects an incorrect input and resets the sequence length.
- ⚙️ **Direct register access** — Configures AVR GPIO through `DDRB`, `PORTB`, and `PIND`.
- ⏱️ **Timing control** — Uses AVR delay functions to control LED patterns and game timing.

## 🛠️ Hardware & Software

| Component | Purpose |
|---|---|
| AVR microcontroller | Executes the game logic |
| 4 LEDs | Displays the sequence |
| 4 push buttons | Captures player input |
| Current-limiting resistors | Protects the LEDs |
| Pull-up resistors or internal pull-ups | Provides defined button input levels |
| Proteus | Circuit design and simulation |
| AVR C/C++ toolchain | Compiles the firmware |

**Clock frequency:** 16 MHz, configured using `F_CPU`.

> The exact AVR microcontroller part number and circuit connections should be added to this section to make the project reproducible.

## 🔌 Pin Configuration

The firmware uses the following AVR port assignments:

| Signal | AVR Pin | Register role |
|---|---|---|
| LED 1 | PB0 | Output |
| LED 2 | PB1 | Output |
| LED 3 | PB2 | Output |
| LED 4 | PB3 | Output |
| Button 1 | PD0 | Input |
| Button 2 | PD1 | Input |
| Button 3 | PD2 | Input |
| Button 4 | PD3 | Input |

The firmware configures `PB0–PB3` as outputs and `PD0–PD3` as inputs. It enables the corresponding internal pull-ups through `PORTD`, so button presses are detected as **active-low signals**.

## 🧠 How It Works

1. **Initialization:** Configures the GPIO directions and enables pull-ups for the buttons.
2. **Start indication:** Flashes the LEDs to signal that the game is starting.
3. **Sequence generation:** Creates a sequence of LED identifiers and adds a new step in each round.
4. **LED playback:** Displays the complete sequence so the player can memorize it.
5. **Player input:** Detects button presses using falling-edge checks on the active-low inputs.
6. **Sequence validation:** Compares each input with the corresponding expected sequence entry.
7. **Round progression:** Advances to a longer sequence when the player's inputs are correct.
8. **Game-over handling:** Displays a failure indication and restarts the challenge from a sequence length of one when an incorrect input is detected.

## 💻 Embedded C/C++ Concepts Demonstrated

- AVR GPIO register configuration (`DDR`, `PORT`, and `PIN`)
- Bitwise masking and bit manipulation
- Active-low digital input handling
- Falling-edge detection through previous and current input states
- Arrays and sequence indexing
- Functions for modular program structure
- Pseudo-random number generation using `rand()`
- Timing delays using `<util/delay.h>`
- State-based game logic and input validation

## 🚀 Build & Run

1. Clone or download this repository.
2. Open the project in your AVR-compatible IDE or build environment.
3. Select the exact AVR microcontroller used in your Proteus circuit.
4. Configure the clock to match the firmware's `F_CPU` setting of 16 MHz.
5. Compile the firmware and generate the appropriate HEX file.
6. Load the HEX file into the microcontroller model in Proteus.
7. Start the simulation and use the four push buttons to repeat the LED sequence.

## 🔧 Potential Improvements

- Add proper button debouncing for more reliable input detection.
- Seed the pseudo-random number generator for less predictable sequences.
- Add a score display using a seven-segment display or LCD.
- Introduce a maximum sequence length and safe array-bound checks.
- Improve game-over feedback with a distinct LED pattern.
- Replace blocking delays with timer-based, non-blocking timing.
- Add a restart button and difficulty settings.

## 🎯 Learning Outcome

This project applies fundamental embedded programming concepts to an interactive application. It provides practical experience with AVR register-level GPIO control, digital inputs, bitwise operations, timing, and sequence validation, while creating a foundation for more advanced projects involving timers, interrupts, and peripheral drivers.

---

<p align="center">
  <strong>Built to practice embedded programming, one sequence at a time. ⚡</strong>
</p>
