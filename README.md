# ⚡ Battery Management System (BMS) Circuit Simulation

A fully interactive, browser-based **Battery Management System circuit simulation** built with pure HTML, CSS, and JavaScript. No frameworks, no build tools — just open `index.html` in any modern browser.

---

## 🖥️ Live Demo

Open `index.html` directly in your browser — works fully offline.

---

## 📐 Features

### Real-Time Monitoring
| Parameter | Description |
|---|---|
| **State of Charge (SoC)** | Live % with color-coded status and cell bar visualization |
| **State of Health (SoH)** | Degradation model based on charge cycle count |
| **Pack Voltage** | 4S Li-Ion configuration (10.8V–16.8V range) |
| **Temperature** | Thermistor-based with analog gauge display |
| **Current** | Charge/discharge current with direction indicator |
| **Power** | Instantaneous wattage |

### Circuit Schematic
- Animated **live circuit diagram** with real current-flow visualization
- 4-cell battery bank with individual cell voltage display
- Charge/discharge **MOSFET switch** status (Q1/Q2)
- BMS Controller IC block with gate driver lines
- Current sense **shunt resistor**
- Thermistor temperature sensing path

### Protection Functions
| Protection | Trigger |
|---|---|
| **Auto-disconnect at full charge** | Supply cuts at SoC = 100% to prevent overcharge |
| **Over-temperature protection** | Emergency disconnect at ≥ 55°C |
| **Warning alert** | Thermal warning at ≥ 45°C |
| **Auto-reconnect** | Supply restores when temperature normalizes (< 42°C) |
| **Low battery alert** | Visual + log warning at ≤ 10% SoC |
| **SoH degradation alert** | Log warning when health drops below 70% |

### UI Elements
- **Analog semicircle gauges** — SoC, Temperature, Voltage, SoH
- **Live trend charts** — 3 scrolling history charts (Chart.js)
- **6-function protection status panel** with color indicators
- **Scrollable event log** with timestamped entries
- **System status badge** — Normal / Warning / Critical

---

## 🎮 Simulation Controls

| Slider | Effect |
|---|---|
| **Charge Rate** | Simulates external charger current (0–100%) |
| **Load (Discharge)** | Simulates connected load (0–80%) |
| **Ambient Temp Offset** | Shift environment temperature (–15 to +45°C) |
| **Cycle Count** | Simulate battery aging (0–2000 cycles → degrades SoH) |

**Try these scenarios:**
- Ramp charge rate to max → watch SoC hit 100% and supply auto-disconnect
- Set both charge + load to max → temperature spikes, triggers emergency cutoff
- Set cycle count to 2000 → SoH drops to ~30%, degradation warnings appear
- Manually disconnect then reconnect supply via the control button

---

## 🔋 Battery Model

- **Chemistry:** Lithium-Ion (Li-Ion)
- **Configuration:** 4S (4 cells in series)
- **Cell voltage range:** 2.7V (empty) → 4.2V (full)
- **Pack voltage range:** 10.8V → 16.8V
- **Rated cycle life:** 2000 charge cycles
- **SoH degradation model:** Linear from 100% (0 cycles) → 30% (2000 cycles)

---

## 🚀 Getting Started

```bash
# Clone the repo
git clone https://github.com/YOUR_USERNAME/bms-simulation.git

# Open in browser
cd bms-simulation
open index.html        # macOS
start index.html       # Windows
xdg-open index.html    # Linux
```

No dependencies to install. No build step required.

---

## 🗂️ Project Structure

```
bms-simulation/
├── index.html      # Complete simulation (single file)
└── README.md       # This file
```

---

## 🛠️ Tech Stack

| Technology | Usage |
|---|---|
| **HTML5 Canvas** | Circuit schematic rendering with animation |
| **Chart.js 4.4** | Live trend charts (CDN) |
| **Vanilla JS** | Simulation engine, state management |
| **CSS3** | Dark theme, gauges, animations |
| **Google Fonts** | Share Tech Mono + Exo 2 |

---

## 📊 Simulation Architecture

```
Input Controls
    │
    ▼
Simulation Engine (tick @ 800ms)
    ├── SoC Model     (charge/discharge delta)
    ├── Thermal Model (heat from charge + load + ambient)
    ├── SoH Model     (cycle-based degradation)
    └── Electrical    (voltage, current, power)
         │
         ▼
Protection Logic
    ├── Over-voltage check
    ├── Under-voltage check
    ├── Over-temperature → AUTO DISCONNECT
    ├── Full charge → AUTO DISCONNECT
    └── Auto-reconnect when safe
         │
         ▼
Rendering Layer
    ├── Canvas circuit schematic
    ├── KPI cards + gauges
    ├── Chart.js trend graphs
    └── Event log
```

---

## 📸 Screenshots

The simulation features a dark industrial UI with:
- Animated circuit schematic with real-time current flow
- Color-coded cell bank visualization
- Semicircular analog gauges
- Rolling history charts
- Protection status indicators

---

## 📄 License

MIT License — free to use, modify, and distribute.

---

## 🤝 Contributing

Pull requests welcome! Areas for improvement:
- More battery chemistries (LiFePO4, NiMH)
- Balancing circuit simulation
- Coulomb counting accuracy model
- Export data to CSV
- Mobile layout optimization
